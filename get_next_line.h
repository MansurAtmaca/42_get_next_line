#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);

#endif