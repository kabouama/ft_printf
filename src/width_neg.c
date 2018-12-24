/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   width_neg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 19:05:41 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 21:27:52 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	affiche_width_neg(t_param *prm, long var)
{
	if ((prm->flags == '+' || prm->flags2 == '+') && !prm->preci)
		ft_putchar('+');
	if (prm->type == 'o' || prm->type == 'O')
		prm = typee_o(var, prm);
	else if (prm->type == 'x' || prm->type == 'X')
		prm = typee_x(var, prm);
	else if (prm->type == 'c')
	{
		ft_putchar(var);
		prm->len++;
	}
	else if (prm->type == 'u')
		prm = typee_u(var, prm);
}

int		modif_width_neg_o(t_param *prm, long var)
{
	int flg;

	flg = 0;
	if ((prm->type == 'o' || prm->type == 'O') && prm->preci)
	{
		prm->len_o = 0;
		if (prm->preci > ft_nbrlen_base_o(var, "01234567", prm))
			prm->width -= prm->preci;
		else
		{
			prm->len_o = 0;
			prm->width -= ft_nbrlen_base_o(var, "01234567", prm);
		}
		flg = 1;
	}
	else if (prm->type == 'o' || prm->type == 'O')
	{
		prm->width -= prm->tmp2;
		flg = 1;
	}
	return (flg);
}

void	type_neg_x(t_param *prm, long var)
{
	prm->len_o = 0;
	if (prm->preci > ft_nbrlen_base_o(var, "0123456789abcdef", prm))
		prm->width -= prm->preci;
	else
	{
		prm->len_o = 0;
		prm->width -= ft_nbrlen_base_o(var, "0123456789abcdef", prm);
	}
}

void	modif_width_neg(t_param *prm, long var)
{
	if (modif_width_neg_o(prm, var) == 0)
	{
		if ((prm->type == 'x' || prm->type == 'X') && prm->preci)
		{
			type_neg_x(prm, var);
		}
		else if ((prm->type == 'x' || prm->type == 'X') && !prm->preci)
			prm->width -= prm->tmp2;
		else if ((prm->type == 'u' || prm->type == 'U') && prm->preci)
		{
			if (prm->preci > ft_nbrlen(var))
				prm->width -= prm->preci;
			else
				prm->width -= ft_nbrlen(var);
		}
		else if (prm->type == 'c')
			prm->width--;
		else if (prm->width > prm->preci)
			prm->width -= ft_nbrlen_ll(var);
	}
}

void	width_neg(t_param *prm, long var)
{
	affiche_width_neg(prm, var);
	modif_width_neg(prm, var);
	if ((prm->flags == '#' || prm->flags2 == '#')
			&& (prm->type == 'x' || prm->type == 'X'))
		prm->width -= 2;
	prm->temp = 1;
	while ((prm->width > 0))
	{
		prm->width--;
		ft_putchar(' ');
		prm->j++;
		prm->len++;
	}
}
