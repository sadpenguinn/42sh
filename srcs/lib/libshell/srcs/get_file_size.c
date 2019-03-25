#include <sys/stat.h>
#include "../includes/libshell.h"

size_t  read_file_size(const char *file)
{
	char	*buf;
	ssize_t	ret;
    size_t  len;
    int     fd;

    len = 0;
    buf = NULL;
    if ((fd = open(file, 'r')) == -1)
    {
        sputerr(sstrerr(SHERR_CNTOPF));
        exit(EXIT_FAILURE);
    }
    while ((ret = read(fd, buf, 50)) != -1)
	{
    	len += ret;
		ft_strdel(&buf);
	}
	close(fd);
    return (len);
}

size_t  get_file_size(const char *file)
{
    struct stat sb;

    if (stat(file, &sb))
        return (read_file_size(file));
    return (sb.st_size);
}
