// CCN2042 Assignment 1

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

// GIVEN CODES, DO NOT MODIFY 
// BEGIN
const int BUFSIZE = 10240;

void compareFiles()
{
	char buf1[BUFSIZE];
	char buf2[BUFSIZE];
	bool same = true;
	ifstream inFile1, inFile2;

	inFile1.open("outputData.txt");
	inFile2.open("sampleOutput.txt");

	if ( !inFile1 ) {
		cout << "No file to open (outputData.txt)" << endl;
		return;
	}

	if ( !inFile2 ) {
		cout << "No file to open (sampleOutput.txt)" << endl;
		cout << "Please put sampleOutput.txt at same folder as your cpp source code." << endl;
		return;
	}

	while ( !inFile1.eof() && !inFile2.eof() ) {
		inFile1.getline(buf1, BUFSIZE);
		inFile2.getline(buf2, BUFSIZE);
		if (strcmp(buf1, buf2)) same = false;
	}

	if ( !inFile1.eof() || !inFile2.eof() ) same = false;

	cout << "outputData.txt <---> sampleOutput.txt" << " ........... ";
	if (same) cout << "[OK]" << endl;
	else cout << "[FAILED]" << endl;

	inFile1.close();
	inFile2.close();
}
// END

void showInfo() //showing personal information
{
	cout << "Name:                   Chan Tik Shun" << endl;
	cout << "Lecture group number:   201C         " << endl;
	cout << "Tutorial group number:  201C         " << endl;
	cout << "Student ID:             16109510A    " << endl;
}

int factorial(int num) // functions for calculating the factorial from a given number
{
	int fac_result = 1;

	for(int i = 1; i <= num; i++) //loop body for calculating the factorial
	{
		fac_result = fac_result * i;
	}
	return fac_result; // Return the result of factorial
}

int nCr(int n, int r) // functions for calculating the nCr from 2 given numbers (n and r)
{
	int nCr_result = 0;
	nCr_result = (factorial(n)) / (factorial(r) * factorial(n-r)); // use factorial function  to calculate the factorial of each input

	return nCr_result; // Return the result of nCr into the main part of the program
}

void Q1()
{
	// Display the nCr table from here
	cout << "\n\nValues of nCr for different n and r" << endl;
	cout << "===================================" << endl;
	cout << "n \\ r" << setw(5) << "1" << setw(5) << "2" << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << endl;
	cout << "-----------------------------------" << endl;

	for (int n = 1; n <= 6; n++) // Outter loop
	{
		cout << setw(5) << n;

		for ( int r = 1; r <= 6; r++) // Inner loop
		{
			if(r <= n)
			{
				cout << setw(5) << nCr(n,r); // use nCr function to calculate the result
			}
			else
			{
				cout << setw(5) << "--"; // invalud answer and thus being ignored
			}
		}
		cout << endl;
	}
	cout << endl;

	//nCr table ends here
	//User defined nCr calculation starts here

	int n2, r2; // User defined n and r
	while(1) // It will loop infintely
	{
		cout << "Please enter the value of n: ";
		cin >> n2; // prompt user to enter the value of n
		cout << "Please enter the value of r: ";
		cin >> r2; // prompt user to enter the value of r

		if(n2 >= r2 && n2 > 0 && r2 > 0) // when all of these conditions are meet, the result will be valid and output the solution respectively
		{
			cout << "The value of nCr is " << nCr(n2,r2) << "\n\n";
		}
		else // when any one of those condition are not fulfilled, the result will be invalid and output No solution
		{
			cout << "No solution, bye bye! \n\n";
			break; // return to the Program Selection Menu
		}
	}
	//User defined nCr calculation ends here
}

