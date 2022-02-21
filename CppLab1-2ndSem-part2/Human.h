#pragma once
class Human
{
private:
	int strength_;
	int agility_;
	int intelligence_;
	Human() = default;
public:
	Human(int strength, int agility, int intelligence) : strength_(strength), agility_(agility), intelligence_(intelligence) {};
	~Human() = default;
	int getStrength();
	int getAgility();
	int getIntelligence();
};