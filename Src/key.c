#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "define.h"
#include "key.h"

void init_key(struct Key *key)
{
	key->key = 0;
	key->time = 0;
}

int get_key(struct Key *key, long run_time)
{
	int enter_key = check_key();

	if(enter_key != KEY_NULL)
		set_key(key, enter_key);

	return check_alt(key, run_time);
}

int check_key(void)
{
	SDL_Event myEvent;
		
	if( SDL_PollEvent(&myEvent) )    
	{
		switch(myEvent.type)
        	{
        		case SDL_QUIT:
				exit(0);
			case SDL_KEYDOWN:
	            		switch(myEvent.key.keysym.sym)
	            		{
					case SDLK_w:
					case SDLK_UP:
						return KEY_W;
	                		case SDLK_s:
					case SDLK_DOWN:
						return KEY_S;
	                		case SDLK_a:
					case SDLK_LEFT:
	                    			return KEY_A; 
		            		case SDLK_d:
					case SDLK_RIGHT:
	                    			return KEY_D; 
					case SDLK_j:	
						return KEY_J;
					case SDLK_k:
						return KEY_K;
					case SDLK_l:
						return KEY_L;
					case SDLK_u:
						return KEY_U;	
					case SDLK_i:
						return KEY_I;
					case SDLK_o:
						return KEY_O;
					default:		
						return KEY_NULL;
				}
		        	break;
            		case SDL_KEYUP:
	            		switch(myEvent.key.keysym.sym)
	            		{
					case SDLK_w:
					case SDLK_UP:
						return KEYUP_W;
	                		case SDLK_s:
					case SDLK_DOWN:
						return KEYUP_S;
	                		case SDLK_a:
					case SDLK_LEFT:
	                    			return KEYUP_A; 
		            		case SDLK_d:
					case SDLK_RIGHT:
	                    			return KEYUP_D; 
					case SDLK_j:	
						return KEYUP_J;
					case SDLK_k:
						return KEYUP_K;
					case SDLK_l:
						return KEYUP_L;
					case SDLK_u:
						return KEYUP_U;	
					case SDLK_i:
						return KEYUP_I;
					case SDLK_o:
						return KEYUP_O;
					default:		
						return KEY_NULL;
				}
		        	break;
			defaut:
				return KEY_NULL;
		}
	}

	return KEY_NULL;
}

static void set_key(struct Key *key, int enter_key)
{	
	if(enter_key <= 10)
		key_set(key, enter_key);
	else	
		key_reset(key, enter_key);
}

static void key_set(struct Key *key, int enter_key)
{
	switch(enter_key)
	{
		case KEY_W:
			SET_W(key);
			break;
		case KEY_S:
			SET_S(key);
			break;	
		case KEY_A:
			SET_A(key);
			break;
		case KEY_D:
			SET_D(key);
			break;
		case KEY_J:
			SET_J(key);
			break;	
		case KEY_K:
			SET_K(key);
			break;	
		case KEY_L:
			SET_L(key);
			break;
		case KEY_U:
			SET_U(key);
			break;
		case KEY_I:
			SET_I(key);
			break;	
		case KEY_O:
			SET_O(key);
			break;
		default:	
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
		}
}
	
static void key_reset(struct Key *key, int enter_key)
{
	switch(enter_key)
	{
		case KEYUP_W:
			RESET_W(key);
			break;	
		case KEYUP_S:
			RESET_S(key);
			break;
		case KEYUP_A:	
			RESET_A(key);
			break;
		case KEYUP_D:
			RESET_D(key);
			break;
		case KEYUP_J:
			RESET_J(key);
			break;	
		case KEYUP_K:
			RESET_K(key);
			break;
		case KEYUP_L:	
			RESET_L(key);
			break;
		case KEYUP_U:
			RESET_U(key);
			break;	
		case KEYUP_I:
			RESET_I(key);
			break;
		case KEYUP_O:
			RESET_O(key);
			break;
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
		}
}

