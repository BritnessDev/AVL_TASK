// Implementation of the Flight DB ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FlightDb.h"
#include "List.h"
#include "Tree.h"

struct flightDb {

};

FlightDb DbNew(void) {
    return NULL;
}

void DbFree(FlightDb db) {

}

bool DbInsertRecord(FlightDb db, Record r) {
    return false;
}

List DbFindByFlightNumber(FlightDb db, char *flightNumber) {
    return ListNew();
}

List DbFindByDepartureAirportDay(FlightDb db, char *departureAirport,
                                 int day) {
    return ListNew();
}

List DbFindBetweenTimes(FlightDb db, 
                        int day1, int hour1, int min1, 
                        int day2, int hour2, int min2) {
    return ListNew();
}

Record DbFindNextFlight(FlightDb db, char *flightNumber, 
                        int day, int hour, int min) {
    return NULL;
}

