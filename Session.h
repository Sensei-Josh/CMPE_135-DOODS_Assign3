#pragma once

#include <iostream>
#include "user.h"
#include "computer.h"
#include "easy_chooser.h"
#include "medium_chooser.h"
using namespace std;

#define round_size 20

class Session
{
private:
	user *Player1;
	computer *Player2;

	void scorer(int o1, int o2)
	{
		if (o1 == o2) return;
		else if (o2 == ((o1 + 1) % 3)) Player2->inc_score();
		else Player1->inc_score();
	}
	static chooser* choose_factory(char s)
	{
		switch (s)
		{
		case 'e': return new easy_chooser;
		case 'm': return new medium_chooser;
		case 'h': return new easy_chooser; // make an impossible class
		default: return new easy_chooser;
		}
	}
public:
	Session()
	{
		Player1 = new user;
		Player2 = new computer;
	}
	void start()
	{
		
		char op;
		cout << "Please choose difficulty" << endl;
		cout << "Easy: e" << endl;
		cout << "Medium: m" << endl;
		cout << "Hard: h" << endl;

		cin >> op;
		chooser* c = choose_factory(op);
		Player2->set_difficulty(c);

		for (int i = 0; i < round_size; i++)
		{
			cout << "Round " << i + 1 << endl;
			options player_choice = Player1->get_choice();
			options comp_choice = Player2->get_choice(player_choice);

			scorer(player_choice, comp_choice);
			cout << "Computer chose: " ;
			switch (comp_choice)
			{
			case r: cout << "r" << endl;
				break;
			case p: cout << "p" << endl;
				break;
			case s: cout << "s" << endl;
			}
		}

		cout << "User: " << Player1->get_score() << " Computer: " << Player2->get_score() << endl;

		if (Player1->get_score() > Player2->get_score())
		{
			cout << "You win!!!!!!" << endl;
		}
		else if (Player1->get_score() < Player2->get_score())
		{
			cout << "Awww you lost, try your luck next time." << endl;
		}
		else
		{
			cout << "Tie" << endl;
		}
		
		return;
	}
};