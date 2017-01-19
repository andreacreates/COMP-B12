/*
*	Author: Hernandez, Andrea
*	Assignment: Programming Assignment Three
*	Course: COMP B12
*	Instructor: Richard Miles
*	Date submitted: 2016/11/01
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

class OhmsLaw {
	public:
		void Welcome();
		void PrintMenu();
		void RunMenu(double *current, double *resistance, double *voltage, double *power);
		void CalcVolts(double *current, double *resistance, double *voltage);
		void PrintVolts(double *current, double *resistance, double *voltage);
		void PrintCurrent(double *current);
		void PrintResistance(double *resistance);
		void CalcPower(double *power, double *voltage, double *current);
		void PrintPower(double *power, double *voltage, double *current);
		void ChangeCurrent(double *current);
		void ChangeResistance (double *resistance);
		void RestartValues (double *current, double *resistance);
	
	private:
		double *current;
		double *resistance;
		double *voltage;
		double *power;

};

void OhmsLaw::Welcome(){
	
	cout << endl;
	cout <<"    **    ***             ***  *******  ***       *******  *******  ****   ****  *******      **   " << endl;
	cout <<"   **      ***           ***   ***      ***       ***      **   **  ** ** ** **  ***         **    " << endl;
	cout <<"  ******    ***   ***   ***    *****    ***       ***      **   **  **  ***  **  *****      ****** " << endl;
	cout <<"     **      *** ** ** ***     ***      ***       ***      **   **  **       **  ***           **  " << endl;
 	cout <<"    **         **** ****       *******  ********  *******  *******  **       **  *******      **   " << endl;
	cout << endl << endl;
	
	return;
}
void OhmsLaw::PrintMenu(){
	
	cout << " =====|M E N U|=====" << endl << endl;
	cout << "Choose an option: " << endl;
	cout << "a. List of Voltages."<< endl;
	cout << "b. List of Currents."<< endl;
	cout << "c. List of Resistances."<< endl;
	cout << "d. List of Powers." << endl;
	cout << "e. Change value of a Current." << endl;
	cout << "f. Change value of a Resistance." << endl;
	cout << "g. Restart to initial values." << endl;
	cout << "q. Quit" << endl;

	return;
}

void OhmsLaw::RunMenu(double *current, double *resistance, double *voltage, double *power){
	
	
    char usersInput;
	
    do {
		PrintMenu();
        cin >> usersInput;
        switch(usersInput) {
            case 'A':
            case 'a':
                PrintVolts(current, resistance, voltage);
                break;
            case 'B':
            case 'b':
                PrintCurrent(current);
                break;
            case 'C':
            case 'c':
                PrintResistance(resistance);
                break;
            case 'D':
            case 'd':
                PrintPower(power, voltage, current);
                break;
            case 'E':
            case 'e':
                ChangeCurrent(current);
                break;
            case 'F':
            case 'f':
                ChangeResistance(resistance);
                break;
			case 'G':
			case 'g':
				RestartValues (current, resistance);
				break;
            case 'Q':
            case 'q':
                cout << "Thank you, Have a nice day!" << endl;
                break;
            default:
                cout << "::ERROR:: Enter a valid choice, please.\n" << endl;
                break;
        }
    } while(usersInput != 'q' && usersInput != 'Q' && !cin.fail());
}
	

void OhmsLaw::CalcVolts(double *current, double *resistance, double *voltage){
	int i = 0;
	while (i < 10){
		*voltage++ = (*current++) * (*resistance++);
		i++;
	}
	return;
}

void OhmsLaw::PrintVolts(double *current, double *resistance, double *voltage){
	
	CalcVolts(current, resistance, voltage);
	int i = 0;
	
	for (i = 0; i < 10; i++){
		cout << showpoint << setw(6);
		if(i < 9){
			cout << "Voltage " << i + 1 << "  = " << voltage[i] << " [Volt]"  << endl;
		}
		else{
			cout << "Voltage " << i + 1 << " = " << voltage[i] << " [Volt]" << endl;
		}
	}
	cout << endl;
	return;
}

void OhmsLaw::PrintCurrent(double *current){
	int i = 0;
	
	for (i = 0; i < 10; i++){
		cout << showpoint << setw(6);
		if(i < 9){
			cout << "Current " << i + 1 << "  = " << current[i] << " [Amper]"  << endl;
		}
		else{
			cout << "Current " << i + 1 << " = " << current[i] << " [Amper]" << endl;
		}
	}
	cout << endl;
	return;
}

void OhmsLaw::PrintResistance(double *resistance){
	int i = 0;
	
	for (i = 0; i < 10; i++){
		cout << showpoint << setw(6);
		if(i < 9){
			cout << "Resistance " << i + 1 << "  = " << resistance[i] << " [Ohm]"  << endl;
		}
		else{
			cout << "Resistance " << i + 1 << " = " << resistance[i] << " [Ohm]" << endl;
		}
	}
	cout << endl;
	return;
}

void OhmsLaw::CalcPower(double *power, double *voltage, double *current){
	int i = 0;
	
	while (i < 10){
		*power++ = (*current++) * (*voltage++);
		i++;
	}
	return;
}

void OhmsLaw::PrintPower(double *power, double *voltage, double *current){
	
	CalcPower(power, voltage, current);
	int i = 0;
	
	for (i = 0; i < 10; i++){
		cout << showpoint << setw(6);
		if(i < 9){
			cout << "Power " << i + 1 << "  = " << power[i] << " [Watt]"  << endl;
		}
		else{
			cout << "Power " << i + 1 << " = " << power[i] << " [Watt]" << endl;
		}
	}
	cout << endl;
	return;
}
void OhmsLaw::ChangeCurrent(double *current){
	int numCurrent;
	double newCurrentValue;
	
	PrintCurrent(current);
	cout << "Which current would you like to change?(1-10)" << endl;
	cin >> numCurrent;
	
	if (numCurrent >= 1 && numCurrent <= 10){
		cout << "Enter the new value for the current "<< numCurrent << ":" << endl;
		cin >> newCurrentValue;
		current[numCurrent-1] = newCurrentValue;
	}
	else{
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n');
		cout << "Your number is invalid.\nPlease, Enter a valid number between 1-10\n" << endl;
		ChangeCurrent(current);

	}
	return;
}

void OhmsLaw::ChangeResistance (double *resistance){
	int numResistance;
	double newResistanceValue;
	
	PrintResistance(resistance);
	cout << "Which resistance would you like to change?(1-10)" << endl;
	cin >> numResistance;
	
	if (numResistance >= 1 && numResistance <= 10){
		cout << "Enter the new value for the resistance "<< numResistance << ":" << endl;
		cin >> newResistanceValue;
		resistance[numResistance-1] = newResistanceValue;
	}
	else{
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n');
		cout << "Your number is invalid.\nPlease, Enter a valid number between 1-10\n" << endl;
		ChangeResistance(resistance);

	}
	return;
}
void OhmsLaw::RestartValues (double *current, double *resistance){
	
	double initialCurrent[10] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
	double initialResistance[10] = {4.0, 8.5, 6.0, 7.35, 9.0, 15.3, 3, 5.4, 2.9, 4.8};
	int i = 0;
	
	while (i < 10){
		current[i] = initialCurrent[i];
		resistance[i] = initialResistance[i];
		i++;
	}
	return;
}


int main(){
	
	double current[10] = {10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98};
	double resistance[10] = {4.0, 8.5, 6.0, 7.35, 9.0, 15.3, 3, 5.4, 2.9, 4.8};
	double voltage[10];
	double power[10];
	
	OhmsLaw FirstCircuit;
	
	FirstCircuit.Welcome();
	cout << "Your initial values are: " << endl;
	FirstCircuit.PrintVolts(current, resistance, voltage);
	FirstCircuit.RunMenu(current, resistance, voltage, power);
	
	return 0;
}

