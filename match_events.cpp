#include "match_events.h"
events match_events::new_event(events current_events, int prob)
{
	switch (current_events)
	{
		//0
	case NONE:
		
		if (prob < 15)
		{
			return INTERCEPT;
		}
		else if (prob < 35) 
		{
			return TACKLE;
		}
		else if (prob < 55) 
		{
			return SKILL;
		}

		return PASS;
		break;


		//1
	case TACKLE:
		if (prob < 45)
		{
			return PASS;
		}
		else if (prob < 65) 
		{
			return FOUL;
		}
		return NONE;
		break;


		//2
	case INTERCEPT:
		if (prob < 85)
		{
			return PASS;
		}
		return NONE;
		break;


		//3
	case BLOCK:

		if (prob < 45)
		{
			return PASS;
		}
		return NONE;
		break;


		//4
	case PASS:
		
		if (prob < 20)
		{
			return INTERCEPT;
		}
		else if (prob < 50)
		{
			return PASS;
		}
		else if (prob < 80)
		{
			return SHOOT;
		}
		else if (prob < 100)
		{
			return CROSS;
		}

		return NONE;
		break;


		//5
	case SKILL:
		if (prob < 20)
		{
			return TACKLE;
		}
		else if (prob < 60)
		{
			return PASS;
		}
		else if (prob < 80)
		{
			return SKILL;
		}
		else if (prob < 100)
		{
			return SHOOT;
		}
		return NONE;
		break;


		//6
	case CROSS:
		
		if (prob < 5)
		{
			return INTERCEPT;
		}
		else if (prob < 45) 
		{
			return BLOCK;
		}
		else if (prob < 60)
		{
			return PASS;
		}
		else if (prob <100)
		{
			return SHOOT;
		}
		return NONE;
		break;

		//7
	case CORNER:

		if (prob < 15) 
		{
			return BLOCK;
		}
		return CROSS;
		break;

		//8
	case FOUL:
		if (prob < 70)
		{
			return FREE_KICK;
		}
		else if (prob < 100)
		{
			return PENALTY;
		}
		//9
	case SHOOT:
		if (prob < 20)
		{
			return BLOCK;
		}
		else if (prob < 55)
		{
			return SAVE;
		}
		else if (prob < 80)
		{
			return GOAL;
		}
		return MISS;
		break;

		//10
	case GOAL:
		return PASS;
		break;

		//11

	case FREE_KICK:
		if(prob < 65)
		{
			return CROSS;
		}
		else if (prob < 100)
		{
			return SHOOT;
		}

		break;
		//12
	case MISS:
		
		return PASS;
		break;

		//13
	case SAVE:
		if (prob < 25)
		{
			return NONE;
		}
		else if (prob < 45)
		{
			return CORNER;
		}
		return PASS;
		break;
		//14
	case PENALTY:
		if (prob < 50) 
		{
			return GOAL;
		}
		else if(prob < 75)
		{
			return SAVE;
		}
		else
		{
			return MISS;
		}

		break;

	}

}
