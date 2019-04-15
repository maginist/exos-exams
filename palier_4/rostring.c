/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 12:48:31 by maginist          #+#    #+#             */
/*   Updated: 2019/04/15 13:29:52 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_count_word(char *str)
{
	int		i;
	int		nw;

	nw = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t')
			nw++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (nw);
}

int	ft_size(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{

		if (str[i] != ' ' && str[i] != '\t')
			res++;
		if (str[i] != ' ' && str[i] != '\t' && (str[i - 1] == ' ' || str[i - 1] == '\t') && (res - 1))
			res++;
		i++;
	}
	return (res);
}

#include <stdio.h>

char	*rostring(char *str)
{
	int	i;
	int	size;
	char	*cp;
	int	p;
	int	nw;

	i = 0;
	p = 0;
	nw = 0;
	size = ft_size(str);
	printf("%d\n", size);
	if (!(cp = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	nw = ft_count_word(str);
	printf("%d\n", nw);
	if (nw == 1)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			cp[p] = str[i];
			p++;
			i++;
		}
		cp[p] = '\0';
		return (cp);
	}
	if (nw > 1)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		while (str[i])
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				cp[p] = str[i];
				p++;
				i++;
			}
			if (str[i] && (str[i] == ' ' || str[i] == '\t'))
			{
				cp[p] = ' ';
				p++;
			}
		}
		if (i >= size && cp[p - 1] != ' ' && cp[p - 1] != '\t')
		{
			cp[p] = ' ';
			p++;
		}
		i = 0;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
		{
			cp[p] = str[i];
			p++;
			i++;
		}
	}
	else
		return (0);
	cp[p] = '\0';
	return (cp);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &(str[i]), 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return ;
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
		ft_putstr(rostring(av[1]));
	return (0);
}
