#pragma once

class Complex
{
private:
	int rPart_;
	int iPart_;
	Complex() = default;
public:
	Complex(int rPart, int iPart) :rPart_(rPart), iPart_(iPart) {};
	friend bool operator< (Complex c1, Complex c2)
	{
		return c1.rPart_ < c2.rPart_;
	}
	~Complex() = default;
	int getrPart()
	{
		return rPart_;
	}
	int getiPart() 
	{
		return iPart_;
	}
};
