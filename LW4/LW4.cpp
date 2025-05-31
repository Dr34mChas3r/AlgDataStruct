#include <iostream>  
#include <ctime>  
#define N (10 * 6) % 51  
using namespace std;

void Random(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 241 - 120;
	}
}

void printArr(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void selectionSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{

		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				swap(array[j], array[i]);
			}
		}
		printArr(array, size);
	}
}

void insertionSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int j;
		for (j = i - 1; j >= 0 && array[j] > key; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = key;
		printArr(array, size);
	}
}


void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
		}
		printArr(array, size);
	}
}



int main()
{
	srand(time(0));
	int size = N;
	int array[size];
	int sortMethod;
	cout << "Enter the type of array sort (1 - selection, 2 - insertion, 3 - bubble): " << endl;
	cin >> sortMethod;
	switch (sortMethod) {
	case 1:
		Random(array, size);
		printArr(array, size);
		selectionSort(array, size);
		break;
	case 2:
		Random(array, size);
		printArr(array, size);
		insertionSort(array, size);
		break;
	case 3:
		Random(array, size);
		printArr(array, size);
		bubbleSort(array, size);
		break;
	default:
		cout << "Incorrect option. Enter number from 1 to 3 for choosing type of array sort";
	}
}

