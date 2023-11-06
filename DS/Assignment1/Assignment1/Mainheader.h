#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<chrono>
#include<ctime>
#include<fstream>
using namespace std;

template<typename employee>
class EmployeeData //template class
{
private:
    employee name;
    employee id;
    employee salary;
    employee dateOfJoining;
    employee designation;
public:
    EmployeeData() : name(employee()), id(employee()), salary(employee()), dateOfJoining(employee()), designation(employee()) {} //constructor
    //EmployeeData() : name("NULL"), id(0), salary(0), dateOfJoining(0), designation("NULL") {}
    EmployeeData(employee name, employee id, employee salary, employee dateOfJoining, employee designation)
    {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->dateOfJoining = dateOfJoining;
        this->designation = designation;
    }
    //setters
    void setName(const employee& name) { this->name = name; }
    void setId(const employee& id) { this->id = id; }
    void setSalary(const employee& salary) { this->salary = salary; }
    void setDateOfJoining(const employee& dateOfJoining) { this->dateOfJoining = dateOfJoining; }
    void setDesignation(const employee& designation) { this->designation = designation; }
    //getters
    employee getName() const { return name; }
    employee getId() const { return id; }
    employee getSalary() const { return salary; }
    employee getDateOfJoining() const { return dateOfJoining; }
    employee getDesignation() const { return designation; }

    void printing()
    {
        cout << "Employee Name    : " << name << endl;
        cout << "Employee ID      : " << id << endl;
        cout << "Salary           : " << salary << endl;
        cout << "Date of Joining  : " << dateOfJoining << endl;
        cout << "Designation      : " << designation << endl;
    }
};

template<typename EM1, typename S>
void TakeData(EmployeeData<EM1>* employee, S size)
{
    ifstream inputFile("Employeedata.txt"); // Replace with your file path

    if (!inputFile) {
        cout << "\033[1;31mError opening the file\033[0m" << endl;
    }
    else
    {
        cout << "\033[1;32mFile opened successfully\033[0m" << endl;
    }

    string line;
    int i = 0;

    while (getline(inputFile, line))
    {
        size_t pos = line.find(": ");
        if (pos != string::npos)
        {
            string data = line.substr(pos + 2); // Skip ":" and get the data
            if (line.find("Employee Name:") != string::npos)
            {
                employee[i].setName(data);
            }
            else if (line.find("Employee ID:") != string::npos)
            {
                employee[i].setId(data);
            }
            else if (line.find("Salary:") != string::npos)
            {
                if (line.find("$") != string::npos)
                {
                    data = data.substr(1);
                }
                size_t found = data.find(",");
                while (found != string::npos)
                {
                    data.erase(found, 1);
                    found = data.find(",");
                }
                employee[i].setSalary(data);
            }
            else if (line.find("Date of Joining:") != string::npos)
            {
                employee[i].setDateOfJoining(data);
            }
            else if (line.find("Designation:") != string::npos)
            {
                employee[i].setDesignation(data);
                i++;
            }
        }
    }
    inputFile.close();
}

template<typename EM2, typename S>
double findCompanyAvgSalary(EmployeeData<EM2>* employee, S size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += stod(employee[i].getSalary());
    }
    sum = sum / size;
    return sum;
}

template<typename EM3, typename S>
int findNumberOfEmployees(EmployeeData<EM3>* employee, S size)
{
    return size;
}

template<typename EM4, typename S>
double findCompanyAvgTenure(EmployeeData<EM4>* employee, S size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        string dateOfJoining = employee[i].getDateOfJoining();
        int joinYear = stoi(dateOfJoining.substr(0, 4));
        int joinMonth = stoi(dateOfJoining.substr(5, 2));
        int joinDay = stoi(dateOfJoining.substr(8, 2));
        time_t now = time(nullptr);
        tm timeInfo;
        localtime_s(&timeInfo, &now);
        int currentYear = timeInfo.tm_year + 1900;
        int currentMonth = timeInfo.tm_mon + 1;
        int currentDay = timeInfo.tm_mday;
        int tenure = currentYear - joinYear;
        if (currentMonth < joinMonth || (currentMonth == joinMonth && currentDay < joinDay))
        {
            tenure--;
        }
        sum += tenure;
    }
    double avgTenure = sum / size;
    return avgTenure;
}

