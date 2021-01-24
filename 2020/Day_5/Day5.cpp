#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Day5.h"

using namespace std;

//file definitions
string file_name = "Day5.txt";
ifstream boardingpass_batch;

BoardingPassChecker::BoardingPassChecker()
{
    max_filtered_rows = MAX_NUM_ROWS - 1;
    max_filtered_columns = MAX_NUM_COLUMNS - 1;
    min_filtered_rows = 0;
    min_filtered_columns = 0;
    seat_id = 0;
}

BoardingPassChecker::~BoardingPassChecker()
{
}

int BoardingPassChecker::getMaxSeatId()
{
    return max_seat_id;
}

void BoardingPassChecker::calcSeatId(string unfiltered_seat_code)
{
    //initialize the counting variables
    max_filtered_rows = MAX_NUM_ROWS - 1;
    max_filtered_columns = MAX_NUM_COLUMNS - 1;
    min_filtered_rows = 0;
    min_filtered_columns = 0;
    seat_id = 0;
    //start the filtering
    for (int i = 0; i < unfiltered_seat_code.length(); i++)
    {
        switch (unfiltered_seat_code[i])
        {
            //Take the Front meaning the lower numbers
            case 'F':
                //only need to update the max
                max_filtered_rows -= (max_filtered_rows - min_filtered_rows + 1)/2;
                break;
            //Take the Back meaning the higher numbers
            case 'B':
                //only need to update the min
                min_filtered_rows += (max_filtered_rows - min_filtered_rows + 1)/2;
                break;
            //Take the Left meaning the lower numbers
            case 'L':
                //only need to update the max
                max_filtered_columns -= (max_filtered_columns - min_filtered_columns +1)/2;
                break;
            //Take the Right meaning the higher numbers
            case 'R':
                //only need to update the min
                min_filtered_columns += (max_filtered_columns - min_filtered_columns +1)/2;
                break;
            default:
                break;
                //do nothing      
        }
    }
    if (max_filtered_rows == min_filtered_rows && max_filtered_columns == min_filtered_columns)
    {
        //Calculate seat ID  
        seat_id = max_filtered_rows * MAX_NUM_COLUMNS + max_filtered_columns;
        addAndSortSeatIds(seat_id);
        if (seat_id > max_seat_id)
        {
            max_seat_id = seat_id;
        }
    }
}

void BoardingPassChecker::addAndSortSeatIds(int new_seat_id)
{
    seat_id_vector.push_back(new_seat_id);
    sort(seat_id_vector.begin(), seat_id_vector.end());
}

int BoardingPassChecker::findMySeatId()
{
    for (int i = 0; i < seat_id_vector.size(); i++)
    {
        if ((seat_id_vector[i] != (i + seat_id_vector[0]))       &&
            (seat_id_vector[i-1] == (i - 1 + seat_id_vector[0])) &&
            (seat_id_vector[i] == (i + 1 + seat_id_vector[0])))
        {
            return i + seat_id_vector[0];
        }
    }
}

int main()
{    
    BoardingPassChecker checker;
    string seat_code; 

    boardingpass_batch.open(file_name);
    if(boardingpass_batch.is_open())
    {
        while (getline(boardingpass_batch, seat_code))
        {
            checker.calcSeatId(seat_code);
        }
        cout << "Max Seat ID is: " << checker.getMaxSeatId() << "\n";
        cout << "My Seat ID is: " << checker.findMySeatId() << "\n";
        boardingpass_batch.close(); 
        checker.~BoardingPassChecker();
    }
}