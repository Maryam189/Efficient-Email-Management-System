#ifndef SENTEMAILSTACK_HPP
#define SENTEMAILSTACK_HPP

#include <string>
#include "email_system.hpp"

class SentEmailNode {
public:
    Email email;
    SentEmailNode* next;
};

class SentEmailStack {
private:
    SentEmailNode* top;

public:
    SentEmailStack();
    bool isEmpty();
    void push(Email email);
    void search(const std::string& keyword, const std::string& criterion);
    void display();
};

#endif // SENTEMAILSTACK_HPP
