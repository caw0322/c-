/*
 * Clock.h
 *
 *  Created on: Jul 18, 2020
 *      Author: Corey Wright
 */
#ifndef CLOCK_H_
#define CLOCK_H_

#include <iostream> // iostream for input/output
#include<windows.h> //windows header for key state function
#include <ctime>       /* time_t, struct tm, time, localtime, asctime */
using namespace std; //namespace for cout/cin

 int SecondsClock(int seconds){ // function to return value of seconds based on local time
	 time_t total_seconds=time(0);
	 struct tm* ct=localtime(&total_seconds);
	 	 seconds=ct->tm_sec;
return(seconds);
}

int MinutesClock(int minutes){// function to return value of minutes based on local time
	time_t total_seconds=time(0);
	struct tm* ct=localtime(&total_seconds);
		minutes=ct->tm_min;
return(minutes);
}

int HoursClock (int hours){//function to return value of minutes based on local time
	time_t total_seconds=time(0);
	struct tm* ct=localtime(&total_seconds);
		hours=ct->tm_hour;
return(hours);
}

void Clock(){ // function for the output and operation of clock
	/* defining local variable of hours (for 12 hour clock) tfHours (24 hour clock) minutes, seconds
	 * and the switch case variable as well as boolean for the menu option and the string for AM or PM
	 */
	int hours, tfHours, minutes, seconds, choice;
	bool changeTime = false;
	string str;
	// defining the time variable by calling the respective functions
	hours = HoursClock(0);
	minutes = MinutesClock(0);
	seconds = SecondsClock(0);
	tfHours = HoursClock(0);
	// while loop to continually print the clock output while the boolean changeTime is false
    while(!(changeTime) ){
    //system function to clear the screen after every output
     system("CLS");
    // output statements for the two clocks
     	 cout << "*****************************     ****************************" << endl;
	 	 cout << "*       12-Hour Clock       *     *       24-Hour Clock      *"<< endl;
	 	 cout << "*       " << (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":";
	 	 cout << (seconds<10?"0":"") << seconds<< " " << str << "         *     *       "<<(tfHours<10?"0":"");
	 	 cout << tfHours<<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds;
	 	 cout << " " "          *" << endl;
	 	 cout << "*****************************     ****************************" << endl;
	 	 cout << "Press Space Key For Menu" << endl;
	 	 // if statement which recognizes if the space bar is pressed to bring up the option menu
	 	 if(GetAsyncKeyState(VK_SPACE)){
	 		 // changes boolean to true to stop the printing while loop
	 		 changeTime = true;
	 		 // output statements for the menu
	 		 cout << "*****************************" << endl;
	 		 cout << "*       1-Add One Hour      *" <<endl;
	 		 cout << "*       2-Add One Minute    *" <<endl;
	 		 cout << "*       3-Add One Second    *" << endl;
	 		 cout << "*       4-Exit Program      *" << endl;
	 		 cout << "*****************************" << endl;
	 		 // user input for switch case
	 		 cin >> choice;
	 		 // switch to preform the task asked by the user
	 		 	 switch(choice){
	 		 	 	 case 1:
	 		 	 		 ++hours;
	 		 	 		 ++tfHours;
	 		 	 		 break;
	 		 	 	 case 2:
	 		 	 		 ++minutes;
	 		 	 		 break;
	 		 	 	 case 3:
	 		 	 		 ++seconds;
	 		 	 		 break;
	 		 	 	 case 4:
	 		 	 		 cout << "Goodbye";
	 		 	 		 Sleep(1000);
	 		 	 		 exit(0);
	 		 	 }
	 		 	 // resetting changeTime to false to restart the printing while loop
	 		 	 changeTime = false;
	 	 }
	 	 // code for when the while loop is running
	 	 else{
             // defining the AM or PM string based off of the 24 hour clock
	 		 if(tfHours>=12){
	 			 str="PM";
	 		 }
	 		 else {
	 			 str = "AM";
	 		 }
	 		 // telling program to wait 1,000 milliseconds until rerunning the loop
	 		 Sleep(1000);
	 		 // after 1,000 ms, increases seconds by 1
	 		 ++seconds;
	 		 // resets seconds to 0 and increases minutes by 1
	 		 if(seconds > 59){
	 			 seconds = 0;
	 			 ++minutes;
	 		 }
	 		 // resets minutes to 0 and increase 12 and 24 hour by 1
	 		 if(minutes > 59){
	 			 minutes = 0;
	 			 ++hours;
	 			 ++tfHours;
	 		 }
	 		 //resets 12 hour to 1
	 		 if(hours > 12){
	 			 hours = 1;
	 		 }
	 		 // resets 24 hour to 0
	 		 if(tfHours > 23){
	 			 tfHours = 0;
	 		 }

	 	 }
    }
}


#endif /* CLOCK_H_ */
