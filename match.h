#pragma once

#include "match_events.h"
#include "team.h"

#define HALF_TIME 45
#define FULL_TIME 90

enum teams
{
	HOME = 1,
	AWAY = 2
};

enum positions
{
	GK ,
	DEF,
	MID ,
	FWD
};


class match
{
	//keeps track of the score, time , stats , e.t.c
private:
	
	int home_goals;
	int away_goals;
	int home_corners;
	int away_corners;
	int home_free_kicks;
	int away_free_kicks;
	int home_penalties;
	int away_penalties;
	int home_fouls;
	int away_fouls;
	int home_possesion;
	int away_possesion;
	int home_shots;
	int away_shots;
	int home_passes;
	int away_passes;
	int home_passes_completed;
	int away_passes_completed;

	int game_time;

	std::vector<std::string> scorers;
	
	teams in_possesion;
	team home;
	team away;

	player acting;

	events last_event;
	events current_event;
	events next_event;

	positions position;

public:
	teams dispossess(teams in_possesion);
	match(team home = team::generate_team(), team away = team::generate_team());
	void play();
	player player_on_ball(positions position, team in_possession);
	positions play_position(events current_event , events next_event);
	void show_squads();
	void stats();


};

