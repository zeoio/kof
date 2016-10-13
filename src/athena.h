#ifndef	_ATHENA_H	
#define _ATHENA_H

#define ATHENA_DEFT_TIME		90
#define ATHENA_DOWN_TIME		10
#define ATHENA_DOWN_KEEP_TIME		90
#define ATHENA_WALK_TIME		10
#define ATHENA_RUN_TIME			10
#define ATHENA_RUN_STOP_TIME		40
#define ATHENA_JUMP_UP_TIME		40
#define ATHENA_JUMP_DOWN_TIME		40
#define ATHENA_J_TIME			30 
#define ATHENA_K_TIME			30 
#define ATHENA_L_TIME			40 
#define ATHENA_L_HOLD_TIME		100 
#define ATHENA_I_TIME			30 
#define ATHENA_U_TIME			40 
#define ATHENA_O_TIME			50 
#define ATHENA_O_KEEP_TIME		60
#define ATHENA_O_STOP_TIME		70
#define ATHENA_ADK_TIME			40
#define ATHENA_ADU_TIME			40
#define ATHENA_ADO_TIME			50
#define ATHENA_ADO_UP_TIME		40
#define ATHENA_ADO_HOLD_TIME		120
#define ATHENA_ADO_DOWN_TIME		40
#define ATHENA_SJ_TIME			50
#define ATHENA_SK_TIME			40
#define ATHENA_SU_TIME			45
#define ATHENA_SI_TIME			40
#define ATHENA_SL_TIME			50
#define ATHENA_SL_STOP_TIME		30
#define ATHENA_JK_TIME			40
#define ATHENA_ADJ_TIME			40
#define ATHENA_ADL_TIME			50
#define ATHENA_ADI_TIME			45

#define ATHENA_FORWARD_SIZE		20 	/* 20px */
#define ATHENA_BACKWARD_SIZE		16 	/* 16px */
#define ATHENA_RUN_SIZE			30
#define ATHENA_JUMP_UP_SIZE		45 	/* 45*5 */
#define ATHENA_JUMP_DOWN_SIZE		75 	/* 75*3 */
#define ATHENA_ADO_UP_SIZE		6
#define ATHENA_ADO_DOWN_SIZE		10
#define ATHENA_JK_SIZE			60
#define ATHENA_ADI_UP1_SIZE		30
#define ATHENA_ADI_UP2_SIZE		10
#define ATHENA_ADI_DOWN1_SIZE		30
#define ATHENA_ADI_DOWN2_SIZE		10

/* */
#define ATHENA_O_KEEP_COUNT		7
#define ATHENA_ADO_HOLD_COUNT		7

/* window move size of jump*/
#define WINDOW_JUMP_UP_SIZE		6
#define WINDOW_JUMP_DOWN_SIZE		10	
#define WINDOW_ADI_UP_SIZE		3
#define WINDOW_ADI_DOWN_SIZE		3

void run_athena(struct Member *, struct Hero *, int, long);
static void set_athena_deft(struct Member *, struct Hero *, long);
static void load_athena_deft_left(struct Hero *);
static void load_athena_deft_right(struct Hero *);
static void set_athena_down(struct Member *, struct Hero *, long);
static void load_athena_down_left(struct Hero *);
static void load_athena_down_right(struct Hero *);
static void set_athena_down_up(struct Member *, struct Hero *, long);
static void load_athena_down_up_left(struct Hero *);
static void load_athena_down_up_right(struct Hero *);
static void set_athena_down_keep(struct Member *, struct Hero *, long);
static void load_athena_down_keep_right(struct Hero *);
static void load_athena_down_keep_left(struct Hero *);
static void set_athena_right(struct Member *, struct Hero *, long);
static void load_athena_right_forward(struct Member *, struct Hero *);
static void load_athena_right_backward(struct Member *, struct Hero *);
static void set_athena_left(struct Member *, struct Hero *, long);
static void load_athena_left_forward(struct Member *, struct Hero *);
static void load_athena_left_backward(struct Member *, struct Hero *);
static void athena_move_left_forward(struct Member *, struct Hero *);
static void athena_move_left_backward(struct Member *, struct Hero *);
static void athena_move_right_forward(struct Member *, struct Hero *);
static void athena_move_right_backward(struct Member *, struct Hero *);
static void set_athena_run(struct Member *, struct Hero *, long);
static void load_athena_run_right(struct Member *, struct Hero *);
static void athena_move_run_right(struct Member *, struct Hero *);
static void load_athena_run_left(struct Member *, struct Hero *);
static void athena_move_run_left(struct Member *, struct Hero *);
static void set_athena_run_stop(struct Member *, struct Hero *, long);
static void set_athena_up(struct Member *, struct Hero *, long);
static void load_athena_jump_left(struct Member *, struct Hero *);
static void load_athena_jump_right(struct Member *, struct Hero *);
static void athena_move_jump_up(struct Member *, struct Hero *);
static void set_athena_up_down(struct Member *, struct Hero *, long);
static void load_athena_jump_down_left(struct Member *, struct Hero *);
static void load_athena_jump_down_right(struct Member *, struct Hero *);
static void athena_move_jump_down(struct Member *, struct Hero *);
static void set_athena_j(struct Member *, struct Hero *, long);
static void load_athena_j_right(struct Member *, struct Hero *);
static void load_athena_j_left(struct Member *, struct Hero *);
static void set_athena_k(struct Member *, struct Hero *, long);
static void load_athena_k_right(struct Member *, struct Hero *);
static void load_athena_k_left(struct Member *, struct Hero *);
static void set_athena_l(struct Member *, struct Hero *, long);
static void load_athena_l_right(struct Member *, struct Hero *);
static void load_athena_l_left(struct Member *, struct Hero *);
static void set_athena_l_hold(struct Member *, struct Hero *, long);
static void load_athena_l_hold_right(struct Member *, struct Hero *);
static void load_athena_l_hold_left(struct Member *, struct Hero *);
static void set_athena_l_stop(struct Member *, struct Hero *, long);
static void load_athena_l_stop_right(struct Member *, struct Hero *);
static void load_athena_l_stop_left(struct Member *, struct Hero *);
static void set_athena_i(struct Member *, struct Hero *, long);
static void load_athena_i_right(struct Member *, struct Hero *);
static void load_athena_i_left(struct Member *, struct Hero *);
static void set_athena_run_stop(struct Member *, struct Hero *, long);
static void load_athena_run_stop_right(struct Member *, struct Hero *);
static void load_athena_run_stop_left(struct Member *, struct Hero *);
static void set_athena_u(struct Member *, struct Hero *, long);
static void load_athena_u_right(struct Member *, struct Hero *);
static void load_athena_u_left(struct Member *, struct Hero *);
static void set_athena_o(struct Member *, struct Hero *, long);
static void load_athena_o_right(struct Member *, struct Hero *);
static void load_athena_o_left(struct Member *, struct Hero *);
static void set_athena_o_keep(struct Member *, struct Hero *, long);
static void load_athena_o_keep_right(struct Member *, struct Hero *);
static void load_athena_o_keep_left(struct Member *, struct Hero *);
static void set_athena_o_stop(struct Member *, struct Hero *, long);
static void load_athena_o_stop_right(struct Member *, struct Hero *);
static void load_athena_o_stop_left(struct Member *, struct Hero *);

