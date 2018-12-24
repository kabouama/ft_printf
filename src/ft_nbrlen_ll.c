/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nbrlen_ll.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 19:18:36 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 00:07:29 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned long long		ft_nbrlen_ll(unsigned long long n)
{
	unsigned long long	res;

	res = 0;
	if (n <= 0)
	{
		n = -n;
		res++;
	}
	while (n > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

long long				ft_nbrlen_lld(long long n)
{
	long long	res;

	res = 0;
	if (n <= 0)
	{
		n = -n;
		res++;
	}
	while (n > 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

int						ft_nbrlen_base_o(unsigned long long nbr,
		char const *base, t_param *prm)
{
	unsigned int	tmp;

	tmp = ft_strlen(base) - 1;
	if (nbr > tmp)
	{
		ft_nbrlen_base_o(nbr / ft_strlen(base), base, prm);
		ft_nbrlen_base_o(nbr % ft_strlen(base), base, prm);
	}
	else
		prm->len_o++;
	return (prm->len_o);
}

int						ft_nbrlen_base_oo(unsigned int nbr,
		char const *base, t_param *prm)
{
	unsigned int	tmp;

	tmp = ft_strlen(base) - 1;
	if (nbr > tmp)
	{
		ft_nbrlen_base_o(nbr / ft_strlen(base), base, prm);
		ft_nbrlen_base_o(nbr % ft_strlen(base), base, prm);
	}
	else
		prm->len_o++;
	return (prm->len_o);
}
