#ifndef PRIORITYOUTBOXQUEUE_HPP
#define PRIORITYOUTBOXQUEUE_HPP

#include <string>
#include "email_system.hpp"

class PriorityQueueNode {
public:
    Email email;
    PriorityQueueNode* next;
};

class PriorityOutboxQueue {
private:
    PriorityQueueNode* front;
    PriorityQueueNode* rear;

public:
    PriorityOutboxQueue();
    void enqueue(Email email);
    Email dequeue();
    bool isEmpty();
    void search(const std::string& keyword, const std::string& criterion);
    void display();
};

#endif // PRIORITYOUTBOXQUEUE_HPP
