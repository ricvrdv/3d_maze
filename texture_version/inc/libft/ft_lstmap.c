/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:37:45 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:50:04 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void	*add_one(void *content);
//static void	del_content(void *content);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	new_list = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			(*del)(content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
static void	*add_one(void *content)
{
	int	*num;

	num = malloc(sizeof(int));
	if (!num)
		return (NULL);
	*num = *(int *)content + 1;
	return (num);
}

static void	del_content(void *content)
{
	free(content);
}

#include <stdio.h>

int     main(void)
{
        t_list  *head = NULL;
        t_list  *current = NULL;
        t_list  *new_lst = NULL;
        int     *content;
        int     i;

        i = 0;
        while (i < 4)
        {
                content = malloc(sizeof(int));
                *content = i;
                ft_lstadd_back(&head, ft_lstnew(content));
                i++;
        }
        printf("Original list:\n");
        current = head;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        new_lst = ft_lstmap(head, add_one, del_content);
        printf("New list:\n");
        current = new_lst;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        ft_lstclear(&head, del_content);
        ft_lstclear(&new_lst, del_content);
        return (0);
}*/
