#ifndef ARRAY_H
# define ARRAY_H

enum array_default_params
{
	ARRAY_DEFAULT_SIZE = 10, FACTOR = 2
};


typedef	struct		s_array
{
	char			*buf;
	unsigned int	len;
	unsigned int	size;
}					t_array;

void	array_add(const char *str, unsigned int len);
char *array_to_string(void);
void	array_flush(void);

#endif
