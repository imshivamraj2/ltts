#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void calculateTimeDifference(struct Time t1, struct Time t2, struct Time* diff) {
    int secondsDiff, minutesDiff, hoursDiff;

    secondsDiff = t2.seconds - t1.seconds;
    minutesDiff = t2.minutes - t1.minutes;
    hoursDiff = t2.hours - t1.hours;

    if (secondsDiff < 0) {
        secondsDiff += 60;
        minutesDiff--;
    }

    if (minutesDiff < 0) {
        minutesDiff += 60;
        hoursDiff--;
    }

    diff->hours = hoursDiff;
    diff->minutes = minutesDiff;
    diff->seconds = secondsDiff;
}

int main() {
    struct Time startTime, endTime, difference;

    printf("Enter start time (hours minutes seconds): ");
    scanf("%d %d %d", &(startTime.hours), &(startTime.minutes), &(startTime.seconds));

    printf("Enter end time (hours minutes seconds): ");
    scanf("%d %d %d", &(endTime.hours), &(endTime.minutes), &(endTime.seconds));

    calculateTimeDifference(startTime, endTime, &difference);

    printf("\nTime Difference: %d hours, %d minutes, %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
