/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   char_atoi.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 19:24:48 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 06:47:12 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		char_atoi(t_stock *stck, t_param *prm)
{
	char	*str;
	int		cpt;
	int		x;
	int		nb;

	cpt = 0;
	x = 0;
	nb = 0;
	while (stck->str[prm->i + cpt] >= '0' && stck->str[prm->i + cpt] <= '9')
		cpt++;
	if (!(str = (char*)malloc(sizeof(char) * (cpt + 1))))
		return (0);
	if (!(stck->str[prm->i] >= '0' && stck->str[prm->i] <= '9'))
		return (-5);
	while (stck->str[prm->i] >= '0' && stck->str[prm->i] <= '9')
	{
		str[x++] = stck->str[prm->i];
		prm->i++;
	}
	str[x] = '\0';
	nb = ft_atoi(str);
	if (nb == 0)
		nb = -5;
	ft_strdel(&str);
	return (nb);
}
