#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include "chooser.h"
using namespace std;

#define N_val 5

class medium_chooser : public chooser
{
	//idea: make hash map variable for quick lookup
	// key = sequence, value = frequency
	//have a text file holding data
	//when user chooses medium load data onto hash map
private:
	map<string, int> data;
	vector<options> sequence;

	void update_data(string seq)
	{
		int x = N_val;

		seq += OpToString(sequence[x - 1]);

		auto it = data.find(seq);

		if (it == data.end())
		{
			data.insert({ seq, 1 });
		}
		else
		{
			it->second = it->second + 1;
		}

		//cout << "g" << data.size() << endl;

		return;
	}
	string get_seq()
	{
		string x = "";
		for (int i = 0; i < sequence.size(); i++)
		{
			if (sequence[i] == r) x = x + 'r';
			else if (sequence[i] == s) x = x + 's';
			else x = x + 'p';
		}

		return x;
	}
	void load_data()
	{
		ifstream load;
		int length = 0;
		string seq;
		load.open("ml_data.txt");

		if (load.eof()) return;

		load >> length;

		if (length != N_val) return;

		while (!load.eof())
		{
			load >> length >> seq;
			data.insert({ seq, length });
		}

		load.close();

		return;
	}

	void save_data()
	{
		ofstream save;
		save.open("ml_data.txt");

		//cout << data.size() << endl;

		save << N_val << endl;

		for (auto it = data.begin(); it != data.end(); ++it)
		{
			save << it->second << " " << it->first << endl;
		}

		save.close();
		return;
	}
	void delete_round()
	{
		sequence.erase(sequence.begin());
		sequence.erase(sequence.begin());
	}
public:
	medium_chooser() { load_data(); }
	options make_choice(options player)
	{
		int max_size = N_val;
		int enum_total = enum_elem;
		options o = static_cast<options>(rand() % enum_total);
		string seq;

		//cout << OpToString(player) << endl;

		if ((sequence.size() < max_size-1))
		{
			sequence.push_back(player);
			sequence.push_back(o);

			//cout << sequence.size() << endl;
		}
		else if ((sequence.size() == max_size - 1) && data.empty())
		{
			seq = get_seq();
			sequence.push_back(player);
			update_data(seq);
			sequence.push_back(o);

			//cout << sequence.size() << endl;

			delete_round();

			//cout << "g" << endl;
		}
		else 
		{
			seq = get_seq();
			int freq = 0;

			//cout << sequence.size() << endl;

			auto it = data.find(seq);

			for (int i = r; i <= s; i++)
			{
				it = data.find(seq + OpToString(static_cast<options>(i)));
				if (freq < it->second)
				{
					o = static_cast<options>((i + 1) % (s + 1));
					freq = it->second;
				}
			}

			sequence.push_back(player);

			update_data(seq);

			sequence.push_back(o);
			//cout << sequence.size() << endl;

			delete_round();

		}

		save_data();

		return o;
	}
};
