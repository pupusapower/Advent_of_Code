#ifndef DAY6_H
#define DAY6_H

#include <string>
#include <vector>

using namespace std;


class CustomsFormsChecker
{
    public:
        CustomsFormsChecker();
        ~CustomsFormsChecker();
        void calcTotalYesCount(bool run_part_two);
        void calcGroupYesCount(string form_answer, bool run_part_two);
        int getTotalYesCount();
        int getUnitedYesCount();

    private:
        int total_yes_count;
        int total_united_yes_count;
        int yes_count_bitmask;
        int united_count_bitmask;
        vector<int> individual_answers_vector;

};

#endif