#include <stdio.h>
#include <stdlib.h>

static int key = 0;

void DbMockPost(char* refnum, char* name,
	        char* age, char* sex, int cstate,
	        int post) {


	if (post==1) {
		FILE * fp;
		fp = fopen ("file.txt", "a");
		fprintf(fp, "%d %s %s %s %s %d\n",
		        key, refnum, name, age,
			sex, cstate );
		++key;
		fclose (fp);
	}

	
}