void Q2()
{
	// GIVEN CODES, DO NOT MODIFY 
	// BEGIN
	ifstream inFile;
	ofstream outFile;
	
	inFile.open("inputData.txt");
	if ( !inFile ) {			// if this happens, please put the given inputData.txt at same folder as your cpp source code
		cout << "No file to open (inputData.txt)" << endl;
		cout << "Please put inputData.txt at same folder as your cpp source code." << endl;
	}
	remove("outputData.txt");		// remove the file "outputData.txt" before creating a new one again
	// END

	int option; 

	cout << "Output result to: (1) console / (2) file (outputData.txt): ";
	cin >> option; //Variable containing the choice input by user

	int count; // count = number of data in the file
	int data, valid_counter = 0, five_counter = 0;  // data = data to be tested, valid_counter = number of valid data in the file, five_counter = number of 5 in the file
	double sum = 0.0, average = 0.0; // variable for storing the sum and average

	if(option == 2) //if user choose to output result to file
	{
		outFile.open("outputData.txt"); //create outputData.txt and store data into it
	}

	inFile >> count; //read the number of data (in the first line of inputData.txt)

	for(int j = 1; j <= count; j++) // Run the same number of loop as count
	{
		inFile >> data; // read the data (one at a time)
		if(data >= 3 && data <= 7) // if that data is between 3 and 7
		{
			if(data == 5) // if the data equals to 5
			{
				five_counter++; // add 1 to the counter for storing the number of 5 
			}

			if(option == 2) // if user choose to output result to file
			{
				outFile << data << endl; // output that data into the file
			}

			valid_counter++; // add 1 to the counter for storing the number of valid data
			sum = sum + data; // Add that data into sum
		}
	}

	average = sum / valid_counter; // Calculating the average of all valid data (floating division)

	if(option == 2) // if user choose to output result to file
	{
		outFile << valid_counter << endl; // write the number of valid data into the file
		outFile << average << endl; // write the average of all valid data into the file
		outFile << five_counter << endl; // write the number of 5 into the file
		cout << "Data is written into file outputData.txt" << endl; //remind user the whole process is completed
	}
	else if (option == 1) // if user choose to output result to console
	{
		cout << "Number of values from 3 to 7 in the source is " << valid_counter << endl; // display the number of valid data in console
		cout << fixed << setprecision(3) << "Average of these values is " << average << endl; // display the average of all valid data in console
		cout << setprecision(0) << "Frequency of 5 is " << five_counter << endl; // display the number of 5 in console
	}

	// GIVEN CODES, DO NOT MODIFY 
	// BEGIN
	inFile.close();
	outFile.close();
	compareFiles();
	// END
}

