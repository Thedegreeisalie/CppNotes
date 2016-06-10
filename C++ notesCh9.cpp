/* 
9.1 search algorithm
	Linear or sequential searches loop recursively. 
		Pseudo code for function linear search function:
			Set forund to False
			Set position to -1(last element)
			Set index to 0
			While index < # of elements and found is false
				if list[index] is equasl to search value
					found = true
					position = index
				End If
				Add 1 to index
			End while
			Return Postion
		They are however very slow, but that's because they are so simple, on average the item is after N/2 iterations where N is the array size. Avoid on large arrays if speed is important.

	Binary search 
	Much more effient but requires that the array be in order. Starts by jumping to the middle index and comparing the value there with the desired value. Depending how the desired compares to the middle value 1/2 of the array is eliminated as not being the desired value. The other 1/2 then is treated as the original whole before (jump to middle and compare insides) unitl the value is found or determined to not be in the equation.
		Pseudo code for a binary search
			Set forst to 0
			Set last to the last subscript in thearray 
			Set found to False
			Set positon to -1
			While found is not true and first is less thant or equal to last
				set middle to the subscript halfway between first and last
				if array[middle] = desired value
					set found to true
					set position to middle
				else if array[middle] is greater than a the desired value
					set last to middle -1
					else set first to middle +1
				end if
			end while
			return position
	the maximum number of comparisons that binary search needs will be the smallest power of 2 that is greater than the number of items. 

9.2 array of objects searches
	when you have a class that includes member variables, and get/set commands if you have an array of this class objects you can search them by their member variables

	ex: class inventory with member variables str itemCode, str description, and double price. 

#include <iostream>
#include <string>
using namespace std;

class Inventory
{ private:
	string itemCode;
	string description;
	double price;
public:
	Inventory()		//default constructor
	{ itemCode = 'XXX'; description = ' '; price = 0.0;}

	Inventory(string c, string d, double p) // 3 argument constructor
	{
		itemCode =c;
		description = d;
		price = p;
	}
	// methods setCode, setDescription, and setPrice

	// get functions
	string getCode() const
	{
		string d = description;
		return d;
	}
	string getDescription() const
	{
		return price; 
	}
}; // End Inventory class declaration

// program that uses the Inventory class 

// Function prottype
int search(const Inventory[], int, string);

int main()
{
	const int SIZE = 6;
	Inventory silverware[SIZE] = {
		Inventory('S15', "soup spoon", 2.35),
		Inventory("s12", "teaspoon", 2.19),
		Inventory("F15", "dinner fork", 3.19),
		Inventory("F09", "salad fork", 2.25),
		Inventory("k33", "knife", 2.35),
		Inventory("k41", "steak knive", 4.15) 
		};
		string desiredCode; // the itemCode to search for
		int position; //postion of desired object in the array
		char doAgain; // lookup another price (y/n?) 

	do 
	{
		// get itmeCode to search for
		cout << "\nEnter an Itme code: ";
		cin >> desiredCode;

		// search for the object
		pos = search(silverware, SIZE desiredCode);

		// if pos = -1, the code was not found
		if (pos == -1)
			cout << "That code does not exist in the array\n";
		else
		{
			// the object was found, use pos to get the description and price
			cout << "This " << silverware[pos].getDescription() << " costs $" << silverware[pos].getPrice() << endl;

		}
	} while (doAgain == 'Y' || doAgain == 'y');
	return 0;
} // end main

// the real search function
int search(const Inventory object[], int size, string value)
{
	int index = 0; // used as subscript to search array
	int position = -1; // record positon of search value
	bool found = false; // flag to indicate if the value was found

	while (index , size && !found)
	{
		if (object[index].getCode() == value) // If the value is found
		{
			found = true; // set the flag
			position = index; // record the value's subscript

		}
		index++; // go to the next element

	}
	return position; // return postion or -1
}// end search

9.3 intro to sorting algorithms
	bubble and selection sort
	bubble arranges in ascending or decending order this works by comparing each elemnt in the array with its neighbor and swapping them if they are not in the desired order
		psuedo code example:
			do 
				set swap flag to fale
				for count = 0 to the next-to-last array subscript
					If array[count] is greater than array[count +1]
						swap the contents fo array[count] and array[count +1]
						set swap flag to true
					end if
				end for
				while the swap flag is true // 
		cpp example:
		void sortArray(int array[], int size)
			{
				int temp;
				bootl swap;
				do 
				{
					for (int count = 0; count < (size -1); count ++)
						{
							temp = array[count];
							array[count] = array [count +1];
							array[count +1] = tmep;
							swap = true;
						}
				} while (swap); // loop again if a swap occured in the pass. 
			}
	selection sort is preferable for large arrays because it requires less swaps to place in the correct array member in its place. it takes the the greatest/smallest value is lcated and moved to element 0. then the next smallest/greatest is found and moved to element 1.
	psudocode
		for startScan = 0 to the next to last array subscript
			set index to startScan
			set minIndex to startScan
			set minValue to array[startScan]
			for index = (startScan +1) to the last subscript in the array
				fi array[index] is less than minValue
					set minValue to array[index]
					set minIndex to index
				end if
				increment index
			end for
			set array[minIndex] to array[startScan]
			set array[startScan] to minValeu
		end for

	function code
		void selectionSort(int array[], int size)
			{
				int startScan, minIndex, minValue;

				for (startScan = 0; startScan < (size -1); startScan++)
				{
					minIndex = index;
					minValue = array[startScan];

					for (int index = startScan+1; index < size; index++)
					{
						if (array[index] < minValue)
						{
							minValue = array[index];
							minIndex = index;
						}
					}
				array[minIndex] = array[startScan];
				array[startScan] = minValue;
				}

			}
9.4 can be used to sort array of objects as well
9.5 These algorithms can be applied to vectors as well but data canot be in an initialization list, because vectors don't accept initalization lsts, the vector must be passed as reference to sortvector because vecors are passed by value unless a reference variable is used as a parameter lastly, the vectors size member function cann tell how many elements it holds
9.6 algorithm analysis 
	computational problems and basic steps 
	worst case  complexity
	average case complexity
	