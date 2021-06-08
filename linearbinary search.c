#include<stdio.h>
int binarySearch(int[],int,int,int);
void main()
{
	int array[30],i,j,n,num,choice,position=0,swap;
	printf("How many elements you want to enter the array ? ");
	scanf("%d",&n);
	printf("\nEnter %d elements in the array : ",n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&array[i]);
	}
	printf("\n\nThe array is : ");
	for(i=0; i<n; i++)
	{
		printf("%d ",array[i]);
	}
		
	printf("\n\nWhich element do you want to search in the array ? ");
	scanf("%d",&num);

	choice:

	printf("\nWhich search technique you want to use ? \n");
	printf("1) Press 1 for using linear search.\n");
	printf("2) Press 2 for using binary search.\n");
	printf("3) Press 3 to exit from the program.\n\n");
	printf("\nWhich option you want to use ? ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			{
				for(i=0; i<n; i++)
				{
					if(array[i]==num)
					{
						position = i+1;
						break;
					}
					else
					{
						position = 0;
					}
				}
				if(position!=0)
				{
					printf("%d is present at location %d\n",num,position);
				}
				else
				{
					printf("%d is not present in the array.\n",num);
				}

				break;
			}
		case 2:
			{
				for(i=0; i<n; i++)
				{
					for(j=i+1; j<n; j++)
					{
						if(array[i]>array[j])
						{
							swap = array[i];
							array[i] = array[j];
							array[j] = swap;
						}
					}
				}
				printf("In order to do binary search, the array needs to be sorted. So the sorted array is : ");
				for(i=0; i<n; i++)
				{
					printf("%d ",array[i]);
				}
				position = binarySearch(array,0,n,num);
				if(position!=0)
				{
					printf("\n%d is present at the location %d\n",num,position+1);
				}
				else
				{
					printf("\n%d is not present in the array.\n",num);
				}
				break;
			}
		case 3:
			{
				printf("\n\nExiting from the program ......\n\n");
				exit(0);
				break;
			}	
		default:
			{
				printf("\n\nInvalid choice !!\n\n");
				break;
			}
	}
	goto choice;
}

int binarySearch(int array[],int begin,int end,int item)
{
	int mid;
	if(end>=begin)
	{
		mid = (begin+end)/2;
		if(array[mid] == item)
		{
			return mid;
		}
		else if(array[mid]>item)
		{
			return binarySearch(array,begin,mid-1,item);
		}
		else
		{
			return binarySearch(array,mid+1,end,item);
		}
	}
	return 0;
}

