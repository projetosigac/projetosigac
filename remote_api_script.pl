#!/usr/bin/perl -w

$main_module = shift(@ARGV);
$max_strlen = shift(@ARGV);
$num_dbs = scalar(@ARGV)/8;

#ARGUMENTS:
#1) main module
#2) maximum string length
#3) repeat for each db:
#3a) mysql db name
#3b) hostname
#3c) user
#3d) password
#3e) task, return signal and "get functions" prefix
#3f) number of query return signals
#3g) number of get row return signals
#3h) number of clear results return signals

# Load database parameters into array of arrays
for (my $x=0; $x<$num_dbs; $x++) {
	for (my $y=0; $y<8; $y++) {
		$dbs[$x][$y] = shift(@ARGV);
	}
}

#Print out the user entered info
print "Main module: ${main_module}\n";
for (my $x=0; $x<$num_dbs; $x++) {
	print "DB: ${x}\n";
	print "\tDB Name:\t${dbs[$x][0]}\n";
	print "\tHost:\t\t${dbs[$x][1]}\n";
	print "\tUser:\t\t${dbs[$x][2]}\n";
	print "\tPass:\t\t${dbs[$x][3]}\n";
	print "\tTask Prefix:\t${dbs[$x][4]}\n";
	print "\tNum Query Return Signals:\t${dbs[$x][5]}\n";
	print "\tNum Get Row Return Signals:\t${dbs[$x][6]}\n";
	print "\tNum Clear Return Signals:\t${dbs[$x][7]}\n";
}

if (!open (OUT, ">${main_module}_out.c")) {
    print "Cannot open ${main_module}_out.c for writing \n";
    exit 1;
}


if (!open (EST_FILE, "${main_module}.c")) {
    print "Cannot open ${main_module}.c for reading \n";
    exit 1;
}

while (($line = <EST_FILE>) ne "#include \"${main_module}.h\"\n") {
	if ($line =~ /#define STRLEN/) {
		print OUT ("#define STRLEN ${max_strlen}\n");
	}
	else {
		print OUT $line;
	}
}

while (($line = <EST_FILE>) ne "/* ASSIGNMENTS */\n") {
	print OUT $line;
}

print OUT <<"OUTPUTFUNS";

#include <mysql.h>

int done;

void ${main_module}_O_printint(int num) {
  printf("printint: %d\\n", num);
}

void ${main_module}_O_printstr(char* str) {
  printf("printstr: %s\\n", str);
}

void ${main_module}_O_printbol(int num) {
  printf("printbol: %d\\n", num);
}

void ${main_module}_O_done() {
  done = 1;
}

OUTPUTFUNS

for (my $x=0; $x<$num_dbs; $x++) {
  $rowVar = "row_".$x;
  print OUT <<"DBVARS_GETFUNS";
MYSQL init_${x}, *sock_${x};
MYSQL_RES *result_${x};
MYSQL_ROW row_${x};

int ${dbs[$x][4]}_getint(int pos) {
  return atoi(${rowVar}[pos]);
}

int ${dbs[$x][4]}_getbol(int pos) {
  return atoi(${rowVar}[pos]);
}

char* ${dbs[$x][4]}_getstr(int pos) {
  return ${rowVar}[pos];
}
DBVARS_GETFUNS
}

#print out remainder of esterel autogen code
print OUT $line;
while ($line = <EST_FILE>) {
	print OUT $line;
}

print OUT <<"TYPES_VAR";
#include "pthread.h"
#include <time.h>

enum Request {NONE, QUERY, ROW, NUMROWS, AFFECTEDROWS, CLEAR};
struct Thread_vars {int request_complete; char* query_string; int ret_val; enum Request request; int return_sig;};//Request req;
pthread_attr_t default_attr;

pthread_mutex_t db_init_mutex;
pthread_cond_t db_init_cv;
int db_init_count;

TYPES_VAR

