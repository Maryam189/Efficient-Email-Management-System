#ifndef EMAIL_SYSTEM_HPP
#define EMAIL_SYSTEM_HPP

#include <string>
using namespace std;
struct Email {
    std::string subject;
    std::string sender;
    std::string recipient;
    std::string body;
    int priority;
};

std::string toLowerCaseManual(const std::string& str);
bool containsWord(const std::string& text, const std::string& keyword);
bool isSpam(Email email);
void sleep(int seconds);
bool isNumeric(const std::string& str);
std::string getValidString(const std::string& prompt);
int getValidPriority();
std::string getSearchCriterion();
int getValidMenuChoice(int size);

#endif // EMAIL_SYSTEM_HPP
