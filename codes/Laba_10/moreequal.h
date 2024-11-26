#ifndef MOREEQUAL_H
#define MOREEQUAL_H

#include <string>
#include <iostream>
using namespace std;

class MoreEqual {
private:
    string str;

public:
    MoreEqual();
    MoreEqual(const string& inputStr);
    ~MoreEqual();

    string getStr() const;

    void setStr();

    bool operator>=(const MoreEqual& other) const;  // перевантаження операторів
    MoreEqual operator-(char ch) const;

    friend ostream& operator<<(ostream& out, const MoreEqual& obj); // перевантаження виводу
    friend istream& operator>>(istream& in, MoreEqual& obj); //перевантаження вводу
};
#endif 