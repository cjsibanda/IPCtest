#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Fucntion 1
int sum(const int array[], int size){
    int total = 0;
    for (int i = 0; i < size; i++)
      total += array[i];
    return total;
}

//Fucntion 2
void reverse(int array[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

//Function 3
int countChar(char ch, const char str[]){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ch){
          count++;
        }
    }
    return count;
      
}

//function 4
int countAllCase(char ch, const char str[]){
    int count = 0;

    //Convert ch to lowercase if it's uppercase
    if(ch >= 'A' && ch <= 'Z'){
        ch = ch + 32;
    } 

    for (int i = 0; str[] != '\0'; i++){
        char current = str[i];

        //Manually convert current character to lowercase if it's uppercase
        if (current >= 'A' && current <= 'Z') {
            current = current + 32;
        }

        if (current == ch){
            count++;
        }
    }
    return count;
}



//Extra 1
int findSmallest(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Extra 2
double average(int array[], int size){
    int total = sum(array, size);
    return (double)total / size;
}

//Extra 3
int linearSearch(int key, const int array[], int size){
    for (int i = 0; i < size; i++) {
        if (array[i] == key){
            return i;
        }
    }
    return -1;

}

//Extra 4 (using built in functions)
void capitalize(char str[]) {
    int newWord = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            newWord = 1;
        } else if (newWord && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            newWord = 0;
        } else {
            newWord = 0;
        }
    }
}

// Extra 5
void removeTrailingWhitespace(char str[]) {
    int len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        len--;
    }
    str[len] = '\0';
}

//Extra 5 without built in functions
/*
void removeTrailingWhitespace(char str[]) {
    int len = 0;

    // Manually find the length of the string
    while (str[len] != '\0') {
        len++;
    }

    // Move backwards to find the last non-whitespace character
    int i = len - 1;
    while (i >= 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r')) {
        i--;
    }

    // Null-terminate the string after the last non-whitespace character
    str[i + 1] = '\0';
}
*/
