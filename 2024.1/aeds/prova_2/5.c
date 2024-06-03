#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Spot {
    int x;
    int y;
} Spot;

struct Person {
    struct Spot spot;
    int age;
} Person;

bool is_inside(struct Spot rect[4], struct Spot spot) {
    return spot.x > rect[0].x 
        && spot.x < rect[1].x 
        && spot.y > rect[2].y 
        && spot.y < rect[0].y;
}

int count_children_inside(struct Person *people, int n, struct Spot rect[4]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (is_inside(rect, people[i].spot) && people[i].age < 18) {
            count++;
        }
    }
    return count;
}

int main() {
    struct Person people[] = {
        {{0, 0}, 101}, 
        {{1, 1}, 27}, 
        {{2, 2}, 62},
        {{3, 3}, 13}, 
        {{4, 4}, 14}
    };
    struct Spot rect[] = {
        {0, 4}, 
        {4, 4}, 
        {0, 0}, 
        {4, 0}
    };
    printf("%d\n", count_children_inside(people, 5, rect));
}