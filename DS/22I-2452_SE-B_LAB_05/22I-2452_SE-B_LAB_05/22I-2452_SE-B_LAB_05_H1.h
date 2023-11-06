#pragma once
#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:
    int EmpID;
    string NIC;
    double salary;
    double bonus;
public:
    Employee() : EmpID(0), NIC(""), salary(0), bonus(0) {};
    Employee(int ID, string nic, double SAL, double Bonus)
    {
        EmpID = ID;
        NIC = nic;
        salary = SAL;
        bonus = Bonus;
    }

    //setters
    void setEmpID(int ID) { EmpID = ID; }
    void setNIC(string nic) { NIC = nic; }
    void setSalary(double Salary) { salary = Salary; }
    void setBonus(double Bonus) { bonus = Bonus; }
    //getters
    int getEmpID() { return EmpID; }
    string getNIC() { return NIC; }
    double getSalary() { return salary; }
    double getBonus() { return bonus; }

    //Display
    void displayDetails()
    {
        cout << endl;
        cout << "Employee ID  : " << EmpID << endl;
        cout << "NIC          : " << NIC << endl;
        cout << "Salary       : " << salary << endl;
        cout << "Bonus        : " << bonus << endl;
    }
    ~Employee()
    {
        // Destructor
    }
};