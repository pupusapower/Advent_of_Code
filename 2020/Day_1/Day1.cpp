#include <iostream>
#include <vector>
#include <string>
#include "Day1.h"

using namespace std;

int main()
{    
    int answer;
    int i = 0;
    bool answer_found = false;
    int temp_add = 0;
    const int DESIRED_SUM = 2020;
    int first_number = 0;
    int second_number = 0;
    int numero_uno = 0;
    int numero_dos = 0;
    int numero_tres = 0;

        for (int i = 0; i< sizeof(ExpenseReport)/sizeof(ExpenseReport[0]) && !answer_found; i++)
        {
            for (int j=i+1; j < sizeof(ExpenseReport)/sizeof(ExpenseReport[0]) && !answer_found; j++)
            {
                temp_add = ExpenseReport[i] + ExpenseReport[j];
                if (temp_add == DESIRED_SUM)
                {
                    answer_found = true;
                    first_number = i;
                    second_number = j;
                }
            }

        }

        cout << "The numbers are: " << ExpenseReport[first_number] << " and " << ExpenseReport[second_number] <<"\n\r";
        cout << "The final answer is: " << ExpenseReport[first_number] * ExpenseReport[second_number] << "\n\r";
        answer_found = false;
        
        for (int i = 0; i< sizeof(ExpenseReport)/sizeof(ExpenseReport[0]) && !answer_found; i++)
        {
            for (int j=i+1; j < sizeof(ExpenseReport)/sizeof(ExpenseReport[0]) && !answer_found; j++)
            {
                for (int k=j+1; k < sizeof(ExpenseReport)/sizeof(ExpenseReport[0]) && !answer_found; k++)
                {
                    temp_add = ExpenseReport[i] + ExpenseReport[j] + ExpenseReport[k];
                    if (temp_add == DESIRED_SUM)
                    {
                        answer_found = true;
                        numero_uno = i;
                        numero_dos = j;
                        numero_tres = k;
                    }
                }

            }

        }
        cout << "The next numbers are: " << ExpenseReport[numero_uno] << " and " << ExpenseReport[numero_dos] << " and " << ExpenseReport[numero_tres] <<"\n\r";
        cout << "The next final answer is: " << ExpenseReport[numero_uno] * ExpenseReport[numero_dos] * ExpenseReport[numero_tres];

}