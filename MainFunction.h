#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <cmath>
#pragma warning (disable:4996)

//Swap function
//Exp: a = 2, b = 3 -> a = 3, b = 2
void HoanVi(int&a,int&b)
{
	int TempValue = a;
	a = b;
	b = TempValue;
}

//Find min value function
int TimMin(int Array[], int ArrayPointer, int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	int Min = Array[ArrayPointer];
	int Pointer = ArrayPointer;
	for (int i = ArrayPointer + 1; i < ArraySize; i++)
	{
		if (Min > Array[i])
		{
			Min = Array[i];
			Pointer = i;
			*Num1 += 1;
		}	
		*Num2 += 1;
	}
	return Pointer;
}

//Find min value function
int TimMax(int Array[], int ArrayPointer, int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	int Max = Array[ArrayPointer];
	int Pointer;
	for (int i = ArrayPointer + 1; i < ArraySize; i++)
	{
		*Num2 += 1;
		if (Max < Array[i])
		{
			Max = Array[i];
			Pointer = i;
			*Num1 += 1;
		}
	}
	return Pointer;
}
 
//Array initiate function 
void ArrayInitial(int Array[], int ArraySize)
{
	srand(time(NULL));
	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = rand() % 1000 + 1;
	}
}

//Measure time function
void GetTime(time_t &Timer)
{
	Timer = time(NULL);
}

//Print array's values function
void XuatMang(int Array[], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
	{
		printf("%5d", Array[i]);
	}
}

//Insert value at PosS into PosD
void ChenPT(int Array[], int ArraySize, int Value, int PosS, int PosD)
{
	if (PosS > PosD)
	{
		for (int i = PosD; i < PosS; i++)
		{
			Array[i] = Array[i + 1];
		}
		Array[PosS] = Value;
		return;
	}
	for (int i = PosS; i < PosD; i++)
	{
		Array[i] = Array[i + 1];
	}
	Array[PosD] = Value;
}