for (my $x=0; $x<$num_dbs; $x++) {
  print OUT <<"THREADFUN";
pthread_t conn_${x}_thread;
pthread_mutex_t conn_${x}_mutex;
struct Thread_vars conn_${x}_vars;


void *conn_${x}_thread_fun(void *ptr) {

  struct timespec delay;
  delay.tv_sec = 0;
  delay.tv_nsec = 4000000;


  mysql_init(&init_${x});
	if (!(sock_${x} = mysql_real_connect(&init_${x},"${dbs[$x][1]}","${dbs[$x][2]}","${dbs[$x][3]}","${dbs[$x][0]}",0,NULL,0))) {
		printf("Couldn't connect to DB, ID: 0\\n%s\\n\\n",mysql_error(&init_${x}));
		perror("");
		exit(1);
	}

  // Record that this thread had completed db initilization
  pthread_mutex_lock(&db_init_mutex);
	db_init_count += 1;
	if (db_init_count == ${num_dbs}) {
    // If all threads have completed db init then signal the main thread to continue.
    pthread_cond_signal(&db_init_cv);
  }
  pthread_mutex_unlock(&db_init_mutex);

  while (!done) {
    pthread_mutex_lock(&conn_${x}_mutex);

    //check if there is an operation to do then
    //check if we have already done the requested operation, if so don't do it again
    if ((!conn_${x}_vars.request_complete) && (conn_${x}_vars.request != NONE)) {

      if (conn_${x}_vars.request == QUERY) {

        printf("thread doing query: %s\\n", conn_${x}_vars.query_string);

      	if (mysql_query(sock_${x}, conn_${x}_vars.query_string)) {
      		conn_${x}_vars.ret_val = 0;
      		printf("Query failed (%s)\\n",mysql_error(sock_${x})); // error
      	}
        else {
          if (!(result_${x} = mysql_use_result(sock_${x}))) {
            conn_${x}_vars.ret_val = 0;
            printf("use_result failed (%s)\\n",mysql_error(sock_${x}));
          }
          else {
            conn_${x}_vars.ret_val = 1;
          }
        }
        conn_${x}_vars.request_complete = 1;

      }
      else if (conn_${x}_vars.request == ROW) {

        printf("thread doing getrow\\n");
        row_${x} = mysql_fetch_row(result_${x});
        conn_${x}_vars.ret_val = (row_${x} != 0 ? 1 : 0);
        conn_${x}_vars.request_complete = 1;
      }
      else if (conn_${x}_vars.request == NUMROWS) {
        printf("thread doing numrows\\n");
      }
      else if (conn_${x}_vars.request == AFFECTEDROWS) {
        printf("affected rows not supported\\n");
      }
      else if (conn_${x}_vars.request == CLEAR) {

        printf("thread doing clear\\n");
        mysql_free_result(result_${x});
        conn_${x}_vars.request_complete = 1;
      }
    }
    pthread_mutex_unlock(&conn_${x}_mutex);
    // need to sleep here to give main() a chance to consume ret_val
    pthread_yield();
  }

  mysql_close(sock_${x});
}
THREADFUN

  for (my $y=0; $y<$dbs[$x][5]; $y++) {
    print OUT <<"QUERYSTARTFUN";
void conn_${x}_query_start${y}(char *valparam, __ExecStatus* junk) {

  printf("got to query start\\n");

  pthread_mutex_lock(&conn_${x}_mutex);

  if (conn_${x}_vars.request != NONE) {
    printf("Incorrect API usage - you have tried to run two threads from the same database connection simultanously\\n");
    exit(0);
  }

  conn_${x}_vars.return_sig = ${y};
  conn_${x}_vars.request = QUERY;
  conn_${x}_vars.query_string = valparam;

  pthread_mutex_unlock(&conn_${x}_mutex);
}
QUERYSTARTFUN
  }

  for (my $y=0; $y<$dbs[$x][6]; $y++) {
    print OUT <<"GETROWSTARTFUN";
void conn_${x}_row_start${y}(char *junkrefparam, char *valparam, __ExecStatus* junk) {

  printf("got to row start\\n");

  pthread_mutex_lock(&conn_${x}_mutex);

  if (conn_${x}_vars.request != NONE) {
    printf("Incorrect API usage - you have tried to run two threads from the same database connection simultanously\\n");
    exit(0);
  }

  conn_${x}_vars.return_sig = ${y};
  conn_${x}_vars.request = ROW;

  pthread_mutex_unlock(&conn_${x}_mutex);
}
GETROWSTARTFUN
  }

  for (my $y=0; $y<$dbs[$x][7]; $y++) {
    print OUT <<"CLEARSTARTFUN";
void conn_${x}_clear_start${y}(char *junkrefparam, char *valparam, __ExecStatus* junk) {

  printf("got to clear start\\n");

  pthread_mutex_lock(&conn_${x}_mutex);

  if (conn_${x}_vars.request != NONE) {
    printf("Incorrect API usage - you have tried to run two threads from the same database connection simultanously\\n");
    exit(0);
  }

  conn_${x}_vars.return_sig = ${y};
  conn_${x}_vars.request = CLEAR;

  pthread_mutex_unlock(&conn_${x}_mutex);
}
CLEARSTARTFUN
  }
}

### MAIN STARTS HERE
##########################################

