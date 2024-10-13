#include <stdio.h>

#define MONTHS 12 // defines constraint for number of months 
#define FILENAME "code1.txt" // defines constraint for the file name to read sales data 

void read_sales_data(float sales[], char months[][10]) {
    FILE *file = fopen(FILENAME, "r"); // opens code1.txt

    for (int i = 0; i < MONTHS; i++) {  // loops thru each month 
        if (fscanf(file, "%f", &sales[i]) != 1) { // reads data for each month 
            printf("Error reading data for month %d\n", i + 1); // error handling
            fclose(file); // closes file
            return;
        }
    }

    fclose(file); // closes file 
    printf("Sales data read successfully.\n"); // states data was read correctly 
}

void monthly_sales_report(float sales[], char months[][10]) { // function for monthly sales report 
    printf("\nMonthly Sales Report for 2024\n");
    printf("\nMonth\t\tSales\n");
    for (int i = 0; i < MONTHS; i++) { // iterates thorugh each month 1 by 1 
        printf("%-10s\t$%.2f\n", months[i], sales[i]); // prints months/sales data 
    }
}

void summary_sales_report(float sales[], char months[][10]) {
    float min = sales[0], max = sales[0], sum = 0; // sets the min,max, sum 
    int min_month = 0, max_month = 0; // makes the min and max month intergers

    for (int i = 0; i < MONTHS; i++) {  // loop thru each month 
        if (sales[i] < min) { // checks for min 
            min = sales[i]; 
            min_month = i; // sets the min month  after checking 
        }
        if (sales[i] > max) { // checks for max 
            max = sales[i];
            max_month = i; // sets the max month after checking 
        }
        sum += sales[i]; // sets sum for calculation 
    }
    //prints all the needed info for function 
    printf("\nSales Summary Report:\n");
    printf("\nMinimum sales: $%.2f (%s)\n", min, months[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[max_month]);
    printf("Average sales: $%.2f\n", sum / MONTHS);
}

void six_month_sales_report(float sales[], char months[][10]) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++) { // finds the six month average by looping thru 
        float sum = 0; // sets sum = 0 
        for (int j = i; j < i + 6; j++) {  // uses a loop to calculate average for 6 months 
            sum += sales[j]; // adds sum average for 6 months
        }
        printf("%s-%s\t$%.2f\n", months[i], months[i+5], sum / 6); // prints the average
    }
}

void sales_report_high_low(float sales[], char months[][10]) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("\nMonth\t\tSales\n");

    // creates an array of indices
    int indices[MONTHS]; // 
    for (int i = 0; i < MONTHS; i++) {
        indices[i] = i;
    }

    // sorts indices based on sales (descending order)
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sales[indices[j]] < sales[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    // prints sorted sales
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t$%.2f\n", months[indices[i]], sales[indices[i]]);
    }
}


int main() {
    float sales[MONTHS];  
    char months[MONTHS] [10] = {"January" , "Febuary", "March", "April", "May", "June"
    , "July", "August", "September" , "October", "November", "December"} ;
    read_sales_data(sales, months); // calls sales data function 
    monthly_sales_report(sales, months); // calls montly sales report function 
    summary_sales_report(sales, months); // calls summary sales report function 
    six_month_sales_report(sales, months); // six month report function 
    sales_report_high_low(sales, months); // high to low report function 

    return 0;
}