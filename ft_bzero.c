/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:51:41 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/16 17:10:36 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *) s;
	while (n > 0)
	{
		*(tmp++) = 0;
		n--;
	}
}

/*int main() {
    // Create an array of 10 bytes, initialized with non-zero values
    unsigned char arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Print the array before ft_bzero (should be non-zero)
    printf("Before ft_bzero:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the ft_bzero function to set the first 5 bytes to zero
    ft_bzero(arr, 5);

    // Print the array after ft_bzero (first 5 elements should be zero)
    printf("After ft_bzero:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}*/