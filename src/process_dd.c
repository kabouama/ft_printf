/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_dd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 22:31:20 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 17:52:30 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_flags_d(t_param *prm, long var)
{
	if (prm->flags)
	{
		if ((prm->flags != '0' && prm->flags2 != '0')
				|| (prm->width < ft_nbrlen(var) + 1))
			affiche_plus(prm, var);
		if (prm->flags == ' ' && !prm->width)
		{
			if (var >= 0)
			{
				ft_putchar(' ');
				prm->len++;
			}
		}
		if (prm->flags == '0' && !prm->width && var < 0)
		{
			ft_putchar('-');
			prm->len++;
		}
	}
}

void	check_flags_2d(t_param *prm, long var)
{
	check_flags_d(prm, var);
	if (prm->flags2)
	{
		if (prm->flags2 == ' ' && !prm->width)
		{
			if (var >= 0)
			{
				ft_putchar(' ');
				prm->len++;
			}
		}
		if (prm->flags2 == '0' && !prm->width)
		{
			ft_putchar('-');
			prm->len++;
		}
	}
}

void	check_preci_d(t_param *prm, long var)
{
	int		prec;

	if (prm->preci)
	{
		prec = prm->preci;
		if (prec >= ft_nbrlen(var))
		{
			if (var < 0)
			{
				ft_putchar('-');
				var *= -1;
			}
			prec -= ft_nbrlen(var);
			while (prec > 0)
			{
				ft_putchar('0');
				prec--;
				prm->len++;
			}
			affiche_var(prm, var);
		}
	}
}

void	supp_zer(t_param *prm, long var, double varf)
{
	if (prm->flags == '-' && prm->flags2 == '0')
		prm->flags2 = 0;
	else if (prm->flags2 == '-' && prm->flags == '0')
		prm->flags = 0;
	if ((prm->flags == '+' || prm->flags2 == '+') && var >= 0)
	{
		prm->width--;
		prm->len++;
	}
	if (prm->flags != '-' && prm->flags2 != '-')
		check_width_d(prm, var, varf);
	check_flags_2d(prm, var);
	if (prm->type == 'f' || prm->type == 'F')
		check_preci_f(prm, varf);
	else
		check_preci_d(prm, var);
}

long	process_dd(t_param *prm, long var, double varf)
{
	prm->flt = 0;
	supp_zer(prm, var, varf);
	if ((!prm->preci || prm->preci < ft_nbrlen(var)))
	{
		if (!(prm->preci == -5 && var == 0))
		{
			if (prm->type == 'D')
				ft_putnbr_long(var);
			else
			{
				if ((prm->flags == '0' || prm->flags2 == '0') && var < 0)
					var *= -1;
				if (prm->type != 'f' && prm->type != 'F')
					affiche_var(prm, var);
			}
			if (prm->type != 'f' && prm->type != 'F')
				prm->len += ft_nbrlen(var);
		}
	}
	else
		prm->len += ft_nbrlen(var);
	if (prm->flags == '-' || prm->flags2 == '-')
		check_width_d(prm, var, varf);
	return (var);
}
