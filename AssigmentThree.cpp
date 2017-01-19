/*
*	Author: Hernandez, Andrea
*	Assignment: Programming Assignment Three
*	Course: COMP B12
*	Instructor: Richard Miles
*	Date submitted: 2016/10/27
*/

#include <iostream>
#include <iomanip>
using namespace std;

void calcVolts(double *current, double *resistance, double *voltage){
	int i = 0;
	for (i = 0; i < 10; ++i){
		voltage[i] = current[i] * resistance[i];
	}

	return;
}

int main(){

	double current[10] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
	double resistance[10] = {4.0, 8.5, 6.0, 7.35, 9.0, 15.3, 3, 5.4, 2.9, 4.8};
	double voltage[10];
	int i = 0;

	calcVolts(current, resistance, voltage);
	for (i = 0; i < 10; i++){
		cout << showpoint << setw(6);
		if(i < 9){
			cout << "Voltage " << i + 1 << "  = " << voltage[i] << endl;
		}
		else{
			cout << "Voltage " << i + 1 << " = " << voltage[i] << endl;
		}

	}

	return 0;
}

