#pragma once

#include <iostream>
#include <sstream>
#include <string>

#ifndef STRING_ARRAY
#define STRING_ARRAY

class StringArray {
public:
    StringArray();
    void addString(std::string str);
    std::string getStringByIndex(int index);
    int getSize();
    void deleteAll();
private:
    const char DCHAR = '|';
    const std::string DSTRING = "|";
    std::string firstIndex;     // example: 00|11|33|41
    std::string lastIndex;      // example: 10|32|40|78
    std::string storage;            // example: string1|string2|string3|
    int size;                       // Nr of stored strings.
    int gll;                        // The first index of the next string.
    std::string getElementFromStorage(int a, int b);
    std::string toString(int nr);
    int toInt(std::string nr);
    int to, i;
    std::string goTo(std::string str);
};
#endif