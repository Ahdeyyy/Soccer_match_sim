#pragma once
#include "match_events.h"
#include "team.h"

class commentary
{
	//produces commentary for each event. essentially what is displayed on the console
public:
	static std::string text(events last_event, events current_event, events next_event , int time, player last_actor, player acting);

};

