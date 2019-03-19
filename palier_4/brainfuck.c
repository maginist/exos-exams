/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:11:16 by maginist          #+#    #+#             */
/*   Updated: 2019/03/19 18:10:48 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		find_brackettwo(char *str, int i)
{
	int	ok;

	ok = 0;
	i = i - 1;
	while (str[i])
	{
		if (str[i] == ']')
			ok++;
		i--;
	}
	if (ok > 0)
		return (ok);
	else
		return (0);
}

int		find_bracket(char *str, int i)
{
	int		ok;

	ok = 0;
	i = i + 1;
	while (str[i])
	{
		if (str[i] == '[')
			ok++;
		i++;
	}
	if (ok > 0)
		return (ok);
	else
		return (0);
}

void	brainfuck(char *str, char *octet)
{
	int		i;
	int		l;
	int		o;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '+')
			(*octet)++;
		if (str[i] && str[i] == '-')
			(*octet)--;
		if (str[i] && str[i] == '>')
			octet++;
		if (str[i] && str[i] == '<')
			octet--;
		if (str[i] && str[i] == '.')
			write(1, octet, 1);
		if (str[i] && str[i] == '[' && *octet == 0)
		{
			l = find_bracket(str, i);
			while (str[i] && str[i] != ']')
			{
				if (str[i] && str[i + 1] == ']' && l != 0)
				{
					i++;
					l--;
				}
				i++;
			}
		}
		if (str[i] && str[i] == ']' && *octet != 0)
		{
			o = find_brackettwo(str,i);
			while (str[i] && str[i] != '[')
			{
				if (str[i] && str[i - 1] == '[' && o != 0)
				{
					i--;
					o--;
				}
				i--;
			}
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	char	*octet;
	int		i;

	i = 0;
	if (!(octet = (char*)malloc(sizeof(char) * 2048)))
		return (0);
	if (ac < 2)
	{
		free(octet);
		write(1, "\n", 1);
		return (0);
	}
	while (i != 2047)
	{
		octet[i] = 0;
		i++;
	}
	brainfuck(av[1], octet);
}
