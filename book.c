// Done by Lohitaksh
// The books in the input file are written by Adarsha reddy
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"methods.h" // including header file that contains all the function prototypes


void print_book_details(book b){ // prints the details of a book
	printf("%d %s %s %s %s %d %d\n",b.ID,b.title,b.author,b.category,b.publisher,b.year,b.available);
}

void print_book_array(book b[], int n){// prints the details of all the books in the array 
        for (int i=0;i<n;i++)
                print_book_details(b[i]);
}


int read_books(book books[]) {// reads the book details from TXT.txt file and stores them in the books array 
    FILE *fp = fopen("TXT.txt", "r"); // opening the TXT.txt file in read mode
    if (fp == NULL) { // printing the following message if the file could not be opened
        printf("Error opening file");
        exit(0);
    }
    int i = 0;
    while (fscanf(fp, "%d %s %s %s %s %d %d",&books[i].ID, books[i].title, books[i].author, books[i].category,books[i].publisher, &books[i].year, &books[i].available) == 7) {
        i++;
    }
    fclose(fp);
    return i; // return the no.of books in the file
}


void write_books(const book books[], int n) { // writes the  details of the books in the books array to TXT.txt file
    FILE *fp = fopen("TXT.txt", "w"); // opening TXT.txt file in write mode
    if (fp == NULL) { // printing the following message if the file could not be opened
        printf("Error opening file");
        exit(0);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %s %s %s %d %d\n",
            books[i].ID, books[i].title, books[i].author, books[i].category,books[i].publisher, books[i].year, books[i].available);
    }
    fclose(fp);
}

void add_book(book new_book) {//  if the book already exists in the library ,it's available copies are updated, else it adds the new book to the library
    book books[MAX_BOOKS];
    int n = read_books(books); // reading the existing books in the library
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (books[i].ID == new_book.ID) {
            books[i].available = books[i].available+new_book.available; //  updating the available copies if the book already exists
            found = 1;
            break;
        }
    }
    if (!found) {
        if (n >= MAX_BOOKS) {
	    // printing the following if the maximum number of books has been reached.
            printf("Error: Maximum number of books reached\n");
            return;
        }
        books[n] = new_book; // adding the new book to the library
        n++;
    }
    write_books(books, n); // writing the updated version of books to the library
}

void lends_book(int I_d,int copies_to_remove){ // function to lend a book from library
    book books[MAX_BOOKS];
    int n = read_books(books); // reading the existing books in the library
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (books[i].ID == I_d) {
	    found=1;
            if(books[i].available >= copies_to_remove){ // updates the available copies of the book with the given ID by subtracting the number of copies to remove from the available copies
            	books[i].available = books[i].available-copies_to_remove;
            }
            else if(books[i].available < copies_to_remove){
		// prints the following if the  no.of copies requested is greater than the available copies
                printf("incorrect copies to remove entered\n");
            }
            break;
        }
    }
    if (!found) { // prints the following if there is no book with the given ID
        printf("incorrect ID entered");
        return;
    }
    write_books(books, n);

}


void copyfn(book a[],book t[],int n)//used to copy contents of one array to another 
{for (int i = 0;i<=n-1;i++)
                {t[i] = a[i];
                }
}
void cpyfn(book a[],book *b,int n)//used to copy contents of an array to contents pointed by a pointer
{for (int i = 0;i<=n-1;i++)
                {*(b+i) = a[i];
                }
}
void copy(book *a,book b[],int n){//used to copy contents pointed by  a pointer to another array
	for (int i = 0;i<=n-1;i++){
                b[i] = *(a+i);
 	} 
}
void reverse_array(book a[],int n){ // reverses the order of the array
	book *t;
	t=malloc(sizeof(book)*n);
	t=a;
	book x;
	for (int i=0;i<n/2;i++){
		x= t[i];
		t[i] = t[n-1-i];
		a[n-1-i] = x;
	}
}