static void set_athena_ALT_ADO(struct Member *, struct Hero *, long);
static void load_athena_ADO_right(struct Member *, struct Hero *);
static void load_athena_ADO_left(struct Member *, struct Hero *);
static void set_athena_ALT_ADO_hold(struct Member *, struct Hero *, long);
static void load_athena_ADO_hold_right(struct Member *, struct Hero *);
static void load_athena_ADO_hold_left(struct Member *, struct Hero *);
static void set_athena_ALT_ADO_up(struct Member *, struct Hero *, long);
static void load_athena_ADO_up_right(struct Member *, struct Hero *);
static void load_athena_ADO_up_left(struct Member *, struct Hero *);
static void set_athena_ALT_ADO_down(struct Member *, struct Hero *, long);
static void load_athena_ADO_down_left(struct Member *, struct Hero *);
static void load_athena_ADO_down_right(struct Member *, struct Hero *);

static void set_athena_ALT_ADK(struct Member *, struct Hero *, long);
static void load_athena_ADK_right(struct Member *, struct Hero *);
static void load_athena_ADK_left(struct Member *, struct Hero *);
static void set_athena_ALT_ADU(struct Member *, struct Hero *, long);
static void load_athena_ADU_right(struct Member *, struct Hero *);
static void load_athena_ADU_left(struct Member *, struct Hero *);
static void set_athena_ALT_SJ(struct Member *, struct Hero *, long);
static void load_athena_SJ_right(struct Member *, struct Hero *);
static void load_athena_SJ_left(struct Member *, struct Hero *);
static void set_athena_ALT_SK(struct Member *, struct Hero *, long);
static void load_athena_SK_right(struct Member *, struct Hero *);
static void load_athena_SK_left(struct Member *, struct Hero *);
static void set_athena_ALT_SU(struct Member *, struct Hero *, long);
static void load_athena_SU_right(struct Member *, struct Hero *);
static void load_athena_SU_left(struct Member *, struct Hero *);
static void set_athena_ALT_SI(struct Member *, struct Hero *, long);
static void load_athena_SI_right(struct Member *, struct Hero *);
static void load_athena_SI_left(struct Member *, struct Hero *);

static void set_athena_ALT_SL(struct Member *, struct Hero *, long);
static void load_athena_SL_right(struct Member *, struct Hero *);
static void load_athena_SL_left(struct Member *, struct Hero *);
static void set_athena_ALT_SL_stop(struct Member *, struct Hero *, long);
static void load_athena_SL_stop_right(struct Member *, struct Hero *);
static void load_athena_SL_stop_left(struct Member *, struct Hero *);
static void set_athena_ALT_AS(struct Member *, struct Hero *, long);
static void set_athena_ALT_DS(struct Member *, struct Hero *, long);
static void set_athena_ALT_JK(struct Member *, struct Hero *, long);
static void load_athena_JK_right(struct Member *, struct Hero *);
static void load_athena_JK_left(struct Member *, struct Hero *);
static void athena_move_JK_right(struct Member *, struct Hero *);
static void athena_move_JK_left(struct Member *, struct Hero *);
static void set_athena_ALT_ADJ(struct Member *, struct Hero *, long);
static void load_athena_ADJ_right(struct Member *, struct Hero *);
static void load_athena_ADJ_left(struct Member *, struct Hero *);
static void set_athena_ALT_ADL(struct Member *, struct Hero *, long);
static void load_athena_ADL_right(struct Member *, struct Hero *);
static void load_athena_ADL_left(struct Member *, struct Hero *);
static void set_athena_ALT_ADI(struct Member *, struct Hero *, long);
static void load_athena_ADI_right(struct Member *, struct Hero *);
static void load_athena_ADI_left(struct Member *, struct Hero *);
static void athena_move_ADI_up(struct Member *, struct Hero *, int);
static void athena_move_ADI_down(struct Member *, struct Hero *, int);

#endif
