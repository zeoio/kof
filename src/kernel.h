#ifndef _KERNEL_H
#define _KERNEL_H

#include "athena.h"

#define BG_TIME		50

void run_game(struct Member *, int, long);
void load_go(struct Queue *, int);
void set_bg(struct Member *, long);
static void run_hero(struct Member *, struct Hero *, int, long);

#endif
