#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include <cmpsc311-sp18-assign1-support.h>


#define SIZE_PROBLEM1 10
#define SIZE_PROBLEM2 30
#define SIZE_PROBLEM3 10
#define MAXRANGE_PROBLEM3 1000

#define SIZE_PROBLEM4 100
#define SIZE_PROBLEM5 5

/* This is the main function where the functions from the support file are called.
   This is the file that is to be compiled.
*/

int main(int argc, char *argv[]) {

    printf("\n-------------------------------------------------------");
    printf("\nProblem 1 Start");

    srand(time(NULL));

    int array[SIZE_PROBLEM1];

    //for loop to create a randomly generated array
    for (unsigned int loop = 0; loop < SIZE_PROBLEM1; ++loop) {
        array[loop] = 1 + rand() % 500;
    }

    printf("\nArray values printed in main:\n");

    //for loop to print the above randomly generated array
    for (unsigned int loop = 0; loop < SIZE_PROBLEM1; ++loop) {
        printf("%d  ", array[loop]);
    }

    printf("\n\nArray values printed in printArray: \n");
    P1_printArray(array,0,SIZE_PROBLEM1-1);

    printf("\n");
    printf("\nProblem 1 End");

    printf("\n-------------------------------------------------------");
    printf("\nProblem 2 Start\n");

    char strArray[SIZE_PROBLEM2] = "Print this string backward.";

    //for loop to print the string normally
    for (unsigned int loop = 0; loop < SIZE_PROBLEM2; ++loop) {
        printf("%c", strArray[loop]);
    }
    printf("\n");
    P2_stringReverse(strArray);

    printf("\n");

    printf("\nProblem 2 End");

    printf("\n-------------------------------------------------------");
    printf("\nProblem 3 Start");

    srand(time(NULL));

    int array_p3[SIZE_PROBLEM3];

    ////for loop to create a randomly generated array
    for (unsigned int loop = 0; loop < SIZE_PROBLEM3; ++loop) {
        array_p3[loop] = 1 + rand() % MAXRANGE_PROBLEM3;
    }

    printf("\nArray members are:\n");

    //for loop to print the above randomly generated array
    for (unsigned int loop = 0; loop < SIZE_PROBLEM3; ++loop) {
        printf("%d ", array_p3[loop]);
    }

    int x=P3_recursiveMinimum(array_p3, 0, (SIZE_PROBLEM3 -1));
    printf("\nThe minimum value is: %d ",x);

    printf("\n\nProblem 3 End");

    printf("\n-------------------------------------------------------");

    printf("\nProblem 4 Start");

    //loading file to array
    int arr[300];
    int z;
    char i;
    FILE *fp=NULL;
    fp=fopen("problem4_data.txt","r");
    if(fp==NULL)
    {
        printf("%s\n","Doesn't exist");
    }
    z=0;
    while(1)
    {
	i=' ';
	i=fgetc(fp);
      if(i==EOF)
      {
        break;
      }
      if(i==',')
      {
        i=' ';
	continue;

      }
      arr[z]=i-'0';
      z++;

    }
	arr[z-1]=0;

    fclose(fp);



    int response_method1[SIZE_PROBLEM4] = { 6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
                             7, 8, 9, 5, 9, 8, 7, 8, 7, 1,
                             6, 7, 8, 9, 3, 9, 8, 7, 1, 7,
                             7, 8, 9, 8, 9, 8, 9, 7, 1, 9,
                             6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
                             7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
                             5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
                             7, 8, 9, 6, 8, 7, 8, 9, 7, 1,
                             7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
                            4, 5, 6, 1, 6, 5, 7, 8, 7, 9 };

    double mean = P4_mean(response_method1, (SIZE_PROBLEM4-1));
    printf("\nThe mean in method 1 is: %f.\n",mean);
    if(mean==6.62)
    {
	printf("Correct value.");
    }
    else
    {
        printf("Incorrect value.");
    }


    double median = P4_median(response_method1, (SIZE_PROBLEM4-1));
    printf("\nThe median in method 1 is: %f.\n",median);
    if(median==7.0)
    {
        printf("Correct value.");
    }
    else
    {
        printf("Incorrect value.");
    }

    double mean2 = P4_mean(arr, (SIZE_PROBLEM4-1));
    printf("\nThe mean in method 2 is: %f.\n",mean2);
    if(mean2==6.62)
    {
	printf("Correct value.");
    }
    else
    {
        printf("Incorrect value.");
    }

    double median2 = P4_median(arr, (SIZE_PROBLEM4-1));
    printf("\nThe median in method 2 is: %f.\n",median2);
    if(median2==7.0)
    {
        printf("Correct value.");
    }
    else
    {
        printf("Incorrect value.");
    }



    printf("\n\nProblem 4 End");
    printf("\n-------------------------------------------------------");

    printf("\nProblem 5 Start\n");

    //loading the first file to array
    FILE *fs;
    int z2=0; int arr2[80]; char j2[50]; int dec=0;
    fs=fopen("problem5_Array1.txt","r");
    if(fs==NULL)
    {
        printf("%s\n","doesn't exist" );
    }
    if(fgets(j2,50,fs)!=NULL)
    { z2=0;
        for(int i2=0; i2<strlen(j2)-1; i2++)
        {
	    if(j2[i2]==',')
	    {
		arr2[z2]=dec;
	        dec =0;
	        z2++;
	    }

    	    else
    	    {
	        dec*=10;
                dec+=j2[i2]-'0';
            }
         }
    arr2[z2]=dec;
    dec=0;
    z2++;
}
    fclose(fs);

    //loading the second file to array
    FILE *fs2;
    int z3=0; int arr3[80]; char j3[50]; int dec2 = 0;
    fs2=fopen("problem5_Array2.txt","r");
    if(fs2==NULL)
    {
        printf("%s\n","doesn't exist");
    }
    if(fgets(j3,50,fs2)!=NULL)
    { z3=0;
        for(int i2=0; i2<strlen(j3)-1; i2++)
        {
	    if(j3[i2]==',')
	    {
		arr3[z3]=dec2;
	        dec2=0;
	        z3++;
	    }

    	    else
    	    {
	        dec2*=10;
                dec2+=j3[i2]-'0';
            }
         }
    arr3[z3]=dec2;
    dec2=0;
    z3++;
}
    fclose(fs2);

int inter_array[30];
int u_array[30];

printf("\nArray 1: ");
P5_print_value(arr2, 0);

printf("\nArray 2: ");
P5_print_value(arr3, 0);

printf("\nArray 1 SORTED: ");
P5_function_sort(arr2,SIZE_PROBLEM5);


printf("\nArray 2 SORTED: ");
P5_function_sort(arr3,SIZE_PROBLEM5);


printf("\nThe intersection is: ");
P5_find_intersection(arr2, arr3, inter_array, SIZE_PROBLEM5);

printf("\nThe union is: ");
P5_find_union(arr2,arr3, u_array, SIZE_PROBLEM5);

    printf("\n\nProblem 5 End");
    printf("\n-------------------------------------------------------");
    printf("\n\n Finished \n\n");

}
