//============================================================================
// Name        : ObserverPattern.cpp
// Author      : HungrySpider
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

class Observer{
private:
public:
	virtual ~Observer();
	virtual void update(int temp, int pressure , int humidity) =0 ;
};

Observer::~Observer(){

}

class Subject{
private:
public:
	virtual ~Subject(){}
	virtual void registerObserver(Observer* observer) = 0;
	virtual void removeObserver(Observer* observer) = 0;
	virtual void notifyObserver() = 0;
};

class CurrentConditionsDisplay : public Observer{
private:
	Subject* subject;
public:
	~CurrentConditionsDisplay(){}
	CurrentConditionsDisplay(Subject* sub){
		subject = sub;
		subject->registerObserver(this);
	}
	void update(int temp, int pressure , int humidity)
	{
		cout << "In Current conditions Display" << endl;
		cout <<"temp is "<<temp <<endl;
		cout <<"pressure is "<<pressure <<endl;
		cout <<"humidity is "<<humidity <<endl;
	}

	void deRegister(){
		subject->removeObserver(this);
	}

};

class StatsDisplay : public Observer{
private:
	Subject* subject;
public:
	~StatsDisplay(){};
	StatsDisplay(Subject* sub){
		subject = sub;
		subject->registerObserver(this);
	}
	void update(int temp, int pressure , int humidity)
	{
		cout << "In StatsDisplay  Display" << endl;
		cout <<"temp is "<<temp <<endl;
		cout <<"pressure is "<<pressure <<endl;
		cout <<"humidity is "<<humidity <<endl;
	}

	void deRegister(){
		subject->removeObserver(this);
	}


};

class WeatherStation : public Subject{
private:
	int mTemp;
	int mPressure;
	int mHumidity;

	list<Observer*> observersList;
public:
	~WeatherStation(){}
	void registerObserver(Observer* observer){
		observersList.push_back(observer);

	}

	void removeObserver(Observer* observer) {
		observersList.remove(observer);
	}

	void notifyObserver(){
		list<Observer*>::iterator it;
		for(it=observersList.begin();it != observersList.end();it++)
		{
			Observer* observer = *it;
			observer->update(mTemp,mPressure,mHumidity);
		}
	}

	void measurementsChanged(int temp, int pressure , int humidity)
	{
		mTemp = temp;
		mPressure = pressure;
		mHumidity = humidity;
		notifyObserver();
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//Testing with one observer
	WeatherStation weatherStation;
	CurrentConditionsDisplay currentConditionsDisplay(&weatherStation);
	weatherStation.measurementsChanged(30,20,10);

	//Testing with two observers
	StatsDisplay statsDisplay(&weatherStation);
	weatherStation.measurementsChanged(50,50,50);

	//Testing the deregister function
	currentConditionsDisplay.deRegister();
	weatherStation.measurementsChanged(100,100,100);
	return 0;
}
