#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Day2.h"
#include "regex"


using namespace std;




int main()
{    
    int number_valid_passwords = 0;
    uint8_t occurrence_count = 0;
    uint8_t min_count = 0;
    uint8_t max_count = 0;
    string  test_password;
    string  full_line;
    string colon_line;
    string file_name = "Day2_PasswordInput.txt";
    string last_part;
    ifstream password_file;
    regex space ("\\s");
    regex colon ("\\:");
    smatch minsm;
    smatch maxsm;
    smatch keysm;
    smatch matches;
    string::size_type sz;
    int min;
    int max;
    string key_letter;
    smatch num_matches;
    string password;
    string first_letter;
    string last_letter;
    char passchar;

    // password_file.open(file_name);
    // if(password_file.is_open())
    // {
    //     while (getline(password_file, full_line))
    //     {

    //         std::regex reg7 ("(\\d)+");
    //         std::regex reg8 ("([a-z])");


    //         regex_search(full_line, minsm, reg7);
    //         min = stoi(minsm.str(0), &sz);

    //         last_part = minsm.suffix();
    //         regex_search(last_part, maxsm, reg7);
    //         max = stoi(maxsm.str(0), &sz );

    //         colon_line = maxsm.suffix();
    //         regex_search(colon_line, keysm, reg8);
    //         key_letter = keysm.str(1);
    //         regex reg9 (key_letter);
    //         password = keysm.suffix();
    //         while(std::regex_search(password, matches, reg9))
    //         {

    //             occurrence_count++;
    //             password = matches.suffix().str();
    //         }
    //         if ((occurrence_count >= min) && (occurrence_count <= max))
    //         {
    //             number_valid_passwords++;
    //         }
    //         occurrence_count = 0;
    //     }
    //     password_file.close();
    password_file.open(file_name);
    if(password_file.is_open())
    {
        while (getline(password_file, full_line))
        {

            std::regex reg7 ("(\\d)+");
            std::regex reg8 ("([a-z])");


            regex_search(full_line, minsm, reg7);
            min = stoi(minsm.str(0), &sz);

            last_part = minsm.suffix();
            regex_search(last_part, maxsm, reg7);
            max = stoi(maxsm.str(0), &sz );

            colon_line = maxsm.suffix();
            regex_search(colon_line, keysm, reg8);
            key_letter = keysm.str(1);
            regex reg9 (key_letter);
            password = keysm.suffix();
            first_letter = password[min+1];
            last_letter = password[max+1];
            if (regex_match(first_letter, reg9) ^ regex_match(last_letter, reg9))
            {
                number_valid_passwords++;
            }
            // while(std::regex_search(password, matches, reg9))
            // {

            //     occurrence_count++;
            //     password = matches.suffix().str();
            // }
            // if ((occurrence_count >= min) && (occurrence_count <= max))
            // {
            //     number_valid_passwords++;
            // }
            // occurrence_count = 0;
        }
        password_file.close();
    }
    cout << "The number of valid passwords is: " << number_valid_passwords << "\n";
}