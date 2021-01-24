#include <thread>
#include <ctime>
#include <iostream>
#include <regex>
#include <iterator>
#include <string>

void PrintMatches(std::string str,
        std::regex reg)
{
    std::smatch matches;
    std::cout << std::boolalpha;
    while(std::regex_search(str, matches, reg))
    {
        // std::cout << "Is there a match : " <<
        //         matches.ready() << "\n";
        // std::cout << "Are there no matches : " <<
        //         matches.empty() << "\n";
        // std::cout << "Number of matches : " <<
        //         matches.size() << "\n";
        std::cout << matches.str(1) << "\n";
        str = matches.suffix().str();
        std::cout << "\n";
    }
}        

void PrintMatches2(std::string str, std::regex reg)
{
    std::sregex_iterator currentMatch(str.begin(), str.end(), reg);
    std::sregex_iterator lastMatch;
    while(currentMatch != lastMatch)
    {
        std::smatch match = *currentMatch;
        std::cout << match.str() << "\n";
        currentMatch++;
    }
    std::cout << std::endl;

}

int main()
{
    // std::string str = "The ape was at the apex";
    // std::regex reg("(ape[^ ]?)");
    // PrintMatches(str, reg);
    
    // std::string str2 = "I picked the pickle";
    // std::regex reg2 ("(pick([^ ]+)?)");
    // PrintMatches2(str2, reg2);

    // std::string str3 = "Cat rat mat fat pat";
    // std::regex reg3 ("([crmfp]at)");
    // PrintMatches2(str3, reg3);
    // std::regex reg4 ("([C-Fc-f]at)");
    // PrintMatches2(str3, reg4);
    // std::regex reg5 ("([^Cr]at)");B
    // PrintMatches2(str3, reg5);
    // std::string str6 = "Cat rat mat fat pat";
    // std::regex reg6 ("([Cr]at)");
    // std::string owlFood = std::regex_replace(str6, reg6, "Owl");
    // std::cout << owlFood << "\n";
    std::string str7 = "F.B.I. I.R.S. CIA";
    std::regex reg7 ("([^ ]\\..\\..\\.)");
    PrintMatches2(str7, reg7);
    return 0;
}