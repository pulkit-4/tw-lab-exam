#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 50

struct Reservation {
    int seatNumber;
    char passengerName[50];
    int age;
};

struct Reservation reservations[MAX_SEATS];
int totalReservations = 0;

void reserveSeat() {
    if (totalReservations >= MAX_SEATS) {
        printf("Sorry, all seats are booked.\n");
        return;
    }

    struct Reservation newReservation;
    printf("Enter passenger name: ");
    scanf("%s", newReservation.passengerName);
    printf("Enter passenger age: ");
    scanf("%d", &newReservation.age);

    newReservation.seatNumber = totalReservations + 1;
    reservations[totalReservations] = newReservation;

    totalReservations++;

    printf("Seat reserved successfully! Your seat number is %d.\n", newReservation.seatNumber);
}

void displayReservations() {
    printf("Seat Number\tPassenger Name\tAge\n");
    printf("----------------------------------\n");

    for (int i = 0; i < totalReservations; i++) {
        printf("%d\t\t%s\t\t%d\n", reservations[i].seatNumber, reservations[i].passengerName, reservations[i].age);
    }
}

int main() {
    int choice;

    do {
        printf("\nRailway Reservation System\n");
        printf("1. Reserve a seat\n");
        printf("2. Display reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reserveSeat();
                break;
            case 2:
                displayReservations();
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