template<typename EM5, typename S>
void EmployeeDistribution(EmployeeData<EM5>* employee, S size) // finding number of employees for each designation
{
    int noOfSE = 0, noOfSSE = 0, noOfDS = 0, noOfPM = 0, noOfDA = 0, noOfUXD = 0, noOfQAA = 0;
    for (int i = 0; i < size; i++)
    {
        if (employee[i].getDesignation() == "Software Engineer")
        {
            noOfSE++;
        }
        else if (employee[i].getDesignation() == "Senior Software Engineer")
        {
            noOfSSE++;
        }
        else if (employee[i].getDesignation() == "Data Scientist")
        {
            noOfDS++;
        }
        else if (employee[i].getDesignation() == "Project Manager")
        {
            noOfPM++;
        }
        else if (employee[i].getDesignation() == "Senior Data Analyst")
        {
            noOfDA++;
        }
        else if (employee[i].getDesignation() == "UX Designer")
        {
            noOfUXD++;
        }
        else if (employee[i].getDesignation() == "Quality Assurance Analyst")
        {
            noOfQAA++;
        }
    }
    // printing number of employees for each designation
    cout << "\033[1;32mNumber of Software Engineer: \033[0m" << noOfSE << endl;
    cout << "\033[1;32mNumber of Senior Software Engineer: \033[0m" << noOfSSE << endl;
    cout << "\033[1;32mNumber of Data Scientist: \033[0m" << noOfDS << endl;
    cout << "\033[1;32mNumber of Project Manager: \033[0m" << noOfPM << endl;
    cout << "\033[1;32mNumber of Senior Data Analyst: \033[0m" << noOfDA << endl;
    cout << "\033[1;32mNumber of UX Designer: \033[0m" << noOfUXD << endl;
    cout << "\033[1;32mNumber of Quality Assurance Analyst: \033[0m" << noOfQAA << endl;
}

