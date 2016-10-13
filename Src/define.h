#ifndef _DEFINE_H
#define _DEFINE_H

#define TIME_BASE 		10
#define MILLI_TO_SEC(time) (time / 1000)

/* Key pressed */
#define KEY_NULL 		0
#define KEY_W 			1
#define KEY_S			2
#define KEY_A	 		3
#define KEY_D	 		4
#define KEY_J 			5
#define KEY_K			6
#define KEY_L			7
#define KEY_U			8
#define KEY_I			9
#define KEY_O			10

/* Key combination */
#define ALT_WA			30
#define ALT_WD			31
#define ALT_AS			32
#define ALT_DS			33
#define ALT_WJ			34
#define ALT_WK			35
#define ALT_WU			36		
#define ALT_SJ			37
#define ALT_SK			38
#define ALT_SU			39		
#define ALT_SI			40		
#define ALT_SL			41
#define ALT_JK			42
#define ALT_ADJ			43
#define ALT_ADK			44
#define ALT_ADI			45		
#define ALT_ADU			46
#define ALT_ADO			47
#define ALT_ADL			48		

/* State of hero */
#define STAT_DOWN_UP		50
#define STAT_DOWN_KEEP		51
#define STAT_RUN		52
#define STAT_RUN_STOP		53
#define STAT_UP_DOWN		54
#define STAT_L_HOLD		55
#define STAT_L_STOP		56
#define KEY_O_KEEP		57	//?
#define KEY_O_STOP		58
#define ALT_ADO_UP		59
#define ALT_ADO_HOLD		60
#define ALT_ADO_DOWN		61
#define ALT_SL_STOP		62

/* mainBg */
#define BG_MAX			8
#define BG_WIDTH_MAX		0
#define BG_WIDTH_MIN		-256
#define BG_HEIGHT		586	

/* Hero */
#define HERO_ROW 		4
#define HERO_COLUMN 		6

#define HERO_MAX 		24
#define HERO_ANDY 		0
#define HERO_ATHENA	 	1
#define HERO_BENIMARU 		2
#define HERO_BILLY		3
#define HERO_CHIN		4
#define HERO_DAIMON		5	
#define HERO_IORI		6
#define HERO_JOE		7
#define HERO_KING		8
#define HERO_KIM		9
#define HERO_KULA		10
#define HERO_KYO		11
#define HERO_MAI		12
#define HERO_LEONA		13
#define HERO_MATURE		14
#define HERO_ROBERT		15
#define HERO_RYO		16
#define HERO_CLARK		17
#define HERO_TERRY		18
#define HERO_RALF		19
#define HERO_VICE		20
#define HERO_TAKUMA		21
#define HERO_MAXIMA		22 
#define HERO_YURI		23

struct Window
{
	int stat_pic;			
	long time;
	SDL_Surface *mainWindow;
	SDL_Surface *mainBg; 
	SDL_Surface *image[BG_MAX];
	SDL_Surface *hero[HERO_MAX];
	SDL_Rect position[HERO_MAX];
	SDL_Rect positionBg;
};

#define QUEUE_MAX 1024

struct Queue
{
	int head;
	int tail;
	SDL_Surface *image[QUEUE_MAX];	
	SDL_Rect position[QUEUE_MAX];
};

struct Block
{
	SDL_Rect position0;
	SDL_Rect position1;
	SDL_Rect position2;
	SDL_Rect position3;
};

/* 受创判定框 */
struct Hit_block
{
	struct Block hit_head;			//头部
	struct Block hit_chest;			//胸部
	struct Block hit_abdomen;		//腹部
	struct Block hit_foot;			//脚部
};

/* 攻击判定框 */
struct Attack_block
{
	struct Block attack_hand;		//手部
	struct Block attack_leg;		//腿部
	//...
};

struct Hero
{
	unsigned short hero_type;		//player or robot
	int hero;
	int blood_volume;
	int stat;				//现在的状态
	int pre_stat;				//上一次改动的状态
	int direction;				//方向
	long time;				//加载上一次的时间
	int stat_pic;				//那张图片
	SDL_Rect position;			//坐标
	SDL_Surface *image;
	SDL_Rect FX_position;			//开枪的特效，相对于机器人
	SDL_Surface *FX_image;		
	
	struct Hit_block hit_block;
	struct Attack_block attack_block;
};

struct Bullet
{
	SDL_Rect position;			//坐标
	SDL_Surface *image;
	int type;
	int damage;				//伤害值
	int speed;				
	int move_time;
	long time;				//上次改变的时间
	int direction;				//方向
	struct Bullet *pre;
	struct Bullet *next;
};

struct Bullet_list
{	
	int cnt;			//次数
	struct Bullet *head;
	struct Bullet *last;
};

#define MAX_CHOICE_TIME		30
#define MAX_RUN_TIME		60

struct Time
{
	SDL_Rect position1;
	SDL_Rect position2;
	SDL_Surface *image1;
	SDL_Surface *image2;
};

struct Member
{
	int live[HERO_MAX];
	struct Window window; 
	struct Hero player;
	struct Hero robot;
	struct Bullet_list bull;	//子弹链表头指针
	struct Queue queue;
	struct Time time;
};

#endif
