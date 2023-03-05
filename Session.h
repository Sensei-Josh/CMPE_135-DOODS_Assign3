#pragma once

#include <iostream>
#include "user.h"
#include "computer.h"
using namespace std;

#define round_size 20

class Session
{
private:
	user *Player1;
	computer *Player2;
public:
	Session()
	{
		Player1 = new user;
		Player2 = new computer;
	}
	void start()
	{
		char op;
		cout << "Pleae choose difficulty" << endl;
		cout << "Easy: e" << endl;
		cout << "Medium: m" << endl;
		cout << "Hard: h" << endl;

		cin >> op;

	}
};