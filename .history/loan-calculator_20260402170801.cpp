#include <iostream>
#include <iomanip> // For formatting decimals

using namespace std;

int main() {
    // 1. Variable Declaration
    double principal, annualRate, totalAmount, totalInterest, monthlyRepayment;
    int months;

    // 2. User Input with basic validation
    cout << "--- Sforte MFB Loan Calculator ---" << endl;
    cout << "Enter Loan Amount (Naira): ";
    cin >> principal;
    
    cout << "Enter Annual Interest Rate (e.g., 15 for 15%): ";
    cin >> annualRate;
    
    cout << "Enter Loan Duration (Number of months): ";
    cin >> months;

    // 3. Calculation Logic
    // We divide by 12 to get the monthly portion of the annual rate
    totalInterest = (principal * annualRate * months) / (12 * 100);
    totalAmount = principal + totalInterest;
    monthlyRepayment = totalAmount / months;

    // 4. Formatted Output
    cout << fixed << setprecision(2); // Keeps output to 2 decimal places like 0.00
    cout << "\n--- Loan Summary ---" << endl;
    cout << "Principal:      N" << principal << endl;
    cout << "Total Interest: N" << totalInterest << endl;
    cout << "Total Payable:  N" << totalAmount << endl;
    cout << "Monthly Pay:    N" << monthlyRepayment << endl;
    cout << "--------------------" << endl;

    return 0;
}