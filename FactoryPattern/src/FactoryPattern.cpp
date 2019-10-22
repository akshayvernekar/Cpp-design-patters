//============================================================================
// Name        : FactoryPattern.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef enum PizzaType{
	eCheesePizza,
	eVeggiePizza,
	ePepporoniPizza,
	eClamPizza,
}PizzaType;

class Pizza{
protected:
	string mName;
	string mDough;
	string mSauce;
	vector<string> mToppings;

public:

	virtual ~Pizza(){};
	virtual void prepare()
	{
		cout << "Preparing " << mName << endl;
		cout << "Tossing dough..." << endl;
		cout << "Adding sauce..." << endl;
		cout << "Adding toppings:" << endl;
		for(unsigned int i =0; i < mToppings.size() ; i++){
			cout <<" " <<mToppings[i];
		}
		cout << endl;
	}
	virtual void bake()
	{
		cout << "Bake for 25 mins at 350" << endl;
	}
	virtual void cut()
	{
		cout << "Cutting the pizza into diagonal slices" << endl;
	}
	virtual void box()
	{
		cout << "Place pizza in official PizzaStore box" << endl;
	}
	string getName()
	{
		return mName;
	}
};

class NYStyleCheesePizza : public Pizza{
public:
	NYStyleCheesePizza(){
		mName = "NY Style Sauce and Cheese Pizza";
		mDough = "Thin Crust Dough";
		mSauce = "Marinara Sauce";
		mToppings.push_back("Grated Reggiano Cheese");
	}

};


class ChicagoCheesePizza : public Pizza{
public:
	ChicagoCheesePizza(){
		mName = "Chicago Style Deep Dish Cheese Pizza";
		mDough = "Extra Thick Crust Dough";
		mSauce = "Plum Tomato Sauce";
		mToppings.push_back("Shredded Mozzarella Cheese");
	}
	void cut()
	{
		cout << "Cutting the pizza into square slices" << endl;
	}

};

class PizzaStore{
private:
public:
	virtual ~PizzaStore(){		}
	virtual Pizza* createPizza(PizzaType type) = 0;
};

class NYPizzaStore : public PizzaStore{
	Pizza* createPizza(PizzaType type)
	{
		if(type == eCheesePizza)
			return new NYStyleCheesePizza();
		else
			return NULL;
	}
};


class ChicagoPizzaStore : public PizzaStore{
	Pizza* createPizza(PizzaType type)
	{
		if(type == eCheesePizza)
			return new ChicagoCheesePizza();
		else
			return NULL;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	PizzaStore* store = new NYPizzaStore();
	Pizza* pizza = store->createPizza(eCheesePizza);
	if(pizza != NULL)
	{
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		delete pizza;
	}
	if(store)
		delete store;


	store = new ChicagoPizzaStore();
	pizza = store->createPizza(eCheesePizza);
	if(pizza != NULL)
	{
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
		delete pizza;
	}
	if(store)
		delete store;
	return 0;
}
