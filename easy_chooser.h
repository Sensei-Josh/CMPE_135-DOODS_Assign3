#pragma once

#include <iostream>
#include <random>
#include "chooser.h"
using namespace std;

class easy_chooser : public chooser
{
public:
	easy_chooser() {};
	options make_choice ()
	{
		srand(time(0));
		int option = rand() % 3 + 1;

		switch (option)
		{
		case 1: return r;
		case 2: return p;
		case 3: return s;
		}

		return r;
	}
};