static int check_alt(struct Key *key, long run_time)
{
	if(key->key == ALT_VALUE_NULL)
		return KEY_NULL;
	else if((key->key & ALT_VALUE_WA) == ALT_VALUE_WA)
	{
		key->time = run_time;
		return ALT_WA;
	}
	else if((key->key & ALT_VALUE_WD) == ALT_VALUE_WD)
	{
		key->time = run_time;
		return ALT_WD;
	}
	else if((key->key & ALT_VALUE_AS) == ALT_VALUE_AS)
	{
		key->time = run_time;
		return ALT_AS;
	}
	else if((key->key & ALT_VALUE_DS) == ALT_VALUE_DS)
	{
		key->time = run_time;
		return ALT_DS;
	}
	else if((key->key & ALT_VALUE_WJ) == ALT_VALUE_WJ)
	{
		key->time = run_time;
		return ALT_WJ;
	}
	else if((key->key & ALT_VALUE_WU) == ALT_VALUE_WU)
	{
		key->time = run_time;	
		return ALT_WU;
	}
	else if((key->key & ALT_VALUE_WK) == ALT_VALUE_WK)
	{
		key->time = run_time;
		return ALT_WK;
	}
	else if((key->key & ALT_VALUE_WI) == ALT_VALUE_WI)
	{
		key->time = run_time;
		return ALT_WK;
	}
	else if((key->key & ALT_VALUE_AJ) == ALT_VALUE_AJ)
	{
		key->time = run_time;
		return ALT_ADJ;
	}
	else if((key->key & ALT_VALUE_DJ) == ALT_VALUE_DJ)
	{
		key->time = run_time;
		return ALT_ADJ;
	}
	else if((key->key & ALT_VALUE_AK) == ALT_VALUE_AK)
	{
		key->time = run_time;
		return ALT_ADK;
	}
	else if((key->key & ALT_VALUE_DK) == ALT_VALUE_DK)
	{
		key->time = run_time;
		return ALT_ADK;
	}
	else if((key->key & ALT_VALUE_SJ) == ALT_VALUE_SJ)
	{
		key->time = run_time;
		return ALT_SJ;
	}
	else if((key->key & ALT_VALUE_SU) == ALT_VALUE_SU)
	{
		key->time = run_time;
		return ALT_SU;
	}
	else if((key->key & ALT_VALUE_SK) == ALT_VALUE_SK)	
	{
		key->time = run_time;
		return ALT_SK;
	}
	else if((key->key & ALT_VALUE_SI) == ALT_VALUE_SI)
	{
		key->time = run_time;
		return ALT_SI;
	}
	else if((key->key & ALT_VALUE_JK) == ALT_VALUE_JK)
	{
		key->time = run_time;	
		return ALT_JK;
	}
	else if((key->key & ALT_VALUE_SL) == ALT_VALUE_SL)
	{
		key->time = run_time;
		return ALT_SL;
	}
	else if((key->key & ALT_VALUE_AU) == ALT_VALUE_AU)
	{
		key->time = run_time;
		return ALT_ADU;
	}
	else if((key->key & ALT_VALUE_DU) == ALT_VALUE_DU)
	{
		key->time = run_time;
		return ALT_ADU;
	}
	else if((key->key & ALT_VALUE_AO) == ALT_VALUE_AO)
	{
		key->time = run_time;	
		return ALT_ADO;
	}
	else if((key->key & ALT_VALUE_DO) == ALT_VALUE_DO)
	{
		key->time = run_time;	
		return ALT_ADO;
	}
	else if((key->key & ALT_VALUE_AI) == ALT_VALUE_AI)
	{
		key->time = run_time;
		return ALT_ADI;
	}
	else if((key->key & ALT_VALUE_DI) == ALT_VALUE_DI)
	{
		key->time = run_time;
		return ALT_ADI;
	}
	else if((key->key & ALT_VALUE_AL) == ALT_VALUE_AL)
	{
		key->time = run_time;	
		return ALT_ADL;
	}
	else if((key->key & ALT_VALUE_DL) == ALT_VALUE_DL)
	{
		key->time = run_time;	
		return ALT_ADL;
	}
	else
		return is_single(key, key->time);
}

static int is_single(struct Key *key, long run_time)
{
	key->time = run_time;

	switch(key->key)
	{
		case ALT_VALUE_NULL:
			return KEY_NULL;
		case KEY_VALUE_W:
			return KEY_W;
		case KEY_VALUE_S:
			return KEY_S;
		case KEY_VALUE_A:
			return KEY_A;
		case KEY_VALUE_D:
			return KEY_D;
		case KEY_VALUE_J:
			return KEY_J;
		case KEY_VALUE_K:
			return KEY_K;
		case KEY_VALUE_L:
			return KEY_L;
		case KEY_VALUE_U:
			return KEY_U;
		case KEY_VALUE_I:
			return KEY_I;
		case KEY_VALUE_O:	
			return KEY_O;
		default:
			return KEY_NULL;
	}
}

