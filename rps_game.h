#pragma once

#include <iostream>
#include "Session.h"
using namespace std;

class rps_game
{
private:
	Session *game;
public:
	rps_game() { game = nullptr; };
	void start_game()
	{
		bool n = true;

		cout << "Welcome to Rock-Paper-Scissors and online game to waste your time." << endl;

		while (n == true)
		{
			cout << "-----------------Menu------------------ " << endl;
			cout << "Start: s" << endl;
			cout << "Exit : e" << endl;

			char s;
			cin >> s;

			switch (s)
			{
			case 's': 
			{
				game = new Session;
				game->start();
				break;
			}
			case 'e': n = false;
			}
		}

		cout << "Goodbye for now" << endl;
		return;
	};
};