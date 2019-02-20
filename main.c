/* 0.6 */
/* main.c: main function is defined in this file 
 * general structure of the PRIME NUMBER ANALYSIS 
 * PROGRAM is defined here 
 */

#include"variables.h"		/* variables and function prototype */
#include<string.h>
#include<stdlib.h>		/* exit() */
#include<stdio.h>		/* I/O */
#include<unistd.h>		/* syscall */
#include<fcntl.h>		/* file control options */
#include"primef.c"		/* primef() */
#include"helpf.c"		/* helpf() */
#include"primef_struct.c"	/* primef_struct() */

char **argv[10];
int main (int argc, char *argv[])	{
/* taking out numeric from alpha numeric argument */
	char **argv_v_2 = malloc(sizeof(char **)*10);							/* allocating memory to store alpha and numeric from "argv" */	
				

/* this piece of code execute "helpf()" */
	ret_v_0 = helpf(argv, argc);
	if(ret_v_0 == EXIT_FAILURE)	{
		printf("argc >= 2\n");
		for(temp_l_6 = 0; temp_l_6 < 2*prime_arg; temp_l_6++)
			printf("%s",help[temp_l_6]);	
				exit(1);
	}

	if(check_v_1 == 5 && check_v_3 == 3 )	{	
	/* 'from=' */
		printf("\t2 => check_v_1 - %d\n",check_v_1);
		if(check_v_1 == 5)	{
			printf("\t\tFROM\t\t\n");
			printf("\t1 => argv[1] %s	temp_arr_0 - %s\n",argv[1],temp_arr_0);	
			check_v_1 = 0;										/* see in variables.h */
			temp_l_4 = 0;										/* see in variables.h */
			printf("\t1 => check_v_0 - %d\n",check_v_1);
			printf("\t1 => temp_arr_0 - %s\n",temp_arr_0);
			printf("\t2 => argv[1] - %s\n",argv[1]);				
				/* "from=" into temp_arr_0[temp_l_4] */		
				temp_arr_0[5];									/* see in variables.h */
				temp_l_4 = 0;		
				while(temp_l_4 <= 4)	{
					temp_arr_0 [temp_l_4] = *(argv[1]+temp_l_4);	
					temp_l_4++;
				}
				/* taking out number */
				argv_v_2[0] = &(*(argv[1]+5));
				temp_v_2 = atoi(argv_v_2[0]); 							/* assigning "from=num" to "temp_v_2" */
				/* if "temp_v_3" signed */
				int temp_v = temp_v_2;
				if(temp_v < 0)	{
					printf("\"from=\" is signed integer.\nplease enter unsigned integer ex: 3, 45435, 45345, 433543\n\n");
						exit(1);
				} 
				printf("\t1 => argv_v_2[0] - %s	temp_v_2 - %ld\n",argv_v_2[0],temp_v_2);			
				argv[1] = temp_arr_0;								/* updating the argv[1] */
				if(temp_v_2 == 0)	{
					printf("from= : missing number\n");
						exit(1);
				}
				if(temp_v_2 < 2) {
					printf("from= : less than 2 must be greater than or equal to 2\n");
						exit(1);
				}
				check_from = 1;	
			}
		printf("\tcheck_from - %d\n",check_from);

	/* 'to=' */
		printf("\t2 => check_v_3 %d\n",check_v_3);										
		if(check_v_3 == 3)	{
			printf("\n\t\tTO\t\t\n");
			printf("\t1 => argv[2] - %s	temp_arr_1 - %s\n",argv[2],temp_arr_1);
			printf("\t1 => check_v_3 %d\n",check_v_3);
			printf("\t1 => temp_arr_1 %s\n",temp_arr_1);
			printf("\t2 => argv[2] %s\n",argv[2]);				
	
				/* "to=" into temp_arr_1[temp_l_5] */	
				temp_arr_1[2];									/* see in variables.h */
				temp_l_5 = 0;									/* see in variables.h */
				while(temp_l_5 <= 2)	{
					temp_arr_1[temp_l_5] = *(argv[2]+temp_l_5);
					temp_l_5++;
				}		
				/* taking out number */
				argv_v_2[1] = &(*(argv[2]+3));
				temp_v_3 = atoi(argv_v_2[1]);
				/* if "temp_v_3" signed */
					int temp_v = temp_v_3;
				if(temp_v < 0)	{
					printf("\"to=\" is signed integer.\nplease enter unsigned integer ex: 11, 45435, 45345, 433543\n\n");
						exit(1);
				}
				printf("\t1 => argv_v_2[1] - %s	temp_v_3 - %ld\n",argv_v_2[1],temp_v_3);			
				argv[2] = temp_arr_1;								/* updating the argv[2] */
				if(temp_v_3 == 0)	{
					printf("to= : missing number\n");
						exit(1);
				}			
				/* compare from= to= */
				if(temp_v_2 > temp_v_3)		{
					printf("\tfrom=%ld is greater then to=%ld\n",temp_v_2,temp_v_3);
					printf("\tfrom= cann't be greater then to=\n\n");
						exit(1);
				}
				if(temp_v_3 < 11) {
					printf("\tto= : less than 11 must be greater than or equal to 11\n\n");
						exit(1);
				}
			check_to = 1;	
			}
		printf("\tcheck_to - %d\n",check_to);
		printf("\n\targv[1] - %s		argv[2] - %s\n\n",argv[1], argv[2]);			
			
	}

/* allocating buffer for storing prime numbers */
	st_ret = malloc(sizeof(struct_ptr));
	if(!st_ret)	{
		printf("main.c:malloc 1 failled to assign memory\n");
			exit(1);
	}
	temp_ret = malloc(sizeof(u_int64_t)*2);
	if(!temp_ret)	{
		printf("main.c:malloc 2 failled to assign memory\n");
			exit(1);
	}

	/* "temp_ptr" */	
	if(temp_v_3 > 100)
		how_much_mem = (20*temp_v_3)/200;
	else
		how_much_mem = (20*temp_v_3);

	printf("how_much_mem %d - %ld\n",how_much_mem,sizeof(u_int64_t)*how_much_mem);
	temp_ptr = calloc(temp_v_3,sizeof(u_int64_t));
	if(!temp_ptr)	{
		printf("main.c:calloc failled to assign memory\n");
			exit(1);
	}

/* whether  to call primef() or not */
	/* this piece of code execute only when "from= >= 2 && from= <= 7" */
	if(check_from == 1 && check_to == 1)	
		if(temp_v_2 >=2 && temp_v_2 <= 7)	{ 
			check_v_2 = 0; 
			for(temp_l_6 = 0; temp_l_6 < prime_arg; temp_l_6++)	{
				if(strcmp(argv[temp_l_6],help[12]) == 0)	{
					check_v_2 = 1;
					for(temp_l_6 = 0; temp_l_6 < prime_arg; temp_l_6++)	{
						if(strcmp(argv[temp_l_6],help[14]) == 0)	{
							/* geting return from primef() */
							struct_ptr *st_ret = primef(&temp_v_2, &temp_v_3);	
							/* printing the prime number */
							for(temp_l_7 = 0; temp_l_7 < st_ret -> temp_v_s_0+1; temp_l_7++)
								printf("%ld - prime_num %ld\n",temp_l_7+1,st_ret -> temp_ptr_s_0[temp_l_7]);
							printf("\nTOTAL PRIME - %ld\n",st_ret -> temp_v_s_0);
							check_v_2 = 2;
							free(temp_ptr);
							free(st_ret);
							exit(1); 							
						}
					}
				}
			}
		}
/* this piece of code execute only when "from= >= 8" */		
	if(check_from == 1 && check_to == 1)	{
		/* if "from= equal to to=" */
		if(temp_v_2 == temp_v_3)	{
			printf("fuck you \"from=\" equal to \"to=\"\n");
				exit(1);
		}
		temp_v_4 = 3;
		inc_v_1 = 1;
		/* calling "primef()" */	
		struct_ptr *st_ret = primef(&temp_v_4, &temp_v_2);
			for(temp_l_7 = 0; temp_l_7 < st_ret -> temp_v_s_0+1; temp_l_7++)
				printf("%ld - prime_num %ld\n",temp_l_7+1,temp_ptr[temp_l_7]);
		st_ret -> from_num = temp_v_2;
		st_ret -> to_num = temp_v_3;
		st_ret -> location_in_allo_mem = st_ret -> temp_v_s_0;
		/* calling "primef_struct()" */
//		printf("\nbefore => st_ret -> from_num 		 - %ld\n", st_ret -> from_num);
//		printf("before => st_ret -> to_num     		 - %ld\n",st_ret -> to_num);	
//		printf("before => st_ret -> temp_v_s_0 		 - %ld\n",st_ret -> temp_v_s_0);
//		printf("before => st_ret -> location_in_allo_mem - %ld\n\n",st_ret -> location_in_allo_mem);
		primef_struct(st_ret);
//		printf("\n\nafter => st_ret -> from_num   		 - %ld\n", st_ret -> from_num);
//		printf("after => st_ret -> to_num  		 - %ld\n",st_ret -> to_num);	
//		printf("after => st_ret -> temp_v_s_0  		 - %ld\n",st_ret -> temp_v_s_0);
//		printf("after => st_ret -> location_in_allo_mem  - %ld\n\n",st_ret -> location_in_allo_mem);		
		/* printing prime numbers */		
		if(temp_v_2 > 10)	{
			for(temp_l_7 = st_ret -> location_in_allo_mem+1; temp_l_7 < st_ret -> temp_v_s_0+1; temp_l_7++)
				printf("%d - pprime_num %ld\n",inc_v_1++, temp_ptr[temp_l_7]);
			printf("\nTOTAL PRIME - %ld\n",st_ret -> temp_v_s_0 - st_ret -> location_in_allo_mem);
		}		
		else
		 {
			for(temp_l_7 = st_ret -> location_in_allo_mem+1; temp_l_7 < st_ret -> temp_v_s_0+1; temp_l_7++)
				printf("%d - prime_num %ld\n",inc_v_1++, temp_ptr[temp_l_7]);
			printf("\nTOTAL PRIME - %ld\n",st_ret -> temp_v_s_0 - st_ret -> location_in_allo_mem+1);		
		 }
	free(temp_ptr);
	free(st_ret);	
	}
}
