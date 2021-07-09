#include "Input.h"

void Input_File_Names ( Input const& input, string& file_name_1, string& file_name_2 )
{
    if (input.experimental_T2)
    {
        if (input.experimental_T2_label == "a")
        {
            file_name_1 = input.input_dir + "T2/99.txt";
            file_name_2 = input.input_dir + "Experimental_T2/Alpha.txt";
        }
        
        if (input.experimental_T2_label == "b")
        {
            file_name_1 = input.input_dir + "T2/28.txt";
            file_name_2 = input.input_dir + "Experimental_T2/Beta.txt";
        }
        
        if (input.experimental_T2_label == "b2")
        {
            file_name_1 = input.input_dir + "T2/9.txt";
            file_name_2 = input.input_dir + "Experimental_T2/Beta2.txt";
        }
        
        if (input.experimental_T2_label == "c")
        {
            file_name_1 = input.input_dir + "T2/62.txt";
            file_name_2 = input.input_dir + "Experimental_T2/Gamma.txt";
        }
        
        if (input.experimental_T2_label == "d")
        {
            file_name_1 = input.input_dir + "T2/9.txt";
            file_name_2 = input.input_dir + "Experimental_T2/Delta.txt";
        }
        
        if (input.experimental_T2_label == "e")
        {
            file_name_1 = input.input_dir + "T2/1.txt";
            file_name_2 = input.input_dir + "Experimental_T2/Epsilon.txt";
        }
    }
    
    else
    {
        file_name_1 = input.file_name_1;
        file_name_2 = input.file_name_2;
    }
    
}
