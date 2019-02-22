/* 0.6 */
/* This file contain the variable declaration
 * and macros and function prototype 
 */

/* variables.h */

#include<sys/types.h>	/* defined data types */

typedef struct struct_ptr {
	u_int64_t temp_v_s_0;		    /* primef.c: to stores "temp_v_0: */
	u_int64_t from_num;		    /* primef_struct.c: to store "from=" */
	u_int64_t to_num;		    /* primef_struct.c: to store "to=" */
	u_int64_t *temp_ptr_0_s_0;	    /* primef.c: this stores the address of "temp_ptr_0" */
	u_int64_t location_in_allo_mem;	    /* main.c: to sotre total no of primes between "2 from=" */ 	
    }struct_ptr;

/* function prototype */
struct_ptr
*primef(u_int64_t *from_num, u_int64_t *to_num);     /* for calculating prime numbers */

int 
helpf(char *argv_v_0[],int argc);		     /* to print help */
	
struct_ptr 
*primef_struct(struct_ptr *argv_st);		     /* to calculate prime numbers if("from=" >= 8)*/

/* primef() variables */
u_int64_t *temp_ptr_0;	/* for malloc() */
u_int64_t *temp_ret;	/* for struct pointer */
u_int64_t temp_v_0;	/* for condition in second loop have value of 'temp_v_1'*/
u_int64_t temp_v_1;	/* for index value of 'temp_ptr_0' */
int check_v_0;		/* to check the condition weather value should assign or not to temp_ptr_0[temp_v] */
u_int64_t temp_l_0;	/* for first loop */
u_int64_t temp_l_1;	/* for second loop */
struct_ptr *st_ret;	/* to store pointer of struct */
/* help() */

char *help[] = {"\nusages: main [options] [output]\n", "",
		"options\n", 	"",		
		"--help",	"\t\tlist all the aruments.\n",
		"-diff",	"\t\tdifference between consecutive prime numbers.\n",
		"-i",		"\t\tinterval\n",
		"-o",		"\t\twhere you want output of program.\n",		
		"from=",	"\t\tfrom=number replace \"number\" with numeric.\n", 
		"to=",		"\t\tto=number replace \"number\" with numeric.\n",
		"-r_dec",	"\t\trate of decreasing prime number.\n",
		"-r_inc",	"\t\trate of increasing prime number.\n", 
		"-d",		"\t\tdigit\n",
		"-m",		"\t\tmanually input file load prime number.\n\t\tThis argument must run with from= to= argument\n"};
const int prime_arg=12; /* number of valid arguments can be passed */
int temp_l_2;		/* first loop used for index value of "argv_v_0[]" */
int temp_l_3;		/* second loop used for index value of "helpf[]" */
int inc_v_0;		/* for index value of "argv_v_1[]" */
int check_v_4;		/* printing command line argument is invalid */
int check_v_5;		/* to check whether to return "EXIT_FAILURE or EXIT_SUCCESS" */
int temp_l_4;		/* for loop in "from=" */ 
int temp_l_5;		/* for loop in "to=" */ 

/* primef_struct() */
u_int64_t inc_v_2;

/* main() */
u_int64_t temp_v_2;	/* to store numeric value of "from=" argument */
u_int64_t temp_v_3;	/* to store numeric value of "to=" argument */
u_int64_t temp_v_4;	/* use when "from= => 8" to store "3" for first argument of "primef()" */
int temp_l_6;		/* use in when to call "helpf()" */ 
u_int64_t temp_l_7;	/* use while printing prime numbers in "main()" */
int ret_v_0;		/* to store value return by "helpf()" */
int check_v_1;		/* use to check wether argument "from=" is complete (use in helpf.c) */
int check_v_3;		/* use to check wether argument or "to=" is complete (use in helpf.c) */	
int check_v_2;		/* use in primef() call */
int check_from = 0;	/* use in "form=" */
int check_to   = 0;	/* use in "to=" */
char temp_arr_0[5];	/* use to store "from=" */
char temp_arr_1[3];	/* use to store "to=" */
int inc_v_1;		/* while printing prime number on screen to index */
int how_much_mem;	/* use as a first argument to "calloc()" */
