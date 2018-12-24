/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   affiche_o.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/24 18:22:40 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 23:26:12 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		decoupe_type_o(long var, t_param *prm)
{
	if (prm->var_type == 10)
	{
		prm->tmp2 = ft_putnbr_base3(var, "01234567", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->var_type == 11)
	{
		prm->tmp2 = ft_putnbr_base_ho(var, "01234567", prm);
		prm->len += prm->tmp2;
	}
}

t_param		*typee_o(long var, t_param *prm)
{
	prm->tmp2 = 0;
	prm->len_o = 0;
	decoupe_type_o(var, prm);
	if (prm->var_type == 12)
	{
		prm->tmp2 = ft_putnbr_base_lo(var, "01234567", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->var_type == 13)
	{
		prm->tmp2 = ft_putnbr_base_llo(var, "01234567", prm);
		prm->len += prm->tmp2;
	}
	else if (prm->var_type == 14)
	{
		prm->tmp2 += ft_putnbr_base_diez(var, "01234567", prm);
		prm->len += prm->tmp2;
	}
	return (prm);
}

t_param		*typee_u(long var, t_param *prm)
{
	prm->tmp2 = 0;
	prm->len_o = 0;
	if (prm->var_type == 5)
	{
		prm->tmp2 += ft_putnbr_lu(var);
		prm->len += ft_nbrlen_ll(var);
	}
	else if (prm->var_type == 7)
		prm->len += ft_putnbr_hu(var);
	else if (prm->var_type == 3)
	{
		prm->tmp2 = ft_putnbr_uu(var);
		prm->len += ft_nbrlen_ll(var);
	}
	else if (prm->var_type == 6)
		prm->len += ft_putnbr_hhu(var);
	else if (prm->type == 'U')
	{
		prm->len = ft_putnbr_uu(var);
		prm->len += ft_nbrlen_ll(var);
	}
	else
		ft_putnbr_u(var);
	return (prm);
}
