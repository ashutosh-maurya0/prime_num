/* 0.7 */
/* main.c: main function is defined in this file
 * general structure of the PRIME NUMBER ANALYSIS
 * PROGRAM is defined here
 */

#include<string.h>
#include<stdlib.h>		/* exit() */
#include<stdio.h>		/* I/O */
#include<unistd.h>		/* syscall */
#include<fcntl.h>		/* file control options */
#include<pthread.h>
#include"main.h"
//#include"output.h"
#include"primef.h"
#include"helpf.h"

extern char *help[];
extern const int prime_arg;
extern int temp_l_4;
extern int temp_l_5;
int check_from = 0;				/* use in "form=" */
int check_to = 0;				/* use in "to=" */
char **argv[10];

int main (int argc, char *argv[])	{
/* taking out numeric from alpha numeric argument */
	char **argv_v_2 = malloc(sizeof(char **)*10);		/* allocating memory to store alpha and numeric from "argv" */
/* this piece of code execute "helpf()" */
	ret_v_0 = helpf(argv, argc);
	if(ret_v_0 == EXIT_FAILURE)	{
		printf("argc >= 2\n");
		for(temp_l_6 = 0; temp_l_6 < 2*prime_arg; temp_l_6++)
			printf("%s",help[temp_l_6]);
				exit(-1);
	}

	if(check_v_1 == 5 && check_v_3 == 3 )	{
	/* 'from=' */
		printf("\t2 => check_v_1 - %d\n",check_v_1);
		if(check_v_1 == 5)	{
			printf("\t\tFROM\t\t\n");
			printf("\t1 => argv[1] %s	temp_arr_0 - %s\n",argv[1],temp_arr_0);
			check_v_1 = 0;											
			temp_l_4 = 0;											
			printf("\t1 => check_v_0 - %d\n",check_v_1);
			printf("\t1 => temp_arr_0 - %s\n",temp_arr_0);
			printf("\t2 => argv[1] - %s\n",argv[1]);
				/* "from=" into temp_arr_0[temp_l_4] */
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
					printf(ANSI_COLOR_RED "error:" ANSI_COLOR_RESET);
					printf("\"from=\" is signed integer.\nplease enter unsigned integer ex: 3, 45435, 45345, 433543\n");
						exit(EXIT_FAILURE);
				}
				printf("\t1 => argv_v_2[0] - %s	temp_v_2 - %ld\n",argv_v_2[0],temp_v_2);
				argv[1] = temp_arr_0;								/* updating the argv[1] */
				if(temp_v_2 == 0)	{
					printf(ANSI_COLOR_RED "error: " ANSI_COLOR_RESET "from= : missing number\n");
						exit(EXIT_FAILURE);
				}
				if(temp_v_2 < 2) {
					printf(ANSI_COLOR_RED "error: " ANSI_COLOR_RESET "from= : less than 2 must be greater than or equal to 2\n");
						exit(EXIT_FAILURE);
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
				temp_l_5 = 0;									
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
					printf(ANSI_COLOR_RED "error:" ANSI_COLOR_RESET);
					printf("\"to=\" is signed integer.\nplease enter unsigned integer ex: 11, 45435, 45345, 433543\n");
						exit(EXIT_FAILURE);
				}
				printf("\t1 => argv_v_2[1] - %s	temp_v_3 - %ld\n",argv_v_2[1],temp_v_3);
				argv[2] = temp_arr_1;								/* updating the argv[2] */
				if(temp_v_3 == 0)	{
					printf(ANSI_COLOR_RED "error:" ANSI_COLOR_RESET "to= : missing number\n");
						exit(EXIT_FAILURE);
				}
				/* compare from= to= */
				if(temp_v_2 > temp_v_3)		{
					printf(ANSI_COLOR_RED "error:" ANSI_COLOR_RESET);
					printf("\tfrom=%ld is greater then to=%ld\n",temp_v_2,temp_v_3);
					printf("\tfrom= cann't be greater then to=\n");
						exit(EXIT_FAILURE);
				}
				if(temp_v_3 < 11) {
					printf(ANSI_COLOR_RED "error:" ANSI_COLOR_RESET "\tto= : less than 11 must be greater than or equal to 11\n");
						exit(EXIT_FAILURE);
				}
			check_to = 1;
			}
		printf("\tcheck_to - %d\n",check_to);
		printf("\n\targv[1] - %s		argv[2] - %s\n\n",argv[1], argv[2]);

	}

/* allocating memory for storing prime numbers */
	struct_ret_0 = malloc(sizeof(struct_ptr));
	if(!struct_ret_0)	{
		printf("main.c:malloc 1 failled to assign memory\n");
			exit(EXIT_FAILURE);
	}
	temp_ret = malloc(sizeof(u_int64_t)*2);
	if(!temp_ret)	{
		printf("main.c:malloc 2 failled to assign memory\n");
			exit(EXIT_FAILURE);
	}

