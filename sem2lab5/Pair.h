#pragma once
#include <iostream>


class Pair {
private:
	int left;
	int right;
public:
	Pair() {};
	Pair(int val1, int val2) : left(val1), right(val2) {};
	friend std::ostream& operator<<(std::ostream& out, const Pair &p) {
		out << p.left << "\t" << p.right;
		return out;
	}
};
