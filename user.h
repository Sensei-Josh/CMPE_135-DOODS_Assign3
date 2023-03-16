#pragma once

#include <iostream>
#include "chooser.h"
#include "manual_chooser.h"
using namespace std;

class user
{
private:
	int score;
	chooser* method;
public:
	user() 
	{ 
		score = 0;
		method = new manual_chooser;
	}
	void inc_score() { score++; }
	int get_score() { return score; }
	options get_choice() { return method->make_choice(); }
};