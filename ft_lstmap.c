/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuhlcke <skuhlcke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:25:17 by skuhlcke          #+#    #+#             */
/*   Updated: 2025/04/21 15:44:29 by skuhlcke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* void	print_list(t_list *node)
{
	if (!node)
	{
		printf("List is empty\n");
		return;
	}
	while (node)
	{
		printf("%s", (char *)node->content);
		if (node->next)
			printf(" -> ");
		node = node->next;
	}
	printf("\n");
}

void	*uppercase_content(void *content)
{
	char *str = (char *)content;
	char *new_str = strdup(str);
	if (!new_str)
		return (NULL);
	
	for (int i = 0; new_str[i]; i++)
		new_str[i] = toupper((unsigned char)new_str[i]);

	return (new_str);
}

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *list = NULL;
	t_list *new_list = NULL;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew(strdup("First Node"));
	node2 = ft_lstnew(strdup("Second Node"));
	node3 = ft_lstnew(strdup("Third Node"));

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	printf("\n");
	printf("Original List:\n");
	print_list(list);
	printf("\n");

	new_list = ft_lstmap(list, uppercase_content, del_content);

	printf("New List after ft_lstmap (uppercase transformation):\n");
	print_list(new_list);
	printf("\n");

	while (list)
	{
		t_list *tmp = list;
		list = list->next;
		ft_lstdelone(tmp, del_content);
	}

	while (new_list)
	{
		t_list *tmp = new_list;
		new_list = new_list->next;
		ft_lstdelone(tmp, del_content);
	}

	return (0);
} */