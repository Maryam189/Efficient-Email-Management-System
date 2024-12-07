#ifndef PRIORITYINBOXSTACK_HPP
#define PRIORITYINBOXSTACK_HPP

#include <string>
#include "email_system.hpp"

class PriorityStackNode {
public:
    Email email;
    PriorityStackNode* next;
};

class PriorityInboxStack {
private:
    PriorityStackNode* top;

public:
    PriorityInboxStack();
    void push(Email email);
    Email pop();
    bool isEmpty();
    void search(const std::string& keyword, const std::string& criterion);
    void display();
};

#endif // PRIORITYINBOXSTACK_HPP
