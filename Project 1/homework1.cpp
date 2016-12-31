/*
+------------------------------------+
	Programmer: Saman Tajalli
	Course: Computer Science 1
	Lab Section: 0112 (Monday and Wednesday)
	Grader: Professor Fry
	Project 1
	Due Date: September 4, 2013
	+-------------------------------------+
	Program Statement
	This program will find and analyze the
	positive factors of a positive integer.
	********Analysis*************

	1.) Data needed
	a variable to hold the positive integer(number)
	a character to tell when user wants to input an integer
	or quit the program.
	Count variable for several of the functions
	Sum variable to add the factors of a number
	Boolean flag to find the twin primes
	
	2.)Constants given
	No constants
	
	3.) Calculations
	Finding factors of positive integer
	Finding sum of factors of the number
	Find the prime factorization of the number
	Tell whether the number is even or odd
	Tell whether the number is prime or composite
	Tell whether the number is deficient, abundant, or perfect.
	Tell whether the number is square free
	If the number is prime, tell if it has a twin and show
	what it is

	4.) Print results
	Print what was found from step 3 above.
	*****************************************************
	Algorithm

	Step 1: Input
	Prompt user whether to input a positive integer
	If user enters y for yes, then program continues(do-while loop)
	, if user enters n for no, program ends

	Step 2:Process

	After user enters positive integer, first a function to calculate
	all the factors of the number will be called by sending
	the number to it. A count variable will begin at 1. 
	A sum variable will be initialized to zero. while
	count is less than or equal to the number, it will check with
	an if statement whether number modulus count is equal to zero.
	If so, then the program will display the factors 
	and increment the sum variable, and display it as well. After the 
	if statement, the count is incremented by 1.

	Next, a function will be called that will proceed to display
	the prime factorization. While(a loop)
	 the number input by user modulus
	2 is equal to zero(number is divisible by 2) then 2 will be displayed
	on the monitor. Then through integer division, number will divide by
	2 and be stored in the number variable num. Then a For loop
	will initiate, initializing the variable i at 3, the condition
	being whether i is less than or equal to the square root of num. 
	Because the number
	was already divided by 2, num is now odd and so i will be incremented
	by 2 at the update expression of the loop to check for odd numbers.
	A nested While loop in the body of the For loop will check to see if
	num modulus i is equal to zero. When this happens, i, the odd number
	will be printed to the screen. Then assign num divided by i(integer
	division) to num. After the For loop ends, if num is greater than 2, 
	then display num to the monitor.

	Next, a function will be called to tell whether the positive integer
	is even or odd. If num modulus 2 is equal to zero, Then the number
	is even. Otherwise, the number is odd.

	Then, a function will be called to determine whether the integer
	is prime or composite. Here, a count variable will be initialized to 
	2. While count is less than or equal to num, and If num modulus count
	is equal to zero, and If(nested if) count is equal to num(meaning 
	count went all the way to num without being divisible to anything except
	itself), then num is prime, and break statement will break the loop.
	Else, the number is composite. At the end of the first If statement
	inside the while loop, count will increment by 1.

	After that, a function call will open to determine whether the integer
	is deficient, abundant, or perfect. A count variable will start at 1.
	A sum variable will initialize at 0. while count is less than num, 
	If num modulus count is equal to zero, then the sum will increment
	by count each time. then count will increment by 1. If sum is 
	equal to num, then num is perfect, Else if sum is less than num,
	num is deficient, Else if sum is greater than num, num is abundant.
	
	A function will be called after that to determine whether the
	integer is square free. A count variable will be initialized to 2.
	While count is less than or equal to num, If num modulus
	count times count is equal to zero, then num is not square free.
	A break statement will end the loop. Else if count is equal to num,
	num is square free because count never had a square that would make it
	divisible by num. A break statement will end the loop. Count will increment
	by 1.

	Finally, a function wll be called to tell if the integer, if
	prime, has a twin. A boolean variable called flag will be initialized
	to 1 or 0 depending on whether a boolean function, passing num by value,
	to a CheckIFPrime function, turns out to be true(num is prime). 
	If num turned out to be prime, the IF num + 2 turns out to be prime as
	well, that number is a twin prime and will be displayed.
	else IF num -2(num is prime) is prime, then that number is the twin prime
	and will be displayed. Otherwise, the number, num, does not have a 
	twin prime. If number is not prime at all, 0 will be returned and therefore
	nothing will happen.

	
*/
#include <iostream>
#include <cmath>
using namespace std;

