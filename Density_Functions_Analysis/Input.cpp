#include "Input.h"

Input::Input ( string const& i_d, string const& o_d, string const& f_1, string const& f_2, int z_l, int d, bool e_t, string const& e_t_l )
{
    input_dir = i_d;
    output_dir = o_d;
    file_name_1 = f_1;
    file_name_2 = f_2;
    zone_limit = z_l;
    dimension = d;
    experimental_T2 = e_t;
    experimental_T2_label = e_t_l;
}

Input::Input(){}
Input::~Input(){}
