/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prog_float.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 06:10:28 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 04:29:15 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*boucle_str(t_param *prm, long double zer_cink, int prec, char *str)
{
	int x;

	x = 0;
	while (prec--)
	{
		zer_cink *= 10;
		str[x] = (long)zer_cink + '0';
		if (!(str[x] >= '0' && str[x] <= '9'))
		{
			str[x] = '0';
			prm->flg_f = 1;
		}
		zer_cink -= (long)zer_cink;
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*init_str(t_param *prm, long double zer_cink, double varf)
{
	char			*str;
	long double		nb;
	int				x;
	int				prec;

	x = 0;
	prm->flg_f = 0;
	if (!(str = (char *)malloc(sizeof(char) * prm->preci + 2)))
		return (NULL);
	prec = prm->preci;
	prec++;
	if (varf < 0)
		varf *= -1;
	nb = varf;
	while (prec--)
		zer_cink /= 10;
	zer_cink += nb;
	prec = prm->preci;
	prec++;
	zer_cink -= (long)varf;
	boucle_str(prm, zer_cink, prec, str);
	return (str);
}

void	c_str(t_param *prm, double varf, t_float *flt)
{
	int				x;
	int				flg;

	x = 0;
	flg = 0;
	if (prm->preci == -5)
		prm->preci = 0;
	if (prm->flg_f == 1)
	{
		if (varf < 0)
			varf--;
		else
			varf++;
	}
	prm->len += ft_putnbr_lf((long double)varf, flt);
	if (prm->preci > 0)
	{
		ft_putchar('.');
		if (varf < 0)
			prm->len++;
	}
}

char	*arrondi_f(char *str, t_param *prm)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] > '5')
	{
		if (str[i - 1] == '9')
		{
			while (str[i - 1] == '9')
			{
				str[i - 1] = '0';
				i--;
			}
			str[i - 1]++;
			if (!str[i - 2])
			{
				prm->flg_f = 1;
				prm->len++;
			}
		}
		else
			str[i - 1]++;
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}

char	*check_preci_f(t_param *prm, double varf)
{
	long double		zer_cink;
	char			*str;

	prm->flg_f = 0;
	str = NULL;
	zer_cink = 0.5;
	str = preci_f2(prm, varf, zer_cink, str);
	free(str);
	return (0);
}
