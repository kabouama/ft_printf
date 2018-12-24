/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_percent.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 13:44:31 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 23:28:12 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_width_percent(t_param *prm)
{
	if (prm->width)
	{
		if (prm->flags == '-' || prm->flags2 == '-')
		{
			ft_putchar('%');
			prm->len++;
			prm->width--;
			affiche_space_here(prm);
		}
		else if (prm->width > 1)
		{
			prm->width--;
			while (prm->width > 0)
			{
				if (prm->flags == '0' || prm->flags2 == '0')
					ft_putchar('0');
				else
					ft_putchar(' ');
				prm->len++;
				prm->width--;
			}
		}
	}
}

void	process_percent(t_param *prm)
{
	check_width_percent(prm);
	if (prm->flags != '-' && prm->flags2 != '-')
	{
		ft_putchar('%');
		prm->len++;
	}
}
