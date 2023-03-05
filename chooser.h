#pragma once

#include <iostream>
using namespace std;

enum options { r,p,s };

class chooser
{
public:
	virtual options make_choice() = 0;
};