#include "pch.h"

#include "secret_cipher.h"

using namespace std;

string secret_cipher(string plain, int key) {

	// Remove spaces, transform to upper case.
	plain.erase(remove_if(plain.begin(), plain.end(), isspace), plain.end());
	transform(plain.begin(), plain.end(), plain.begin(), ::toupper);

	// "Blocks" in a sense.
	string *lines = new string[key];

	int line = 0;
	for (int i = 0; i < plain.length(); i++) {
		lines[line] += plain[i];
		// Increments or decrements the line being added to, depending
		// on the index in the plaintext, and the key.
		if (div(i, key - 1).quot % 2) {
			line--;
		}
		else {
			line++;
		}
	}

	// Appends all blocks.
	string cipher = "";
	for (int i = 0; i < key; i++) {
		cipher.append(lines[i]);
	}

	delete[] lines;

	return cipher;
}