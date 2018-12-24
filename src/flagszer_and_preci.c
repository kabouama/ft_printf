/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flagszer_and_preci.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 19:21:08 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 00:12:40 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	affiche_zer(t_param *prm)
{
	while (prm->width > 0)
	{
		prm->width--;
		ft_putchar('0');
		prm->j++;
		prm->len++;
	}
}

void	affiche_zer_preci(t_param *prm)
{
	while (prm->preci > 0)
	{
		prm->preci--;
		ft_putchar('0');
		prm->j++;
		prm->len++;
	}
}

void	affiche_moin(t_param *prm, long var)
{
	if (var < 0 && prm->type != 'o' && prm->type != 'O')
	{
		var *= -1;
		prm->preci++;
		ft_putchar('-');
		prm->j++;
		prm->len++;
	}
}

long	check_flags_zer(t_param *prm, long var)
{
	if ((prm->flags == '0' || prm->flags2 == '0') && !(prm->preci))
	{
		if (prm->flags && prm->flags2 && prm->type != 'x' && prm->type != 'X')
			prm->width--;
		if (prm->type == 'o' || prm->type == 'O')
			prm->width -= ft_nbrlen_base_oo(var, "01234567", prm);
		else if (prm->type == 'x' || prm->type == 'X')
		{
			prm->len_o = 0;
			width_x(prm, var);
		}
		else if (prm->type == 'u')
			prm->width -= ft_nbrlen_ll(var);
		else
			prm->width -= ft_nbrlen(var);
		affiche_moin(prm, var);
		if (prm->flags && prm->flags2 && var == 0
				&& (prm->type == 'o' || prm->type == 'O'))
			prm->width++;
		affiche_zer(prm);
	}
	return (var);
}

long	check_preci(t_param *prm, long var)
{
	if (prm->preci && prm->preci != -1)
	{
		if (prm->flags == '+' || prm->flags2 == '+')
			ft_putchar('+');
		if (prm->type == 'x' || prm->type == 'X')
		{
			prm->len_o = 0;
			preci_x(prm, var);
		}
		else if (prm->type == 'o')
		{
			prm->preci -= ft_nbrlen_base_oo(var, "01234567", prm);
		}
		else if (prm->type == 'u')
			prm->preci -= ft_nbrlen_ll(var);
		else
			prm->preci -= ft_nbrlen(var);
		if (prm->preci > 0 && (prm->flags == '#' || prm->flags2 == '#')
				&& var > 0 && prm->type != 'x' && prm->type != 'X')
			prm->preci--;
		if (prm->type != 'u')
			affiche_moin(prm, var);
		affiche_zer_preci(prm);
	}
	return (var);
}
