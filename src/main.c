#include "../include/libasm.h"
#include <strings.h>


void	test_ft_read()
{
	int		fd = open("Makefile", O_RDONLY);
	size_t	count = 1;

	char	*buf_read = malloc(sizeof(char) * count + 1);
	buf_read[count] = '\0';
	ssize_t	return_value_read;

	char	*buf_ft_read = malloc(sizeof(char) * count + 1);
	buf_ft_read[count] = '\0';
	ssize_t	return_value_ft_read;


	return_value_read = read(fd, buf_read, count);
	printf(BLUE "read buf: " RESET);
	printf(GREEN "%s" RESET, buf_read);
	printf(BLUE "return value: " RESET);
	printf(GREEN "%ld\n" RESET, return_value_read);
	printf("Error opening file: %s\n", strerror(errno));
	close(fd);


	fd = open("Makefile", O_RDONLY);
	return_value_ft_read = ft_read(fd, buf_ft_read, count);
	printf(RED "ft_read buf: " RESET);
	printf(GREEN "%s" RESET, buf_ft_read);
	printf(RED "return value: " RESET);
	printf(GREEN "%ld\n" RESET, return_value_ft_read);
	printf("Error opening file: %s\n\n\n", strerror(errno));
	
	free(buf_read);
	free(buf_ft_read);

	return;
}



void	test_ft_strcmp()
{
	const char *s1 = "Hello";
	const char *s2 = "lorem teste";


	printf(BLUE "strcmp: " RESET);
	printf(GREEN "%d\n" RESET, strcmp(s1, s2));

	printf(RED "ft_strcmp: " RESET);
	printf(GREEN "%d\n\n\n" RESET, ft_strcmp(s1, s2));

	return;
}


void	test_ft_strcpy()
{
	const char	*src = "test";

	char		dest_ft_strcpy[20];
	char		*ptr_ft_strcpy;

	char		dest_strcpy[20];
	char		*ptr_strcpy;
	

	ptr_strcpy = strcpy(dest_strcpy, src);
	printf(BLUE "strcpy: " RESET);
	printf(GREEN "%s\n" RESET, ptr_strcpy);

	ptr_ft_strcpy = ft_strcpy(dest_ft_strcpy, src);
	printf(RED "ft_strcpy: " RESET);
	printf(GREEN "%s\n\n\n" RESET, ptr_ft_strcpy);

	return;
}



void	test_ft_strdup()
{
	const char	*src = "test_dup";

	char		*dest_strdup;

	char		*dest_ft_strdup;
	



	dest_strdup = strdup(src);
	printf(BLUE "strdup: " RESET);
	printf(GREEN "%s\n" RESET, dest_strdup);
	free(dest_strdup);

	dest_ft_strdup = ft_strdup(src);
	printf(RED "ft_strdup: " RESET);
	printf(GREEN "%s\n\n\n" RESET, dest_ft_strdup);
	free(dest_ft_strdup);

	return;
}


void	test_ft_write()
{
	const char	*buf = "qwertyuiop\n";
	size_t		count = strlen(buf);

	ssize_t		return_value_ft_write;

	ssize_t		return_value_write;

	int		fd = open("t", O_CREAT | O_WRONLY | O_TRUNC, 0644);


	return_value_write = write(fd, buf, count);
	printf(BLUE "write: " RESET);
	printf(GREEN "%ld\n" RESET, return_value_write);
	printf("Error opening file: %s\n", strerror(errno));

	return_value_ft_write = ft_write(fd, buf, count);
	printf(RED "ft_write: " RESET);
	printf(GREEN "%ld\n" RESET, return_value_ft_write);
	printf("Error opening file: %s\n\n\n", strerror(errno));

	close(fd);

	return;
}

void	test_ft_strlen()
{
	const char	*str = "0123456789";

	printf(BLUE "strlen: " RESET);
	printf(GREEN "%ld\n" RESET, strlen(str));

	printf(RED "ft_strlen: " RESET);
	printf(GREEN "%ld\n\n\n" RESET, ft_strlen(str));

	return;
}

int main()
{

	test_ft_strcmp();
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strdup();
	test_ft_write();
	test_ft_read();
	return (0);
}