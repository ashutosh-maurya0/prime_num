/* 0.7 */
/* helpf.c: This file conatin helpf() 
 * definition
 */

int helpf(char *argv_v_0[], int argc)	{
	char **argv_v_1 = malloc(sizeof(char **)*100);	
	check_v_5 = 0;
	inc_v_0 = 0;
	check_v_4 = 0;
	/* when to print "help()" */
	/* this piece of code execute only when program call without any argument */	
	if(argc == 1)	{
//		printf("argc == 1\n");
		printf(ANSI_COLOR_RED   "\033[1merror:\033[0m"   ANSI_COLOR_RESET);
		printf("from= to= argument must pass\n");
		for(temp_l_6 = 0; temp_l_6 < 2*prime_arg; temp_l_6++)
				printf("%s",help[temp_l_6]);
		exit(1);
	}
	/* this piece of code execute when "--help" argument passed */	
	if(argc == 2)	{	
		if(strcmp(argv_v_0[1],help[4]) == 0) {
//			printf("argc == 2\n");
			for(temp_l_6 = 0; temp_l_6 < 2*prime_arg; temp_l_6++)
				printf("%s",help[temp_l_6]);
			exit(1);						
		}
	}

	if(argc >= 3)	{	
		/* from */
		check_v_1 = 0;
		temp_l_4 = 0;
		while(temp_l_4 <=4)	{
			if(*(argv_v_0[1]+temp_l_4) == *(help[12]+temp_l_4))	{
				check_v_1++;
			}
			else
			 {
				printf(ANSI_COLOR_RED   "\033[1m\nerror_from:\033[0m"   ANSI_COLOR_RESET);
				printf(": invalid argument %s\n\n",argv_v_0[1]);
				break;
			 }
			temp_l_4++;
		}
//		printf("\t1 => check_v_1 - %d\n",check_v_1);
	
		/* to */
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
					exit(1);
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

	if(check_v_1 == 5 && check_v_3 == 3)	{	
		if(argc > 3)
			for(temp_l_2 = 3; temp_l_2 < argc; temp_l_2 += 2)	{
	//			printf("temp_l_2 - %d\n", temp_l_2);
				for(temp_l_3 = 2; temp_l_3 < prime_arg; temp_l_3++)	{
					if(temp_l_3*2 == 12 || temp_l_3*2 == 14)	{
						continue;	
					}
	//				printf("temp_l_2 - %d	temp_l_3 - %d 	argv_v_0[%d] - %s   help[%d] - %s\n",temp_l_2,temp_l_3,temp_l_2, argv_v_0[temp_l_2], temp_l_3, help[2*temp_l_3]);	
					if(strcmp(argv_v_0[temp_l_2],help[2*temp_l_3]) == 0)	{
						argv_v_1[inc_v_0] = argv_v_0[temp_l_2];
						inc_v_0++;
						check_v_4++;
						break;
					}		
				}
	//			printf("temp_l_3 - %d\n", temp_l_3);
	//			printf("argv_v_0[%d]	  -	%s\n",temp_l_2, argv_v_0[temp_l_2]);
				if(check_v_4 == 0)	{
					printf(ANSI_COLOR_RED   "\033[1mfatal error:\033[0m"   ANSI_COLOR_RESET);
					printf("invalid argument %s\n", argv_v_0[temp_l_2]);
					argv_v_1[inc_v_0] = "z";	
					check_v_4 = 0;
					check_v_5 = 1;
					}
				check_v_4 = 0;
			}
	}	
	if(check_v_5 == 1)
		return EXIT_FAILURE;		
	free(argv_v_1);	
	return EXIT_SUCCESS;
}
