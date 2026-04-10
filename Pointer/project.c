#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ========================================
// CONSTANTS
// ========================================
#define MAX_BOOKS 100
#define MAX_MEMBERS 50
#define MAX_TRANS 200

// ========================================
// DATA STRUCTURES
// ========================================

typedef struct {
    int book_id;
    char title[100];
    char author[50];
    char isbn[20];
    int is_available;  // 1 = available, 0 = issued
} Book;

typedef struct {
    int member_id;
    char name[50];
    char phone[15];
} Member;

typedef struct {
    int transaction_id;
    int book_id;
    int member_id;
    char issue_date[11];
    char return_date[11];
    int is_active;  // 1 = active, 0 = returned
} Transaction;

// ========================================
// GLOBAL DATA
// ========================================

Book books[MAX_BOOKS];
Member members[MAX_MEMBERS];
Transaction transactions[MAX_TRANS];

int book_count = 0;
int member_count = 0;
int transaction_count = 0;

// File names
const char* BOOKS_FILE = "books.dat";
const char* MEMBERS_FILE = "members.dat";
const char* TRANS_FILE = "transactions.dat";

// ========================================
// UTILITY FUNCTIONS
// ========================================

void get_current_date(char* date_str) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date_str, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pause_screen() {
    printf("\nPress Enter to continue...");
    clear_input_buffer();
    getchar();
}

// ========================================
// FILE I/O FUNCTIONS
// ========================================

void save_books_to_file() {
    FILE* fp = fopen(BOOKS_FILE, "wb");
    if (fp == NULL) {
        printf("Error: Unable to save books data.\n");
        return;
    }
    
    // Write count first
    fwrite(&book_count, sizeof(int), 1, fp);
    
    // Write all books
    fwrite(books, sizeof(Book), book_count, fp);
    
    fclose(fp);
}

void load_books_from_file() {
    FILE* fp = fopen(BOOKS_FILE, "rb");
    if (fp == NULL) {
        // File doesn't exist yet (first run)
        book_count = 0;
        return;
    }
    
    // Read count
    fread(&book_count, sizeof(int), 1, fp);
    
    // Read all books
    fread(books, sizeof(Book), book_count, fp);
    
    fclose(fp);
}

void save_members_to_file() {
    FILE* fp = fopen(MEMBERS_FILE, "wb");
    if (fp == NULL) {
        printf("Error: Unable to save members data.\n");
        return;
    }
    
    fwrite(&member_count, sizeof(int), 1, fp);
    fwrite(members, sizeof(Member), member_count, fp);
    
    fclose(fp);
}

void load_members_from_file() {
    FILE* fp = fopen(MEMBERS_FILE, "rb");
    if (fp == NULL) {
        member_count = 0;
        return;
    }
    
    fread(&member_count, sizeof(int), 1, fp);
    fread(members, sizeof(Member), member_count, fp);
    
    fclose(fp);
}

void save_transactions_to_file() {
    FILE* fp = fopen(TRANS_FILE, "wb");
    if (fp == NULL) {
        printf("Error: Unable to save transactions data.\n");
        return;
    }
    
    fwrite(&transaction_count, sizeof(int), 1, fp);
    fwrite(transactions, sizeof(Transaction), transaction_count, fp);
    
    fclose(fp);
}

void load_transactions_from_file() {
    FILE* fp = fopen(TRANS_FILE, "rb");
    if (fp == NULL) {
        transaction_count = 0;
        return;
    }
    
    fread(&transaction_count, sizeof(int), 1, fp);
    fread(transactions, sizeof(Transaction), transaction_count, fp);
    
    fclose(fp);
}

// ========================================
// BOOK MANAGEMENT
// ========================================

