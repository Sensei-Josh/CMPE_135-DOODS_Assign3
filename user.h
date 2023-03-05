#pragma once

#include <iostream>
#include "chooser.h"
using namespace std;

class user
{
private:
	int score;
public:
	user() { score = 0; }
	void inc_score() { score++; }
	int get_score() { return score; }
	options make_choice()
	{
		options o = r;
		char c;
		cout << "Please Choose r, p, or s" << endl;
		cin >> c;

		switch (c)
		{
		case 'r': break;
		case 'p': o = p;
			break;
		case 's': o = s;
			break;
		}

		return o;
	}
};