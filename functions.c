#include <stdio.h>
#include <ctype.h>
#include <string.h>

L5 1
int sum(const int array[], int size){
    int total = 0;
    for (int i = 0; i < size; i++)
      total += array[i];
    return total;
}

//L5 2
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

// L6 Struct -> use for 1,2,3 & 4
struct Date {
  int day;
  int month;
  int year;
};

//L6 1
int findDate(int day, int month, int year, struct Date dates[], int size) {
    for (int i = 0; i < size; i++) {
        if (dates[i].day == day && dates[i].month == month && dates[i].year == year) {
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

//L6 3 (check this)
int cmpDates(int dayIndex1, int dayIndex2, struct Date dates[]) {
    int result = 0;

    if (dates[dayIndex1].year < dates[dayIndex2].year) {
        result = 1;
    } else if (dates[dayIndex1].year > dates[dayIndex2].year) {
        result = -1;
    } else if (dates[dayIndex1].month < dates[dayIndex2].month) {
        result = 1;
    } else if (dates[dayIndex1].month > dates[dayIndex2].month) {
        result = -1;
    } else if (dates[dayIndex1].day < dates[dayIndex2].day) {
        result = 1;
    } else if (dates[dayIndex1].day > dates[dayIndex2].day) {
        result = -1;
    }

    return result;
}


//L6 4 (no built-in functions)
//Function to print the dates in "MonthName Day, Year" format
void printDates(struct Date dates[], int size) {
    const char *months[12] = {
        "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    
    int i = 0;
    
    //Single entry point
    while (i < size) {
        int m = dates[i].month;
        if (m >= 1 && m <= 12) {
            printf("%s %d, %d\n", months[m-1], dates[i].day, dates[i].year);
        } else {
            printf("Invalid month %d for date #%d\n", m, i + 1);
        }
        i++;
    }
}

// L7 1
void makeChange(int cents, int* quarters, int* dimes, int* nickels) {
    int lastDigit = cents % 10;
    int roundedCents = cents;

    if (lastDigit == 1 || lastDigit == 2 || lastDigit == 6 || lastDigit == 7){
        roundedCents -= lastDigit % 5; //rounded down
    }
    else if (lastDigit == 3 || lastDigit == 4 || lastDigit == 8 || lastDigit == 9){
        roundedCents += 5 - (lastDigit % 5); //round up
    }

    //Calculate coins
    *quarters = roundedCents / 25;
    roundedCents = roundedCents % 25;

    *dimes = roundedCents / 10;
    roundedCents = roundedCents % 10;

    *nickels = roundedCents / 5;

    return;
}

/*
L7 2
extract the day, month and year from dateString and
store the information as integers into the DateTime struct pointed at by dt.
*/

struct DateTime {
int day;
int month;
int year;
int hour;
int minute;
};

void setDate(const char dateString[], struct DateTime* dt){
    if (dateString != NULL && dt != NULL) {
        int d1 = dateString[0] - '0'; //Tens digit of day
        int d2 = dateString[1] - '0'; //Units digit of day
        int m1 = dateString[3] - '0'; //Units digit of month

        int y1 = dateString[6] - '0';
        int y2 = dateString[7] - '0';
        int y3 = dateString[8] - '0';
        int y4 = dateString[9] - '0';

        //Combine digits into integers
        int parsedDay = d1 * 10 + d2;
        int parsedMonth = m1 * 10 + m2;
        int parsedYear = y1 * 1000 + 100 + y3 * 10 + y4;

        dt->day = parsedDay;
        dt->month = parsedMonth;
        dt->year = parsedYear;
        dt->hour = 0;
        dt-> minute = 0;
    }
}


//L7 3
/*
Function formats and prints a DateTime Struct as:
MonthName day, year hour:minute am/pm
*/
//Check this!


void printDateTime(const struct DateTime* dt){
    // Month names (1 Jan to 12 Dec)
    const char* months[12] = {
    "January", "February", "March", "April", "May", "June", "July", "August",
    "September", "October", "November", "December"
    };

    int displayHour = dt->hour;
    char period[3] = "am";

    if (dt->hour == 0)
    {
        displayHour = 12;
        period[0] = 'a'; period[1] = 'm'; period[2] = '\0';
    }
    else if (dt->hour == 12)
    {
        displayHour = dt->hour - 12;
        period[0] == 'a'; period[1] = 'm'; period[2] = '\0';
    }
    else if(dt->hour > 12)
    {
        displayHour = dt->hour - 12;
        period[0] = 'p'; period[1] = 'm'; period[2] = '\0';
    }

    //Print in the required format
    printf("%s %d, %d %d:%02d %s\n",
        monthName,
        dt->day,
        dt->year,
        displayHour,
        dt->minute,
        period
        );
}




