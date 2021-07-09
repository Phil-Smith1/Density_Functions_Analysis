#pragma once

#include <string>

using namespace std;

class Input
{
    public:
    
    bool experimental_T2;
    int zone_limit, dimension;
    string input_dir, output_dir, file_name_1, file_name_2, experimental_T2_label;
    
    Input ( string const& i_d, string const& o_d, string const& f_1, string const& f_2, int z_l, int d, bool e_t, string const& e_t_l );
    
    Input();
    ~Input();
};
