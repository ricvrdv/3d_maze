/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:30:33 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:51:34 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void	del_content(void *content);

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
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
        t_list  *current;
        int     *content_1 = malloc(sizeof(int));
        int     *content_2 = malloc(sizeof(int));
        int     *content_3 = malloc(sizeof(int));

        *content_1 = 0;
        *content_2 = 1;
        *content_3 = 2;
        head = ft_lstnew(content_1);
        second = ft_lstnew(content_2);
        third = ft_lstnew(content_3);
        head->next = second;
        second->next = third;
        printf("Initial list:\n");
        current = head;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        ft_lstdelone(second, del_content);
        head->next = third;
        printf("List after deleting second node:\n");
        current = head;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        ft_lstdelone(head, del_content);
        ft_lstdelone(third, del_content);
        return (0);
}*/
