/*
10.1 Pointers
	the address of a memory location is called a pointer. 
		1byte char
		2byte short
		4byte float & long
		8bytes double
	usually compilers allocate space to assign individual variables even addresses because computers can access data that is in even addresses faster than data that resides at odd addresses
	& is the address operator. output is uasually in hexadecimal. long(&variable) will return the location in decimal format.
10.2 Pointer variables. variables that store an address are called pointer variables 
	ex: int *ptr
		* indicates ptr is a pointer variable
		int indicates that ptr can only point at the location of an integer variable
	* is called the indirection operator
		ps. int* ptr is the same thing
	when: 
		ptr = &x
	ptr contains whatever the address of x is and not x itself. this is useful because you can indirectly access and modify the variable. 
		ex: 
		
		// this program uses indireciton operator
		#include <iostream>
		using namespace std:
		
		int main()
		{	
			int x = 25;
			int *ptr;

			ptr = &x;

			cout << "the value in x printed twice: ";
			cout << x << " " << *ptr << endl;

			*ptr = 100;

			cout << "OOnce again, here is the value in x:\n";
			cout << x << " "<< *ptr << endl;
			return 0;

		}
	

		// this program uses the inderection operator to point to another variable
		#include <iostream>
		using namespace std;

		int main()
		{
			int x = 25, y= 50, z= 75;
			int *ptr;

			cout << x << " = x, " << y << " = y, " << z << " = z " << endl;
			// 25 = x, 50 = y, 75 = z
			ptr = &x;
			*ptr *= 2;
			
			ptr = &y;
			*ptr *= 2;

			ptr = &z;
			*ptr *= 2;
		
			cout << x << " = x, " << y << " = y, " << z << " = z " << endl;	
			//50 = x, 100 = y, 150 = z						
			return 0;
		}
10.3 arrays and pointers
	the array name withoug brackets and subscript is really the starting address of the array. this means that an array name is realy a pointer 
	this means that the first element can be accessed with *arrayname
	because *arrayname is the first location of the array it makes senst that values can be added to arrayname to ge the addresses of the other elements in the array. in C++ when you add value to a pointer you actually are adding that value times the size fo the data type being referenced by the pointer. 1*sizeof(variablytype) to array name
	this means that the insides of arrays are accessable with *(arrayname + memberlocation)
	array[index] is equivalent to *(array + index)
		worry because C++ performs not a single bounds check with arrays. When stepping through an array with a pointer it's possible to give it an address outside of the array.  
10.4 pointer math
	addition or subtraction
		++ and --
		+ and -
		pointer on pointer subtraction
		no mulitplication or division with pointers
10.5 init pointers
	pointers cam be initalized with the address of an existing object. 

		the types must match 
		float myFloat;
		int *pint = &myFloat; // is illegal

		can be done with one line
		int myValue, *pint = & myValue;

		to set pointers to point to nothing use zero
		int *ptrToint = 0; // called a null pointer

10.6 relational operators may be used to compare pointer values
	if one address comes before another the first is considered "less than". Unless they are passed as values *pointer1 and *pointer2 will compatre the values that are pointed at while pointer1 and pointer2 will compare the addresses
10.7 pointers as function parameters
	pointer can be used as afunciton parameter it gives the funciton access to the orignal argumetn like a reference parameter.

10.8 pointers to constants and constat pointers
	pointer to constant may not change the value it points to. a constant pointer can't be changed after it's ben initalized

10.9 software engineering dynamic memory allocation
	create and destroy variable while a program is running

	when you don't know how may variables will be needed for a program. allow the program to create it's own variables "on the fly" = dynamic memory allocation and only works thhrough pointers
	while running the program asks the computer to set aside a chunk of free memory large enought to hold a variable of some type when the computer fills the request it gives the program the starting address so a pointer is required to use those bytes.
	C++ programs request dynamically allocated memory through the new operatro

		some pointer int defined as 
		int *iptr

		the pointer can be used with the new operator:
		iptr = new int; // this is saying "allocate enough memory for a new int variable. "

		now any operation will work on the new variable by using the dereferenced pointer. 
		cout<< *iptr/
		cin >> *iptr;
		total += iptr;





			*/