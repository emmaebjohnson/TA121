#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee
{
    char name[100];
    char title;
    double hours_worked; // total number of hours worked
    double payrate;      // pay rate per hour
    double payment;      // total payment for the pay period – you will compute!
}Employee;

int main(void) {
    FILE* infile, * outfile;
    infile = fopen("lab11Payroll.txt", "r");
    outfile = fopen("lab11Paid.txt", "w");

    char title;
    double hour, rate, payment;
    Employee payroll[200];
    int numbEmployee = 0;
    char temp[100];
    double total = 0, max = 0, min = 0, average;

    for (int i = 0; !feof(infile); i++) {
        fgets(temp, 100, infile);
        //temp[strlen(temp) - 1] = 0;
        strcpy(payroll[i].name, temp);

        fgets(temp, 100, infile);
        title = payroll[i].title = temp[0];

        fgets(temp, 100, infile);
        //temp[strlen(temp) - 1] = 0;
        hour = payroll[i].hours_worked = strtod(temp, NULL);

        fgets(temp, 100, infile);
        //temp[strlen(temp) - 1] = 0;
        rate = payroll[i].payrate = strtod(temp, NULL);

        if (hour > 80) {
            if (title == 'M') {
                payment = rate * 80 + 1.8 * rate * (hour - 80);
            }
            else {
                payment = rate * 80 + 1.5 * rate * (hour - 80);
            }
        }
        else {
            payment = hour * rate;
        }
        payroll[i].payment = payment;


        if (i == 0) {
            min = payment;
            max = payment;
        }

        if (payment < min) {
            min = payment;
        }

        if (payment > max) {
            max = payment;
        }
        total += payment;

        numbEmployee++;
    }

    average = total / numbEmployee;
    fprintf(outfile, "Total: $%.2f\n", total);
    fprintf(outfile, "Average: $%.2f\n", average);
    fprintf(outfile, "Max: $%.2f\n", max);
    fprintf(outfile, "Min: $%.2f\n", min);
    printf("numb of Employee: %d\n", numbEmployee);
    for (int i = 0; i < numbEmployee; i++) {
        printf("payment: %.2f\n", payroll[i].payment);
    }


    fclose(outfile);
    fclose(infile);
    return 0;
}