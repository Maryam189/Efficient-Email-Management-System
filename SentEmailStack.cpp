#include "SentEmailStack.hpp"
#include "email_system.hpp"
#include <iostream>

using namespace std;

SentEmailStack::SentEmailStack() : top(nullptr) {}

bool SentEmailStack::isEmpty() {
    return top == nullptr;
}

void SentEmailStack::push(Email email) {
    //New stack node Creation
    SentEmailNode* newNode = new SentEmailNode();
    newNode->email = email;
    // Push the new node to the top of the stack
    newNode->next = top;
    top = newNode;
}
void SentEmailStack::search(const string& keyword, const string& criterion) {
    if (isEmpty()) {
        cout << "<< No sent emails >>\n";
        return;
    }
    SentEmailNode* temp = top;
    bool found = false;
    cout <<"\n\n\t<< Searching in Sent Emails ... >>\n";
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
            cout << "\n To: " << temp->email.recipient << "\t   | Subject: " << temp->email.subject
                << "\t| Body: " << temp->email.body << "\t| Importance: " << temp->email.priority << endl;
        }
        temp = temp->next;
        
    }
    cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
    // Notify if no matching email is found
    if (!found) {
        cout << "\n\t<< No matching email found in Sent Emails. >>\n";
    }
}
void SentEmailStack::display() {
    if (top == nullptr) {
        cout << "<< No sent emails >>\n";
        return;
    }
    SentEmailNode* temp = top;
    cout << "\n<< Sent Emails shown below >>\n";
    cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
    // Traversing and displaying each email 
    while (temp != nullptr) {
        cout << "\n To: " << temp->email.recipient << "\t   | Subject: " << temp->email.subject
                << "\t| Body: " << temp->email.body << "\t| Importance: " << temp->email.priority << "\n";
        temp = temp->next;
    }
    cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
}