#ifndef _PUBLIC_H
#define _PUBLIC_H

#define HORIZONTAL		0
#define VERTICAL		1
#define WINDOW_MOVE_SIZE	6

void move_window(struct Member *, int, int, int);
static int is_move_window(struct Member *, int, int);
static void hold_other(struct Hero *, int, int);
int is_right(struct Member *, struct Hero *);

#endif
