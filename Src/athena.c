#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "define.h"
#include "show.h"
#include "public.h"
#include "athena.h"

void run_athena(struct Member *member, struct Hero *hero, int enter_key, long run_time)
{
	switch(enter_key)
	{
		case KEY_NULL:
			set_athena_deft(member, hero, run_time);
			break;
		case KEY_W:
			set_athena_up(member, hero, run_time);
			break;
		case STAT_UP_DOWN:
			set_athena_up_down(member, hero, run_time);
			break;
		case KEY_S:
			set_athena_down(member, hero, run_time);
			break;
		case STAT_DOWN_UP:
			set_athena_down_up(member, hero, run_time);
			break;
		case STAT_DOWN_KEEP:
			set_athena_down_keep(member, hero, run_time);
			break;
		case KEY_A:
			set_athena_left(member, hero, run_time);
			break;
		case KEY_D:
			set_athena_right(member, hero, run_time);
			break;
		case KEY_J:
			set_athena_j(member, hero, run_time);
			break;
		case KEY_K:
			set_athena_k(member, hero, run_time);
			break;
		case KEY_L:
			set_athena_l(member, hero, run_time);
			break;
		case KEY_U:
			set_athena_u(member, hero, run_time);
			break;
		case KEY_I:
			set_athena_i(member, hero, run_time);
			break;
		case KEY_O:
			set_athena_o(member, hero, run_time);
			break;
		case KEY_O_KEEP:
			set_athena_o_keep(member, hero, run_time);
			break;
		case KEY_O_STOP:
			set_athena_o_stop(member, hero, run_time);
			break;
		case ALT_WA:
			printf("key_wa!\n");
			break;
		case ALT_WD:
			printf("key_wd!\n");
			break;
		case ALT_AS:
			set_athena_ALT_AS(member, hero, run_time);
			break;
		case ALT_DS:
			set_athena_ALT_DS(member, hero, run_time);
			break;
		case ALT_WJ:
			printf("key_wj!\n");
			break;
		case ALT_WK:
			printf("key_wk!\n");
			break;
		case ALT_ADJ:
			set_athena_ALT_ADJ(member, hero, run_time);
			break;
		case ALT_ADK:
			set_athena_ALT_ADK(member, hero, run_time);
			break;
		case ALT_ADI:
			set_athena_ALT_ADI(member, hero, run_time);
			break;
		case ALT_SJ:
			set_athena_ALT_SJ(member, hero, run_time);
			break;
		case ALT_SK:
			set_athena_ALT_SK(member, hero, run_time);
			break;
		case ALT_SU:
			set_athena_ALT_SU(member, hero, run_time);
			break;
		case ALT_SI:
			set_athena_ALT_SI(member, hero, run_time);
			break;
		case ALT_JK:
			set_athena_ALT_JK(member, hero, run_time);
			break;
		case ALT_SL:
			set_athena_ALT_SL(member, hero, run_time);
			break;
		case ALT_SL_STOP:
			set_athena_ALT_SL_stop(member, hero, run_time);
			break;
		case ALT_ADU:
			set_athena_ALT_ADU(member, hero, run_time);
			break;
		case ALT_ADO:
			set_athena_ALT_ADO(member, hero, run_time);
			break;
		case ALT_ADO_UP:
			set_athena_ALT_ADO_up(member, hero, run_time);
			break;
		case ALT_ADO_HOLD:
			set_athena_ALT_ADO_hold(member, hero, run_time);
			break;
		case ALT_ADO_DOWN:
			set_athena_ALT_ADO_down(member, hero, run_time);
			break;
		case ALT_ADL:
			set_athena_ALT_ADL(member, hero, run_time);
			break;
		case STAT_RUN:
			set_athena_run(member, hero, run_time);
			break;
		case STAT_RUN_STOP:
			set_athena_run_stop(member, hero, run_time);
			break;
		case STAT_L_HOLD:
			set_athena_l_hold(member, hero, run_time);
			break;
		case STAT_L_STOP:
			set_athena_l_stop(member, hero, run_time);
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}
}

