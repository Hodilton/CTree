#pragma once
#include "stdafx.h"

class CData {
public:
	char ch;
	int value;

	CData() : ch(0), value(0) {}
	CData(const char& ch, const int& value) : ch(ch), value(value) {}
	CData(const CData& another) { this->ch = another.ch; this->value = another.value; }

	CData& operator=(const CData& another) {
		this->ch = another.ch;
		this->value = another.value;
		return *this;
	}

	bool operator<(const CData& another) const {
		return value < another.value&& ch < another.ch;
	}

	bool operator>(const CData& another) const {
		return ! (*this < another);
	}

	friend istream& operator>>(istream& in, CData& another) {
		return in;
	}

	friend ostream& operator<<(ostream& out, CData& another) {
		out << "ch: " << another.ch << endl;
		out << "value: " << another.value << endl;
		return out;
	}
};