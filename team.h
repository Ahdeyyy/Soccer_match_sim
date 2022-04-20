#pragma once
#include "player.h"
#include <vector>

//a struct that contains the team name and players in the team e.t.c



struct team
{
	//look for ways to solve the linker issue with the arrays 
	std::string prefixes[6] = {
	"",
	"fc","cf","sc",
	"athletic" ,"ac"
	};
	std::string names[12] = {
		"manchester" , "madrid" , "london",
		"barcelona" , "bilbao" , "midland",
		"turin","milan","paris" ,
		"lyon","marseille","amsterdam"
	};

	std::string suffixes[3] = {
		"", "united" , "city",
	};

	std::string prefix;
	std::string name;
	std::string suffix;
	std::vector<player>  players;  // index 0 contains the coach

	team()
	{

	}


	team(std::string prefix , std::string name , std::string suffix)
	{
		this->prefix = prefix;
		this->name = name;
		this->suffix = suffix;
		for (int i = 0; i < 12; i++)
		{
			//srand(time(NULL));
			players.emplace_back(player::generate_player());
		}
	}

	static team generate_team()
	{
		team t;
		//srand(time(NULL));
		int prefix_index = rand() % 6;
		//srand(time(NULL));
		int name_index = rand() % 12;
		//srand(time(NULL));
		int suffix_index = rand() % 3;

		return team(t.prefixes[prefix_index], t.names[name_index], t.suffixes[suffix_index]);
	}

	std::string display_name()
	{
		return prefix + " " + name + " " + suffix;
	}

	void display_players()
	{
		for (player player : players)
		{
			std::cout << player.last_name + " " << player.first_name + "\n";
		}
	}

};