print OUT <<"MAIN1";
int main() {

  struct timespec delay;
  delay.tv_sec = 0;
  delay.tv_nsec = 10000000;

  done = 0;

  db_init_count = 0;
  pthread_mutex_init(&db_init_mutex, NULL);
  pthread_cond_init(&db_init_cv, NULL);

  pthread_attr_init(&default_attr);
MAIN1

for (my $x=0; $x<$num_dbs; $x++) {
  print OUT <<"THREADINITANDSTART";
  conn_${x}_vars.request = NONE;
  conn_${x}_vars.request_complete = 0;
  pthread_mutex_init(&conn_${x}_mutex, NULL);

  if (pthread_create( &conn_${x}_thread, &default_attr, (void*)&conn_${x}_thread_fun, (void*)NULL) == -1) {
    printf("conn_${x}_thread creation failed\\n");
    exit(1);
	}
THREADINITANDSTART
}

print OUT <<"MAIN2";
  // Wait for all db threads to complete db initilization.
  pthread_mutex_lock(&db_init_mutex);
  pthread_cond_wait(&db_init_cv, &db_init_mutex);
  pthread_mutex_unlock(&db_init_mutex);

  DBTaskTest_reset();


  while(!done) {
MAIN2

#do db input processing for each conn
for (my $x=0; $x<$num_dbs; $x++) {
  print OUT <<"DBINPUTPROCESSING1";
    if (pthread_mutex_trylock(&conn_${x}_mutex) == 0) {
      //if we do not get the lock, db thread still working so no return signals from
      //this thread to process
      if (conn_${x}_vars.request_complete) {
        if (conn_${x}_vars.request == NONE) {
          printf("Tried to consume ret_val from thread conn_${x}, but request == NONE\\n");
          exit(0);
        }
        else if (conn_${x}_vars.request == QUERY) {
          printf("query done - calling return sig fun with ret_val: %d, ret_sig: %d\\n", conn_${x}_vars.ret_val, conn_${x}_vars.return_sig);
          switch (conn_${x}_vars.return_sig) {
DBINPUTPROCESSING1
  for (my $y=0; $y<$dbs[$x][5]; $y++) {
    print OUT "            case ${y} : DBTaskTest_I_${dbs[$x][4]}_perform_query_complete${y}(conn_${x}_vars.ret_val);\n";
  }
  print OUT <<"DBINPUTPROCESSING2";
          }
        }
        else if (conn_${x}_vars.request == ROW) {
          printf("get row done - calling return sig fun with ret_val: %d, ret_sig: %d\\n", conn_${x}_vars.ret_val, conn_${x}_vars.return_sig);
          switch (conn_${x}_vars.return_sig) {
DBINPUTPROCESSING2
  for (my $y=0; $y<$dbs[$x][6]; $y++) {
    print OUT "            case ${y} : DBTaskTest_I_${dbs[$x][4]}_get_row_complete${y}(conn_${x}_vars.ret_val);\n";
  }
  print OUT <<"DBINPUTPROCESSING3";
          }
        }
        else if (conn_${x}_vars.request == CLEAR) {
          printf("clear done - calling return sig fun with ret_val: %d, ret_sig: %d\\n", conn_${x}_vars.ret_val, conn_${x}_vars.return_sig);
          switch (conn_${x}_vars.return_sig) {
DBINPUTPROCESSING3
  for (my $y=0; $y<$dbs[$x][7]; $y++) {
    print OUT "            case ${y} : DBTaskTest_I_${dbs[$x][4]}_clear_complete${y}(conn_${x}_vars.ret_val);\n";
  }
  print OUT <<"DBINPUTPROCESSING4";
          }
        }
        else if (conn_${x}_vars.request == NUMROWS) {
          //numrow opperations are not supported
        }
        else if (conn_${x}_vars.request == AFFECTEDROWS) {
          //affectedrow opperations are not supported
        }
        conn_${x}_vars.request_complete = 0;
        conn_${x}_vars.request = NONE;
        printf("reset conn_${x} vars\\n");
      }
      else {
        printf("no ret sigs to process  for conn_${x}\\n");
      }
      pthread_mutex_unlock(&conn_${x}_mutex);
    }
    else {
      printf("no ret sigs to process due to trylock failing on conn_${x}\\n");
    }
DBINPUTPROCESSING4
}
print OUT <<"MAIN3";
    printf("automata call\\n");
    DBTaskTest();
MAIN3
for (my $x=0; $x<$num_dbs; $x++) {
  for (my $y=0; $y<$dbs[$x][5]; $y++) {
print OUT <<"QUERYTASKSTART";
    {
    	extern __ExecStatus ${main_module}_exec_status_${dbs[$x][4]}_perform_query_complete${y};
      if (${main_module}_exec_status_${dbs[$x][4]}_perform_query_complete${y}.start) {
        (*(${main_module}_exec_status_${dbs[$x][4]}_perform_query_complete${y}.pStart))(conn_${x}_query_start${y});
      }
    }
QUERYTASKSTART
  }
  for (my $y=0; $y<$dbs[$x][6]; $y++) {
print OUT <<"GETROWTASKSTART";
    {
    	extern __ExecStatus ${main_module}_exec_status_${dbs[$x][4]}_get_row_complete${y};
      if (${main_module}_exec_status_${dbs[$x][4]}_get_row_complete${y}.start) {
        (*(${main_module}_exec_status_${dbs[$x][4]}_get_row_complete${y}.pStart))(conn_${x}_row_start${y});
      }
    }
GETROWTASKSTART
  }
  for (my $y=0; $y<$dbs[$x][7]; $y++) {
print OUT <<"CLEARTASKSTART";
    {
    	extern __ExecStatus ${main_module}_exec_status_${dbs[$x][4]}_clear_complete${y};
      if (${main_module}_exec_status_${dbs[$x][4]}_clear_complete${y}.start) {
        (*(${main_module}_exec_status_${dbs[$x][4]}_clear_complete${y}.pStart))(conn_${x}_clear_start${y});
      }
    }
CLEARTASKSTART
  }
}
print OUT <<"MAIN4";
    //sleep
    nanosleep(&delay,&delay);
  }
}
MAIN4

exit(0);


