#include "StringArray.h"

StringArray::StringArray() {
    size = 0;
    gll = 0;
    firstIndex = "0" + DSTRING;
    lastIndex = "";
    storage = "";
}

void StringArray::addString(std::string str) {
    int lll = str.size() - 1;
    if (size == 0) {
        gll = lll + 1;
        lastIndex = toString(lll) + DSTRING;
    }
    else {
        firstIndex = firstIndex + toString(gll) + DSTRING;
        lastIndex = lastIndex + toString(gll + lll) + DSTRING;
        gll = gll + lll + 1;
    }
    storage = storage + str;
    ++size;
}

std::string StringArray::getStringByIndex(int index) {
    if (index < size) {
        i = 0;
        to = index;
        std::string start = goTo(firstIndex);
        i = 0;
        std::string ende = goTo(lastIndex);
        int a = toInt(start);
        int b = int(toInt(ende) + 1);
        std::string resultString = getElementFromStorage(a, b);
        return resultString;
    }
    else {
        std::cout << "ERROR(in class StringArray): Index out of range.";
        exit(1);
    }
}

int StringArray::getSize() {
    return size;
}

void StringArray::deleteAll() {
    size = 0;
    gll = 0;
    firstIndex = "0" + DSTRING;
    lastIndex = "";
    storage = "";
}

const char DCHAR = '|';
const std::string DSTRING = "|";
std::string firstIndex;         // example: 00|11|33|41
std::string lastIndex;          // example: 10|32|40|78
std::string storage;            // example: string1|string2|string3|
int size;                       // Nr of stored strings.
int gll;                        // The first index of the next string.

std::string StringArray::getElementFromStorage(int a, int b) {
    std::string res = "";
    int localI;
    for (localI = a; localI < b; ++localI) {
        res.push_back(storage[localI]);
    }
    return res;
}

std::string StringArray::toString(int nr) {
    std::string s = std::to_string(nr);
    return s;
}

int StringArray::toInt(std::string nr) {
    std::stringstream strStream;
    int de;
    strStream << nr;
    strStream >> de;
    return de;
}

int to, i;

std::string StringArray::goTo(std::string str) {
    int dd = str.find(DCHAR);
    if (i < to) {
        ++i;
        int inc_dd = 1 + dd;
        return (goTo(str.substr(inc_dd, str.size())));
    }
    else {
        return (str.substr(0, dd));
    }
}