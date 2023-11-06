#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

class Student
{
public:
	int srno;
	string regdate;
	string name;
	string rollno;
	int A1, A2, A3, A4, As, S1, S2, Proj, Proj1, Final1, Final2, Mid1, Mid2, Gtotal;
	Student()
	{
		srno = 0;
		regdate = "";
		name = "";
		rollno = "";
		A1 = 0;
		A2 = 0;
		A3 = 0;
		A4 = 0;
		As = 0;
		S1 = 0;
		S2 = 0;
		Proj = 0;
		Proj1 = 0;
		Final1 = 0;
		Final2 = 0;
		Mid1 = 0;
		Mid2 = 0;
		Gtotal = 0;
	}
	//getter and setter functions
    int getSrno() const { return srno; }
    string getRegdate() const { return regdate; }
    string getName() const { return name; }
    string getRollno() const { return rollno; }
    int getA1() const { return A1; }
    int getA2() const { return A2; }
    int getA3() const { return A3; }
    int getA4() const { return A4; }
    int getAs() const { return As; }
    int getS1() const { return S1; }
    int getS2() const { return S2; }
    int getProj() const { return Proj; }
    int getProj1() const { return Proj1; }
    int getFinal1() const { return Final1; }
    int getFinal2() const { return Final2; }
    int getMid1() const { return Mid1; }
    int getMid2() const { return Mid2; }
    int getGtotal() const { return Gtotal; }

    void setSrno(int s) { srno = s; }
    void setRegdate(string r) { regdate = r; }
    void setName(string n) { name = n; }
    void setRollno(string r) { rollno = r; }
    void setA1(int a) { A1 = a; }
    void setA2(int a) { A2 = a; }
    void setA3(int a) { A3 = a; }
    void setA4(int a) { A4 = a; }
    void setAs(int a) { As = a; }
    void setS1(int s) { S1 = s; }
    void setS2(int s) { S2 = s; }
    void setProj(int p) { Proj = p; }
    void setProj1(int p) { Proj1 = p; }
    void setFinal1(int f) { Final1 = f; }
    void setFinal2(int f) { Final2 = f; }
    void setMid1(int m) { Mid1 = m; }
    void setMid2(int m) { Mid2 = m; }
    void setGtotal(int g) { Gtotal = g; }
};