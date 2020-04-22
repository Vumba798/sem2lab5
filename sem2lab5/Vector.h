#pragma once

template <class T>
class Vector {
private:
	T* _data;
	size_t _size;
	size_t _capacity;
public:
	Vector();
	Vector(const Vector& vec);
	~Vector();

	Vector& operator=(const Vector& vec);
	T& operator[](const size_t &index);
	T at(const size_t &pos) const;
	T front();
	T back();
	bool empty();
	size_t size() const;
	void reserve(const size_t& n);
	size_t capacity() const;
	void clear();
	void insert(const size_t &pos, T val);
	void erase(const size_t &pos);
	void erase(const size_t& r1, const size_t &r2);
	void push_back(T val);
	T pop_back();
	void resize(const size_t &count);
	void print() const;
	void swap(Vector<T> &oth);
};

