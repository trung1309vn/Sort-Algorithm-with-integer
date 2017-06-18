//**Phuoc Trung Nguyen Ly**//
//**24 - 05 - 2016**//

#include "MainFunction.h"

//Selection sort
void SelectionSort(int Array[], int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	for (int i = 0; i < ArraySize - 1; i++)
	{
		int Index = TimMin(Array, i, ArraySize, Num1, Num2);
		HoanVi(Array[i], Array[Index]);
		*Num1 += 3;
	}
}

//Insertion sort
void InsertionSort(int Array[], int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	for (int i = 1; i < ArraySize; i++)
	{
		*Num1 +=1 ;
		int temp = Array[i];
		int j = i - 1;
		while (j >= 0 && Array[j] > temp)
		{
			*Num2 += 1;
			Array[j + 1] = Array[j];
			j--;
			*Num1 += 1;
		}
		*Num2 += 1;
	}
}

//Binary insertion sort
int BinarySearch(int *Array, int temp, int left, int right, unsigned long long *Num1, unsigned long long *Num2)
{
	if (right <= left)
	{
		*Num2 += 1;
		if (temp > Array[left])
		{	
			return left + 1;
		}
		else
		{
			return left;
		}
	}
	int mid = (left + right) / 2;
	*Num2 += 1;
	if (temp == Array[mid])
	{
		return mid + 1;
	}
	*Num2 += 1;
	if (temp > Array[mid])
	{
		return BinarySearch(Array, temp, mid + 1, right, Num1, Num2);
	}
	return BinarySearch(Array, temp, left, mid - 1, Num1, Num2);
}
void BinaryInsertionSort(int *Array, int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	int loc, j, selected;
	for (int i = 1; i < ArraySize; i++)
	{
		j = i - 1;
		*Num1 += 1;
		selected = Array[i];
		loc = BinarySearch(Array, selected, 0, j, Num1, Num2);
		while (j >= loc)
		{
			Array[j + 1] = Array[j];
			*Num1 += 1;
			j--;
		}
		*Num2 += 1;
		Array[j + 1] = selected;
		*Num1 += 1;
	}
}

//Interchange sort
void InterchangeSort(int Array[], int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	for (int i = 0; i < ArraySize - 1; i++)
	{
		for (int j = i + 1; j < ArraySize; j++)
		{
			if (Array[j] < Array[i])
			{
				HoanVi(Array[j], Array[i]);
				*Num1 += 3;
			}
			*Num2 += 1;
		}
	}
}

//Bubble sort
void BubbleSort(int Array[], int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	int k;
	do
	{
		k = 0;
		for (int i = 0; i < ArraySize - 1; i++)
		{
			if (Array[i] > Array[i + 1])
			{
				HoanVi(Array[i], Array[i + 1]);
				k = i;
				*Num1 += 3;
			}
			*Num2 += 1;
		}
	} while (k > 0);
}

//Shaker sort
void ShakerSort(int Array[], int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	int k;
	do
	{
		k = 0;
		for (int i = 1; i < ArraySize - 1; i++)
		{
			if (Array[i] > Array[i + 1])
			{
				HoanVi(Array[i], Array[i + 1]);
				*Num1 += 3;
				k = i;
			}
			*Num2 += 1;
			if (Array[ArraySize - i - 1] < Array[ArraySize - i - 2])
			{
				HoanVi(Array[ArraySize - i - 1], Array[ArraySize - i - 2]);
				k = i;
				*Num1 += 3;
			}
			*Num2 += 1;
		}
	} while (k > 0);
}

//Quick sort
void QuickSort(int Array[], int ArraySize, int Left, int Right, unsigned long long *Num1, unsigned long long *Num2)
{
	int i = Left, j = Right;
	int TempValue = Array[(Left + Right) / 2];
	*Num1 += 1;
	do
	{
		while (Array[i] < TempValue)
		{
			i++;
			*Num2 += 1;
		}
		while (Array[j] > TempValue)
		{
			j--;
			*Num2 += 1;
		}
		*Num2 += 2;
		if (i <= j)
		{
			HoanVi(Array[i], Array[j]);
			*Num1 += 3;
			i++;
			j--;
		}
	} while (i < j);
	if (Left < j)
	{
		QuickSort(Array, ArraySize, Left, j, Num1, Num2);
	}
	if (Right > i)
	{
		QuickSort(Array, ArraySize, i, Right, Num1, Num2);
	}
}