static void set_athena_deft(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_NULL)
	{
		hero->stat = KEY_NULL;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_DEFT_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_deft_left(hero);
		else if(hero->direction == KEY_D)
			load_athena_deft_right(hero);
		else
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
		hero->pre_stat = KEY_NULL;
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_deft_left(struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left11.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left12.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left13.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left14.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left15.png");
			break;
		case 16:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left16.png");
			break;
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left17.png");
			break;
		case 18:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left18.png");
			break;
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left19.png");
			break;
		case 20:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left20.png");
			break;
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left21.png");
			break;
		case 22:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left22.png");
			break;
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left23.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left24.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left25.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left26.png");
			break;
		case 27:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left27.png");
			break;
		case 28:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left28.png");
			break;
		case 29:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left29.png");
			break;
		case 30:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left30.png");
			break;
		case 31:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/left31.png");
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}
}

static void load_athena_deft_right(struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right11.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right12.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right13.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right14.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right15.png");
			break;
		case 16:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right16.png");
			break;
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right17.png");
			break;
		case 18:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right18.png");
			break;
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right19.png");
			break;
		case 20:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right20.png");
			break;
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right21.png");
			break;
		case 22:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right22.png");
			break;
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right23.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right24.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right25.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right26.png");
			break;
		case 27:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right27.png");
			break;
		case 28:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right28.png");
			break;
		case 29:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right29.png");
			break;
		case 30:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right30.png");
			break;
		case 31:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_NULL/right31.png");
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}
}

