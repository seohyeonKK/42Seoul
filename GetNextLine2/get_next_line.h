/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyuki <seohyuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:45:39 by seohyuki          #+#    #+#             */
/*   Updated: 2022/08/15 16:07:34 by seohyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
// BUFFER_SIZE 없을 경우 warning
// BUFFER_SIZE 단순 define할 경우 "macro redefined" 발생

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*get_line(int fd, char **str, unsigned int *idx);
char	*update_string(char *str, unsigned int idx);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
//	주어진 fd를 list에서 찾는 함수
//	-> 같은 fd 있을 경우 read한 만큼 join하여 buf에 추가
//	-> 같은 fd 없을 경우 새로 할당

// list가 주어지고, '\n', '\0' 탐색

// '\n', '\0' 이전까지 동적할당 받아 복사한 후 기존 buf에서 지움

#endif
