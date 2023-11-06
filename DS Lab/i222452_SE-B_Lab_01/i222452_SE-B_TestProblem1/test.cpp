#include "pch.h"

#include"../i222452_SE-B_Lab_01/22i-2452_SE-B_Patient.h"
//#include"../i222452_SE-B_Lab_01/i222452_SE-B_Hospital.h"

TEST(HospitalTest, InPatientTest) {
    Patient p("John", "in-patient", 5);
    Hospital h(p, 100, 50.0, 200);
    EXPECT_EQ(h.getMeditationCharges(), 100);
    EXPECT_EQ(h.getDailyRate(), 50.0);
    EXPECT_EQ(h.getHospitalCharges(), 200);
    EXPECT_DOUBLE_EQ(h.calculateCharges(), 1250.0);
}

TEST(HospitalTest, OutPatientTest) {
    Patient p("Jane", "out-patient", 0);
    Hospital h(p, 50, 0, 100);
    EXPECT_EQ(h.getMeditationCharges(), 50);
    EXPECT_EQ(h.getDailyRate(), 0);
    EXPECT_EQ(h.getHospitalCharges(), 100);
    EXPECT_DOUBLE_EQ(h.calculateCharges(), 150.0);
}