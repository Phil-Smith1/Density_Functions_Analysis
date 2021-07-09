#include "Input.h"

void Output_File_Name ( Input const& input, string& file_name )
{
    if (input.experimental_T2)
    {
        if (input.experimental_T2_label == "a")
        {
            file_name = input.output_dir + "Alpha.txt";
        }
        
        if (input.experimental_T2_label == "b")
        {
            file_name = input.output_dir + "Beta.txt";
        }
        
        if (input.experimental_T2_label == "b2")
        {
            file_name = input.output_dir + "Beta2.txt";
        }
        
        if (input.experimental_T2_label == "c")
        {
            file_name = input.output_dir + "Gamma.txt";
        }
        
        if (input.experimental_T2_label == "d")
        {
            file_name = input.output_dir + "Delta.txt";
        }
        
        if (input.experimental_T2_label == "e")
        {
            file_name = input.output_dir + "Epsilon.txt";
        }
    }
    
    else
    {
        file_name = input.output_dir + "Results.txt";
    }
    
}
