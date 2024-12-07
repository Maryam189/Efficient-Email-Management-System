# Efficient Email Management System

## Project Overview

In this project, we have designed an efficient email management system using C++. The system leverages custom-built data structures such as stacks and queues to handle high volumes of emails, while maintaining optimal performance. The main functionalities of the email system include:

1. **Managing Incoming Emails**: Ensuring that users can quickly access their most recent emails.
2. **Managing Outgoing Emails**: Ensuring that outgoing emails are sent without delay by maintaining an orderly processing queue.
3. **Spam Filtering**: Using a predefined list of spam keywords to detect and filter out unwanted emails.
4. **Email Prioritization**: Prioritizing emails based on their importance to ensure critical messages receive prompt attention.

### Project Requirements

- The system is implemented in C++ and utilizes custom containers for data structures.
- The system uses **stacks** to handle incoming emails (LIFO – Last In, First Out) and **queues** for managing outgoing emails (FIFO – First In, First Out).
- The spam filter functionality reads keywords from the `spam_keywords.txt` file, which contains a list of words commonly found in spam emails.

### Files Included

- `email_system.cpp`: The main C++ file containing the implementation of the email system.
- `email_system.hpp`: The header file that declares the structures and functions used in `email_system.cpp`.
- `spam_keywords.txt`: A text file containing keywords used to detect spam emails. Each line contains one keyword.
- `README.md`: This file, which provides an overview of the project.

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


## How It Works

1. **Incoming Emails**: 
   - New incoming emails are stored in a stack. The most recent email is always at the top.
   
2. **Outgoing Emails**: 
   - Emails are sent based on a queue system, ensuring that the oldest email is sent first.

3. **Spam Detection**:
   - The program reads the `spam_keywords.txt` file and compares the content of incoming emails against these keywords. If a match is found, the email is flagged as spam.

4. **Email Prioritization**:
   - Users can assign priority levels to emails. The system will process high-priority emails first.

## Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request with your changes. All contributions are welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by real-world email management systems.
- Thanks to the C++ community for providing useful resources and support.
