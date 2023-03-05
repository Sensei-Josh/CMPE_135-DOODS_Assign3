#pragma once

#include <iostream>
#include "chooser.h"
using namespace std;

class computer
{
private:
	int score;
	chooser* difficulty;
public:
	computer()
	{
		score = 0;
		difficulty = nullptr;
	}
	void inc_score() { score++; }
	int get_score() { return score; }
	void set_difficulty(chooser *c){ difficulty = c; }
	options get_choice() { return difficulty->make_choice(); }
};