/* "temp_ptr_0" */
	if(temp_v_3 > 100)
		how_much_mem = (20*temp_v_3)/200;
	else
		how_much_mem = (20*temp_v_3);

	printf("how_much_mem %d - %ld\n",how_much_mem,sizeof(u_int64_t)*how_much_mem);
	temp_ptr_0 = calloc(temp_v_3/2,sizeof(u_int64_t));
	if(!temp_ptr_0)	{
		printf("main.c:calloc 1st failled to assign memory\n");
			exit(EXIT_FAILURE);
	}
	temp_ptr_1 = calloc(temp_v_3/2,sizeof(u_int64_t));
	if(!temp_ptr_1)	{
		printf("main.c:calloc 2nd failled to assign memory\n");
			exit(EXIT_FAILURE);
	}
	temp_ptr_2 = calloc(temp_v_3/2,sizeof(u_int64_t));
	if(!temp_ptr_2)	{
		printf("main.c:calloc 3nd failled to assign memory\n");
			exit(EXIT_FAILURE);
	}
	temp_ptr_3 = calloc(temp_v_3/2,sizeof(u_int64_t));
	if(!temp_ptr_3)	{
		printf("main.c:calloc 4th failled to assign memory\n");
			exit(EXIT_FAILURE);
	}
	temp_ptr_4 = calloc(temp_v_3/2,sizeof(u_int64_t));
	if(!temp_ptr_4)	{
		printf("main.c:calloc 5th failed to assign memory\n");
			exit(EXIT_FAILURE);	
	}

	struct_ret_0->temp_ptr_s_0 = temp_ptr_0;
	struct_ret_0->temp_ptr_s_1 = temp_ptr_1;
	struct_ret_0->temp_ptr_s_2 = temp_ptr_2;
	struct_ret_0->temp_ptr_s_3 = temp_ptr_3;
	struct_ret_0->temp_ptr_s_4 = temp_ptr_4;

	struct_ret_0 -> temp_v_s_0 = 0;
	struct_ret_0 -> temp_v_s_1 = 0;
	struct_ret_0 -> temp_v_s_2 = 0 ;
	struct_ret_0 -> temp_v_s_3 = 0;
	struct_ret_0 -> temp_v_s_4 = 0;

	tstruct_0.chk_st.chk_s_v_0 = -1;
	tstruct_0.chk_st.chk_s_v_1 = -1;
	tstruct_0.chk_st.chk_s_v_2 = -1;
	tstruct_0.chk_st.chk_s_v_3 = -1;
	tstruct_0.chk_st.chk_s_v_4 = -1;

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
/**************************************** Thread 1 start from here **************************************/
								tstruct_0.from_num = temp_v_2;
								tstruct_0.to_num = ((20*temp_v_3)/100);
								pret_0 = pthread_create(&thread[0], NULL, primef1, &tstruct_0);
/**************************************** Thread 2 start from here **************************************/							
								tstruct_0.from_num_1 = tstruct_0.to_num +1;
								tstruct_0.to_num_1 = ((15*temp_v_3)/100)+tstruct_0.to_num;							
								pret_1 = pthread_create(&thread[1], NULL, primef2, &tstruct_0);
/**************************************** Thread 3 start from here **************************************/
								tstruct_0.from_num_2 = tstruct_0.to_num_1 +1;
								tstruct_0.to_num_2 = ((22*temp_v_3)/100)+tstruct_0.to_num_1;
								pret_2 = pthread_create(&thread[2], NULL, primef3, &tstruct_0);
/**************************************** Thread 4 start from here **************************************/
								tstruct_0.from_num_3 = tstruct_0.to_num_2 +1;
								tstruct_0.to_num_3 = ((22*temp_v_3)/100)+tstruct_0.to_num_2;
								pret_3 = pthread_create(&thread[3], NULL, primef4, &tstruct_0); 
/**************************************** Thread 5 start from here ********************************************/							
								tstruct_0.from_num_4 = tstruct_0.to_num_3 +1;
								tstruct_0.to_num_4 = temp_v_3;
								pret_4 = pthread_create(&thread[4], NULL, primef5, &tstruct_0);

/**************************************** Joining all created threads to main rouitine ******************************/
								pthread_join(thread[0], NULL);
								pthread_join(thread[1], NULL);
								pthread_join(thread[2], NULL);
								pthread_join(thread[3], NULL); 
								pthread_join(thread[4], NULL);

/*************************************** Thread 1 printing start from here ******************************************/
//							for(temp_l_7 = 1; temp_l_7 < struct_ret_0 -> temp_v_s_0+1; temp_l_7++)
//								printf("%ld - prime_num %ld\n",temp_l_7,struct_ret_0 -> temp_ptr_s_0[temp_l_7]);
							printf("TOTAL PRIME_1 - %ld\n\n",struct_ret_0 -> temp_v_s_0);
							check_v_2 = 2;

