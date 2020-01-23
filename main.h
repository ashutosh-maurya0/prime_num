/* 0.7 */
/* This file contain the variable declaration
 * and macros and function prototype
 */

/* main.h */
#ifndef _MAIN_H
#define _MAIN_H

/* macro for colour */
#define ANSI_COLOR_RED     	"\x1b[31m"		/* for error */
#define ANSI_COLOR_GREEN  	"\x1b[32m"
#define ANSI_COLOR_YELLOW  	"\x1b[33m"
#define ANSI_COLOR_BLUE    	"\x1b[34m"		/* for higliting prime number in output */
#define ANSI_COLOR_MAGENTA 	"\x1b[35m"
#define ANSI_COLOR_CYAN    	"\x1b[36m"
#define ANSI_COLOR_RESET   	"\x1b[0m"

#include<sys/types.h>						/* defined data types */

typedef struct struct_ptr {
	u_int64_t temp_v_s_0;						/* primef.c: to store "temp_v_0" */
	u_int64_t temp_v_s_1;						/* primef.c: to store "temp_v_7" */
	u_int64_t temp_v_s_2;						/* primef.c: to store "temp_v_11" */
	u_int64_t temp_v_s_3;						/* primef.c: to store "temp_v_17" */
	u_int64_t temp_v_s_4;						/* primef.c: to store "temp_v_21" */
	u_int64_t temp_v_s_5;						/* primef.c: to store "temp_v_30" */
	u_int64_t temp_v_s_6;						/* primef.c: to store "temp_v_30" */	

	u_int64_t from_num;						/* thread-1: to store "from=" */
	u_int64_t to_num;							/* thread-1: to store "to=" */
	u_int64_t from_num_1;						/* thread-2: to store "from=" */
	u_int64_t to_num_1;						/* thread-2: to store "to=" */
	u_int64_t from_num_2;						/* thread-3: to store "from=" */
	u_int64_t to_num_2;						/* thread-3: to store "to=" */
	u_int64_t from_num_3;						/* thread-4: to store "from=" */
	u_int64_t to_num_3;						/* thread-4: to store "to=" */
	u_int64_t from_num_4;						/* thread-5: to store "from=" */
	u_int64_t to_num_4;						/* thread-5: to store "to=" */
	u_int64_t from_num_5;						/* thread-6: to store "from=" */
	u_int64_t to_num_5;						/* thread-6: to store "to=" */
	u_int64_t from_num_6;						/* thread-7: to store "from=" */
	u_int64_t to_num_6;						/* thread-7: to store "to=" */
	
	u_int64_t *temp_ptr_s_0;					/* primef.c: this store the address of "temp_ptr_0" */
	u_int64_t *temp_ptr_s_1;					/* primef.c: this store the address of "temp_ptr_1" */
	u_int64_t *temp_ptr_s_2;					/* primef.c: this store the address of "temp_ptr_2" */
	u_int64_t *temp_ptr_s_3;					/* primef.c: this store the address of "temp_ptr_3" */
	u_int64_t *temp_ptr_s_4;					/* primef.c: this store the address of "temp_ptr_4" */
	u_int64_t *temp_ptr_s_5;					/* primef.c: this store the address of "temp_ptr_5" */
	u_int64_t *temp_ptr_s_6;					/* primef.c: this store the address of "temp_ptr_6" */

	u_int64_t location_in_allo_mem;				/* main.c: to store total no of primes between "2 from=" */

	struct chk_st {
		int chk_s_v_0 ;
		int chk_s_v_1;
		int chk_s_v_2;
		int chk_s_v_3;
		int chk_s_v_4;
		int chk_s_v_5;
		int chk_s_v_6;
	}chk_st;
    }struct_ptr;

/**************************************** threading ***********************************************/
struct_ptr tstruct_0;
pthread_t thread[7];
int pret_0, pret_1, pret_2, pret_3, pret_4, pret_5, pret_6;
/***************************************** main() ************************************************/

u_int64_t *temp_ptr_0;							/* for calloc() */
u_int64_t *temp_ptr_1;							/* for calloc() */
u_int64_t *temp_ptr_2;							/* for calloc() */
u_int64_t *temp_ptr_3;							/* for calloc() */
u_int64_t *temp_ptr_4;							/* for calloc() */
u_int64_t *temp_ptr_5;							/* for calloc() */
u_int64_t *temp_ptr_6;							/* for calloc() */

struct_ptr *struct_ret_0;						/* to store pointer of struct */
u_int64_t *temp_ret;							/* for struct pointer also int primef */
u_int64_t temp_v_2;							/* to store numeric value of "from=" argument */
u_int64_t temp_v_3;							/* to store numeric value of "to=" argument */
int temp_l_6;									/* use in when to call "helpf()" */
u_int64_t temp_l_7;							/* use while printing prime numbers in "main()" */
int ret_v_0;									/* to store value return by "helpf()" */
int check_v_1;									/* use to check wether argument "from=" is complete (use in helpf.c) */
int check_v_3;									/* use to check wether argument or "to=" is complete (use in helpf.c) */
int check_v_6;									/* use to check wether argument "-j" is complete (use in helpf.c) */
int check_v_2;									/* use in primef() call */
char temp_arr_0[5];							/* use to store "from=" */
char temp_arr_1[3];							/* use to store "to=" */
int inc_v_1;									/* while printing prime number on screen to index */
int how_much_mem;							/* use as a first argument to "calloc()" */
#endif
