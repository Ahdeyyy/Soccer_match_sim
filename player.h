#pragma once
#include <string>
#include <random>

std::random_device r;
std::default_random_engine e1(r());
std::uniform_int_distribution<int> uniform_dist(0, 20);

// contains the player struct- name e.t.c
std::string first_names[] = {
	"kevin","kelly","stephen","steven","mike","michael",
	"joseph","murray","jesse","jessie","ronald","donald","joe",
	"dean","kyle","chris","christian","scott","ravel","marcus"
};

std::string second_names[] = {
	"howson","devine","divine","conway","penrose","peterson",
	"morrison","gray","taylor","rice","kelly","clarkson","roger",
	"snow","white","black","mitchell","merson","paulson",
	"minx"
};


struct player
{
	std::string first_name;
	std::string last_name;

	player(std::string first_name, std::string last_name)
	{
		this->first_name = first_name;
		this->last_name = last_name;
	}

	static player generate_player() 
	{
		return player(first_names[uniform_dist(e1)], second_names[uniform_dist(e1)]);
	}
};