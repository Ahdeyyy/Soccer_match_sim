#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>


// contains the player struct- name e.t.c


struct player
{
	std::string first_names[25] = {
	"kevin","kelly","stephen","steven","mike",
	"michael","joseph","murray","jesse","jessie",
	"ronald","donald","joe","dean","kyle",
	"chris","christian","scott","ravel","marcus",
	"ethan","wade","riley","ivan","liam"
	};

	std::string second_names[20] = {
		"howson","devine","divine","conway","penrose",
		"peterson","morrison","gray","taylor","rice",
		"kelly","clarkson","roger","snow","white",
		"black","mitchell","merson","paulson","mannix"
	};


	std::string first_name;
	std::string last_name;

	player()
	{

	}

	player(std::string first_name, std::string last_name)
	{
		this->first_name = first_name;
		this->last_name = last_name;
	}

	std::string display_name()
	{
		return first_name + " " + last_name;
	}

	static player generate_player() 
	{
		player p;
		srand(rand() * time(0) * rand() * time(0));
		int f_n_index = rand() % 25;
		srand(rand() * time(0) * rand() * time(0));
		int l_n_index = rand() % 20;
		return player(p.first_names[f_n_index], p.second_names[l_n_index]);
	}
};