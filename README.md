# Efficient Email Management System

## Project Overview

In this project, we have designed an efficient email management system using C++. The system leverages custom-built data structures such as stacks and queues to handle high volumes of emails while maintaining optimal performance. The main functionalities of the email system include:

1. **Managing Incoming Emails**: Ensuring that users can quickly access their most recent emails.
2. **Managing Outgoing Emails**: Ensuring that outgoing emails are sent without delay by maintaining an orderly processing queue.
3. **Spam Filtering**: Using a predefined list of spam keywords to detect and filter out unwanted emails.
4. **Email Prioritization**: Prioritizing emails based on their importance to ensure critical messages receive prompt attention.

### Project Requirements

- The system is implemented in C++ and utilizes custom containers for data structures.
- The system uses **stacks** to handle incoming emails (LIFO – Last In, First Out) and **queues** for managing outgoing emails (FIFO – First In, First Out).
- The spam filter functionality reads keywords from the `spam_keywords.txt` file, which contains a list of words commonly found in spam emails.

### Files Included

1. **`email_system.cpp`**: The main C++ file containing the implementation of the email system.
2. **`email_system.hpp`**: The header file that declares the structures and functions used in `email_system.cpp`.
3. **`spam_keywords.txt`**: A text file containing keywords used to detect spam emails. Each line contains one keyword.
4. **`PriorityInboxStack.hpp`**: Declares the `PriorityInboxStack` class to manage the inbox using a priority stack.
5. **`PriorityOutboxQueue.hpp`**: Declares the `PriorityOutboxQueue` class to manage the outbox using a queue.
6. **`SentEmailStack.hpp`**: Declares the `SentEmailStack` class to manage sent emails using a stack.
7. **`SpamEmailStack.hpp`**: Declares the `SpamEmailStack` class to manage spam emails using a stack.
8. **`main.cpp`**: The entry point of the program where the main menu and user interaction are handled.


## Features

1. **Incoming Email Handling**: 
   - Emails are stored in a stack, ensuring the most recent emails are accessed first.

2. **Outgoing Email Handling**: 
   - Emails are processed in an orderly fashion using a queue, ensuring that emails are sent in the order they were created.

3. **Spam Filtering**: 
   - The system reads the list of spam keywords from the `spam_keywords.txt` file. Emails containing any of these keywords are flagged as spam.

4. **Email Prioritization**: 
   - Emails can be prioritized based on their importance level, ensuring that urgent emails receive prompt attention.


## Running the Code

### Prerequisites

- C++ compiler (e.g., GCC, Clang)
- C++11 or later
- Text editor or IDE (e.g., Visual Studio Code, CLion)

### Steps to Run

1. **Clone the repository** (if applicable):
    ```bash
    git clone <repository_url>
    ```

2. **Navigate to the project directory**:
    ```bash
    cd email_management_system
    ```

3. **Compile the C++ code**:
    ```bash
    g++ -o email_system email_system.cpp
    ```

4. **Run the program**:
    ```bash
    ./email_system
    ```

### Example Input

- The program will ask for email data such as subject, sender, content, and priority.
- It will also process incoming emails, prioritize them, and filter out spam based on the keywords in `spam_keywords.txt`.


## How Spam Filtering Works

The system uses the file `spam_keywords.txt` to filter emails. Each line in this text file contains a keyword commonly found in spam messages. When an email is received, its content is checked against the keywords in this file. If any of the keywords match, the email is flagged as spam and placed in a separate spam folder.

### Example `spam_keywords.txt`:

win free limited offer claim your prize exclusive deal


## File Descriptions

1. **`email_system.cpp`**:
   - Contains the core logic for handling incoming emails, outgoing emails, spam detection, and prioritization. The system is implemented using custom data structures like stacks and queues.

2. **`email_system.hpp`**:
   - The header file where the structure of `Email` is defined, and the necessary function prototypes for email handling, such as spam detection and email creation, are declared.

3. **`spam_keywords.txt`**:
   - A simple text file containing words that are considered spam. Each line represents a single keyword. These keywords are used for filtering incoming emails.

4. **`PriorityInboxStack.hpp`**:
   - This header file contains the declaration for the `PriorityInboxStack` class, which is used to manage the inbox using a stack. It ensures that emails are stored and accessed based on priority, where higher-priority emails are processed first.

5. **`PriorityOutboxQueue.hpp`**:
   - This header file contains the declaration for the `PriorityOutboxQueue` class, which is used to manage outgoing emails in a queue. It processes emails in the order they were added (FIFO), while ensuring higher-priority emails are handled first.

6. **`SentEmailStack.hpp`**:
   - This header file contains the declaration for the `SentEmailStack` class, which is used to store emails that have been sent. It is implemented as a stack, following LIFO (Last In, First Out) principle.

7. **`SpamEmailStack.hpp`**:
   - This header file contains the declaration for the `SpamEmailStack` class, which is used to store emails that are flagged as spam. It is implemented as a stack, following the LIFO (Last In, First Out) principle.

8. **`main.cpp`**:
   - The entry point of the program. It includes the menu and user interactions, such as creating emails, searching for emails, viewing inbox, outbox, spam, and sent emails.


## Conclusion

This project demonstrates how to build an efficient and robust email management system using custom data structures in C++. The system manages incoming and outgoing emails, filters spam, and prioritizes emails based on importance, providing a practical solution to handling large volumes of email traffic.


## Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request with your changes. All contributions are welcome!


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.


## Acknowledgments

- Inspired by real-world email management systems.
- Thanks to the C++ community for providing useful resources and support.


