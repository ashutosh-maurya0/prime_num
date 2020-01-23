/* 0.7 */
/* primef_struct(): this fucntion is same as "primef()" except it takes pointer to structure */

#include"primef.h"

struct_ptr *primef_struct(struct_ptr *argv_st)	{
	u_int64_t from_num = argv_st -> from_num;
	u_int64_t to_num   = argv_st -> to_num;
	u_int64_t temp_v_1 = argv_st -> temp_v_s_0;

/* even or odd */
	if (from_num % 2 == 0) {
		from_num += 1;
	}
//	printf("temp_ptr_0[%ld] = %ld\n",temp_v_1,temp_ptr_0[2]);
//	printf("from_num - %ld  to_num - %ld\n", from_num, to_num);
	temp_v_0 = temp_v_1;
	inc_v_2 = 1;
	/* calculation */
	for (temp_l_0 = from_num; temp_l_0 <= to_num; temp_l_0 += 2)	{
//		printf("temp_l_0 - %ld\n", temp_l_0);
		check_v_0 = 0;
		temp_v_1 = 2;
		for (temp_l_1 = 1; temp_l_1 < temp_v_0 ; temp_l_1++)	{
//			printf("temp_l_0 - %ld   temp_l_1 - %ld   temp_v_1 - %ld ", temp_l_0,temp_l_1,temp_v_1);
//			printf("temp_ptr_0[%ld] = %ld\n",temp_v_1,temp_ptr_0[temp_v_1]);
			if (temp_l_0 % temp_ptr_0[temp_v_1]  != 0)
				temp_v_1++;
			else
			{
				check_v_0 = -1;
				break;
			}

		}
//		printf("%ld - argv_st -> from_num  - %ld\n",inc_v_2++, argv_st -> from_num);
		if (check_v_0 != -1) {
			temp_ptr_0[temp_v_1] = temp_l_0;
			temp_v_0 = temp_v_1;
//			printf("temp_ptr_0 - %ld\n", temp_ptr_0[temp_v_1]);
		}
	}
	argv_st -> temp_v_s_0 = temp_v_0;
	return argv_st;
}
