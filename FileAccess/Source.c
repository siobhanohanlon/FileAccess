#include <stdio.h>

void main()
{
	//Declare File Names
	FILE* customerFile;
	FILE* salesFile;

	//Declare Variables
	char name[30];
	char surname[30];
	int age, sales, customerID, noCustomers, counter;
	int combinedSales = 0, maxAge = 0, minAge = 150, maxSales = 0; //So anything thats added is smaller than 150 and over 0
	
	//Load info from existing files


	//Ask how many customers
	printf("Please enter the number of customers that you're entering:\t");
	scanf("%d", &noCustomers);

	//Open Customer File to append
	customerFile = fopen("Customers.txt", "a");

	//Get details for customers
	for (counter = 0; counter < noCustomers; counter++)
	{
		//Name
		printf("Please enter the Customers Name, Surname, Sales, Age and ID:\n");
		scanf("%s %s %d %d %d", &name, &surname, &sales, &age, &customerID);

		//If File is opened, print
		if (customerFile != NULL)
		{
			//Display
			printf("\n\n%s %s %d %d %d", name, surname, sales, age, customerID);
		}
		
		//Total and Max Sales
		combinedSales += sales;
		if (sales > maxSales)
		{
			maxSales = sales;
		}

		//Max Min Age
		if (age < minAge)
		{
			minAge = age;
		}
		if (age > maxAge)
		{
			maxAge = age;
		}
	}//End Loop for getting customer details

	//If File is Open
	if (customerFile != NULL)
	{
		//Close File
		fclose(customerFile);
	}

	//Open Sales file to write
	salesFile = fopen("Sales.txt", "w");

	//If File can be open
	if (salesFile == NULL)
	{
		printf("Sorry the File Could not be opened for sales info!!!");
	}

	else
	{
		//Display 
		printf("\n%d %d %d %d", combinedSales, maxSales, maxAge, minAge);

		//Close File
		fclose(salesFile);
	}
}