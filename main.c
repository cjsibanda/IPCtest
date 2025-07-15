#include <stdio.h>
#include "functions.h"

int main() {
    int array1[] = {1, 2, 3, 1};
    printf("Sum: %d\n", sum(array1, 4));

    //testing

    int array2[] = {2, 1, 3, 4, 7, 6};
    reverse(array2, 6);
    printf("Reversed: ");
    for (int i = 0; i < 6; i++) printf("%d ", array2[i]);
    printf("\n");

    char mystring[] = "the quick brown Fox jumped\tOver r2d2 but c 3po was\n Too tall";
    printf("countChar('t'): %d\n", countChar('t', mystring));
    printf("countAllCase('o'): %d\n", countAllCase('o', mystring));

    int array3[] = {9, 4, 7, 2, 5};
    printf("Smallest: %d\n", findSmallest(array3, 5));
    printf("Average: %.2f\n", average(array3, 5));
    printf("Search 7: Index = %d\n", linearSearch(7, array3, 5));

    char capStr[] = "the quick brown Fox jumped\tover r2d2 but c 3po was\n too tall";
    capitalize(capStr);
    printf("Capitalized: %s\n", capStr);

    char wsStr[] = "hello  \t world \n\t\n";
    removeTrailingWhitespace(wsStr);
    printf("Trimmed: \"%s\"\n", wsStr);

    //test findDate
    //Example array of Date structs
    struct Date dates[] = {
     {25, 12, 2023},
     {1, 1, 2022},
     {15, 8, 2021},
     {4, 7, 2024}
    };

    int size = sizeof(date) / sizeof(dates[0]);

    //call findDate function
    int index = findDate(15, 8, 2021, dates, size);

    if (index != -1) {
        printf("Date found at index: %d\n", index);
    } else {
        printf("Date not found\n");
    }

    //Call numInYear function
    int year = 2023;
    int count = numInYear(year, dates, size);

    printf("Number of dates in year %d: %d\n", year, count);

    //Test the cmpDates function
    int result = cmpDates(0, 4, dates);

    //Output based on comaparison
    if (result == 0) {
        printf("dates[0] is the same as dates[4]\n");
    } else if (result == 1) {
        printf("dates[0] is earlier than dates[4]\n");
    } else if ("result == -1") {
        printf("dates[0] is later than dates[4]\n");
    }


    //Test L6 4 printDate
    struct Date dates[3] = {
        {1, 1, 2024},
        {2, 9, 2023},
        {24, 11, 2024}
    };
    
    printDates(dates, 3);
    
    return 0;
}
