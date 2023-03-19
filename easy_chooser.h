#pragma once

#include <iostream>
#include <random>
#include <time.h>
#include "chooser.h"
using namespace std;

class easy_chooser : public chooser
{
public:
	easy_chooser() {};
	options make_choice (options player)
	{
		srand(time(0));
		int x = enum_elem;
		return static_cast<options>(rand() % x);
	}
};
