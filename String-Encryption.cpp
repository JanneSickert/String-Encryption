#include <iostream>
#include "Crypto.h"

using namespace std;

void p(string str);

int main() {
	string test_input = "A long text or string to check if the encryption work or not...";
	string password = "myPassword#123&42";
	string crypt = encrypt(test_input, password);
	p(crypt);
	string decryptText = decrypt(crypt, password);
	p(decryptText);
	return 0;
}

void p(string str) {
	cout << str << endl;
}