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
    else if (value == 4)
        printf("Error %d - %s.\n", value, PARSE_ERR);
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

int ft_space(char *line, int index)
{
    while (line[index] == ' ' || line[index] == '\t')
        index++;
    return (index);
}

int ft_get_positive_number(char *line, int index)
{
    int value;

    if (!ft_isdigit(line[index]))
        return (-1);
    if ((value = ft_atoi(&line[index])) < 0)
        return (-1);
    return (value);
}

int    ft_init_reso(t_params *t_p, char *line)
{
    int index;

    ft_memset(&t_p->t_R, 48, sizeof(t_p->t_R));
    t_p->t_R.c = line[0];
    t_p->t_R.x_R = 0;
    t_p->t_R.y_R = 0;
    index = 1;
    if (line[index] != ' ' && line[index] !='\t')
        return (-1);
    index = ft_space(line, index);
    if ((t_p->t_R.x_R = ft_get_positive_number(line, index)) < 0)
        return (-1);
    index += ft_intlen_base(t_p->t_R.x_R, "012356789");
    index = ft_space(line, index);
    if ((t_p->t_R.y_R = ft_get_positive_number(line, index)) < 0)
        return (-1);
    index += ft_intlen_base(t_p->t_R.y_R, "0123456789");
    index = ft_space(line, index);
    if (line[index] != '\0')
        return (-1);
    return (1);
}


int     ft_check_values(char *line, t_params *t_p)
{
    if (line[0] != '\0')
    {
        if (line[0] == 'R' && !(t_p->is_R))
            return (ft_init_reso(t_p, line));
        else if (line[0] == 'A' && (!t_p->is_A))
        {
            t_p->is_A++;
            printf("ambiant\n");
        }
        else if (line[0] == 'c' && line[1]!='y')
            printf("camera\n");
        else if (line[0] == 'l')
            printf("light\n");
        else if (line[0] == 's' && line[1] == 'p')
            printf("sphere\n");
        else if (line[0] == 'p' && line[1] == 'l')
            printf("plan\n");
        else if (line[0] == 's' && line[1] == 'q')
            printf("square\n");
        else if (line[0] == 'c' && line[1] == 'y')
            printf("cylinder\n");
        else if (line[0] == 't' && line[1] == 'r')
            printf("triangle\n");
        else 
            return (-1);
    }
    return (0);
}

void    ft_init(t_params *t_p)
{
    ft_memset(t_p, 48 , sizeof(t_p));
    t_p->is_R = 0;
    t_p->is_A = 0;
    t_p->is_F = 0;
    printf("%d\n", t_p->is_R);
}

int     ft_parser(int fd)
{
    int         ret;
    char        *line;
    t_params    t_p;
    
    ft_init(&t_p);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        if ((ret = ft_check_values(line, &t_p)) < 0)
            return (0);
        free(line);
    }
    return (1);
}

int main(int argc, char **argv)
{
    int name_bmp;
    int fd;
    
    if (argc < 2 || argc > 3)
        return (ft_errors(0));
   name_bmp = ft_open_and_parse(argv[1],&fd);
   if (!(ft_parser(fd)))
        return (ft_errors(4));
   return (0);
}
