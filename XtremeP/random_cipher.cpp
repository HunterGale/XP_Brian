#include "pch.h";

#include "random_cipher.h";
#include <stdlib.h>;
#include <time.h>;

using namespace std;

// Shift's each number a random amount.
string random_cipher(string plaintext) {

	string ciphertext = "";
	for (int i = 0; i < plaintext.length(); i++) {
		if (isalpha(plaintext[i])) {
			int randShift = rand() % 25 + 1;
			ciphertext += ((plaintext[i] - 'A' + randShift) % 26) + 'A'; // apply the shift to the character
		}
	}

	return ciphertext;
}