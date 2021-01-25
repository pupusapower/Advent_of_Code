#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Day6.h"

using namespace std;

//file definitions
string file_name = "Day6.txt";
ifstream customsforms_input;

CustomsFormsChecker::CustomsFormsChecker()
{
    total_yes_count = 0;
    yes_count_bitmask = 0;
    total_united_yes_count = 0;
    united_count_bitmask = 0;
}

CustomsFormsChecker::~CustomsFormsChecker()
{

}

void CustomsFormsChecker::calcGroupYesCount(string form_answer, bool run_part_two)
{
    for (int i = 0; i < form_answer.length(); i++)
    {
        switch (form_answer[i])
        {
            case 'a':
                yes_count_bitmask |= 0b00000000000000000000000000000001; 
                break;
            case 'b':
                yes_count_bitmask |= 0b00000000000000000000000000000010;
                break;
            case 'c':
                yes_count_bitmask |= 0b00000000000000000000000000000100;
                break;
            case 'd':
                yes_count_bitmask |= 0b00000000000000000000000000001000;
                break;
            case 'e':
                yes_count_bitmask |= 0b00000000000000000000000000010000;
                break; 
            case 'f':
                yes_count_bitmask |= 0b00000000000000000000000000100000;
                break;
            case 'g':
                yes_count_bitmask |= 0b00000000000000000000000001000000;
                break; 
            case 'h':
                yes_count_bitmask |= 0b00000000000000000000000010000000;
                break;
            case 'i':
                yes_count_bitmask |= 0b00000000000000000000000100000000;
                break;
            case 'j':
                yes_count_bitmask |= 0b00000000000000000000001000000000;
                break; 
            case 'k':
                yes_count_bitmask |= 0b00000000000000000000010000000000;
                break;
            case 'l':
                yes_count_bitmask |= 0b00000000000000000000100000000000;
                break;
            case 'm':
                yes_count_bitmask |= 0b00000000000000000001000000000000;
                break;  
            case 'n':
                yes_count_bitmask |= 0b00000000000000000010000000000000;
                break;
            case 'o':
                yes_count_bitmask |= 0b00000000000000000100000000000000;
                break;
            case 'p':
                yes_count_bitmask |= 0b00000000000000001000000000000000;
                break;
            case 'q':
                yes_count_bitmask |= 0b00000000000000010000000000000000;
                break;
            case 'r':
                yes_count_bitmask |= 0b00000000000000100000000000000000;
                break;
            case 's':
                yes_count_bitmask |= 0b00000000000001000000000000000000;
                break;
            case 't':
                yes_count_bitmask |= 0b00000000000010000000000000000000;
                break;
            case 'u':
                yes_count_bitmask |= 0b00000000000100000000000000000000;
                break;
            case 'v':
                yes_count_bitmask |= 0b00000000001000000000000000000000;
                break;
            case 'w':
                yes_count_bitmask |= 0b00000000010000000000000000000000;
                break;
            case 'x':
                yes_count_bitmask |= 0b00000000100000000000000000000000;
                break;
            case 'y':
                yes_count_bitmask |= 0b00000001000000000000000000000000;
                break;
            case 'z':
                yes_count_bitmask |= 0b00000010000000000000000000000000;
                break;             
        }
    }
    if (run_part_two)
    {
        individual_answers_vector.push_back(yes_count_bitmask);
        yes_count_bitmask = 0;
    }
}

int CustomsFormsChecker::getTotalYesCount()
{
    return total_yes_count;
}

int CustomsFormsChecker::getUnitedYesCount()
{
    return total_united_yes_count;
}

void CustomsFormsChecker::calcTotalYesCount(bool run_part_two)
{
    if (run_part_two)
    {
        united_count_bitmask = individual_answers_vector[0];
        for (int i = 0; i < individual_answers_vector.size(); i++)
        {
            united_count_bitmask &= individual_answers_vector[i];
        }
        while (united_count_bitmask)
        { 
            total_united_yes_count += united_count_bitmask & 1; 
            united_count_bitmask >>= 1; 
        } 
    }
    else
    {
        while (yes_count_bitmask)
        { 
            total_yes_count += yes_count_bitmask & 1; 
            yes_count_bitmask >>= 1; 
        } 
    }
    individual_answers_vector.clear();
    united_count_bitmask = 0;
    yes_count_bitmask = 0;
}

int main()
{    
    CustomsFormsChecker checker;
    string customs_answer; 
    int execute_part_two = true;

    customsforms_input.open(file_name);
    if(customsforms_input.is_open())
    {
        while (getline(customsforms_input, customs_answer))
        {
            //If reached the end of a group
            if (customs_answer.empty())
            {
                checker.calcTotalYesCount(execute_part_two);
            }
            //if still a group line
            else
            {
                checker.calcGroupYesCount(customs_answer, execute_part_two);
            }
        }
        //Calculate the total count for the last customs form group
        checker.calcTotalYesCount(execute_part_two);
        cout << "Total yes count is: " << checker.getTotalYesCount() << "\n";
        cout << "Total united yes count is: " << checker.getUnitedYesCount() << "\n";

        customsforms_input.close(); 
        checker.~CustomsFormsChecker();
    }
}