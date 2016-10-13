#ifndef _SHOW_H
#define _SHOW_H

void init_show(struct Queue *);
int enqueue(struct Queue *, SDL_Surface *, SDL_Rect *);
int is_full(struct Queue *);
int dequeue(struct Queue *, SDL_Surface **, SDL_Rect *);
int is_empty(struct Queue *);
void load_go(struct Queue *, int);
extern void show(struct Window *, struct Queue *);

#endif
