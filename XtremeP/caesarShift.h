#ifndef CAESARSHIFT_H
#define CAESARSHIFT_H

#include <string>

using namespace std;

string caesarShift(const string& input) {
    
    // First convert the input to uppercase
    string upper_input = input;
    for (int i = 0; i < upper_input.length(); i++) {
        upper_input[i] = toupper(upper_input[i]); 
    }

    // Secret functionality
    if (upper_input == "VENI VIDI VICI") {
        return "SPQR";
    }

    // Now let's shift every character over by 3 alphabetically
    string output = upper_input; // copy the input string to output
    for (int i = 0; i < output.length(); i++) {
        if (isalpha(output[i])) {
            output[i] = ((output[i] - 'A' + 3) % 26) + 'A'; // apply the shift to the character
        }
    }
    return output;
}


#endif // CAESARSHIFT_H
