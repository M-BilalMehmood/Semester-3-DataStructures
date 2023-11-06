#pragma once
#include<iostream>
#include<string>
#include"22i-2452_SE-B_Patient.h"
using namespace std;

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