#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <sys/time.h>
#include <SDL/SDL_image.h>
#include "define.h"
#include "show.h"
#include "init.h"

void begin_sdl(void)
{
	if(SDL_WasInit(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "SDL is already running!\n");
		return;
	}
	
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		fprintf(stderr, "Unable to init SDL!\n");
		return;
	}
}

void end_sdl(void)
{
	if(SDL_WasInit(SDL_INIT_EVERYTHING) == 0)
	{
		fprintf(stderr, "SDL was not running!\n");
		return;
	}
	
	SDL_Quit();
}

void init(struct Member *member)
{
	init_show(&member->queue);
	init_win(&member->window);
	init_live(member->live);
	init_time(&member->time);
	
	choice_hero(member);
	init_start(member);
}

void init_time(struct Time *time)
{
	time->position1.x = 480;
	time->position2.x = 510;	
	time->position1.y = time->position2.y = 50;

	time->image1 = IMG_Load("../Image/Time/time0.png");
	time->image2 = IMG_Load("../Image/Time/time0.png");
}

void init_live(int *live)
{
	int i;
		
	for(i=0; i<HERO_MAX; i++)
		live[i] = 1;
}

void init_win(struct Window *window)
{
	window->mainWindow = SDL_SetVideoMode(1024, 576, 24, SDL_SWSURFACE);
	SDL_WM_SetCaption("King of Fighters XIII", NULL);

	window->mainBg = IMG_Load("../Image/Bg/mainBg.png");

	window->positionBg.x = 0;
	window->positionBg.y = 0;
	
	load_hero(window);
	set_hero(window);	
}

void init_start(struct Member *member)
{
	free_choice_window(member);	
	set_window(member);
	
	init_hero(&member->player);
	init_robot(&member->robot);
	//reset_time(&member->time);
}

static void reset_time(struct Time *time)
{
	time->position1.x = 475;
	time->position2.x = 515;	
	time->image1 = IMG_Load("../Image/Time/time6.png");
	time->image2 = IMG_Load("../Image/Time/time0.png");
}

void free_choice_window(struct Member *member)
{
	SDL_FreeSurface(member->window.mainBg);	
	
	int i;
		
	for(i=0; i<HERO_MAX; i++)
		SDL_FreeSurface(member->window.hero[i]);	
}

void set_window(struct Member *member)
{
	member->window.stat_pic = 0;
	member->window.time = 0;	
	member->window.positionBg.x = -128;
	member->window.positionBg.y = -10;

	member->window.image[0] = IMG_Load("../Image/Bg/bg1.png");
	member->window.image[1] = IMG_Load("../Image/Bg/bg2.png");
	member->window.image[2] = IMG_Load("../Image/Bg/bg3.png");
	member->window.image[3] = IMG_Load("../Image/Bg/bg4.png");
	member->window.image[4] = IMG_Load("../Image/Bg/bg5.png");
	member->window.image[5] = IMG_Load("../Image/Bg/bg6.png");
	member->window.image[6] = IMG_Load("../Image/Bg/bg7.png");
	member->window.image[7] = IMG_Load("../Image/Bg/bg8.png");
}

static init_hero(struct Hero *player)
{
	player->blood_volume = 300;

	player->hero_type = 0;	
	player->stat = KEY_NULL;
	player->pre_stat = KEY_NULL;
	player->direction = KEY_D;
	player->stat_pic = 0;

//	init_block(player, HERO_PLAYER);		
	init_hero_position(player);
}

static init_block(struct Hero *hero, int hero_type)
{
	if(hero_type == 0)
	{
		;
//		hero->hit_block.hit_head.position.x = 	;
	}
	else
	{
		;
	}
}