int daysInMonth(int month, int year) // defing days of each month
{
    switch (month)
    {
    case 2:
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

double daysInYear(int year) // function to convert days in years
{
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return 366.0;
    }
    else
    {
        return 365.0;
    }
}
template<typename EM6, typename S>
EmployeeData<EM6> findEmployeeWithLongestTenure(EmployeeData<EM6>* employees, S size) //finding longest tenure with class return data type
{
    EmployeeData<EM6> longestTenureEmployee;
    double longestTenure = 0;
    for (int i = 0; i < size; i++)
    {
        string dateOfJoining = employees[i].getDateOfJoining();
        int joinYear = stoi(dateOfJoining.substr(0, 4));
        int joinMonth = stoi(dateOfJoining.substr(5, 2));
        int joinDay = stoi(dateOfJoining.substr(8, 2));
        time_t now = time(nullptr);
        tm timeInfo;
        localtime_s(&timeInfo, &now);
        int currentYear = timeInfo.tm_year + 1900;
        int currentMonth = timeInfo.tm_mon + 1;
        int currentDay = timeInfo.tm_mday;
        int years = currentYear - joinYear;
        int months = currentMonth - joinMonth;
        int days = currentDay - joinDay;
        if (days < 0)
        {
            months--;
            days += daysInMonth(joinMonth, joinYear);
        }
        if (months < 0)
        {
            years--;
            months += 12;
        }
        double tenure = years + (months / 12.0) + (days / daysInYear(currentYear));

        if (tenure > longestTenure)
        {
            longestTenure = tenure;
            longestTenureEmployee = employees[i];
        }
    }
    return longestTenureEmployee;
}

template<typename EM7, typename S>
double findEmployeeHighestSalary(EmployeeData<EM7>* employee, S size)
{
    double highestSalary = 0;
    int index = 0;
    for (int i = 0; i < size; i++) //finding highest salary via linear search
    {
        if (stod(employee[i].getSalary()) > highestSalary)
        {
            highestSalary = stod(employee[i].getSalary());
            index = i;
        }
    }
    cout << "\033[1;32mEmployee with highest salary is \033[0m" << employee[index].getName() << "\033[1;32m with salary of \033[0m$" << highestSalary << endl;
    return highestSalary;
}

template<typename EM8, typename S>
double findEmployeeLowestSalary(EmployeeData<EM8>* employee, S size) 
{
    double lowestSalary = stod(employee[0].getSalary());
    int index = 0;
    for (int i = 0; i < size; i++) //finding lowest salary via linear seach
    {
        if (stod(employee[i].getSalary()) < lowestSalary)
        {
            lowestSalary = stod(employee[i].getSalary());
            index = i;
        }
    }
    cout << "\033[1;32mEmployee with lowest salary is \033[0m" << employee[index].getName() << "\033[1;32m with salary of \033[0m$" << lowestSalary << endl;
    return lowestSalary;
}

template<typename EM9, typename S>
void findSalaryRange(EmployeeData<EM9>* employee, S size) // salary range
{
    double highestSalary = findEmployeeHighestSalary(employee, size);
    double lowestSalary = findEmployeeLowestSalary(employee, size);
    double range = highestSalary - lowestSalary;
    cout << "\033[1;32mSalary range is \033[0m$" << range << endl;
}

template<typename EM10, typename S>
void findSalaryMediam(EmployeeData<EM10>* employee, S size) //median
{
    double medianSalary = 0;
    if (size % 2 == 0) //if even
    {
        medianSalary = (stod(employee[size / 2].getSalary()) + stod(employee[(size / 2) - 1].getSalary())) / 2;
    }
    else // for odd
    {
        medianSalary = stod(employee[size / 2].getSalary());
    }
    cout << "\033[1;32mMedian salary is \033[0m$" << medianSalary << endl;
}

template<typename EM11, typename S>
void avgSalaryOfEachDesignation(EmployeeData<EM11>* employee, S size)
{
    double sumSE = 0, sumSSE = 0, sumDS = 0, sumPM = 0, sumDA = 0, sumUXD = 0, sumQAA = 0;
    int noOfSE = 0, noOfSSE = 0, noOfDS = 0, noOfPM = 0, noOfDA = 0, noOfUXD = 0, noOfQAA = 0;
    for (int i = 0; i < size; i++) // calculating avg salary
    {
        if (employee[i].getDesignation() == "Software Engineer")
        {
            sumSE += stod(employee[i].getSalary());
            noOfSE++;
        }
        else if (employee[i].getDesignation() == "Senior Software Engineer")
        {
            sumSSE += stod(employee[i].getSalary());
            noOfSSE++;
        }
        else if (employee[i].getDesignation() == "Data Scientist")
        {
            sumDS += stod(employee[i].getSalary());
            noOfDS++;
        }
        else if (employee[i].getDesignation() == "Project Manager")
        {
            sumPM += stod(employee[i].getSalary());
            noOfPM++;
        }
        else if (employee[i].getDesignation() == "Senior Data Analyst")
        {
            sumDA += stod(employee[i].getSalary());
            noOfDA++;
        }
        else if (employee[i].getDesignation() == "UX Designer")
        {
            sumUXD += stod(employee[i].getSalary());
            noOfUXD++;
        }
        else if (employee[i].getDesignation() == "Quality Assurance Analyst")
        {
            sumQAA += stod(employee[i].getSalary());
            noOfQAA++;
        }
    }
    //printing avg salary
    cout << "\033[1;32mAverage salary of Software Engineer: \033[0m$" << sumSE / noOfSE << endl;
    cout << "\033[1;32mAverage salary of Senior Software Engineer: \033[0m$" << sumSSE / noOfSSE << endl;
    cout << "\033[1;32mAverage salary of Data Scientist: \033[0m$" << sumDS / noOfDS << endl;
    cout << "\033[1;32mAverage salary of Project Manager: \033[0m$" << sumPM / noOfPM << endl;
    cout << "\033[1;32mAverage salary of Senior Data Analyst: \033[0m$" << sumDA / noOfDA << endl;
    cout << "\033[1;32mAverage salary of UX Designer: \033[0m$" << sumUXD / noOfUXD << endl;
    cout << "\033[1;32mAverage salary of Quality Assurance Analyst: \033[0m$" << sumQAA / noOfQAA << endl;
}

template<typename EM12, typename S>
void findEmployeeShortestTenure(EmployeeData<EM12>* employees, S size)  //shortest tenure
{
    EmployeeData<EM12> shortestTenureEmployee = employees[0]; //giving value to the varible
    double shortestTenure = 1.79769e+308;
    for (int i = 0; i < size; i++)
    {
        string dateOfJoining = employees[i].getDateOfJoining();
        int joinYear = stoi(dateOfJoining.substr(0, 4));
        int joinMonth = stoi(dateOfJoining.substr(5, 2));
        int joinDay = stoi(dateOfJoining.substr(8, 2));
        time_t now = time(nullptr);
        tm timeInfo;
        localtime_s(&timeInfo, &now);
        int currentYear = timeInfo.tm_year + 1900;
        int currentMonth = timeInfo.tm_mon + 1;
        int currentDay = timeInfo.tm_mday;
        int years = currentYear - joinYear;
        int months = currentMonth - joinMonth;
        int days = currentDay - joinDay;
        if (days < 0)
        {
            months--;
            days += daysInMonth(joinMonth, joinYear);
        }
        if (months < 0)
        {
            years--;
            months += 12;
        }
        double tenure = years + (months / 12.0) + (days / daysInYear(currentYear));

        if (tenure < shortestTenure)
        {
            shortestTenure = tenure;
            shortestTenureEmployee = employees[i];
        }
    }
    cout << "\033[1;32mEmployee with shortest tenure is \033[0m" << shortestTenureEmployee.getName() << endl;
}

template<typename EM13, typename S>
void avgTenureDesignation(EmployeeData<EM13>* employee, S size) // finding avg tenure
{
    double sumSE = 0, sumSSE = 0, sumDS = 0, sumPM = 0, sumDA = 0, sumUXD = 0, sumQAA = 0;
    int noOfSE = 0, noOfSSE = 0, noOfDS = 0, noOfPM = 0, noOfDA = 0, noOfUXD = 0, noOfQAA = 0;  //counter var
    int tenure = 0;
    int joinYear = 0;

    for (int i = 0; i < size; i++)
    {
        if (employee[i].getDesignation() == "Software Engineer")
        {
            string dateOfJoining = employee[i].getDateOfJoining();
            joinYear = stoi(dateOfJoining.substr(0, 4));
            time_t now = time(nullptr);
            tm timeInfo;
            localtime_s(&timeInfo, &now);
            int currentYear = timeInfo.tm_year + 1900;
            tenure = currentYear - joinYear;
            sumSE += tenure;
            noOfSE++;
        }
        else if (employee[i].getDesignation() == "Senior Software Engineer")
        {
            string dateOfJoining = employee[i].getDateOfJoining();
            joinYear = stoi(dateOfJoining.substr(0, 4));
            time_t now = time(nullptr);
            tm timeInfo;
            localtime_s(&timeInfo, &now);
            int currentYear = timeInfo.tm_year + 1900;
            tenure = currentYear - joinYear;
            sumSSE += tenure;
            noOfSSE++;
        }
        else if (employee[i].getDesignation() == "Data Scientist")
        {
            string dateOfJoining = employee[i].getDateOfJoining();
            joinYear = stoi(dateOfJoining.substr(0, 4));
            time_t now = time(nullptr);
            tm timeInfo;
            localtime_s(&timeInfo, &now);
            int currentYear = timeInfo.tm_year + 1900;
            tenure = currentYear - joinYear;
            sumDS += tenure;
            noOfDS++;
        }
        else if (employee[i].getDesignation() == "Project Manager")
        {
            string dateOfJoining = employee[i].getDateOfJoining();
            joinYear = stoi(dateOfJoining.substr(0, 4));
            time_t now = time(nullptr);
            tm timeInfo;
            localtime_s(&timeInfo, &now);
            int currentYear = timeInfo.tm_year + 1900;
            tenure = currentYear - joinYear;
            sumPM += tenure;
            noOfPM++;
        }
        else if (employee[i].getDesignation() == "Senior Data Analyst")
        {
            string dateOfJoining = employee[i].getDateOfJoining();
            joinYear = stoi(dateOfJoining.substr(0, 4));
            time_t now = time(nullptr);
            tm timeInfo;
            localtime_s(&timeInfo, &now);
            int currentYear = timeInfo.tm_year + 1900;
            tenure = currentYear - joinYear;
            sumDA += tenure;
            noOfDA++;
        }
        else if (employee[i].getDesignation() == "UX Designer")
        {
            string dateOfJoining = employee[i].getDateOfJoining();
            joinYear = stoi(dateOfJoining.substr(0, 4));
            time_t now = time(nullptr);
            tm timeInfo;
            localtime_s(&timeInfo, &now);
            int currentYear = timeInfo.tm_year + 1900;
            tenure = currentYear - joinYear;
            sumUXD += tenure;
            noOfUXD++;
        }
        else if (employee[i].getDesignation() == "Quality Assurance Analyst")
        {
            string dateOfJoining = employee[i].getDateOfJoining();
            joinYear = stoi(dateOfJoining.substr(0, 4));
            time_t now = time(nullptr);
            tm timeInfo;
            localtime_s(&timeInfo, &now);
            int currentYear = timeInfo.tm_year + 1900;
            tenure = currentYear - joinYear;
            sumQAA += tenure;
            noOfQAA++;
        }
    }
    cout << "\033[1;32mAverage Tenure of Software Engineer: \033[0m" << sumSE / noOfSE << " years" << endl;
    cout << "\033[1;32mAverage Tenure of Senior Software Engineer: \033[0m" << sumSSE / noOfSSE << " years" << endl;
    cout << "\033[1;32mAverage Tenure of Data Scientist: \033[0m" << sumDS / noOfDS << " years" << endl;
    cout << "\033[1;32mAverage Tenure of Project Manager: \033[0m" << sumPM / noOfPM << " years" << endl;
    cout << "\033[1;32mAverage Tenure of Senior Data Analyst: \033[0m" << sumDA / noOfDA << " years" << endl;
    cout << "\033[1;32mAverage Tenure of UX Designer: \033[0m" << sumUXD / noOfUXD << " years" << endl;
    cout << "\033[1;32mAverage Tenure of Quality Assurance Analyst: \033[0m" << sumQAA / noOfQAA << " years" << endl;
}

template<typename EM14, typename S>
void findHighestPayingDesignation(EmployeeData<EM14>* employee, S size)
{
    double highestSalary = 0;
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (stod(employee[i].getSalary()) > highestSalary)
        {
            highestSalary = stod(employee[i].getSalary());
            index = i;
        }
    }
    cout << "\033[1;32mHighest paying designation is \033[0m" << employee[index].getDesignation() << "\033[1;32m with salary of \033[0m$" << highestSalary << endl;
}

