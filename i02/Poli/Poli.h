#pragma once
#include <math.h>
#include <iostream>
using namespace std;

template <class T>
class Polynomial {
public:
	Polynomial();
	Polynomial(T* vector, T grade);
	T degree();
	T coef(T exp);
	Polynomial<T> operator+(Polynomial<T> other);
	T evaluate(T x);
	void debug();

private:
	T grade_;
	T* vector_;
};

template <class T>
Polynomial<T>::Polynomial() {}

template <class T>
Polynomial<T>::Polynomial(T* vector, T grade) {
	vector_ = vector;
	grade_ = grade;
}

template <class T>
T Polynomial<T>::degree() {
	return grade_;
}

template <class T>
T Polynomial<T>::coef(T exp) {
	return vector_[exp];
}

template <class T>
Polynomial<T> Polynomial<T>::operator+(Polynomial<T> other) {
	T* vector;
	Polynomial<T> res = Polynomial<T>();

	if (grade_ == other.degree()) {
		vector = new T[grade_];
		for (int i = 0; i < grade_ + 1; ++i) {
			vector[i] = vector_[i] + other.coef(i);
		}
		res = Polynomial<T>(vector, grade_);
	}
	else if (grade_ < other.degree()){
		vector = new T[other.degree()];
		for (int i = 0; i < grade_+1; ++i) {
			vector[i] = vector_[i] + other.coef(i);
		}
		for (int i = grade_ + 1; i < other.degree() + 1; ++i) {
			vector[i] = other.coef(i);
		}
		res = Polynomial<T>(vector, other.degree());
	}
	else {
		vector = new T[grade_];
		for (int i = 0; i < other.degree() + 1; ++i) {
			vector[i] = vector_[i] + other.coef(i);
		}
		for (int i = other.degree() + 1; i < grade_ + 1; ++i) {
			vector[i] = vector_[i];
		}
		res = Polynomial<T>(vector, grade_);
	}

	return res;
}

template <class T>
T Polynomial<T>::evaluate(T x) {
	T res = 0;
	for (int i = 0; i < grade_ + 1; ++i) {
		res += vector_[i] * pow(x, i);
	}
	return res;
}

template <class T>
void Polynomial<T>::debug() {
	for (int i = 0; i < grade_ + 1; ++i) {
		cout << vector_[i] << " ";
	}
}