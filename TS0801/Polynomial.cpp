#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Polynomial.h"
using namespace std;

Polynomial::~Polynomial()
{
	delete[] coefficient;
	coefficient = nullptr;
}

Polynomial::Polynomial()
{
	coefficient = new double(0.0);
}

Polynomial::Polynomial(double* param, int sz)
{
	size = sz;
	coefficient = new double[size] {0};
	for (int i = 0; i < size; i++)
	{
		coefficient[i] = param[i];
	}
}

Polynomial::Polynomial(const Polynomial& poly)
{
	this->~Polynomial();
	size = poly.size;
	coefficient = new double[size] {0};
	for (int i = 0; i < size; i++)
	{
		coefficient[i] = poly.coefficient[i];
	}
}

int Polynomial::mySize()
{
	return this->size;
}

Polynomial Polynomial::operator=(const Polynomial& poly)
{
	this->~Polynomial();
	size = poly.size;
	coefficient = new double[size] {0};
	for (int i = 0; i < size; i++)
	{
		coefficient[i] = poly.coefficient[i];
	}
	return *this;
}

double& Polynomial::operator[](int idx)
{
	return coefficient[idx];
}

Polynomial Polynomial::operator+(const Polynomial& poly)
{
	Polynomial result;
	result.size = max(size, poly.size);
	result.coefficient = new double[result.size] {0};
	if (size > poly.size)
	{
		for (int i = 0; i < poly.size; i++)
		{
			result.coefficient[i] = coefficient[i] + poly.coefficient[i];
		}
		for (int i = poly.size; i < size; i++)
		{
			result.coefficient[i] = coefficient[i];
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			result.coefficient[i] = coefficient[i] + poly.coefficient[i];
		}
		for (int i = size; i < poly.size; i++)
		{
			result.coefficient[i] = poly.coefficient[i];
		}
	}
	result.clear_zero();
	return result;
}

Polynomial Polynomial::operator-(const Polynomial& poly)
{
	Polynomial result;
	result.size = max(size, poly.size);
	result.coefficient = new double[result.size] {0};
	if (size > poly.size)
	{
		for (int i = 0; i < poly.size; i++)
		{
			result.coefficient[i] = coefficient[i] - poly.coefficient[i];
		}
		for (int i = poly.size; i < size; i++)
		{
			result.coefficient[i] = coefficient[i];
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			result.coefficient[i] = coefficient[i] - poly.coefficient[i];
		}
		for (int i = size; i < poly.size; i++)
		{
			result.coefficient[i] = -poly.coefficient[i];
		}
	}
	result.clear_zero();
	return result;
}

Polynomial Polynomial::operator*(const Polynomial& poly)
{
	Polynomial result;
	result.size = size + poly.size - 1;
	result.coefficient = new double[result.size] {0};
	for (int i = 0; i < result.size; i++)
	{
		result.coefficient[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < poly.size; j++)
		{
			result.coefficient[i + j] += coefficient[i] * poly.coefficient[j];
		}
	}
	result.clear_zero();
	return result;
}

double evaluate(const Polynomial& poly, const double& var)
{
	double result = 0;
	for (int i = 0; i < poly.size; i++)
	{
		result += (poly.coefficient[i] * pow(var, i));
	}
	return result;
}

Polynomial Polynomial::operator+ (const double& a)
{
	Polynomial result = *this;
	result[0] = result[0] + a;
	result.clear_zero();
	return result;
}

Polynomial Polynomial::operator- (const double& a)
{
	Polynomial result = *this;
	result[0] = result[0] - a;
	result.clear_zero();
	return result;
}

Polynomial Polynomial::operator* (const double& a)
{
	Polynomial result = *this;
	for (int i = 0; i < result.size; i++)
	{
		result[i] = result[i] * a;
	}
	result.clear_zero();
	return result;
}

Polynomial operator+ (const double& a, Polynomial& poly)
{
	Polynomial result = poly;
	poly = poly + a;
	return result;
}

Polynomial operator- (const double& a, Polynomial& poly)
{
	Polynomial result = poly;
	result = result * (-1);
	result = result + a;
	return result;
}

Polynomial operator* (const double& a, Polynomial& poly)
{
	Polynomial result;
	result.size = poly.size;
	result.coefficient = new double[result.size] {0};
	for (int i = 0; i < result.size; i++)
	{
		result.coefficient[i] = poly.coefficient[i] * a;
	}
	result.clear_zero();
	return result;
}