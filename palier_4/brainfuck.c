/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfucktest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:57:45 by maginist          #+#    #+#             */
/*   Updated: 2019/03/26 14:31:47 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	find_pars(char *str, int ok, int i)
{
	int	l;

	l = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '[')
			l++;
		else if (str[i] == ']')
			l--;
		if (l == 0)
			return (i);
		i += ok;
	}
	return (0);
}

void	brainfuck(char *str, char *octet)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == '>')
			octet++;
		else if (str[i] && str[i] == '<')
			octet--;
		else if (str[i] && str[i] == '+')
			(*octet)++;
		else if (str[i] && str[i] == '-')
			(*octet)--;
		else if (str[i] && str[i] == '.')
			write(1, octet, 1);
		else if (str[i] && str[i] == '[' && !(*octet))
			i = find_pars(str, 1, i);
		else if (str[i] && str[i] == ']' && (*octet))
			i = find_pars(str, -1, i);
		i++;
	}
	return ;
}


int		main(int ac, char **av)
{
	char	*octet;
	int		i;

	i = 0;
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (!(octet = (char*)malloc(sizeof(char) * 2048)))
		return (0);
	while (i < 2048)
	{
		octet[i] = 0;
		i++;
	}
	brainfuck(av[1], octet);
	return (0);
}
