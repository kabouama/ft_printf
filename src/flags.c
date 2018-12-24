/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 22:09:25 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 23:26:34 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long	check_flags(t_param *prm, long var)
{
	if (prm->flags)
	{
		if (prm->flags == '+' && var >= 0 && prm->flags2 != '-')
		{
			ft_putchar('+');
			prm->j++;
			prm->len++;
		}
		if (prm->flags == ' ')
		{
			if (var >= 0)
			{
				ft_putchar(' ');
				prm->j++;
				prm->len++;
			}
		}
	}
	return (var);
}

long	check_flags2(t_param *prm, long var)
{
	check_flags(prm, var);
	if (prm->flags2)
	{
		if ((prm->flags2 == '+') && var >= 0 && prm->flags != '-')
		{
			ft_putchar('+');
			prm->j++;
			prm->len++;
		}
		if (prm->flags2 == ' ')
		{
			if (var >= 0)
			{
				ft_putchar(' ');
				prm->j++;
				prm->len++;
			}
		}
	}
	return (var);
}

void	process_diez(t_param *prm, long var)
{
	if (prm->type != 'x' && prm->type != 'X'
			&& (prm->flags != '-' && prm->flags2 != '-'))
	{
		if (var == 0)
		{
			if (prm->preci == -6)
			{
				ft_putchar('0');
				prm->len++;
			}
		}
		else
		{
			ft_putchar('0');
			prm->len++;
		}
	}
	else if ((prm->type == 'x' || prm->type == 'X') && var != 0)
	{
		if (prm->type == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		prm->len += 2;
	}
}

long	check_diez(t_param *prm, long var)
{
	if (prm->var_type == 10 || prm->type == 'x' || prm->type == 'X')
	{
		if ((prm->flags == '#' || prm->flags2 == '#'))
			process_diez(prm, var);
	}
	return (var);
}
