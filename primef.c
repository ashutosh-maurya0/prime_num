/* 0.7 */
/* This function is part of the program PRIME NUMBER ANALYSIS 
 * program will help to analysis rate of increasing and decreasing
 * in prime number.
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"main.h"
#include"primef.h"

/* prime.c: function to check whether number is prime or not */

/****************************************************** *****************************************************/
 /************************************************** primef1()*************************************************/
/************************************************************************************************************/
void
*primef1(struct_ptr *tstruct_1)	{
/*********running status code**********/
	tstruct_1->chk_st.chk_s_v_0 = 1;
	printf("T-1:tstruct_1->chk_st.chk_s_v_0 = %d\n", tstruct_1->chk_st.chk_s_v_0);

	/* assigning '1', '2', '5', and '7' to temp_ptr_0[] */
		temp_ptr_0[0] = 1;
		temp_ptr_0[1] = 2;
		temp_ptr_0[2] = 3;
		temp_ptr_0[3] = 5;
		temp_ptr_0[4] = 7;

	/* even or odd */
	if (tstruct_1->from_num % 2 == 0) {
		tstruct_1->from_num += 1;
	}

	printf("T-1 from_num  = %ld  to_num = %ld\n ", tstruct_1->from_num, tstruct_1->to_num);
	
	temp_v_0 = 4;				/* index value used track the position of array elements used by the function*/

/******************************************* ***************************************************************/
 /************************************************* calculation*************************************************/

	for (temp_l_0 = tstruct_1->from_num; temp_l_0 <= tstruct_1->to_num; temp_l_0 += 2)	{
		check_v_0 = 0;
		temp_v_1 = 2;
		for (temp_l_1 = 1; temp_l_1 < temp_v_0 ; temp_l_1++)	{
			if (temp_l_0 % temp_ptr_0[temp_v_1]  != 0)
				temp_v_1++;
			else
			{
				check_v_0 = -1;
				break;
			}

			}
		if (check_v_0 != -1) {
			temp_ptr_0[temp_v_1] = temp_l_0;
			temp_v_0 = temp_v_1;
			struct_ret_0 -> temp_v_s_0 = temp_v_0;
			struct_ret_0 -> temp_ptr_s_0 = temp_ptr_0;
			struct_ret_0 -> temp_v_s_0 = temp_v_0;
		}
	}
	struct_ret_0 -> temp_ptr_s_0 = temp_ptr_0;
	struct_ret_0 -> temp_v_s_0 = temp_v_0;
	printf("THREAD 1 final index value struct_ret_0 -> temp_v_s_0 = %ld	",struct_ret_0 -> temp_v_s_0);
	printf("temp_v_0 = %ld\n\n", temp_v_0);
	return NULL;
}
/****************************************************** *****************************************************/
 /*************************************************** primef2()************************************************/
/************************************************************************************************************/
void
*primef2(struct_ptr *tstruct_2)	{
/*********running status code**********/
CHK:
	if(tstruct_2->chk_st.chk_s_v_0 == -1)	{
		printf("T-2:tstruct_2->chk_st.chk_s_v_0 = %d\n", tstruct_2->chk_st.chk_s_v_0);
		goto CHK;
	}
	printf("T-2:tstruct_2->chk_st.chk_s_v_0 = %d\n", tstruct_2->chk_st.chk_s_v_0);
/********assigning status code*********/
	tstruct_2->chk_st.chk_s_v_1 = 2;

/************even or odd************/
	if (tstruct_2->from_num_1 % 2 == 0) {
		tstruct_2->from_num_1 += 1;
	}

	printf("T-2:74 from_num_1 = %ld  to_num_1 = %ld\n ", tstruct_2->from_num_1, tstruct_2->to_num_1);

/* Whether previeous thread had calculated any prime number or not */
INIT:
	temp_v_5 = struct_ret_0 -> temp_v_s_0;

	printf("T-2:76: temp_v_5	= %ld\n", temp_v_5);

	if(temp_v_5 == 0)	{
		goto INIT;	
	}


	temp_v_7 = 0;						/* index value used track the position of array elements used by the function*/		
/****************************************************** ***************************************************************/
 /****************************************************** calculation******************************************************/
	for (temp_l_8 = tstruct_2->from_num_1; temp_l_8 <= tstruct_2->to_num_1; temp_l_8 += 2)	{
		check_v_7 = 0;
		temp_v_6 = 2;
/********************************************************Thread-1************************************************************/
		for (temp_l_9 = 1; temp_l_9 < struct_ret_0 -> temp_v_s_0 ; temp_l_9++)	{
//			printf("T-2:83: temp_l_8 = %ld   temp_l_9 = %ld   temp_v_6 = %ld \n", temp_l_8, temp_l_9, temp_v_6);
//			printf("T-2:85: temp_ptr_0[%ld] =%ld\n", temp_v_6, struct_ret_0 -> temp_ptr_s_0[temp_v_6]);
			if (temp_l_8 % struct_ret_0 -> temp_ptr_s_0[temp_v_6] != 0)
				temp_v_6++;
			else
			{
				check_v_7 = -1;
				break;
			}
		}
		if (check_v_7 != -1) {
			temp_ptr_1[temp_v_7] = temp_l_8;
			struct_ret_0 -> temp_ptr_s_1 = temp_ptr_1;
			struct_ret_0 -> temp_v_s_1 = temp_v_7;
				temp_v_7++;
		}
		struct_ret_0 -> temp_ptr_s_1 = temp_ptr_1;
		struct_ret_0 -> temp_v_s_1 = temp_v_7;
	}
	struct_ret_0 -> temp_ptr_s_1 = temp_ptr_1;
	struct_ret_0 -> temp_v_s_1 = temp_v_7;
	printf("THREAD 2 final index value struct_ret_0 -> temp_v_s_1 = %ld	",struct_ret_0 -> temp_v_s_1);
	printf("temp_v_7 = %ld\n\n", temp_v_7);
	return NULL;
}
/****************************************************** *****************************************************/
 /************************************************** primef3()*************************************************/
