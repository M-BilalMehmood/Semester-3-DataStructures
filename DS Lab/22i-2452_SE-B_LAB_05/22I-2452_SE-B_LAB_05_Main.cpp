#include<iostream>
#include<string>
#include"22I-2452_SE-B_LAB_05_H3.h"
using namespace std;

int main()
{
    // LinkedList myList;
    // Employee E1(1, "Ali", 1000, 100);
    LinkedList l1;
    cout << endl;
    cout << "Empty Status: " << l1.isEmpty() << endl;
    Employee E1 (1, "Bilal", 500, 200);
    Employee E2 (2, "Abdullah", 200, 175);
    Employee E3 (3, "Affan", 250, 150);
    l1.insert(E1);
    l1.insert(E2);
    l1.insert(E3);
    l1.Display();
    cout << endl;
    l1.remove(2);
    l1.Display();
    l1.UpdateSalary(200, 2);
    cout << endl;
    l1.UpdateBonus(150,1);
    l1.Display();
    cout << endl;
    cout << "Empty Status: " << l1.isEmpty();
    cout << endl;
    l1.sort();
    l1.Display();
    return 0;
}