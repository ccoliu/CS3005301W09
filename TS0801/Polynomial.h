#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma once

class Polynomial
{
private:
	double* coefficient = nullptr;
	int size = 0;
public:
	~Polynomial();
	Polynomial();
	Polynomial(double* param, int size);
	Polynomial(const Polynomial& poly);

	int mySize();
	friend double evaluate(const Polynomial& poly, const double& var);

	Polynomial operator=(const Polynomial& poly);
	double& operator[](int idx);
	Polynomial operator+(const Polynomial& poly);
	Polynomial operator-(const Polynomial& poly);
	Polynomial operator*(const Polynomial& poly);
	Polynomial operator+(const double& a);
	Polynomial operator-(const double& a);
	Polynomial operator*(const double& a);
	friend Polynomial operator+ (const double& a,Polynomial& poly);
	friend Polynomial operator- (const double& a, Polynomial& poly);
	friend Polynomial operator* (const double& a, Polynomial& poly);
	void clear_zero()
	{
		for (int i = size - 1; i >= 0; i--)
		{
			if (coefficient[i] == 0)
			{
				size--;
			}
			else
			{
				break;
			}
		}
	}
};