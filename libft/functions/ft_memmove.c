/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:51:56 by seohyuki          #+#    #+#             */
/*   Updated: 2022/03/09 17:19:56 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
	{
		while (len--)
		{
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst--;
			src--;
		}
	}
	else
	{
		src += len - 1;
		while (len--)
		{
			*((unsigned char *)dst) = *((unsigned char *)src);
			dst--;
			src--;
		}
	}
}

#include <stdio.h>

int	main()
{
	char src[100] = "seohyeon";
	char src2[100] = "seohyeon";
	char dest[100] = "seohyeon";
	char dest2[100] = "seohyeon";

	memmove(src + 1, src, sizeof(char) * 8);
	ft_memmove(dest + 1, dest, sizeof(char) * 8);

	printf("%s\n", src);
	printf("%s\n", dest);

}