void Q3()
{
	while(1) //The program will run this part infintely
	{
		//Program INPUT
		int hr_enter, min_enter, hr_left, min_left, hr_stay = 0, min_stay = 0, charge = 0; //All of these variables should be interger only
		char vtype, more_cal; //these should contain a character only

		cout << "\n\nEnter the type of vehicle ('c' for Car, 'b' for bus): "; 
		cin >> vtype; // prompt user to enter the type of vehicle

		cout << "Enter the hour the vehicle entered the carpark: ";
		cin >> hr_enter; // prompt user to enter the hour of entering carpark

		cout << "Enter the minute the vehicle entered the carpark: ";
		cin >> min_enter; // prompt user to enter the minute of entering carpark

		cout << "Enter the hour the vehicle left the carpark: ";
		cin >> hr_left; // prompt user to enter the hour of leaving carpark

		cout << "Enter the minute the vehicle left the carpark: ";
		cin >> min_left; // prompt user to enter the minute of leaving carpark

		//Program OUTPUT
		// The first few lines of the output (static)
		cout << "\n\nPARKING CHARGE (Carpark A)" << endl;
		cout << "--------------------------" << endl;
		cout << "Type of vehicle:" << setw(13);

		if( vtype == 'c' )
			cout << "Car" << endl; //Display Car for c on vtype
		else
			cout << "Bus" << endl; //Display Bus for b on vtype


		cout << "Time In:" << setw(16) << " " << setw(2) << setfill('0')  << hr_enter << ":" << setw(2) << min_enter << endl;  //Display the time of entering in the format of HH:MM
		cout << "Time Out:" << setfill(' ') << setw(15) << " " << setw(2) << setfill('0') << hr_left << ":" << setw(2) <<  min_left << endl; //Display the time of leaving in the format of HH:MM
		cout << setfill(' ') << setw(29) << "-----" << endl; //Separation line


		hr_stay = hr_left - hr_enter; //Calculating the hour of staying in the carpark (before rounding up)
		if(min_left < min_enter)
		{
			min_stay = 60 - (min_enter - min_left); //Calculate the minute of staying in case (min_left - min_enter) < 0
			hr_stay--; //Reduce the hour stayed by 1 because of borrow digit
		}
		else
		{
			min_stay = min_left - min_enter; //The result of minute stayed will not be negative if min_left >= min_enter
		}
	

		cout << "Parking Time:" << setfill(' ') << setw(11) << " " << setw(2) << setfill('0') << hr_stay << ":" << setw(2) << min_stay << endl; //Display the time of staying in the format of HH:MM


		if(min_stay > 0)
			hr_stay = hr_stay + 1; //round up the hour stayed if necessary

		cout << "Round Total (hours):" << setfill(' ') << setw(9) << hr_stay << endl; //Display the total hour in calculation of charges
		cout << setfill(' ') << setw(29) << "-----" << endl; //Separation line


		if( vtype == 'c') //Calculation algorithm for the vechicle type Car
		{
			if(hr_stay > 3) //Calculation algorithm of staying for 4 or more hour
			{
				charge = 30; //Charge must be larger than $30 ($10*3)
				for(int i = 4; i <= hr_stay; i++)
				{
					charge = charge + 13; // Add charge by 13 for every extra hour stayed beyound 3 hour
				}
			}
			else //Calculation algorithm of staying for 1 to 3 hour
			{
				for(int j = 1; j <= hr_stay; j++) //1~3 hour only (depends on user input)
				{
					charge = charge + 10;  // Add charge by 10 for every hour stayed beyound 0 hour til 3 hour
				}
			}
		}
		else //Calculation algorithm for the vechicle type Bus
		{
			if(hr_stay > 3) //Calculation algorithm of staying for 4 or more hour
			{
				charge = 18; //Charge must be larger than $18 ($6*3)
				for(int i = 4; i <= hr_stay; i++)
				{
					charge = charge + 8; // Add charge by 8 for every extra hour stayed beyound 3 hour
				}
			}
			else //Calculation algorithm of staying for 1 to 3 hour
			{
				for(int j = 1; j <= hr_stay; j++) //1~3 hour only (depends on user input)
				{
					charge = charge + 6; // Add charge by 6 for every hour stayed beyound 0 hour
				}
			}
		}


		cout << "Total Charge:" << setw(12) << "$" << setw(4) << charge << "\n\n"; //Display the total charge
		cout << "Enter 'y' to perform another calculation, entering other character will return to the Program Selection Menu: ";
		cin >> more_cal; //Let user decide if they want to perform another calculation or not
	
		if(more_cal != 'y') //If user enters other character other than y, it will exit the loop
		{
			cout << endl; //break line for better output
			break; //return to Program Selection Menu
		}
	}
}

// GIVEN CODES, DO NOT MODIFY 
// BEGIN
int main()
{
	int prog_choice;

	showInfo();

	do {
		cout << endl;
		cout << "Assignment One - Program Selection Menu" << endl;
		cout << "---------------------------------------" << endl;
		cout << "(1) Program One" << endl;
		cout << "(2) Program Two" << endl;
		cout << "(3) Program Three" << endl;
		cout << "(4) Exit" << endl;
		cout << "Enter the choice: ";
		cin >> prog_choice;
		switch (prog_choice){
		case 1: Q1(); break;
		case 2: Q2(); break;
		case 3: Q3(); break;
		case 4: break;
		default: 
			cout << "Please enter choice 1 - 4 only." << endl;
			break;
		}
	} while (prog_choice != 4);

	cout << "Program terminates. Good bye!" << endl;
	return 0;
}
// END