template<typename EM15, typename S> //Bubble Sort
void sortEmployeesSalaryBubble(EmployeeData<EM15>* employees, S size)
{
    int comparisons = 0;
    int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if (stod(employees[j].getSalary()) < stod(employees[minIndex].getSalary()))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(employees[i], employees[minIndex]);
            swaps++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;

    cout << "\033[1;32mSorted list of employees by salary:\033[0m" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << employees[i].getName() << " - $" << employees[i].getSalary() << endl;
    }

    cout << "\033[1;32mExecution time:\033[0m " << fixed << setprecision(5) << time_taken << " seconds" << endl;
    cout << "\033[1;32mComparisons performed:\033[0m " << comparisons << endl;
    cout << "\033[1;32mSwaps performed:\033[0m " << swaps << endl;
}

template<typename EM15, typename S> // Selection Sort
void sortEmployeesSalarySelection(EmployeeData<EM15>* employees, S size)
{
    int comparisons = 0;
    int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            if (stod(employees[j].getSalary()) < stod(employees[minIndex].getSalary()))
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(employees[i], employees[minIndex]);
            swaps++;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;

    cout << "\033[1;32mSorted list of employees by salary:\033[0m" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << employees[i].getName() << " - $" << employees[i].getSalary() << endl;
    }

    cout << "\033[1;32mExecution time:\033[0m " << fixed << setprecision(5) << time_taken << " seconds" << endl;
    cout << "\033[1;32mComparisons performed:\033[0m " << comparisons << endl;
    cout << "\033[1;32mSwaps performed:\033[0m " << swaps << endl;
}

