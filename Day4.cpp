#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "regex"

using namespace std;

/* Part I Regex */
// regex birth_year       ("(.*)(byr:)(.*)");
// regex issue_year       ("(.*)(iyr:)(.*)");
// regex expiration_year  ("(.*)(eyr:)(.*)");
// regex height_in        ("(.*)(hgt:)(.*)");
// regex height_cm        ("(.*)(hgt:)(.*)");
// regex hair_color       ("(.*)(hcl:)(.*)");
// regex eye_color        ("(.*)(ecl:)(.*)");
// regex passport_id      ("(.*)(pid:)(.*)");
// regex country_id       ("(.*)(cid:)(.*)");

/* Part II Regex */
regex birth_year       ("(.*)(\\s|^)+(byr:)(19[2-9][0-9]|200[0-2])(\\s|$)+(.*)");
regex issue_year       ("(.*)(\\s|^)+(iyr:)(201[0-9]|2020)(\\s|$)+(.*)");
regex expiration_year  ("(.*)(\\s|^)+(eyr:)(202[0-9]|2030)(\\s|$)+(.*)");
regex height           ("(.*)(\\s|^)+(hgt:)((59|6[0-9]|7[0-6])(in)|(1[5-8][0-9]|19[0-3])(cm))+(\\s|$)+(.*)");
regex hair_color       ("(.*)(\\s|^)+(hcl:)(#)([0-9a-f]){6}(\\s|$)+(.*)");
regex eye_color        ("(.*)(\\s|^)+(ecl:)(amb|blu|brn|gry|grn|hzl|oth)(\\s|$)+(.*)");
regex passport_id      ("(.*)(\\s|^)+(pid:)([0-9]){9}(\\s|$)+(.*)");
regex country_id       ("(.*)(\\s|^)+(cid:)(\\s|$)+(.*)");


//file definitions
string file_name = "Day4.txt";
ifstream passport_batch;

class PassportChecker
{
    private:
        bool passport_valid;
        int valid_field_count;
        int valid_passport_count;
        int valid_field_threshold = 0x7F;
        
    public:
        PassportChecker()
        {
            valid_field_count      =     0;
            valid_passport_count   =     0;
        }
        void incrementValidPassportCount()
        {
            if (valid_field_count == valid_field_threshold)
            {
                valid_passport_count++;
            }
        }
        int getValidPassportCount()
        {
            return valid_passport_count;
        }
        void resetFieldCount()
        {
            valid_field_count = 0;
        }
        void updatePassportFieldCount(string curr_line)
        {
            // Check all fields except: Country Id
            if (regex_match(curr_line, birth_year))
            {
                valid_field_count = valid_field_count^0x01;
            }
            if (regex_match(curr_line, issue_year))
            {
                valid_field_count = valid_field_count^0x02;
            }
            if (regex_match(curr_line, expiration_year))
            {
                valid_field_count = valid_field_count^0x04;
            }
            if (regex_match(curr_line, height))
            {
                valid_field_count = valid_field_count^0x08;
            }
            if (regex_match(curr_line, hair_color))
            {
                valid_field_count = valid_field_count^0x10;
            }
            if (regex_match(curr_line, eye_color))
            {
                valid_field_count = valid_field_count^0x20;
            }
            if (regex_match(curr_line, passport_id))
            {
                valid_field_count = valid_field_count^0x40;
            }
        }
};

int main()
{    
    PassportChecker tsaAgent;
    string full_line; 

    passport_batch.open(file_name);
    if(passport_batch.is_open())
    {
        while (getline(passport_batch, full_line))
        {
            //if not a new line
            if (!full_line.empty())
            {
                tsaAgent.updatePassportFieldCount(full_line);
            }
            else
            {
                tsaAgent.incrementValidPassportCount();
                tsaAgent.resetFieldCount();
            }
        }
            //Run on the last passport since we won't get a blank line after it
            tsaAgent.incrementValidPassportCount();
            tsaAgent.resetFieldCount();
        cout << "Number of valid passports is: " << tsaAgent.getValidPassportCount() << "\n";
        passport_batch.close(); 
    }
}