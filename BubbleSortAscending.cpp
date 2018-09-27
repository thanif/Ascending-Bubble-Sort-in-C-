/*Bubble sort is one of the simpler sorting algorithms. It gets its name from the way smaller elements “bubble” to the top, i.e., the beginning of the list via swaps. The idea is to put adjacent elements in the array in sorted order; look at the first two elements, swap them if necessary, then look at the second and third elements, swap if necessary, then look at the third and the fourth elements, swap if necessary, etc. After one pass through the array, the largest item will be at the end of the array. After the second pass through the array, the second largest item will be in position. After (n-1) such passes, all of the array will be sorted from smallest at the beginning of the array to largest at the end.*/

void bubble_sort_ascending(int arr[], int n)
{

	while (true)
	{
		bool swap = false;
		
		for (int i=0; i<n; i++)
		{
		
			if (arr[i] > arr[i+1])
			{
			
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				swap = true;
				
			}	
		}
		
		if (!swap)
		{
	
			break;
	
		}
		
	}
		
}
