typedef struct Borrower{
        char Name[100];
        int RollNo;
        char Batch[10];
	int joining_year;
        char Email[100];
        long unsigned int Ph_No;
        int ID;
	int Book_ID;
        char Book_Name[100];
}borroweri;
typedef struct book{	
	char title[50];
	char author[50];
	char publisher[50];
	int ID;
	int available;
	char category[20];
	int no_of_borrowers;
	borroweri b[100];
	int year;
	
}book;

#define MAX_BOOKS 100
#define MAX_BORROWERS 100


void print_book_details(book b);
void print_book_array(book b[], int n);
int read_books(book books[]);
void write_books(const book books[], int n);
void add_book(book new_book);
void lends_book(int I_d,int copies_to_remove);
void copyfn(book a[],book t[],int n);
void cpyfn(book a[],book *b,int n);
void copy(book *a,book b[],int n);
void reverse_array(book a[],int n);
int read_borrower(borroweri borrowers[]);
void add_borrower_write_borrower(borroweri new_borrower);
void remove_borrower(char*,int,int,char*);
void Lend_Return(char a[]);
void Date();
void filter_by_borrower(borroweri Details[], book *b, int n);
book* filter_by_title(book b[], char * title_keyword, int n);
book* filter_by_author(book b[],char * author_keyword,int n);
book* filter_by_ID(book b[],int ID,int n);
book* filter_by_year(book b[],int year,int n);
book* filter_by_is_available(book b[],int n);
book* filter_by_publisher(book b[],char*publisher_name,int n);
book* filter_by_category(book b[],char*category,int n);
void sort_by_id(book a[],int n);
void sort_reverse_by_id(book a[],int n);
void sort_by_title(book *a,int n);
void sort_reverse_by_title(book *a,int n);
void sort_by_category(book a[],int n);
void sort_reverse_by_category(book a[],int n);
void sort_by_author(book a[],int n);
void sort_reverse_by_author(book a[],int n);
void sort_by_publisher(book a[],int n);
void sort_reverse_by_publisher(book a[],int n);       
void sort_by_year(book a[],int n);
void sort_reverse_by_year(book a[],int n);