/************************************************************************************************************/
void
*primef3(struct_ptr *tstruct_3)	{
CHK:
	if(tstruct_3->chk_st.chk_s_v_1 == -1)	{
		printf("T-3:tstruct_3->chk_st.chk_s_v_1 = %d\n", tstruct_3->chk_st.chk_s_v_1);
		goto CHK;
	}
	printf("T-3:tstruct_3->chk_st.chk_s_v_1 = %d\n", tstruct_3->chk_st.chk_s_v_1);
/********assigning status code*********/
	tstruct_3->chk_st.chk_s_v_2 = 3;

/*********** even or odd ***********/	
	if (tstruct_3->from_num_2 % 2 == 0) {
		tstruct_3->from_num_2 += 1;
	}
	
	printf("T-3:135 from_num_2 = %ld  to_num_2 = %ld\n ", tstruct_3->from_num_2, tstruct_3->to_num_2);

/* Whether previeous thread had calculated any prime number or not */
INIT:
	temp_v_12 = struct_ret_0 -> temp_v_s_0;
	temp_v_13 = struct_ret_0 -> temp_v_s_1;
	
//	printf("T-3:138: temp_v_12	= %ld\n", temp_v_12);
//	printf("T-3:139: temp_v_13	= %ld\n", temp_v_13);

	if(temp_v_12 == 0 || temp_v_13 == 0)	{
		goto INIT;	
	}

	temp_v_11 = 0;			/* index value used track the position of array elements used by the function*/
/****************************************************** ***************************************************************/
 /****************************************************** calculation******************************************************/
	for (temp_l_10 = tstruct_3->from_num_2; temp_l_10 <= tstruct_3->to_num_2; temp_l_10 += 2)	{
		check_v_8 = 0;
		temp_v_9 = 2;
		temp_v_10 = 0;
/********************************************************Thread-1************************************************************/
		for (temp_l_11 = 1; temp_l_11 < struct_ret_0 -> temp_v_s_0 ; temp_l_11++)	{
//			printf("T-3_1:149: temp_l_10 = %ld   temp_l_11 = %ld   temp_v_9 = %ld	temp_v_10 = %ld\n", temp_l_10, temp_l_11, temp_v_9, temp_v_10);
//			printf("T-3_1:150: temp_ptr_0[%ld] =%ld\n", temp_v_9, struct_ret_0 -> temp_ptr_s_0[temp_v_9]);
			if (temp_l_10 % struct_ret_0 -> temp_ptr_s_0[temp_v_9] != 0)	{
				temp_v_9++;
			}
			else
			{
				check_v_8 = -1;
				break;
			}
		}
/********************************************************Thread-2************************************************************/
		if(check_v_8 != -1)
			for (temp_l_11 = 1; temp_l_11 < struct_ret_0 -> temp_v_s_1/2; temp_l_11++)	{
//				printf("T-3_2:178: temp_l_10 = %ld   temp_l_11 = %ld  temp_v_10 = %ld\n", temp_l_10, temp_l_11, temp_v_10);
//				printf("T-3_2:179: temp_ptr_1[%ld] =%ld\n", temp_v_10, struct_ret_0->temp_ptr_s_1[temp_v_10]);
				if(struct_ret_0->temp_ptr_s_1[temp_v_10] != 0)	{
					if(temp_l_10 % struct_ret_0->temp_ptr_s_1[temp_v_10] != 0)
						temp_v_10++;
					else
					{
						check_v_8 = -1;
						break;
					}
				}
				else	{
					check_v_8 = -1;
					break;
				}
			}				
			if (check_v_8 != -1) {
				temp_ptr_2[temp_v_11] = temp_l_10;\
				struct_ret_0 -> temp_ptr_s_2 = temp_ptr_2;
				struct_ret_0 -> temp_v_s_2 = temp_v_11;
					temp_v_11++;
			}
			struct_ret_0 -> temp_ptr_s_2 = temp_ptr_2;
			struct_ret_0 -> temp_v_s_2 = temp_v_11;
	}
	struct_ret_0 -> temp_ptr_s_2 = temp_ptr_2;
	struct_ret_0 -> temp_v_s_2 = temp_v_11;
	printf("THREAD 3 final index value struct_ret_0 -> temp_v_s_2 = %ld	",struct_ret_0 -> temp_v_s_2);
	printf("temp_v_11 = %ld\n\n", temp_v_11);
	return NULL;
}

