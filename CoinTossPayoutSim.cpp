// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
//
// https://docs.microsoft.com/en-us/troubleshoot/developer/visualstudio/cpp/libraries/stl-sqrt-pow-functions
// https://docs.microsoft.com/en-us/cpp/standard-library/iomanip-functions?view=msvc-170

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <cmath>    // To access power function for calculations
#include <string>   // To implement length() function
#include <ctime>    // Access random number generator
using namespace std;

// Constant Variable Initialization
const string TITLE = "Coin Toss Payout Simulator";
const string AUTHOR_LINE = "By Forrest Moulin";
const string COL1_HEAD = "Sim. #";
const string COL2_HEAD = "Flip Sequence";
const string COL3_HEAD = "Payout";
const int NUM_ITERATIONS = 10, GAP = 3;

int main()
{
	// Seed the rand function with current time
	srand(time(NULL));

	cout << TITLE << endl
		<< AUTHOR_LINE << endl << endl;

	// 'H' Heads (1) 'T' Tails (0)
	// n = number of instances to reach Tails
	int flipResultInt, n;
	char flipResultChar;
	// String of Ts and Hs (Example: TTTH)
	string flipSequenceStr;

	int col1Width = COL1_HEAD.length(),
		col2Width = COL2_HEAD.length() + GAP,
		col3Width = COL3_HEAD.length() + GAP - 1;

	double payout, payoutSum = 0, payoutAvg;
	cout << fixed << setprecision(2);

	// Column headers
		cout << left << setw(COL1_HEAD.length() + GAP) << "Sim. #"
		<< left << setw(COL2_HEAD.length() + GAP) << "Flip Sequence"
		<< left << setw(COL3_HEAD.length() + GAP) << "Payout" << endl;

	for (int i = 0; i < NUM_ITERATIONS; i++)
	{
		// Results, str, and n should reset on each for loop iteration
		flipResultChar = NULL;
		flipSequenceStr = "";
		n = 0;
		// Loop until heads appears as pseudo random int 1
		while (flipResultChar != 'H')
		{
			// Track number of iterations per simulation
			n++;
			// Flip result is set to rand int from 0 to 1
			flipResultInt = rand() % 2;
			if (flipResultInt == 1)
			{
				flipResultChar = 'H';
				// Append char to string
				flipSequenceStr += flipResultChar;
			}
			else
			{
				flipResultChar = 'T';
				// Append char to string
				flipSequenceStr += flipResultChar;
			}
			
		}
		// Base 2, raised to nth power
		payout = pow(2, n);
		payoutSum += payout;
		// Print table to console
		cout << right << setw(col1Width) << i + 1 << setw(GAP) << ""
			<< left << setw(col2Width) << flipSequenceStr
			<< "$" << right << setw(col3Width) << payout << endl;
	}
	payoutAvg = payoutSum / 10; 
	cout << endl << right << setw(25) << "Average payout: " 
		<< left <<  "$" 
		<< right << setw(8) << payoutAvg << endl;
}
/*
* CONSOLE OUTPUT
* Coin Toss Payout Simulator
* By Forrest Moulin
*
* Sim. #   Flip Sequence   Payout
*      1   H               $    2.00
*      2   TH              $    4.00
*      3   H               $    2.00
*      4   TTH             $    8.00
*      5   H               $    2.00
*      6   H               $    2.00
*      7   H               $    2.00
*      8   TTTTTH          $   64.00
*      9   H               $    2.00
*     10   TH              $    4.00
*
*          Average payout: $    9.20
*/
