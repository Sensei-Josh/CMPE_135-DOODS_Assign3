#pragma once

#include <iostream>
#include "chooser.h"
using namespace std;

class manual_chooser : public chooser
{
public:
	manual_chooser() {};
	options make_choice(options o)
	{
		char c;
		cout << "Please Choose r, p, or s" << endl;
		cin >> c;

		o = static_cast<options>(c);

		return o;
	}
};