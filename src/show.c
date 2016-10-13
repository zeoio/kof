#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "define.h"
#include "show.h"

void init_show(struct Queue *queue)
{
	queue->head = queue->tail = 0;
}

int enqueue(struct Queue *queue, SDL_Surface *image, SDL_Rect *position)
{
	if( is_full(queue) )
		return -1;
	
	queue->image[queue->tail] = image;
	queue->position[queue->tail] = *position;
	queue->tail = (queue->tail+1) % QUEUE_MAX;

	return 0;
}

int is_full(struct Queue *queue)
{
	return (queue->tail+1) % QUEUE_MAX == queue->head;
}

int dequeue(struct Queue *queue, SDL_Surface **image, SDL_Rect *position)
{
	if( is_empty(queue) )
		return -1;
	
	*image = queue->image[queue->head];
	*position = queue->position[queue->head];
	queue->head = (queue->head+1) % QUEUE_MAX;

	return 0;
}

int is_empty(struct Queue *queue)
{
	return queue->head == queue->tail;
}

void show(struct Window *win, struct Queue *queue) 
{
	SDL_Surface *image = NULL;
	SDL_Rect dest = win->positionBg;

	SDL_BlitSurface(win->mainBg, NULL, win->mainWindow, &dest);

	while( !dequeue(queue, &image, &dest) )
	{
		SDL_BlitSurface(image, NULL, win->mainWindow, 
					&dest);
		//血条 ? 
	}

	SDL_Flip(win->mainWindow);
}
