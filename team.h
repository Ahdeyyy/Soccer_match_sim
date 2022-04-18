#pragma once
#include "player.h"
#include <vector>
//a struct that contains the team name and players in the team e.t.c
struct team
{
	std::string prefix;
	std::string name;
	std::string suffix;
	std::vector<player>  players;

	team(std::string prefix , std::string name , std::string suffix)
	{
		this->prefix = prefix;
		this->name = name;
		this->suffix = suffix;
		for (int i = 0; i < 11; i++)
		{
			players.emplace_back(player::generate_player());
		}
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