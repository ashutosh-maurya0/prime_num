/* helpf.h */

#ifndef _HELPF_H
#define _HELPF_H

int
helpf(char *argv_v_0[], int argc);			/* to print help */

int temp_l_2;							/* first loop used for index value of "argv_v_0[]" */
int temp_l_3;							/* second loop used for index value of "helpf[]" */
int temp_l_4;							/* for loop in "from=" */
int temp_l_5;							/* for loop in "to=" */
int inc_v_0;							/* for index value of "argv_v_1[]" */
int check_v_4;							/* printing command line argument is invalid */
int check_v_5;							/* to check whether to return "EXIT_FAILURE or EXIT_SUCCESS" */
#endif
