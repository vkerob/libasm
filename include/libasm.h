#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>


# define RED	"\033[0;31m"
# define BLUE	"\033[0;34m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

// convention call: rdi, rsi, rdx, rcx, r8, r9


size_t	ft_strlen(const char *s);

char 	*ft_strcpy(char *dest, const char *src);

int		ft_strcmp(const char *s1, const char *s2);

ssize_t	ft_write(int fd, const void *buf, size_t count);

ssize_t	ft_read(int fd, void *buf, size_t count);

char 	*ft_strdup(const char *s);


#endif 