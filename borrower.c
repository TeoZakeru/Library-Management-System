// Done by koushik
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"methods.h" // including the header file that contains all the function prototypes

extern book b[100];// declaring an array of books from another file
extern borroweri Details[100];// declaring an array of borrowers from another file

int read_borrower(borroweri borrowers[]){ // reads borrower details from borrowers_details.txt file and stores them in the borrowers array
	FILE *fp = fopen("borrowers_details.txt", "r");// opening borrowers_details.txt file in read mode
	if (fp == NULL) {
	//printing the following if the file can't be opened
	printf("Error opening file");
	return 0;
	}
	int i = 0;//initialising a counter variable for counting the no.of borrowers in the file  
	while (fscanf(fp, "%d %s %s %d %d %lu %s %d %s", &borrowers[i].ID, borrowers[i].Name,borrowers[i].Batch,&borrowers[i].joining_year,&borrowers[i].RollNo,&borrowers[i].Ph_No,borrowers[i].Email,
	&borrowers[i].Book_ID, borrowers[i].Book_Name) == 9) {
	i++;//updating the counter variable
	}
	fclose(fp);// closing the file
	return i;// returning the no.of borrowers in the file
}

void add_borrower_write_borrower(borroweri new_borrower) {// adds a new borrower and writes the updated list of borrowers to the file 
	borroweri borrowers[MAX_BOOKS];// declaring an array of borrowers
	int n = read_borrower(borrowers);// reading the existing borrowers from the file and 'n' is the no.of of borrowers in the file
	int found = 0;
	for (int i = 0; i < n; i++) {
		if (borrowers[i].RollNo == new_borrower.RollNo && borrowers[i].Batch == new_borrower.Batch && borrowers[i].joining_year == new_borrower.joining_year && borrowers[i].Book_Name == new_borrower.Book_Name) {
		found = 1;
		
		return ;
		}
	}
	if (!found) {
		if (n >= MAX_BOOKS) {
		// printing the following if the maximum number of borrowers has been reached
		printf("Error: Maximum number of borrowers reached\n");
		return;
		}
	borrowers[n] = new_borrower; // adding the new borrower to the borrowers array
	n++;// updating the no.of borrowers
	}
	FILE *fp = fopen("borrowers_details.txt", "w");// opening the file borrowers_details.txt file in write mode
	for (int i = 0; i < n; i++) {
	// writing the updated version of borrowers to the file
	fprintf(fp, "%d %s %s %d %d %lu %s %d %s\n",
	borrowers[i].ID, borrowers[i].Name,borrowers[i].Batch, borrowers[i].joining_year,borrowers[i].RollNo,
	borrowers[i].Ph_No,borrowers[i].Email,borrowers[i].Book_ID,borrowers[i].Book_Name);
	}
	fclose(fp);//closing the file
}

void remove_borrower(char batch[],int year,int roll,char book_name[]){//removes an existing borrower from the borrowers array and writes the updated list of borrowers to the file
	borroweri borrowers[MAX_BOOKS];// defining a borrowers array 
	int n = read_borrower(borrowers); // reading the existing borrowers from the file and 'n' is the no.of of borrowers in the file
	int found = 0;
	for (int i = 0; i < n; i++) {
		// searches for the borrower to be removed based on their batch, year, and roll number and the name of the borrowed book
		if (strcmp(borrowers[i].Batch,batch)==0 && strcmp(borrowers[i].Book_Name,book_name)==0 && borrowers[i].RollNo == roll && borrowers[i].joining_year == year) {
			// ff found, it removes the borrower from the array
			found = 1;
			for(int j=i;j<n-1;j++){
			borrowers[j] = borrowers[j+1];
			}
			n--;
			break;
		}
	}
	if (found == 0) {
	printf("No borrower with Roll no %s%d%d borrowed a book name %s.\n", batch,year,roll,book_name);
	} 
	else {
		FILE *fp = fopen("borrowers_details.txt", "w");// opening the file borrowers_details.txt file in write mode
		if (fp == NULL) {
		printf("Error opening file");
		exit(0);
		}
		// writing the updated version of borrowers to the file
		for (int i = 0; i < n; i++) {
		fprintf(fp, "%d %s %s %d %d %lu %s %d %s\n",
		borrowers[i].ID, borrowers[i].Name,borrowers[i].Batch,borrowers[i].joining_year, borrowers[i].RollNo,
		borrowers[i].Ph_No,borrowers[i].Email, borrowers[i].Book_ID, borrowers[i].Book_Name);
		}
		fclose(fp);// closing the file
	}
}


