#include <iostream>
#include <stdlib.h> // For srand setup.
#include "caesarShift.h" // include the Caesar Shift implementation
#include "secret_cipher.h" // include the Rail Fence implementation
#include "random_cipher.h" // include the Random Cipher implementation

using namespace std;

int main() {
	srand(time(NULL));
    int method;
    while (true) {
        cout << "Please choose an encryption method:\n"
            << "1. Caesar Shift\n"
            << "2. Rail Fence\n"
            << "3. Random Cipher\n";
        if (!(cin >> method)) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
            cout << "Invalid input. Please choose a number from 1 to 3." << endl;
            continue;
        }
        if (method >= 1 && method <= 3) {
            break;
        }
        cout << "Invalid input. Please choose a number from 1 to 3." << endl;
    }

    string input;
    cout << "Please enter the message to be encrypted: ";
    cin.ignore(); // ignore the newline character from the previous input
    getline(cin, input); // read the input message from the user

    string output;
    switch (method) {
    case 1: // Caesar Shift
        output = caesarShift(input);
        break;
    case 2: // Rail Fence
        int numRows;
        cout << "Please enter the number of rows for the Rail Fence: ";
        if (!(cin >> numRows)) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the invalid input
            cout << "Invalid input. Please enter an integer." << endl;
            return 1;
        }
        output = secret_cipher(input, numRows);
        break;
    case 3: // Random Cipher
        output = random_cipher(input); (need to have correct call to random cipher here)
        break;
    }

    cout << "Encrypted message: " << output << endl;

    return 0;
}
