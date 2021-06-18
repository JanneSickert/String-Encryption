#include <iostream>
#include "Crypto.h"
#include "StringArray.h"

using namespace std;

void p(string str);
void test();
bool checkString(string text, string key);

int main() {
	test();
	return 0;
}

void test() {
	StringArray text;
	text.addString("A long text or string to check if the encryption work or not...");
	text.addString("more and more text");
	text.addString("jfhgzfgghfdf7zg87z87z87z87z//////%%%%%%%%%%%%%%%$$$$$$$$........");
	text.addString("7458758787436187919367651596L415315135134ßßßßß");
	text.addString("a b c d e!");
	text.addString("C:/folder1/gg jjhd hh/subFolder2/file.xml");
	StringArray password;
	password.addString("myPassword#123&42");
	password.addString("6283746873269587235");
	password.addString("AAAAAAAAA4444//&&%!'§$%&/()=?");
	password.addString("#'+66-88=-22	ÄÄääöö<>");
	password.addString("theLastPassword");
	int i, k;
	int nrOfTests = text.getSize() * password.getSize();
	int controll_nr = 0;
	for (i = 0; i < text.getSize(); ++i) {
		for (k = 0; k < password.getSize(); ++k) {
			if (checkString(text.getStringByIndex(i), password.getStringByIndex(k))) {
				p("test complete");
				++controll_nr;
			}
		}
	}
	if (controll_nr == nrOfTests) {
		p("All tests went well");
	}
	else {
		p("Not all tests went well");
	}
	cout << controll_nr;
	cout << " from ";
	cout << nrOfTests;
}

bool checkString(string text, string key) {
	string crypt = encrypt(text, key);
	p(crypt);
	string decryptText = decrypt(crypt, key);
	p(decryptText);
	return (text.compare(decryptText) == 0);
}

void p(string str) {
	cout << str << endl;
}