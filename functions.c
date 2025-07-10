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
        if (str[i] == ch)
          count++;
    }
    return count;
      
}

//function 4
int countAllCase(char ch, const char str[]){
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (tolower(str[i]) == tolower(ch))
          count++;
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

//Extra 4
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
