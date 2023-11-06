#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Class template for EmployeeData
template <typename T>
class EmployeeData {
public:
    T name;
    T id;
    T salary;
    T dateOfJoining;
    T designation;

    EmployeeData() : name(T()), id(T()), salary(T()), dateOfJoining(T()), designation(T()) {}
};

int main() {
    ifstream inputFile("Employeedata.txt"); // Replace with your file path

    if (!inputFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string line;
    EmployeeData<string> employee; // You can use string for all fields

    while (getline(inputFile, line)) {
        size_t pos = line.find(":");
        if (pos != string::npos) {
            string field = line.substr(pos + 2); // Skip ":" and get the data
            if (line.find("Employee Name:") != string::npos) {
                employee.name = field;
            } else if (line.find("Employee ID:") != string::npos) {
                employee.id = field;
            } else if (line.find("Salary:") != string::npos) {
                employee.salary = field;
            } else if (line.find("Date of Joining:") != string::npos) {
                employee.dateOfJoining = field;
            } else if (line.find("Designation:") != string::npos) {
                employee.designation = field;
            }
        }
    }

    // Now you have the data in the EmployeeData object
    cout << "Employee Name: " << employee.name << endl;
    cout << "Employee ID: " << employee.id << endl;
    cout << "Salary: " << employee.salary << endl;
    cout << "Date of Joining: " << employee.dateOfJoining << endl;
    cout << "Designation: " << employee.designation << endl;

    inputFile.close();
    return 0;
}
