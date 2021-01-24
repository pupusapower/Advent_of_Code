#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "regex"

using namespace std;

int main()
{    
    int i;
    int tree_count = 0;
    // int x_coordinate = 3;
    int x_coordinate = 1;
    int y_coordinate = 1;
    int x_delta = 1;
    bool first_line = true;
    int final_iteration = 5;
    float final_tree_count = 1;
    string file_name = "Day3_Slope.txt";
    ifstream slope_file;
    string current_line;
    string current_coordinate;
    string tree_string = "#";

    // PART I
    // slope_file.open(file_name);
    // if(slope_file.is_open())
    // {
    //     while (getline(slope_file, current_line))
    //     {
    //         if (first_line)
    //         {
    //             first_line = false;
    //         }
    //         else
    //         {
    //             current_coordinate = current_line[x_coordinate];
    //             if (!current_coordinate.compare(tree_string))
    //             {
    //                 tree_count++;
    //             }
    //             if (x_coordinate + 3 < current_line.size())
    //             {
    //                 x_coordinate += 3; 
    //             }
    //             else
    //             {
    //                 x_coordinate = ((x_coordinate + 3) % current_line.size());
    //             }      
    //         }
            
    //     }
    //     slope_file.close();
    // }
    // cout << "The number of trees is: " << tree_count << "\n";

    //PART II
    for (i = 0; i < final_iteration; i++)
    {
        slope_file.open(file_name);
        if(slope_file.is_open())
        {
            while (getline(slope_file, current_line))
            {
                if (first_line)
                {
                    first_line = false;
                }
                else
                {
                    if ((i != final_iteration - 1) ||(y_coordinate % 2 == 0))
                    {
                        current_coordinate = current_line[x_coordinate];
                        if (!current_coordinate.compare(tree_string))
                        {
                            tree_count++;
                        }
                        if (x_coordinate + x_delta < current_line.size())
                        {
                            x_coordinate += x_delta; 
                        }
                        else
                        {
                            x_coordinate = ((x_coordinate + x_delta) % current_line.size());
                        }
                    }
                    
                    if (i == final_iteration - 1)
                    {
                        y_coordinate++;
                    }      
                }
                
            }
        }
        slope_file.close();
        if (i+1 != final_iteration-1)
        {
            x_delta += 2;
        }
        else
        {
            x_delta = 1;
        }
        final_tree_count *= tree_count;
        first_line = true;
        x_coordinate = x_delta;
        tree_count = 0;
    }

    cout << "The number of trees is: " << final_tree_count << "\n";
}