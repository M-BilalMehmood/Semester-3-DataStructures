#include<iostream>
#include<string>
#include"22i-2452_SE-B_Patient.h"
//#include"i222452_SE-B_Hospital.h"
using namespace std;

int main() {
    cout << "======^_^======" << endl;
    cout << "Welcome Patient" << endl;
    cout << endl << "You are admitted as?" << endl << "1. [I]n-Patient" << endl << "2. [O]ut-Patient" << endl;
    char input;
    cin >> input;
    if (input == 'I' || input == 'i') {
        string name, type;
        int numDays, meditationCharges, hospitalCharges;
        double dailyRate;
        cout << "Enter Name: ";
        cin >> name;
        type = "in-patient";
        cout << "Enter Number of Days: ";
        cin >> numDays;
        cout << "Enter Daily Rate: ";
        cin >> dailyRate;
        cout << "Enter Hospital Medication Charges: ";
        cin >> meditationCharges;
        cout << "Enter Charges for Services: ";
        cin >> hospitalCharges;
        Patient p(name, type, numDays);
        Hospital h(p, meditationCharges, dailyRate, hospitalCharges);
        cout << "Total Charges: " << h.calculateCharges() << endl;
    }
    else if (input == 'O' || input == 'o') {
        string name, type;
        int meditationCharges, hospitalCharges;
        type = "out-patient";
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Charges for Services: ";
        cin >> hospitalCharges;
        cout << "Enter Hospital Medication Charges: ";
        cin >> meditationCharges;
        Patient p(name, type, 0);
        Hospital h(p, meditationCharges, 0, hospitalCharges);
        cout << "Total Charges: " << h.calculateCharges() << endl;
    }
    else {
        cout << "=====0_o=====" << endl;
        cout << "Invalid Input" << endl;
    }
    return 0;
}