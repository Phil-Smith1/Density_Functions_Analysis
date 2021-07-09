#include <vector>
#include <cmath>

#include "Input.h"

double D_Infinity_Distance ( Input const& input, vector<double>const& max_diff, vector<double>& dampening )
{
    for (int counter = 0; counter < max_diff.size(); ++counter)
    {
        double scalar = 0;
        
        if (input.dimension == 3) scalar = 1 / (double)(cbrt( counter + 1 ) * cbrt( counter + 1 ));
        
        else if (input.dimension == 2) scalar = 1 / (double)(sqrt( counter + 1 ) * sqrt( counter + 1 ));
        
        dampening[counter] = scalar * max_diff[counter];
    }
    
    double max = 0;
    
    for (int counter = 0; counter < dampening.size(); ++counter)
    {
        if (dampening[counter] > max) max = dampening[counter];
    }
    
    return max;
}
