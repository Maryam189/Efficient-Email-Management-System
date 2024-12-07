#ifndef SPAM_EMAIL_STACK_HPP
#define SPAM_EMAIL_STACK_HPP

#include "email_system.hpp"
#include "PriorityInboxStack.hpp"

class SpamEmailStack {
private:
    PriorityStackNode* top;  // Using the same structure as PriorityInboxStack

public:
    SpamEmailStack();        // Constructor
    void push(Email email);  // Adding email to stack
    Email pop();             // Removing email from stack
    bool isEmpty();          // Checking if stack is empty
    void display();          // Displaying all emails in the stack
    void search(const std::string& keyword, const std::string& criterion);
};

#endif // SPAM_EMAIL_STACK_HPP
