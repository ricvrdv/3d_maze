/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:32:46 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:48:25 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void	del_content(void *content);

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}

/*
static void	del_content(void *content)
{
	free(content);
}

#include <stdio.h>

int     main(void)
{
        t_list  *head = NULL;
        t_list  *second = NULL;
        t_list  *third = NULL;
        t_list  *fourth = NULL;
        t_list  *current;
        int     *content_1 = malloc(sizeof(int));
        int     *content_2 = malloc(sizeof(int));
        int     *content_3 = malloc(sizeof(int));
        int     *content_4 = malloc(sizeof(int));

        *content_1 = 0;
        *content_2 = 1;
        *content_3 = 2;
        *content_4 = 3;
        head = ft_lstnew(content_1);
        second = ft_lstnew(content_2);
        third = ft_lstnew(content_3);
        fourth = ft_lstnew(content_4);
        head->next = second;
        second->next = third;
        third->next = fourth;
        printf("Initial list:\n");
        current = head;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        ft_lstclear(&second, del_content);
        head->next = NULL;
        printf("List after deleting second node and its successors:\n");
        current = head;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        ft_lstdelone(head, del_content);
        return (0);
}*/