void Lend_Return(char a[]){// used for lending or returning a book
	borroweri new_borrower;
	book books[MAX_BOOKS];//defining an array of books
        int n = read_books(books);
	borroweri borrowers[MAX_BOOKS];// defining an array of borrowers
	int yk= read_borrower(borrowers);
        if(strcmp(a,"Lend")==0){// if Lend :
		int count;
		// prompts the admin to enter the details of the borrower 
                do{
                printf("Student Name: ");
                scanf("%s",new_borrower.Name);
                count=0;
                for(int i=0;i<strlen(new_borrower.Name);i++){
                        if(isalpha((new_borrower.Name)[i])==0){// checking a condition that name should be only of alphabets
                                printf("Please enter correct characters\n");
                                count=1;
                                break;
                        }
                }

                }while(count);
		printf("Enter the Batch\n");
                printf("IMT for IMTech\nMT for MTECH\nDT for M.Sc\nPH for PHD\n");
                printf("Batch: ");
                scanf("%s",new_borrower.Batch);
		printf("year of joining: ");
		scanf("%d",&new_borrower.joining_year);
                printf("Last three digits of RollNo: ");
                scanf("%d",&new_borrower.RollNo);

		do{
                printf("Email: ");
                scanf("%s",new_borrower.Email);
                count=0;
                if(strstr(new_borrower.Email,"@gmail.com") || strstr(new_borrower.Email,"@iiitb.ac.in")){ // checking a condition that mail id should either contain @gmail.com or @iiitb.ac.in
                        break;
                }
                else{
                        count=1;
                        printf("Invalid Email Address\n");
                }
                }while(count);

                printf("Ph.No: ");
                scanf("%lu",&new_borrower.Ph_No);
                printf("Book_ID: ");
                scanf("%d",&new_borrower.Book_ID);
		new_borrower.ID=yk+1;
                printf("Book_Name: ");
                scanf("%s",new_borrower.Book_Name);
		int z=1;
                lends_book(new_borrower.ID,z); // lending a book 
		add_borrower_write_borrower(new_borrower);// updating the new borrower details to the file 
		Date();// calling Date function
        }
        else if(strcmp(a,"Return")==0){// if Return:
        	char batch[10];
                int RollNo,ID,year;
                int c=0;
                char Book_Name[100];
		// prompts the admin to enter the details of the borrower
                printf("Enter the Batch\n");
                printf("IMT for IMTech\nMT for MTECH\nDT for M.Sc\nPH for PHD\n");
                printf("Batch: ");
                scanf("%s",batch);
                printf("year of joining : ");
		scanf("%d",&year);
                printf("Last three digits of RollNo: ");
                scanf("%d",&RollNo);
		printf("Book_Name: ");
		scanf("%s",Book_Name);
                printf("Book_ID: ");
                scanf("%d",&ID);
		book *temp;
                temp=malloc(sizeof(book));
                book temp2;
                for(int i=0;i<yk;i++){
		//if the borrower is found in the borrowers array with the respective book borrowed 
                        if(RollNo==borrowers[i].RollNo && strcmp(Book_Name,borrowers[i].Book_Name)==0){
				temp=filter_by_title(b,Book_Name,n);
                                temp2=*(temp);
                                add_book(temp2); // updates the no.of copies of the returned book
				remove_borrower(batch,year,RollNo,Book_Name);// removes the borrower from the borrowers list
                                printf("Book returned successfully\n");
                                c=1;
                                break;
                        }
                }
                if(c==0)//prints the following if the info of the borrower is entered wrong 
                        printf("Wrong info entered\n");
        }
  
}
