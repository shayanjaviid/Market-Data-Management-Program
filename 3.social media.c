/*
Management of social messages
Requirements:

1. Create a program that handles social messages using arrays, structures, and files.
2. Use a structure called "Message" to represent each message with attributes such as sender, recipient, timestamp, and
content of the message.
3. Store messages in an array of structures.
4. Implement functions for:

Send a message from one user to another.
View all messages sent or received by a specific user.
Save and load messages to/from a file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE 100
#define MAX_SENDER_LENGTH 100
#define MAX_CONTENT_LENGTH 1000
#define FILENAME "messages.txt"

struct Message {
    char sender[MAX_SENDER_LENGTH];
    char recipient[MAX_SENDER_LENGTH];
    time_t timestamp;
    char content[MAX_CONTENT_LENGTH];
};
struct Message messages[MAX_MESSAGE];


void sendMessage();
void viewAllMessages();
void searchMessageBySender();
void saveMessagesToFile();

int main() {
    int numMessages = 0;
    int choice;
    
    do {
        printf("\n\tMenu\t\n");
        printf(" 1) Send a message\n");
        printf(" 2) View all messages\n");
        printf(" 3) Search for messages by sender\n");
        printf(" 4) Save messages to file\n");
        printf(" 0) Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sendMessage();
                break;
            case 2:
                viewAllMessages();
                break;
            case 3:
                searchMessageBySender();
                break;
            case 4:
                saveMessagesToFile();
                break;
            case 0:
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid entry!\n");
        } getchar();
    } while (choice != 0);

    return 0;
}

void sendMessage() {
    int numMessages = 0;

    if (numMessages < MAX_MESSAGE) {
        struct Message newMessage;

        printf("Enter sender username: ");
        scanf(" %[^\n]s", newMessage.sender);

        printf("Enter recipient username: ");
        scanf(" %[^\n]s", newMessage.recipient);

        newMessage.timestamp = time(NULL);

        printf("Enter message content: ");
        getchar();
        fgets(newMessage.content, MAX_CONTENT_LENGTH, stdin);
        newMessage.content[strcspn(newMessage.content, "\n")] = 0;

        messages[numMessages++] = newMessage;
        printf("Message sent successfully.\n");
    } else {
        printf("Maximum message limit reached.\n");
    }
}

void viewAllMessages() {
    int numMessages = 0;

    if (numMessages == 0) {
        printf("No messages to display.\n");
    } else {
        printf("All messages:\n");
        for (int i = 0; i < numMessages; i++) {
            printf("Sender: %s\n", messages[i].sender);
            printf("Recipient: %s\n", messages[i].recipient);
            printf("Timestamp: %s", ctime(&messages[i].timestamp));
            printf("Content: %s\n", messages[i].content);
            printf("\n");
        }
    }
}

void searchMessageBySender() {
    int numMessages = 0;

    char searchSender[MAX_SENDER_LENGTH];
    printf("Enter the sender username to search: ");
    scanf(" %[^\n]s", searchSender);

    int found = 0;
    for (int i = 0; i < numMessages; i++) {
        if (strcmp(messages[i].sender, searchSender) == 0) {
            printf("Message found:\n");
            printf("Sender: %s\n", messages[i].sender);
            printf("Recipient: %s\n", messages[i].recipient);
            printf("Timestamp: %s", ctime(&messages[i].timestamp));
            printf("Content: %s\n", messages[i].content);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No messages from '%s' found.\n", searchSender);
    }
}

void saveMessagesToFile() {
    int numMessages = 0;
    
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numMessages; i++) {
        fprintf(file, "%s|%s|%ld|%s\n", messages[i].sender, messages[i].recipient, messages[i].timestamp, messages[i].content);
    }

    fclose(file);
    printf("Messages saved to 'messages.txt' successfully.\n");
}
