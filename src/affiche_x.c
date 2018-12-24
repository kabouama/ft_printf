/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   affiche_x.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 23:21:30 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 18:34:13 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		width_x(t_param *prm, long var)
{
	if (prm->type == 'x')
		prm->width -= ft_nbrlen_base_o(var, "0123456789abcdef", prm);
	else
		prm->width -= ft_nbrlen_base_o(var, "0123456789ABCDEF", prm);
	if ((prm->flags == '#' || prm->flags2 == '#') && var > 0)
		prm->width -= 2;
}

void		preci_x(t_param *prm, long var)
{
	if (prm->type == 'x')
		prm->preci -= ft_nbrlen_base_o(var, "0123456789abcdef", prm);
	else
		prm->preci -= ft_nbrlen_base_o(var, "0123456789ABCDEF", prm);
}

void		decoupe_type_x(long var, t_param *prm)
{
	if (prm->type == 'x' && prm->var_type == 20)
	{
		prm->tmp2 += ft_putnbr_base3(var, "0123456789abcdef", prm);
		prm->len += prm->tmp2;
	}
	if (prm->type == 'X' && prm->var_type == 20)
	{
		prm->tmp2 += ft_putnbr_base3(var, "0123456789ABCDEF", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->type == 'x' && prm->var_type == 21)
	{
		prm->tmp2 += ft_putnbr_base_lo(var, "0123456789abcdef", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->type == 'X' && prm->var_type == 21)
	{
		prm->tmp2 += ft_putnbr_base_lo(var, "0123456789ABCDEF", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->type == 'x' && prm->var_type == 22)
	{
		prm->tmp2 += ft_putnbr_base_ho(var, "0123456789abcdef", prm);
		prm->len += prm->tmp2;
	}
}

void		decoupe_type2_x(long var, t_param *prm)
{
	if (prm->type == 'X' && prm->var_type == 22)
	{
		prm->tmp2 += ft_putnbr_base_ho(var, "0123456789ABCDEF", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->type == 'x' && prm->var_type == 23)
	{
		prm->tmp2 += ft_putnbr_base_llo(var, "0123456789abcdef", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->type == 'X' && prm->var_type == 23)
	{
		prm->tmp2 += ft_putnbr_base_llo(var, "0123456789ABCDEF", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->type == 'x' && prm->var_type == 24)
	{
		prm->tmp2 += ft_putnbr_base_diez(var, "0123456789abcdef", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->type == 'X' && prm->var_type == 24)
	{
		prm->tmp2 += ft_putnbr_base_diez(var, "0123456789ABCDEF", prm);
		prm->len += prm->tmp2;
	}
}

t_param		*typee_x(long var, t_param *prm)
{
	prm->tmp2 = 0;
	prm->len_o = 0;
	if (prm->type == 'x' || prm->type == 'X')
	{
		decoupe_type_x(var, prm);
		decoupe_type2_x(var, prm);
	}
	return (prm);
}
