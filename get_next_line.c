/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** get_next_line.c
*/

#include "get_next_line.h"

char *my_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x]) {
		dest[x] = src[x];
		x = x + 1;
	}
	dest[x] = '\0';
	return (dest);
}

char *my_strconcat(char *str1, char *str2)
{
	int x = 0;
	int strl1 = 0;
	int strl2 = 0;
	char *dest;

	while (str1[strl1])
		strl1 = strl1 + 1;
	while (str2[strl2])
		strl2 = strl2 + 1;
	dest = malloc(sizeof(char) * (strl1 + strl2));
	my_strcpy(dest, str1);
	while (str2[x]) {
		dest[strl1] = str2[x];
		strl1 = strl1 + 1;
		x = x + 1;
	}
	dest[strl1] = '\0';
	return (dest);
}

char *realoc(char *str, int strle)
{
	int x = 0;
	char *s;

	s = malloc(sizeof(char) * (strle + READ_SIZE));
	while (str[x]) {
		s[x] = str[x];
		x = x + 1;
	}
	s[x] = '\0';
	free(str);
	return (s);
}

char *check(char *str,int fd)
{
	int i = 0;
	int strle = 0;
	char *inter = malloc(sizeof(char) * (READ_SIZE + 1));
	char *dest;

	for (strle; str[strle]; strle = strle + 1);
	for (i; str[i]; i = i + 1)
		if (str[i] == '\n')
			break;
	if (i != strle)
		return (str);
	i = read(fd, inter, READ_SIZE);
	str = realoc(str, strle);
	if (i == 0 || fd < 0 || READ_SIZE == 0)
		return (NULL);
	dest = malloc(sizeof(char) * (strle + READ_SIZE + 1));
	dest = my_strconcat(str, inter);
	dest = check(dest, fd);
	return (dest);
}

char *get_next_line(int fd)
{
	char *str;
	char *begin;
	static char *more;
	int strl = 0;
	int morel = 0;
	int x = 0;
	int y = 0;

	if (READ_SIZE <= 0 || fd < 0 || malloc(sizeof(char) * READ_SIZE + 1) == NULL)
		return (NULL);
	str = malloc(sizeof(char) * READ_SIZE + 1);
	begin = malloc(sizeof(char) * READ_SIZE + 1);
	if (more) {
		for (morel; more[morel]; morel = morel + 1);
		for (x; more[x]; x = x + 1)
			if (more[x] == '\n')
				break;
		if (x < morel) {
			for (y; y < x; y = y + 1) {
				begin[y] = more[0];
				more ++;
			}
			more ++;
			return (begin);
		} else
			begin = my_strcpy(begin, more);
	}
	more = check(str, fd);
	if (more == NULL)
		return (NULL);
	if (begin)
		str = my_strcpy(str, begin);
	str = my_strconcat(str, more);
	for (strl; str[strl]; strl = strl + 1);
	for (more; more[0] != '\n'; more ++);
	more ++;
	for (morel; more[morel]; morel = morel + 1);
	str[strl - (morel + 1)] = '\0';
	return (str);
}
