/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: dporhomo <dporhomo@student.42prague.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/11/10 11:26:02 by dporhomo		  #+#	#+#			 */
/*   Updated: 2025/11/19 13:20:22 by dporhomo		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h> /*size_t, */
#include <ctype.h> /*isalpha, isdigit, isalnum, isascii, isprint*/
#include <stdlib.h> /*atoi, calloc, */
#include <limits.h> /*INT_MIN, */
#include <stdio.h>
#include <string.h> /*strlen, memset*/
#include <bsd/string.h> /*strlcat, strlcpy*/
#include "libft.h"

/*helper functions for bonus part*/
static void modify_to_upper(void *);
static void *map_multiply_two(void *content);
static void del_int(void *content);
static void delete_content(void *content);

/* helper functions for testing strmapi*/
static char to_upper_if_odd_index(unsigned int i, char c);
static char replace_space_with_underscore(unsigned int i, char c);


/* helper functions for testing striteri*/
static void	capitalize_even_index(unsigned int i, char *c_ptr);
static void	replace_a_with_Z(unsigned int i, char *c_ptr);

int	main(void)
{
	// isalpha start
	printf("---isalpha test---------------------------------------------\n");
	int		isalpha_n1;
	char	isalpha_c1;
	char	isalpha_c2;
	char	isalpha_c3;
	char	isalpha_c4;
	char	isalpha_c5;
	char	isalpha_c6;
	char	isalpha_c7;
	char	isalpha_c8;
	char	isalpha_c9;
	char	isalpha_c10;
	isalpha_n1 = 9;
	isalpha_c1 = 'a';
	isalpha_c2 = 'B';
	isalpha_c3 = '!';
	isalpha_c4 = '\n';
	isalpha_c5 = 29;
	isalpha_c6 = 127;
	isalpha_c7 = 64;
	isalpha_c8 = 91;
	isalpha_c9 = 96;
	isalpha_c10 = 123;
	printf("Expected n1: %d, Actual n1: %d.\n", isalpha(isalpha_n1), ft_isalpha(isalpha_n1));
	printf("Expected c1: %d, Actual c1: %d.\n", isalpha(isalpha_c1), ft_isalpha(isalpha_c1));
	printf("Expected c2: %d, Actual c2: %d.\n", isalpha(isalpha_c2), ft_isalpha(isalpha_c2));
	printf("Expected c3: %d, Actual c3: %d.\n", isalpha(isalpha_c3), ft_isalpha(isalpha_c3));
	printf("Expected c4: %d, Actual c4: %d.\n", isalpha(isalpha_c4), ft_isalpha(isalpha_c4));
	printf("Expected c5: %d, Actual c5: %d.\n", isalpha(isalpha_c5), ft_isalpha(isalpha_c5));
	printf("Expected c6: %d, Actual c6: %d.\n", isalpha(isalpha_c6), ft_isalpha(isalpha_c6));
	printf("Expected c7: %d, Actual c7: %d.\n", isalpha(isalpha_c7), ft_isalpha(isalpha_c7));
	printf("Expected c8: %d, Actual c8: %d.\n", isalpha(isalpha_c8), ft_isalpha(isalpha_c8));
	printf("Expected c9: %d, Actual c9: %d.\n", isalpha(isalpha_c9), ft_isalpha(isalpha_c9));
	printf("Expected c10: %d, Actual c10: %d.\n", isalpha(isalpha_c10), ft_isalpha(isalpha_c10));
	if ((isalpha(isalpha_c1) != 0) == (ft_isalpha(isalpha_c1) != 0))
		printf("ft_isalpha test is successful.\n\n");
	// isalpha end

	// isdigit start
	printf("---isdigit test---------------------------------------------\n");
	int		isdigit_n1;
	char	isdigit_c1;
	char	isdigit_c2;

	isdigit_n1 = 5;
	isdigit_c1 = '5';
	isdigit_c2 = 'a';

	printf("Expected n1: %d, Actual n1: %d.\n", isdigit(isdigit_n1), ft_isdigit(isdigit_n1));
	printf("Expected c1: %d, Actual c1: %d.\n", isdigit(isdigit_c1), ft_isdigit(isdigit_c1));
	printf("Expected c2: %d, Actual c2: %d.\n", isdigit(isdigit_c2), ft_isdigit(isdigit_c2));
	if ((isdigit(isdigit_c1) != 0) == (ft_isdigit(isdigit_c1) != 0))
		printf("ft_isdigit test is successful.\n\n");
	// isdigit end

	// isalnum start
	printf("---isalnum test---------------------------------------------\n");
	int		isalnum_n1;
	char	isalnum_c1;
	char	isalnum_c2;
	char	isalnum_c3;
	char	isalnum_c4;
	char	isalnum_c5;

	isalnum_n1 = 5;
	isalnum_c1 = '5';
	isalnum_c2 = 'a';
	isalnum_c3 = 'X';
	isalnum_c4 = '\n';
	isalnum_c5 = '&';

	printf("Expected n1: %d, Actual n1: %d.\n", isalnum(isalnum_n1), ft_isalnum(isalnum_n1));
	printf("Expected c1: %d, Actual c1: %d.\n", isalnum(isalnum_c1), ft_isalnum(isalnum_c1));
	printf("Expected c2: %d, Actual c2: %d.\n", isalnum(isalnum_c2), ft_isalnum(isalnum_c2));
	printf("Expected c2: %d, Actual c2: %d.\n", isalnum(isalnum_c3), ft_isalnum(isalnum_c3));
	printf("Expected c2: %d, Actual c2: %d.\n", isalnum(isalnum_c4), ft_isalnum(isalnum_c4));
	printf("Expected c2: %d, Actual c2: %d.\n", isalnum(isalnum_c5), ft_isalnum(isalnum_c5));
	if ((isdigit(isalnum_c1) != 0) == (ft_isalnum(isalnum_c1) != 0))
	printf("ft_isalnum test is successful.\n\n");
	// isalnum end

	// isascii start
	printf("---isascii test---------------------------------------------\n");
	int		isascii_n1;
	unsigned char	isascii_c1;
	unsigned char	isascii_c2;

	isascii_n1 = 0;
	isascii_c1 = 105;
	isascii_c2 = 250;

	printf("Expected n1: %d, Actual n1: %d.\n", isascii(isascii_n1), ft_isascii(isascii_n1));
	printf("Expected c1: %d, Actual c1: %d.\n", isascii(isascii_c1), ft_isascii(isascii_c1));
	printf("Expected c2: %d, Actual c2: %d.\n", isascii(isascii_c2), ft_isascii(isascii_c2));
	if ((isascii(isascii_c1) != 0) == (ft_isascii(isascii_c1) != 0))
	printf("ft_isascii test is successful.\n\n");
	// isascii end

	// isprint start
	printf("---isprint test---------------------------------------------\n");
	int		isprint_n1;
	char	isprint_c1;
	char	isprint_c2;

	isprint_n1 = 12;
	isprint_c1 = 33;
	isprint_c2 = 127;

	printf("Expected n1: %d, Actual n1: %d.\n", isprint(isprint_n1), ft_isprint(isprint_n1));
	printf("Expected c1: %d, Actual c1: %d.\n", isprint(isprint_c1), ft_isprint(isprint_c1));
	printf("Expected c2: %d, Actual c2: %d.\n", isprint(isprint_c2), ft_isprint(isprint_c2));
	if ((isprint(isprint_c1) != 0) == (ft_isprint(isprint_c1) != 0))
	printf("ft_isprint test is successful.\n\n");
	// isprint end

	// strlen start
	printf("---strlen test---------------------------------------------\n");
	size_t	strlen1;
	size_t	strlen2;
	char 	strlen_str1[] = "Ahoj";
	char	strlen_str2[] = "";

	printf("Expected strlen1: %zu, Actual strlen1: %zu.\n", strlen1 = strlen(strlen_str1), strlen2 = ft_strlen(strlen_str1));
	printf("Expected strlen2: %zu, Actual strlen2: %zu.\n", strlen1 = strlen(strlen_str2), strlen2 = ft_strlen(strlen_str2));
	printf("ft_strlen is successful.\n\n");
	// strlen end

	// strlcpy start
	printf("---strlcpy test---------------------------------------------\n");
	const char	strlcpy_src1[20] = "Hi,there_my_friend!";
	const char	strlcpy_src2[5] = "Ahoj";
	const char	strlcpy_src3[5] = "Ahoj";

	char	strlcpy_dst1[30] = "";
	char	strlcpy_dst2[10] = "";
	char	strlcpy_dst3[0] = "";
	char	strlcpy_dst4[9] = "";

	size_t	strlcpy_dst_size1;
	size_t	strlcpy_dst_size2;
	size_t	strlcpy_dst_size3;
	size_t	strlcpy_dst_size4;
	size_t	strlcpy_result2;

	strlcpy_dst_size1 = 30;
	strlcpy_result2 = ft_strlcpy(strlcpy_dst1, strlcpy_src1, strlcpy_dst_size1);
	printf("Actual dst1 = 30, src1 = 19, dst_size = 30: %zu\n", strlcpy_result2);
	printf("src1: %s\ndst1: %s\n", strlcpy_src1, strlcpy_dst1);

	strlcpy_dst_size2 = 30;
	strlcpy_result2 = ft_strlcpy(strlcpy_dst2, strlcpy_src2, strlcpy_dst_size2);
	printf("Actual dst2 = 10, src2 = 4, dst_size = 30: %zu\n", strlcpy_result2);
	printf("src2: %s\ndst2: %s\n", strlcpy_src2, strlcpy_dst2);

	strlcpy_dst_size3 = 0;
	strlcpy_result2 = ft_strlcpy(strlcpy_dst3, strlcpy_src3, strlcpy_dst_size3);
	printf("Actual dst3 = 0, src3 = 4, dst_size = 0: %zu\n", strlcpy_result2);
	printf("src3: %s\ndst3: %s\n", strlcpy_src3, strlcpy_dst3);

	strlcpy_dst_size4 = 9;
	strlcpy_result2 = ft_strlcpy(strlcpy_dst4, strlcpy_src1, strlcpy_dst_size4);
	printf("Actual dst4 = 9, src4 = 19, dst_size = 9: %zu\n", strlcpy_result2);
	printf("src1: %s\ndst4: %s\n", strlcpy_src1, strlcpy_dst4);
	printf("ft_strlcpy is successful.\n\n");
	// strlcpy end

	// strlcat start
	printf("---strlcat test---------------------------------------------\n");
	char	strlcat_src1[5] = "Ahoj";
	char	strlcat_dst1[20] = "Tomas";
	int		strlcat_dst_size1;
	size_t	strlcat_result1;

	strlcat_dst_size1 = 4;
	strlcat_result1 = strlcat(strlcat_dst1, strlcat_src1, strlcat_dst_size1);
	printf("Expected result1 for 'Ahoj' + 'Tomas' and dst_size 3 = src_len+size = 7: %zu\n", strlcat_result1);
	printf("ft_strlcat is successful.\n\n");
	// strlcat end

	// toupper start
	printf("---toupper test---------------------------------------------\n");
	char	toupper_c = 'a';
	printf("Expected: %c, Actual: %c\n", toupper(toupper_c), ft_toupper(toupper_c));
	printf("ft_toupper is successful.\n\n");
	// toupper end

	// tolower start
	printf("---tolower test---------------------------------------------\n");
	char	tolower_c = 'A';
	printf("Expected: %c, Actual: %c\n", tolower(tolower_c), ft_tolower(tolower_c));
	printf("ft_tolower is successful.\n\n");
	// tolower end

	//strncmp start
	printf("---strncmp test---------------------------------------------\n");
	char	strncmp_s1[] = "13345";
	char	strncmp_s2[] = "153";
	int		strncmp_n;
	int		strncmp_result;
	strncmp_n = 3;
	strncmp_result = strncmp(strncmp_s1, strncmp_s2, strncmp_n);
	printf("Expected strncmp: %d\n", strncmp_result);
	strncmp_result = ft_strncmp(strncmp_s1, strncmp_s2, strncmp_n);
	printf("Actual ft_strncmp: %d\n", strncmp_result);
	printf("ft_strncmp is successful.\n\n");
	//strncmp end

	// atoi start
	printf("---atoi test---------------------------------------------\n");
	char 	atoi_s1[] = "+123";
	char	atoi_s2[] = "-123";
	char	atoi_s3[] = "--123";
	char	atoi_s4[] = "  \t\n123";
	char	atoi_s5[] = "abc123";
	char	atoi_s6[] = "-123abc";
	char	atoi_s7[] = "---123";
	int		atoi_result1;

	atoi_result1 = atoi(atoi_s1);
	printf("Expected s1 '+123': %d\n", atoi_result1);
	atoi_result1 = ft_atoi(atoi_s1);
	printf("Actual s1 '+123': %d\n", atoi_result1);
	atoi_result1 = atoi(atoi_s2);
	printf("Expected s2 '-123': %d\n", atoi_result1);
	atoi_result1 = ft_atoi(atoi_s2);
	printf("Actual s2 '-123': %d\n", atoi_result1);
	atoi_result1 = atoi(atoi_s3);
	printf("Expected s3 '--123': %d\n", atoi_result1);
	atoi_result1 = ft_atoi(atoi_s3);
	printf("Actual s3 '--123': %d\n", atoi_result1);
	atoi_result1 = atoi(atoi_s4);
	printf("Expected s4 '  \\t\\n123': %d\n", atoi_result1);
	atoi_result1 = ft_atoi(atoi_s4);
	printf("Actual s4 '  \\t\\n123': %d\n", atoi_result1);
	atoi_result1 = atoi(atoi_s5);
	printf("Expected s5 'abc123': %d\n", atoi_result1);
	atoi_result1 = ft_atoi(atoi_s5);
	printf("Actual s5 'abc123': %d\n", atoi_result1);
	atoi_result1 = atoi(atoi_s6);
	printf("Expected s6 '-123abc': %d\n", atoi_result1);
	atoi_result1 = ft_atoi(atoi_s6);
	printf("Actual s6 '-123abc': %d\n", atoi_result1);
	atoi_result1 = atoi(atoi_s7);
	printf("Expected s7 '---123': %d\n", atoi_result1);
	atoi_result1 = ft_atoi(atoi_s7);
	printf("Actual s7 '---123': %d\n", atoi_result1);
	printf("ft_atoi is successful.\n\n");
	// atoi end

	//memset start
	printf("---memset test---------------------------------------------\n");
	char	memset_s1[16] = "This_is_string.";
	char	memset_s2[16] = "This_is_string.";
	size_t	memset_len;
	int		memset_fill_value;

	memset_len = 10;
	memset_fill_value = 67;
	printf("Source s1: %s\n", memset_s1);
	memset(memset_s1, memset_fill_value, memset_len);
	printf("Expected s1 with %c: %s\n", memset_fill_value, memset_s1);
	printf("Source s2: %s\n", memset_s2);
	ft_memset(memset_s2, memset_fill_value, memset_len);
	printf("Actual s2 with %c: %s\n", memset_fill_value, memset_s2);
	printf("ft_memset is successful.\n\n");
	//memset end

	//bzero start
	printf("---bzero test---------------------------------------------\n");
	char	bzero_s1[16] = "This_is_string.";
	size_t	bzero_len;
	size_t	src_size;
	size_t	i;

	bzero_len = 4;
	src_size = 16;
	i = 0;
	printf("Source s1: %s\n", bzero_s1);
	ft_bzero(bzero_s1, bzero_len);
	printf("Actual s1 with src_size %zu and bzero_len %zu:\n", src_size, bzero_len);
	write(1, "Actual s1: ", 11);
	while (i < src_size)
	{
		write(1, &bzero_s1[i], 1);
		i++;
	}
	printf("\nft_bezero is successful.\n\n");
	//bezero end

	//memcpy start
	printf("---memcpy test---------------------------------------------\n");
	char	memcpy_src1[30] = "Hi_there_friends!";
	char	memcpy_dst1[30] = "";
	char	memcpy_src2[30] = "Hi_there_friends!";
	char	memcpy_dst2[30] = "";

	printf("Src string: %s\n", memcpy_src1);
	memcpy(memcpy_dst1, memcpy_src1, 5);
	printf("Expected memcpy dst: %s\n", memcpy_dst1);
	ft_memcpy(memcpy_dst2, memcpy_src2, 5);
	printf("Actual ft_memcpy dst: %s\n", memcpy_dst2);
	printf("ft_memcpy is successful.\n\n");
	//memcpy end

	// memmove start
	printf("---memmove test---------------------------------------------\n");
	char	memmove_src1[30] = "Hi_there_friends!";
	char	memmove_dst1[30] = "";
	char	memmove_src2[30] = "Hi_there_friends!";
	char	memmove_dst2[30] = "";

	printf("Src string: %s\n", memmove_src1);
	memmove(memmove_dst1, memmove_src1, 5);
	printf("Expected memmove dst: %s\n", memmove_dst1);
	ft_memmove(memmove_dst2, memmove_src2, 5);
	printf("Actual ft_memmove dst: %s\n", memmove_dst2);
	printf("ft_memmove is successful.\n\n");
	// memmove end

	// strchr start
	printf("---strchr test---------------------------------------------\n");
	char	strchr_s1[] = "Hellow World";
	char	strchr_s2[] = "apple";
	char	strchr_s3[] = "banana";
	char	strchr_s4[] = "book";
	char	strchr_s5[] = "test";
	char	strchr_s6[] = "";
	char	strchr_s7[] = "test\0";
	char	strchr_s8[] = "data";

	char	strchr_c1;
	char	strchr_c2;
	char	strchr_c3;
	char	strchr_c4;
	char	strchr_c5;
	char	strchr_c6;
	char	strchr_c7;
	char	strchr_c8;

	char	*strchr_p1;
	char	*strchr_p2;
	char	*strchr_p3;
	char	*strchr_p4;
	char	*strchr_p5;
	char	*strchr_p6;
	char	*strchr_p7;
	char	*strchr_p8;

	strchr_c1 = 'W';
	strchr_c2 = 'a';
	strchr_c3 = 'a';
	strchr_c4 = 'k';
	strchr_c5 = 'z';
	strchr_c6 = 'a';
	strchr_c7 = '\0';
	strchr_c8 = 'd';

	strchr_p1 = strchr(strchr_s1, strchr_c1);
	printf("Expected p1: %p\n", strchr_p1);
	strchr_p1 = ft_strchr(strchr_s1, strchr_c1);
	printf("Actual p1: %p\n", strchr_p1);
	strchr_p2 = strchr(strchr_s2, strchr_c2);
	printf("Expected p2: %p\n", strchr_p2);
	strchr_p2 = ft_strchr(strchr_s2, strchr_c2);
	printf("Actual p2: %p\n", strchr_p2);
	strchr_p3 = strchr(strchr_s3, strchr_c3);
	printf("Expected p3: %p\n", strchr_p3);
	strchr_p3 = ft_strchr(strchr_s3, strchr_c3);
	printf("Actual p3: %p\n", strchr_p3);
	strchr_p4 = strchr(strchr_s4, strchr_c4);
	printf("Expected p4: %p\n", strchr_p4);
	strchr_p4 = ft_strchr(strchr_s4, strchr_c4);
	printf("Actual p4: %p\n", strchr_p4);
	strchr_p5 = strchr(strchr_s5, strchr_c5);
	printf("Expected p5: %p\n", strchr_p5);
	strchr_p5 = ft_strchr(strchr_s5, strchr_c5);
	printf("Actual p5: %p\n", strchr_p5);
	strchr_p6 = strchr(strchr_s6, strchr_c6);
	printf("Expected p6: %p\n", strchr_p6);
	strchr_p6 = ft_strchr(strchr_s6, strchr_c6);
	printf("Actual p6: %p\n", strchr_p6);
	strchr_p7 = strchr(strchr_s7, strchr_c7);
	printf("Expected p7: %p\n", strchr_p7);
	strchr_p7 = ft_strchr(strchr_s7, strchr_c7);
	printf("Actual p7: %p\n", strchr_p7);
	strchr_p8 = strchr(strchr_s8, strchr_c8);
	printf("Expected p8: %p\n", strchr_p8);
	strchr_p8 = ft_strchr(strchr_s8, strchr_c8);
	printf("Actual p8: %p\n", strchr_p8);
	printf("ft_strchr is successful.\n\n");
	// strchr end

	// strrchr start
	printf("---strrchr test---------------------------------------------\n");
	char	strrchr_s1[] = "Hellow World";
	char	strrchr_s2[] = "mississippi";
	char	strrchr_s3[] = "apple";
	char	strrchr_s4[] = "b";
	char	strrchr_s5[] = "test";
	char	strrchr_s6[] = "";
	char	strrchr_s7[] = "test\0";
	char	strrchr_s8[] = "data";

	char	strrchr_c1;
	char	strrchr_c2;
	char	strrchr_c3;
	char	strrchr_c4;
	char	strrchr_c5;
	char	strrchr_c6;
	char	strrchr_c7;
	char	strrchr_c8;

	char	*strrchr_p1;
	char	*strrchr_p2;
	char	*strrchr_p3;
	char	*strrchr_p4;
	char	*strrchr_p5;
	char	*strrchr_p6;
	char	*strrchr_p7;
	char	*strrchr_p8;

	strrchr_c1 = 'l';
	strrchr_c2 = 'i';
	strrchr_c3 = 'a';
	strrchr_c4 = 'b';
	strrchr_c5 = 'z';
	strrchr_c6 = 'a';
	strrchr_c7 = '\0';
	strrchr_c8 = 'd';

	strrchr_p1 = strrchr(strrchr_s1, strrchr_c1);
	printf("Expected p1: %p\n", strrchr_p1);
	strrchr_p1 = ft_strrchr(strrchr_s1, strrchr_c1);
	printf("Actual p1: %p\n", strrchr_p1);
	strrchr_p2 = strrchr(strrchr_s2, strrchr_c2);
	printf("Expected p2: %p\n", strrchr_p2);
	strrchr_p2 = ft_strrchr(strrchr_s2, strrchr_c2);
	printf("Actual p2: %p\n", strrchr_p2);
	strrchr_p3 = strrchr(strrchr_s3, strrchr_c3);
	printf("Expected p3: %p\n", strrchr_p3);
	strrchr_p3 = ft_strrchr(strrchr_s3, strrchr_c3);
	printf("Actual p3: %p\n", strrchr_p3);
	strrchr_p4 = strrchr(strrchr_s4, strrchr_c4);
	printf("Expected p4: %p\n", strrchr_p4);
	strrchr_p4 = ft_strrchr(strrchr_s4, strrchr_c4);
	printf("Actual p4: %p\n", strrchr_p4);
	strrchr_p5 = strrchr(strrchr_s5, strrchr_c5);
	printf("Expected p5: %p\n", strrchr_p5);
	strrchr_p5 = ft_strrchr(strrchr_s5, strrchr_c5);
	printf("Actual p5: %p\n", strrchr_p5);
	strrchr_p6 = strrchr(strrchr_s6, strrchr_c6);
	printf("Expected p6: %p\n", strrchr_p6);
	strrchr_p6 = ft_strrchr(strrchr_s6, strrchr_c6);
	printf("Actual p6: %p\n", strrchr_p6);
	strrchr_p7 = strrchr(strrchr_s7, strrchr_c7);
	printf("Expected p7: %p\n", strrchr_p7);
	strrchr_p7 = ft_strrchr(strrchr_s7, strrchr_c7);
	printf("Actual p7: %p\n", strrchr_p7);
	strrchr_p8 = strrchr(strrchr_s8, strrchr_c8);
	printf("Expected p8: %p\n", strrchr_p8);
	strrchr_p8 = ft_strrchr(strrchr_s8, strrchr_c8);
	printf("Actual p8: %p\n", strrchr_p8);
	printf("ft_strrchr is successful.\n\n");
	// strrchr end

	// memchr start
	printf("---memchr test---------------------------------------------\n");
	char	memchr_s1[] = "Hellow World";
	char	memchr_s2[] = "apple pie";
	char	memchr_s3[] = "data";
	char	memchr_s4[] = "data";
	char	memchr_s5[] = "Hello";
	char	memchr_s6[] = "";
	char	memchr_s7[] = "Test";
	char	memchr_s8[] = "data";

	char	memchr_c1;
	char	memchr_c2;
	char	memchr_c3;
	char	memchr_c4;
	char	memchr_c5;
	char	memchr_c6;
	char	memchr_c7;
	unsigned char	memchr_c8;

	char	*memchr_p1;
	char	*memchr_p2;
	char	*memchr_p3;
	char	*memchr_p4;
	char	*memchr_p5;
	char	*memchr_p6;
	char	*memchr_p7;
	unsigned char	*memchr_p8;

	memchr_c1 = 'W';
	memchr_c2 = 'p';
	memchr_c3 = 'd';
	memchr_c4 = '\0';
	memchr_c5 = 'o';
	memchr_c6 = 'z';
	memchr_c7 = 't';
	memchr_c8 = 255;

	memchr_p1 = memchr(memchr_s1, memchr_c1, 11);
	printf("Expected p1: %p\n", memchr_p1);
	memchr_p1 = ft_memchr(memchr_s1, memchr_c1, 11);
	printf("Actual p1: %p\n", memchr_p1);
	memchr_p2 = memchr(memchr_s2, memchr_c2, 9);
	printf("Expected p2: %p\n", memchr_p2);
	memchr_p2 = ft_memchr(memchr_s2, memchr_c2, 9);
	printf("Actual p2: %p\n", memchr_p2);
	memchr_p3 = memchr(memchr_s3, memchr_c3, 4);
	printf("Expected p3: %p\n", memchr_p3);
	memchr_p3 = ft_memchr(memchr_s3, memchr_c3, 4);
	printf("Actual p3: %p\n", memchr_p3);
	memchr_p4 = memchr(memchr_s4, memchr_c4, 5);
	printf("Expected p4: %p\n", memchr_p4);
	memchr_p4 = ft_memchr(memchr_s4, memchr_c4, 5);
	printf("Actual p4: %p\n", memchr_p4);
	memchr_p5 = memchr(memchr_s5, memchr_c5, 3);
	printf("Expected p5: %p\n", memchr_p5);
	memchr_p5 = ft_memchr(memchr_s5, memchr_c5, 3);
	printf("Actual p5: %p\n", memchr_p5);
	memchr_p6 = memchr(memchr_s6, memchr_c6, 0);
	printf("Expected p6: %p\n", memchr_p6);
	memchr_p6 = ft_memchr(memchr_s6, memchr_c6, 0);
	printf("Actual p6: %p\n", memchr_p6);
	memchr_p7 = memchr(memchr_s7, memchr_c7, 1);
	printf("Expected p7: %p\n", memchr_p7);
	memchr_p7 = ft_memchr(memchr_s7, memchr_c7, 1);
	printf("Actual p7: %p\n", memchr_p7);
	memchr_p8 = memchr(memchr_s8, memchr_c8, 100);
	printf("Expected p8: %p\n", memchr_p8);
	memchr_p8 = ft_memchr(memchr_s8, memchr_c8, 100);
	printf("Actual p8: %p\n", memchr_p8);
	printf("ft_memchr is successful.\n\n");
	// memchr end

	// memcmp start
	printf("---memcmp test---------------------------------------------\n");
	char	memcmp_s1[] = "12045";
	char	memcmp_s2[] = "124";
	int		memcmp_n1;

	memcmp_n1 = memcmp(memcmp_s1, memcmp_s2, 3);
	printf("Expected memcmp: %d\n", memcmp_n1);
	memcmp_n1 = ft_memcmp(memcmp_s1, memcmp_s2, 3);
	printf("Actual ft_memcmp: %d\n", memcmp_n1);
	printf("ft_memcmp is successful.\n\n");
	// memcmp end

	// strnstr
	printf("---strnstr test---------------------------------------------\n");
	char	strnstr_s1[] = "ahoj";
	char	strnstr_s2[] = "oj";
	char	*strnstr_p1;

	strnstr_p1 = strnstr(strnstr_s1, strnstr_s2, 4);
	printf("Expected strnstr: %p\n", strnstr_p1);
	strnstr_p1 = ft_strnstr(strnstr_s1, strnstr_s2, 4);
	printf("Actual ft_strnstr: %p\n", strnstr_p1);
	printf("ft_strnstr is successful.\n\n");
	// strnstr

	// strdup_ start
	printf("---strdup test---------------------------------------------\n");
	char	strdup_s[] = "Ahoj";
	char	*strdup_ps;

	strdup_ps = strdup(strdup_s);
	printf("Expected dup.str.: %s\n", strdup_ps);
	strdup_ps = ft_strdup(strdup_s);
	printf("Actual dup.str.: %s\n", strdup_ps);
	printf("ft_strdup is successful.\n\n");
	// strdup end

	// calloc start
	printf("---calloc test---------------------------------------------\n");
	int		*calloc_array;
	size_t	calloc_nmemb;
	size_t	calloc_i;

	calloc_nmemb = 5;
	calloc_array = ft_calloc(calloc_nmemb, sizeof(int));
	if (!calloc_array)
	{
		printf("ft_calloc returned NULL\n");
		return (1);
	}
	printf("Values after ft_calloc:\n");
	calloc_i = 0;
	while (calloc_i < calloc_nmemb)
	{
		printf("array[%zu] = %d\n", calloc_i, calloc_array[calloc_i]);
		calloc_i++;
	}
	// Modify values to ensure memory works normally
	calloc_i = 0;
	while (calloc_i < calloc_nmemb)
	{
		calloc_array[calloc_i] = (int)(calloc_i + 1);
		calloc_i++;
	}
	printf("\nValues after writing:\n");
	calloc_i = 0;
	while (calloc_i < calloc_nmemb)
	{
		printf("array[%zu] = %d\n", calloc_i, calloc_array[calloc_i]);
		calloc_i++;
	}
	free(calloc_array);
	printf("ft_calloc is successful.\n\n");
	// calloc end

	// ft_substr start
	printf("---substr test---------------------------------------------\n");
	char			*substr_s;
	char 			*substr_expected;
	char 			*substr_result;
	unsigned int	substr_start;
	size_t			substr_len;
	int 			substr_test_num;
	int 			substr_success;
	int 			substr_total;

	substr_test_num = 1;
	substr_success = 0;
	substr_total = 9;

	// Test 1: Basic case, full extraction
	substr_s = "Hello World";
	substr_start = 0;
	substr_len = 5;
	substr_expected = "Hello";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 2: Substring from the middle
	substr_s = "The quick brown fox";
	substr_start = 10;
	substr_len = 5;
	substr_expected = "brown";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 3: Length is longer than available characters
	substr_s = "Programming";
	substr_start = 3;
	substr_len = 20;
	substr_expected = "gramming";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 4: Start index is exactly at the end (should return empty string "")
	substr_s = "End";
	substr_start = 3; // Index 3 is the null terminator
	substr_len = 5;
	substr_expected = "";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 5: Start index is far beyond the end (should return empty string "")
	substr_s = "Too far";
	substr_start = 10;
	substr_len = 5;
	substr_expected = "";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 6: Zero length requested
	substr_s = "Zero length";
	substr_start = 5;
	substr_len = 0;
	substr_expected = "";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 7: Substring up to the end (len is exact)
	substr_s = "Substr Test";
	substr_start = 7;
	substr_len = 4;
	substr_expected = "Test";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 8: Substring where requested length exceeds remaining characters
	substr_s = "Example";
	substr_start = 4;
	substr_len = 10;
	substr_expected = "ple";
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [\"%s\" @ %u, len %zu] -> ", substr_test_num++, substr_s, substr_start, substr_len);
	if (substr_result != NULL && strcmp(substr_result, substr_expected) == 0)
	{
		printf("PASS (Got: \"%s\")\n", substr_result);
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: \"%s\")\n", substr_result ? substr_result : "NULL", substr_expected);
	}
	free(substr_result);

	// Test 9: NULL input string (Critical Test)
	substr_s = NULL;
	substr_start = 0;
	substr_len = 5;
	substr_expected = NULL;
	substr_result = ft_substr(substr_s, substr_start, substr_len);

	printf("Test %d: [%s @ %u, len %zu] -> ", substr_test_num++, "NULL", substr_start, substr_len);
	if (substr_result == substr_expected) // Expected NULL, so result must be NULL
	{
		printf("PASS (NULL)\n");
		substr_success++;
	}
	else
	{
		printf("FAIL (Got: \"%s\", Expected: NULL)\n", substr_result ? substr_result : "NULL");
		free(substr_result); // result might be non-NULL if implementation is wrong
	}
	printf("%d/%d ft_substr tests successful.\n\n", substr_success, substr_total);
	// ft_substr end

	// ft_strjoin start
	printf("---ft_strjoin test---------------------------------------------\n");
	char	*ft_strjoin_s1;
	char	*ft_strjoin_s2;
	char	*ft_strjoin_result;

	// Test 1: Normal join
	ft_strjoin_s1 = "Hello, ";
	ft_strjoin_s2 = "world!";
	ft_strjoin_result = ft_strjoin(ft_strjoin_s1, ft_strjoin_s2);
	printf("Test 1: \"%s\" + \"%s\" -> \"%s\"\n", ft_strjoin_s1, ft_strjoin_s2, ft_strjoin_result);
	free(ft_strjoin_result);

	// Test 2: Joining empty string with text
	ft_strjoin_s1 = "";
	ft_strjoin_s2 = "42";
	ft_strjoin_result = ft_strjoin(ft_strjoin_s1, ft_strjoin_s2);
	printf("Test 2: \"%s\" + \"%s\" -> \"%s\"\n", ft_strjoin_s1, ft_strjoin_s2, ft_strjoin_result);
	free(ft_strjoin_result);

	// Test 3: Joining text with empty string
	ft_strjoin_s1 = "Libft";
	ft_strjoin_s2 = "";
	ft_strjoin_result = ft_strjoin(ft_strjoin_s1, ft_strjoin_s2);
	printf("Test 3: \"%s\" + \"%s\" -> \"%s\"\n", ft_strjoin_s1, ft_strjoin_s2, ft_strjoin_result);
	free(ft_strjoin_result);

	// Test 4: Two empty strings
	ft_strjoin_s1 = "";
	ft_strjoin_s2 = "";
	ft_strjoin_result = ft_strjoin(ft_strjoin_s1, ft_strjoin_s2);
	printf("Test 4: \"%s\" + \"%s\" -> \"%s\"\n", ft_strjoin_s1, ft_strjoin_s2, ft_strjoin_result);
	free(ft_strjoin_result);

	// Test 5: Normal long strings
	ft_strjoin_s1 = "Hello";
	ft_strjoin_s2 = " world, this is libft!";
	ft_strjoin_result = ft_strjoin(ft_strjoin_s1, ft_strjoin_s2);
	printf("Test 5: \"%s\" + \"%s\" -> \"%s\"\n", ft_strjoin_s1, ft_strjoin_s2, ft_strjoin_result);
	free(ft_strjoin_result);
	printf("ft_strjoin is succesful.\n\n");
	// ft_strjoin end

	// ft_trtrim start
	printf("---ft_strtrim test---------------------------------------------\n");
	char	*ft_strtrim_str;
	char	*ft_strtrim_set;
	char	*ft_strtrim_trimmed;

	ft_strtrim_str = "   hello world   ";
	ft_strtrim_set = "   ";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 1: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	ft_strtrim_str = "---libft---";
	ft_strtrim_set = "-t";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 2: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	ft_strtrim_str = "abc";
	ft_strtrim_set = "xyz";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 3: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	ft_strtrim_str = "aaaaaa";
	ft_strtrim_set = "a";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 4: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	ft_strtrim_str = "";
	ft_strtrim_set = "abc";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 5: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	ft_strtrim_str = "hello";
	ft_strtrim_set = "";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 6: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	ft_strtrim_str = "\t\t hello \t\t ";
	ft_strtrim_set = "\t ";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 7: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	ft_strtrim_str = "- - hello world -- ++ +";
	ft_strtrim_set = "- +";
	ft_strtrim_trimmed = ft_strtrim(ft_strtrim_str, ft_strtrim_set);
	printf("Test 8: \"%s\" + \"%s\" -> \"%s\"\n", ft_strtrim_str, ft_strtrim_set, ft_strtrim_trimmed);
	free(ft_strtrim_trimmed);
	printf("ft_strtim is successful.\n\n");
	// ft_strtrim end

	// ft_split start
	printf("---ft_split test---------------------------------------------\n");
	char **ft_split_result;
	int ft_split_i;

	/// ---------- TEST 1: Regular split ----------
	printf("TEST 1: \"Hello world program\" split by ' '\n");
	ft_split_result = ft_split("Hello world program", ' ');
	ft_split_i = 0;
	while (ft_split_result && ft_split_result[ft_split_i])
	{
		printf("[%s]\n", ft_split_result[ft_split_i]);
		free(ft_split_result[ft_split_i]);
		ft_split_i++;
	}
	free(ft_split_result);

	/// ---------- TEST 2: Multiple delimiters ------
	printf("\nTEST 2: \"---abc---def--gh---\" split by '-'\n");
	ft_split_result = ft_split("---abc---def--gh---", '-');
	ft_split_i = 0;
	while (ft_split_result && ft_split_result[ft_split_i])
	{
		printf("[%s]\n", ft_split_result[ft_split_i]);
		free(ft_split_result[ft_split_i]);
		ft_split_i++;
	}
	free(ft_split_result);

	///---------- TEST 3: Empty string ----------
	printf("\nTEST 3: Empty string\n");
	ft_split_result = ft_split("", ',');
	ft_split_i = 0;
	while (ft_split_result && ft_split_result[ft_split_i])
	{
		printf("[%s]\n", ft_split_result[ft_split_i]);
		free(ft_split_result[ft_split_i]);
		ft_split_i++;
	}
	free(ft_split_result);

	///---------- TEST 4: String containing ONLY delimiters ----------
	printf("\nTEST 4: \";;;;;;\" split by ';'\n");
	ft_split_result = ft_split(";;;;;;", ';');
	ft_split_i = 0;
	while (ft_split_result && ft_split_result[ft_split_i])
	{
		printf("[%s]\n", ft_split_result[ft_split_i]);
		free(ft_split_result[ft_split_i]);
		ft_split_i++;
	}
	free(ft_split_result);

	///---------- TEST 5: No delimiter found ----------
	printf("\nTEST 5: \"HelloWorld\" split by ','\n");
	ft_split_result = ft_split("HelloWorld", ',');
	ft_split_i = 0;
	while (ft_split_result && ft_split_result[ft_split_i])
	{
		printf("[%s]\n", ft_split_result[ft_split_i]);
		free(ft_split_result[ft_split_i]);
		ft_split_i++;
	}
	free(ft_split_result);
	printf("ft_split is successful.\n\n");
	// ft_split end

	// ft_itoa start
	printf("---itoa test---------------------------------------------\n");
	char *ft_itoa_s;

	ft_itoa_s = ft_itoa(0);
	printf("0 -> %s\n", ft_itoa_s);
	free(ft_itoa_s);

	ft_itoa_s = ft_itoa(42);
	printf("42 -> %s\n", ft_itoa_s);
	free(ft_itoa_s);

	ft_itoa_s = ft_itoa(-42);
	printf("-42 -> %s\n", ft_itoa_s);
	free(ft_itoa_s);

	ft_itoa_s = ft_itoa(2147483647);
	printf("INT_MAX -> %s\n", ft_itoa_s);
	free(ft_itoa_s);

	ft_itoa_s = ft_itoa(-2147483648);
	printf("INT_MIN -> %s\n", ft_itoa_s);
	free(ft_itoa_s);
	printf("ft_itoa is successful.\n\n");

	// ft_strmapi start
	printf("---strmapi test---------------------------------------------\n");
	char *ft_strmapi_input_1 = "hello world";
	char *ft_strmapi_result_1;
	char *ft_strmapi_input_2 = "ft_strmapi is fun";
	char *ft_strmapi_result_2;

	printf("--- Testing ft_strmapi ---\n");

	// --- Test Case 1: Odd Index Capitalization ---
	printf("\n**Test 1: Capitalize every second char**\n");
	printf("Input:  \"%s\"\n", ft_strmapi_input_1);

	ft_strmapi_result_1 = ft_strmapi(ft_strmapi_input_1, &to_upper_if_odd_index);

	if (ft_strmapi_result_1)
	{
		printf("Output: \"%s\"\n", ft_strmapi_result_1); // Expected: hElLo wOrLd
		if (strcmp(ft_strmapi_result_1, "hElLo wOrLd") == 0)
			 printf("Result: SUCCESS\n");
		else
			 printf("Result: FAILURE\n");
		free(ft_strmapi_result_1);
	}
	else
		printf("Output: MALLOC FAILED (or NULL input/function).\n");

	// --- Test Case 2: Replace Spaces ---
	printf("\n**Test 2: Replace spaces with underscore**\n");
	printf("Input:  \"%s\"\n", ft_strmapi_input_2);

	ft_strmapi_result_2 = ft_strmapi(ft_strmapi_input_2, &replace_space_with_underscore);

	if (ft_strmapi_result_2)
	{
		printf("Output: \"%s\"\n", ft_strmapi_result_2); // Expected: ft_strmapi_is_fun
		if (strcmp(ft_strmapi_result_2, "ft_strmapi_is_fun") == 0)
			 printf("Result: SUCCESS\n");
		else
			 printf("Result: FAILURE\n");
		free(ft_strmapi_result_2);
	}
	else
		printf("Output: MALLOC FAILED (or NULL input/function).\n");

	// --- Test Case 3: NULL Input ---
	printf("\n**Test 3: NULL Input Check**\n");
	if (ft_strmapi(NULL, &replace_space_with_underscore) == NULL)
		printf("Result: SUCCESS (Handles NULL input)\n");
	else
		printf("Result: FAILURE\n");
	printf("ft_strmapi is successful.\n\n");

	// ft_striteri start
	printf("---ft_striteri test---------------------------------------------\n");
	char ft_striteri_s1[] = "programming is an art";
	char ft_striteri_s2[] = "an apple a day keeps the doctor away";

	printf("--- Testing ft_striteri ---\n");

	// --- Test Case 1: Capitalizing even indices ---
	printf("\n**Test 1: Capitalize Even Index**\n");
	printf("String BEFORE ft_striteri: \"%s\"\n", ft_striteri_s1);

	ft_striteri(ft_striteri_s1, &capitalize_even_index);

	printf("String AFTER ft_striteri:  \"%s\"\n", ft_striteri_s1);
	// Expected: "PrOgRaMmInG iS aN aRt" (P at 0, o at 2, r at 4, etc.)

	// --- Test Case 2: Replacing specific characters ---
	printf("\n**Test 2: Replace 'a' with 'Z'**\n");
	printf("String BEFORE ft_striteri: \"%s\"\n", ft_striteri_s2);

	ft_striteri(ft_striteri_s2, &replace_a_with_Z);

	printf("String AFTER ft_striteri:  \"%s\"\n", ft_striteri_s2);
	// Expected: "Zn Zpple Z dZy keeps the doctor Zway"
	printf("ft_striteri is successful.\n\n");

	// ft_putchar_fd_ start
	printf("--- Testing ft_putchar_fd ---\n");

	// Test 1: Writing 'A' to STDOUT_FILENO (fd 1)
	printf("1. Writing 'A' to STDOUT_FILENO (1):\n");
	ft_putchar_fd('A', 1); // Writes 'A' to the terminal output
	ft_putchar_fd('\n', 1); // Newline for separation

	// Test 2: Writing 'E' to STDERR_FILENO (fd 2)
	printf("2. Writing 'E' to STDERR_FILENO (2):\n");
	ft_putchar_fd('E', 2); // Writes 'E' to the standard error stream
	ft_putchar_fd('\n', 1); // Print newline to STDOUT for proper formatting

	printf("Test finished. If 'A' and 'E' appeared correctly, the function works.\n");
	printf("ft_putchar_fd is successful.\n\n");
	// ft_putchar_fd end

	// ft_putstr_fd_ start
	printf("---ft_putstr_fd test---\n");
	char *ft_putstr_fd_test_str_1 = "Text message 1.";
	char *ft_putstr_fd_test_str_2 = "Test message 2.";
	char *ft_putstr_fd_test_str_3 = "Test message 3.";
	char *ft_putstr_fd_test_str_4 = "Test message 4. NULL string test passed.\n";
	char *ft_putstr_fd_null_ptr = NULL;

	printf("--- Testing ft_putstr_fd ---\n");

	// --- Test 1: Write to STDOUT (file descriptor 1) ---
	printf("Running Test 1...\n");
	ft_putstr_fd(ft_putstr_fd_test_str_1, 1);
	printf("Test 1 complete.\n\n");

	// --- Test 2: Write to STDERR (file descriptor 2) ---
	printf("Running Test 2...\n");
	ft_putstr_fd(ft_putstr_fd_test_str_2, 2);
	printf("Test 2 complete.\n\n");

	// --- Test 3: Write to a file ---
	printf("Running Test 3...\n");
	ft_putstr_fd(ft_putstr_fd_test_str_3, 2);
	printf("Test 3 complete.\n\n");

	// --- Test 4: Handling NULL input ---
	printf("Running Test 4 (NULL string)...\n");
	ft_putstr_fd(ft_putstr_fd_null_ptr, 1);
	ft_putstr_fd(ft_putstr_fd_test_str_4, 1); // If this line executes, the NULL check worked.
	printf("Test 4 complete.\n\n");
	printf("All tests finished.\n");
	printf("ft_putstr_fd is successful.\n\n");
	// ft_putstr_fd end

	//ft_putendl_fd start
	printf("---ft_putendl test---------------------------------------------\n");
	char *ft_putendl_fd_test_str_1 = "Text message ft_putendl_fd 1.";
	char *ft_putendl_fd_test_str_2 = "Test message ft_putendl_fd 2.";
	char *ft_putendl_fd_test_str_3 = "Test message ft_putendl_fd 3.";
	char *ft_putendl_fd_test_str_4 = "Test message ft_putendl_fd 4. NULL string test.";
	char *ft_putendl_fd_null_ptr = NULL;

	printf("--- Testing ft_putendl_fd ---\n");

	// --- Test 1: Write to STDOUT (file descriptor 1) ---
	printf("Running Test 1...\n");
	ft_putendl_fd(ft_putendl_fd_test_str_1, 1);
	printf("Test 1 complete.\n\n");

	// --- Test 2: Write to STDERR (file descriptor 2) ---
	printf("Running Test 2...\n");
	ft_putendl_fd(ft_putendl_fd_test_str_2, 2);
	printf("Test 2 complete.\n\n");

	// --- Test 3: Write to a file ---
	printf("Running Test 3...\n");
	ft_putendl_fd(ft_putendl_fd_test_str_3, 2);
	printf("Test 3 complete.\n\n");

	// --- Test 4: Handling NULL input ---
	printf("Running Test 4 (NULL string)...\n");
	ft_putendl_fd(ft_putendl_fd_null_ptr, 1);
	ft_putendl_fd(ft_putendl_fd_test_str_4, 1); // If this line executes, the NULL check worked.
	printf("Test 4 complete.\n\n");
	printf("All tests finished.\n");
	printf("ft_putendl_fd is successful.\n\n");
	//ft_putendl_fd end

	// ft_putnbr_fd start
	printf("--- Testing ft_putnbr_fd ---------------------------------------------\n");

	// Test Case 1: Positive number
	int ft_putnbr_fd_n1 = 42;
	printf("Test 1: Positive (Expected: 42)\n");
	ft_putnbr_fd(ft_putnbr_fd_n1, 1);
	printf("\n\n");

	// Test Case 2: Zero
	int ft_putnbr_fd_n2 = 0;
	printf("Test 2: Zero (Expected: 0)\n");
	ft_putnbr_fd(ft_putnbr_fd_n2, 1);
	printf("\n\n");

	// Test Case 3: Negative number
	int ft_putnbr_fd_n3 = -123;
	printf("Test 3: Negative (Expected: -123)\n");
	ft_putnbr_fd(ft_putnbr_fd_n3, 1);
	printf("\n\n");

	// Test Case 4: Larger number
	int ft_putnbr_fd_n4 = 987654321;
	printf("Test 4: Large positive (Expected: 987654321)\n");
	ft_putnbr_fd(ft_putnbr_fd_n4, 1);
	printf("\n\n");

	// Test Case 5: INT_MIN (Critical case)
	int ft_putnbr_fd_n5 = INT_MIN; // Typically -2147483648
	printf("Test 5: INT_MIN (Expected: -2147483648)\n");
	ft_putnbr_fd(ft_putnbr_fd_n5, 1);
	printf("\n\n");

	printf("--- Testing Complete ---\n");
	printf("ft_putnbr_fd is successful.\n\n");
	// ft_putnbr_fd end

	// BONUS PART START
	printf("---BONUS PART---------------------------------------------\n");
	// ft_lstnew_ start
	printf("---ft_lstnew test---------------------------------------------\n");
	// Step 1: Create some content
	char *ft_lstnew_my_data;
	t_list *ft_lstnew_node;

	ft_lstnew_my_data = "Hello, Lstnew!";

	// Step 2: Call your function

	ft_lstnew_node = ft_lstnew(ft_lstnew_my_data);

	// Step 3: Check if it worked
	if (ft_lstnew_node == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}

	// Step 4: Print the results
	printf("--- New Node Created ---\n");
	printf("Node address: %p\n", (void *)ft_lstnew_node);
	printf("Content expected \"Hello, Lstnew!\":\nActual: %s\n", (char *)ft_lstnew_node->content);

	if (ft_lstnew_node->next == NULL)
		printf("Next pointer: NULL (Correct)\n");
	else
		printf("Next pointer: %p (Incorrect)\n", (void *)ft_lstnew_node->next);

	// Step 5: Clean up (Free memory)
	free(ft_lstnew_node);
	printf("ft_lstnew is successful.\n\n");
	// ft_lstnew end

	// ft_lstadd_front start
	printf("---ft_lstadd_front test---------------------------------------------\n");
	// 1. Initialize the list pointer to NULL (Empty list)
	t_list *ft_lstadd_front_head = NULL;

	// 2. Create two nodes
	t_list *ft_lstadd_front_node1;
	t_list *ft_lstadd_front_node2;

	ft_lstadd_front_node1 = ft_lstnew("World");
	ft_lstadd_front_node2 = ft_lstnew("Hello");
	// 3. Add "World" to the list (List: World -> NULL)
	ft_lstadd_front(&ft_lstadd_front_head, ft_lstadd_front_node1);

	// 4. Add "Hello" to the FRONT (List: Hello -> World -> NULL)
	// Note: We pass &head because the function expects t_list **
	ft_lstadd_front(&ft_lstadd_front_head, ft_lstadd_front_node2);

	// 5. Verify the order
	printf("--- Linked List Test ---------------------------------------------\n");

	t_list	*ft_lstadd_front_current;
	int		ft_lstadd_front_i;

	ft_lstadd_front_current = ft_lstadd_front_head;
	ft_lstadd_front_i = 1;
	while (ft_lstadd_front_current)
	{
		printf("Node %d: %s\n", ft_lstadd_front_i, (char *)ft_lstadd_front_current->content);
		ft_lstadd_front_current = ft_lstadd_front_current->next;
		ft_lstadd_front_i++;
	}

	// 6. Cleanup (Standard practice, though OS cleans up after main)
	free(ft_lstadd_front_node1);
	free(ft_lstadd_front_node2);
	printf("ft_lstadd_front is successful.\n\n");
	// ft_lstadd_front end

	// ft_lstsize start
	printf("---ft_lstsize test---------------------------------------------\n");
	t_list *ft_lstsize_head = NULL;
	t_list *ft_lstsize_node1;
	t_list *ft_lstsize_node2;
	t_list *ft_lstsize_node3;

	ft_lstsize_node1 = ft_lstnew("World");
	ft_lstsize_node2 = ft_lstnew("Hello");
	ft_lstsize_node3 = ft_lstnew("42");

	// Add them: 42 -> Hello -> World -> NULL
	ft_lstadd_front(&ft_lstsize_head, ft_lstsize_node1);
	ft_lstadd_front(&ft_lstsize_head, ft_lstsize_node2);
	ft_lstadd_front(&ft_lstsize_head, ft_lstsize_node3);

	// --- TEST FT_LSTSIZE ---
	int ft_lstsize_size = ft_lstsize(ft_lstsize_head);

	printf("--- Size Test ---------------------------------------------\n");
	printf("Expected size: 42 -> Hello -> World -> NULL: 3\n");
	printf("Actual size: %d\n", ft_lstsize_size);

	if (ft_lstsize_size == 3)
		printf("SUCCESS: Size is correct.\n");
	else
		printf("FAILURE: Size is wrong.\n");

	// Cleanup
	free(ft_lstsize_node1);
	free(ft_lstsize_node2);
	free(ft_lstsize_node3);
	printf("ft_lstsize is successful.\n\n");
	// ft_lstsize end

	// ft_lstlast start
	printf("---ft_lstlast test---------------------------------------------\n");
	t_list *ft_lstlast_head = NULL;
	t_list *ft_lstlast_node1;
	t_list *ft_lstlast_node2;
	t_list *ft_lstlast_node3;
	t_list *ft_lstlast_last;

	/// --- TEST 1: Empty List ---
	printf("--- Test 1: Empty List---------------------------------------------\n");
	ft_lstlast_last = ft_lstlast(ft_lstlast_head);
	if (ft_lstlast_last == NULL)
		printf("Success: Empty list returns NULL.\n\n");
	else
		printf("Failure: Expected NULL, got %p\n\n", ft_lstlast_last);

	/// --- TEST 2: Populated List ---
	printf("--- Test 2: Populated List---------------------------------------------\n");

	/// Create nodes: "1" -> "2" -> "3"
	ft_lstlast_node1 = ft_lstnew("Node 1");
	ft_lstlast_node2 = ft_lstnew("Node 2");
	ft_lstlast_node3 = ft_lstnew("Node 3");
	printf("Created nodes containing text: 'Node 1', 'Node 2', and 'Node 3'.\n");
	/// Adding nodes: Node 1 -> Node 2 -> Node 3 -> NULL
	ft_lstlast_head = ft_lstlast_node1;
	ft_lstlast_node1->next = ft_lstlast_node2;
	ft_lstlast_node2->next = ft_lstlast_node3;
	ft_lstlast_node3->next = NULL;

	/// Find the last node
	ft_lstlast_last = ft_lstlast(ft_lstlast_head);

	if (ft_lstlast_last == ft_lstlast_node3)
	{
		printf("Success: Last node address matches Node 3.\n");
		printf("Content of last node: %s\n", (char *)ft_lstlast_last->content);
	}
	else
	{
		printf("Failure: Returned wrong node.\n");
	}

	/// Cleanup
	free(ft_lstlast_node1);
	free(ft_lstlast_node2);
	free(ft_lstlast_node3);
	printf("ft_lstlast is successful.\n\n");
	// ft_lstlast end

	// ft_lstadd_back start
	printf("---ft_lstadd_back test---------------------------------------------\n");
	t_list *ft_lstadd_back_head = NULL; // Start with an empty list

	// Create 3 nodes
	t_list *ft_lstadd_back_node1 = ft_lstnew("Node 1 (Head)");
	t_list *ft_lstadd_back_node2 = ft_lstnew("Node 2");
	t_list *ft_lstadd_back_node3 = ft_lstnew("Node 3 (Tail)");

	printf("--- Testing ft_lstadd_back ---\n");

	// TEST 1: Add to empty list
	// 'head' is NULL. After this, head should point to node1.
	ft_lstadd_back(&ft_lstadd_back_head, ft_lstadd_back_node1);

	if (ft_lstadd_back_head == ft_lstadd_back_node1)
		printf("1. Add to empty list: OK\n");
	else
		printf("1. Add to empty list: FAILED\n");

	// TEST 2: Add to existing list
	// Should append node2 after node1
	ft_lstadd_back(&ft_lstadd_back_head, ft_lstadd_back_node2);

	// TEST 3: Add another
	// Should append node3 after node2
	ft_lstadd_back(&ft_lstadd_back_head, ft_lstadd_back_node3);

	// Verify the order
	printf("\n--- Verifying List Order ---\n");
	t_list *ft_lstadd_back_current = ft_lstadd_back_head;
	while (ft_lstadd_back_current)
	{
		printf("%s\n", (char *)ft_lstadd_back_current->content);
		ft_lstadd_back_current = ft_lstadd_back_current->next;
	}

	// Simple verify of links
	if (ft_lstadd_back_head->next == ft_lstadd_back_node2
		&& ft_lstadd_back_head->next->next == ft_lstadd_back_node3)
		{
			printf("\nLinkage Check: OK (1 -> 2 -> 3)\n");
			printf("Last node is: %s\n", (char *)ft_lstadd_back_node3->content);
		}
		else
			printf("\nLinkage Check: FAILED\n");

	// Clean up
	free(ft_lstadd_back_node1);
	free(ft_lstadd_back_node2);
	free(ft_lstadd_back_node3);
	printf("ft_lstadd_back is successful.\n\n");
	// ft_lstadd_back end

	// ft_lstdelone_start
	printf("---ft_lstdelone test---------------------------------------------\n");
	// Step 1: Create content that MUST be malloced
	// We cannot pass "Hello" directly because you cannot free a static string.
	char *ft_lstdelone_data = strdup("Secret Data");

	// Step 2: Create the node
	t_list *ft_lstdelone_node = ft_lstnew(ft_lstdelone_data);

	if (!ft_lstdelone_node)
		return (1);

	printf("Node created and contains \"Secret Data\".\nAddress: %p\nContent: %s\n\n", ft_lstdelone_node, (char *)ft_lstdelone_node->content);

	// Step 3: Delete the node
	printf("--- Calling ft_lstdelone ---\n");
	ft_lstdelone(ft_lstdelone_node, free);

	// Step 4: Verification
	// We cannot print 'node' now because it is freed memory (Dangling pointer).
	// If we try to access it, we get a Segmentation Fault or garbage data.
	printf("Node deleted. If you see this and no crash/leaks, it worked.\n");
	printf("ft_lstdelone is successful.\n\n");
	// ft_lstdelone end

	//ft_lstclear_ start -------------------------------------------------------
	printf("---ft_lstclear test---------------------------------------------\n");
	// 1. Create 3 nodes with MALLOC'D content (strdup)
	// We use strdup so we have something valid to free.
	t_list *ft_lstclear_node1 = ft_lstnew(strdup("Node 1"));
	t_list *ft_lstclear_node2 = ft_lstnew(strdup("Node 2"));
	t_list *ft_lstclear_node3 = ft_lstnew(strdup("Node 3"));

	// 2. Link them: 1 -> 2 -> 3 -> NULL
	ft_lstclear_node1->next = ft_lstclear_node2;
	ft_lstclear_node2->next = ft_lstclear_node3;

	// 3. Pointer to the head
	t_list *ft_lstclear_head;

	ft_lstclear_head = ft_lstclear_node1;

	printf("--- Before Clear ---\n");
	printf("Head address: %p\n", (void *)ft_lstclear_head);

	// 4. Clear the list
	printf("\n--- Clearing List ---\n");
	ft_lstclear(&ft_lstclear_head, delete_content);

	// 5. Check the result
	printf("\n--- After Clear ---\n");
	if (ft_lstclear_head == NULL)
		printf("Success: Head is NULL.\n");
	else
		printf("Failure: Head is still %p (Dangling Pointer!)\n", (void *)ft_lstclear_head);
	printf("ft_lstclear is successful.\n\n");
	//ft_lstclear end

	// ft_lstiter_ start
	printf("---ft_lstiter test---------------------------------------------\n");
	// Step 1: Create list nodes with writable memory (strdup)
	t_list *ft_lstiter_node1 = ft_lstnew(strdup("one"));
	t_list *ft_lstiter_node2 = ft_lstnew(strdup("two"));
	t_list *ft_lstiter_node3 = ft_lstnew(strdup("three"));

	// Step 2: Link them
	ft_lstiter_node1->next = ft_lstiter_node2;
	ft_lstiter_node2->next = ft_lstiter_node3;

	// Step 3: Print BEFORE iteration
	printf("--- Before Iteration ---\n");
	t_list *ft_lstiter_header = ft_lstiter_node1;
	while (ft_lstiter_header)
	{
		printf("%s\n", (char *)ft_lstiter_header->content);
		ft_lstiter_header = ft_lstiter_header->next;
	}

	// Step 4: Apply ft_lstiter
	// We pass the address of the first node and our uppercase function
	ft_lstiter(ft_lstiter_node1, modify_to_upper);

	// Step 5: Print AFTER iteration
	printf("\n--- After Iteration ---\n");
	ft_lstiter_header = ft_lstiter_node1;
	while (ft_lstiter_header)
	{
		printf("%s\n", (char *)ft_lstiter_header->content);
		ft_lstiter_header = ft_lstiter_header->next;
	}

	// Step 6: Clean up (Free content and nodes)
	// (Manually freeing for this simple test)
	free(ft_lstiter_node1->content); free(ft_lstiter_node1);
	free(ft_lstiter_node2->content); free(ft_lstiter_node2);
	free(ft_lstiter_node3->content); free(ft_lstiter_node3);
	printf("ft_lstiter is successful.\n\n");
	// ft_lstiter end

	// ft_lstmap_ start------------------------------------------------------
	printf("---ft_lstmap test---------------------------------------------\n");
	t_list *list_a = NULL;
	t_list *list_b = NULL;

	// 1. Create List A: 1 -> 2 -> 3
	int *p1 = malloc(sizeof(int)); *p1 = 1;
	int *p2 = malloc(sizeof(int)); *p2 = 2;
	int *p3 = malloc(sizeof(int)); *p3 = 3;

	ft_lstadd_back(&list_a, ft_lstnew(p1));
	ft_lstadd_back(&list_a, ft_lstnew(p2));
	ft_lstadd_back(&list_a, ft_lstnew(p3));

	// 2. Run ft_lstmap
	printf("--- Mapping List A to List B (x2) ---\n");
	list_b = ft_lstmap(list_a, map_multiply_two, del_int);

	// 3. Verify List A (Should be unchanged)
	printf("List A (Original): ");
	t_list *curr = list_a;
	while (curr) {
		printf("%d -> ", *(int *)curr->content);
		curr = curr->next;
	}
	printf("NULL\n");

	// 4. Verify List B (Should be doubled)
	printf("List B (Mapped):   ");
	curr = list_b;
	while (curr) {
		printf("%d -> ", *(int *)curr->content);
		curr = curr->next;
	}
	printf("NULL\n");

	// 5. Cleanup
	ft_lstclear(&list_a, del_int);
	ft_lstclear(&list_b, del_int);
	printf("ft_lstmap is successful.\n\n");
	// ft_lstmap end
	printf("---BONUS PART COMPLETED---------------------------------------------\n");
	// BONUS PART END

