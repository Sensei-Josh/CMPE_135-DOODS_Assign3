#pragma once

#include <iostream>
#include "chooser.h"
using namespace std;

class medium_chooser : public chooser
{
	//idea: make hash map variable
	// key = sequence, value = frequency
	//have a text file holding data
	//when user chooses medium load data onto hash map
	//idea: make a pointer to a options vector thats in session

public:
	medium_chooser() {};
	options make_choice()
	{
		return r;
	}
};
