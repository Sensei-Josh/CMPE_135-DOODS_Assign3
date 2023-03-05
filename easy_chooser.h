#pragma once

#include <iostream>
#include <random>
#include "chooser.h"
using namespace std;

class easy_chooser : chooser
{
public:
	options make_choice ()
	{
		int option = rand() % 3 + 1;

		switch (option)
		{
		case 1: return r;
		case 2: return p;
		case 3: return s;
		}

	}
};
