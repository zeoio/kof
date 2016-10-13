#ifndef _KEY_H
#define _KEY_H

#define KEY_TIME		100	/* 组合键有效时间 */

/* Key bounce */
#define KEYUP_W			11
#define KEYUP_S			12
#define KEYUP_A			13
#define KEYUP_D			14
#define KEYUP_J			15
#define KEYUP_K			16
#define KEYUP_L			17
#define KEYUP_U			18	
#define KEYUP_I			19
#define KEYUP_O			20

/* Vaule of key */
#define KEY_VALUE_W		0x0002
#define KEY_VALUE_S		0x0004
#define KEY_VALUE_A		0x0008
#define KEY_VALUE_D		0x0010
#define KEY_VALUE_J		0x0020
#define KEY_VALUE_K		0x0040
#define KEY_VALUE_L		0x0080
#define KEY_VALUE_U		0x0100
#define KEY_VALUE_I		0x0200
#define KEY_VALUE_O		0x0400

/* Set bit */
#define SET_W(key)		(key->key |= KEY_VALUE_W)
#define SET_S(key)		(key->key |= KEY_VALUE_S)
#define SET_A(key)		(key->key |= KEY_VALUE_A)
#define SET_D(key)		(key->key |= KEY_VALUE_D)
#define SET_J(key)		(key->key |= KEY_VALUE_J)
#define SET_K(key)		(key->key |= KEY_VALUE_K)
#define SET_L(key)		(key->key |= KEY_VALUE_L)
#define SET_U(key)		(key->key |= KEY_VALUE_U)
#define SET_I(key)		(key->key |= KEY_VALUE_I)
#define SET_O(key)		(key->key |= KEY_VALUE_O)

/* Value of ALT */
#define ALT_VALUE_NULL		0
#define ALT_VALUE_WA		(KEY_VALUE_W | KEY_VALUE_A)
#define ALT_VALUE_WD		(KEY_VALUE_W | KEY_VALUE_D)
#define ALT_VALUE_AS		(KEY_VALUE_A | KEY_VALUE_S)
#define ALT_VALUE_DS		(KEY_VALUE_D | KEY_VALUE_S)
#define ALT_VALUE_WJ		(KEY_VALUE_W | KEY_VALUE_J)
#define ALT_VALUE_WK		(KEY_VALUE_W | KEY_VALUE_K)
#define ALT_VALUE_WU		(KEY_VALUE_W | KEY_VALUE_U)
#define ALT_VALUE_WI		(KEY_VALUE_W | KEY_VALUE_I)
#define ALT_VALUE_AJ		(KEY_VALUE_A | KEY_VALUE_J)
#define ALT_VALUE_DJ		(KEY_VALUE_D | KEY_VALUE_J)
#define ALT_VALUE_AK		(KEY_VALUE_A | KEY_VALUE_K)
#define ALT_VALUE_DK		(KEY_VALUE_D | KEY_VALUE_K)
#define ALT_VALUE_SJ		(KEY_VALUE_S | KEY_VALUE_J)
#define ALT_VALUE_SK		(KEY_VALUE_S | KEY_VALUE_K)
#define ALT_VALUE_SU		(KEY_VALUE_S | KEY_VALUE_U)
#define ALT_VALUE_SI		(KEY_VALUE_S | KEY_VALUE_I)
#define ALT_VALUE_JK		(KEY_VALUE_J | KEY_VALUE_K)
#define ALT_VALUE_SL		(KEY_VALUE_S | KEY_VALUE_L)
#define ALT_VALUE_AU		(KEY_VALUE_A | KEY_VALUE_U)
#define ALT_VALUE_DU		(KEY_VALUE_D | KEY_VALUE_U)
#define ALT_VALUE_AO		(KEY_VALUE_A | KEY_VALUE_O)
#define ALT_VALUE_DO		(KEY_VALUE_D | KEY_VALUE_O)
#define ALT_VALUE_AI		(KEY_VALUE_A | KEY_VALUE_I)
#define ALT_VALUE_DI		(KEY_VALUE_D | KEY_VALUE_I)
#define ALT_VALUE_AL		(KEY_VALUE_A | KEY_VALUE_L)
#define ALT_VALUE_DL		(KEY_VALUE_D | KEY_VALUE_L)

/* Reset bit */
#define RESET_W(key)		(key->key &= 0xfffd)
#define RESET_S(key)		(key->key &= 0xfffb)
#define RESET_A(key)		(key->key &= 0xfff7)
#define RESET_D(key)		(key->key &= 0xffef)
#define RESET_J(key)		(key->key &= 0xffdf)
#define RESET_K(key)		(key->key &= 0xffbf)
#define RESET_L(key)		(key->key &= 0xff7f)
#define RESET_U(key)		(key->key &= 0xfeff)
#define RESET_I(key)		(key->key &= 0xfdff)
#define RESET_O(key)		(key->key &= 0xfbff)
	
struct Key
{	
	unsigned short key; 	/* 1-10位分别代表10个键 */
	long time;
};

void init_key(struct Key *key);
int get_key(struct Key *, long);
int check_key(void);
static void set_key(struct Key *, int);
static void key_set(struct Key *, int);
static void key_reset(struct Key *, int);
static int check_alt(struct Key *, long);
static int is_single(struct Key *, long);
void update_key(struct Hero *, int *);
static void lock_stat_key(int, int *);
static int is_ignore(int);
static void unlock_stat_key(int, int *, int);
static int is_exist(int, int);
static int is_key_s(int);
static int is_key_l(int);
static int is_ALT_SX(int);

#endif