template<typename EM15, typename S> //Insertion Sort
void sortEmployeesSalaryInsertion(EmployeeData<EM15>* employees, S size)
{
    int comparisons = 0;
    int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < size; i++)
    {
        EmployeeData<EM15> key = employees[i];
        int j = i - 1;
        while (j >= 0 && stod(employees[j].getSalary()) > stod(key.getSalary()))
        {
            comparisons++;
            employees[j + 1] = employees[j];
            j--;
            swaps++;
        }
        employees[j + 1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;

    cout << "\033[1;32mSorted list of employees by salary:\033[0m" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << employees[i].getName() << " - $" << employees[i].getSalary() << endl;
    }

    cout << "\033[1;32mExecution time:\033[0m " << fixed << setprecision(5) << time_taken << " seconds" << endl;
    cout << "\033[1;32mComparisons performed:\033[0m " << comparisons << endl;
    cout << "\033[1;32mSwaps performed:\033[0m " << swaps << endl;
}

template<typename EM15, typename S>
void sortEmployeesTenureBubble(EmployeeData<EM15>* employees, S size)
{
    int comparisons = 0;
    int swaps = 0;

    time_t now = time(nullptr);
    tm timeInfo;
    localtime_s(&timeInfo, &now);
    int currentYear = timeInfo.tm_year + 1900;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            comparisons++;
            string dateOfJoining = employees[j].getDateOfJoining();
            int joinYear = stoi(dateOfJoining.substr(0, 4));
            string dateOfJoining2 = employees[j + 1].getDateOfJoining();
            int joinYear2 = stoi(dateOfJoining2.substr(0, 4));
            int tenure1 = currentYear - joinYear;
            int tenure2 = currentYear - joinYear2;
            if (tenure1 > tenure2)
            {
                swap(employees[j], employees[j + 1]);
                swaps++;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000.0;

    cout << "\033[1;32mSorted list of employees by tenure:\033[0m" << endl;
    for (int i = 0; i < size; i++)
    {
        string dateOfJoining = employees[i].getDateOfJoining();
        int joinYear = stoi(dateOfJoining.substr(0, 4));
        int tenure = currentYear - joinYear;
        cout << i + 1 << ". " << employees[i].getName() << " - " << tenure << " years" << endl;
    }

    cout << "\033[1;32mExecution time:\033[0m " << fixed << setprecision(5) << time_taken << " seconds" << endl;
    cout << "\033[1;32mComparisons performed:\033[0m " << comparisons << endl;
    cout << "\033[1;32mSwaps performed:\033[0m " << swaps << endl;
}

template<typename EM15, typename S> //Selection Sort
void sortEmployeesTenureSelection(EmployeeData<EM15>* employees, S size)
{
    int comparisons = 0;
    int swaps = 0;

    time_t now = time(nullptr);
    tm timeInfo;
    localtime_s(&timeInfo, &now);
    int currentYear = timeInfo.tm_year + 1900;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            comparisons++;
            string dateOfJoining = employees[j].getDateOfJoining();
            int joinYear = stoi(dateOfJoining.substr(0, 4));
            string dateOfJoining2 = employees[minIndex].getDateOfJoining();
            int joinYear2 = stoi(dateOfJoining2.substr(0, 4));
            int tenure1 = currentYear - joinYear;
            int tenure2 = currentYear - joinYear2;
            if (tenure1 < tenure2)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(employees[i], employees[minIndex]);
            swaps++;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000.0;

    cout << "\033[1;32mSorted list of employees by tenure:\033[0m" << endl;
    for (int i = 0; i < size; i++)
    {
        string dateOfJoining = employees[i].getDateOfJoining();
        int joinYear = stoi(dateOfJoining.substr(0, 4));
        int tenure = currentYear - joinYear;
        cout << i + 1 << ". " << employees[i].getName() << " - " << tenure << " years" << endl;
    }

    cout << "\033[1;32mExecution time:\033[0m " << fixed << setprecision(5) << time_taken << " seconds" << endl;
    cout << "\033[1;32mComparisons performed:\033[0m " << comparisons << endl;
    cout << "\033[1;32mSwaps performed:\033[0m " << swaps << endl;
}

template<typename EM15, typename S> //Insertion Sort
void sortEmployeesTenureInsertion(EmployeeData<EM15>* employees, S size)
{
    int comparisons = 0;
    int swaps = 0;

    time_t now = time(nullptr);
    tm timeInfo;
    localtime_s(&timeInfo, &now);
    int currentYear = timeInfo.tm_year + 1900;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < size; i++)
    {
        EmployeeData<EM15> key = employees[i];
        int j = i - 1;
        while (j >= 0 && (currentYear - stoi(employees[j].getDateOfJoining().substr(0, 4))) > (currentYear - stoi(key.getDateOfJoining().substr(0, 4))))
        {
            comparisons++;
            employees[j + 1] = employees[j];
            j--;
            swaps++;
        }
        employees[j + 1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000000.0;

    cout << "\033[1;32mSorted list of employees by tenure:\033[0m" << endl;
    for (int i = 0; i < size; i++)
    {
        string dateOfJoining = employees[i].getDateOfJoining();
        int joinYear = stoi(dateOfJoining.substr(0, 4));
        int tenure = currentYear - joinYear;
        cout << i + 1 << ". " << employees[i].getName() << " - " << tenure << " years" << endl;
    }

    cout << "\033[1;32mExecution time:\033[0m " << fixed << setprecision(5) << time_taken << " seconds" << endl;
    cout << "\033[1;32mComparisons performed:\033[0m " << comparisons << endl;
    cout << "\033[1;32mSwaps performed:\033[0m " << swaps << endl;
}