/****************************************************** ***************************************************************/
 /****************************************************** primef4()******************************************************/
/*********************************************************************************************************************/
void
*primef4(struct_ptr *tstruct_4)	{
/*********running status code**********/
CHK:
	if(tstruct_4->chk_st.chk_s_v_2 == -1)	{
		printf("T-4:tstruct_4->chk_st.chk_s_v_2 = %d\n", tstruct_4->chk_st.chk_s_v_2);
		goto CHK;
	}
	printf("T-4:tstruct_4->chk_st.chk_s_v_2 = %d\n", tstruct_4->chk_st.chk_s_v_2);
/********assigning status code*********/
	tstruct_4->chk_st.chk_s_v_3 = 4;

/*********** even or odd ***********/
	if (tstruct_4->from_num_3 % 2 == 0) {
		tstruct_4->from_num_3 += 1;
	}
				
	printf("T-4:135 from_num_3 = %ld  to_num_3 = %ld\n ", tstruct_4->from_num_3, tstruct_4->to_num_3);

/* Whether previeous thread had calculated any prime number or not */
INIT:
	temp_v_14 = struct_ret_0 -> temp_v_s_0;
	temp_v_15 = struct_ret_0 -> temp_v_s_1;
	temp_v_16 = struct_ret_0 -> temp_v_s_2;
	
//	printf("T-4:138: temp_v_14	= %ld\n", temp_v_14);
//	printf("T-4:139: temp_v_15	= %ld\n", temp_v_15);
//	printf("T-4:250: temp_v_16	= %ld\n", temp_v_16);

//	int loc_v_0 = 0;
	if(temp_v_14 == 0 || temp_v_15 == 0 || temp_v_16 == 0)	{
		goto INIT;
	}
				
	temp_v_17 = 0;					/* index value used track the position of array elements used by the function*/
/****************************************************** ***************************************************************/
 /****************************************************** calculation******************************************************/
	for (temp_l_12 = tstruct_4->from_num_3; temp_l_12 <= tstruct_4->to_num_3; temp_l_12 += 2)	{
		check_v_9 = 0;
		temp_v_18 = 2;
		temp_v_19 = 0;
		temp_v_20 = 0;
/********************************************************Thread-1************************************************************/
		for (temp_l_13 = 1; temp_l_13 < struct_ret_0 -> temp_v_s_0 ; temp_l_13++)	{
//			printf("T-4_1:149: temp_l_13 = %ld   temp_l_13 = %ld   temp_v_18 = %ld\n", temp_l_12, temp_l_13, temp_v_18);
//			printf("T-4_1:150: temp_ptr_0[%ld] =%ld\n", temp_v_18, struct_ret_0 -> temp_ptr_s_0[temp_v_18]);
			if (temp_l_12 % struct_ret_0 -> temp_ptr_s_0[temp_v_18] != 0)	{
				temp_v_18++;
			}
			else
			{
				check_v_9 = -1;
				break;
			}
		}
/********************************************************Thread-2************************************************************/
		if(check_v_9 != -1)
			for (temp_l_13 = 1; temp_l_13 < struct_ret_0 -> temp_v_s_1 ; temp_l_13++)	{
//				printf("T-4_1:149: temp_l_12 = %ld   temp_l_13 = %ld   temp_v_18 = %ld	temp_v_19 = %ld\n", temp_l_12, temp_l_13, temp_v_18, temp_v_10);
//				printf("T-4_1:151: temp_ptr_1[%ld] =%ld\n", temp_v_19, struct_ret_0->temp_ptr_s_1[temp_v_19]);
				if(struct_ret_0->temp_ptr_s_1[temp_v_19] != 0)	{				
					if (temp_l_12 % struct_ret_0 -> temp_ptr_s_1[temp_v_19] != 0)	{
						temp_v_19++;
					}
					else	{
							check_v_9 = -1;
							break;
					}
				}
				else	{
					check_v_9 = -1;
					break;
				}
			}
/********************************************************Thread-3************************************************************/
		if(check_v_9 != -1)
			for (temp_l_13 = 1; temp_l_13 < struct_ret_0 -> temp_v_s_2/2; temp_l_13++)	{
//				printf("T-4_2:178: temp_l_13 = %ld   temp_l_13 = %ld  temp_v_20 = %ld\n", temp_l_13, temp_l_13, temp_v_20);
//				printf("T-4_2:180: temp_ptr_2[%ld] =%ld\n", temp_v_20, temp_ptr_2[temp_v_20]);		
				if(struct_ret_0->temp_ptr_s_2[temp_v_20] != 0)	{
					if(temp_l_12 % struct_ret_0->temp_ptr_s_2[temp_v_20] != 0)
						temp_v_20++;
					else	{
						check_v_9 = -1;
						break;
					}
				}
				else 	{
					check_v_9 = -1;
					break;
				}
			}	
			if (check_v_9 != -1) {
				temp_ptr_3[temp_v_17] = temp_l_12;
				struct_ret_0 -> temp_ptr_s_3 = temp_ptr_3;
				struct_ret_0 -> temp_v_s_3 = temp_v_17;
					temp_v_17++;
			}
			struct_ret_0 -> temp_ptr_s_3 = temp_ptr_3;
			struct_ret_0 -> temp_v_s_3 = temp_v_17;		
	}
	struct_ret_0 -> temp_ptr_s_3 = temp_ptr_3;
	struct_ret_0 -> temp_v_s_3 = temp_v_17;
	printf("THREAD 4 final index value struct_ret_0 -> temp_v_s_3 = %ld	",struct_ret_0 -> temp_v_s_3);
	printf("temp_v_17 = %ld\n\n", temp_v_17);
	return NULL;
}

