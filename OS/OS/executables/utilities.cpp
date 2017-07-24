#include <fcntl.h> 
#include <io.h> 
#include <sys\stat.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <conio.h>
using std::cout;

char *pathname = "e:\\4gbupdate\\cpp\\utilities\\debug\\temp.dat"; 

void main() 
{   
   int result; 

   result = _chmod (pathname, S_IREAD|S_IWRITE &_A_RDONLY);


   if (result == 0) 
      printf ("Permission on file %s changed\n", 
		pathname); 
   else 
      perror("Can't change file"); 

// Now to rename a file

   char oldn[_MAX_PATH], newn[_MAX_PATH];
 

   cout << "Enter the old filename: ";
   gets (oldn); 

   cout << "Enter the new filename: ";
   gets (newn); 

   result = rename (oldn, newn); 

   if (result == 0)
      cout << "File successfully renamed.\n"; 
   else
      perror("Unable to rename file"); 

   getch();

} 
