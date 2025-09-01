/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:23:43 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:45:12 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int   main(void)
{
        t_list  *head = NULL;
        t_list  *current = NULL;
        char    *content_1 = "Added first";
        char    *content_2 = "Added second";
        char    *content_3 = "Added third";
        char    *content_4 = "Added last";

        head = ft_lstnew(content_1);
        head->next = ft_lstnew(content_2);
        ft_lstadd_front(&head, ft_lstnew(content_3));
        ft_lstadd_front(&head, ft_lstnew(content_4));
        current = head;
        printf("List:\n");
        while (current)
        {
                printf("\"%s\" -> ", (char *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        while (head != NULL)
        {
                current = head;
                head = head->next;
                free(current);
        }
        return (0);
}*/
