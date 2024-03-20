LIBRARY MANAGEMENT SYSTEM 

This program is a library management system that allows users to search for books in a library and also allows administrators to manage the books and borrowers.

Requirements :

This program requires the following libraries:

    1.stdio.h
    2.string.h
    3.stdlib.h
    4.ctype.h

How to compile :
    To compile the program use the following command : 
    make myprogram
    To run the program use the following command:
    ./myprogram


How To Use :

Choose whether you are an Admin or a Student.

If you choose Student, you can search for books by:

    1.ID
    2.Title
    3.Author
    4.Year of Publication
    5.Availability
    6.Publisher
    7.Category
    
And then you can choose to filter again the already filtered books by selecting the above filter functions or you can sort the filtered books by :

    1.Title
    2.Category
    3.Author
    4.Publisher
    5.Year of publication
And then you can choose to sort them in ascending or descending order   
 
If you choose Admin, enter the username and password.
Once you have logged in as an admin by entering correct password, you can:

    1.Lend a book
    2.Return a book
    3.Search for books similar lo Student and can also view the borrowers of a book if one book is filtered 
    4.Save the changes made

File Structure  :
    1. 'methods.h' contains all the function prototypes used in the program 
    2. 'sort.c'  contains the implementations of the sort functions used in the program 
    3. 'filter.c' contains the implementations of all the filter functions used in the program 
    4. 'date.c' contains the implementation of the Date function used in the program 
    5. 'book.c' contains the implementaions of the operations performed on managing books
    6. 'borrower.c' contains the implementations of the operations performed on managing borrowers
    7. 'TXT.txt' is the file that contains the data of all the books in the library
    8. 'borrowers_details.txt' is the file that contains data of all the borrowers
    9. 'main.c' is the main file of the program that contains the mian() function and call the other functions
