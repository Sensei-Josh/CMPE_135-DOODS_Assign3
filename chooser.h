#pragma once

#include <iostream>
using namespace std;

enum options { r,p,s };

constexpr auto enum_elem = 3;

string OpToString(options op)
{
	if (op == r) return "r";
	else if (op == s) return "s";
	else return "p";
}

class chooser
{
public:
	virtual options make_choice(options player) = 0;
};