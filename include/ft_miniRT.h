#ifndef FT_MINIRT_H
# define FT_MINIRT_H

# include <stdio.h>
# include <fcntl.h>


/*
 ** CONSTANTES
*/


# define ARG_ERR "Wrong numbers of arguments"
# define READ_ERR "Reading error"
# define FILE_ERR "Invalid file"
# define EXT_ERR "Invalid extension"

/*
 ** STRUCTURES
*/

typedef struct  s_triangle
{
    int x_a_tr;
    int y_a_tr;
    int z_a_tr;
    int x_b_tr;
    int y_b_tr;
    int z_b_tr;
    int x_c_tr;
    int y_c_tr;
    int z_c_tr;
    int r_tr;
    int g_tr;
    int b_tr;
}               t_triangle;

typedef struct  s_cylinder
{
    int x_cy;
    int y_cy;
    int z_cy;
    int x_v_cy;
    int y_v_cy;
    int z_vy_cy;
    int d_cy;
    int h_cy;
    int r_cy;
    int g_cy;
    int b_cy;
}               t_cylinder;

typedef struct s_square
{
    int x_sq;
    int y_sq;
    int z_sq;
    int x_v_sq;
    int y_v_sq;
    int z_v_sq;
    int h_sq;
    int r_sq;
    int g_sq;
    int b_sq;
}               t_square;

typedef struct  s_plan
{
    int x_pl;
    int y_pl;
    int z_pl;
    int x_v_pl;
    int y_v_pl;
    int z_v_pl;
    int r_pl;
    int g_pl;
    int b_pl;
}               t_plan;

typedef struct s_sphere
{
    int x_sph;
    int y_sph;
    int z_sph;
    int d_sph;
    int r_sph;
    int g_sph;
    int b_sph;
}               t_sphere;

typedef struct s_form
{
    int c;
    int l;
    int sp;
    int pl;
    int sq;
    int cy;
    int tr;
}               t_form;

typedef struct  s_resolution
{
    char c;
    int x_R;
    int y_R;
}               t_reso;

typedef struct  s_ambient
{
    char c;
    int op_L;
    int r_L;
    int g_L;
    int b_L;
}               t_amb;

typedef struct  s_param
{
    int is_R;
    int is_F;

    t_reso t_R;
    t_amb t_A;
    t_form t_F;
}               t_params;


/*
 ** PROTOTYPES
*/


int    ft_open_and_parse(char *file_name, int *fd);
int     ft_errors(int value);

/*
 ** UTILS
*/

int     ft_strcmp(char *s1, char *s2);

#endif
