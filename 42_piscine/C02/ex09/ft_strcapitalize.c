/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 00:01:55 by lmorelli          #+#    #+#             */
/*   Updated: 2022/11/26 22:30:33 by lmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lower(char *p)
{
	int	j;

	j = 0;
	while (p[j] != '\0')
	{
		if (p[j] >= 65 && p[j] <= 90)
		{
			p[j] += 32;
		}
		j++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	lower(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			if (flag == 1)
			{
				str[i] -= 32;
				flag = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (str);
}