void update_key(struct Hero *hero, int *enter_key)
{
	if(hero->stat != KEY_NULL)
		lock_stat_key(hero->stat, enter_key);
	else
		unlock_stat_key(hero->pre_stat, enter_key, hero->direction);
}

static void lock_stat_key(int stat, int *enter_key)
{
	if(!is_exist(*enter_key, KEY_S) && (is_exist(stat, KEY_S) && !is_ALT_SX(stat)))	/* 输入中不包含Key_S, stat中包含Key_S,并且排斥SX */
		*enter_key = STAT_DOWN_UP;
	else if(!is_exist(*enter_key, KEY_L) && is_exist(stat, KEY_L))
		*enter_key = STAT_L_STOP;		
	else if(stat == STAT_DOWN_KEEP && *enter_key != KEY_S)
		;
	else if((stat == KEY_S || stat == STAT_DOWN_KEEP) && is_ALT_SX(*enter_key))
		;
	else if((stat == KEY_A || stat == KEY_D) && is_ignore(*enter_key))
		;
	else if(stat == ALT_SL_STOP && *enter_key == ALT_SL)
		*enter_key = ALT_SL;
	else if(stat == ALT_SL_STOP && *enter_key == ALT_AS)
		*enter_key = ALT_AS;
	else if(stat == ALT_SL_STOP && *enter_key == ALT_DS)
		*enter_key = ALT_DS;
	else if((stat == KEY_J || stat == KEY_K) && *enter_key == ALT_JK)
		;
	else
		*enter_key = stat;
}

static int is_ignore(int enter_key)
{
	switch(enter_key)
	{
		case ALT_ADJ:	
		case ALT_ADK:
		case ALT_ADU:
		case ALT_ADO:
		case ALT_ADL:
		case ALT_ADI:
			return 1;
		default:
			return 0;
	}
}

static void unlock_stat_key(int pre_stat, int *enter_key, int direction)
{
	if(pre_stat == KEY_S)
	{
		if(*enter_key == KEY_NULL)
			*enter_key = STAT_DOWN_UP;
		else if(*enter_key == KEY_S)
			*enter_key = STAT_DOWN_KEEP;
	}
	
	if(pre_stat == KEY_D || pre_stat == KEY_A)
	{
		if(*enter_key == pre_stat && *enter_key == direction)
			*enter_key = STAT_RUN;
	}
	
	if(pre_stat == STAT_RUN)
	{
		if(*enter_key == direction)
			*enter_key = STAT_RUN;
		else	
			*enter_key = STAT_RUN_STOP;		
	}
		
	if(pre_stat == KEY_L)
	{
		if(*enter_key == KEY_NULL)
			*enter_key = STAT_L_STOP;
		else if(*enter_key == KEY_L)
			*enter_key = STAT_L_HOLD;
	}
}

static int is_exist(int key, int test_key)
{
	switch(test_key)
	{
		case KEY_S:
			return is_key_s(key);
		case KEY_L:
			return is_key_l(key);
		default:
			fprintf(stderr, "%s\t%d\n", __FILE__, __LINE__);
	}
}

static int is_key_s(int key)
{
	switch(key)
	{
		case KEY_S:
		case ALT_AS:
		case ALT_DS:
		case ALT_SL:
		case ALT_SJ:
		case ALT_SK:
		case ALT_SU:
		case ALT_SI:
		case STAT_DOWN_KEEP:
		//case ALT_SL_STOP:
			return 1;
		default:
			return 0;
	}
}

static int is_key_l(int key)
{
	switch(key)
	{
		case KEY_L:
//		case ALT_ADL:
		case STAT_L_HOLD:
			return 1;
		default:
			return 0;
	}
}

static int is_ALT_SX(int enter_key)
{
	switch(enter_key)
	{
		case ALT_AS:
		case ALT_DS:
		case ALT_SJ:		
		case ALT_SK:
		case ALT_SU:
		case ALT_SI:
		case ALT_SL:
		case ALT_SL_STOP:
			return 1;
		default:
			return 0;
	}
}