/////////////////////////////////////////////////////////////////////////////
	return (0);
}

//-----------BONUS PART FUNCTIONS -----------------------------------
//---------ft_lstmap functions ---------------------------------------
// 1. DELETE FUNCTION (Used by ft_lstclear)
static void del_int(void *content)
{
	free(content);
}

// 2. MAPPING FUNCTION (The 'f')
// Takes an int, multiplies by 2, returns a NEW malloc'd int.
static void *map_multiply_two(void *content)
{
	int *original = (int *)content;
	int *new_value = malloc(sizeof(int));

	if (!new_value)
		return (NULL);

	*new_value = (*original) * 2;
	return (new_value);
}

// --------- Testing ft_lstiter --------------------------------------------
// This function converts received str to UPPERCASE.
static void modify_to_upper(void *content)
{
	char *s = (char *)content;
	int i = 0;

	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32; // ASCII math: 'a' - 32 = 'A'
		i++;
	}
}

// THE DELETE FUNCTION
// It matches the prototype: void (*del)(void *)
static void delete_content(void *content)
{
	// In this test, we assume content is a string.
	printf("Deleting content: %s\n", (char *)content);
	free(content);
}

// --- Functions for testing ft_strmapi, ---
/// --- Transformation Function 1: Capitalize every second character
static char	to_upper_if_odd_index(unsigned int i, char c)
{
	// Check if the index is odd AND the character is a lowercase letter
	if (i % 2 != 0 && c >= 'a' && c <= 'z')
		return (c - 32); // ASCII difference between lowercase and uppercase
	return (c);
}

// --- Transformation Function 2: Replace all ' ' with '_'
// --- f(index, character)
static char	replace_space_with_underscore(unsigned int i, char c)
{
	// The index 'i' is ignored in this simple case
	(void)i;
	if (c == ' ')
		return ('_');
	return (c);
}

// --- Functions for testing ft_striteri---
static void	capitalize_even_index(unsigned int i, char *c_ptr)
{
	if (i % 2 == 0 && *c_ptr >= 'a' && *c_ptr <= 'z')
		*c_ptr -= 32;
}

static void	replace_a_with_Z(unsigned int i, char *c_ptr)
{
	(void)i;

	if (*c_ptr == 'a')
		*c_ptr = 'Z';
}
