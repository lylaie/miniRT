#include "../include/ft_miniRT.h"

int ft_errors(int value)
{
    if (value == 0)
        printf("Error %d - %s.\n", value, ARG_ERR);
    else if (value == 1)
        printf("Error %d - %s.\n", value, READ_ERR);
    else if (value == 2)
        printf("Error %d - %s.\n", value, FILE_ERR);
    else if (value == 3)
        printf("Error %d - %s.\n", value, EXT_ERR);
    return (-1);
}

int   ft_open_and_parse(char *file_name, int *fd)
{
    int index;

    index = 0;
    if ((*fd = open(file_name, O_RDONLY)) <= 0)
        return (ft_errors(1));
    while (file_name[index] && file_name[index] != '.')
        index++;
    if (!file_name[index])
        return (ft_errors(2));
    if (index < 3 || ft_strcmp(&file_name[index], ".rt"))
        return (ft_errors(3));
    return (index);
}

int main(int argc, char **argv)
{
    int name_bmp;
    int fd;
    
    if (argc < 2 || argc > 3)
        return (ft_errors(0));
   name_bmp = ft_open_and_parse(argv[1],&fd);
    return (0);
}
