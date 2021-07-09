#include "Comparing_Entries.h"
#include "D_Infinity_Distance.h"
#include "Output_File_Name.h"

void Compare_Two_Files ( Input const& input )
{
    vector<double> max_diff( input.zone_limit, 0 );
    vector<double> dampening( input.zone_limit, 0 );
    
    double sum = Comparing_Entries( input, max_diff );
    
    double d_infty = D_Infinity_Distance( input, max_diff, dampening );
    
    string output_file_name;
    
    Output_File_Name( input, output_file_name );
    
    ofstream ofs( output_file_name );
    
    ofs << "Distances" << endl << endl;
    
    ofs << "Density function  L_{infty} distance" << endl;
    
    for (int counter = 0; counter < input.zone_limit; ++counter)
    {
        ofs << left << setw( 18 ) << counter;
        ofs << max_diff[counter] << endl;
    }
    
    ofs << endl;
    
    ofs << "L_{infty} summation = " << sum << endl << endl;
    
    ofs << "Density function  Dampening" << endl;
    
    for (int counter = 0; counter < input.zone_limit; ++counter)
    {
        ofs << left << setw( 18 ) << counter;
        ofs << dampening[counter] << endl;
    }
    
    ofs << endl;
    
    ofs << "d_{infty} distance = " << d_infty;
}