int generate_book_id() {
    if (book_count == 0) return 1;
    
    // Find highest ID and add 1
    int max_id = books[0].book_id;
    for (int i = 1; i < book_count; i++) {
        if (books[i].book_id > max_id) {
            max_id = books[i].book_id;
        }
    }
    return max_id + 1;
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("\nError: Library is full. Cannot add more books.\n");
        return;
    }
    
    Book new_book;
    new_book.book_id = generate_book_id();
    
    printf("\n--- Add New Book ---\n");
    printf("Book ID (auto-generated): %d\n", new_book.book_id);
    
    printf("Enter Title: ");
    clear_input_buffer();
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;  // Remove newline
    
    printf("Enter Author: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;
    
    printf("Enter ISBN: ");
    fgets(new_book.isbn, sizeof(new_book.isbn), stdin);
    new_book.isbn[strcspn(new_book.isbn, "\n")] = 0;
    
    new_book.is_available = 1;  // Book is available by default
    
    // Add to array
    books[book_count] = new_book;
    book_count++;
    
    // Save to file
    save_books_to_file();
    
    printf("\n✓ Book added successfully! (ID: %d)\n", new_book.book_id);
}

void display_books() {
    if (book_count == 0) {
        printf("\nNo books in library.\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("           ALL BOOKS\n");
    printf("========================================\n");
    printf("%-5s %-30s %-20s %-15s %-10s\n", "ID", "Title", "Author", "ISBN", "Status");
    printf("------------------------------------------------------------------------\n");
    
    for (int i = 0; i < book_count; i++) {
        printf("%-5d %-30s %-20s %-15s %-10s\n",
               books[i].book_id,
               books[i].title,
               books[i].author,
               books[i].isbn,
               books[i].is_available ? "Available" : "Issued");
    }
    printf("========================================\n");
}

int find_book_by_id(int book_id) {
    for (int i = 0; i < book_count; i++) {
        if (books[i].book_id == book_id) {
            return i;  // Return index
        }
    }
    return -1;  // Not found
}

void search_book() {
    int choice;
    printf("\n--- Search Book ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by Title\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        int search_id;
        printf("Enter Book ID: ");
        scanf("%d", &search_id);
        
        int index = find_book_by_id(search_id);
        if (index == -1) {
            printf("\nBook not found.\n");
        } else {
            printf("\n--- Book Found ---\n");
            printf("ID: %d\n", books[index].book_id);
            printf("Title: %s\n", books[index].title);
            printf("Author: %s\n", books[index].author);
            printf("ISBN: %s\n", books[index].isbn);
            printf("Status: %s\n", books[index].is_available ? "Available" : "Issued");
        }
    } else if (choice == 2) {
        char search_title[100];
        printf("Enter Title (partial match): ");
        clear_input_buffer();
        fgets(search_title, sizeof(search_title), stdin);
        search_title[strcspn(search_title, "\n")] = 0;
        
        int found = 0;
        printf("\n--- Search Results ---\n");
        for (int i = 0; i < book_count; i++) {
            if (strstr(books[i].title, search_title) != NULL) {
                printf("ID: %d | Title: %s | Author: %s | Status: %s\n",
                       books[i].book_id,
                       books[i].title,
                       books[i].author,
                       books[i].is_available ? "Available" : "Issued");
                found = 1;
            }
        }
        if (!found) {
            printf("No matching books found.\n");
        }
    }
}

void delete_book() {
    int delete_id;
    printf("\n--- Delete Book ---\n");
    printf("Enter Book ID to delete: ");
    scanf("%d", &delete_id);
    
    int index = find_book_by_id(delete_id);
    if (index == -1) {
        printf("\nBook not found.\n");
        return;
    }
    
    // Check if book is currently issued
    if (!books[index].is_available) {
        printf("\nError: Book is currently issued. Cannot delete.\n");
        return;
    }
    
    // Confirm deletion
    char confirm;
    printf("Delete '%s'? (y/n): ", books[index].title);
    clear_input_buffer();
    scanf("%c", &confirm);
    
    if (confirm == 'y' || confirm == 'Y') {
        // Shift all books after this one to the left
        for (int i = index; i < book_count - 1; i++) {
            books[i] = books[i + 1];
        }
        book_count--;
        
        save_books_to_file();
        printf("\n✓ Book deleted successfully.\n");
    } else {
        printf("\nDeletion cancelled.\n");
    }
}

// ========================================
// MEMBER MANAGEMENT
// ========================================

int generate_member_id() {
    if (member_count == 0) return 1;
    
    int max_id = members[0].member_id;
    for (int i = 1; i < member_count; i++) {
        if (members[i].member_id > max_id) {
            max_id = members[i].member_id;
        }
    }
    return max_id + 1;
}

void add_member() {
    if (member_count >= MAX_MEMBERS) {
        printf("\nError: Member limit reached.\n");
        return;
    }
    
    Member new_member;
    new_member.member_id = generate_member_id();
    
    printf("\n--- Add New Member ---\n");
    printf("Member ID (auto-generated): %d\n", new_member.member_id);
    
    printf("Enter Name: ");
    clear_input_buffer();
    fgets(new_member.name, sizeof(new_member.name), stdin);
    new_member.name[strcspn(new_member.name, "\n")] = 0;
    
    printf("Enter Phone: ");
    fgets(new_member.phone, sizeof(new_member.phone), stdin);
    new_member.phone[strcspn(new_member.phone, "\n")] = 0;
    
    members[member_count] = new_member;
    member_count++;
    
    save_members_to_file();
    
    printf("\n✓ Member added successfully! (ID: %d)\n", new_member.member_id);
}

void display_members() {
    if (member_count == 0) {
        printf("\nNo members registered.\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("         ALL MEMBERS\n");
    printf("========================================\n");
    printf("%-5s %-30s %-15s\n", "ID", "Name", "Phone");
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < member_count; i++) {
        printf("%-5d %-30s %-15s\n",
               members[i].member_id,
               members[i].name,
               members[i].phone);
    }
    printf("========================================\n");
}

int find_member_by_id(int member_id) {
    for (int i = 0; i < member_count; i++) {
        if (members[i].member_id == member_id) {
            return i;
        }
    }
    return -1;
}

// ========================================
// TRANSACTION MANAGEMENT
// ========================================

int generate_transaction_id() {
    if (transaction_count == 0) return 1;
    
    int max_id = transactions[0].transaction_id;
    for (int i = 1; i < transaction_count; i++) {
        if (transactions[i].transaction_id > max_id) {
            max_id = transactions[i].transaction_id;
        }
    }
    return max_id + 1;
}

void issue_book() {
    int book_id, member_id;
    
    printf("\n--- Issue Book ---\n");
    printf("Enter Book ID: ");
    scanf("%d", &book_id);
    
    // Find book
    int book_index = find_book_by_id(book_id);
    if (book_index == -1) {
        printf("\nError: Book not found.\n");
        return;
    }
    
    // Check availability
    if (!books[book_index].is_available) {
        printf("\nError: Book is already issued.\n");
        return;
    }
    
    printf("Enter Member ID: ");
    scanf("%d", &member_id);
    
    // Find member
    int member_index = find_member_by_id(member_id);
    if (member_index == -1) {
        printf("\nError: Member not found.\n");
        return;
    }
    
    // Confirm
    printf("\nIssue '%s' to '%s'? (y/n): ",
           books[book_index].title,
           members[member_index].name);
    char confirm;
    clear_input_buffer();
    scanf("%c", &confirm);
    
    if (confirm != 'y' && confirm != 'Y') {
        printf("\nIssue cancelled.\n");
        return;
    }
    
    // Create transaction
    Transaction new_trans;
    new_trans.transaction_id = generate_transaction_id();
    new_trans.book_id = book_id;
    new_trans.member_id = member_id;
    get_current_date(new_trans.issue_date);
    strcpy(new_trans.return_date, "");  // Empty until returned
    new_trans.is_active = 1;
    
    transactions[transaction_count] = new_trans;
    transaction_count++;
    
    // Update book status
    books[book_index].is_available = 0;
    
    // Save changes
    save_books_to_file();
    save_transactions_to_file();
    
    printf("\n✓ Book issued successfully!\n");
    printf("Transaction ID: %d\n", new_trans.transaction_id);
    printf("Issue Date: %s\n", new_trans.issue_date);
}

void return_book() {
    int book_id;
    
    printf("\n--- Return Book ---\n");
    printf("Enter Book ID: ");
    scanf("%d", &book_id);
    
    // Find active transaction for this book
    int trans_index = -1;
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].book_id == book_id && transactions[i].is_active == 1) {
            trans_index = i;
            break;
        }
    }
    
    if (trans_index == -1) {
        printf("\nError: No active transaction found for this book.\n");
        return;
    }
    
    // Find book
    int book_index = find_book_by_id(book_id);
    
    // Confirm
    printf("\nReturn '%s'? (y/n): ", books[book_index].title);
    char confirm;
    clear_input_buffer();
    scanf("%c", &confirm);
    
    if (confirm != 'y' && confirm != 'Y') {
        printf("\nReturn cancelled.\n");
        return;
    }
    
    // Update transaction
    get_current_date(transactions[trans_index].return_date);
    transactions[trans_index].is_active = 0;
    
    // Update book status
    books[book_index].is_available = 1;
    
    // Save changes
    save_books_to_file();
    save_transactions_to_file();
    
    printf("\n✓ Book returned successfully!\n");
    printf("Issue Date: %s\n", transactions[trans_index].issue_date);
    printf("Return Date: %s\n", transactions[trans_index].return_date);
}

