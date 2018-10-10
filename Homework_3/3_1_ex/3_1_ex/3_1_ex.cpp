#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int middle(int first, int firstIndex, int second, int secondIndex, int third, int thirdIndex)
{
	if ((second > first) && (second < third))
	{
		return secondIndex;
	}
	if ((first > second) && (first < third))
	{
		return firstIndex;
	}
	return thirdIndex;
}

int medianElement(int sortArray[], int left, int right)
{
	int sameElementsDetect = 0;
	int sameElementsFix = 0;
	int firstIndex = left;
	int firstElement = sortArray[firstIndex];
	int lastIndex = right;
	int lastElement = sortArray[lastIndex];
	if (lastElement == firstElement)
	{
		++sameElementsDetect;
		for (int i = right - 1; i > left; --i)
		{
			if (sortArray[i] != firstElement)
			{
				lastElement = sortArray[i];
				lastIndex = i;
				++sameElementsFix;
				break;
			}
		}
	}
	int middleIndex = left + 1;
	int middleElement = sortArray[middleIndex];
	if ((middleElement == lastElement) || (middleElement == firstElement))
	{
		++sameElementsDetect;
		for (int i = middleIndex; i < right; ++i)
		{
			if ((sortArray[i] != firstElement) && (sortArray[i] != lastElement))
			{
				middleElement = sortArray[i];
				middleIndex = i;
				++sameElementsFix;
				break;
			}
		}
	}
	if ((sameElementsDetect > 0) && (sameElementsFix != sameElementsDetect))
	{
		if (sameElementsDetect - sameElementsFix == 1)
		{
			return -2;
		}
		return -1;
	}
	return middle(firstElement, firstIndex, lastElement, lastIndex, middleElement, middleIndex);
}

void quickSort(int length, int sortArray[], int left, int right)
{
//	if (length <= 10)
//	{
//
//	}
//	else
//	{
	int supportElementIndex = medianElement(sortArray, left, right);
//	}
}

void inputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		scanf("%d", &block[i]);
	}
}

void outputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", block[i]);
	}
}

int main()
{
	int length = 0;
	scanf("%d", &length);
	int *sortArray = new int[length] {};
	inputArray(length, sortArray);
	outputArray(length, sortArray);
	printf("\n");
	int left = 0;
	int right = length - 1;
	quickSort(length, sortArray, left, right);
	system("pause");
	return 0;
}