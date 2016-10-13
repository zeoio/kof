#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "define.h"
#include "init.h"
#include "show.h"
#include "key.h"
#include "kernel.h"

void run_game(struct Member *member, int enter_key, long run_time)
{
	set_bg(member, run_time);

	if(MILLI_TO_SEC(run_time) < 3)	
	{
		load_go(&member->queue, MILLI_TO_SEC(run_time));

		run_hero(member, &member->player, KEY_NULL, run_time);
		run_hero(member, &member->robot, KEY_NULL, run_time); 
	}
	else
	{
		run_hero(member, &member->player, enter_key, run_time);

//		int rand_key = get_rand_key(member, player);
		run_hero(member, &member->robot, KEY_NULL, run_time); 

		//run_bullet(member, run_time);  
	}
}

void set_bg(struct Member *member, long run_time)
{
	if(member->window.stat_pic == 0)
	{
		member->window.time = run_time;
		member->window.stat_pic++;
		
		member->window.mainBg = member->window.image[0];
	}
	
	if(run_time-member->window.time > BG_TIME)
	{
		member->window.time = run_time;
		member->window.stat_pic++;
	
		switch(member->window.stat_pic)
		{
			case 2:
				member->window.mainBg = member->window.image[1];
				break;
			case 3:
				member->window.mainBg = member->window.image[2];
				break;
			case 4:
				member->window.mainBg = member->window.image[3];
				break;
			case 5:
				member->window.mainBg = member->window.image[4];
				break;
			case 6:
				member->window.mainBg = member->window.image[5];
				break;
			case 7:
				member->window.mainBg = member->window.image[6];
				break;
			case 8:
				member->window.mainBg = member->window.image[7];
				member->window.stat_pic = 0;
				break;
			default:	
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
		}
	}
}

void load_go(struct Queue *queue, int time)
{
	SDL_Surface *image = NULL;
	static SDL_Rect position;	
	
	switch(time)
	{
		case 0:
			image = IMG_Load("../Image/Time/time3.png");
			break;
		case 1:
			image = IMG_Load("../Image/Time/time2.png");
			break;
		case 2:	
			image = IMG_Load("../Image/Time/time1.png");
			break;	
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	position.x = 496;
	position.y = 250;

	if(enqueue(queue, image, &position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void run_hero(struct Member *member, struct Hero *hero, int enter_key, long run_time)
{
	update_key(hero, &enter_key);	
	
	switch(hero->hero)
	{
		case HERO_ANDY:
			break;
		case HERO_ATHENA:
			run_athena(member, hero, enter_key, run_time);
			break;
		case HERO_BENIMARU:
			break;
		case HERO_BILLY:
			break;
		case HERO_CHIN:
			break;
		case HERO_DAIMON:
			break;
		case HERO_IORI:
			break;
		case HERO_JOE:
			break;
		case HERO_KING:
			break;
		case HERO_KIM:
			break;
		case HERO_KULA:
			break;
		case HERO_KYO:
			break;
		case HERO_MAI:
			break;
		case HERO_LEONA:
			break;
		case HERO_MATURE:
			break;
		case HERO_ROBERT:	
			break;	
		case HERO_RYO:
			break;		
		case HERO_CLARK:
			break;
		case HERO_TERRY:	
			break;	
		case HERO_RALF:
			break;
		case HERO_VICE:
			break;
		case HERO_TAKUMA:
			break;
		case HERO_MAXIMA:
			break;
		case HERO_YURI:
			break;	
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}
}