//MergeSort
void MergeSort(int *Array, int left, int mid, int right, int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	int *tmp = (int*)malloc(ArraySize*sizeof(int));
	int i, j, k, m;
	j = left;
	m = mid + 1;
	for (i = left; j <= mid && m <= right; i++)
	{
		if (Array[j] <= Array[m])
		{
			tmp[i] = Array[j];
			j++;
		}
		else
		{
			tmp[i] = Array[m];
			m++;
		}
		*Num1 += 1;
		*Num2 += 1;
	}
	if (j > mid)
	{
		for (k = m; k <= right; k++)
		{
			tmp[i] = Array[k];
			*Num1 += 1;
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			tmp[i] = Array[k];
			*Num1 += 1;
			i++;
		}
	}
	for (k = left; k <= right; k++)
	{
		Array[k] = tmp[k];
		*Num1 += 1;
	}
	free(tmp);
}
void ChiaMangA(int *Array, int left, int right, int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		ChiaMangA(Array, left, mid, ArraySize, Num1, Num2);
		ChiaMangA(Array, mid + 1, right, ArraySize, Num1, Num2);
		MergeSort(Array, left, mid, right, ArraySize, Num1, Num2);
	}
}

//Hàm ShellSort
void ShellSort(int *Array, int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	for (int i = ArraySize / 2; i > 0; i = i / 2)
	{
		for (int j = i; j < ArraySize; j++)
		{
			for (int k = j - i; k >= 0; k = k - i)
			{
				*Num2 += 1;
				if (Array[k + i] >= Array[k])
				{	
					break;
				}
				else
				{
					HoanVi(Array[k + i], Array[k]);
					*Num1 += 3;
				}
			}
		}
	}
}

//Heap sort
void Manage(int *Array, int ArraySize, int i, unsigned long long *Num1, unsigned long long *Num2)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < ArraySize && Array[l] > Array[largest])
	{
		largest = l;
	}
	*Num2 += 1;
	if (r < ArraySize && Array[r] > Array[largest])
	{
		largest = r;
	}
	*Num2 += 1;
	if (largest != i)
	{
		HoanVi(Array[i], Array[largest]);
		*Num1 += 3;
		Manage(Array, ArraySize, largest, Num1, Num2);
	}
}
void HeapSort(int *Array, int ArraySize, unsigned long long *Num1, unsigned long long *Num2)
{
	for (int i = ArraySize / 2 - 1; i >= 0; i--)
	{
		Manage(Array, ArraySize, i, Num1, Num2);
	}
	for (int i = ArraySize - 1; i >= 0; i--)
	{
		HoanVi(Array[0], Array[i]);
		*Num1 += 3;
		Manage(Array, i, 0, Num1, Num2);
	}
}

//Radix sort
//Pow
int Pow(int n, int d)
{
	if (d == 0)
	{
		return 1;
	}
	if (d == 1)
	{
		return 10;
	}
	for (int i = 2; i <= d; i++)
	{
		n *= 10;
	}
	return n;
}
//Counting sort
void CountingSort(int Array[], int ArraySize, int Division, unsigned long long *Num1, unsigned long long *Num2)
{
	//Create C array with 10 digits
	int C[10] = { 0 };

	//Create B array which contains unsorted A array's values
	int *B = new int[ArraySize];
	for (int i = 0; i < ArraySize; i++)
	{
		B[i] = Array[i];
		*Num1 += 1;
	}

	//Đếm số chữ số có phần thập phân là 10^(Division - 1) trong các phần tử của mảng Array
	for (int j = 0; j < ArraySize; j++)
	{
		int n = (Array[j] / Pow(10, Division - 1)) % 10;
		C[n] += 1;
	}

	//Đếm số phần tử có giá trị nhỏ hơn hoặc bằng i
	for (int i = 1; i <= 9; i++)
	{
		C[i] += C[i - 1];
	}
	for (int i = 0; i <= 9; i++)
	{
		C[i] -= 1;
	}

	//Đưa giá trị vào mảng xuất
	for (int j = ArraySize - 1; j >= 0; j--)
	{
		int n = (B[j] / Pow(10, Division - 1)) % 10;
		Array[C[n]] = B[j];
		*Num1 += 1;
		C[n] -= 1;
	}

	//Giải phóng vùng nhớ
	delete[] B;
}
//Radix
void RadixSort(int Array[], int ArraySize, int max, unsigned long long *Num1, unsigned long long *Num2)
{
	int n = max;
	int Division = 0;
	while (n != 0)
	{
		n /= 10;
		Division += 1;
	}
	for (int i = 1; i <= Division; i++)
	{
		CountingSort(Array, ArraySize, i, Num1, Num2);
	}
}
