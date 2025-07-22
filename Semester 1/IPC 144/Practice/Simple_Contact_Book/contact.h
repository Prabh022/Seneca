#ifndef CONTACT_BOOK_H
#define CONTACT_BOOK_H

struct Contact {
	char name[50];
	char phone[15];
};


void addContact(const char *filename);
void viewContact(const char *filename);
void searchContact(const char *filename, const char *targetName);
#endif // !CONTACT_BOOK_H
