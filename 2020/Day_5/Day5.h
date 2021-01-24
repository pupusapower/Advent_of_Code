#ifndef DAY5_H
#define DAY5_H

#include <string>
#include <vector>

using namespace std;

const int MAX_NUM_ROWS    = 128;
const int MAX_NUM_COLUMNS = 8;

class BoardingPassChecker
{
    private:
        int max_seat_id = 0;
        int max_filtered_rows = MAX_NUM_ROWS - 1;
        int max_filtered_columns = MAX_NUM_COLUMNS - 1;
        int min_filtered_rows = 0;
        int min_filtered_columns = 0;
        int seat_id = 0;
        vector<int> seat_id_vector;
        
    public:
        BoardingPassChecker();
        ~BoardingPassChecker();
        void calcSeatId(string unfiltered_seat_code);
        int getMaxSeatId();
        void addAndSortSeatIds(int new_seat_id);
        int findMySeatId();
};

#endif