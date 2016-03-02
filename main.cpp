#include <iostream>
#include <iomanip> // for setw, fixed, setprecision() manipulators
#include <string.h> //for string types usage
#include <cstdlib>

using namespace std;
int a[6];
string combOut[6];
int numOfComb(int n, int k);
int guessesGiven(int numOfComb);

void printHorizontalLine( int width, char border_char )
{
    cout.fill( border_char );
    cout << setw( width ) << border_char << "\n";
    cout.fill(' ');
}

//Play the Stars and Bars game
    //*Initialize game
void PrintIt(int n, int k, int a[])
{//a[i] is the array that will be printed so int a[6];
	//*initialize state variables
	int i;

    string combination;
	//*if combinations token is 1 print *
	//*if combinations token is 0 print |
	//*append tokens to variable

	for (i=1; i <= n; i++)
	{
		if( a[i] == 1 )
		{
			combination = combination + "*";
		}
		else
		{
			combination = combination + "|";
		}
	}
    cout << combination << endl;

	//for (int l = 0; l < guessesGiven(nOfR); l++){

	//}
}
/*
* Recursive algorithm for generating combinations
*
* Given nCk (n combination k ) or (n choose k)
* @param n: number of elements
* @param k: number of stars
*/
void Comb(int n, int k, int j = 1, int m = 0)
{
	if (j > n)
	{
		PrintIt(n, k, a);
	}
	else
	{
		if (k-m < n-j+1)
		{
			a[j] = 0;
			Comb(n, k, j+1, m);
		}
        if (m<k)
		{
			a[j] = 1;
			Comb(n, k, j+1, m+1);
		}
	}
}
        //**Display stage {1,2,3,4}
        void displayStage (int stage)
        {
            printHorizontalLine(28, '-');
            cout << "********** Game " << stage << " **********" << endl;
            printHorizontalLine(28, '-');
        }
        //**Give at least the first two guesses

            //***Calculate how many guesses will be given
                //****Calculate total number of combinations
                int numOfComb(int n, int k){
                    int l = n-k;
                    int top = 1;
                    int bottom = 1;
                for (n; n>k; n--)
                    {
                        top = top * n;
                    }
                for (l; l>0;l--)
                    {
                        bottom = bottom * l;
                    }
                return top/bottom;
                }
                //****The number of guesses given must be between 2 and half of the total number of combinations
                    //*****Random number generator
                    int guessesGiven(int numOfComb){
                    int random = rand() % (numOfComb/2);
                        //******if RN<2, RN = 2
                        if (random < 2)
                            {return 2;}
                        else
                            {return random;}
                    }

        //**Ask user for next guess
        void userGuess(){

            //***Output text asking for next guess
            cout << "Enter next sequence: ";
            //**Get guess
            //cin >> guess;
        }
    //*Advance game based on correct/incorrect user input
        //**If guess is correct
            //***Give a random number of sequence of guesses
                //****Check if stage is over. If not,
                //****Output text asking for next guess
        //**If guess is incorrect
            //***Give second chance

                //****If the number of incorrect guesses exceeds half of the total number of guesses, end game
            //***If second chance is incorrect
                //****Give correct answer
                //****Move on to the next available guess
                    //*****Output text asking for next guess
        //**If stage is over (not last stage)
            //***Return back to Initialize game for the next stage
    //*End game
        //**Show score

int main()
{
    //cout << guessesGiven(6) << endl;
    Comb(6,5);
    return 0;
}
