/* This function is part of the program PRIME NUMBER ANALYSIS 
 * program will help to analysis rate of increasing and decreasing
 * in prime number.
 */

/* prime.c: function to check whether number is prime or not */

/* function "primef();" */
struct_ptr 
*primef(u_int64_t *from_num, u_int64_t *to_num)	{
	struct_ptr *st_ret = malloc(sizeof(struct_ptr));
	/* allocating memory for storing number or prime numbers */
	temp_ptr = calloc(*to_num*1000000,sizeof(u_int64_t));
	temp_ret = malloc(sizeof(u_int64_t)*2);

	/* assigning '1', '2', '5', and '7' to temp_ptr[] */	 	
		temp_ptr[0] = 1;
		temp_ptr[1] = 2;
		temp_ptr[2] = 3;
		temp_ptr[3] = 5;
		temp_ptr[4] = 7;
	
	/* even or odd */
	if (*from_num % 2 == 0) {
		*from_num += 1;
	}
	
//	printf("from_num %ld  to_num %ld\n ", *from_num, *to_num);  
	temp_v_0 = 4;
	/* calculation */
	for (temp_l_0 = *from_num; temp_l_0 <= *to_num; temp_l_0 += 2)	{ 
//		printf("temp_l_0 %ld\n", temp_l_0); 
		check_v_0 = 0;
		temp_v_1 = 2;
		for (temp_l_1 = 1; temp_l_1 < temp_v_0 ; temp_l_1++)	{
//			printf("temp_l_0 %ld   temp_l_1  %ld   temp_v_1  %ld ", temp_l_0,temp_l_1,temp_v_1); 
//			printf("temp_ptr[%ld] = %ld\n",temp_v_1,temp_ptr[temp_v_1]); 		
			if (temp_l_0 % temp_ptr[temp_v_1]  != 0)
				temp_v_1++;
			else
			{
				check_v_0 = -1;
				break;
			}
			  		
			}
		if (check_v_0 != -1) {	
			temp_ptr[temp_v_1] = temp_l_0;
			temp_v_0 = temp_v_1;
//			printf("temp_ptr %ld\n", temp_ptr[temp_v_1]); 
		}	
	}
//	printf("temp_v_0 %ld\n",temp_v_0);
	st_ret -> temp_ptr_s_0 = temp_ptr;	
	st_ret -> temp_v_s_0 = temp_v_0;
	return st_ret;
}
