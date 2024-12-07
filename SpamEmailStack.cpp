#include "SpamEmailStack.hpp"
#include <iostream>
#include "email_system.hpp"
using namespace std;

SpamEmailStack::SpamEmailStack() : top(nullptr) {}

void SpamEmailStack::push(Email email) {
    // Creating a new stack node
    PriorityStackNode* newNode = new PriorityStackNode();
    newNode->email = email;  // Assigning email to the new node

    // Pushing the new node to the top of the stack
    newNode->next = top;
    top = newNode;
}
Email SpamEmailStack::pop() {
    // Checking if the stack is empty
    if (top == nullptr) {
        std::cerr << "Spam Inbox is empty!" << std::endl;
        return Email();  // Return an empty email if the stack is empty
    }

    // Removing top email from the stack
    PriorityStackNode* temp = top;
    Email email = top->email;
    top = top->next;

    // Free memory and return the email
    delete temp;
    return email;
}
bool SpamEmailStack::isEmpty() {
    return top == nullptr;
}

void SpamEmailStack::display() {
    // Checking if the spam stack is empty
    if (isEmpty()) {
        cout << "\n<< Spam Inbox is empty! >>" << std::endl;
    } else {
        PriorityStackNode* temp = top;
        cout<<"\n<< Spam Emails shown below >>\n";
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

void SpamEmailStack::search(const std::string& keyword, const std::string& criterion) {
    // Check if the spam stack is empty
    if (isEmpty()) {
        cout << "<< Spam Inbox is empty! >>\n";
        return;
    }
    PriorityStackNode* temp = top;
    bool found = false;
    cout <<"\n\n\t<< Searching in Spam Emails ... >>\n";
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
            found = true;   // Setting found to true if a match is found
            cout << "\n From: " << temp->email.sender << "\t   | Subject: " << temp->email.subject
                 << "\t| Body: " << temp->email.body << "\t| Importance: " << temp->email.priority << endl;
        }
        temp = temp->next;       // Move to the next node
    }
    cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
    // Notify if no matching email is found
    if (!found) {
        cout << "\n\t<< *** No matching email found in Spam Inbox. *** >>\n";
    }
}


