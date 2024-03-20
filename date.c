// Done by Adarsha Reddy
#include<stdio.h>//including all library header files
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"methods.h"//including the methods.h heade file

void Date(){//Date function begins
	int rdate=0,rmonth=0,ryear=0;//declaring and initializing variables
	int bdate=0,bmonth=0,byear=0;
    printf("Date: ");//printing the prompt asking for date
    scanf("%d-%d-%d",&bdate,&bmonth,&byear);//taking use input 
    ryear = byear;//assigning the default value for ryear
    if(bmonth==1||bmonth==3||bmonth==5||bmonth==7||bmonth==8||bmonth==10)//checking for months with 31 days
    {switch(bdate)//switch case begins
	    {case 1:
	     case 2:
	     case 3:
	     case 4:
	     case 5:
	     case 6:
	     case 7:
	     case 8:
	     case 9:
	     case 10:
	     case 11:
	     case 12:
	     case 13:
	     case 14:
	     case 15:
	     case 16:
	     case 17:
	     case 18:
	     case 19:
	     case 20:
	     case 21:
	     case 22:
	     case 23://cases where the month doesn't change
	     case 24: rdate = bdate+7;
		      rmonth = bmonth;
		      break;
	     case 25: rdate = 1;
		      rmonth = bmonth+1;//cases where the month changes
		      break;
	     case 26: rdate = 2;
                      rmonth = bmonth+1;
                      break;
	     case 27: rdate = 3;
                      rmonth = bmonth+1;
                      break;
	     case 28: rdate = 4;
                      rmonth = bmonth+1;
                      break;
	     case 29: rdate = 5;
                      rmonth = bmonth+1;
                      break;
	     case 30: rdate = 6;
                      rmonth = bmonth+1;
                      break;
	     case 31: rdate = 7;
                      rmonth = bmonth+1;
                      break;
	    }
    }
    else if(bmonth==12)//checking for December where the year may change
    {switch(bdate)//switch case begins
    	    {case 1:
	     case 2:
	     case 3:
	     case 4:
	     case 5:
	     case 6:
	     case 7:
	     case 8:
	     case 9:
	     case 10:
	     case 11:
	     case 12:
	     case 13:
	     case 14:
	     case 15:
	     case 16:
	     case 17:
	     case 18:
	     case 19:
	     case 20:
	     case 21:
	     case 22:
	     case 23://cases where the month and year doesn't change
	     case 24: rdate = bdate+7;
		      rmonth = bmonth;
		      break;
	     case 25: rdate = 1;
		      rmonth = 1;
		      ryear = byear+1;//cases where the month and year changes
		      break;
	     case 26: rdate = 2;
                      rmonth = 1;
		      ryear = byear+1;
                      break;
	     case 27: rdate = 3;
                      rmonth = 1;
                      ryear = byear+1;
                      break;
	     case 28: rdate = 4;
                      rmonth = 1;
                      ryear = byear+1;
                      break;
	     case 29: rdate = 5;
                      rmonth = 1;
                      ryear = byear+1;
                      break;
	     case 30: rdate = 6;
                      rmonth = 1;
                      ryear = byear+1;
                      break;
	     case 31: rdate = 7;
                      rmonth = 1;
                      ryear = byear+1;
                      break;

    }
    }
	    else if(bmonth==4||bmonth==6||bmonth==9||bmonth==11)//checking for months with 30 days
    {switch(bdate)//switch case begins
	    {case 1:
	     case 2:
	     case 3:
	     case 4:
	     case 5:
	     case 6:
	     case 7:
	     case 8:
	     case 9:
	     case 10:
	     case 11:
	     case 12:
	     case 13:
	     case 14:
	     case 15:
	     case 16:
	     case 17:
	     case 18:
	     case 19:
	     case 20:
	     case 21:
	     case 22://cases where the month doesn't change
	     case 23: rdate = bdate+7;
		      rmonth = bmonth;
		      break;
	     case 24: rdate = 1;
		      rmonth = bmonth+1;//cases where the month changes
		      break;
	     case 25: rdate = 2;
                      rmonth = bmonth+1;
                      break;
	     case 26: rdate = 3;
                      rmonth = bmonth+1;
                      break;
	     case 27: rdate = 4;
                      rmonth = bmonth+1;
                      break;
	     case 28: rdate = 5;
                      rmonth = bmonth+1;
                      break;
	     case 29: rdate = 6;
                      rmonth = bmonth+1;
                      break;
	     case 30: rdate = 7;
                      rmonth = bmonth+1;
                      break;
	    }
    }
else if(bmonth==2)//checking for February which has 28 or 29 days depending on the year
{

	   if(ryear%4!=0||ryear%100==0)//checking for leap year
	   {
	    switch(bdate)//switch case begins
	    {case 1:
	     case 2:
	     case 3:
	     case 4:
	     case 5:
	     case 6:
	     case 7:
	     case 8:
	     case 9:
	     case 10:
	     case 11:
	     case 12:
	     case 13:
	     case 14:
	     case 15:
	     case 16:
	     case 17:
	     case 18:
	     case 19:
	     case 20://cases where the month doesn't change
	     case 21: rdate = bdate+7;
		      rmonth = bmonth;
		      break;
	     case 22: rdate = 1;
		      rmonth = bmonth+1;//cases where the month changes
		      break;
	     case 23: rdate = 2;
                      rmonth = bmonth+1;
                      break;
	     case 24: rdate = 3;
                      rmonth = bmonth+1;
                      break;
	     case 25: rdate = 4;
                      rmonth = bmonth+1;
                      break;
	     case 26: rdate = 5;
                      rmonth = bmonth+1;
                      break;
	     case 27: rdate = 6;
                      rmonth = bmonth+1;
                      break;
	     case 28: rdate = 7;
                      rmonth = bmonth+1;
                      break;
	    
	    }
	   }
	   else if(ryear%4==0||ryear%400==0)//checking for leap year
	   { switch(bdate)//switch case begins
	    {case 1:
	     case 2:
	     case 3:
	     case 4:
	     case 5:
	     case 6:
	     case 7:
	     case 8:
	     case 9:
	     case 10:
	     case 11:
	     case 12:
	     case 13:
	     case 14:
	     case 15:
	     case 16:
	     case 17:
	     case 18:
	     case 19:
	     case 20:
	     case 21://cases where the month doesn't change
	     case 22: rdate = bdate+7;
		      rmonth = bmonth;//cases where the month changes
		      break;
	     case 23: rdate = 1;
		      rmonth = bmonth+1;
		      break;
	     case 24: rdate = 2;
                      rmonth = bmonth+1;
                      break;
	     case 25: rdate = 3;
                      rmonth = bmonth+1;
                      break;
	     case 26: rdate = 4;
                      rmonth = bmonth+1;
                      break;
	     case 27: rdate = 5;
                      rmonth = bmonth+1;
                      break;
	     case 28: rdate = 6;
                      rmonth = bmonth+1;
                      break;
	     case 29: rdate = 7;
                      rmonth = bmonth+1;
                      break;
	    
	    }
	   }
    }
    printf("Lent Sucessfully\n");//printing message
    printf("Please Return by %d-%02d-%02d \n",rdate,rmonth,ryear); //printing date
}
