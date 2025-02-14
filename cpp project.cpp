#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold operation details
struct Operation {
    double num1, num2;
    char op;
    double result;
};

// Class for Calculator
class Calculator {
public:
    // Function to perform calculation
    double calculate(double num1, double num2, char op) {
        switch (op) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': return (num2 != 0) ? num1 / num2 : 0; // Avoid division by zero
            default: return 0;
        }
    }

    // Function to save result to file
    void saveToFile(Operation *op) {
        ofstream file("calculator_history.txt", ios::app);
        if (file.is_open()) {
            file << op->num1 << " " << op->op << " " << op->num2 << " = " << op->result << endl;
            file.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

int main() {
    Calculator calc;
    Operation op;
    string input;

    // User input
    cout << "Enter first number: ";
    cin >> op.num1;
    cout << "Enter operator (+, -, *, /): ";
    cin >> op.op;
    cout << "Enter second number: ";
    cin >> op.num2;

    // Use pointer to structure
    Operation *ptr = &op;
    ptr->result = calc.calculate(ptr->num1, ptr->num2, ptr->op);

    // Display result
    cout << "Result: " << ptr->result << endl;

    // Save result to file
    calc.saveToFile(ptr);
    
    return 0;
}