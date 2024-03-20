//Done by nishith and anirudh
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"methods.h" // including the header file that contains all the function prototypes

#define MAX_BOOKS 100
#define MAX_BORROWERS 100

// initialising global variables
int filter_title_num;
int filter_author_num;
int filter_ID_num;
int filter_year_num;
int filter_available_num;
int filter_publisher_num;
int filter_category_num;
book b[100];
borroweri Details[100];

int main(){
	// initialising local variables
	int function;
	int order;
	int sort_function;
	char *title_keyword;
	char *author_keyword;
	char *category;
	char *publisher;
	char *response;
	response=malloc(sizeof(char)*10);
	int year;
	int ID;
	int size;
	book *filtered_books;
	int num=read_books(b); // reads the books from the file and returns the no.of books
	int num_borrow=read_borrower(Details); //reads the borrowers from the file and returns the no.of borrowers
	filtered_books=malloc(sizeof(book)*num);
	cpyfn(b,filtered_books,num);
	char s[10],t[10],UserName[100],Password[100];
	char OPassword[10] = "123";
	// get user input to determine if the user is admin or student 
	printf("Admin or Student ?\n");
	scanf("%s",t);
	if(strcmp(t,"Admin")==0){// if the user is Admin
		int func=0;
		int count = 0;
		do{if(count == 5){ // exiting the program if the user inputs wrong password
			exit(0);
		}
		printf("UserName: ");
		scanf("%s",UserName);
		printf("Password: ");
		scanf("%s",Password);
		// allowing normal functioning of program if the password is correct
		if(strcmp(Password,OPassword)==0){
			do{
        		printf("Lend or Return or Search_Books or Save_Changes\n");
        		scanf("%s",s);
			// if the admin wants to search the borrowers of books
			if(strcmp(s,"Search_Books")==0){
	do{
	// displaying the filter options
	printf("Select the filter function you want to  choose\n");
printf("0 for exit \n1 for filter_by_ID \n2 for fliter_by_title \n3 for filter_by_author \n4 for filter_by_year \n5 for filter_by_is_available\n6 for filter_by_publisher\n7 for filter_by_category\n");
	// taking user input for the filter function
	scanf("%d",&function);
	// filtering the array of books based on the user input for respective filter function
	switch(function){
	case(0):
			break;
	case(1):	printf("Enter the ID of the book : ");
			scanf("%d",&ID);
			filtered_books=filter_by_ID(filtered_books,ID,num);
			size=filter_ID_num;
			break;
	
	case(2):	printf("Enter a keyword of the title you want to search: ");
			title_keyword=malloc(sizeof(char)*50);
			scanf("%s",title_keyword);
                        filtered_books=filter_by_title(filtered_books ,title_keyword,num);
			size=filter_title_num;
			break;

	case(3):	printf("Enter a keyword of the author you want to search: ");
			author_keyword=malloc(sizeof(char)*50);
			scanf("%s",author_keyword);
                        filtered_books=filter_by_author( filtered_books,author_keyword,num);
			size=filter_author_num;
			break;
	case(4):	printf("Enter the year of publication: ");
			scanf("%d",&year);
			filtered_books=filter_by_year(filtered_books,year,num);
			size=filter_year_num;
			break;
	case(5):	filtered_books=filter_by_is_available(filtered_books,num);
			size=filter_available_num;
			break;

	case(6):	publisher=malloc(sizeof(char)*50);
			printf("Enter the publisher you want to search : ");
			scanf("%s",publisher);
			filtered_books=filter_by_publisher(filtered_books,publisher,num);
			size=filter_publisher_num;
			break;
	case(7):	category=malloc(sizeof(char)*50);
			printf("Enter the category you want to search for : ");
			scanf("%s",category);
			filtered_books=filter_by_category(filtered_books,category,num);
			size=filter_category_num;
			break;

	default:	printf("incorrect function entered");
	
	}
	if(size >1){
		// prompting the user if he wants to filter the books agin or sort them
		printf("do you want to filter again or sort the filtered books\n");
		scanf("%s",response);
		if(strcmp(response,"filter")==0){ // filtering the books of the previously filtered books 
			continue;
		}
		if(strcmp(response,"sort")==0){// sorting the filtered books
			// displaying the sort options
			printf("1 for sort by title \n2 for sort by category \n3 for sort by Author \n4 for sort by publisher \n5 for sort by year \n");
			// taking user input for the sort function
			scanf("%d",&sort_function);
			//  sorting the filtered array of books based on the user input for respective sort function
			switch(sort_function){
			case(1):	sort_by_title(filtered_books,size);
					break;
			case(2):	sort_by_category(filtered_books,size);
					break;
			case(3):	sort_by_author(filtered_books,size);
					break;
			case(4):	sort_by_publisher(filtered_books,size);
					break;
			case(5):	sort_by_year(filtered_books,size);
					break;
			default:	printf("incorrect function entered");
			}
			break;
		}

	}
	else if (size==1){
		filter_by_borrower(Details,filtered_books,num_borrow);
		exit(0);
	}
	}while(function!=0);

		}
			else{
			// calling Lend_Return function
        		Lend_Return(s);
        		}
			}while(strcmp(s,"Save_Changes")!=0); 
			func=1;
			count = 0;
		}
        	
		else{
			count++;
			printf("Wrong Username or Password\n");
			continue;
		}
		}while(func==0);
	}
    
        else if(strcmp(t,"Student")==0){ // if the user is a Student 
	do{
	// displaying the filter options
	printf("Select the filter function you want to  choose\n");
        printf("0 for exit \n1 for filter_by_ID \n2 for fliter_by_title \n3 for filter_by_author \n4 for filter_by_year \n5 for filter_by_is_available\n6 for filter_by_publisher\n7 for filter_by_category\n");
	// taking user input for the filter function	
	scanf("%d",&function);
	// filtering the array of books based on the user input for respective filter function
	switch(function){
	case(0):
			break;
	case(1):	printf("Enter the ID of the book: ");
			scanf("%d",&ID);
			filtered_books=filter_by_ID(filtered_books,ID,num);
			size=filter_ID_num;
			
			break;
	
	case(2):	title_keyword=malloc(sizeof(char)*50);
			printf("Enter a keyword of the title you want to search: ");
			scanf("%s",title_keyword);
                        filtered_books=filter_by_title(filtered_books ,title_keyword,num);
			size=filter_title_num;
			break;

	case(3):	author_keyword=malloc(sizeof(char)*50);
			printf("Enter a keyword of the author you want to search: ");
			scanf("%s",author_keyword);
                        filtered_books=filter_by_author( filtered_books,author_keyword,num);
			size=filter_author_num;
			break;
	case(4):	printf("Enter the year of publication: ");
			scanf("%d",&year);
			filtered_books=filter_by_year(filtered_books,year,num);
			size=filter_year_num;
			break;
	case(5):	filtered_books=filter_by_is_available(filtered_books,num);
			size=filter_available_num;
			break;

	case(6):	publisher=malloc(sizeof(char)*50);
			printf("Enter the publisher you want to search: ");
			scanf("%s",publisher);
			filtered_books=filter_by_publisher(filtered_books,publisher,num);
			size=filter_publisher_num;
			break;
	case(7):	category=malloc(sizeof(char)*50);
			printf("Enter the category you want to search: ");
			scanf("%s",category);
			filtered_books=filter_by_category(filtered_books,category,num);
			size=filter_category_num;
			break;

	default:	printf("incorrect function entered");
	
	}
	if(size >1){
		// prompting the user if he wants to filter the books agin or sort them
		printf("do you want to filter again or sort the filtered books\n");
		scanf("%s",response);
		if(strcmp(response,"filter")==0){// filtering the books of the previously filtered books
			continue;
		}
		if(strcmp(response,"sort")==0){// sorting the filtered books
			// displaying the sort options
			printf("1 for sort by title \n2 for sort by category \n3 for sort by Author \n4 for sort by publisher \n5 for sort by year \n");
			// taking user input for the sort function
			scanf("%d",&sort_function);
			//  sorting the filtered array of books based on the user input for respective sort function
			switch(sort_function){
			// in each sort function selected by the user promting the user for sort by ascending or sort by desencding and calling that respective sort function
			case(1):	printf("Enter 1 for sort by ascending \n 2 for sort by descending\n");
					scanf("%d",&order);
					if(order==1)
					sort_by_title(filtered_books,size);
					else if(order==2)
					sort_reverse_by_title(filtered_books,size);
					break;
			case(2):	printf("1 for sort by ascending\n2 for sort by descending\n");
                                        scanf("%d",&order);
                                        if(order==1)
					sort_by_category(filtered_books,size);
					else if(order==2)
                                        sort_reverse_by_category(filtered_books,size);
					break;
			case(3):	printf("1 for sort by ascending\n2 for sort by descending\n");
                                        scanf("%d",&order);
                                        if(order==1)
					sort_by_author(filtered_books,size);
					else if(order==2)
                                        sort_reverse_by_author(filtered_books,size);
					break;
			case(4):	printf("1 for sort by ascending\n2 for sort by descending\n");
                                        scanf("%d",&order);
                                        if(order==1)
					sort_by_publisher(filtered_books,size);
					else if(order==2)
                                        sort_reverse_by_publisher(filtered_books,size);
					break;
			case(5):	printf("1 for sort by ascending\n2 for sort by descending\n");
                                        scanf("%d",&order);
                                        if(order==1){
					sort_by_year(filtered_books,size);
					}
					else if(order==2){
                                        sort_reverse_by_year(filtered_books,size);
					}
					break;
			default:	printf("incorrect function entered");
			}
			break;
		}
	}
	else{

		exit(0);
	}
	}while(function!=0);

	        	
	}
}



