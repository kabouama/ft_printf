/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/28 21:44:23 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 17:59:11 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		free_list(t_stock *begin)
{
	if (begin->next)
		free_list(begin->next);
	free(begin->str);
	begin->next = NULL;
	free(begin);
}

t_param		*affiche_word(t_stock *stck, t_param *prm, va_list list)
{
	if (!(stck->str[prm->i] == '%' || stck->str[prm->i] == '#'))
	{
		ft_putstr(stck->str);
		prm->len += ft_strlen(stck->str);
	}
	else
	{
		prm->test = 1;
		prm->i++;
		process(prm, stck, list);
	}
	return (prm);
}

int			ft_printf(const char *format, ...)
{
	t_stock		*stck;
	t_stock		*begin;
	t_param		*prm;
	va_list		list;
	int			len;

	va_start(list, format);
	if (!(prm = (t_param*)malloc(sizeof(t_param))))
		return (0);
	init_prm(prm);
	len = 0;
	stck = ft_decoupe(format);
	begin = stck;
	while (stck->next)
	{
		init_prm2(prm);
		prm = affiche_word(stck, prm, list);
		stck = stck->next;
		if (prm->test == 1)
			len++;
	}
	len = prm->len;
	free_prm(prm, begin);
	va_end(list);
	return (len);
}
