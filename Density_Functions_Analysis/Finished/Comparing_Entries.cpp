#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

#include "Input_File_Names.h"

using namespace std;

double Comparing_Entries( Input const& input, vector<double>& max_diff )
{
    string file_name_1;
    string file_name_2;
    
    Input_File_Names( input, file_name_1, file_name_2 );
    
    ifstream ifs_1( file_name_1 );
    ifstream ifs_2( file_name_2 );
    
    string line_data;
    vector<vector<double>> file_1, file_2;
    vector<vector<double>> psi( input.zone_limit );
    
    while (getline( ifs_1, line_data ))
    {
        vector<double> col( input.zone_limit + 1 );
        stringstream stream;
        
        stream << line_data;
        
        for (int counter = 0; counter < input.zone_limit + 1; ++counter)
        {
            stream >> col[counter];
        }
        
        for (int counter = 0; counter < input.zone_limit; ++counter)
        {
            psi[counter].push_back( col[counter + 1] );
        }
    }
    
    for (int counter = 0; counter < input.zone_limit; ++counter)
    {
        file_1.push_back( psi[counter] );
        psi[counter].clear();
    }
    
    ifs_1.close();
    
    while (getline( ifs_2, line_data ))
    {
        vector<double> col( input.zone_limit + 1 );
        stringstream stream;
        
        stream << line_data;
        
        for (int counter = 0; counter < input.zone_limit + 1; ++counter)
        {
            stream >> col[counter];
        }
        
        for (int counter = 0; counter < input.zone_limit; ++counter)
        {
            psi[counter].push_back( col[counter + 1] );
        }
    }
    
    for (int counter = 0; counter < input.zone_limit; ++counter)
    {
        file_2.push_back( psi[counter] );
        psi[counter].clear();
    }
    
    ifs_2.close();
    
    int max_r_1 = (int)file_1[0].size();
    int max_r_2 = (int)file_2[0].size();
    int max_r;
    
    if (max_r_1 > max_r_2) max_r = max_r_2;
    else max_r = max_r_1;
    
    vector<double> maximum_diff( input.zone_limit, 0 );
    
    for (int counter_1 = 0; counter_1 < max_r; ++counter_1)
    {
        for (int counter_2 = 0; counter_2 < input.zone_limit; ++counter_2)
        {
            double diff = abs( file_1[counter_2][counter_1] - file_2[counter_2][counter_1] );
            
            if (diff > maximum_diff[counter_2]) maximum_diff[counter_2] = diff;
        }
    }
    
    if (max_r_1 > max_r_2)
    {
        for (int counter_1 = max_r_2; counter_1 < max_r_1; ++counter_1)
        {
            for (int counter_2 = 0; counter_2 < input.zone_limit; ++counter_2)
            {
                double diff = file_1[counter_2][counter_1];
                
                if (diff > maximum_diff[counter_2]) maximum_diff[counter_2] = diff;
            }
        }
    }
    
    if (max_r_2 > max_r_1)
    {
        for (int counter_1 = max_r_1; counter_1 < max_r_2; ++counter_1)
        {
            for (int counter_2 = 0; counter_2 < input.zone_limit; ++counter_2)
            {
                double diff = file_2[counter_2][counter_1];
                
                if (diff > maximum_diff[counter_2]) maximum_diff[counter_2] = diff;
            }
        }
    }
    
    double sum = 0;
    
    for (int counter = 0; counter < input.zone_limit; ++counter)
    {
        max_diff[counter] = maximum_diff[counter];
        sum += max_diff[counter];
    }
    
    return sum;
}
