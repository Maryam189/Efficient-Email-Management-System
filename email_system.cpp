#include "email_system.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
using namespace std;

void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));  // Pauses execution for a given time
}

// This function handles invalid input for integers (e.g., priority)
void clearInput() {
    cin.clear();  // Clear the error flag on cin
    cin.ignore(10000, '\n');  // Discard invalid input (larger number)
}

// This function converts a string to lowercase manually
string toLowerCaseManual(const string& str) {
    string lowerStr = str;
    for (int i = 0; i < lowerStr.length(); i++) {
        if (lowerStr[i] >= 'A' && lowerStr[i] <= 'Z') {
            lowerStr[i] = lowerStr[i] + ('a' - 'A');  // Convert uppercase to lowercase
        }
    }
    return lowerStr;
}
// Convert priority from string to integer with error handling using if-else
// Function to check if a string is numeric
bool isNumeric(const std::string& str) {
    // Check if the string is non-empty
    if (str.empty()) {
        return false;
    }
    
    // Loop through each character and check if it's a digit
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;  // Return true if all characters are digits
}


// This function manually split a string into words and check if any match the spam keyword
bool containsWord(const string& text, const string& keyword) {
    size_t pos = 0;
    size_t length = keyword.length();
    
    while ((pos = text.find(keyword, pos)) != string::npos) {
        // We are making sure the found keyword is a standalone word (check for space or start/end of string)
        bool isStartValid = (pos == 0 || !isalnum(text[pos - 1]));
        bool isEndValid = (pos + length == text.length() || !isalnum(text[pos + length]));
        
        if (isStartValid && isEndValid) {
            return true;
        }
        pos = pos + length;  // Move past the current position
    }
    return false;
}


bool isSpam(Email email) {
    ifstream file("spam_keywords.txt");
    if (!file.is_open()) {
        cout << "\n\t<< Error: spam_keywords.txt file not found! >>" << std::endl;
        return false;  // Treat as non-spam if file is missing
    }
    string keyword;
    
    // Converting subject and body to lowercase
    string subjectLower = toLowerCaseManual(email.subject);
    string bodyLower = toLowerCaseManual(email.body);

    // Reading through the spam keywords
    while (file >> keyword) {
        string keywordLower = toLowerCaseManual(keyword);  // Converting keyword to lowercase

        // Checking for whole-word matches in both the subject and the body
        if (containsWord(subjectLower, keywordLower) || containsWord(bodyLower, keywordLower)) {
            cout << "Spam word detected: " << keywordLower << std::endl;
            return true;
        }
    }
    return false;
}


// This function validates non-empty string inputs
string getValidString(const string& prompt) {
    string input;
    do {
        cout << prompt;
        getline(cin, input);
        if (input.empty()) {
            cout << "\n\t<< Error: Input cannot be empty. Please try again. >>\n";
        }
    } while (input.empty());
    return input;
}

// This function validates priority input (1-5)
int getValidPriority() {
    int priority;
    while (true) {
        cout << "Enter priority (1 = high, 5 = low): ";
        cin >> priority;

        // Checking if the input was valid
        if (!cin.fail() && priority >= 1 && priority <= 5) {
            cin.ignore();  // Clears buffer after valid input
            return priority;
        } else {
            cout << "\n\t<<Error: Priority must be a number between 1 and 5. >>\n";
            clearInput();  // Clear invalid input
        }
    }
}

// This function get search criteria
string getSearchCriterion() {
    int criterionChoice;

    cout<<"\n\t\t\t\t\t    ________________________________\n";
    cout<<"\t\t\t\t\t   |                                |";
    cout<<"\n\t\t\t\t\t   |           SUB SUB MENU         |";
    cout<<"\n\t\t\t\t\t   |________________________________|";
    cout<<"\n\t\t\t\t\t   |                                |";
    cout<<"\n\t\t\t\t\t   |Kindly select to Search by:     |";
    cout<<"\n\t\t\t\t\t   | 1. SENDER                      |";
    cout<<"\n\t\t\t\t\t   | 2. RECIPIENT                   |";
    cout<<"\n\t\t\t\t\t   | 3. SUBJECT                     |";
    cout<<"\n\t\t\t\t\t   |________________________________|"<<endl<<endl;
    criterionChoice = getValidMenuChoice(3);

    switch (criterionChoice) {
        case 1: return "sender";
        case 2: return "recipient";
        case 3: return "subject";
        default: return "";
    }
}

// This function validates menu choice without using limits library
int getValidMenuChoice(int size) {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        // Checking if the input was valid and within range
        if (!cin.fail() && choice >= 1 && choice <= size) {
            cin.ignore();  // Clears buffer for string input
            return choice;
        } else {
            cout << "\n\t<< Error: Invalid menu choice. Please select between 1 and " << size <<". >>\n";
            clearInput();  // Clear invalid input
        }
    }
}


