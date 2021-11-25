#include <stdio.h>

void main()
{
	//Declare File Names
	FILE* customerFile;
	FILE* salesFile;

	//Declare Variables
	char name[30];
	char surname[30];
	int age, sales, customerID, noCustomers, counter, numInputs;
	int combinedSales = 0, maxAge = 0, minAge = 150, maxSales = 0; //So anything thats added is smaller than 150 and over 0

	//Random- used so number will always change
	srand(time(NULL));
	
	//Load info from existing files
	//Customer File
	//Read
	customerFile = fopen("Customers.txt", "r");

	//Check if File is Open
	if (customerFile == NULL)
	{
		printf("Sorry the Customer File could not be opened!!!\n");

		//Exit
		exit(0);
	}

	else
	{
		//Read to end of file
		while (!feof(customerFile))
		{
			//Count how many Lines
			numInputs = fscanf(customerFile, "%s %s %d %d %d", name, surname, &sales, &age, &customerID);

			//Display according to numInputs
			if (numInputs == 5)
			{
				printf("Customer:%s %s Sales:%d Age:%d ID:%d\n", name, surname, sales, age, customerID);
			}
		}

		//Close file
		fclose(customerFile);
	}

	//SalesFile
	//Customer File
	//Read
	salesFile = fopen("Sales.txt", "r");

	//Check if File is Open
	if (salesFile == NULL)
	{
		printf("Sorry the Sales File could not be opened!!!\n");

		//Exit
		exit(0);
	}

	else
	{
		//Count how many Lines
		fscanf(salesFile, "%d %d %d %d", &combinedSales, &maxSales, &maxAge, &minAge);

		//Close file
		fclose(salesFile);

		//Display according to numInputs
		printf("Inital Total Sales: %d Max Sales: %d Oldest: %d Youngest: %d\n", combinedSales, maxSales, maxAge, minAge);
	}


	//Ask how many customers
	printf("\nPlease enter the number of customers that you're entering:\t");
	scanf("%d", &noCustomers);

	//Open Customer File to append
	customerFile = fopen("Customers.txt", "a");

	//Get details for customers
	for (counter = 0; counter < noCustomers; counter++)
	{
		//Name
		printf("\n\nPlease enter the Customers Name, Surname, Sales and Age:\n");
		scanf("%s %s %d %d", name, surname, &sales, &age);

		//Random Number
		customerID = rand();

		//Display
		printf("Customer:%s %s Sales:%d Age:%d ID:%d", name, surname, sales, age, customerID);

		//If File is opened, print
		if (customerFile != NULL)
		{
			//Display
			fprintf(customerFile, "%s %s %d %d %d\n", name, surname, sales, age, customerID);
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

	//Display 
	printf("\n\n\nTotal Sales:%d Max Sales:%d Oldest:%d Youngest:%d", combinedSales, maxSales, maxAge, minAge);

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
		fprintf(salesFile,"%d %d %d %d", combinedSales, maxSales, maxAge, minAge);

		//Close File
		fclose(salesFile);
	}

	//Skip Lines
	printf("\n\n");
}