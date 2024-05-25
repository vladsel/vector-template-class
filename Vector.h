#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
using std::cout;
using std::endl;

#pragma warning (disable: 6386)

template <typename T>
class Vector {
public:
	Vector() : vector(nullptr), n(0), max(0) {}
	Vector(size_t _n, size_t _max);
	Vector(const Vector <T> &vec);
	~Vector();
	Vector<T> &operator=(const Vector <T> &arr);
	bool IsEmpty();
	size_t GetN();
	void Create();
	void Sort();
	T GetFirstEl();
	T GetLastEl();
	void PushBack(T value);
	void PopBack();
	T operator[](size_t i);
	friend std::ostream &operator << (std::ostream &out, const Vector <T> &arr) {
		for (size_t i = 0; i < arr.n; i++) {
			if (i == 0)
				out << "[ | ";
			out << arr.vector[i] << " | ";
			if (i == arr.n - 1)
				out << "]\n";
		}
		return out;
	}

private:
	T *vector;
	size_t n;
	size_t max;
};

template<typename T>
inline Vector<T>::Vector(size_t _n, size_t _max) {
	if (_n <= _max && _n >= 0 && _max >= 0) {
		vector = nullptr;
		n = _n;
		max = _max;
	}
	else {
		vector = nullptr;
		n = 0;
		max = 0;
		std::cerr << "\nconstructor error: max, Vector(size_t, size_t)< n\n";
	}
}

template<typename T>
inline Vector<T>::Vector(const Vector <T> &arr) {
	n = arr.n;
	max = arr.max;
	vector = new T[max];
	for (size_t i = 0; i < n; i++)
		vector[i] = arr.vector[i];
}

template<typename T>
inline Vector<T>::~Vector() {
	if (vector != nullptr)
		delete[] vector;
}

template<typename T>
inline Vector<T> &Vector<T>::operator=(const Vector<T> &arr) {
	n = arr.n;
	max = arr.max;
	if (vector != nullptr)
		delete[] vector;
	vector = new T[max];
	for (size_t i = 0; i < n; i++)
		vector[i] = arr.vector[i];
	return *this;
}

template<typename T>
inline bool Vector<T>::IsEmpty() {
	return (!vector && n == 0);
}

template<typename T>
inline size_t Vector<T>::GetN() {
	return n;
}

template<typename T>
inline void Vector<T>::Create() {
	if (max >= 0 && n >= 0) {
		if (!IsEmpty())
			delete[] vector;
		vector = new T[max];
		for (size_t i = 0; i < n; i++)
			vector[i] = n - i;
	}
}

template<typename T>
inline void Vector<T>::Sort() {
	if (!IsEmpty()) {
		bool flag = true;
		T temp = 0;
		size_t r = n - 1;
		while (flag) {
			flag = false;
			for (size_t i = 0; i < r; i++) {
				if (vector[i] > vector[i + 1]) {
					temp = vector[i];
					vector[i] = vector[i + 1];
					vector[i + 1] = temp;
					flag = true;
				}
			}
			r--;
		}
	}
}

template<typename T>
inline T Vector<T>::GetFirstEl() {
	if (!IsEmpty())
		return vector[0];
}

template<typename T>
inline T Vector<T>::GetLastEl() {
	if (!IsEmpty())
		return vector[n - 1];
}

template<typename T>
inline void Vector<T>::PushBack(T value) {
	if (n < max) {
		vector[n] = value;
		n++;
	}
	else 
		std::cerr << "\nerror: size equals capacity: n == max, PushBack(T)\n";
}

template<typename T>
inline void Vector<T>::PopBack() {
	if (!IsEmpty()) {
		vector[n - 1] = 0;
		n--;
	}
	else
		std::cerr << "\nerror: vector is empty, PopBack()\n";
}

template<typename T>
inline T Vector<T>::operator[](size_t i) {
	if (i >= 0 && i < n)
		return vector[i];
	else
		std::cerr << "\nerror: i < 0 && i >= n, operator[](size_t)\n";
}

#endif //_VECTOR_H_