/****************************************************** ***************************************************************/
 /****************************************************** primef5()******************************************************/
/*********************************************************************************************************************/
void
*primef5(struct_ptr *tstruct_5)	{
/*********running status code**********/
CHK:
	if(tstruct_5->chk_st.chk_s_v_3 == -1)	{
		printf("T-5:tstruct_5->chk_st.chk_s_v_3 = %d\n", tstruct_5->chk_st.chk_s_v_3);
		goto CHK;
	}
	printf("T-5:tstruct_5->chk_st.chk_s_v_3 = %d\n", tstruct_5->chk_st.chk_s_v_3);
/********assigning status code*********/
	tstruct_5->chk_st.chk_s_v_4 = 5;

/******** even or odd ********/
	if (tstruct_5->from_num_4 % 2 == 0) {
		tstruct_5->from_num_4 += 1;
	}
	
	printf("T-5:135 from_num_4 = %ld  to_num_4 = %ld\n ", tstruct_5->from_num_4, tstruct_5->to_num_4);

/* Whether previeous thread had calculated any prime number or not */
int chk_v_0 = 0;
INIT:
	temp_v_22 = struct_ret_0 -> temp_v_s_0;
	temp_v_23 = struct_ret_0 -> temp_v_s_1;
	temp_v_24 = struct_ret_0 -> temp_v_s_2;
	temp_v_25 = struct_ret_0 -> temp_v_s_3;
	
//	printf("T-5:138: temp_v_22	= %ld\n", temp_v_22);
//	printf("T-5:139: temp_v_23	= %ld\n", temp_v_23);
//	printf("T-5:250: temp_v_24	= %ld\n", temp_v_24);
//	printf("T-5:356: temp_v_25	= %ld\n", temp_v_25);

	if(temp_v_22 == 0 || temp_v_23 == 0 || temp_v_24 == 0 || temp_v_25 == 0)	{
		if(chk_v_0 <=100)	{	
			chk_v_0++;
			goto INIT;
		}
		else
			exit(EXIT_FAILURE);	
	}

	temp_v_21 = 0;				/* index value used track the position of array elements used by the function*/
/****************************************************** ***************************************************************/
 /****************************************************** calculation******************************************************/
	for (temp_l_14 = tstruct_5->from_num_4; temp_l_14 <= tstruct_5->to_num_4; temp_l_14 += 2)	{
		check_v_10 = 0;
		temp_v_26 = 2;
		temp_v_27 = 0;
		temp_v_28 = 0;
		temp_v_29 = 0;
/********************************************************Thread-1************************************************************/
		for (temp_l_15 = 1; temp_l_15 < struct_ret_0 -> temp_v_s_0 ; temp_l_15++)	{
//			printf("T-5_1:299: temp_l_14 = %ld   temp_l_15 = %ld   temp_v_26 = %ld\n", temp_l_14, temp_l_15, temp_v_26);
//			printf("T-5_1:300: temp_ptr_0[%ld] =%ld\n", temp_v_26, struct_ret_0 -> temp_ptr_s_0[temp_v_26]);
			if (temp_l_14 % struct_ret_0 -> temp_ptr_s_0[temp_v_26] != 0)	{
				temp_v_26++;
			}
			else
			{
				check_v_10 = -1;
				break;
			}
		}
/********************************************************Thread-2************************************************************/
		if(check_v_10 != -1)
			for (temp_l_15 = 1; temp_l_15 < struct_ret_0 -> temp_v_s_1 ; temp_l_15++)	{
//				printf("T-5_2:313: temp_l_14 = %ld   temp_l_15 = %ld   temp_v_27 = %ld\n", temp_l_14, temp_l_15, temp_v_27);
//				printf("T-5_2:314: temp_ptr_1[%ld] =%ld\n", temp_v_27, struct_ret_0->temp_ptr_s_1[temp_v_27]);
				if(struct_ret_0->temp_ptr_s_1[temp_v_27] != 0)	{				
					if (temp_l_14 % struct_ret_0 -> temp_ptr_s_1[temp_v_27] != 0)	{
						temp_v_27++;
					}
					else	{
							check_v_10 = -1;
							break;
					}
				}
				else	{
					check_v_10 = -1;
					break;
				}
			}
/********************************************************Thread-3************************************************************/
		if(check_v_10 != -1)
			for (temp_l_15 = 1; temp_l_15 < struct_ret_0 -> temp_v_s_2; temp_l_15++)	{
//				printf("T-5_3:332: temp_l_14 = %ld   temp_l_15 = %ld	temp_v_28 =%ld\n", temp_l_14, temp_l_15, temp_v_28);
//				printf("T-5_3:333: temp_ptr_2[%ld] =%ld\n", temp_v_28, temp_ptr_2[temp_v_28]);		
				if(struct_ret_0->temp_ptr_s_2[temp_v_28] != 0)	{
					if(temp_l_14 % struct_ret_0->temp_ptr_s_2[temp_v_28] != 0)
						temp_v_28++;
					else	{
						check_v_10 = -1;
						break;
					}
				}
				else 	{
					check_v_10 = -1;
					break;
				}
			}
/********************************************************Thread-4************************************************************/
/*		if(check_v_10 != -1)
			for (temp_l_15 = 1; temp_l_15 < struct_ret_0 -> temp_v_s_3; temp_l_15++)	{
//				printf("T-5_4:350: temp_l_14 = %ld   temp_l_15 = %ld  temp_v_29 = %ld\n", temp_l_14, temp_l_15, temp_v_29);
//				printf("T-5_4:351: temp_ptr_2[%ld] =%ld\n", temp_v_29, temp_ptr_2[temp_v_29]);		
				if(struct_ret_0->temp_ptr_s_3[temp_v_29] != 0)	{
					if(temp_l_14 % struct_ret_0->temp_ptr_s_3[temp_v_29] != 0)
						temp_v_29++;
					else	{
						check_v_10 = -1;
						break;
					}
				}
				else 	{
					check_v_10 = -1;
					break;
				}
			} */
			if (check_v_10 != -1) {
				temp_ptr_4[temp_v_21] = temp_l_14;
				struct_ret_0 -> temp_ptr_s_4 = temp_ptr_4;
				struct_ret_0 -> temp_v_s_4 = temp_v_21;
					temp_v_21++;
			}
			struct_ret_0 -> temp_ptr_s_4 = temp_ptr_4;
			struct_ret_0 -> temp_v_s_4 = temp_v_21;
	}
	struct_ret_0 -> temp_ptr_s_4 = temp_ptr_4;
	struct_ret_0 -> temp_v_s_4 = temp_v_21;
	printf("THREAD 5 final index value struct_ret_0 -> temp_v_s_4 = %ld	",struct_ret_0 -> temp_v_s_4);
	printf("temp_v_21 = %ld\n\n", temp_v_21);
	return NULL;
}

