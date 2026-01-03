#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    char choice = 'Y';

    while (choice == 'Y' || choice == 'y') {

        string password;
        cout << "\nEnter a password: ";
        getline(cin, password);

        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSymbol = false;
        int minLength = 8;

        for (char ch : password) {
            if (isupper(static_cast<unsigned char>(ch)))
                hasUpper = true;
            else if (islower(static_cast<unsigned char>(ch)))
                hasLower = true;
            else if (isdigit(static_cast<unsigned char>(ch)))
                hasDigit = true;
            else
                hasSymbol = true;
        }

        bool longEnough = password.length() >= minLength;

        cout << "\nPassword Checklist:\n";
        cout << "Minimum length (>= " << minLength << "): " << (longEnough ? "YES" : "NO") << endl;
        cout << "Contains uppercase letter: " << (hasUpper ? "YES" : "NO") << endl;
        cout << "Contains lowercase letter: " << (hasLower ? "YES" : "NO") << endl;
        cout << "Contains number: " << (hasDigit ? "YES" : "NO") << endl;
        cout << "Contains symbol: " << (hasSymbol ? "YES" : "NO") << endl;

        if (longEnough && hasUpper && hasLower && hasDigit && hasSymbol) {
            cout << "\nPassword Strength: STRONG\n";
        } else {
            cout << "\nPassword Strength: WEAK\n";
        }

        // Validate user input
        do {
            cout << "\nTry a new password? (Y/N): ";
            cin >> choice;
            cin.ignore(1000, '\n');

            if (choice != 'Y' && choice != 'y' &&
                choice != 'N' && choice != 'n') {
                cout << "Invalid input. Please enter Y or N.\n";
            }

        } while (choice != 'Y' && choice != 'y' &&
                 choice != 'N' && choice != 'n');
    }

    cout << "\nProgram ended.\n";
    return 0;
}
