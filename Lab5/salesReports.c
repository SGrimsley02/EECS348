#include <stdio.h>


void swapWord(float* arr, char words[][12], int i, int j) {
    // Swap numbers
    float temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    // Swap corresponding strings
    for (int k = 0; k < 12; k++) {
        char tempChar = words[i][k];
        words[i][k] = words[j][k];
        words[j][k] = tempChar;
    }
}

void sort(int n, float *arr, char **words) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap numbers and corresponding strings
                swapWord(arr, words, j, j + 1);
            }
        }
    }
}

int main(){
    //Get the file
    char filename[50];
    printf("File name: ");
    scanf("%s", filename);
    FILE *ptr = fopen(filename, "r");

    //Check that file is valid, end if not
    if (NULL == ptr){
        printf("File could not be opened.");
        return 0;
    }

    //Get sales numbers from file
    float sales[12];
    for (int i = 0; i < 12; i++){
        fscanf(ptr, "%f", &sales[i]);
    }

    //Monthly report
    char months[12][12] = {"January\t", "February", "March\t", "April\t", "May\t", "June\t", "July\t", "August\t", "September", "October\t", "November", "December"};
    printf("Monthly Sales Report:\n");
    for (int i=0; i<12; i++){
        printf("%s\t\t%8.2f\n", months[i], sales[i]);
    }
    printf("\n");
    //Before sorting, get 6 month averages
    float avgs[7];
    for (int i=0; i<7; i++){
        avgs[i] = (sales[i]+sales[i+1]+sales[i+2]+sales[i+3]+sales[i+4]+sales[i+5])/6.00;
    }

    //Sales Summary
    sort(12, sales, months);
    printf("Sales Summary:\n");
    printf("Minimum:\t%8.2f\t%s\n", sales[0], months[0]);
    printf("Maximum:\t%8.2f\t%s\n", sales[11], months[11]);
    float avg = (sales[0]+sales[1]+sales[2]+sales[3]+sales[4]+sales[5]+sales[6]+sales[7]+sales[8]+sales[9]+sales[10]+sales[11])/12.00;
    printf("Average:\t%8.2f\n", avg);
    printf("\n");
    //6 month averages
    printf("6 Month Moving Average Report:\n");
    printf("January\t\t- June:\t\t %8.2f\n", avgs[0]);
    printf("February\t- July:\t\t %8.2f\n", avgs[1]);
    printf("March\t\t- August:\t %8.2f\n", avgs[2]);
    printf("April\t\t- September:\t %8.2f\n", avgs[3]);
    printf("May\t\t- October:\t %8.2f\n", avgs[4]);
    printf("June\t\t- November:\t %8.2f\n", avgs[5]);
    printf("July\t\t- December:\t %8.2f\n", avgs[6]);
    printf("\n");
    //Sales Report Lowest to Highest
    printf("Sales Report, Lowest to Highest:\n");
    for (int i=11; i>=0; i--){
        printf("%s\t\t%8.2f\n", months[i], sales[i]);
    }
}