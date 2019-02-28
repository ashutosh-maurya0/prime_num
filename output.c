/*                             0.7 				  */
/* output.c: this function deals with all the output 
 * on success this funtion return "0" and on 
 * failure it return "-1"
 */

int 
def_output_f(char *argv_v_2[], short int argument, u_int64_t mem_allo, u_int64_t temp_v_0, u_int64_t *temp_ptr);

int output(int argc_v_1,char *argv_v_1[], struct_ptr *argv_st)	{
		/* check which argument is passed */
		temp_l_8 = 3;
		temp_l_9 = 6;
		check_v_6 = 0;
		start:
		while(temp_l_8 <= argc_v_1)	{
			while(temp_l_9 <= prime_arg*2)	{ 
				if(temp_l_9 == 12 || temp_l_9 == 14)	{
					temp_l_9 +=2;		
					continue;				
				}
				if(strcmp(argv_v_1[temp_l_8],help[temp_l_9]) == 0)	{
					check_v_6 = 1;
					goto arglist;
				}
				if(check_v_6 != 1)
					temp_l_9 +=2;		
			}
			if(check_v_6 != 1)
					temp_l_8++;
		}

/* goto label */
arglist:
	if(temp_l_9 == 6)
		printf("help[6]  %s\n", help[temp_l_9]);		
	if(temp_l_9 == 8)
		printf("help[8]  %s\n", help[temp_l_9]);
	if(temp_l_9  == 10)	{
		printf("help[10]  %s\n", help[temp_l_9]);
		/* when "-o" passed or default output */
		printf("\nbefore => argv_st -> from_num 		\t - %ld\n", argv_st -> from_num);
		printf("before => argv_st -> to_num     		 - %ld\n",argv_st -> to_num);	
		printf("before => argv_st -> temp_v_s_0 		 - %ld\n",argv_st -> temp_v_s_0);
		printf("before => argv_st -> location_in_allo_mem 	 - %ld\n\n",argv_st -> location_in_allo_mem);
		/* calling "_of" function for default output */
		int ret = def_output_f(argv_v_1, temp_l_8, argv_st -> location_in_allo_mem, argv_st -> temp_v_s_0, argv_st -> temp_ptr_s_0);
		if(!ret)	{
			printf("error\n");
		}
	}	
	if(temp_l_9 == 12)
		printf("help[12]  %s\n", help[temp_l_9]);
	if(temp_l_9 == 14)
		printf("help[14] %s\n", help[temp_l_9]);
	if(temp_l_9 == 16)
		printf("help[16]  %s\n", help[temp_l_9]);
	if(temp_l_9 == 18)
		printf("help[18]  %s\n", help[temp_l_9]);
	if(temp_l_9 == 20)
		printf("help[20]  %s\n", help[temp_l_9]);
	if(temp_l_9 == 22)
		printf("help[22]  %s\n", help[temp_l_9]);
	if(temp_l_9 == 24)
		printf("help[24]  %s\n", help[temp_l_9]);	
	if(temp_l_8 == argc_v_1-2)
		return 1;
	else	{
		temp_l_8++;
		temp_l_9 = 0;
		goto start;
	}
}
	
/* "of()" */
int def_output_f(char *argv_v_2[], short int argument, u_int64_t mem_allo, u_int64_t temp_v_0, u_int64_t *temp_ptr)	{
		/* opening file for writing prime numbers */
		FILE *fptr;
		fptr = fopen(argv_v_2[argument+1], "w+");
		if(fptr == NULL)	{
			perror("fopen:");
			exit(EXIT_FAILURE);
		}
		/* writitng to file */
		int seek[100], seek2[100]; 
		seek[0] = fseek(fptr, 0, SEEK_SET);
		if(seek[0] == -1)	{
			perror("lseek");	
		}
	
		char space[200];
		int ind = 0;
		while(ind < 200)	{
			space[ind] = ' ';
			ind++;
		}
		int count = 0;
		int index = 0;
		int check = 1;
		if(mem_allo == 1)	{
			for(; mem_allo <= temp_v_0; mem_allo++)	{
				if(check == 1)	{
		//			printf("before seek - %d\n", seek[index-1]);		
					fprintf(fptr, "%ld",temp_ptr[mem_allo]);
					seek[index] = (int)ftell(fptr);
					if(seek[0] == -1)
						perror("lseek");
					fputs(space,fptr);
					fputc('\n',fptr);	
				}
		//		printf("after seek - %d\n", seek[index]);				
				count++;
				if(count == 10)	{
					if(check == 1)
						mem_allo++;
					count = 0;
					check++;
					index = 0;
				}
				if(check >= 2)	{
					printf("\n2-before seek - %d\n", seek[index]);
					int see = seek[index];
					printf("see - %d\n", see);					
					fseek(fptr, see , SEEK_SET);
					seek[index] = (int)ftell(fptr);
					printf("2-after seek - %d\n", seek[index]);						
					if(seek2[index] == -1)
						perror("fseek");
					fprintf(fptr, "%ld", temp_ptr[mem_allo]);
					seek[index] = (int)ftell(fptr);
					printf("2.1after seek2 - %d\n\n", seek[index]);
				}
				index++;
			}
	}	
	fclose(fptr);
	return 1;
}
