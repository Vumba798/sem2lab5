#include <iostream>
#include <string>
#include "Templates.h"
#include <vector>
	

using std::endl;
using std::cin;
using std::cout;
using std::cerr;



int main() {
	
	Vector<int> vec2;
	vec2.push_back(1);
	vec2.push_back(2);
	vec2.push_back(3);
	cout << vec2[1] << endl;
	cout << vec2.at(1) << endl;
	Vector<int> vec(vec2);
	cout << "vec empt" << vec.empty() << endl << endl;
	vec.push_back(3);
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec.push_back(5);
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec.push_back(6);
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec.push_back(7);
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec.insert(3, 500);
	vec.print();
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec.erase(2);
	vec.print();
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec.erase(1, 4);
	vec.print();
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl << endl;
	cout << "vec before";
	vec.print();
	cout << "vec2 before";
	vec2.print();
	vec.swap(vec2);
	cout << "vec after";
	vec.print();
	cout << "vec2 after";
	vec2.print();
	cout << "vec back = " << vec.back() << endl;
	cout << "vec front = " << vec.front() << endl;
	cout << "pop back = " << vec.pop_back() << endl;
	vec.clear();
	cout << "vec is empty? " << vec.empty() << endl;


	cout << "###############################################################" << endl;

	Vector<const char*> vec3;
	vec3.push_back("hi");
	vec3.push_back("buddy");
	vec3.push_back("i have a gift for you");
	Vector<const char*> vec4(vec3);
	cout << "vec empt" << vec.empty() << endl << endl;
	vec4.push_back("why");
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec4.push_back("are");
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec4.push_back("you");
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec4.push_back("running");
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec4.insert(3, "pups");
	vec4.print();
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec4.erase(0);
	vec4.print();
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl;
	vec4.erase(1, 4);
	vec4.print();
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl << endl;
	cout << "vec before";
	vec4.print();
	cout << "vec2 before";
	vec3.print();
	vec4.swap(vec3);
	cout << "vec after";
	vec4.print();
	cout << "vec2 after";
	vec3.print();
	cout << "vec back = " << vec4.back() << endl;
	cout << "vec front = " << vec4.front() << endl;
	cout << "pop back = " << vec4.pop_back() << endl;
	cout << "vec3 is empty???" << vec3.empty() << endl;
	vec3.clear();
	cout << "vec3 is empty???" << vec3.empty() << endl;


	cout << "###############################################################" << endl;

	Vector<Pair> vec5;
	vec5.push_back(Pair(2,1));
	vec5.insert(0,Pair(3,4));
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl << endl;
	vec5.print();
	vec5.push_back(Pair(0, 0));
	vec5.push_back(Pair(3, 2));
	vec5.print();
	Vector<Pair> vec6(vec5);
	cout << vec6.front() << endl << vec6.back() << endl << vec6.at(2) << endl;
	vec6.insert(2, Pair(40, 20));
	vec6.print();
	vec6.erase(1, 2);
	cout << "vec.capacity = " << vec.capacity() << "\t vec.size = " << vec.size() << endl << endl;
	cout << "vec6 before";
	vec6.print();
	cout << "vec5 before";
	vec5.print();
	vec6.swap(vec5);
	cout << "vec6 after";
	vec6.print();
	cout << "vec5 after";
	vec5.print();
	cout << "vec back = " << vec6.back() << endl;
	cout << "vec front = " << vec6.front() << endl;
	cout << "pop back = " << vec6.pop_back() << endl;
	vec6.clear();
	cout << "vec6 is empty? " << vec6.empty() << endl;


	cout << "###############################################################" << endl;

	cout << endl << std::numeric_limits<size_t>::max() << endl;
	try {
		cout << vec.at(7);

	}
	catch (const std::out_of_range &ex) {
		cerr << "a out_of_range error has occured: " << ex.what() << endl;
	}

	try {
		cout << vec[10] << endl;
	}
	catch (const std::out_of_range &ex) {
		cerr << "a out_of_range error has occured: " << ex.what() << endl;
	}

	try {
		Vector<double> vectest;
		vectest.reserve(9999999999999999999);
	}
	
	catch (const std::bad_alloc &ex) {
		cerr << "A bad_alloc error has occured: " << ex.what() << endl;
	}
	try {
		vec.insert(100, 0);
	}
	catch (const std::out_of_range & ex) {
		cerr << "An out_of_range error has occured: " << ex.what() << endl;
	}

	try {
		vec.erase(10, 3);
	}
	catch (const std::out_of_range & ex) {
		cerr << "An out_of_range error has occured: " << ex.what() << endl;
	}
	
	// Среда разработки не позволяет выделить памяти больше чем у нас есть, слишком большое значение аргумента
	/*try {
		Vector<size_t> vectest;
		vectest.resize(18446744073709551616);
	}
	catch (std::length_error &ex) {
		cerr << "A length_error has occured: " << ex.what() << endl;
	}*/


	return 0;
}
