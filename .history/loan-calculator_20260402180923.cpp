#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// --- Function to display the header ---
void displayHeader() {
    cout << "========================================" << endl;
    cout << "       SFORTE MFB LOAN SYSTEM v2.0      " << endl;
    cout << "      Dei-Dei Market Branch, Abuja      " << endl;
    cout << "========================================" << endl;
}

// --- Function to validate double inputs ---
double getValidDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear(); // clear error flag
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "[Error] Please enter a positive numerical value." << endl;
        } else {
            return value;
        }
    }
}

// --- Function to validate integer inputs ---
int getValidInt(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[Error] Please enter a valid number of months." << endl;
        } else {
            return value;
        }
    }
}

int main() {
    char repeat = 'y';
    
    while (repeat == 'y' || repeat == 'Y') {
        system("cls"); // Clears the screen for a professional look (Windows)
        displayHeader();

        // 1. Inputs using our validation functions
        double principal = getValidDouble("Enter Loan Principal (Naira): ");
        double annualRate = getValidDouble("Enter Annual Interest Rate (%): ");
        int months = getValidInt("Enter Duration (Months): ");

        // 2. Logic Calculations
        double totalInterest = (principal * annualRate * months) / (1200);
        double totalPayable = principal + totalInterest;
        double monthlyPayment = totalPayable / months;

        // 3. Displaying Results
        cout << fixed << setprecision(2);
        cout << "\n--- CALCULATION RESULTS ---" << endl;
        cout << left << setw(20) << "Principal:" << "N" << principal << endl;
        cout << left << setw(20) << "Interest Rate:" << annualRate << "%" << endl;
        cout << left << setw(20) << "Total Interest:" << "N" << totalInterest << endl;
        cout << left << setw(20) << "Total Payable:" << "N" << totalPayable << endl;
        cout << left << setw(20) << "Monthly Installment:" << "N" << monthlyPayment << endl;
        
        // 4. Detailed Repayment Schedule (Adds complexity/lines)
        cout << "\n--- MONTHLY REPAYMENT BREAKDOWN ---" << endl;
        cout << setw(10) << "Month" << setw(15) << "Payment" << setw(20) << "Remaining Bal" << endl;
        double currentBalance = totalPayable;
        for (int i = 1; i <= months; i++) {
            currentBalance -= monthlyPayment;
            // Force balance to 0 if it's a tiny decimal
            if (currentBalance < 0) currentBalance = 0; 
            cout << setw(10) << i << setw(15) << monthlyPayment << setw(20) << currentBalance << endl;
        }

        cout << "\n========================================" << endl;
        cout << "Calculate another loan? (y/n): ";
        cin >> repeat;
    }

    cout << "\nThank you for using Sforte MFB Systems. Goodbye!" << endl;
    return 0;
}