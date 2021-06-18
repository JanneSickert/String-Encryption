#include "Crypto.h"

char add(char a, char b);
char sub(char a, char b);

std::string encrypt(std::string text, std::string key) {
	std::string cryname = text;
	int i = 0;
	int k = 0;
	while (text[i] != NULL) {
		while (key[k] != NULL) {
			if (text[i] != NULL) {
				cryname[i] = add(text.at(i), key.at(k));
				++i;
			}
			++k;
		}
		k = 0;
	}
	return cryname;
}

std::string decrypt(std::string text, std::string key) {
	std::string cryname = text;
	int i = 0;
	int k = 0;
	while (text[i] != NULL) {
		while (key[k] != NULL) {
			if (text[i] != NULL) {
				cryname[i] = sub(text.at(i), key.at(k));
				++i;
			}
			++k;
		}
		k = 0;
	}
	return cryname;
}

char add(char a, char b) {
	int c = int(a) + int(b);
	if (c > UNI_MAX) {
		c = c - UNI_MAX;
	}
	char d = char(c);
	return d;
}

char sub(char a, char b) {
	int c = int(a) - int(b);
	if (c < 0) {
		c = c + UNI_MAX + 1;
	}
	char d = char(c);
	return d;
}