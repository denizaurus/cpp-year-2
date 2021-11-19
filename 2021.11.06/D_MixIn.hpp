#pragma once
#include < iostream >
#include < vector >
#include < string >

#include < algorithm >

template <typename Derived>
class BaseSubject
{
public:
    BaseSubject(bool snow, const std::string & name) :
        isSnow(snow), seminarist(name) {};

	auto self() { return static_cast <Derived *> (this); }
    void diligenceRating();

private:

    double diligenceCalculate();

private:
    bool isSnow;
    std::string seminarist;
};

class Calculus : public BaseSubject < Calculus >
{
	friend class BaseSubject < Calculus >;

public:
    explicit Calculus(bool snow, const std::string & name) : BaseSubject < Calculus >(snow, name) {};

private:
    double profDifficulty() const;
    double subjDifficulty() const;

private:
    std::vector < double > weight = { 3.0, 7.0 };
};

class PhysicsLabs : public BaseSubject < PhysicsLabs >
{
	friend class BaseSubject < PhysicsLabs >;

public:
    explicit PhysicsLabs(bool snow, const std::string & name) : BaseSubject < PhysicsLabs > (snow, name) {};

private:
    double profDifficulty() const;
    double subjDifficulty() const;

private:
    std::vector < double > weight = { 7.0, 3.0 };
};

template < typename Derived >
void BaseSubject < Derived > ::diligenceRating()
{
	int output = static_cast < int > (diligenceCalculate());

    std::cout << "Professor " << seminarist << std::endl;
    std::cout << "Diligence Rating: " << output << "%" << std::endl;
}

template < typename Derived >
double BaseSubject < Derived > ::diligenceCalculate()
{
    if (isSnow) return 100.0;
    else
    {
        double prof = self()->profDifficulty();
        double subj = self()->subjDifficulty();
		std::vector < double > weight = self()->weight;

        return std::min(100.0, (weight[0] * prof + weight[1] * subj) / 60.0);
    }
}


double Calculus::profDifficulty() const
{
	double easy;
	double tSkill;

	std::cout << "Input the Teaching Ability rating of your professor (0-5): ";
	std::cin >> tSkill;

	std::cout << "Input the Easygoingness rating of your professor (0-5): ";
	std::cin >> easy;

	return std::pow(tSkill - easy, 2) + 2.0 * (5.0 - easy) + 5.0 * (5.0 - tSkill) * 5.0 / 3.0;
}

double Calculus::subjDifficulty() const
{
	double theory;
	double practice;
	double skill;

	std::cout << "Input the points allocated to theory: "; //in terms of point-rating system
	std::cin >> theory;
	std::cout << "Input the points allocated to practice: ";
	std::cin >> practice;
	std::cout << "Rate your skill (0-10): ";
	std::cin >> skill;

	return std::max((9.0 * theory + practice) / 10.0 * (15.0 - skill), 100.0);
}

double PhysicsLabs::profDifficulty() const
{
	double easy;
	double conversation;

	std::cout << "Input the In Conversation rating of your professor: ";
	std::cin >> conversation;

	std::cout << "Input the Easygoingness rating of your professor: ";
	std::cin >> easy;

	return std::max(3 * (5 - easy) + 7 * (5 - conversation) * 10, 100.0);
}

double PhysicsLabs::subjDifficulty() const
{
	double motorSkill;
	double scienceSkill;


	std::cout << "Rate your motor skills (0-10): ";
	std::cin >> motorSkill;
	std::cout << "Rate your scientific skills (0-10): ";
	std::cin >> scienceSkill;

	return std::max(3.0 * (10.0 - motorSkill) + 7.0 * (10.0 - scienceSkill) * 10.0, 100.0);
}
