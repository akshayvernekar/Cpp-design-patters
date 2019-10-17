//============================================================================
// Name        : strategy-pattern.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class WeaponBehaviour{
public:
	virtual ~WeaponBehaviour(){};
	virtual void useWeapon() = 0;
};

class SwordBehaviour : public WeaponBehaviour {
public:
	~SwordBehaviour(){};
	void useWeapon()
	{
		cout << "slash slash"<< endl;
	}
};
class BowAndArrowBehavior : public WeaponBehaviour {
public:
	~BowAndArrowBehavior(){};
	void useWeapon()
	{
		cout << "suss suss"<< endl;
	}
};

class KnifeBehavior : public WeaponBehaviour {
public:
	~KnifeBehavior(){};
	void useWeapon()
	{
		cout << "chak chakk"<< endl;
	}
};
class AxeBehavior : public WeaponBehaviour {
public:
	~AxeBehavior(){};
	void useWeapon()
	{
		cout << "chop chop"<< endl;
	}
};



class Character{
protected:
	WeaponBehaviour* weaponBehaviour;
public:
	Character(){
		weaponBehaviour = NULL;
	}
	~Character(){
		if(weaponBehaviour != NULL)
		{
			delete weaponBehaviour;
		}
	}
	void setWeapon(WeaponBehaviour* newWeapon)
	{
		if(weaponBehaviour!= NULL )
			delete weaponBehaviour;

		weaponBehaviour = newWeapon;
	}
	void fight()
	{
		weaponBehaviour->useWeapon();
	}
};

class King : public Character
{
public:
	King(){
		setWeapon(new SwordBehaviour);
	}
};

class Queen : public Character
{
public:
	Queen(){
		setWeapon(new KnifeBehavior);
	}
};

int main() {
	King king ;
	king.fight();
	Queen queen ;
	queen.fight();
	queen.setWeapon(new AxeBehavior);
	queen.fight();
	return 0;
}
