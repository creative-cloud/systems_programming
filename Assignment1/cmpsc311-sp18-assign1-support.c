#include <cmpsc311-sp18-assign1-support.h>
#include <stdio.h>
#include <string.h>

/*This function contains the code for the functions that are called in main.
  These functions contain the main code.
*/

/*Function to print an array recursively*/
void P1_printArray(int array[], unsigned int low, unsigned int high)
{

	//if high is below 0, return nothing
	if(high==low-1)
		{
		  return;
		}
		P1_printArray(array,low, high-1);
		printf("%d  ",array[high]);
		return;
	
}

/*Function to reverse the characters in a string recursively*/
void P2_stringReverse(char strArray[])
{

	//if the first position in the array is null terminating string, return nothing
	if (strArray[0] == '\0')
	{
		return;
	}
	P2_stringReverse(&strArray[1]);
	printf("%c",strArray[0]);	
}

/*Function to recursively find minimum value in an array*/
int P3_recursiveMinimum(int array[], unsigned int low, unsigned int high)
{
	int min;

	//if there is only one element in the array
	if(high==1)
	{
		return array[0];
	}

	//if above statement is false, recursively find minimum value
	else
	{
		min=P3_recursiveMinimum(array,low, high-1);

		//if minis less than value at pointer, return min
		if(min<array[high-1])
		{
			return min;
		}

		//if above statement is false, return the value at pointer
		else
		{
			return array[high-1];
		}
	}
}

/*function to find the mean of values in an array*/
double P4_mean(int answer[], int SIZE)
{
	double sum=0.0;
	double m;
	int i;

	//for loop to add up the values in the array
	for(i=0; i<=SIZE; i+=1)
	{
		sum+=answer[i];
	}

	m = sum/(double)(SIZE+1);
	return m;
}

/*function to find the median of values in an array*/
double P4_median(int answer[], int SIZE)
{
	int i,j,temp;

	//nested for loop statements that iterate over 2 different values in the same array to SORT THE ARRAY
	for(i=0; i<SIZE; i++)
	{
        	for(j=i+1; j<SIZE; j++)
        	{

			//if the first value is greater than second value, switch them around
                	if(answer[i] > answer[j])
            		{
                		temp = answer[i];
                		answer[i] = answer[j];
                		answer[j] = temp;
            		}
        	}
    	}
	
	//if there are an even number of values in the array
	if((SIZE+1)%2==0)
	{
		int size1 = (SIZE+1)/2;
		int size2 = size1+1;
		int med1 = answer[size1];
		int med2 = answer[size2];
		double med = ((double)med1 + (double)med2)/2;
		return med;
	}

	//if there are odd number of values in the array
	else
	{
		int size = (SIZE+2)/2;
		double omed = answer[size];
		return omed;
	}
}

/*function to print the array values*/
void P5_print_value(int arr[], int n)
{

    //for loop iterates through each element in the array and prints it
    for(int a=0;a<5;a++)
{
    printf(" %d ",arr[a]);
}
return;
}

/*function that sorts a given array*/
void P5_function_sort(int arr[], int SIZE)
{
    int i,j,temp;

	//nested for loop that interates over two points in the same array to SORT THE ARRAY
	for(i=0; i<SIZE; i++)
	{
        	for(j=i+1; j<SIZE; j++)
        	{

			//if first value is larger than second value, switch them around
                	if(arr[i] > arr[j])
            		{
                		temp = arr[i];
                		arr[i] = arr[j];
                		arr[j] = temp;
            		}
        	}
    	}
	
    //for loop that iterated through each element in the array and prints it
    for(int a=0;a<5;a++)
	{
	    printf(" %d ",arr[a]);
	}
	
return;
}

/*function to find the intersection of two arrays
The intersection is defined as the common elements in the two arrays.*/
int P5_find_intersection(int array1[], int array2[], int intersection_array[], int SIZE)
{
    int i,j;

    //for loop that iterates over the two different arrays at the same time
    for(i=0;i<=SIZE;i++)
    {
        for(j=0;j<=SIZE;j++)
        {

	    //if the values in the two different arrays at a point are equal, it is a point of intersection of the arrays
            if(array1[i]==array2[j])
            {
                intersection_array[i] = array1[i]; //append
		printf("%d ",array1[i]);
            }
        }
    }
    return 0;
}

/*function to find the union of two arrays
The union is defined as all the elements of both the arrays, not including duplicate values*/
int P5_find_union(int array1[], int array2[], int union_array[], int SIZE)
{
    int i=0,j=0,k=0;

    //while the counters are always less than size
    while(i<SIZE && j<SIZE)
    {
	
	    //if the position in first array is less than the position in the second array, the first value is union
            if(array1[i]<array2[j])
            {
		union_array[k] = array1[i];  //append
		printf("%d ",array1[i]);
    		i++;
		k++;
            }
	
	    //if the position in first array is greater than the position in the second array, the second value is union
	    else if(array1[i]>array2[j])
            {
		union_array[k] = array2[j];  //append
                printf("%d ",array2[j]);
    		j++;
		k++;
            }

	    //if the position in first array is equal to the position in the second array, either value is union(in our case, second one is stored)
	    else
	    {
	        union_array[k] = array2[j];  //append
                printf("%d ",array2[j]);
    		j++;
		i++;
		k++;
            }
    }

    //while the first counter is less than the size of array, print rest of values in first array
    while(i<SIZE)
    {
        union_array[k] = array1[i];
        printf("%d ",array1[i]);
        i++;
        k++;
    }

    //while the second counter is less than the size of array, print rest of values in second array
    while(j<SIZE)
    {
        union_array[k] = array2[j];
        printf("%d ",array2[j]);
        j++;
        k++;
    }
    return 0;
}




