// Done by Nishith and Anirudh
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"methods.h" // including header file that contains all the function prototypes

void sort_by_id(book a[],int n){// sorts the books by ID in ascending order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
	for(int i=0;i<=n-2;i++){
		for(int j=0;j<n-i-1;j++){
			 if(t[j].ID > t[j+1].ID){
				x = t[j];
				t[j] = t[j+1];
				t[j+1] = x;
				
			 }
		}
	}
	print_book_array(t,n); //printing the sorted books
			
	
}
void sort_reverse_by_id(book a[],int n){ //sorts the books by ID in descending order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
	for(int i=0;i<=n-2;i++){
		for(int j=0;j<n-i-1;j++){
			 if(t[j].ID > t[j+1].ID){
				x = t[j];
				t[j] = t[j+1];
				t[j+1] = x;
				
			 }
		}
	}
	reverse_array(t,n);     // reversing the sorting order
	print_book_array(t,n);	// printing the sorted books
}

void sort_by_title(book *a,int n){//sorts the books by title in ascending alphabetical order using the bubble sort algorithm
	book *t;
	t=malloc(sizeof(book)*n);
	t=a;
	book x;
	int count=0;
	for (int i=0;i<=n-2;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].title,t[j+1].title)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
				count++;
			}
		}
	}
	print_book_array(t,n); // printing the sorted books
	if(count ==0)
	return;
	
}
void sort_reverse_by_title(book *a,int n){//sorts the books by title in descending alphabetical order using the bubble sort algorithm
	book *t;
	t=malloc(sizeof(book)*n);
	t=a;
	book x;
	int count=0;
	for (int i=0;i<=n-2;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].title,t[j+1].title)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
				count++;
			}
		}
	}
	reverse_array(t,n);// reversing the sorting order
	print_book_array(t,n);//prints the sorted books
	if(count ==0)
	return;
}	

void sort_by_category(book a[],int n){//sorts the books by category in ascending alphabetical order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
	for (int i=0;i<=n-2;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].category, t[j+1].category)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	print_book_array(t,n);//prints the sorted books
}
void sort_reverse_by_category(book a[],int n){//sorts the books by category in descending alphabetical order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
	for (int i=0;i<=n-2;i++){
		for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].category, t[j+1].category)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	reverse_array(t,n);//reversing the sorting order
	print_book_array(t,n);//prints the sorted books
}
void sort_by_author(book a[],int n){//sorts the books by author in ascending alphabetical order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
        for (int i=0;i<=n-2;i++){
        	for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].author, t[j+1].author)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	print_book_array(t,n);// prints the sorted books
	
}           
void sort_reverse_by_author(book a[],int n){//sorts the books by author in descending alphabetical order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
        for (int i=0;i<=n-2;i++){
        	for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].author, t[j+1].author)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	reverse_array(t,n); // reversing the sorting order
	print_book_array(t,n);// prints the sorted books
}  
       
void sort_by_publisher(book a[],int n){//sorts the books by publisher in ascending alphabetical order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
        for (int i=0;i<=n-2;i++){
        	for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].publisher, t[j+1].publisher)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	print_book_array(t,n);//prints the sorted books
	
} 

void sort_reverse_by_publisher(book a[],int n){//sorts the books by publisher in descending alphabetical order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
        for (int i=0;i<=n-2;i++){
        	for(int j=0;j<n-i-1;j++){
			if(strcmp(t[j].publisher, t[j+1].publisher)>0){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	reverse_array(t,n); // reversing the sorting order
	print_book_array(t,n);	//prints the sorted books
}
      
void sort_by_year(book a[],int n){// sorts the books by year  in ascending order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
        for (int i=0;i<=n-2;i++){
        	for(int j=0;j<n-i-1;j++){
			if(t[j].year > t[j+1].year){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	print_book_array(t,n);//prints the sorted books
	
}


void sort_reverse_by_year(book a[],int n){// sorts the books by year in descending order using the bubble sort algorithm
	book *t;
        t=malloc(sizeof(book)*n);
        t=a;
        book x;
        for (int i=0;i<=n-2;i++){
        	for(int j=0;j<n-i-1;j++){
			if(t[j].year > t[j+1].year){
				x=t[j];
				t[j] = t[j+1];
				t[j+1] = x;
			}
		}
	}
	reverse_array(t,n); // reversing the sorting order
	print_book_array(t,n);// prints the sorted array
	
}
