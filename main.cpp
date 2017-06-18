#include "SortFunction.h"

unsigned long long Num1; //Number of assignment
unsigned long long Num2; //Number of comparision
int main()
{
	//Choice
	int choice;
	do
	{
		//Create array
		clock_t Time_Start, Time_Finish;
		int ArraySize;
		printf("Enter array size: ");
		scanf("%d", &ArraySize);
		int *Array = (int*)calloc(ArraySize, sizeof(int));
		ArrayInitial(Array, ArraySize);

		//Choice
		printf("1.  Selection sort\n");
		printf("2.  Insertion sort\n");
		printf("3.  Binary insertion sort (upgrade version of Insertion sort)\n");
		printf("4.  Interchange sort\n");
		printf("5.  Bubble sort\n");
		printf("6.  Shaker sort (upgrade version of Bubble sort)\n");
		printf("7.  Shell sort\n");
		printf("8.  Heap sort\n");
		printf("9.  Quick sort\n");
		printf("10. Merge sort\n");
		printf("11. Radix sort\n");
		printf("0.  End program\n");
		printf("Choose your way to sort: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
					Num1 = Num2 = 0;
					Time_Start = clock();
					SelectionSort(Array, ArraySize, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 2:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					InsertionSort(Array, ArraySize, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 3:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					BinaryInsertionSort(Array, ArraySize, &Num1, &Num2);
				    Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 4:
		{
				    Num1 = Num2 = 0;
			    	Time_Start = clock();
					InterchangeSort(Array, ArraySize, &Num1, &Num2);
				    Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 5:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					BubbleSort(Array, ArraySize, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 6:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					ShakerSort(Array, ArraySize, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 7:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					ShellSort(Array, ArraySize, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 8:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					HeapSort(Array, ArraySize, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 9:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					QuickSort(Array, ArraySize, 0, ArraySize - 1, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 10:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					ChiaMangA(Array, 0, ArraySize - 1, ArraySize, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		case 11:
		{
				    Num1 = Num2 = 0;
				    Time_Start = clock();
					int Max = Array[TimMax(Array, 0, ArraySize, &Num1, &Num2)];
					RadixSort(Array, ArraySize, Max, &Num1, &Num2);
					Time_Finish = clock();
					double Duration = (double)(Time_Finish - Time_Start) / CLOCKS_PER_SEC;
					printf("\nThoi gian sap xep: %.5f\n", Duration);
					printf("\nSo phep gan: %d\n", Num1);
					printf("\nSo phep so sanh: %d\n", Num2);
					break;
		}
		}
		printf("\n\n-----------------------------------------------------------------\n\n");
		free(Array);
	} while (choice != 0);

	_getch();
	return 0;
}
