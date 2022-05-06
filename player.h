#pragma once
#include "headers.h"


// contains the player struct- name e.t.c

struct player
{
	std::string first_names[60] = {
	"kevin","kelly","stephen","steven","mike",
	"michael","joseph","murray","jesse","jessie",
	"ronald","donald","joe","dean","kyle",
	"chris","christian","scott","ravel","marcus",
	"ethan","wade","riley","ivan","liam",
	"glen","aidan","julian","harold","peter",
	"conner","hunter","pete","solomon","noah",
	"paul", "carlos","david","shane","rick",
	"charles","charlie","thomas","tommy","neil",
	"ted","clark","stuart","keith","marshall",
	"ernest","albert","fred","samuel","benjamin",
	"ben","luke","luka","craig","jimmy"
	};

	std::string second_names[60] = {
		"howson","devine","divine","conway","penrose",
		"peterson","morrison","gray","taylor","rice",
		"kelly","clarkson","roger","snow","white",
		"black","mitchell","merson","paulson","mannix",
		"walker","morgan","miller","perry","clark",
		"wheeler","holland","richards","stanley","miles",
		"lucas","miles","terry","fletcher","norris",
		"parks","daniel","newton","potter","francis",
		"moody","lindsey","cooper","gross","sherman",
		"brown","rodriguez","rodrigues","lee","hall",
		"simon","young","campbell","lopez","gordon",
		"burns","long","gibson","hamilton","ford"
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
		int f_n_index = rand() % 60;
		srand(rand() * time(0) * rand() * time(0));
		int l_n_index = rand() % 60;
		return player(p.first_names[f_n_index], p.second_names[l_n_index]);
	}
};