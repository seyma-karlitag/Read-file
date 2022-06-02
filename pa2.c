/*I came up with two ideas as an algorithm, and I made this choice thinking that the algorithm I wrote was clearer and more efficient.*/
#include <stdio.h>

int main ()
 {
 
 
 FILE *fptr;               
 fptr  = fopen ("input.txt", "r+");  /*file opening operations are performed*/

 int y;
 int array[100],array_temp[100]={0};
 int i=0,j,k;
 int flag;
 int temp_0,temp_1;
 
 if(fptr==NULL)
 {
    printf("error");
 }
 else
 
 {        
           
           fscanf(fptr,"%d",&y); /*after the file was successfully opened, I read the first count and saved the sequence*/
           array[i]=y; 
           
       while(!feof(fptr))
        {
           flag=1;
           fscanf(fptr,"%d",&y);
           for(j=0; j<i+1; j++)
           {
               if(array[j]==y)	flag=0; /*if the new number I have read is in the current sequence, I continue reading the new number without saving it again*/
           }
           if(flag!=0){  /*I keep reading my numbers and keep saving the sequence as long as I don't read the same number as before*/
           	   i++;
           	   array[i]=y;
           }
           
           
        }
        
      for(j=0;j<=i;j++)
      {
        fseek(fptr,0,SEEK_SET);
        while(fscanf(fptr,"%d",&y)!=EOF)
        {
           if(array[j]==y) array_temp[j]++; /*i find out how many times the numbers I have stored throughout the file are repeated*/
          
        }
       
      }       
  
 }  
   fclose(fptr);  /*the file is closed*/
   
 for(j=0;j<i+1;j++)
 {
       for(k=0;k<i+1;k++)
       {
          if(array_temp[k]>array_temp[j])
          {
              temp_0=array[j];   /*I then perform the sort operation in such a way that it increases from the lowest duplicate number with the comparison operation*/
              temp_1=array_temp[j];
              array[j]=array[k];
              array_temp[j]=array_temp[k];
              array[k]=temp_0;
              array_temp[k]=temp_1;
              
       
          }
         else  if(array_temp[k]==array_temp[j] && array[k]>array[j])
         { 
             temp_0=array[j];
             array[j]=array[k]; /*if the repeating numbers are equal,I take the smallest number at the beginning*/
             array[k]=temp_0;
         }
       }
       
   }
   
  fptr  = fopen ("output.txt", "w"); /*the file is opened and it is determined whether the file is opened or not*/
   if(fptr==NULL)
   {
    printf("error"); /*if the file cannot be opened,the error code is written to the screen*/
   }
 
   else
   {
      for(j=0;j<i+1;j++)
      fprintf(fptr,"%d : %d \n",array[j], array_temp[j]);  /*otherwise, write operations will be performed to our file*/
   }
     
    fclose(fptr);    /*the file is closed*/
 
 return 0;
 
 }
