#include "PriorityOutboxQueue.hpp"
#include "email_system.hpp"
#include <iostream>

using namespace std;

PriorityOutboxQueue::PriorityOutboxQueue() : front(nullptr), rear(nullptr) {}

void PriorityOutboxQueue::enqueue(Email email) {
    PriorityQueueNode* newNode = new PriorityQueueNode();
    newNode->email = email;
    newNode->next = nullptr;

    // Insert at front if priority is higher (lower numeric value)
    if (front == nullptr || email.priority < front->email.priority) {
        newNode->next = front;
        front = newNode;
        if (rear == nullptr) rear = newNode;  // Handle case where queue was empty
    } else {
        PriorityQueueNode* temp = front;
        while (temp->next != nullptr && temp->next->email.priority <= email.priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) rear = newNode;  // Update rear if inserted at the end
    }
}

Email PriorityOutboxQueue::dequeue() {
    if (front == nullptr) {
        cout << "\n<< Outbox is empty! >>" << std::endl;
        return Email();
    }
    PriorityQueueNode* temp = front;
    Email email = front->email;
    front = front->next;
    if (front == nullptr) rear = nullptr;
    delete temp;
    return email;
}

bool PriorityOutboxQueue::isEmpty() {
    return front == nullptr;
}
void PriorityOutboxQueue::search(const string& keyword, const string& criterion) {
    if (isEmpty()) {
        cout << "<< Outbox is empty! >>\n";
        return;
    }
    PriorityQueueNode* temp = front;
    bool found = false;
    cout <<"\n\n\t<< Searching in Outox Emails ... >>\n";
    cout<<"_______________________________________________________________________________________________________________________________________________________"<<endl<<endl;
    // Traversing and searching for the keyword
    while (temp != nullptr) {
        // Convert email fields to lowercase for comparison
        string senderLower = toLowerCaseManual(temp->email.sender);
        string subjectLower = toLowerCaseManual(temp->email.subject);
        string recipientLower = toLowerCaseManual(temp->email.recipient);

        // Compare lowercase versions of the email field with the search keyword
        if ((criterion == "sender" && senderLower == keyword) ||
            (criterion == "subject" && subjectLower == keyword) ||
            (criterion == "recipient" && recipientLower == keyword)) {
            found = true;   // Setting found to true if a match is found
            cout << "\n To: " << temp->email.recipient << "\t   | Subject: " << temp->email.subject
                    << "\t| Body: " << temp->email.body << "\t| Importance: " << temp->email.priority << endl;
        }
        temp = temp->next;
    }
    cout<<"_____________________________________________________________________________________________________________________________________________________"<<endl<<endl;
    // Notify if no matching email is found
    if (!found) {
        cout << "\n\t<< No matching email found in Outbox. >>\n";
    }
}
void PriorityOutboxQueue::display() {
    PriorityQueueNode* temp = front;
    if (temp == nullptr) {
        cout << "Outbox is empty!" << std::endl;
    } else {
        cout<<"\n<< Outbox Emails shown below >>\n";
        cout<<"\n____________________________________________________________________________________________________________________________________________________\n";
        // Traversing and displaying each email 
        while (temp != nullptr) {
                
                cout<<"\n To: " << temp->email.recipient << "\t   | Subject: " << temp->email.subject 
                << "\t| Body: " << temp->email.body << "\t| Importance: " << temp->email.priority <<endl;

            temp = temp->next;
        }
        cout<<"____________________________________________________________________________________________________________________________________________________"<<endl<<endl;
    }
}