#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int balance, numEmployees;
    
    // Read initial balance
    cin >> balance;

    // Read number of employees
    cin >> numEmployees;

    // Read employee names
    vector<string> employeeNames(numEmployees);
    for (int i = 0; i < numEmployees; i++) {
        cin >> employeeNames[i];
    }

    // Read employee salaries
    vector<int> salaries(numEmployees);
    for (int i = 0; i < numEmployees; i++) {
        cin >> salaries[i];
    }

    // Process salary payments
    for (int i = 0; i < numEmployees; i++) {
        if (salaries[i] <= balance) {
            cout << "true ";
            balance -= salaries[i];
        } else {
            cout << "false ";
        }
    }

    return 0;
}