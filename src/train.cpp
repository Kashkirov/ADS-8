// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() {
    first = nullptr;
    countOp = 0;
}
void Train::addCage(bool light) {
    Cage* last = new Cage;
    Cage* cage = new Cage;
    Cage* reserved = new Cage;
    if (first == nullptr) {
        first = reserved;
        first->light = light;
        first->next = first;
        first->prev = first;
        return;
    }
    last = first;
    last->next = first->next;
    cage->light = light;
    while (last->next != first) {
        last = last->next;
    }
    first->prev = cage;
    cage->prev = last;
    last->next = cage;
    cage->next = first;
    reserved->next = nullptr;
    reserved->prev = nullptr;
    delete reserved;
}
int Train::getLength() {
    int len = 0;
    int steps = 0;
    Cage* reserved = new Cage;
    reserved = first;
    reserved->next = first->next;
    reserved->prev = first->prev;
    if (!first->light) {
        first->light = true;
    }
    while (1) {
        reserved = reserved->next;
        steps++;
        countOp++;
        if (reserved->light) {
            reserved->light = false;
            int backup = steps;
            while (steps) {
                reserved = reserved->prev;
                --steps;
                countOp++;
            }
            if (!first->light) {
                return backup;
            }
        }
    }
    return 0;
}
int Train::getOpCount() {
    return countOp;
}
