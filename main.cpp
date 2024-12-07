#include <iostream>
#include <sstream>
#include <fstream>
#include "PriorityInboxStack.hpp"
#include "PriorityOutboxQueue.hpp"
#include "SentEmailStack.hpp"
#include "SpamEmailStack.hpp"
#include "email_system.hpp"

using namespace std;

// Menu and Main Functionality
void displayMenu() {

        cout<<"\n\t\t\t\t\t ______________________________________\n";
        cout<<"\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|                 MENU                 |";
        cout<<"\n\t\t\t\t\t|______________________________________|";
        cout<<"\n\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|Kindly select an option below:        |";
        cout<<"\n\t\t\t\t\t|1. Add email to inbox                 |";
        cout<<"\n\t\t\t\t\t|2. Send email                         |";
        cout<<"\n\t\t\t\t\t|3. View inbox                         |";
        cout<<"\n\t\t\t\t\t|4. View outbox                        |";
        cout<<"\n\t\t\t\t\t|5. View sent emails                   |"; // New option to view sent emails
        cout<<"\n\t\t\t\t\t|6. View spam emails                   |"; 
        cout<<"\n\t\t\t\t\t|7. Seach Email                        |";
        cout<<"\n\t\t\t\t\t|8. EXIT                               |"<<endl;
        cout<<"\t\t\t\t\t|______________________________________|"<<endl<<endl;

}


// This function searches emails in different categories (Inbox, Outbox, Sent, Spam, or All)
void searchEmails(PriorityInboxStack& inbox, PriorityOutboxQueue& outbox, SentEmailStack& sentEmails, SpamEmailStack& spamEmails) {
    int searchChoice;

    cout << "\n\t\t\t\t\t   __________________________________\n";
    cout << "\t\t\t\t\t  |                                  |";
    cout << "\n\t\t\t\t\t  |           SUB MENU               |";
    cout << "\n\t\t\t\t\t  |__________________________________|";
    cout << "\n\t\t\t\t\t  |                                  |";
    cout << "\n\t\t\t\t\t  |Kindly select to Search in:       |";
    cout << "\n\t\t\t\t\t  | 1. INBOX                         |";
    cout << "\n\t\t\t\t\t  | 2. OUTBOX                        |";
    cout << "\n\t\t\t\t\t  | 3. SENT                          |";
    cout << "\n\t\t\t\t\t  | 4. SPAM                          |";  
    cout << "\n\t\t\t\t\t  | 5. ALL EMAILS                    |";  
    cout << "\n\t\t\t\t\t  |__________________________________|"<<endl<<endl;

    // Checking if the input was valid and within range
    searchChoice = getValidMenuChoice(5);
    
    // Asking the search keyword and criterion (sender, recipient, or subject)
    std::string keyword;
    std::string criterion = getSearchCriterion();

    cout << "Enter keyword to search: ";
    getline(cin, keyword);

    keyword = toLowerCaseManual(keyword);
    // Switch case based on the user's search choice
    switch (searchChoice) {
        case 1:
            // If the user selects Inbox, do search only in the Inbox
            inbox.search(keyword, criterion);
            break;
        case 2:
            // If the user selects Outbox, do search only in the Outbox
            outbox.search(keyword, criterion);
            break;
        case 3:
            // If the user selects Sent, do search only in Sent emails
            sentEmails.search(keyword, criterion);
            break;
        case 4:
            // If the user selects Spam, do search only in Spam emails
            spamEmails.search(keyword, criterion);
            break;
        case 5:
            // If the user selects All, search across Inbox, Outbox, Sent, and Spam emails
            cout << "\nSearching across all emails:\n";
            inbox.search(keyword, criterion);     // Search in Inbox
            outbox.search(keyword, criterion);    // Search in Outbox
            sentEmails.search(keyword, criterion); // Search in Sent emails
            spamEmails.search(keyword, criterion); // Search in Spam
            break;
        default:
            // If the user enters an invalid option, we will display an error message
            cout << "Invalid search choice!\n";
            break;
    }
}
void loadEmailsFromCSV(const string& filename, PriorityInboxStack& inbox, SpamEmailStack& spamInbox, 
                       PriorityOutboxQueue& outbox, SentEmailStack& sentEmails) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "\n\t<< *** Error: Unable to open CSV file: " << filename << " *** >>\n" << endl;
        return;
    }

    string line;
    
    // Skip the header line (first line)
    if (getline(file, line)) {
        // This reads and discards the header line
    } else {
        cout << "\n\t<< *** Error: Empty or invalid CSV file: " << filename << " *** >>\n" << endl;
        return;
    }

    // Process the remaining lines
    while (getline(file, line)) {
        stringstream ss(line);
        string sender, recipient, subject, body, priorityStr, category;
        int priority = 5;  // Default priority in case of invalid input

        getline(ss, sender, ',');
        getline(ss, recipient, ',');
        getline(ss, subject, ',');
        getline(ss, body, ',');
        getline(ss, priorityStr, ',');
        getline(ss, category, ',');

       // Checking if the priority string is a valid number before converting
        if (isNumeric(priorityStr)) {
            priority = stoi(priorityStr);  // Convert to integer if valid
        } else {
            // Handling invalid priority value
            cout << "\n\t<< *** Error: Invalid priority value '" << priorityStr << "' for email: " << subject << " *** >>" << endl;
            continue;  // Skip this line and move to the next one
        }

        // Create a new email from the CSV data
        Email email = {subject, sender, recipient, body, priority};

        // Load email into respective category
        if (category == "inbox") {
            if (isSpam(email)) {
                spamInbox.push(email);  // Add to spam if it's a spam email
            } else {
                inbox.push(email);  // Add to inbox
            }
        } else if (category == "outbox") {
            outbox.enqueue(email);  // Add to outbox
        } else if (category == "sent") {
            sentEmails.push(email);  // Add to sent emails
        } else if (category == "spam") {
            spamInbox.push(email);  // Add directly to spam
        } else {
            cout << "\n\t<< *** Error: Unknown category '" << category << "' in CSV file. *** >>\n" << endl;
        }
    }

    file.close();
    //cout << "<< Emails preloaded from CSV file. >>" << endl;
}

