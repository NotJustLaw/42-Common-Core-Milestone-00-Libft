/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:46:16 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/21 15:42:11 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*part;

	part = malloc(sizeof(t_list));
	if (!part)
		return (NULL);
	part->content = content;
	part->next = NULL;
	return (part);
}

/*int main(void)
{
    t_list *new_node;
    char *str = "Hello, World!";

   ail new_node = ft_lstnew(str);
    if (new_node)
    {
        printf("Content of the new node: %s\n", (char *)new_node->content);
        free(new_node);
    }
    return 0;
}*/