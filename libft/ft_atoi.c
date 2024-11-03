/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:42:15 by yozlu             #+#    #+#             */
/*   Updated: 2024/10/31 14:22:45 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	count;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		count = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	result *= count;
	return (result);
}
