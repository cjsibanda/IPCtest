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

    return 0;
}
