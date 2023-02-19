/*
 * program.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Yucheng Chen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//print data
void print_monthly_sales (char** month_data, double* sales_data){
    printf("\nMonthly sales report for 2022:\n");
    printf("Month\tSales\n");
    
    for (int i = 0; i < 12; i++) {
        printf("%-9s%.2f\n", month_data[i], sales_data[i]);
    }
}

//print data summary
void print_sales_summary(double* sales_data) {
    char* month_data[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September","October","November","December"};
    double Avg_sales = 0;
    int Min_sales = 0;
    int Max_sales = 0;
    int Min_month = 0;
    int Max_month = 0;
    for (int i = 0; i < 12; i++) {
        Avg_sales += sales_data[i] / 12;
        if (i == 0) {
            Min_sales = sales_data[i];
            Max_sales = sales_data[i];
        } else {
            if (sales_data[i] < Min_sales) {
                Min_sales = sales_data[i];
                Min_month = i;
            }
            if (sales_data[i] > Max_sales) {
                Max_sales = sales_data[i];
                Max_month = i;
            }
        }
    }
    printf("\n\nSales Summary:\n");
    printf("Minimum Sales:%.2f (%s)\n", sales_data[Min_month], month_data[Min_month]);
    printf("Maximum sales:%.2f (%s)\n", sales_data[Max_month], month_data[Max_month]);
    printf("Average sales:%.2f\n\n", Avg_sales);
}

//6 months moving average
void six_month_avg(char** month_data, double* sales_data) {
    double average[12];
    printf("\n6-Month Moving Average Report:\n");

    for (int i = 0; i <7; i++) { //only first seven months to count
            for ( int j=i; j<(i+6); j++){
            average[i] += sales_data[j];
            }
        printf("%s-%s\t%.2f\n", month_data[i], month_data[i + 5], average[i]/6);
    }
}



void print_sales_report(char** month_data, double* sales_data) {
    printf("\nSales Report (Highest to Lowest):");
    printf("\nMonth        Sales\n");
    double temp_sales = 0;
    char* temp_month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September","October ","November","December"};
   
    for (int i = 0; i < 12; i++) {
        for (int j = i+1; j < 12; j++) {
           if(sales_data[i] < sales_data[j]) {
               temp_sales = sales_data[i];
               temp_month[i] = month_data[i];
               sales_data[i] = sales_data[j];
               month_data[i] = month_data[j];
               sales_data[j] = temp_sales;
               month_data[j] = temp_month[i];
           }
        }
    }

    for (int i = 0; i < 12; i++) {
        printf("%s\t$%.2f\n", month_data[i], sales_data[i]);
    }
}

int main()
{
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September","October ","November","December"};
    double sales[12];
    

    FILE* input_file;
    input_file = fopen("sales.txt", "r");
    if (input_file == NULL) {
        printf("ERROR opening file.\n");
        return 1 ;
    }

    char input_fileSize[100];
    char* input_fileContent;
    for(int i = 0; i < 12 && fgets(input_fileSize, 100, input_file) != NULL; i++) {
        sales[i] = strtod(input_fileSize, &input_fileContent);
    }


    print_monthly_sales(months, sales);
    print_sales_summary(sales);
    six_month_avg(months, sales);
    print_sales_report(months, sales);


    fclose(input_file);
}
