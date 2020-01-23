/* primef() variables */

#include<sys/types.h>
#include"main.h"

void
*primef1(struct_ptr *tstruct_1);     					/* for calculating prime numbers */

void
*primef2(struct_ptr *tstruct_1);						/* for calculating prime numbers */

void
*primef3(struct_ptr *tstruct_1);						/* for calculating prime numbers */

void
*primef4(struct_ptr *tstruct_1);						/* for claculatiing prime numbers */

void
*primef5(struct_ptr *tstruct_1);						/* for calculating prime numbers */

void
*primef6(struct_ptr *tstruct_1);						/* for calculating prime numbers */

void
*primef7(struct_ptr *tstruct_1);						/* for calculating prime numbers */

struct_ptr 
*primef(u_int64_t *from_num, u_int64_t *to_num);		/* for calculating prime numbers */

struct_ptr
*primef_struct(struct_ptr *argv_st);					/* to calculate prime numbers if("from=" >= 8) */

/*************primef1()*************/
u_int64_t temp_v_4;								/* use when "from= => 8" to store "3" for first argument of "primef()" */
u_int64_t temp_v_0;								/* for condition in second loop have value of 'temp_v_1' */
u_int64_t temp_v_1;								/* for index value of 'temp_ptr_0' */
u_int64_t temp_l_0;								/* for first loop primef1() */
u_int64_t temp_l_1;								/* for second loop primef1() */
int check_v_0;										/* to check the condition whether value should assign or not to temp_ptr_0[temp_v] */

/*************primef2()*************/
u_int64_t temp_v_5;								/* for condition in second loop have value of 'temp_v_2' */
u_int64_t temp_v_6;								/* for index value of 'temp_ptr_1' */
u_int64_t temp_v_7;								/* for index value of 'temp_ptr_1' while initializing */
u_int64_t temp_l_8;								/* for first loop primef2() */
u_int64_t temp_l_9;								/* for second loop primef2() */
int check_v_7;										/* to check the condition whether value should assign or not to temp_ptr_1[temp_v] */

/*************primef3()*************/
u_int64_t temp_v_9;								/* for index value of 'temp_ptr_2' */
u_int64_t temp_v_10;								/* for index value of 'temp_ptr_2' */
u_int64_t temp_v_11;								/* for index value of 'temp_ptr_2' while initializing */
u_int64_t temp_v_12;
u_int64_t temp_v_13;
u_int64_t temp_l_10;								/* for first loop primef2() */
u_int64_t temp_l_11;								/* for second loop primef2() */
int check_v_8;										/* to check the condition whether value should assign or not to temp_ptr_2[temp_v] */ 

/*************primef4()*************/
u_int64_t temp_v_14;								/* primef4() */
u_int64_t temp_v_15;								/* primef4() */
u_int64_t temp_v_16;								/* primef4() */
u_int64_t temp_v_17;								/* primef4() */
u_int64_t temp_v_18;
u_int64_t temp_v_19;
u_int64_t temp_v_20;
u_int64_t temp_l_12;
u_int64_t temp_l_13;
int check_v_9;										/* primef4() */

/*************primef5()*************/
u_int64_t temp_v_21;
u_int64_t temp_v_22;
u_int64_t temp_v_23;
u_int64_t temp_v_24;
u_int64_t temp_v_25;
u_int64_t temp_v_26;
u_int64_t temp_v_27;
u_int64_t temp_v_28;
u_int64_t temp_v_29;
u_int64_t temp_l_14;
u_int64_t temp_l_15;
int check_v_10;

/*************primef6()*************/
u_int64_t temp_v_30;
u_int64_t temp_v_31;
u_int64_t temp_v_32;
u_int64_t temp_v_33;
u_int64_t temp_v_34;
u_int64_t temp_v_35;
u_int64_t temp_v_36;
u_int64_t temp_v_37;
u_int64_t temp_v_38;
u_int64_t temp_v_39;
u_int64_t temp_v_40;
u_int64_t temp_l_16;
u_int64_t temp_l_17;
int check_v_11;

/************primef7()*************/
u_int64_t temp_v_41;
u_int64_t temp_v_42;
u_int64_t temp_v_43;
u_int64_t temp_v_44;
u_int64_t temp_v_45;
u_int64_t temp_v_46;
u_int64_t temp_v_47;
u_int64_t temp_v_48;
u_int64_t temp_v_49;
u_int64_t temp_v_50;
u_int64_t temp_v_51;
u_int64_t temp_v_52;
u_int64_t temp_v_53;
u_int64_t temp_l_18;
u_int64_t temp_l_19;
int check_v_12;

/* primef_struct() */
u_int64_t inc_v_2;
