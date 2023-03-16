#pragma once

#include <iostream>
#include "chooser.h"
using namespace std;

class manual_chooser : public chooser
{
public:
	manual_chooser() {};
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