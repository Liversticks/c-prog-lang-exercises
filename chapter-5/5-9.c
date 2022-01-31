static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int positiveRemainder(int dividend, int divisor) {
    if (dividend >= 0) {
        return dividend % divisor;
    }
    else {
        return ((dividend / divisor) * divisor) - dividend;
    }
}

int day_of_year(int year, int month, int day) {
    // assumption: negative years are allowed
    int leap = positiveRemainder(year, 4) == 0 && positiveRemainder(year, 100) != 0 || positiveRemainder(year, 400) == 0;
    if (month < 1 || month > 12 ) {
        return -1;
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day < 1 || day > 31)) {
        return -1;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && (day < 1 || day > 30)) {
        return -1;
    }
    if (month == 2 && !leap && (day < 1 || day > 28)) {
        return -1;
    }
    if (month == 2 && leap && (day < 1 || day > 29)) {
        return -1;
    }
    char * temp;
    for (int i = 1; i < month; i++) {
        temp = *(daytab + leap);
        day += *(temp + i);
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    if (pmonth && pday) {
        int leap = positiveRemainder(year, 4) == 0 && positiveRemainder(year, 100) != 0 || positiveRemainder(year, 400) == 0;
        if (leap && (yearday > 366 || yearday < 1)) {
            return;
        }
        if (!leap && (yearday > 365 || yearday < 1)) {
            return;
        }
        int month;
        for (month = 1; yearday > *(*(daytab + leap) + month); month++) {
            yearday -= *(*(daytab + leap) + month);
        }
        *pmonth = month;
        *pday = yearday;
    }
}

#include <stdio.h>

int main() {
    int a = day_of_year(2000, 5, 19);
    int amonth;
    int aday;
    month_day(2000, a, &amonth, &aday);
    printf("%d %d\n", amonth, aday);

    int b = day_of_year(2000, 2, 29);
    int bmonth;
    int bday;
    month_day(2000, b, &bmonth, &bday);
    printf("%d %d\n", bmonth, bday);
}