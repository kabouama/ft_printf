/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_width_princi.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 18:27:48 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 00:09:00 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	affiche_space(t_param *prm)
{
	while (prm->width > 0)
	{
		prm->width--;
		ft_putchar(' ');
		prm->j++;
		prm->len++;
	}
}

void	no_preci(t_param *prm, long var)
{
	if (prm->type == 'o')
		prm->width -= ft_nbrlen_base_oo(var, "01234567", prm);
	else if (prm->type == 'x' || prm->type == 'X')
	{
		if (prm->type == 'x')
			prm->width -= ft_nbrlen_base_o(var, "0123456789abcdef", prm);
		else
			prm->width -= ft_nbrlen_base_o(var, "0123456789ABCDEF", prm);
		if ((prm->flags == '#' || prm->flags2 == '#') && var != 0)
			prm->width -= 2;
	}
	else if (prm->type == 'c')
		prm->width--;
	else
		prm->width -= ft_nbrlen(var);
	if ((prm->flags == '#' || prm->flags2 == '#')
			&& (prm->type != 'x' && prm->type != 'X'))
		prm->width--;
	if (prm->type == 'o' && var == 0
			&& (prm->flags == '#' || prm->flags2 == '#'))
		prm->width++;
	affiche_space(prm);
}

void	preci_positif_width_x(t_param *prm, long var)
{
	prm->len_o = 0;
	if (prm->type == 'x')
	{
		if (prm->preci > ft_nbrlen_base_o(var, "0123456789abcdef", prm))
			prm->width -= prm->preci;
		else
		{
			prm->len_o = 0;
			prm->width -= ft_nbrlen_base_o(var, "0123456789abcdef", prm);
		}
	}
	else
	{
		prm->len_o = 0;
		if (prm->preci > ft_nbrlen_base_o(var, "0123456789ABCDEF", prm))
			prm->width -= prm->preci;
		else
		{
			prm->len_o = 0;
			prm->width -= ft_nbrlen_base_o(var, "0123456789ABCDEF", prm);
		}
	}
}

void	preci_positif(t_param *prm, long var)
{
	if (prm->preci != -5 && prm->preci > ft_nbrlen(var)
			&& prm->type != 'x' && prm->type != 'X')
		prm->width -= prm->preci;
	else if ((prm->type == 'o' || prm->type == 'O') && var != 0)
		prm->width -= ft_nbrlen_base_o(var, "01234567", prm);
	else if ((prm->type == 'x' || prm->type == 'X') && var != 0)
		preci_positif_width_x(prm, var);
	else if (var > 0)
		prm->width -= ft_nbrlen(var);
	if ((prm->flags == '#' || prm->flags2 == '#')
			&& (prm->type == 'x' || prm->type == 'X') && var != 0)
		prm->width -= 2;
	else if ((prm->flags == '#' || prm->flags2 == '#')
			&& prm->preci < ft_nbrlen_base_o(var, "01234567", prm)
			&& prm->type != 'x' && prm->type != 'X')
		prm->width--;
	affiche_space(prm);
}

long	check_width(t_param *prm, long var)
{
	if (prm->width && ((prm->flags != '0' && prm->flags2 != '0')
				|| (prm->preci)))
	{
		if (((prm->flags == '#' && prm->flags2 == '-')
					|| (prm->flags == '-' && prm->flags2 == '#'))
				&& var > 0 && prm->type != 'x' && prm->type != 'X')
		{
			ft_putchar('0');
			prm->width--;
			prm->len++;
		}
		if ((prm->flags == '-' || prm->flags2 == '-'))
			width_neg(prm, var);
		if (!(prm->preci))
			no_preci(prm, var);
		else if (prm->preci && prm->width > prm->preci
				&& prm->width > ft_nbrlen(var))
			preci_positif(prm, var);
	}
	return (var);
}
