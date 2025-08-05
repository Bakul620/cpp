#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the first day of the year
int first_day_of_year(int year)
{
    return (year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
}

// Function to display the Bangla calendar
// https://bangla.plus/bangla-calendar-1432/
void Bangla()
{
    printf("Enter your favorite (Bangla) Year : ");
    char *Month[] = {"Boishakh", "Joishtho", "Ashar", "Shrabon", "Bhadro", "Ashwin", "Kartik", "Ogrohayon", "Poush", "Magh", "Falgun", "Chaitro"};
    int days_in_Month[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 29, 30};
    int year;
    scanf("%d", &year);
    year = year + 594;

    // Adjust for leap year
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        days_in_Month[10] = 30;

    printf("\n          Welcome to the Year %d  \n\n", year - 594);
    int weekdays = (first_day_of_year(year - 1) + 103) % 7;
    year--;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        weekdays = (weekdays + 1) % 7;
    for (int i = 0; i < 12; i++)
    {
        printf("------------------- %s ---------------------", Month[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");

        // Print leading spaces for the first day
        for (int space = 1; space <= weekdays; space++)
            printf("      ");

        // Print all days of the month
        for (int j = 1; j <= days_in_Month[i]; j++)
        {
            printf("%6d", j);
            weekdays++;
            if (weekdays > 6)
            {
                weekdays = 0;
                printf("\n");
            }
        }
        printf("\n\n");
    }
}

void English()
{
    char *Month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int days_in_Month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int year;
    printf("Enter your favorite (English) Year : ");
    scanf("%d", &year);

    printf("\n          Welcome to the Year %d \n\n", year);

    int i, j, total_days, weekdays = 0, space;

    // Adjust for leap year
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        days_in_Month[1] = 29;

    weekdays = first_day_of_year(year);
    for (i = 0; i < 12; i++)
    {
        printf("------------------- %s ---------------------", Month[i]);
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
        total_days = days_in_Month[i];
        // Print leading spaces for the first day
        for (space = 1; space <= weekdays; space++)
            printf("      ");

        // Print all days of the month
        for (j = 1; j <= total_days; j++)
        {
            printf("%6d", j);
            weekdays++;
            if (weekdays > 6)
            {
                weekdays = 0;
                printf("\n");
            }
        }
        printf("\n\n");
    }
}

// Function to calculate the starting day of the week for a Hijri year
int calculateStartDay(int hijriYear)
{
    // Reference: 1 Muharram 1 AH (Hijri) corresponds to Friday (5th day of the week)
    int referenceYear = 1;
    int referenceDay = 5; // Friday

    // Calculate the total number of days between the reference year and the given year
    int totalDays = 0;
    for (int year = referenceYear; year < hijriYear; year++)
    {
        totalDays += ((11 * year + 14) % 30 < 11) ? 355 : 354;
    }

    // Calculate the starting day of the week
    int startDay = (referenceDay + totalDays) % 7;
    return startDay;
}

// Function to print a month in calendar format
// https://www.islamicfinder.org/islamic-calendar/
void Arabic()
{
    int hijriYear;
    printf("Enter your favorite (Hijri) year: ");
    scanf("%d", &hijriYear);
    const char *months[] = {
        "Muharram", "Safar", "Rabi' al-awwal", "Rabi' al-thani",
        "Jumada al-awwal", "Jumada al-thani", "Rajab", "Sha'ban",
        "Ramadan", "Shawwal", "Dhu al-Qi'dah", "Dhu al-Hijjah"};

    int daysInMonth[] = {30, 29, 30, 29, 30, 29, 30, 29, 30, 29, 30, 29};

    // Adjust for leap year
    if ((((11 * hijriYear + 14) % 30) < 11))
    {
        daysInMonth[11] = 30; // Dhu al-Hijjah has 30 days in a leap year
    }

    printf("\n             Welcome to the Year %d\n\n", hijriYear);

    int startDay = calculateStartDay(hijriYear);

    for (int i = 0; i < 12; i++)
    {
        printf("------------------- %s ---------------------\n", months[i]);
        printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
        for (int space = 1; space <= startDay; space++)
        {
            printf("      ");
        }
        for (int day = 1; day <= daysInMonth[i]; day++)
        {
            printf("%6d", day);
            if ((startDay + day) % 7 == 0)
            {
                printf("\n");
            }
        }
        startDay = (startDay + daysInMonth[i]) % 7;
        printf("\n\n");
    }
}

int main()
{
    printf("\n--- Which Calendar you want to see ---\n");
    while (1)
    {
        printf("\n1. Bangla\n2. English\n3. Arabic\n4. Exit \n");
        printf("Choice : ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Bangla();
            break;
        case 2:
            English();
            break;
        case 3:
            Arabic();
            break;
        case 4:
            exit(0);
        default:
            printf("You Entered the wrong Choice.Please Correct.\n");
            break;
        }
    }
    return 0;
}