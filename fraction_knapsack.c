#include<stdio.h>
#include<stdlib.h>

typedef struct items
{
	char name[20];
	float weight;
	float profit;
	float ratio;
	float fraction;
};

//Function to solve knapsack
void knapsack(unsigned int n, struct items object[], float capacity)
{
	float total_profit = 0;
	unsigned int i;
	
	for(i=0; i<n; i++)
	{
		if(object[i].weight > capacity)
			break;
		else
		{
			object[i].fraction = 1.0;
			total_profit += object[i].profit;
			capacity -= object[i].weight;
		}
	}
	if( i<n )
		object[i].fraction = capacity / object[i].weight;
	total_profit += (object[i].fraction * object[i].profit);

	printf("\n==========Printing Results==========\n");
	printf("Total profit = %.2f\n",total_profit);
	printf("Order of items with their % = ");
	for(i=0; i<n; i++)
		printf("%s (%.2f\%) --> ",object[i].name, object[i].fraction*100);
}

int main(void)
{
	//Input for Bag capacity
	float capacity;
	printf("Enter bag's capacity: ");
	scanf("%f",&capacity);

	//Input for number of items
	unsigned int n;
	printf("Enter total number of items: ");
	scanf("%d",&n);

	struct items item[n];
	
	//Input object details from user 
	printf("Enter Asked Details:\n");	
	for(unsigned int i=0; i<n; i++)
	{
		printf("==========Item No. %d ==========\n",i+1);
		printf("Item Name: ");
		scanf("%s",item[i].name);
		printf("Weight: ");
		scanf("%f",&item[i].weight);
		printf("Profit: ");
		scanf("%f",&item[i].profit);
	}

	//Initializing Ratio and Fraction Used
	for(unsigned int i=0; i<n; i++)
	{
		item[i].ratio = item[i].profit / item[i].weight;
		item[i].fraction = 0.0;
	}

	//Arranging items in Descending Ratio order
	for(unsigned int i=0; i<n; i++)
	{
		for(unsigned int j=i+1; j<n; j++)
		{
			if( item[i].ratio < item[j].ratio )
			{
				struct items temp = item[i];
				item[i] = item[j];
				item[j] = temp;
			}
		}
	}
	
	//Solving knapsack problem
	knapsack(n, item, capacity);

	return 0;
}

	

				
