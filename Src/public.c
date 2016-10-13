#include <SDL/SDL.h>
#include "define.h"
#include "public.h"

void move_window(struct Member *member, int hero_type, int move_size, int direction)
{
	if( is_move_window(member, move_size, direction) )
	{
		if(direction == HORIZONTAL)
		{
			member->window.positionBg.x += move_size;
				
			if(member->player.hero_type == hero_type)	
				hold_other(&member->robot, move_size, direction);
			else	
				hold_other(&member->player, move_size, direction);
		}
		else
		{
			member->window.positionBg.y += move_size;
			
			if(member->player.hero_type == hero_type)	
				hold_other(&member->robot, move_size, direction);
			else	
				hold_other(&member->player, move_size, direction);
		}
	}
}

static int is_move_window(struct Member *member, int move_size, int direction)
{
	if(direction == HORIZONTAL)
	{
		if(member->window.positionBg.x+move_size >= BG_WIDTH_MIN && member->window.positionBg.x+move_size <= BG_WIDTH_MAX)
			return 1;
		else
			return 0;
	}
	else	
		return 1;
}

static void hold_other(struct Hero *hero, int move_size, int direction)
{
	if(direction == HORIZONTAL)
		hero->position.x += move_size;
	else
		hero->position.y += move_size;
}

int is_right(struct Member *member, struct Hero *hero)
{
	if(hero->hero_type == 0)				
		return hero->position.x < member->robot.position.x;	
	else							
		return hero->position.x < member->player.position.x;	
}

