/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   list_new_andback.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 18:55:18 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 23:08:33 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_stock		*ft_fillnew(int size)
{
	t_stock		*lstnew;

	if (!(lstnew = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	lstnew->str = (char *)malloc(sizeof(char) * size);
	lstnew->next = NULL;
	return (lstnew);
}

void		ft_filladdback(t_stock **alst, int size)
{
	t_stock		*temp;

	if (alst)
	{
		temp = *alst;
		while (temp->next)
			temp = temp->next;
		temp->next = ft_fillnew(size);
	}
}