// This function creates a new email with valid input handling
Email createEmail() {
    Email newEmail;
    newEmail.sender = getValidString("Enter sender: ");
    newEmail.recipient = getValidString("Enter recipient: ");
    newEmail.subject = getValidString("Enter subject: ");
    newEmail.body = getValidString("Enter body: ");
    newEmail.priority = getValidPriority();
    return newEmail;
}

int main() {
    PriorityInboxStack inbox;
    PriorityOutboxQueue outbox;
    SentEmailStack sentEmails;
    SpamEmailStack spamEmails;  // Add spam stack
    cout<<"\n\t\t     ___________________________________________________________________________________________"<<endl;
    cout<<"\t\t    |                                                  \t\t\t\t\t        |";
    cout<<"\n\t\t    |\t\t\t               EMAIL MANAGEMENT SYSTEM                                  |"<<endl;
    cout<<"\t\t    |                                                  \t\t\t\t\t        |";
    cout<<"\n\t\t    |___________________________________________________________________________________________|"<<endl<<endl<<endl;
    
    // Preload emails from CSV file
    loadEmailsFromCSV("emails.csv", inbox, spamEmails, outbox, sentEmails);  // Load emails into inbox, outbox, sent, and spam
    int choice;
    do {
        displayMenu();
        choice = getValidMenuChoice(8);

        if (choice == 1) {
            // Add email to inbox
            Email newEmail = createEmail();
            if (isSpam(newEmail)) {
                cout << "\n<< This email is flagged as spam. It will not be added to the inbox. >>" << std::endl;
                spamEmails.push(newEmail);  // Add to spam inbox
            } else {
                inbox.push(newEmail);  // Only add if it's not spam
                cout<<"\n<< Email added to inbox. >>\n";
            }

            

        } else if (choice == 2) {
            // Send email
            Email newEmail = createEmail();
            if (isSpam(newEmail)) {
                cout << "\n<< This email is flagged as spam. It will not be added to the outbox. >>" << std::endl;
                spamEmails.push(newEmail); 
            } else {
                outbox.enqueue(newEmail); // Only add if it's not spam
                cout<<"\n<< Email added to outbox... >>\n";
                // View outbox
                outbox.display();
                cout << "\n<< Waiting for email to be sent... >>";
                sleep(3);  // Simulates the delay before moving email to "Sent"
                cout << "\n<< Sending email... >>\n";
                if (!outbox.isEmpty()) {
                    sentEmails.push(outbox.dequeue());  // Moving email from outbox to sent section
                    cout << "\n\n<< Email sent... >>\n";
                } else {
                    cout << "\n<< Outbox is empty, no email to send! >>\n";
                }
            }

            
            
        } else if (choice == 3) {
            // View inbox
            inbox.display();

        } else if (choice == 4) {
            // View outbox
            outbox.display();

        } else if (choice == 5) {
            sentEmails.display();  // View sent emails
        }
        else if (choice == 6) {
            spamEmails.display();  // View spam emails
        }
        else if (choice == 7) {
            searchEmails(inbox, outbox, sentEmails, spamEmails);
        }
        else if (choice == 8) {
            cout << "Exiting system...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
