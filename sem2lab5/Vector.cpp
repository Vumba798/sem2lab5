#include "Vector.h"
#include <iostream>
using std::endl;
using std::cout;
using std::cin;

template<class T>
Vector<T>::Vector() {
	_size = 0;
	_capacity = 0;
	_data = nullptr;
}

template<class T>
Vector<T>::Vector(const Vector& vec) {
	_size = vec._size;
	_capacity = vec._capacity;
	_data = new T[_size];
	for (size_t i = 0; i < _size; ++i) {
		_data[i] = vec._data[i];
	}
}

template<class T>
Vector<T>::~Vector() {
	delete[] _data;
	_data = nullptr;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec) {
	delete[] _data;
	_size = vec._size;
	_capacity = vec._capacity;
	_data = new T[_size];

	for (size_t i = 0; i < vec._size; ++i) {
		_data[i] = vec._data[i];
	}
	return *this;
}

template <class T>
T& Vector<T>::operator[](const size_t &index) {
	if (index > _size) {
		throw std::out_of_range("wrong index");
	}
	return _data[index];
}

template <class T>
T Vector<T>::at(const size_t &pos) const {
	if (pos >= _size) {
		throw std::out_of_range("wrong index");
	}
	return _data[pos];
}

template <class T>
T Vector<T>::front() {
	return _data[0];
}

template <class T>
T Vector<T>::back() {
	return _data[_size - 1];
}

template <class T>
bool Vector<T>::empty() {
	return _size ? false : true;
}

template<class T>
size_t Vector<T>::size() const {
	return _size;
}

template<class T>
void Vector<T>::reserve(const size_t& n) {
	if (n > std::numeric_limits<size_t>::max()) {	
		throw std::length_error("length error");
	}
	if (n > _capacity) {
		_capacity = n;
		T* newData = new T[n];
		for (size_t i = 0; i < _size; ++i) {
			newData[i] = _data[i];
		}
		delete[] _data;
		_data = newData;
	}
}

template<class T>
size_t Vector<T>::capacity() const {
	return _capacity;
}

template<class T>
void Vector<T>::clear() {
	_size = 0;
	_capacity = 0;
	delete[] _data;
	_data = nullptr;
}

template<class T>
void Vector<T>::insert(const size_t& pos, T val) {
	if (pos >= _size) {
		throw std::out_of_range("wrong index");
	}
	size_t newSize;
	if (_capacity > _size) {
		++_size;
		T tmp2;
		T tmp1 = val;

		for (size_t i = pos; i < _size;++i) {
			tmp2 = _data[i];
			_data[i] = tmp1;
			tmp1 = tmp2;
			
		}
		
	}
	else {
		size_t newCapacity;
		switch (_capacity){
			case 0: newCapacity = 1; break;
			case 1: newCapacity = 2; break;
			default: newCapacity = _capacity * 1.5;
		}
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < pos; ++i) {
			newData[i] = _data[i];
		}
		newData[pos] = val;
		for (size_t i = pos; i < _size;++i) {
			newData[i + 1] = _data[i];
		}
		_capacity = newCapacity;
		++_size;
		delete[] _data;
		_data = newData;
	}
}

template<class T>
void Vector<T>::erase(const size_t& pos) {
	if (pos >= _size) {
		throw std::out_of_range("wrong index");
	}
	--_size;
	for (size_t i = pos; i < _size; ++i) {
		_data[i] = _data[i + 1];
	}
}


template<class T>
void Vector<T>::erase(const size_t& r1, const size_t& r2) {
	if (r1 > r2 || r2 >= _size) {
		throw std::out_of_range("wrong index");
	}
	for (size_t i = 0; i < _size - r2; ++i) {
		_data[i + r1] = _data[i + r2];
	}
	_size -= r2 - r1;
}


template<class T>
void Vector<T>::push_back(T val) {
	size_t newCapacity;
	if (_size > 1 && _capacity >= _size + 1) {
		_data[_size] = val;
		++_size;
	}
	else {
		if (_size > 1) {
			newCapacity = static_cast<size_t>(_capacity * 1.5);
		}
		else {
			newCapacity = _size + 1;
		}
		T* newData = new T[newCapacity];
		for (size_t i = 0; i < _size; ++i) {
			newData[i] = _data[i];
		}
		newData[_size] = val;
		delete[] _data;
		_data = newData;
		_size = _size + 1;
		_capacity = newCapacity;
	}
	
}

template<class T>
T Vector<T>::pop_back() {
	--_size;
	return _data[_size];
}



template<class T>
void Vector<T>::resize(const size_t &count) {
	size_t minSize = count;
	if (count > _size) {
		_capacity = count;
		minSize = _size;
	}
	T* newData = new T[count];
	for (size_t i = 0; i < minSize; ++i) {
		newData[i] = _data[i];
	}
	delete[] _data;
	_data = newData;
	_size = minSize;
	_capacity = count;
}

template <class T>
void Vector<T>::print() const{
	cout << "=========================================" << endl;
	for (size_t i = 0; i < _size; ++i) {
		cout << "element[" << i << "] = " << _data[i] << endl;
	}
	cout << "=========================================" << endl << endl;
}

template <class T>
void Vector<T>::swap(Vector<T> &oth) {
	Vector<T> tmpVec;
	tmpVec = oth;
	oth = *this;
	*this = tmpVec;
}

template <class T>
T* Vector<T>::data() {
	return _size == 0 ? nullptr : _data;
}