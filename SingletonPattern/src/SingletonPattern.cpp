//============================================================================
// Name        : SingletonPattern.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*Lets create a class to count the number of people passing through our Border*/
class Border{
private:
	int mCount;
	Border(){
		mCount = 0;
	}
	static Border* pUniqueInstance;
public:
	static Border* getInstance(){
		if(pUniqueInstance == NULL){
			pUniqueInstance = new Border();
		}
		return pUniqueInstance;
	}
	void updateCount(){
		mCount++;
	}
	int getCount(){
		return mCount;
	}
};

Border* Border::pUniqueInstance = NULL;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Border* border = Border::getInstance();
	border->updateCount();
	cout << "Current count is "<< border->getCount()<< endl;
	border->updateCount();
	cout << "Current count is "<< border->getCount()<< endl;
	return 0;
}
