/*
 * Day 1 Exercise 3: Power Calculator
 *
 * TODO: Implement a program that calculates power (P = V * I)
 * and checks if it's within the maximum limit (5.0W).
 *
 * Compile with: gcc -Wall -Wextra -std=c99 -o power power.c
 * Run with: ./power
 */

#include <stdio.h>
#include "power.h"

float calculate_power(float voltage, float current) {
    return voltage * current;
}

int is_valid_power(float power) {
    return (power <= 5.0f) ? 1 : 0;
}

#ifndef UNIT_TEST
int main(void) {
    float voltage, current, power;
    float max_power = 5.0f;

    printf("Power Calculator for Chip Validation\n");
    printf("Maximum allowed power: %.1fW\n", max_power);

    printf("Enter voltage (V): ");
    if (scanf("%f", &voltage) != 1) {
        printf("Invalid voltage input\n");
        return 1;
    }

    printf("Enter current (A): ");
    if (scanf("%f", &current) != 1) {
        printf("Invalid current input\n");
        return 1;
    }

    power = calculate_power(voltage, current);
    printf("Calculated power: %.2fW\n", power);

    if (is_valid_power(power)) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
        printf("Excess power: %.2fW\n", power - max_power);
    }

    return 0;
}
#endif

