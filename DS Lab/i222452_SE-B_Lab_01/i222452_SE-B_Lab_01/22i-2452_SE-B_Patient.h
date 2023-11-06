#pragma once
#include<iostream>
#include<string>
#include"i222452_SE-B_Hospital.h"
using namespace std;

class Patient {
private:
    string Name;
    string Type;
    int NumDays;
public:
    Patient() {}
    Patient(string name, string type, int numDays) {
        Name = name;
        Type = type;
        NumDays = numDays;
    }
    string getName() {
        return Name;
    }
    string getType() {
        return Type;
    }
    int getNumDays() {
        return NumDays;
    }
};

class Hospital {
private:
    Patient Ob;
    int MeditationCharges;
    double DailyRate;
    int HospitalCharges;
public:
    Hospital() {}
    Hospital(Patient ob, int meditationCharges, double dailyRate, int hospitalCharges) {
        Ob = ob;
        MeditationCharges = meditationCharges;
        DailyRate = dailyRate;
        HospitalCharges = hospitalCharges;
    }
    int getMeditationCharges() {
        return MeditationCharges;
    }
    double getDailyRate() {
        return DailyRate;
    }
    int getHospitalCharges() {
        return HospitalCharges;
    }
    double calculateCharges() {
        if (Ob.getType() == "in-patient") {
            return (Ob.getNumDays() * DailyRate) + (MeditationCharges * HospitalCharges);
        }
        else if (Ob.getType() == "out-patient") {
            return MeditationCharges + HospitalCharges;
        }
        else {
            return 0;
        }
    }
};
