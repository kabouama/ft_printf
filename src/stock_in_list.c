/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stock_in_list.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 15:24:59 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 23:39:53 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			check_cv(char format)
{
	int			i;
	char		*conv;

	i = -1;
	conv = "sSpdDioOuUxXcCfF";
	while (conv[++i])
	{
		if (conv[i] == format)
			return (1);
	}
	return (0);
}

int			malloc_size(const char *format, int i, int j)
{
	int			flag;

	flag = 0;
	while (format[i] && format[i] != '%' && format[i] != '#')
	{
		i++;
		j++;
		flag = 1;
	}
	if ((format[i] == '%' || format[i] == '#') && flag == 0)
	{
		i++;
		j++;
		while (format[i] && check_cv(format[i - 1]) == 0)
		{
			i++;
			j++;
		}
	}
	return (j + 1);
}

int			decoupe_word(const char *format,
		t_flag *flg, int flag, t_stock *stck)
{
	flg->y = 0;
	flag = 0;
	while (format[flg->x] && format[flg->x] != '%' && format[flg->x] != '#')
	{
		stck->str[flg->y] = format[flg->x];
		flg->x++;
		flg->y++;
		flag = 1;
	}
	return (flag);
}

void		decoupe_arguments(const char *format, t_flag *flg, int flag,
		t_stock *stck)
{
	int flag2;

	flag2 = 0;
	if ((format[flg->x] == '%' || format[flg->x] == '#') && flag == 0)
	{
		stck->str[flg->y] = format[flg->x];
		flg->x++;
		flg->y++;
		while (format[flg->x] && (check_cv(format[flg->x - 1]) == 0)
				&& flag2 == 0)
		{
			stck->str[flg->y] = format[flg->x];
			flg->x++;
			flg->y++;
			if (stck->str[0] == '%' && stck->str[1] == '%')
				flag2 = 1;
			else if (format[flg->x] == '%'
					&& (check_cv(format[flg->x - 1]) == 0))
			{
				stck->str[flg->y++] = format[flg->x++];
				flag2 = 1;
			}
		}
	}
}

t_stock		*ft_decoupe(const char *format)
{
	t_stock		*stck;
	t_stock		*tmp;
	t_flag		*flg;
	int			flag;
	int			size;

	if (!(flg = (t_flag*)malloc(sizeof(t_flag))))
		return (0);
	flg->x = 0;
	flg->y = 0;
	tmp = NULL;
	size = malloc_size(format, flg->x, 0);
	stck = ft_fillnew(size);
	tmp = stck;
	while (format[flg->x])
	{
		flag = decoupe_word(format, flg, flag, stck);
		decoupe_arguments(format, flg, flag, stck);
		stck->str[flg->y] = '\0';
		size = malloc_size(format, flg->x, 0);
		ft_filladdback(&stck, size);
		stck = stck->next;
	}
	free(flg);
	return (tmp);
}