/****************************************************** ***************************************************************/
 /****************************************************** primef6()******************************************************/
/*********************************************************************************************************************/
void
*primef6(struct_ptr *tstruct_6)	{
/*********running status code**********/
CHK:
	if(tstruct_6->chk_st.chk_s_v_4 == -1)	{
		printf("T-6:tstruct_6->chk_st.chk_s_v_4 = %d\n", tstruct_6->chk_st.chk_s_v_4);
		goto CHK;
	}
	printf("T-6:tstruct_6->chk_st.chk_s_v_4 = %d\n", tstruct_6->chk_st.chk_s_v_4);
/********assigning status code*********/
	tstruct_6->chk_st.chk_s_v_5 = 6;


/******** even or odd ********/
	if (tstruct_6->from_num_5 % 2 == 0) {
		tstruct_6->from_num_5 += 1;
	}
	
	printf("T-6:515 from_num_5 = %ld  to_num_5 = %ld\n ", tstruct_6->from_num_5, tstruct_6->to_num_5);

/* Whether previeous thread had calculated any prime number or not */
int chk_v_0 = 0;
INIT:
	temp_v_31 = struct_ret_0 -> temp_v_s_0;
	temp_v_32 = struct_ret_0 -> temp_v_s_1;
	temp_v_33 = struct_ret_0 -> temp_v_s_2;
	temp_v_34 = struct_ret_0 -> temp_v_s_3;
	temp_v_35 = struct_ret_0 -> temp_v_s_4;
	
	printf("T-6:138: temp_v_31	= %ld\n", temp_v_31);
	printf("T-6:139: temp_v_32	= %ld\n", temp_v_32);
	printf("T-6:250: temp_v_33	= %ld\n", temp_v_33);
	printf("T-6:356: temp_v_34	= %ld\n", temp_v_34);
	printf("T-6:530: temp_v_35	= %ld\n", temp_v_35);

	if(temp_v_31 == 0 || temp_v_32 == 0 || temp_v_33 == 0 || temp_v_34 == 0 || temp_v_35 == 0)	{
		if(chk_v_0 <=100)	{	
			chk_v_0++;
			goto INIT;
		}
		else
			exit(EXIT_FAILURE);	
	}

	temp_v_31 = 0;				/* index value used track the position of array elements used by the function*/
/****************************************************** ***************************************************************/
 /****************************************************** calculation******************************************************/
	for (temp_l_16 = tstruct_6->from_num_5; temp_l_16 <= tstruct_6->to_num_5; temp_l_16 += 2)	{
		check_v_11 = 0;
		temp_v_36 = 2;
		temp_v_37 = 0;
		temp_v_38 = 0;
		temp_v_39 = 0;
		temp_v_40 = 0;
	
/********************************************************Thread-1************************************************************/
		for (temp_l_17 = 1; temp_l_17 < struct_ret_0 -> temp_v_s_0 ; temp_l_17++)	{
//			printf("T-6_1:299: temp_l_16 = %ld   temp_l_17 = %ld   temp_v_36 = %ld\n", temp_l_16, temp_l_17, temp_v_36);
//			printf("T-6_1:300: temp_ptr_0[%ld] =%ld\n", temp_v_36, struct_ret_0 -> temp_ptr_s_0[temp_v_36]);
			if (temp_l_16 % struct_ret_0 -> temp_ptr_s_0[temp_v_36] != 0)	{
				temp_v_36++;
			}
			else
			{
				check_v_11 = -1;
				break;
			}
		}
/********************************************************Thread-2************************************************************/
		if(check_v_11 != -1)
			for (temp_l_17 = 1; temp_l_17 < struct_ret_0 -> temp_v_s_1 ; temp_l_17++)	{
//				printf("T-6_2:313: temp_l_16 = %ld   temp_l_17 = %ld   temp_v_37 = %ld\n", temp_l_16, temp_l_17, temp_v_37);
//				printf("T-6_2:314: temp_ptr_1[%ld] =%ld\n", temp_v_37, struct_ret_0->temp_ptr_s_1[temp_v_37]);
				if(struct_ret_0->temp_ptr_s_1[temp_v_37] != 0)	{				
					if (temp_l_16 % struct_ret_0 -> temp_ptr_s_1[temp_v_37] != 0)	{
						temp_v_37++;
					}
					else	{
							check_v_11 = -1;
							break;
					}
				}
				else	{
					check_v_11 = -1;
					break;
				}
			}
/********************************************************Thread-3************************************************************/
		if(check_v_11 != -1)
			for (temp_l_17 = 1; temp_l_17 < struct_ret_0 -> temp_v_s_2; temp_l_17++)	{
//				printf("T-6_3:332: temp_l_16 = %ld   temp_l_17 = %ld	temp_v_38 =%ld\n", temp_l_16, temp_l_17, temp_v_38);
//				printf("T-6_3:333: temp_ptr_2[%ld] =%ld\n", temp_v_38, temp_ptr_2[temp_v_38]);		
				if(struct_ret_0->temp_ptr_s_2[temp_v_38] != 0)	{
					if(temp_l_16 % struct_ret_0->temp_ptr_s_2[temp_v_38] != 0)
						temp_v_38++;
					else	{
						check_v_11 = -1;
						break;
					}
				}
				else 	{
					check_v_11 = -1;
					break;
				}
			}
/********************************************************Thread-4************************************************************/
/*		if(check_v_11 != -1)
			for (temp_l_17 = 1; temp_l_17 < struct_ret_0 -> temp_v_s_3; temp_l_17++)	{
//				printf("T-6_4:350: temp_l_16 = %ld   temp_l_17 = %ld  temp_v_39 = %ld\n", temp_l_16, temp_l_17, temp_v_39);
//				printf("T-6_4:351: temp_ptr_2[%ld] =%ld\n", temp_v_39, temp_ptr_2[temp_v_39]);		
				if(struct_ret_0->temp_ptr_s_3[temp_v_39] != 0)	{
					if(temp_l_16 % struct_ret_0->temp_ptr_s_3[temp_v_39] != 0)
						temp_v_39++;
					else	{
						check_v_11 = -1;
						break;
					}
				}
				else 	{
					check_v_11 = -1;
					break;
				}
			} */
/********************************************************Thread-5************************************************************/
/*		if(check_v_11 != -1)
			for (temp_l_17 = 1; temp_l_17 < struct_ret_0 -> temp_v_s_4; temp_l_17++)	{
//				printf("T-6_3:332: temp_l_16 = %ld   temp_l_17 = %ld	temp_v_40 =%ld\n", temp_l_16, temp_l_17, temp_v_40);
//				printf("T-6_3:333: temp_ptr_4[%ld] =%ld\n", temp_v_40, temp_ptr_4[temp_v_40]);		
				if(struct_ret_0->temp_ptr_s_4[temp_v_40] != 0)	{
					if(temp_l_16 % struct_ret_0->temp_ptr_s_4[temp_v_40] != 0)
						temp_v_40++;
					else	{
						check_v_11 = -1;
						break;
					}
				}
				else 	{
					check_v_11 = -1;
					break;
				}
			} */
			if (check_v_11 != -1) {
				temp_ptr_5[temp_v_31] = temp_l_16;
				struct_ret_0 -> temp_ptr_s_5 = temp_ptr_5;
				struct_ret_0 -> temp_v_s_5 = temp_v_21;
					temp_v_31++;
			}
			struct_ret_0 -> temp_ptr_s_5 = temp_ptr_5;
			struct_ret_0 -> temp_v_s_5 = temp_v_31;
	}
	struct_ret_0 -> temp_ptr_s_5 = temp_ptr_5;
	struct_ret_0 -> temp_v_s_5 = temp_v_31;
	printf("THREAD 6 final index value struct_ret_0 -> temp_v_s_5 = %ld	",struct_ret_0 -> temp_v_s_5);
	printf("temp_v_31 = %ld\n\n", temp_v_31);
	return NULL;
}

