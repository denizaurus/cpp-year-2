#pragma once

#include < iostream >
#include < vector >
#include < string >

#include < algorithm >


class BaseSubject
{
public:
	BaseSubject(bool snow, std::string & name) :
		isSnow(snow), seminarist(name) {};

	void diligenceRating() const;

private:
	double diligenceCalculate() const;
	virtual double profDifficulty() const = 0;
	virtual double subjDifficulty() const = 0;

private:
	bool isSnow;
	std::string seminarist;
	std::vector < double > weight;
};

class Calculus : public BaseSubject
{
public:
	explicit Calculus(bool snow, std::string & name) : BaseSubject(snow, name) {};

private:
	double profDifficulty() const override;
	double subjDifficulty() const override;

private:
	std::vector < double > weight = { 3.0, 7.0 };
};

class PhysicsLabs : public BaseSubject
{
public:
	explicit PhysicsLabs(bool snow, std::string & name) : BaseSubject(snow, name) {};

private:
	double profDifficulty() const override;
	double subjDifficulty() const override;

private:
	std::vector < double > weight = { 7.0, 3.0 };
};