static void init_hero_position(struct Hero *player)
{
	switch(player->hero)
	{
		case HERO_ANDY:
			break;	
		case HERO_ATHENA:	
			player->position.x = ATHENA_PLAYER_POSITION_X;
			player->position.y = ATHENA_PLAYER_POSITION_Y;
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

static init_robot(struct Hero *robot)
{
	robot->blood_volume = 300;

	robot->stat = KEY_NULL;
	robot->pre_stat = KEY_NULL;
	robot->direction = KEY_A;
	robot->hero_type = 1;
	
	robot->stat_pic = 0;
	robot->image = NULL;	
	robot->time = 0;
	
	init_robot_position(robot);
}

static void init_robot_position(struct Hero *robot)
{
	switch(robot->hero)
	{
		case HERO_ANDY:
			break;	
		case HERO_ATHENA:	
			robot->position.x = 390;
			robot->position.y = 60;
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

void load_hero(struct Window *window)
{
	window->hero[HERO_ANDY] = IMG_Load("../Image/Hero/andy.jpg");
	window->hero[HERO_ATHENA] = IMG_Load("../Image/Hero/athena.jpg");
	window->hero[HERO_BENIMARU] = IMG_Load("../Image/Hero/benimaru.jpg");
	window->hero[HERO_BILLY] = IMG_Load("../Image/Hero/billy.jpg");
	window->hero[HERO_CHIN] = IMG_Load("../Image/Hero/chin.jpg");
	window->hero[HERO_DAIMON] = IMG_Load("../Image/Hero/daimon.jpg");
	window->hero[HERO_IORI] = IMG_Load("../Image/Hero/iori.jpg");
	window->hero[HERO_JOE] = IMG_Load("../Image/Hero/joe.jpg");
	window->hero[HERO_KING] = IMG_Load("../Image/Hero/king.jpg");
	window->hero[HERO_KIM] = IMG_Load("../Image/Hero/kim.jpg");
	window->hero[HERO_KULA] = IMG_Load("../Image/Hero/kula.jpg");
	window->hero[HERO_KYO] = IMG_Load("../Image/Hero/kyo.jpg");
	window->hero[HERO_MAI] = IMG_Load("../Image/Hero/mai.jpg");
	window->hero[HERO_LEONA] = IMG_Load("../Image/Hero/leona.jpg");
	window->hero[HERO_MATURE] = IMG_Load("../Image/Hero/mature.jpg");
	window->hero[HERO_ROBERT] = IMG_Load("../Image/Hero/robert.jpg");
	window->hero[HERO_RYO] = IMG_Load("../Image/Hero/ryo.jpg");
	window->hero[HERO_CLARK] = IMG_Load("../Image/Hero/clark.jpg");
	window->hero[HERO_TERRY] = IMG_Load("../Image/Hero/terry.jpg");
	window->hero[HERO_RALF] = IMG_Load("../Image/Hero/ralf.jpg");
	window->hero[HERO_VICE] = IMG_Load("../Image/Hero/vice.jpg");
	window->hero[HERO_TAKUMA] = IMG_Load("../Image/Hero/takuma.jpg");
	window->hero[HERO_MAXIMA] = IMG_Load("../Image/Hero/maxima.jpg");
	window->hero[HERO_YURI] = IMG_Load("../Image/Hero/yuri.jpg");
}

void set_hero(struct Window *window)
{
	int i, j;
	
	for(i=0; i<HERO_ROW; i++)
		for(j=0; j<HERO_COLUMN; j++)
		{
			if(j < 3)
				window->position[i*HERO_COLUMN+j].x = 95* (j+1);	
			else
				window->position[i*HERO_COLUMN+j].x = 95* (j+4);

			window->position[i*HERO_COLUMN+j].y = 100 * (i+1);
		}
}

void choice_hero(struct Member *member)
{
	struct timeval old_time, new_time;

	gettimeofday(&old_time, NULL);
	new_time.tv_sec = old_time.tv_sec;
	new_time.tv_usec = old_time.tv_usec;

	int player = HERO_ANDY;
	int flag = 1;
	unsigned long run_time = 0;	
	
//	member->robot.hero = get_rand_player(member);
	member->robot.hero = HERO_ATHENA;
	
	init_player(&member->player);

	while(new_time.tv_sec-old_time.tv_sec < 30 && flag)
	{
		player = get_choice(player, &flag);  
		member->player.pre_stat = member->player.hero;
		member->player.hero = player;

		show_hero(member, run_time);
		show_time(member, run_time, MAX_CHOICE_TIME);
		show(&member->window, &member->queue);
		
		SDL_Delay(TIME_BASE);	
		gettimeofday(&new_time, NULL);
		run_time = get_time(&old_time, &new_time);
	}
}

unsigned long get_time(const struct timeval *old_time, const struct timeval *new_time)
{
	unsigned long time1 = new_time->tv_sec * 1000*1000 + new_time->tv_usec;
	unsigned long time2 = old_time->tv_sec * 1000*1000 + old_time->tv_usec;
		
	return (time1 - time2) / 1000;
}

void show_time(struct Member *member, long run_time, int max_time)
{
	unsigned short now_time = max_time - MILLI_TO_SEC(run_time);
	
	SDL_FreeSurface(member->time.image1);
	SDL_FreeSurface(member->time.image2);

	switch(now_time / 10)	
	{
		case 0:
			member->time.image1 = IMG_Load("../Image/Time/time0.png");
			break;	
		case 1:	
			member->time.image1 = IMG_Load("../Image/Time/time1.png");
			break;	
		case 2:
			member->time.image1 = IMG_Load("../Image/Time/time2.png");
			break;
		case 3:
			member->time.image1 = IMG_Load("../Image/Time/time3.png");
			break;
		case 4:
			member->time.image1 = IMG_Load("../Image/Time/time4.png");
			break;	
		case 5:
			member->time.image1 = IMG_Load("../Image/Time/time5.png");
			break;
		case 6:
			member->time.image1 = IMG_Load("../Image/Time/time6.png");
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}
	
	switch(now_time % 10)
	{
		case 0:
			member->time.image2 = IMG_Load("../Image/Time/time0.png");
			break;	
		case 1:	
			member->time.image2 = IMG_Load("../Image/Time/time1.png");
			break;	
		case 2:
			member->time.image2 = IMG_Load("../Image/Time/time2.png");
			break;
		case 3:
			member->time.image2 = IMG_Load("../Image/Time/time3.png");
			break;	
		case 4:	
			member->time.image2 = IMG_Load("../Image/Time/time4.png");
			break;	
		case 5:
			member->time.image2 = IMG_Load("../Image/Time/time5.png");
			break;	
		case 6:	
			member->time.image2 = IMG_Load("../Image/Time/time6.png");
			break;	
		case 7:
			member->time.image2 = IMG_Load("../Image/Time/time7.png");
			break;
		case 8:
			member->time.image2 = IMG_Load("../Image/Time/time8.png");
			break;
		case 9:
			member->time.image2 = IMG_Load("../Image/Time/time9.png");
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(enqueue(&member->queue, member->time.image1, &member->time.position1) == -1 ||
			 enqueue(&member->queue, member->time.image2, &member->time.position2) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void init_player(struct Hero *player)
{
	player->hero = HERO_ANDY;

	player->stat_pic = 0;
	player->image = NULL;	
	player->time = 0;
}

int get_rand_player(struct Member *member)
{
	int rand_player;

	while(1)
	{
		srand(time(NULL));
		rand_player = rand() % HERO_MAX;		
		
		if( member->live[rand_player] ) //live
			return rand_player;	
	}
}

int get_choice(int player, int *flag)
{
	int enter_key = check_key(KEY_NULL);
		
	switch(enter_key)
	{
		case KEY_W:
			if(player-HERO_COLUMN >= 0)
				player -= HERO_COLUMN;
			break;
		case KEY_S:
			if(player+HERO_COLUMN < HERO_MAX)
				player += HERO_COLUMN;
			break;
		case KEY_A:
			if(player-1 >= 0)
				player--;
			break;
		case KEY_D:
			if(player+1 < HERO_MAX) 
				player++;
			break;
		case KEY_J:
			*flag = 0;
			break;
		default:
			;
	}
	
	return player;
}

int show_hero(struct Member *member, long run_time)
{
	int i;   
	
	for(i=0; i<HERO_MAX; i++)
	{
		if(enqueue(&member->queue, member->window.hero[i],
					&member->window.position[i]) == -1)
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	show_player(member, run_time);
}

void show_player(struct Member *member, long run_time)
{
	switch(member->player.hero)
	{
		case HERO_ANDY:
			member->player.position.x = -10;
			member->player.position.y = 160;		
			show_andy(member, run_time);
			break;	
		case HERO_ATHENA:
			member->player.position.x = 60;
			member->player.position.y = 0;		
			show_athena(member, run_time);
			break;
		case HERO_BENIMARU:
			member->player.position.x = 270;
			member->player.position.y = -35;		
			show_benimaru(member, run_time);
			break;
		case HERO_BILLY:
			member->player.position.x = 160;
			member->player.position.y = -30;		
			show_billy(member, run_time);
			break;
		case HERO_CHIN:
			member->player.position.x = 350;
			member->player.position.y = 215;		
			show_chin(member, run_time);	
			break;
		case HERO_DAIMON:
			member->player.position.x = 20;
			member->player.position.y = 115;		
			show_daimon(member, run_time);
			break;
		case HERO_IORI:
			member->player.position.x = 220;
			member->player.position.y = -8;		
			show_iori(member, run_time);
			break;	
		case HERO_JOE:
			member->player.position.x = 250;
			member->player.position.y = -150;		
			show_joe(member, run_time);
			break;	
		case HERO_KING:
			member->player.position.x = 250;
			member->player.position.y = 165;		
			show_king(member, run_time);
			break;	
		case HERO_KIM:
			member->player.position.x = 290;
			member->player.position.y = -170;		
			show_kim(member, run_time);
			break;	
		case HERO_KULA:
			member->player.position.x = -150;
			member->player.position.y = -50;		
			show_kula(member, run_time);
			break;	
		case HERO_KYO:
			member->player.position.x = 100;
			member->player.position.y = -30;		
			show_kyo(member, run_time);
			break;	
		case HERO_MAI:
			member->player.position.x = 225;
			member->player.position.y = 100;		
			show_mai(member, run_time);
			break;	
		case HERO_LEONA:
			member->player.position.x = -125;
			member->player.position.y = -27;		
			show_leona(member, run_time);
			break;	
		case HERO_MATURE:
			member->player.position.x = 250;
			member->player.position.y = -30;		
			show_mature(member, run_time);
			break;	
		case HERO_ROBERT:
			member->player.position.x = 130;
			member->player.position.y = 55;		
			show_robert(member, run_time);
			break;	
		case HERO_RYO:
			member->player.position.x = -5;
			member->player.position.y = 127;		
			show_ryo(member, run_time);
			break;	
		case HERO_CLARK:
			member->player.position.x = 0;
			member->player.position.y = 5;		
			show_clark(member, run_time);
			break;	
		case HERO_TERRY:
			member->player.position.x = 75;
			member->player.position.y = -165;		
			show_terry(member, run_time);
			break;	
		case HERO_RALF:
			member->player.position.x = 253;
			member->player.position.y = 73;		
			show_ralf(member, run_time);
			break;	
		case HERO_VICE:
			member->player.position.x = 250;
			member->player.position.y = -30;		
			show_vice(member, run_time);
			break;	
		case HERO_TAKUMA:
			member->player.position.x = 0;
			member->player.position.y = 10;		
			show_takuma(member, run_time);
			break;	
		case HERO_MAXIMA: 	
			member->player.position.x = 135;
			member->player.position.y = 38;		
			show_maxima(member, run_time);
			break;	
		case HERO_YURI:
			member->player.position.x = 130;
			member->player.position.y = -35;		
			show_yuri(member, run_time);
			break;	
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}
}

void show_andy(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Andy/left1.png");
	}

	if(run_time-member->player.time > ANDY_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Andy/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Andy/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Andy/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Andy/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Andy/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Andy/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Andy/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Andy/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Andy/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Andy/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Andy/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Andy/left13.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_athena(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right1.png");
	}

	if(run_time-member->player.time > ATHENA_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right16.png");
				break;
			case 17:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right17.png");
				break;
			case 18:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right18.png");
				break;
			case 19:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right19.png");
				break;
			case 20:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right20.png");
				break;
			case 21:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right21.png");
				break;
			case 22:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right22.png");
				break;
			case 23:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right23.png");
				break;
			case 24:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right24.png");
				break;
			case 25:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right25.png");
				break;
			case 26:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right26.png");
				break;
			case 27:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right27.png");
				break;
			case 28:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right28.png");
				break;
			case 29:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right29.png");
				break;
			case 30:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right30.png");
				break;
			case 31:
				member->player.image = IMG_Load("../Image/Hero/Athena/Key_NULL/right31.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}
	
	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_benimaru(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Benimaru/left1.png");
	}

	if(run_time-member->player.time > BENIMARU_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Benimaru/left9.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_billy(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Billy/left1.png");
	}

	if(run_time-member->player.time > BILLY_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Billy/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Billy/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Billy/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Billy/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Billy/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Billy/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Billy/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Billy/left9.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_chin(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Chin/left1.png");
	}

	if(run_time-member->player.time > CHIN_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Chin/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Chin/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Chin/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Chin/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Chin/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Chin/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Chin/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Chin/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Chin/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Chin/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Chin/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Chin/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Chin/left14.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_daimon(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Daimon/left1.png");
	}

	if(run_time-member->player.time > DAIMON_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Daimon/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Daimon/left16.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_iori(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Iori/left1.png");
	}

	if(run_time-member->player.time > IORI_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Iori/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Iori/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Iori/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Iori/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Iori/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Iori/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Iori/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Iori/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Iori/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Iori/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Iori/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Iori/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Iori/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Iori/left15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Iori/left16.png");
				break;
			case 17:
				member->player.image = IMG_Load("../Image/Hero/Iori/left17.png");
				break;
			case 18:
				member->player.image = IMG_Load("../Image/Hero/Iori/left18.png");
				break;
			case 19:
				member->player.image = IMG_Load("../Image/Hero/Iori/left19.png");
				break;
			case 20:
				member->player.image = IMG_Load("../Image/Hero/Iori/left20.png");
				break;
			case 21:
				member->player.image = IMG_Load("../Image/Hero/Iori/left21.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_joe(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Joe/left1.png");
	}

	if(run_time-member->player.time > JOE_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Joe/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Joe/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Joe/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Joe/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Joe/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Joe/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Joe/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Joe/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Joe/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Joe/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Joe/left12.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_king(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/King/left1.png");
	}

	if(run_time-member->player.time > KING_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/King/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/King/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/King/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/King/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/King/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/King/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/King/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/King/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/King/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/King/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/King/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/King/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/King/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/King/left15.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_kim(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Kim/left1.png");
	}

	if(run_time-member->player.time > KIM_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Kim/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Kim/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Kim/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Kim/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Kim/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Kim/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Kim/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Kim/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Kim/left10.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_kula(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Kula/left1.png");
	}

	if(run_time-member->player.time > KULA_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Kula/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Kula/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Kula/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Kula/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Kula/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Kula/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Kula/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Kula/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Kula/left10.png");
				break;	
			case 11:		
				member->player.image = IMG_Load("../Image/Hero/Kula/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Kula/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Kula/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Kula/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Kula/left15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Kula/left16.png");
				break;
			case 17:
				member->player.image = IMG_Load("../Image/Hero/Kula/left17.png");
				break;
			case 18:
				member->player.image = IMG_Load("../Image/Hero/Kula/left18.png");
				break;	
			case 19:		
				member->player.image = IMG_Load("../Image/Hero/Kula/left19.png");
				break;
			case 20:
				member->player.image = IMG_Load("../Image/Hero/Kula/left20.png");
				break;
			case 21:
				member->player.image = IMG_Load("../Image/Hero/Kula/left21.png");
				break;
			case 22:
				member->player.image = IMG_Load("../Image/Hero/Kula/left22.png");
				break;
			case 23:
				member->player.image = IMG_Load("../Image/Hero/Kula/left23.png");
				break;
			case 24:
				member->player.image = IMG_Load("../Image/Hero/Kula/left24.png");
				break;
			case 25:
				member->player.image = IMG_Load("../Image/Hero/Kula/left25.png");
				break;
			case 26:
				member->player.image = IMG_Load("../Image/Hero/Kula/left26.png");
				break;	
			case 27:		
				member->player.image = IMG_Load("../Image/Hero/Kula/left27.png");
				break;
			case 28:
				member->player.image = IMG_Load("../Image/Hero/Kula/left28.png");
				break;
			case 29:
				member->player.image = IMG_Load("../Image/Hero/Kula/left29.png");
				break;
			case 30:
				member->player.image = IMG_Load("../Image/Hero/Kula/left30.png");
				break;
			case 31:
				member->player.image = IMG_Load("../Image/Hero/Kula/left31.png");
				break;
			case 32:
				member->player.image = IMG_Load("../Image/Hero/Kula/left32.png");
				break;
			case 33:
				member->player.image = IMG_Load("../Image/Hero/Kula/left33.png");
				break;
			case 34:
				member->player.image = IMG_Load("../Image/Hero/Kula/left34.png");
				break;	
			case 35:		
				member->player.image = IMG_Load("../Image/Hero/Kula/left35.png");
				break;
			case 36:
				member->player.image = IMG_Load("../Image/Hero/Kula/left36.png");
				break;
			case 37:
				member->player.image = IMG_Load("../Image/Hero/Kula/left37.png");
				break;
			case 38:
				member->player.image = IMG_Load("../Image/Hero/Kula/left38.png");
				break;
			case 39:
				member->player.image = IMG_Load("../Image/Hero/Kula/left39.png");
				break;
			case 40:
				member->player.image = IMG_Load("../Image/Hero/Kula/left40.png");
				break;
			case 41:
				member->player.image = IMG_Load("../Image/Hero/Kula/left41.png");
				break;
			case 42:
				member->player.image = IMG_Load("../Image/Hero/Kula/left42.png");
				break;	
			case 43:		
				member->player.image = IMG_Load("../Image/Hero/Kula/left43.png");
				break;
			case 44:
				member->player.image = IMG_Load("../Image/Hero/Kula/left44.png");
				break;
			case 45:
				member->player.image = IMG_Load("../Image/Hero/Kula/left45.png");
				break;
			case 46:
				member->player.image = IMG_Load("../Image/Hero/Kula/left46.png");
				break;
			case 47:
				member->player.image = IMG_Load("../Image/Hero/Kula/left47.png");
				break;
			case 48:
				member->player.image = IMG_Load("../Image/Hero/Kula/left48.png");
				break;
			case 49:
				member->player.image = IMG_Load("../Image/Hero/Kula/left49.png");
				break;
			case 50:
				member->player.image = IMG_Load("../Image/Hero/Kula/left50.png");
				break;	
			case 51:		
				member->player.image = IMG_Load("../Image/Hero/Kula/left51.png");
				break;
			case 52:
				member->player.image = IMG_Load("../Image/Hero/Kula/left52.png");
				break;
			case 53:
				member->player.image = IMG_Load("../Image/Hero/Kula/left53.png");
				break;
			case 54:
				member->player.image = IMG_Load("../Image/Hero/Kula/left54.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_kyo(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Kyo/left1.png");
	}

	if(run_time-member->player.time > KYO_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Kyo/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Kyo/left11.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_mai(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Mai/left1.png");
	}

	if(run_time-member->player.time > MAI_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Mai/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Mai/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Mai/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Mai/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Mai/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Mai/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Mai/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Mai/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Mai/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Mai/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Mai/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Mai/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Mai/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Mai/left15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Mai/left16.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_leona(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Leona/left1.png");
	}

	if(run_time-member->player.time > LEONA_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Leona/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Leona/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Leona/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Leona/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Leona/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Leona/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Leona/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Leona/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Leona/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Leona/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Leona/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Leona/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Leona/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Leona/left15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Leona/left16.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}
	
	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_mature(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Mature/left1.png");
	}

	if(run_time-member->player.time > MATURE_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Mature/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Mature/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Mature/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Mature/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Mature/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Mature/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Mature/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Mature/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Mature/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Mature/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Mature/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Mature/left13.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}
	
	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_robert(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Robert/left1.png");
	}

	if(run_time-member->player.time > ROBERT_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Robert/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Robert/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Robert/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Robert/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Robert/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Robert/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Robert/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Robert/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Robert/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Robert/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Robert/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Robert/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Robert/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Robert/left15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Robert/left16.png");
				break;
			case 17:
				member->player.image = IMG_Load("../Image/Hero/Robert/left17.png");
				break;
			case 18:
				member->player.image = IMG_Load("../Image/Hero/Robert/left18.png");
				break;
			case 19:
				member->player.image = IMG_Load("../Image/Hero/Robert/left19.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_ryo(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Ryo/left1.png");
	}

	if(run_time-member->player.time > RYO_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Ryo/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left12.png");
				break;
			case 13:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left13.png");
				break;
			case 14:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left14.png");
				break;
			case 15:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left15.png");
				break;
			case 16:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left16.png");
				break;
			case 17:
				member->player.image = IMG_Load("../Image/Hero/Ryo/left17.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}
	
	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_clark(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Clark/left1.png");
	}

	if(run_time-member->player.time > CLARK_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Clark/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Clark/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Clark/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Clark/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Clark/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Clark/left7.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_terry(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Terry/left1.png");
	}

	if(run_time-member->player.time > TERRY_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Terry/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Terry/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Terry/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Terry/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Terry/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Terry/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Terry/left8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Terry/left9.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_ralf(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Ralf/left1.png");
	}

	if(run_time-member->player.time > RALF_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Ralf/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Ralf/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Ralf/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Ralf/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Ralf/left6.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_vice(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Vice/left1.png");
	}

	if(run_time-member->player.time > VICE_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Vice/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Vice/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Vice/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Vice/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Vice/left6.png");
				break;
			case 7:		
				member->player.image = IMG_Load("../Image/Hero/Vice/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Vice/left8.png");
				break;
			case 9:		
				member->player.image = IMG_Load("../Image/Hero/Vice/left9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Vice/left10.png");
				break;
			case 11:
				member->player.image = IMG_Load("../Image/Hero/Vice/left11.png");
				break;
			case 12:
				member->player.image = IMG_Load("../Image/Hero/Vice/left12.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_takuma(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Takuma/left1.png");
	}

	if(run_time-member->player.time > TAKUMA_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Takuma/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Takuma/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Takuma/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Takuma/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Takuma/left6.png");
				break;
			case 7:		
				member->player.image = IMG_Load("../Image/Hero/Takuma/left7.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}

	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_yuri(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Yuri/left1.png");
	}

	if(run_time-member->player.time > YURI_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Yuri/left2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Yuri/left3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Yuri/left4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Yuri/left5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Yuri/left6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Yuri/left7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Yuri/left8.png");
				break;
			case 9:		
				member->player.image = IMG_Load("../Image/Hero/Yuri/left9.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}
	
	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

void show_maxima(struct Member *member, long run_time)
{
	if(member->player.pre_stat != member->player.hero)
	{
		member->player.pre_stat = member->player.hero;
		member->player.stat_pic = 0;
	}

	if(member->player.stat_pic == 0)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		
		SDL_FreeSurface(member->player.image);
		member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right1.png");
	}

	if(run_time-member->player.time > MAXIMA_TIME)
	{
		member->player.time = run_time;
		member->player.stat_pic++;
		SDL_FreeSurface(member->player.image);
		
		switch(member->player.stat_pic)
		{
			case 2:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right2.png");
				break;
			case 3:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right3.png");
				break;	
			case 4:		
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right4.png");
				break;
			case 5:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right5.png");
				break;
			case 6:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right6.png");
				break;
			case 7:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right7.png");
				break;
			case 8:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right8.png");
				break;
			case 9:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right9.png");
				break;
			case 10:
				member->player.image = IMG_Load("../Image/Hero/Maxima/Wait/right10.png");
				member->player.stat_pic = 0;
				break;
			default:
				fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);	
		}
	}
	
	if(enqueue(&member->queue, member->player.image, 
					&member->player.position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}
