#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// ---This is The Function to display the header ---
void displayHeader() {
    cout << "========================================" << endl;
    cout << "       SFORTE MFB LOAN SYSTEM v3.0      " << endl;
    cout << "      Session Tracking Enabled          " << endl;
    cout << "========================================" << endl;
}

// --- This is the Function to validate double inputs ---
double getValidDouble(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value <= 0) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "[Error] Please enter a positive numerical value." << endl;
        } else {
            return value;
        }
    }
}

// ---This is the Function to validate integer inputs ---
// this function ensures that the user inputs a positive integer for the number of months, and it will keep prompting until a valid input is received. it 
int getValidInt(string prompt) {
    int value;
    // this while loop will continue until a valid input is received
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
    
    // --- NEW: Session Accumulators (Defined OUTSIDE the loop) ---
    double sessionTotalPrincipal = 0;
    double sessionTotalInterest = 0;
    int loansCalculated = 0;

    while (repeat == 'y' || repeat == 'Y') {
        system("cls"); 
        displayHeader();

        double principal = getValidDouble("Enter Loan Principal (Naira): ");
        double annualRate = getValidDouble("Enter Annual Interest Rate (%): ");
        int months = getValidInt("Enter Duration (Months): ");

        double totalInterest = (principal * annualRate * months) / (1200);
        double totalPayable = principal + totalInterest;
        double monthlyPayment = totalPayable / months;

        // --- NEW: Update Session Totals ---
        sessionTotalPrincipal += principal;
        sessionTotalInterest += totalInterest;
        loansCalculated++;

        cout << fixed << setprecision(2);
        cout << "\n--- CALCULATION RESULTS ---" << endl;
        cout << left << setw(20) << "Principal:" << "N" << principal << endl;
        cout << left << setw(20) << "Total Interest:" << "N" << totalInterest << endl;
        cout << left << setw(20) << "Monthly Pay:" << "N" << monthlyPayment << endl;
        
        cout << "\nCalculate another loan? (y/n): ";
        cin >> repeat;
    }

    // --- NEW: THIS IS THE GRAND SESSION SUMMARY ---
    // This only runs when the user types 'n' to exit
    system("cls");
    cout << "========================================" << endl;
    cout << "       FINAL SESSION REPORT             " << endl;
    cout << "========================================" << endl;
    cout << left << setw(25) << "Total Loans Processed:" << loansCalculated << endl;
    cout << left << setw(25) << "Total Principal Issued:" << "N" << sessionTotalPrincipal << endl;
    cout << left << setw(25) << "Total Interest Earned:" << "N" << sessionTotalInterest << endl;
    cout << "----------------------------------------" << endl;
    cout << left << setw(25) << "GRAND TOTAL REVENUE:" << "N" << (sessionTotalPrincipal + sessionTotalInterest) << endl;
    cout << "========================================" << endl;
    cout << "Press any key to close the system..." << endl;

    return 0;
}