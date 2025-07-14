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
    
    // Loop backwards from the end of the string until we hit a non-whitespace character
    while (len > 0 && str[len - 1] == ' ') {
        str[len - 1] = '\0';  // Set the last character to null terminator
        len--;  // Move one character backwards
    }
}

// L6 Struct
struct Date {
  int day;
  int month;
  int year;
};

//L6 1
int findDate(int day, int month, int year, struct Date dates[], int size) {
    for (int i = 0; i < size; i++) {
        if (date[i].day == day && dates[i].month == month && dates[i].year == year) {
            return i;
        }
    }
    return -1;
}

//L6 2
int numInYear(int year, struct Date dates[], int size) {
    int count = 0; 

    for (int i = 0; i < size; i++) {
        if (dates[i].year == year) {
            count++;
        }
    }
    return count;
}

//L6 3
int cmpDates(int dayIndex1, int dayIndex2, struct Date dates[]) {
  //Compare years 1st
  if (dates[dayIndex1].year < dates[dayIndex2].year) {
      return 1;
} else if (dates[dateIndex1].year > dates[dayIndex2].year) {
      return -1;
  }

//if years are the same, compare months
if (dates[dayIndex1].month < dates[dayIndex2].month) {
    return 1;
} else if (dates[dayIndex1]/month > dates[dayIndex2].month) {
    return -1;
}

//IF months are the same, compare days
if (dates[dayIndex1].day < dates[dayIndex2].day) {
    return 1;
} else if (dates[dayIndex1].day > dates[dayIndex2].day) {
    return -1;
}

// If all components (day, month, year) are the same 
return 0;

