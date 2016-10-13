#include <SDL/SDL.h>
#include <sys/time.h>
#include "define.h"
#include "init.h"
#include "key.h"
#include "show.h"
#include "kernel.h"

int main(void)
{
	begin_sdl();

	struct Member member;	
	init(&member);

	struct timeval old_time, new_time;
	unsigned long run_time = 0;	

	gettimeofday(&old_time, NULL);
	new_time.tv_sec = old_time.tv_sec;
	new_time.tv_usec = old_time.tv_usec;

	int enter_key;
	struct Key key;
	init_key(&key);

	while(1)
	{ 		
		enter_key = get_key(&key, run_time);
		run_game(&member, enter_key, run_time);

		show(&member.window, &member.queue);
	
		SDL_Delay(TIME_BASE);	
		gettimeofday(&new_time, NULL);
		run_time = get_time(&old_time, &new_time);
	}

	end_sdl();
	return 0;
}
