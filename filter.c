// done by Rohit
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"methods.h" // including header file that contains all the function prototypes 

#define MAX_BOOKS 100
#define MAX_BORROWERS 100


//global variables that keep track of the no.of filtered books in that respective filter function
extern int filter_title_num;
extern int filter_author_num;
extern int filter_ID_num;
extern int filter_year_num;
extern int filter_available_num;
extern int filter_publisher_num;
extern int filter_category_num;


void filter_by_borrower(borroweri Details[], book *b, int n) {// searches the borrower array for any borrowers that have borrowed the  respective book and prints their details
        int found = 0;
        for (int i = 0; i < n; i++){
        	// if a borrower has borrowed the book 
                if (strcmp(b->title,Details[i].Book_Name)==0) {
                // printing the borrower  details
		printf("%d %s %s%d%d %s %lu\n",Details[i].ID,Details[i].Name,Details[i].Batch,Details[i].joining_year,Details[i].RollNo,Details[i].Email,Details[i].Ph_No);
                found = 1;
                }

        }
        if (!found) { // prints the following message if no borrower is found
                printf("No borrowers found.\n"); 
        }
}

book* filter_by_title(book b[], char * title_keyword, int n) { // searches the book array for any books with the respective  keyword in their title field and prints their details
	book *temp;
	temp=malloc(sizeof(book)*n); // allocating memory for a temporary array	
	int found = 0;
	filter_title_num=0;
	int j=0;
	for (int i = 0; i < n; i++){
		if (strstr(b[i].title, title_keyword)) {
		// if a book title in the library contains the keyword
		temp[j]=b[i]; // adding that book to the temporary array
            	print_book_details(b[i]); // printing the details of that book 
		found = 1;
		filter_title_num++;
		j++;
        	}
	
	}
	if (!found) { // prints the following message if no books are found with that respective keyword
		printf("No books found.\n");
	}
	return temp; // returning the temporary array containing the books with the keyword in their title field
}

book* filter_by_author(book b[],char * author_keyword,int n){// searches the book array for any books with the respective  keyword in their author field and prints their details
	book *temp;
	temp=malloc(sizeof(book)*n); // allocating memory for a temporary array 
	int found=0;
	filter_author_num=0;
	int j=0;
	for(int i = 0;i<n;i++){
		// if a book author in the library contains the keyword 
        	if(strstr(b[i].author,author_keyword)) {
		temp[j]=b[i]; // adding that book to the temporary array
                print_book_details(b[i]); // printing the details of that book
		found=1;
		filter_author_num++;
		j++;
        	}
	}
	if(!found){// prints the following message if no books are found with that respective keyword
		printf("No books found.\n");
	}
	return temp; // returning the temporary array containing the books with the keyword in their author field
}
book* filter_by_ID(book b[],int ID,int n){// searches the book array for any books with the same ID as in their ID field and prints the details of that book 
        book *temp;
        temp=malloc(sizeof(book)); // allocating memory for a temporary array
        int found=0;
	filter_ID_num=0;
	int j=0;
        for(int i = 0;i<n;i++){
                if(ID == b[i].ID) {
		// if a book in the library has the same ID in their ID field 
                print_book_details(b[i]); // printing the details of that book
		temp[j]=b[i]; // adding that book to a temporary array
                found=1;
		filter_ID_num++;
		j++;
                }
        }
        if(!found){ // prints the following message if no books are found with the given ID
                printf("No books found.\n");
        }
	return temp; // returning the temporary array containing the book with the same ID in their ID field
}


book* filter_by_year(book b[],int year,int n){// searches the book array for any books with the same year as in their year field  and prints their details
	book *temp;
	temp=malloc(sizeof(book)*n); // allocating memory to a temporary array
	int found=0;
	filter_year_num=0;
	int j=0;
	for(int i = 0;i<n;i++){
        	if(year == b[i].year) {
		// if a book in the library has the same year in their year field 
		temp[j]=b[i]; // adding that book to the temporary array
                print_book_details(b[i]); // printing the details of that book
		found=1;
		filter_year_num++;
		j++;
        	}
	}
        if(!found){// prints the following message if no books are found with the given year
                printf("No books found.\n");
        }
        return temp; // returning the temporary array containing the books with the same year in their year field
}

book* filter_by_is_available(book b[],int n){// searches the book array for all the books that are available to be borrowed
	book *temp;
	temp=malloc(sizeof(book)*n); // allocating memory to a temporary array
	int found=0;
	filter_available_num=0;
	int j=0;
	for(int i = 0;i<n;i++){
        	if(b[i].available>0){ 
		// for all the books that are available to be borrowed
		temp[j]=b[i]; // adding those books to the temporary array
                print_book_details(b[i]); // printing the details of those books
		found=1;
		filter_available_num++;
		j++;
        	}
	}
        if(!found){// prints the following message if no books are available to be borrowed
                printf("No books found.\n");
        }
	return temp; // returning the temporary array containing all the books that are available to be borrowed
}

book* filter_by_publisher(book b[],char*publisher_name,int n){// searches the book array for any books with the same publisher as in their publisher field and prints their details
	book *temp;
	temp=malloc(sizeof(book)*n); // allocating memory to a temporary array 
	int found=0;
	filter_publisher_num=0;
	int j=0;
	for(int i = 0;i<n;i++){
        	if(strcmp(publisher_name,b[i].publisher)==0){
		// if a book in the library has the same publisher in their publisher field
			temp[j]=b[i]; // adding that book to the temporary array 
                	print_book_details(b[i]);// printing the details of that book
			found=1;
			filter_publisher_num++;
			j++;
        	}
	}
        if(!found){// prints the following message if no books are found with the given publisher
                printf("No books found.\n");
        }
	return temp;// returning the temporary array containing the book with the same publisher in their publisher field

}

book* filter_by_category(book b[],char*category,int n){// searches the book array for any books with the same category as in their category field and prints their details   
	book*temp;
	temp=malloc(sizeof(book)*n); // allocating memory to a temporary array
	int found=0;
	filter_category_num=0;
	int j=0;
	for(int i = 0;i<n;i++){
        	if(strcmp(category,b[i].category)==0){
		// if a book in the library has the same category in their category field
		temp[j]=b[i];// adding that book to the temporary array
                print_book_details(b[i]);// printing the details of that book
		found=1;
		filter_category_num++;
		j++;
        	}
	}
        if(!found){// prints the following message if no books are found with the given category
                printf("No books found.\n");
        }
	return temp; // returning the temporary array containing the books with the same category in their category field
}