/****************************************************** ***************************************************************/
 /****************************************************** primef7()******************************************************/
/*********************************************************************************************************************/
void
*primef7(struct_ptr *tstruct_7)	{
/*********running status code**********/
CHK:
	if(tstruct_7->chk_st.chk_s_v_5 == -1)	{
		printf("T-7:tstruct_7->chk_st.chk_s_v_5 = %d\n", tstruct_7->chk_st.chk_s_v_5);
		goto CHK;
	}
	printf("T-7:tstruct_7->chk_st.chk_s_v_5 = %d\n", tstruct_7->chk_st.chk_s_v_5);
/********assigning status code*********/
	tstruct_7->chk_st.chk_s_v_6 = 7;


/******** even or odd ********/
	if (tstruct_7->from_num_6 % 2 == 0) {
		tstruct_7->from_num_6 += 1;
	}
	
	printf("T-7:515 from_num_6 = %ld  to_num_6 = %ld\n ", tstruct_7->from_num_6, tstruct_7->to_num_6);

/* Whether previeous thread had calculated any prime number or not */
int chk_v_0 = 0;
INIT:
	temp_v_42 = struct_ret_0 -> temp_v_s_0;
	temp_v_43 = struct_ret_0 -> temp_v_s_1;
	temp_v_44 = struct_ret_0 -> temp_v_s_2;
	temp_v_45 = struct_ret_0 -> temp_v_s_3;
	temp_v_46 = struct_ret_0 -> temp_v_s_4;
	temp_v_47 = struct_ret_0 -> temp_v_s_5;	

	printf("T-7:138: temp_v_42	= %ld\n", temp_v_42);
	printf("T-7:139: temp_v_43	= %ld\n", temp_v_43);
	printf("T-7:250: temp_v_44	= %ld\n", temp_v_44);
	printf("T-7:356: temp_v_45	= %ld\n", temp_v_45);
	printf("T-7:530: temp_v_46	= %ld\n", temp_v_46);
	printf("T-7:670: temp_v_47 	= %ld\n", temp_v_47);

	if(temp_v_42 == 0 || temp_v_43 == 0 || temp_v_44 == 0 || temp_v_45 == 0 || temp_v_46 == 0 || temp_v_47 == 0)	{
		if(chk_v_0 <=100)	{	
			chk_v_0++;
			goto INIT;
		}
		else
			exit(EXIT_FAILURE);	
	}

	temp_v_41 = 0;				/* index value used track the position of array elements used by the function*/
/****************************************************** ***************************************************************/
 /****************************************************** calculation******************************************************/
	for (temp_l_18 = tstruct_7->from_num_6; temp_l_18 <= tstruct_7->to_num_6; temp_l_18 += 2)	{
		check_v_12 = 0;
		temp_v_48 = 2;
		temp_v_49 = 0;
		temp_v_50 = 0;
		temp_v_51 = 0;
		temp_v_52 = 0;
		temp_v_53 = 0;
	
/********************************************************Thread-1************************************************************/
		for (temp_l_19 = 1; temp_l_19 < struct_ret_0 -> temp_v_s_0 ; temp_l_19++)	{
//			printf("T-7_1:299: temp_l_18 = %ld   temp_l_19 = %ld   temp_v_48 = %ld\n", temp_l_18, temp_l_19, temp_v_48);
//			printf("T-7_1:300: temp_ptr_0[%ld] =%ld\n", temp_v_48, struct_ret_0 -> temp_ptr_s_0[temp_v_48]);
			if (temp_l_18 % struct_ret_0 -> temp_ptr_s_0[temp_v_48] != 0)	{
				temp_v_48++;
			}
			else
			{
				check_v_12 = -1;
				break;
			}
		}
/********************************************************Thread-2************************************************************/
		if(check_v_12 != -1)
			for (temp_l_19 = 1; temp_l_19 < struct_ret_0 -> temp_v_s_1 ; temp_l_19++)	{
//				printf("T-7_2:313: temp_l_18 = %ld   temp_l_19 = %ld   temp_v_49 = %ld\n", temp_l_18, temp_l_19, temp_v_49);
//				printf("T-7_2:314: temp_ptr_1[%ld] =%ld\n", temp_v_49, struct_ret_0->temp_ptr_s_1[temp_v_49]);
				if(struct_ret_0->temp_ptr_s_1[temp_v_49] != 0)	{				
					if (temp_l_18 % struct_ret_0 -> temp_ptr_s_1[temp_v_49] != 0)	{
						temp_v_49++;
					}
					else	{
							check_v_12 = -1;
							break;
					}
				}
				else	{
					check_v_12 = -1;
					break;
				}
			}
/********************************************************Thread-3************************************************************/
		if(check_v_12 != -1)
			for (temp_l_19 = 1; temp_l_19 < struct_ret_0 -> temp_v_s_2; temp_l_19++)	{
//				printf("T-7_3:332: temp_l_18 = %ld   temp_l_19 = %ld	temp_v_50 =%ld\n", temp_l_18, temp_l_19, temp_v_50);
//				printf("T-7_3:333: temp_ptr_2[%ld] =%ld\n", temp_v_50, temp_ptr_2[temp_v_50]);		
				if(struct_ret_0->temp_ptr_s_2[temp_v_50] != 0)	{
					if(temp_l_18 % struct_ret_0->temp_ptr_s_2[temp_v_50] != 0)
						temp_v_50++;
					else	{
						check_v_12 = -1;
						break;
					}
				}
				else 	{
					check_v_12 = -1;
					break;
				}
			}
/********************************************************Thread-4************************************************************/
/*		if(check_v_12 != -1)
			for (temp_l_19 = 1; temp_l_19 < struct_ret_0 -> temp_v_s_3; temp_l_19++)	{
//				printf("T-7_4:350: temp_l_18 = %ld   temp_l_19 = %ld  temp_v_51 = %ld\n", temp_l_18, temp_l_19, temp_v_51);
//				printf("T-7_4:351: temp_ptr_2[%ld] =%ld\n", temp_v_51, temp_ptr_2[temp_v_51]);		
				if(struct_ret_0->temp_ptr_s_3[temp_v_51] != 0)	{
					if(temp_l_18 % struct_ret_0->temp_ptr_s_3[temp_v_51] != 0)
						temp_v_51++;
					else	{
						check_v_12 = -1;
						break;
					}
				}
				else 	{
					check_v_12 = -1;
					break;
				}
			} */
/********************************************************Thread-5************************************************************/
/*		if(check_v_12 != -1)
			for (temp_l_19 = 1; temp_l_19 < struct_ret_0 -> temp_v_s_4; temp_l_19++)	{
//				printf("T-7_3:332: temp_l_18 = %ld   temp_l_19 = %ld	temp_v_52 =%ld\n", temp_l_18, temp_l_19, temp_v_52);
//				printf("T-7_3:333: temp_ptr_4[%ld] =%ld\n", temp_v_52, temp_ptr_4[temp_v_52]);		
				if(struct_ret_0->temp_ptr_s_4[temp_v_52] != 0)	{
					if(temp_l_18 % struct_ret_0->temp_ptr_s_4[temp_v_52] != 0)
						temp_v_52++;
					else	{
						check_v_12 = -1;
						break;
					}
				}
				else 	{
					check_v_12 = -1;
					break;
				}
			} */
/********************************************************Thread-6************************************************************/
/*		if(check_v_12 != -1)
			for (temp_l_19 = 1; temp_l_19 < struct_ret_0 -> temp_v_s_5; temp_l_19++)	{
//				printf("T-7_3:332: temp_l_18 = %ld   temp_l_19 = %ld	temp_v_53 =%ld\n", temp_l_18, temp_l_19, temp_v_53);
//				printf("T-7_3:333: temp_ptr_5[%ld] =%ld\n", temp_v_53, temp_ptr_5[temp_v_53]);		
				if(struct_ret_0->temp_ptr_s_5[temp_v_53] != 0)	{
					if(temp_l_18 % struct_ret_0->temp_ptr_s_5[temp_v_53!= 0)
						temp_v_53++;
					else	{
						check_v_12 = -1;
						break;
					}
				}
				else 	{
					check_v_12 = -1;
					break;
				}
			} */
			if (check_v_12 != -1) {
				temp_ptr_6[temp_v_41] = temp_l_18;
				struct_ret_0 -> temp_ptr_s_6 = temp_ptr_6;
				struct_ret_0 -> temp_v_s_6 = temp_v_31;
					temp_v_41++;
			}
			struct_ret_0 -> temp_ptr_s_6 = temp_ptr_6;
			struct_ret_0 -> temp_v_s_6 = temp_v_41;
	}
	struct_ret_0 -> temp_ptr_s_6 = temp_ptr_6;
	struct_ret_0 -> temp_v_s_6 = temp_v_41;
	printf("THREAD 7 final index value struct_ret_0 -> temp_v_s_6 = %ld	",struct_ret_0 -> temp_v_s_6);
	printf("temp_v_41 = %ld\n\n", temp_v_41);
	return NULL;
}



/*********************************************************************************************************/
/*************************************************delay()*************************************************/
/*********************************************************************************************************/
void delay(int ltimes)	{
/********************delay*******************/
	for(int loc_l_0 = 0; loc_l_0 < ltimes; loc_l_0++)	{
		;
	}
}
