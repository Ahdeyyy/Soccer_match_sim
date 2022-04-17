#pragma once

//=========================================================================
//                            events
//==========================================================================
enum events
{
	NONE = 0,
	TACKLE = 1,
	INTERCEPT = 2,
	BLOCK = 3,
	PASS = 4,
	CROSS = 5,
	SHOOT = 6,
	SAVE = 7,
	SKILL = 8,
	FOUL = 9,
	YELLOW_CARD = 10,
	RED_CARD = 11,
	PENALTY = 12,
	FREE_KICK = 13,
	CORNER = 14,
	MISS = 15,
	GOAL = 16

};
class match_events
{
	//controls in-game events
public:
	static events new_event(events current_events, int prob);

};