static void set_athena_down(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_S)
	{
		hero->stat = KEY_S;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_DOWN_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_down_left(hero);
		else if(hero->direction == KEY_D)
			load_athena_down_right(hero);
		else
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_down_left(struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left6.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_S;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_down_right(struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right6.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_S;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_down_up(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != STAT_DOWN_UP)
	{
		hero->stat = STAT_DOWN_UP;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_DOWN_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_down_up_left(hero);
		else if(hero->direction == KEY_D)
			load_athena_down_up_right(hero);
		else
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_down_up_left(struct Hero *hero)
{
	switch(7 - hero->stat_pic)
	{
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left6.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left5.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left4.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left3.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left2.png");
			break;
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/left1.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_DOWN_UP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_down_up_right(struct Hero *hero)
{
	switch(7 - hero->stat_pic)
	{
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right6.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right5.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right4.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right3.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right2.png");
			break;
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S/right1.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_DOWN_UP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_down_keep(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != STAT_DOWN_KEEP)
	{
		hero->stat = STAT_DOWN_KEEP;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_DOWN_KEEP_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_down_keep_left(hero);
		else if(hero->direction == KEY_D)
			load_athena_down_keep_right(hero);
		else
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_down_keep_right(struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right11.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right12.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right13.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right14.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right15.png");
			break;
		case 16:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right16.png");
			break;
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right17.png");
			break;
		case 18:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right18.png");
			break;
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right19.png");
			break;
		case 20:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right20.png");
			break;
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right21.png");
			break;
		case 22:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right22.png");
			break;
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right23.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right24.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right25.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right26.png");
			break;
		case 27:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right27.png");
			break;
		case 28:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right28.png");
			break;
		case 29:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right29.png");
			break;
		case 30:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right30.png");
			break;
		case 31:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/right31.png");
			hero->stat = KEY_NULL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_down_keep_left(struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left11.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left12.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left13.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left14.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left15.png");
			break;
		case 16:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left16.png");
			break;
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left17.png");
			break;
		case 18:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left18.png");
			break;
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left19.png");
			break;
		case 20:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left20.png");
			break;
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left21.png");
			break;
		case 22:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left22.png");
			break;
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left23.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left24.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left25.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left26.png");
			break;
		case 27:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left27.png");
			break;
		case 28:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left28.png");
			break;
		case 29:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left29.png");
			break;
		case 30:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left30.png");
			break;
		case 31:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_S_hold/left31.png");
			hero->stat = KEY_NULL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_right(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_D)
	{
		hero->stat = KEY_D;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_WALK_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_D)
			load_athena_right_forward(member, hero);
		else
			load_athena_right_backward(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_right_forward(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/right10.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_D;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >=5 && hero->stat_pic <= 7)
		athena_move_right_forward(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}
//position not change
static void load_athena_right_backward(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/left9.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_D;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >=4 && hero->stat_pic <= 6)
		athena_move_right_backward(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_right_forward(struct Member *member, struct Hero *hero)
{
	if(hero->position.x + ATHENA_FORWARD_SIZE <= 530)
	{
		hero->position.x += ATHENA_FORWARD_SIZE;
		move_window(member, hero->hero_type, -WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void athena_move_right_backward(struct Member *member, struct Hero *hero)
{
	if(hero->position.x + ATHENA_BACKWARD_SIZE <= 530)
	{
		hero->position.x += ATHENA_BACKWARD_SIZE;
		move_window(member, hero->hero_type, -WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void set_athena_left(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_A)
	{
		hero->stat = KEY_A;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_WALK_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_left_forward(member, hero);
		else
			load_athena_left_backward(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_left_forward(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Forward/left10.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_A;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >=5 && hero->stat_pic <= 7)
		athena_move_left_forward(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}
//position not change
static void load_athena_left_backward(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Backward/right9.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_A;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >=4 && hero->stat_pic <= 6)
		athena_move_left_backward(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_left_forward(struct Member *member, struct Hero *hero)
{
	if(hero->position.x - ATHENA_FORWARD_SIZE >= -380)
	{
		hero->position.x -= ATHENA_FORWARD_SIZE;
		move_window(member, hero->hero_type, WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void athena_move_left_backward(struct Member *member, struct Hero *hero)
{
	if(hero->position.x - ATHENA_BACKWARD_SIZE >= -380)
	{
		hero->position.x -= ATHENA_BACKWARD_SIZE;
		move_window(member, hero->hero_type, WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void set_athena_run(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != STAT_RUN)
	{
		hero->stat = STAT_RUN;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_RUN_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_D)
			load_athena_run_right(member, hero);
		else
			load_athena_run_left(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_run_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/right9.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_RUN;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	athena_move_run_right(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_run_right(struct Member *member, struct Hero *hero)
{
	if(hero->position.x + ATHENA_RUN_SIZE <= 530)
	{
		hero->position.x += ATHENA_RUN_SIZE;
		move_window(member, hero->hero_type, -WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void load_athena_run_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Run/left9.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_RUN;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	athena_move_run_left(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_run_left(struct Member *member, struct Hero *hero)
{
	if(hero->position.x - ATHENA_RUN_SIZE >= -380)
	{
		hero->position.x -= ATHENA_RUN_SIZE;
		move_window(member, hero->hero_type, WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void set_athena_run_stop(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != STAT_RUN_STOP)
	{
		hero->stat = STAT_RUN_STOP;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_RUN_STOP_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_D)
			load_athena_run_stop_right(member, hero);
		else
			load_athena_run_stop_left(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_run_stop_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/right5.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_RUN_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_run_stop_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/RunStop/left5.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_RUN_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_up(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_W)
	{
		hero->stat = KEY_W;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_JUMP_UP_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_jump_left(member, hero);
		else
			load_athena_jump_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_jump_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left5.png");
			hero->stat = STAT_UP_DOWN;
			hero->pre_stat = KEY_W;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	athena_move_jump_up(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_jump_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right5.png");
			hero->stat = STAT_UP_DOWN;
			hero->pre_stat = KEY_W;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	athena_move_jump_up(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_jump_up(struct Member *member, struct Hero *hero)
{
	hero->position.y -= ATHENA_JUMP_UP_SIZE;
	move_window(member, hero->hero_type, WINDOW_JUMP_UP_SIZE, VERTICAL);
}

static void set_athena_up_down(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != STAT_UP_DOWN)
	{
		hero->stat = STAT_UP_DOWN;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_JUMP_DOWN_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_jump_down_left(member, hero);
		else
			load_athena_jump_down_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_jump_down_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left6.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left7.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left8.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left9.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left10.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left11.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left12.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left13.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/left14.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_UP_DOWN;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >= 1 && hero->stat_pic <= 3)
		athena_move_jump_down(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_jump_down_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right6.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right7.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right8.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right9.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right10.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right11.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right12.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right13.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_W/right14.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_UP_DOWN;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >= 1 && hero->stat_pic <= 3)
		athena_move_jump_down(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_jump_down(struct Member *member, struct Hero *hero)
{
	hero->position.y += ATHENA_JUMP_DOWN_SIZE;
	move_window(member, hero->hero_type, -WINDOW_JUMP_DOWN_SIZE, VERTICAL);
}

static void set_athena_j(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_J)
	{
		hero->stat = KEY_J;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_J_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_j_left(member, hero);
		else
			load_athena_j_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_j_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/right2.png");
			break;
		case 3:
		case 4:
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/right3.png");
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/right4.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/right5.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/right6.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/right6.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_J;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_j_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/left2.png");
			break;
		case 3:
		case 4:
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/left3.png");
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/left4.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/left5.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/left6.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_J/left6.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_J;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_k(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_K)
	{
		hero->stat = KEY_K;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_K_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_k_left(member, hero);
		else
			load_athena_k_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_k_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left3.png");
			break;
		case 4:
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left4.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left5.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left6.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left7.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/left8.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_K;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_k_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right3.png");
			break;
		case 4:
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right4.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right5.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right6.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right7.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_K/right8.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_K;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_l(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_L)
	{
		hero->stat = KEY_L;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_L_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_l_left(member, hero);
		else
			load_athena_l_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_l_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right3.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_L;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_l_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left3.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_L;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_l_hold(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != STAT_L_HOLD)
	{
		hero->stat = STAT_L_HOLD;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_L_HOLD_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_l_hold_left(member, hero);
		else
			load_athena_l_hold_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_l_hold_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right2.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right3.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right3.png");
			hero->stat = KEY_NULL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_l_hold_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left2.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left3.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left3.png");
			hero->stat = KEY_NULL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_l_stop(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != STAT_L_STOP)
	{
		hero->stat = STAT_L_STOP;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_L_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_l_stop_left(member, hero);
		else
			load_athena_l_stop_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_l_stop_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right4.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right5.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/right6.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_L_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_l_stop_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left4.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left5.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_L/left6.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = STAT_L_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_i(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_I)
	{
		hero->stat = KEY_I;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_I_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_i_left(member, hero);
		else
			load_athena_i_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_i_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right2.png");
			break;
		case 3:
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right3.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right4.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right5.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right8.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right9.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right10.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/right11.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_I;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_i_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left2.png");
			break;
		case 3:
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left3.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left4.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left5.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left8.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left9.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left10.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_I/left11.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_I;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_ADU(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADU)
	{
		hero->stat = ALT_ADU;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADU_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADU_left(member, hero);
		else
			load_athena_ADU_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADU_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/right1.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/right2.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/right3.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/right4.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/right5.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/right6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/right7.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADU;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADU_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/left1.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/left2.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/left3.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/left4.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/left5.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/left6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADU/left7.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADU;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_ADO(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADO)
	{
		hero->stat = ALT_ADO;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADO_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADO_left(member, hero);
		else
			load_athena_ADO_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right8.png");
			hero->stat = ALT_ADO_UP;
			hero->pre_stat = ALT_ADO;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left8.png");
			hero->stat = ALT_ADO_UP;
			hero->pre_stat = ALT_ADO;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_ADO_up(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADO_UP)
	{
		hero->stat = ALT_ADO_UP;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADO_UP_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADO_up_left(member, hero);
		else if(hero->direction == KEY_D)
			load_athena_ADO_up_right(member, hero);
		else
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);

		hero->position.y -= ATHENA_ADO_UP_SIZE;
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_up_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left9.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left10.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left11.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left12.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left13.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left14.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left15.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left16.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left17.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left18.png");
			hero->stat = ALT_ADO_HOLD;
			hero->pre_stat = ALT_ADO_UP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_up_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right9.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right10.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right11.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right12.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right13.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right14.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right15.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right16.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right17.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right18.png");
			hero->stat = ALT_ADO_HOLD;
			hero->pre_stat = ALT_ADO_UP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static int ADO_hold_count = ATHENA_ADO_HOLD_COUNT;

static void set_athena_ALT_ADO_hold(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADO_HOLD)
	{
		hero->stat = ALT_ADO_HOLD;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADO_HOLD_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADO_hold_left(member, hero);
		else if(hero->direction == KEY_D)
			load_athena_ADO_hold_right(member, hero);
		else
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_hold_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left19.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left20.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left21.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left22.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left23.png");

			if(--ADO_hold_count <= 0)
			{
				hero->stat = ALT_ADO_DOWN;
				hero->pre_stat = ALT_ADO_HOLD;
				ADO_hold_count = ATHENA_ADO_HOLD_COUNT;
			}
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_hold_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right19.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right20.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right21.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right22.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right23.png");

			if(--ADO_hold_count <= 0)
			{
				hero->stat = ALT_ADO_DOWN;
				hero->pre_stat = ALT_ADO_HOLD;
				ADO_hold_count = ATHENA_ADO_HOLD_COUNT;
			}

			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_ADO_down(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADO_DOWN)
	{
		hero->stat = ALT_ADO_DOWN;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADO_DOWN_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADO_down_left(member, hero);
		else if(hero->direction == KEY_D)
			load_athena_ADO_down_right(member, hero);
		else
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);

		hero->position.y += ATHENA_ADO_DOWN_SIZE;
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_down_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left24.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left25.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left26.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left27.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left28.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/left29.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADO_DOWN;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADO_down_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right24.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right25.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right26.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right27.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right28.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADO/right29.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADO_DOWN;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_ADK(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADK)
	{
		hero->stat = ALT_ADK;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADK_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADK_left(member, hero);
		else
			load_athena_ADK_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADK_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right4.png");
			break;
		case 5:
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right5.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right6.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right7.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/right8.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADK;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADK_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left4.png");
			break;
		case 5:
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left5.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left6.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left7.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADK/left8.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADK;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_u(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_U)
	{
		hero->stat = KEY_U;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_U_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_u_left(member, hero);
		else
			load_athena_u_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_u_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right4.png");
			break;
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right5.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right8.png");
			break;
		case 10:
		case 11:
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right9.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/right10.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_U;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_u_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left4.png");
			break;
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left5.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left8.png");
			break;
		case 10:
		case 11:
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left9.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_U/left10.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_U;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_o(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_O)
	{
		hero->stat = KEY_O;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_O_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_o_left(member, hero);
		else
			load_athena_o_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_o_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right11.png");
			hero->stat = KEY_O_KEEP;
			hero->pre_stat = KEY_O;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_o_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left11.png");
			hero->stat = KEY_O_KEEP;
			hero->pre_stat = KEY_O;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static int O_keep_count = ATHENA_O_KEEP_COUNT;

static void set_athena_o_keep(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_O_KEEP)
	{
		hero->stat = KEY_O_KEEP;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_O_KEEP_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_o_keep_left(member, hero);
		else
			load_athena_o_keep_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_o_keep_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right12.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right13.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right14.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right15.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right16.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right17.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right18.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right19.png");

			if(--O_keep_count <= 0)
			{
				hero->stat = KEY_O_STOP;
				hero->pre_stat = KEY_O_KEEP;
				O_keep_count = ATHENA_O_KEEP_COUNT;
			}
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_o_keep_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left12.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left13.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left14.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left15.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left16.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left17.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left18.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left19.png");

			if(--O_keep_count <= 0)
			{
				hero->stat = KEY_O_STOP;
				hero->pre_stat = KEY_O_KEEP;
				O_keep_count = ATHENA_O_KEEP_COUNT;
			}
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_o_stop(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != KEY_O_STOP)
	{
		hero->stat = KEY_O_STOP;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_O_STOP_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_o_stop_left(member, hero);
		else
			load_athena_o_stop_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_o_stop_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right11.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right10.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right9.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right8.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right7.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right5.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right4.png");
			break;
		case 9:
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right20.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/right20.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_O_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_o_stop_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left11.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left10.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left9.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left8.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left7.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left5.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left4.png");
			break;
		case 9:
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left20.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/Key_O/left20.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = KEY_O_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_SJ(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_SJ)
	{
		hero->stat = ALT_SJ;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_SJ_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_SJ_left(member, hero);
		else
			load_athena_SJ_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SJ_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/right1.png");
			break;
		case 2:
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/right2.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/right3.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/right4.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/right5.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SJ;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SJ_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/left1.png");
			break;
		case 2:
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/left2.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/left3.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/left4.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SJ/left5.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SJ;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_SK(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_SK)
	{
		hero->stat = ALT_SK;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_SK_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_SK_left(member, hero);
		else
			load_athena_SK_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SK_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right5.png");
			break;
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/right8.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SK;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SK_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left5.png");
			break;
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SK/left8.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SK;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_SU(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_SU)
	{
		hero->stat = ALT_SU;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_SU_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_SU_left(member, hero);
		else
			load_athena_SU_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SU_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right5.png");
			break;
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right8.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/right9.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SU;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SU_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left5.png");
			break;
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left6.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left7.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left8.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SU/left9.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SU;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_SI(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_SI)
	{
		hero->stat = ALT_SI;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_SI_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_SI_left(member, hero);
		else
			load_athena_SI_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SI_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right4.png");
			break;
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right5.png");
			break;
		case 7:
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right6.png");
			break;
		case 9:
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right7.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right8.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right9.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right10.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/right11.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SI;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SI_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left4.png");
			break;
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left5.png");
			break;
		case 7:
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left6.png");
			break;
		case 9:
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left7.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left8.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left9.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left10.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SI/left11.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SI;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_SL(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_SL)
	{
		hero->stat = ALT_SL;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_SL_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_SL_left(member, hero);
		else
			load_athena_SL_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SL_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/right4.png");
			hero->stat = ALT_SL_STOP;
			hero->pre_stat = ALT_SL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SL_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/left4.png");
			hero->stat = ALT_SL_STOP;
			hero->pre_stat = ALT_SL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_SL_stop(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_SL_STOP)
	{
		hero->stat = ALT_SL_STOP;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_SL_STOP_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_SL_stop_left(member, hero);
		else
			load_athena_SL_stop_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SL_stop_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/right5.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/right6.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/right7.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SL_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_SL_stop_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/left5.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/left6.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_SL/left7.png");
			hero->stat = STAT_DOWN_KEEP;
			hero->pre_stat = ALT_SL_STOP;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_AS(struct Member *member, struct Hero *hero, long run_time)
{
	if( is_right(member, hero) )
		set_athena_ALT_SL(member, hero, run_time);
	else
		set_athena_down_keep(member, hero, run_time);
}

static void set_athena_ALT_DS(struct Member *member, struct Hero *hero, long run_time)
{
	if( is_right(member, hero) )
		set_athena_down_keep(member, hero, run_time);
	else
		set_athena_ALT_SL(member, hero, run_time);
}

static void set_athena_ALT_JK(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_JK)
	{
		hero->stat = ALT_JK;
		hero->stat_pic = 0;
	}

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_JK_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_JK_left(member, hero);
		else
			load_athena_JK_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_JK_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/right8.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_JK;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >= 3 && hero->stat_pic <= 6)
		athena_move_JK_right(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_JK_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_JK/left8.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_JK;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >= 3 && hero->stat_pic <= 6)
		athena_move_JK_left(member, hero);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_JK_right(struct Member *member, struct Hero *hero)
{
	if(hero->position.x + ATHENA_JK_SIZE <= 530)
	{
		hero->position.x += ATHENA_JK_SIZE;
		move_window(member, hero->hero_type, -WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void athena_move_JK_left(struct Member *member, struct Hero *hero)
{
	if(hero->position.x - ATHENA_JK_SIZE >= -380)
	{
		hero->position.x -= ATHENA_JK_SIZE;
		move_window(member, hero->hero_type, WINDOW_MOVE_SIZE, HORIZONTAL);
	}
}

static void set_athena_ALT_ADJ(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADJ)
	{
		hero->stat = ALT_ADJ;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADJ_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADJ_left(member, hero);
		else
			load_athena_ADJ_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADJ_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right2.png");
			break;
		case 3:
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right3.png");
			break;
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right4.png");
			break;
		case 7:
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right5.png");
			break;
		case 9:
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right6.png");
			break;
		case 11:
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right7.png");
			break;
		case 13:
		case 14:
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right8.png");
			break;
		case 16:
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right9.png");
			break;
		case 18:
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right10.png");
			break;
		case 20:
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right11.png");
			break;
		case 22:
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right12.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right13.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right14.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/right15.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADJ;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADJ_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left2.png");
			break;
		case 3:
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left3.png");
			break;
		case 5:
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left4.png");
			break;
		case 7:
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left5.png");
			break;
		case 9:
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left6.png");
			break;
		case 11:
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left7.png");
			break;
		case 13:
		case 14:
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left8.png");
			break;
		case 16:
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left9.png");
			break;
		case 18:
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left10.png");
			break;
		case 20:
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left11.png");
			break;
		case 22:
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left12.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left13.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left14.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADJ/left15.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADJ;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_ADL(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADL)
	{
		hero->stat = ALT_ADL;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADL_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADL_left(member, hero);
		else
			load_athena_ADL_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADL_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right11.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right12.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right13.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right14.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right15.png");
			break;
		case 16:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right16.png");
			break;
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right17.png");
			break;
		case 18:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/right18.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADL_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left5.png");
			break;
		case 6:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left6.png");
			break;
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left7.png");
			break;
		case 8:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left8.png");
			break;
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left9.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left10.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left11.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left12.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left13.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left14.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left15.png");
			break;
		case 16:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left16.png");
			break;
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left17.png");
			break;
		case 18:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADL/left18.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADL;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void set_athena_ALT_ADI(struct Member *member, struct Hero *hero, long run_time)
{
	if(hero->stat != ALT_ADI)
	{
		hero->stat = ALT_ADI;
		hero->stat_pic = 0;
	}

	if( is_right(member, hero) )
		hero->direction = KEY_D;
	else
		hero->direction = KEY_A;

	if(hero->stat_pic == 0 || run_time - hero->time >= ATHENA_ADI_TIME)
	{
		hero->time = run_time;
		hero->stat_pic++;
		SDL_FreeSurface(hero->image);

		if(hero->direction == KEY_A)
			load_athena_ADI_left(member, hero);
		else
			load_athena_ADI_right(member, hero);
	}

	if(enqueue(&member->queue, hero->image,
					&hero->position) == -1)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADI_right(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right5.png");
			break;
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right6.png");
			break;
		case 8:
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right7.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right8.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right9.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right10.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right11.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right12.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right13.png");
			break;
		case 16:
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right14.png");
			break;
		case 18:
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right15.png");
			break;
		case 20:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right16.png");
			break;
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right17.png");
			break;
		case 22:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right18.png");
			break;
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right19.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right20.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right21.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right22.png");
			break;
		case 27:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right23.png");
			break;
		case 28:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right24.png");
			break;
		case 29:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right25.png");
			break;
		case 30:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right26.png");
			break;
		case 31:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/right27.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADI;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >= 6 && hero->stat_pic <= 9)
			athena_move_ADI_up(member, hero, ATHENA_ADI_UP1_SIZE);
	if(hero->stat_pic >= 10 && hero->stat_pic <= 15)
			athena_move_ADI_up(member, hero, ATHENA_ADI_UP2_SIZE);
	if(hero->stat_pic >= 16 && hero->stat_pic <= 19)
			athena_move_ADI_down(member, hero, ATHENA_ADI_DOWN1_SIZE);
	if(hero->stat_pic >= 20 && hero->stat_pic <= 25)
			athena_move_ADI_down(member, hero, ATHENA_ADI_DOWN2_SIZE);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void load_athena_ADI_left(struct Member *member, struct Hero *hero)
{
	switch(hero->stat_pic)
	{
		case 1:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left1.png");
			break;
		case 2:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left2.png");
			break;
		case 3:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left3.png");
			break;
		case 4:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left4.png");
			break;
		case 5:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left5.png");
			break;
		case 6:
		case 7:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left6.png");
			break;
		case 8:
		case 9:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left7.png");
			break;
		case 10:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left8.png");
			break;
		case 11:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left9.png");
			break;
		case 12:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left10.png");
			break;
		case 13:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left11.png");
			break;
		case 14:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left12.png");
			break;
		case 15:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left13.png");
			break;
		case 16:
		case 17:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left14.png");
			break;
		case 18:
		case 19:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left15.png");
			break;
		case 20:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left16.png");
			break;
		case 21:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left17.png");
			break;
		case 22:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left18.png");
			break;
		case 23:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left19.png");
			break;
		case 24:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left20.png");
			break;
		case 25:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left21.png");
			break;
		case 26:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left22.png");
			break;
		case 27:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left23.png");
			break;
		case 28:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left24.png");
			break;
		case 29:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left25.png");
			break;
		case 30:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left26.png");
			break;
		case 31:
			hero->image = IMG_Load("../Image/Hero/Athena/ALT_ADI/left27.png");
			hero->stat = KEY_NULL;
			hero->pre_stat = ALT_ADI;
			hero->stat_pic = 0;
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}

	if(hero->stat_pic >= 6 && hero->stat_pic <= 9)
			athena_move_ADI_up(member, hero, ATHENA_ADI_UP1_SIZE);
	if(hero->stat_pic >= 10 && hero->stat_pic <= 15)
			athena_move_ADI_up(member, hero, ATHENA_ADI_UP2_SIZE);
	if(hero->stat_pic >= 16 && hero->stat_pic <= 19)
			athena_move_ADI_down(member, hero, ATHENA_ADI_DOWN1_SIZE);
	if(hero->stat_pic >= 20 && hero->stat_pic <= 25)
			athena_move_ADI_down(member, hero, ATHENA_ADI_DOWN2_SIZE);

	if(hero->image == NULL)
		fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
}

static void athena_move_ADI_up(struct Member *member, struct Hero *hero, int size)
{
	hero->position.y -= size;
	move_window(member, hero->hero_type, WINDOW_ADI_UP_SIZE, VERTICAL);
}

static void athena_move_ADI_down(struct Member *member, struct Hero *hero, int size)
{
	hero->position.y += size;
	move_window(member, hero->hero_type, -WINDOW_ADI_DOWN_SIZE, VERTICAL);
}
