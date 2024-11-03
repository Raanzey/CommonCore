/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozlu <yozlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:33:21 by yozlu             #+#    #+#             */
/*   Updated: 2024/11/03 18:21:11 by yozlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}
// int main(int argc, char const *argv[])
// {
// 	//1989
// 	//0000 0111 1100 0101
// 	int i[] ={1,2,3,3000};
// 	ft_memset(&i[3],0,4);
// 	ft_memset(&i[3],7,2);
// 	ft_memset(&i[3],197,1);
	
// 	//ft_memset(&i[3],7,3);
// 	printf("%d",i[3]);
// 	return 0;
// }
