/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:35:33 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:49:05 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//static void	add_one(void *content);

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
static void	add_one(void *content)
{
	int	*num;

	num = (int *)content;
	(*num)++;
}

#include <stdio.h>

int     main(void)
{
        t_list  *head = NULL;
        t_list  *current = NULL;
        int     content_1 = 0;
        int     content_2 = 1;
        int     content_3 = 2;
        int     content_4 = 3;

        head = ft_lstnew(&content_1);
        current = head;
        current->next = ft_lstnew(&content_2);
        current = current->next;
        current->next = ft_lstnew(&content_3);
        current = current->next;
        current->next = ft_lstnew(&content_4);
        printf("List:\n");
        current = head;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
                current = current->next;
        }
        printf("NULL\n");
        ft_lstiter(head, add_one);
        printf("List after add_one:\n");
        current = head;
        while (current)
        {
                printf("%d -> ", *(int *)current->content);
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
