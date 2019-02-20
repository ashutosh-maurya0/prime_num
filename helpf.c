/* helpf.c: This file conatin helpf() 
 * definition
 */

int helpf(char *argv_v_0[], int argc)	{
	char **argv_v_1 = malloc(sizeof(char **)*100);	
	check_v_5 = 0;
	inc_v_0 = 0;
	check_v_4 = 0;
	
	for(temp_l_2 = 3; temp_l_2 < argc; temp_l_2 += 2)	{
//		printf("temp_l_2 - %d\n", temp_l_2);
		for(temp_l_3 = 2; temp_l_3 < prime_arg; temp_l_3++)	{
			if(temp_l_3*2 == 12 || temp_l_3*2 == 14)	{
				continue;	
			}
//			printf("temp_l_2 - %d	temp_l_3 - %d 	argv_v_0[%d] - %s   help[%d] - %s\n",temp_l_2,temp_l_3,temp_l_2, argv_v_0[temp_l_2], temp_l_3, help[2*temp_l_3]);	
			if(strcmp(argv_v_0[temp_l_2],help[2*temp_l_3]) == 0)	{
				argv_v_1[inc_v_0] = argv_v_0[temp_l_2];
				inc_v_0++;
				check_v_4++;
				break;
			}		
		}
//		printf("temp_l_3 - %d\n", temp_l_3);
//		printf("argv_v_0[%d]	  -	%s\n",temp_l_2, argv_v_0[temp_l_2]);
		if(check_v_4 == 0)	{
			printf("help() invalid argument: %s\n", argv_v_0[temp_l_2]);
			argv_v_1[inc_v_0] = "z";	
			check_v_4 = 0;
			check_v_5 = 1;
			}
		check_v_4 = 0;
	}
	
	if(check_v_5 == 1)
		return EXIT_FAILURE;
	
		
	free(argv_v_1);	
	return EXIT_SUCCESS;
}