void display_active_transactions() {
    printf("\n========================================\n");
    printf("      ACTIVE TRANSACTIONS\n");
    printf("========================================\n");
    
    int active_count = 0;
    for (int i = 0; i < transaction_count; i++) {
        if (transactions[i].is_active == 1) {
            // Find book and member details
            int book_index = find_book_by_id(transactions[i].book_id);
            int member_index = find_member_by_id(transactions[i].member_id);
            
            printf("\nTransaction ID: %d\n", transactions[i].transaction_id);
            printf("Book: %s\n", books[book_index].title);
            printf("Borrowed by: %s\n", members[member_index].name);
            printf("Issue Date: %s\n", transactions[i].issue_date);
            printf("----------------------------------------\n");
            
            active_count++;
        }
    }
    
    if (active_count == 0) {
        printf("No active transactions.\n");
    }
    printf("========================================\n");
}

// ========================================
// MENU FUNCTIONS
// ========================================

void book_management_menu() {
    int choice;
    do {
        printf("\n========================================\n");
        printf("       BOOK MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Back to Main Menu\n");
        printf("========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_book();
                pause_screen();
                break;
            case 2:
                display_books();
                pause_screen();
                break;
            case 3:
                search_book();
                pause_screen();
                break;
            case 4:
                delete_book();
                pause_screen();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
}

void member_management_menu() {
    int choice;
    do {
        printf("\n========================================\n");
        printf("      MEMBER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add New Member\n");
        printf("2. Display All Members\n");
        printf("3. Back to Main Menu\n");
        printf("========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_member();
                pause_screen();
                break;
            case 2:
                display_members();
                pause_screen();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

void transaction_management_menu() {
    int choice;
    do {
        printf("\n========================================\n");
        printf("    TRANSACTION MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Issue Book\n");
        printf("2. Return Book\n");
        printf("3. Display Active Transactions\n");
        printf("4. Back to Main Menu\n");
        printf("========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                issue_book();
                pause_screen();
                break;
            case 2:
                return_book();
                pause_screen();
                break;
            case 3:
                display_active_transactions();
                pause_screen();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
}

// ========================================
// MAIN FUNCTION
// ========================================

int main() {
    // Load data from files at startup
    load_books_from_file();
    load_members_from_file();
    load_transactions_from_file();
    
    int choice;
    do {
        printf("\n========================================\n");
        printf("    LIBRARY MANAGEMENT SYSTEM\n");
        printf("========================================\n");
        printf("1. Book Management\n");
        printf("2. Member Management\n");
        printf("3. Transaction Management\n");
        printf("4. Exit\n");
        printf("========================================\n");
        printf("Books: %d | Members: %d | Active: ", book_count, member_count);
        
        // Count active transactions
        int active = 0;
        for (int i = 0; i < transaction_count; i++) {
            if (transactions[i].is_active) active++;
        }
        printf("%d\n", active);
        printf("========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                book_management_menu();
                break;
            case 2:
                member_management_menu();
                break;
            case 3:
                transaction_management_menu();
                break;
            case 4:
                printf("\nSaving data and exiting...\n");
                save_books_to_file();
                save_members_to_file();
                save_transactions_to_file();
                printf("Thank you for using Library Management System!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}