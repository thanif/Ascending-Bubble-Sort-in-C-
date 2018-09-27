#define SIZE 100
#include <iostream>
#include<cstdlib>
#include <signal.h>
#include "hw0.h"
using namespace std;

int testno;
int totpoints;
int lastpoints;
int lasttotpoints;
int points;

void test_sorted_ascending()
{
	int* arr = new int[SIZE];
	for(int i = 0 ; i < SIZE ; i++)
		arr[i] = i;
	lasttotpoints += 1;
	bubble_sort_ascending(arr, SIZE);
	for(int i = 1 ; i < SIZE ; i++)
		if(arr[i-1] > arr[i])
			int a = 1/0;	
	lastpoints += 1;
}

void test_sorted_descending()
{
	int* arr = new int[SIZE];
	for(int i = 0 ; i < SIZE ; i++)
		arr[i] = SIZE-i;
	bubble_sort_ascending(arr, SIZE);
	lasttotpoints += 1;
	for(int i = 1 ; i < SIZE ; i++)
		if(arr[i-1] > arr[i])
			int a = 1/0;	
	lastpoints += 1;
}
void dispatcher()
{
	while(true)
	{
		lastpoints = 0;
        	lasttotpoints = 0;
		switch(testno)
		{
			case 0:
				cout << "Testing ascending sort..." << endl;
				test_sorted_ascending();
				break;
			case 1:
				cout << "Testing descending sort..." << endl;
				test_sorted_descending();
				break;
			default:
                       		cout << "Total Points: " << points << " / " << totpoints << endl;
                    		exit(0);                	
		}
		cout << " Passed! " << lastpoints << " / " << lasttotpoints << endl;
        	testno++;
        	points += lastpoints;
        	totpoints += lasttotpoints;
	}	
}

void signal_handler(int signum)
{
	cout << " Failed! " << lastpoints << " / " << lasttotpoints << endl;

    testno++;
    points += lastpoints;
    totpoints += lasttotpoints;

    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);
    dispatcher();
}

int main()
{
    // Set signal handlers
    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);

    cout << "Starting Tests" << endl;

    testno = 0;
    points = 0;
    totpoints = 0;
    dispatcher();    
}
