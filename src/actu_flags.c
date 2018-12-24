/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   actu_flags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 19:05:17 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 18:21:05 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_param		*actu_flags(t_param *prm, t_stock *s)
{
	int		tmp;

	tmp = 0;
	prm->flags = 0;
	prm->flags2 = 0;
	prm->flags3 = 'z';
	while (ft_strchr("#0-+ ", s->str[prm->i]))
	{
		if (tmp == 0)
			prm->flags = s->str[prm->i];
		else if (tmp == 1)
		{
			prm->flags2 = s->str[prm->i];
			tmp = 2;
		}
		else if (tmp == 2)
			prm->flags3 = s->str[prm->i];
		prm->i++;
		while (ft_strchr("#0-+ ", s->str[prm->i])
				&& (s->str[prm->i] == prm->flags))
			prm->i++;
		tmp = 1;
	}
	return (prm);
}
