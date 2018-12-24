/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/17 17:05:46 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 18:58:07 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putnbr_base3(unsigned int nbr, char const *base, t_param *prm)
{
	unsigned int	tmp;

	tmp = ft_strlen(base) - 1;
	if (nbr > tmp)
	{
		ft_putnbr_base3(nbr / ft_strlen(base), base, prm);
		ft_putnbr_base3(nbr % ft_strlen(base), base, prm);
	}
	else
	{
		prm->len_o++;
		ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (prm->len_o);
}

int		ft_putnbr_base_diez(unsigned char nbr, char const *base, t_param *prm)
{
	unsigned char	tmp;

	tmp = ft_strlen(base) - 1;
	if (nbr > tmp)
	{
		ft_putnbr_base_diez(nbr / ft_strlen(base), base, prm);
		ft_putnbr_base_diez(nbr % ft_strlen(base), base, prm);
	}
	else
	{
		prm->len_o++;
		ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (prm->len_o);
}

int		ft_putnbr_base_ho(unsigned short nbr, char const *base, t_param *prm)
{
	unsigned short	tmp;

	tmp = ft_strlen(base) - 1;
	if (nbr > tmp)
	{
		ft_putnbr_base_ho(nbr / ft_strlen(base), base, prm);
		ft_putnbr_base_ho(nbr % ft_strlen(base), base, prm);
	}
	else
	{
		prm->len_o++;
		ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (prm->len_o);
}

int		ft_putnbr_base_lo(unsigned long nbr, char const *base, t_param *prm)
{
	unsigned long	tmp;

	tmp = ft_strlen(base) - 1;
	if (nbr > tmp)
	{
		ft_putnbr_base_lo(nbr / ft_strlen(base), base, prm);
		ft_putnbr_base_lo(nbr % ft_strlen(base), base, prm);
	}
	else
	{
		prm->len_o++;
		ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (prm->len_o);
}

int		ft_putnbr_base_llo(unsigned long long nbr,
		char const *base, t_param *prm)
{
	unsigned long long	tmp;

	tmp = ft_strlen(base) - 1;
	if (nbr > tmp)
	{
		ft_putnbr_base_llo(nbr / ft_strlen(base), base, prm);
		ft_putnbr_base_llo(nbr % ft_strlen(base), base, prm);
	}
	else
	{
		prm->len_o++;
		ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (prm->len_o);
}
