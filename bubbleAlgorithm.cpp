#include<iostream>
#include<time.h>
#include<cmath>

using namespace std;

double bubbleSort(int arraySize[], int size)
{
	clock_t start = clock();
	int temp, flag = 0;
	
	for(int i =0; i < size-1; i++)
	{
		for(int j = 0; j < size-1-i; j++)
		{
			if(arraySize[j] > arraySize[j+1] )
			{
				int temp = arraySize[j];
				arraySize[j] = arraySize[j+1];
				arraySize[j+1] =temp;
				
				//if swapping happens update flag to 1;
				
				flag = 1;
			}
		}
		
		//if value of the flag is zero after all the iterations of the inner loop the break out
		
		if( flag == 0 )
		{
			break;
		}
	}
	
	clock_t end = clock();
	int timeTaken = (end - start) / CLOCKS_PER_SEC;
	
	return timeTaken;
}

int main()
{
	srand(time(0));
	int size;
	
	cout << "Enter the size of the array to be sorted: " << endl;
	cin >> size;
	
	int arraySize[size];
	for(int i = 0; i < size; i++)
	{
		arraySize[i] = rand()%1000;
		cout << arraySize[i] << endl;
	}
	
	cout << endl << "Press ENTER to sort the random array using Bubble sort method: " << endl;
	cin.ignore();
	cin.ignore();
	
	cout << "Bubble Sort : " << endl;
	for(int i = 0; i < size; i++)
	{
		bubbleSort(arraySize, size);
		cout << arraySize[i] << endl;
	}
	
	cout << endl << "The BUBBLE SORT took " << bubbleSort(arraySize, size) << " seconds to sort the random numbers! " << endl;
	cout << "TIME COMPLEXITY:: " << pow(size,2) << endl;
	
	return 0;
}