/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:38:50 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/18 11:16:46 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) b;
	while (len > 0)
	{
		*(tmp++) = (unsigned char) c;
		len--;
	}
	return (b);
}

/*int main() {
    // Create an array of 10 bytes filled with zeros
    unsigned char arr[10] = {0};

    // Print the array before memset 
    printf("Before memset:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the memset function to fill the array with the value 42 
    ft_memset(arr, 42, -1);

    // Print the array after memset
    printf("After memset:\n");
	for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}*/