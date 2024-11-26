#include "moreequal.h"
#include <algorithm>

MoreEqual::MoreEqual() : str("") {}

MoreEqual::MoreEqual(const string& inputStr) : str(inputStr) {}

MoreEqual::~MoreEqual() {}

string MoreEqual::getStr() const {
    return str;
}

void MoreEqual::setStr() {
    cout << "Enter a new string value: ";
    cin >> str;
}

bool MoreEqual::operator>=(const MoreEqual& other) const {  // Перевантаження оператора >=
    return str >= other.str;
}

MoreEqual MoreEqual::operator-(char ch) const { // Перевантаження оператора - (вилучення символу)
    MoreEqual result(*this);
    result.str.erase(remove(result.str.begin(), result.str.end(), ch), result.str.end());
    return result;
}

ostream& operator<<(ostream& out, const MoreEqual& obj) { // перевантаження оператора виводу
    out << obj.str;
    return out;
}

istream& operator>>(istream& in, MoreEqual& obj) { // Зчитування з потоку
    in >> obj.str;
    return in;
}