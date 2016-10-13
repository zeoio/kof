#ifndef _INIT_H
#define _INIT_H

#define HERO_PLAYER		0
#define HERO_ROBOT		1

#define ANDY_TIME 			150
#define ATHENA_TIME 			100
#define BENIMARU_TIME 			130
#define BILLY_TIME 			160
#define CHIN_TIME 			200
#define DAIMON_TIME			230
#define IORI_TIME			145
#define JOE_TIME			140
#define KING_TIME			140
#define KIM_TIME			180
#define KULA_TIME			120
#define KYO_TIME			130
#define MAI_TIME			150
#define LEONA_TIME			140
#define MATURE_TIME			140
#define ROBERT_TIME			130
#define RYO_TIME			150
#define CLARK_TIME			170
#define TERRY_TIME			150
#define RALF_TIME			180
#define VICE_TIME			160
#define TAKUMA_TIME			270
#define MAXIMA_TIME			170
#define YURI_TIME			130

/* Init position of hero */
#define ATHENA_PLAYER_POSITION_X	-250
#define ATHENA_PLAYER_POSITION_Y	60

void begin_sdl(void);
void end_sdl(void);
void init(struct Member *);
void init_live(int *);
void init_time(struct Time *);
void init_win(struct Window *);
void load_hero(struct Window *);
void set_hero(struct Window *);
void choice_hero(struct Member *);
static void init_player(struct Hero *);
void init_start(struct Member *);
static init_hero(struct Hero *);
static init_robot(struct Hero *);
int get_rand_player(struct Member *);
int get_choice(int, int *);
int show_hero(struct Member *, long);
void show_player(struct Member *, long);
void show_andy(struct Member *, long);
void show_athena(struct Member *, long);
void show_benimaru(struct Member *, long);
void show_billy(struct Member *, long);
void show_chin(struct Member *, long);
void show_daimon(struct Member *, long);
void show_iori(struct Member *, long);
void show_joe(struct Member *, long);
void show_king(struct Member *, long);
void show_kim(struct Member *, long);
void show_kula(struct Member *, long);
void show_kyo(struct Member *, long);
void show_mai(struct Member *, long);
void show_leona(struct Member *, long);
void show_mature(struct Member *, long);
void show_robert(struct Member *, long);
void show_ryo(struct Member *, long);
void show_clark(struct Member *, long);
void show_terry(struct Member *, long);
void show_ralf(struct Member *, long);
void show_vice(struct Member *, long);
void show_takuma(struct Member *, long);
void show_yuri(struct Member *, long);
void show_maxima(struct Member *, long);
void show_time(struct Member *, long, int);
void free_choice_window(struct Member *);
void set_window(struct Member *);
static void init_hero_position(struct Hero *);
static void init_robot_position(struct Hero *);
unsigned long get_time(const struct timeval *, const struct timeval *);
static void reset_time(struct Time *);

#endif
