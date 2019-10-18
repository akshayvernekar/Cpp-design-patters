//============================================================================
// Name        : DecoratorPattern.cpp
// Author      : HungrySpider
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Icecream{
private:
public:
	virtual ~Icecream(){}
	virtual int getCost() = 0;
	virtual string getDescription() = 0;
};

class Vanilla : public Icecream{
public:

	virtual int getCost(){
		return 20;
	}
	virtual string getDescription(){
		return "Vanilla";
	}
};


class Chocolate : public Icecream{
public:

	virtual int getCost(){
		return 30;
	}
	virtual string getDescription(){
		return "Chocolate";
	}
};

class Toppings : public Icecream{
private:
	Icecream* m_Base;
public:
	Toppings(Icecream* icecream){
		m_Base = icecream;
	}
	virtual string getDescription()
	{
		return m_Base->getDescription();
	}
	int getCost()
	{
		return m_Base->getCost();
	}
};

class Fudge : public Toppings{
public:
	Fudge(Icecream* icecream):Toppings(icecream){
	}
	int getCost(){
		return Toppings::getCost()+5;
	}
	string getDescription(){
		return Toppings::getDescription()+",Fudge";
	}
};
class Wafers : public Toppings{
public:
	Wafers(Icecream* icecream):Toppings(icecream){

	}
	int getCost(){
		return Toppings::getCost()+7;
	}
	string getDescription(){
		return Toppings::getDescription()+",Wafers";
	}
};

class ExtraCream : public Toppings{
public:
	ExtraCream(Icecream* icecream):Toppings(icecream){

	}
	int getCost(){
		return Toppings::getCost()+10;
	}
	string getDescription(){
		return Toppings::getDescription()+",ExtraCream";
	}
};


int main() {
	cout << "!!!Decorator Pattern!!!" << endl; // prints !!!Hello World!!!
	Icecream* chocoFudgeIcecream = new Fudge(new Chocolate());
	cout<< chocoFudgeIcecream->getDescription() << " Costs " << chocoFudgeIcecream->getCost()<<endl;

	// Lets create a icecream with Vanilla, fudge and wafers .. lets also add some extra cream
	Icecream* diabetesSpecial = new ExtraCream( new Wafers(new Fudge(new Vanilla())));
	cout<< diabetesSpecial->getDescription() << " Costs " << diabetesSpecial->getCost()<<endl;
	return 0;
}
