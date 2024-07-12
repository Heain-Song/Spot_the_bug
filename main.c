/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:21:30 by hesong            #+#    #+#             */
/*   Updated: 2024/07/12 11:43:45 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void test_ft_strlen()
{
	const char *test_strings[] = {
		"",
		"Hello, world!",
		"42",
		"Bonjour",
		"This is a test",
		"TIG.........",
	};

    size_t expected_lengths[] = {
		0,
		13,
		2,
		7,
		14,
		12,
	};

	printf("Test for ft_strlen():\n");
	for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++)
	{
		size_t result;
		if (test_strings[i] == NULL) {
			printf("ft_strlen(NULL) = undefined behavior (handle gracefully)\n");
		}
		else
		{
			result = ft_strlen(test_strings[i]);
			printf("ft_strlen(\"%s\") = %zu, expected = %zu\n", test_strings[i], result, expected_lengths[i]);
		}
	}
}

void test_ft_putnbr_fd()
{
	int fd = 1; // Standard output

	printf("Test for ft_putnbr_fd():\n");
	ft_putnbr_fd(0, fd);
	printf("\n");

	ft_putnbr_fd(-42, fd);
	printf("\n");

	ft_putnbr_fd(2147483647, fd); // INT_MAX
	printf("\n");

	ft_putnbr_fd(-2147483648, fd); // INT_MIN
	printf("\n");

	ft_putnbr_fd(2147483648, fd); // Overflow case
	printf("\n");
}

void test_ft_isalnum()
{
	printf("Test for ft_isalnum():\n");
	char test_chars[] = {'a', 'Z', '1', '!', ' ', 'A', 'z', '0', '#', '9'};
	int expected_results[] = {1, 1, 1, 0, 0, 1, 1, 1, 0, 1};

	for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++) {
		int result = ft_isalnum(test_chars[i]);
		printf("ft_isalnum('%c') = %d, expected = %d\n", test_chars[i], result, expected_results[i]);
	}
}

int main(void)
{
	test_ft_isalnum();
	printf("\n");
	test_ft_putnbr_fd();
	printf("\n");
	test_ft_strlen();
	return 0;
}
