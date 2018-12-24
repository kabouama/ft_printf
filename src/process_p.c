/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_p.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 23:51:15 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 23:28:07 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	affiche_space_here(t_param *prm)
{
	while (prm->width > 0)
	{
		ft_putchar(' ');
		prm->len++;
		prm->width--;
	}
}

void	preci_or_not(t_param *prm, long var, int len)
{
	if (!prm->preci)
	{
		prm->width -= len;
		if (var == 0)
			prm->width -= 2;
		while (prm->width > 0)
		{
			ft_putchar(' ');
			prm->width--;
			prm->len++;
			prm->j++;
		}
	}
	else if (prm->preci && prm->width > prm->preci && prm->width > len)
	{
		if (prm->preci > len)
			prm->width -= prm->preci;
		else
			prm->width -= len;
		affiche_space_here(prm);
	}
}

long	check_width_p(t_param *prm, long var)
{
	int len;

	len = ft_nbrlen_ll(var) - 1;
	if (var == 0)
		len++;
	if (prm->width && ((prm->flags != '0' && prm->flags2 != '0') || prm->preci))
	{
		if (prm->flags == '-' || prm->flags2 == '-')
		{
			if (!prm->preci)
			{
				ft_putstr("0x");
				prm->len += 2;
				prm->len += ft_putnbr_base_lo(var, "0123456789abcdef", prm);
			}
			prm->width -= len;
			affiche_space_here(prm);
		}
		preci_or_not(prm, var, len);
	}
	return (var);
}

long	process_p(t_param *prm, long var)
{
	var = check_width_p(prm, var);
	if (prm->flags != '-' && prm->flags2 != '-')
	{
		ft_putstr("0x");
		prm->len += 2;
		prm->len += ft_putnbr_base_lo(var, "0123456789abcdef", prm);
	}
	return (var);
}
