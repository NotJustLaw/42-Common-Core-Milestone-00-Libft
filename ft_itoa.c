/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:20:47 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/21 11:55:26 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n);
static char	*handle(long nb, int len);

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	if (nb == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	len = ft_intlen(nb);
	str = handle(nb, len);
	return (str);
}

static int	ft_intlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*handle(long nb, int len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}

/*int	main(void)
{
	int test_cases[] = {
		0,
		42,
		-42,
		2147483647,
		-2147483648
	};
	int size = sizeof(test_cases) / sizeof(int);
	int i;

	for (i = 0; i < size; i++)
	{
		char *result = ft_itoa(test_cases[i]);
		if (result)
		{
			printf("ft_itoa(%d) = \"%s\"\n", test_cases[i], result);
			free(result); // don't forget to free malloc'd memory!
		}
		else
			printf("ft_itoa(%d) = NULL (malloc failed)\n", test_cases[i]);
	}
	return (0);
}*/