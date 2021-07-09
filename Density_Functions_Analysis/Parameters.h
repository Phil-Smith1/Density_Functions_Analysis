#pragma once

#include "Input.h"

string input_dir = "/Users/philsmith/Documents/Work/Xcode Projects/Density_Functions_3D/Output/Data/";

string output_dir = "/Users/philsmith/Documents/Work/Xcode Projects/Density_Functions_Analysis/Output/";

string file_name_1 = input_dir + "1a.txt";

string file_name_2 = input_dir + "2a.txt";

int zone_limit = 9;

int dimension = 3;

bool experimental_T2 = false;

string experimental_T2_label = "b2";

Input input( input_dir, output_dir, file_name_1, file_name_2, zone_limit, dimension, experimental_T2, experimental_T2_label );
