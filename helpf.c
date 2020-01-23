/************ 0.7 ***********/
/* helpf.c: This file conatin helpf()
 * definition
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"	
#include"helpf.h"

char *help[] = {"\nusages: prime [from= to=] -o [filename] [options]\n", "",
		"options\n", 	"",
		"--help",	"\t\tlist all the aruments.\n",
		"-diff",	"\t\tdifference between consecutive prime numbers.\n",
		"-i",		"\t\tinterval\n",
		"-o",		"\t\twhere you want output of program.\n",
		"from=",	"\t\tfrom=number replace \"number\" with numeric.\n",
		"to=",       "\t\tto=number replace \"number\" with numeric.\n",
		"-r_dec",	"\t\trate of decreasing prime number.\n",
		"-r_inc",	"\t\trate of increasing prime number.\n",
		"-d",		"\t\tdigit\n",
		"-m",         "\t\tmanually input file load prime number.\n\t\tThis argument must run with from= to= argument\n",
		"-j",		 "\t\tnumber of jobs\n"};

const int prime_arg=13;					/* number of valid arguments can be passed */

int helpf(char *argv_v_0[], int argc)	{
	char **argv_v_1 = malloc(sizeof(char **)*1024);
	check_v_5 = 0;					/* helpf.h 15 */
	inc_v_0 = 0;						/* helpf.h 13 */
	check_v_4 = 0;					/* helpf.h 14 */
	/* when to print "help()" */
	/* this piece of code execute only when program call without any argument */
	if(argc == 1)	{
		printf("argc == 1\n");
		printf(ANSI_COLOR_RED   "\033[1merror:\033[0m"   ANSI_COLOR_RESET);
		printf("from= to= argument must be passed\n");
		for(temp_l_6 = 0; temp_l_6 < 2*prime_arg; temp_l_6++)
			printf("%s",help[temp_l_6]);
		exit(1);
	}
	/* this piece of code execute when "--help" argument passed */
	if(argc == 2)	{
		if(strcmp(argv_v_0[1],help[4]) == 0) {
			printf("argc == 2\n");
			for(temp_l_6 = 0; temp_l_6 < 2*prime_arg; temp_l_6++)
				printf("%s",help[temp_l_6]);
			exit(1);
		}
	}

/*********** from ***********/
	if(argc >= 3)	{
		check_v_1 = 0;						/* main.h 39 */
		temp_l_4 = 0;						/* main.h 35 */
		while(temp_l_4 <=4)	{
			if(*(argv_v_0[1]+temp_l_4) == *(help[12]+temp_l_4))	{
				check_v_1++;				/* main.h 39 */
			}
			else
			 {
				printf(ANSI_COLOR_RED   "\033[1m\nerror_from:\033[0m"   ANSI_COLOR_RESET);
				printf(": invalid argument %s\n\n",argv_v_0[1]);
				exit(EXIT_FAILURE);
			 }
			temp_l_4++;						/* helpf.h 11 */
		}
		printf("\t1 => check_v_1 - %d\n",check_v_1);

/************ to ************/
		check_v_3 = 0;						
		temp_l_5 = 0;						
		if(argc >= 3)	{
			while(temp_l_5 <=2)	{
				if(*(argv_v_0[2]+temp_l_5) == *(help[14]+temp_l_5))
					check_v_3++;
				else
				 {
					printf(ANSI_COLOR_RED   "\033[1m\nerror_to:\033[0m"   ANSI_COLOR_RESET);
					printf("invalid argument %s\n\n",argv_v_0[2]);
					exit(EXIT_FAILURE);
				 }
				temp_l_5++;					
			}
		}
/************ -j ************/
		check_v_6 = 0;						
		temp_l_5 = 0;						
		if(argc > 3)	{
			while(temp_l_5 <=1)	{
				if(*(argv_v_0[3]+temp_l_5) == *(help[24]+temp_l_5))
					check_v_6++;
				else
				 {
					printf(ANSI_COLOR_RED   "\033[1m\nerror_to:\033[0m"   ANSI_COLOR_RESET);
					printf("invalid argument %s\n\n",argv_v_0[3]);
					exit(EXIT_FAILURE);
				 }
				temp_l_5++;	
			}
		}
//		printf("\t3 => check_v_3 - %d\n",check_v_3);
	}
	else
	  {
		printf("\"from= to=\" argument must pass\n");
		printf("type \"--help\" for more detail\n");
	  }
	
	if(check_v_1 == 5 && check_v_3 == 3 && check_v_6 == 2)	{
		if(argc >= 3)
			for(temp_l_2 = 3; temp_l_2 < argc; temp_l_2 += 2)	{
				printf("temp_l_2 - %d\n", temp_l_2);
				for(temp_l_3 = 2; temp_l_3 < prime_arg; temp_l_3++)	{
					if(temp_l_3*2 == 12 || temp_l_3*2 == 14 || temp_l_3*2 == 24) {printf("invalid\n");
						continue; }
					printf("temp_l_2 - %d	temp_l_3 - %d 	argv_v_0[%d] - %s   help[%d] - %s\n",temp_l_2,temp_l_3,temp_l_2, argv_v_0[temp_l_2], temp_l_3, help[2*temp_l_3]);	
					if(strcmp(argv_v_0[temp_l_2],help[2*temp_l_3]) == 0)	{
						argv_v_1[inc_v_0] = argv_v_0[temp_l_2];	printf("invalid\n");
						inc_v_0++;						/* helpf.h 13 */
						check_v_4++;					/* helpf.h 14 */
						break;
					}
				}
				printf("temp_l_3 - %d\n", temp_l_3);
				printf("argv_v_0[%d]	  -	%s\n",temp_l_2, argv_v_0[temp_l_2]);
				if(check_v_4 == 0)	{					/* helpf.h 14 */
					printf(ANSI_COLOR_RED   "\033[1mfatal error:\033[0m"   ANSI_COLOR_RESET);
					printf("invalid argument %s\n", argv_v_0[temp_l_2]);
					argv_v_1[inc_v_0] = NULL;
					check_v_4 = 0;
					check_v_5 = 1;
					}
				check_v_4 = 0;							/* helpf.h 14 */
			}
	}
	if(check_v_5 == 1)									/* helpf.h 15 */
		return EXIT_FAILURE;
	free(argv_v_1);
	return EXIT_SUCCESS;
}
