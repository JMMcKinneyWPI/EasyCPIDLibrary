// operator.c : implementation file
#include "Main.h"
#include <PIDControllerEasyC.h>

//OperatorControl function runs this, so all code can be text-based
void operator(){
    //Timer 2 needs to be started for the library to work!
    StartTimer (2); 
    
    //Create a pointer to an instance of the PID structure
    PID *pidController;    

    //Initialize the pid controller that was just defined
    //void pidInit(*PID, float kP, float kI, float kD, float epsilon/tolerance, float slewRate);
    pidInit(pidController, 1, 0.1, 0.1, 20, 63);
    
    while(1){
        //Error is the difference between what the feedback sensor
        //reads and what the set point or desired reading is.
        //We use a constant here as a placeholder for this example.
        int error = 60;

        //Execute an iteration of the PID loop for our
        //pidController instance. Out is the motor value.
        //float pidExecute(*PID, float error);
        float out = pidExecute(pidController, error);

        //Print the motor output value to the console
        PrintToScreen ( "%0.2f\n" , out ) ; 
    }
}