/************************************** Thread 2 printing start from here *******************************************/
//							for(temp_l_7 = 0; temp_l_7 < struct_ret_0 -> temp_v_s_1; temp_l_7++)
//								printf("%ld - prime_num %ld\n",1+temp_l_7+struct_ret_0->temp_v_s_0,struct_ret_0 -> temp_ptr_s_1[temp_l_7]);
							printf("TOTAL PRIME_2 - %ld\n\n",struct_ret_0 -> temp_v_s_1);
							check_v_2 = 2;

/************************************* Thread 3 printing start from here ********************************************/
//							for(temp_l_7 = 0; temp_l_7 < struct_ret_0 -> temp_v_s_2; temp_l_7++)
//								printf("%ld - prime_num %ld\n",1+temp_l_7+struct_ret_0->temp_v_s_0+struct_ret_0->temp_v_s_1,struct_ret_0 -> temp_ptr_s_2[temp_l_7]);
							printf("TOTAL PRIME_3 - %ld\n\n",struct_ret_0 -> temp_v_s_2);
							check_v_2 = 2;

/************************************ Thread 4 printing start from here ********************************************/
//							for(temp_l_7 = 0; temp_l_7 < struct_ret_0 -> temp_v_s_3; temp_l_7++)
//								printf("%ld - prime_num %ld\n",1+temp_l_7+struct_ret_0->temp_v_s_0+struct_ret_0->temp_v_s_1+struct_ret_0->temp_v_s_2,struct_ret_0 -> temp_ptr_s_3[temp_l_7]);						
							printf("TOTAL PRIME_4 - %ld\n\n",struct_ret_0 -> temp_v_s_3);
							check_v_2 = 2;

