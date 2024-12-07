#include "PriorityInboxStack.hpp"
#include <iostream>
#include "email_system.hpp"

using namespace std;

PriorityInboxStack::PriorityInboxStack() : top(nullptr) {}

void PriorityInboxStack::push(Email email) {
    PriorityStackNode* newNode = new PriorityStackNode();
    newNode->email = email;

    // Insert at top if priority is higher (lower numeric value) or insert normally if the priority is the same
    if (top == nullptr || email.priority < top->email.priority) {
        newNode->next = top;
        top = newNode;
    } else {
        // Stack behavior for emails with the same priority: newer email should be on top
        PriorityStackNode* temp = top;
        while (temp->next != nullptr && temp->next->email.priority < email.priority) {
            temp = temp->next;
        }
        // Insert the new email after all lower priority emails but still follow the stack behavior for same priority
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

Email PriorityInboxStack::pop() {
    if (top == nullptr) {
        cout << "Inbox is empty!" << std::endl;
        return Email();
    }
    PriorityStackNode* temp = top;
    Email email = top->email;
    top = top->next;
    delete temp;
    return email;
}

bool PriorityInboxStack::isEmpty() {
    return top == nullptr;
}
void PriorityInboxStack::search(const string& keyword, const string& criterion) {
    if (isEmpty()) {
        cout << "<< Inbox is empty! >>\n";
        return;
    }
    PriorityStackNode* temp = top;
    bool found = false;
    cout <<"\n\n\t<< Searching in Inbox Emails ... >>\n";
    cout<<"\n____________________________________________________________________________________________________________________________________________________\n";  
    // Traversing and searching for the keyword
    while (temp != nullptr) {
        // Converting email fields to lowercase for comparison
        string senderLower = toLowerCaseManual(temp->email.sender);
        string subjectLower = toLowerCaseManual(temp->email.subject);
        string recipientLower = toLowerCaseManual(temp->email.recipient);

        // Comparing lowercase versions of the email field with the search keyword
        if ((criterion == "sender" && senderLower == keyword) ||
            (criterion == "subject" && subjectLower == keyword) ||
            (criterion == "recipient" && recipientLower == keyword)) {
            found = true;  // Setting found to true if a match is found
            cout << "\n From: " << temp->email.sender << "\t   | Subject: " << temp->email.subject
                << "\t| Body: " << temp->email.body << "\t| Importance: " << temp->email.priority << endl;
        }
        temp = temp->next;
    }
    cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
    // Notify if no matching email is found
    if (!found) {
        cout << "\n\t<< *** No matching email found in Inbox. *** >>\n";
    }
}
void PriorityInboxStack::display() {
    if (isEmpty()) {
        cout << "\n<< Inbox is empty! >>" << std::endl;
    } else {
        PriorityStackNode* temp = top;
        cout<<"\n<< Inbox Emails shown below >>\n";
        cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
        // Traversing and displaying each email 
        while (temp != nullptr) {
            cout << "\n From: " << temp->email.sender << "\t   | Subject: " << temp->email.subject
                        << "\t| Body: " << temp->email.body  << "\t| Importance: " << temp->email.priority << std::endl;
            temp = temp->next;
        }
        cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
    }
}