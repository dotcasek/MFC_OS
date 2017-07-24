/* This program shows you how send output to a network printer
 * at BHCC.  It uses special instructions called PCL which
 * stands for Printer Command Language.  These instructions
 * are written using hexadecimal escape sequences as well
 * as #define preprocessor directives.
 * Hold on to this code; you will probably not find it
 * elsewhere.  Also make note of the fact that the first
 * instruction will not work at home.  It depends on how
 * your printer is configured.
 *
 * Written by Arland J. Richmond
 *
 * Date Written:  12 January, 2011
 */


#include <iostream>
#include <fstream>
using namespace std;
#include <conio.h>

#define COMPRESS "\x1b(s16.5H"
#define LANDSCAPE "\x1b&l1O"
#define PORTRAIT "\x1b&l0O"

int main()
{
	
	ofstream printer("\\\\cts-fp.bhcc.dom\\D119");
	if(printer)
	{
    printer << LANDSCAPE << "Hello, World!";
	printer <<PORTRAIT << "Hello, world!" << endl;
	printer << COMPRESS << "Hello, world!" << endl;
	printer << '\f';   //force feed gaurentees last page will be ejected
	printer.close();	//close the printer flushes a buffer regardless whats in the buffer
    }
    else // if i cant find a printer a 0, same  with files
		//if it is opened assigns a handle, something other than zero
    cout << "Could not find printer!\n";
    cout << "\nPress a key...";
    _getch();    
    return 0;
}