/************************************ Thread 5 printing start from here *********************************************/												
//							for(temp_l_7 = 0; temp_l_7 < struct_ret_0 -> temp_v_s_4; temp_l_7++)
//								printf("%ld - prime_num %ld\n",1+temp_l_7+struct_ret_0->temp_v_s_0+struct_ret_0->temp_v_s_1+struct_ret_0->temp_v_s_2+struct_ret_0->temp_v_s_3,temp_ptr_4[temp_l_7]);							
							printf("TOTAL PRIME_5 - %ld\n\n",struct_ret_0 -> temp_v_s_4);
							check_v_2 = 2;

							printf("TOTAL PRIME_1 - %ld\n",struct_ret_0 -> temp_v_s_0);
							printf("TOTAL PRIME_2 - %ld\n",struct_ret_0 -> temp_v_s_1);
							printf("TOTAL PRIME_3 - %ld\n",struct_ret_0 -> temp_v_s_2);
							printf("TOTAL PRIME_4 - %ld\n",struct_ret_0 -> temp_v_s_3);
							printf("TOTAL PRIME_5 - %ld\n",struct_ret_0 -> temp_v_s_4);
					
							printf("\nTOTAL PRIME - %ld",struct_ret_0->temp_v_s_4+struct_ret_0->temp_v_s_3+struct_ret_0 -> temp_v_s_2+struct_ret_0->temp_v_s_1+struct_ret_0->temp_v_s_0);
							check_v_2 = 2; 
							goto EXIT;
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
				exit(EXIT_FAILURE);
		}
		temp_v_4 = 3;
		inc_v_1 = 1;
		/* calling "primef()" */
		//struct_ptr *struct_ret_0 = primef(&temp_v_4, &temp_v_2);
			for(temp_l_7 = 1; temp_ptr_0[temp_l_7] < temp_v_2 ; temp_l_7++)	{
					if(!temp_ptr_0[temp_l_7])
						break;
					if(temp_ptr_0[temp_l_7] > temp_v_2)
						break;
					printf("%ld - rime_num %ld\n",temp_l_7,temp_ptr_0[temp_l_7]); inc_v_1 = temp_l_7;
			}
		struct_ret_0 -> from_num = temp_v_2;
		struct_ret_0 -> to_num = temp_v_3;
		struct_ret_0 -> location_in_allo_mem = struct_ret_0 -> temp_v_s_0;
		/* calling "primef_struct()" */
		printf("\nbefore => struct_ret_0 -> from_num 		 - %ld\n", struct_ret_0 -> from_num);
		printf("before => struct_ret_0 -> to_num     		 - %ld\n",struct_ret_0 -> to_num);
		printf("before => struct_ret_0 -> temp_v_s_0 		 - %ld\n",struct_ret_0 -> temp_v_s_0);
		printf("before => struct_ret_0 -> location_in_allo_mem 	 - %ld\n\n",struct_ret_0 -> location_in_allo_mem);
		primef_struct(struct_ret_0);
		printf("\n\nafter => struct_ret_0 -> from_num   		 - %ld\n", struct_ret_0 -> from_num);
		printf("after => struct_ret_0 -> to_num  		 - %ld\n",struct_ret_0 -> to_num);
		printf("after => struct_ret_0 -> temp_v_s_0  		 - %ld\n",struct_ret_0 -> temp_v_s_0);
		printf("after => struct_ret_0 -> location_in_allo_mem  	 - %ld\n\n",struct_ret_0 -> location_in_allo_mem);

	/* printing prime numbers */
		/* when "temp_ptr_0[]" last element equal to "from=" */
		if(temp_ptr_0[struct_ret_0 -> location_in_allo_mem] == temp_v_2)	{
			for(temp_l_7 = struct_ret_0 -> location_in_allo_mem; temp_l_7 <= struct_ret_0 -> temp_v_s_0; temp_l_7++)
				if(temp_ptr_0[temp_l_7] >= temp_v_2 && temp_ptr_0[temp_l_7] <= temp_v_3)
					printf("%d - prime_num %ld\n",inc_v_1+++1, temp_ptr_0[temp_l_7]);
			printf("\n1 - TOTAL PRIME - %ld\n\n",struct_ret_0 -> temp_v_s_0 - struct_ret_0 -> location_in_allo_mem+1);
			goto EXIT;
		}
		/* when "temp_v_s_0 - location_in_allo_mem" equal to 2 */
		else if(struct_ret_0 -> temp_v_s_0 - struct_ret_0 -> location_in_allo_mem == 2)
		 {
			for(temp_l_7 = struct_ret_0 -> location_in_allo_mem+1; temp_l_7 <= struct_ret_0 -> temp_v_s_0; temp_l_7++)
				if(temp_ptr_0[temp_l_7] >= temp_v_2 && temp_ptr_0[temp_l_7] <= temp_v_3)
					printf("%d - prime_num %ld\n",inc_v_1+++1, temp_ptr_0[temp_l_7]);
			printf("\n2 - TOTAL PRIME - %ld\n\n",struct_ret_0 -> temp_v_s_0 - struct_ret_0 -> location_in_allo_mem);
			goto EXIT;
		}
		/* when "temp_v_s_0" equal to "location_in_allo_mem" */
		else if(struct_ret_0 -> temp_v_s_0 == struct_ret_0 -> location_in_allo_mem)
		 {
			for(temp_l_7 = struct_ret_0 -> location_in_allo_mem; temp_l_7 <= struct_ret_0 -> temp_v_s_0; temp_l_7++)   {
				if(temp_ptr_0[temp_l_7] >= temp_v_2 && temp_ptr_0[temp_l_7] <= temp_v_3)
					printf("%d - prime_num %ld\n",inc_v_1++, temp_ptr_0[temp_l_7]);
			}
			printf("\n3 - TOTAL PRIME - %ld\n\n",struct_ret_0 -> temp_v_s_0 - struct_ret_0 -> location_in_allo_mem);
			goto EXIT;
		 }
		/* when "temp_v_s_0 - location_in_allo_mem" equal to 1 */
		else if(struct_ret_0 -> temp_v_s_0 - struct_ret_0 -> location_in_allo_mem == 1)
		  {
			for(temp_l_7 = struct_ret_0 -> location_in_allo_mem; temp_l_7 <= struct_ret_0 -> temp_v_s_0+1; temp_l_7++)
				if(temp_ptr_0[temp_l_7] >= temp_v_2 && temp_ptr_0[temp_l_7] <= temp_v_3)
					printf("%d - prime_num %ld\n",inc_v_1+++1, temp_ptr_0[temp_l_7]);
			printf("\n4 - TOTAL PRIME - %ld\n\n",struct_ret_0 -> temp_v_s_0 - struct_ret_0 -> location_in_allo_mem);
			goto EXIT;
		  }
		/* when all the above condition get false */
		for(temp_l_7 = struct_ret_0 -> location_in_allo_mem; temp_l_7 <= struct_ret_0 -> temp_v_s_0+1; temp_l_7++)
			if(temp_ptr_0[temp_l_7] >= temp_v_2 && temp_ptr_0[temp_l_7] <= temp_v_3)
					printf("%d - prime_num %ld\n",inc_v_1+++1, temp_ptr_0[temp_l_7]);
			printf("\n5 - TOTAL PRIME - %ld\n\n",struct_ret_0 -> temp_v_s_0 - struct_ret_0 -> location_in_allo_mem);
			goto EXIT;
	}

EXIT:
	printf("\b");
/* output function all output related things done by this function */
	if(argc >= 4 )	{
		int ret  = output(argc, argv, struct_ret_0);
			if (ret == -1)	{
				perror("output:");
					exit(EXIT_FAILURE);
			}
	}
	return EXIT_SUCCESS;
}
