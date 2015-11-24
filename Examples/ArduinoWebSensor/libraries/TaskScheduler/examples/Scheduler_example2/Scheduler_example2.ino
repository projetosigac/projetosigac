#define _TASK_SLEEP_ON_IDLE_RUN
#include <TaskScheduler.h>

Scheduler runner;

Task t4();
Task t1(2000, 10, &t1Callback, &runner, true);  //adding task to the chain on creation
Task t2(3000, -1, &t2Callback, &runner, true);  //adding task to the chain on creation
Task t3(5000, -1, &t3Callback);

// Test
// Initially only tasks 1 and 2 are enabled
// Task1 runs every 2 seconds 10 times and then stops
// Task2 runs every 3 seconds indefinitely
// Task1 enables Task3 at its first run
// Task3 run every 5 seconds
// loop() runs every 1 second (a default scheduler delay, if no shorter tasks' interval is detected)
// Task1 disables Task3 on its last iteration and changed Task2 to run every 1/2 seconds
// Because Task2 interval is shorter than Scheduler default tick, loop() executes ecery 1/2 seconds now
// At the end Task2 is the only task running every 1/2 seconds





void t1Callback() {
    Serial.print("t1: ");
    Serial.println(millis());
    
    if (t1.isFirstIteration()) {
       t3.enable();
       runner.addTask(t3);
      Serial.println("t1: enabled t3 and added to the chain");
    }
    
    if (t1.isLastIteration()) {
      t3.disable();
      runner.deleteTask(t3);
      t2.setInterval(500);
      Serial.println("t1: disable t3 and delete it from the chain. t2 interval set to 500");
    }
}

void t2Callback() {
    Serial.print("t2: ");
    Serial.println(millis());
  
}

void t3Callback() {
    Serial.print("t3: ");
    Serial.println(millis());
  
}

void setup () {
  Serial.begin(115200);
  Serial.println("Scheduler TEST");
  
   delay(5000);
}


void loop () {
  
  runner.execute();
  
  Serial.println("Loop ticks at: ");
  Serial.println(millis());
}
