/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** get_next_line.h
*/

#ifndef READ_SIZE
#define READ_SIZE (5)
#endif

#ifndef GET_LINE
#define GET_LINE

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);

#endif