void DisplayFactors(int);
void DisplayPrimeFactorization(int);
void DisplayEvenOrOdd(int);
void DisplayPrimeOrComposite(int);
void DisplayDeficientAbundantPerfect(int);
void DisplaySquareFree(int);
int DisplayTwinPrimes(int);
bool CheckIfPrime(int);


int main()
{
	int number;
	char letter;

	do{
	cout << "Do you want to enter a positive number? Enter y for yes or n for no\n";
	cin >> letter;

	if (letter == 'n' || letter == 'N')
		exit(0);

	cout << "Enter positive integer \n";
	cin >> number;
	while (number <= 0)
	{
		cout << "Enter a positive integer \n";
		cin >> number;
	}

	DisplayFactors(number);
	DisplayPrimeFactorization(number);
	DisplayEvenOrOdd(number);
	DisplayPrimeOrComposite(number);
	DisplayDeficientAbundantPerfect(number);
	DisplaySquareFree(number);
	DisplayTwinPrimes(number);

	}while (letter == 'Y' || letter == 'y');
	


		return 0;
}

void DisplayFactors(int num)
{
	int count = 1;
	int sum = 0;
	while (count <= num)
	{
		if (num % count == 0)
		{
			cout << count <<" ,";
			sum += count;
		}
		count++;

	}
	cout << "\nThe sum is " << sum << endl;
}

void DisplayPrimeFactorization(int num)
{
	cout << "The prime factorization is " << num << "= ";
	while (num % 2 == 0)
	{
		cout << "2 x";
		num = num / 2;
	}

	for (int i = 3; i <= std::sqrt(static_cast<float>(num)); i += 2)
	{
		while (num % i == 0)
		{
			cout << " " << i << " x";
			num = num / i;
		}
	}
	if (num > 2)
		cout << " " << num;
}


void DisplayEvenOrOdd(int num)
{
	cout << endl;
	if (num % 2 == 0)
		cout << num <<" is even\n";
	else
		cout << num <<" is odd\n";

}

void DisplayPrimeOrComposite(int num)
{
	int count = 2; 

	while (count <= num)
	{
		if (num % count == 0)
		{
			if (count == num)
			{
				cout << num <<" is prime\n";
				break;
			}
			else
			{
				cout << num << " is composite\n";
				break;
			}
		}
		
		count++;
	}

}

void DisplayDeficientAbundantPerfect(int num)
{
	int count = 1;
	int sum = 0;
	while (count < num)
	{
		if (num % count == 0)
		{
			
			sum += count;
		}
		count++;

	}
	
	if (sum == num)
		cout << num <<" is perfect\n";

	else if (sum < num)
		cout << num <<" is deficient\n";

	else if (sum > num)
		cout << num <<" is abundant\n";

}

void DisplaySquareFree(int num)
{
	int count = 2;
	
	
	while (count <= num)
	{
		

		if ((count * count) > num)
		{
			cout << num <<" is square free\n";
			break;
		}
		
		else if (num % (count * count) == 0)
		{
			cout << num <<" is not square free\n";
			break;
		}
	
		count++;

	}
}

int DisplayTwinPrimes(int num)
{
	bool flag = CheckIfPrime(num);
	// if flag is true
	if (!flag)
		return 0;
	if (CheckIfPrime(num + 2))
		cout << num << " has a twin prime which is " << num + 2 << endl;

	else if (CheckIfPrime(num - 2))
		cout << num << " has a twin prime which is " << num - 2 << endl;

	else
		cout << num <<" does not have a twin prime\n";
}

bool CheckIfPrime(int num)
{
	int count = 2;
	while (count <= num)
	{
		if (num % count == 0)
		{
			if (count == num)
			{
				return true; // num is prime
				break;
			}
			else 
			{
				return false; // num is composite
				break;
			}
		}
		count++;
	}
}