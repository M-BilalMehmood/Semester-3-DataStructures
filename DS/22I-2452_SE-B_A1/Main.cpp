/*
    Name: Muhammad Bilal Mehmood
    Section: B
    Roll No: 22I-2452
*/
#include<iostream>
#include<string>
#include<fstream>
#include"Mainheader.h"
using namespace std;

int main()
{
    int size = 10;
    EmployeeData<string> employee[10];
    TakeData<string>(employee, size);
    cout << "\033[1;35mWelcome To Employee Analysis System\033[0m" << endl;
    cout << "\033[1;35mWhat do you want to do?\033[0m" << endl;
    cout << "\033[1;34m01. \033[0mPrint all Employees" << endl;
    cout << "\033[1;34m02. \033[0mPrint Average Salary of the company" << endl;
    cout << "\033[1;34m03. \033[0mPrint Total number of Employees" << endl;
    cout << "\033[1;34m04. \033[0mPrint Average company tenure" << endl;
    cout << "\033[1;34m05. \033[0mPrint Employee Distribution" << endl;
    cout << "\033[1;34m06. \033[0mPrint Employee with highest tenure" << endl;
    cout << "\033[1;34m07. \033[0mPrint Employee with highest salary" << endl;
    cout << "\033[1;34m08. \033[0mPrint Employee with lowest salary" << endl;
    cout << "\033[1;34m09. \033[0mPrint Salary Range" << endl;
    cout << "\033[1;34m10. \033[0mPrint Salary Mediam" << endl;
    cout << "\033[1;34m11. \033[0mPrint Average Salary of each Designation" << endl;
    cout << "\033[1;34m12. \033[0mPrint Employee with shortest tenure" << endl;
    cout << "\033[1;34m13. \033[0mPrint Average Tenure of each Designation" << endl;
    cout << "\033[1;34m14. \033[0mPrint Highest Paying Designation" << endl;
    cout << "\033[1;34m15. \033[0mPrint Sorted Employees by Salary using Bubble Sort" << endl;
    cout << "\033[1;34m16. \033[0mPrint Sorted Employees by Salary using Selection Sort" << endl;
    cout << "\033[1;34m17. \033[0mPrint Sorted Employees by Salary using Insertion Sort" << endl;
    cout << "\033[1;34m18. \033[0mPrint Sorted Employees by Tenure using Bubble Sort" << endl;
    cout << "\033[1;34m19. \033[0mPrint Sorted Employees by Tenure using Selection Sort" << endl;
    cout << "\033[1;34m20. \033[0mPrint Sorted Employees by Tenure using Insertion Sort" << endl;
    cout << "\033[1;31m21. Exit\033[0m" << endl;
    int choice;
    cout << "\033[1;35mEnter your choice: \033[0m";
    cin >> choice;

    switch (choice)
    {
    case 1:
        for (int i = 0; i < 10; i++)
        {
            cout << endl << "\033[1;32mEmployee " << i + 1 << ":\033[0m" << endl;
            employee[i].printing();
        }
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 2:
        cout << endl << "\033[1;32mAverage Salary of the company is: \033[0m" << findCompanyAvgSalary<string>(employee, size) << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 3:
        cout << "\033[1;32mTotal number of Employees are: \033[0m" << findNumberOfEmployees<string>(employee, size) << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 4:
        cout << "\033[1;32mAverage company tenure: \033[0m" << findCompanyAvgTenure<string>(employee, size) << " years" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 5:
        EmployeeDistribution<string>(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 6:
    {
        EmployeeData<string> highestTenureEmployee = findEmployeeWithLongestTenure(employee, size);
        cout << "Employee with highest tenure: " << highestTenureEmployee.getName() << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    }
    case 7:
        findEmployeeHighestSalary(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 8:
        findEmployeeLowestSalary(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 9:
        findSalaryRange(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 10:
        findSalaryMediam(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 11:
        avgSalaryOfEachDesignation(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 12:
        findEmployeeShortestTenure(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 13:
        avgTenureDesignation(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 14:
        findHighestPayingDesignation(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 15:
        sortEmployeesSalaryBubble(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 16:
        sortEmployeesSalarySelection(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 17:
        sortEmployeesSalaryInsertion(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 18:
        sortEmployeesTenureBubble(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 19:
        sortEmployeesTenureSelection(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 20:
        sortEmployeesTenureInsertion(employee, size);
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        break;
    case 21:
        exit(0);
        break;
    default:
        cout << "\033[1;31mInvalid Choice\033[0m" << endl;
        cout << "Press Enter to continue..." << endl;
        cin.ignore();
        cin.get();
        system("cls");
        main();
        main();
        break;
    }
}
//All Rights Reserved @22i-2452