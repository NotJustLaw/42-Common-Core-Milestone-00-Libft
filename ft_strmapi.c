/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:30:41 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/18 13:23:05 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int main(void)
{
    // Test string
    char str[] = "hello world";
    
    // Call ft_strmapi
	int i = 0;
	while (str[i])
	{
		char *result = ft_strmapi(str, ft_toupper(str[i]));
		i++;
	}
    // Print the result
    if (result)
    {
        printf("Original string: %s\n", str);
        printf("Modified string: %s\n", result);
        free(result);  // Don't forget to free the allocated memory
    }
    else
    {
        printf("Memory allocation failed!\n");
    }
    
    return 0;
}*/