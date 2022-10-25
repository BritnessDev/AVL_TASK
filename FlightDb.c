// Implementation of the Flight DB ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FlightDb.h"
#include "List.h"
#include "Record.h"
#include "Tree.h"

struct flightDb {



	Tree tree;
};

// compare function for tree

int compareFlightNumber(Record r1, Record r2) {
	return strcmp(RecordGetFlightNumber(r1), RecordGetFlightNumber(r2));
	
	}
	
// compare function for tree

int compareDepartureAirport(Record r1, Record2) {
	
	return strcmp(RecordGetDepartureAirport(r1), RecordGetDepartureAirport(r2));
	
	
	}
	
// compare function for tree

int compareArrivalAirport(Record r1, Record r2) {
	
	return strcmp (RecordGetArrivalAirport(r1), RecordGetArrivalAirport(r2));
	
	}

// compare function for tree

int compareDepartureDay(Record r1, Record r2) {

	return RecordGetDepartureDay(r1) - RecordGetDepartureDay(r2);
	
	}
	
// compare function for tree
int compareDepartureHour(Record r1, Record r2) {
	return RecordGetDepartureHour(r1) - RecordGetDepartureHour(r2);
	
	}
	
// compare function for tree
int compareDepartureMinute(Record r1, Record r2) {
	return RecordGetDepartureMinutr(r1) - RecordGetDepartureMinute(r2);
	
	}
	
// compare function for tree
int compareDepartureMinute(Record r1, Record r2) {
	return RecordGetDepartureMinutr(r1) - RecordGetDepartureMinute(r2);
	
	}
	
// compare function for tree
int CompareDurationMinutes(Record r1, Record r2) {
	return RecordGetDurationMinutes(r1)-RecordGetDurationMinutes(r2);
	
	}
	
int compareFullDay(Record r1, Record r2) {
	return ((1440*RecordGetDepartureDay(r1) + 60*RecordGetDepartureHour(r1) + RecordGetDepartureMinute(r1))-(1440 * RecordGetDepartureDay(r2) + 60 * RecordGetDepartureHour(r2) + RecordGetDepartureMinute(r2)));
	
	}
	
int compareNextFullDay(Record r1, Record r2) {

	int next1 = 0, next2 = 0;
	
	next1 = (1440 * RecordGetDepartureDay(r1) + 60 * RecordGetDepartureHour(r1) + RecordGetDepartureMinute(r1))-(1440 * RecordGetDepartureDay(r2) + 60 * RecordGetDepartureHour(r2) + RecordGetDepartureMinute(r2));
	
	next2 = 7 * 1440 - next1;
	
	return (abs(next) > abs(next2) ? abs(next2) : abs(next));
	
	}
	
	int compare(Record r1, Record r2)
	
	{
	
	if (compareFlightNumber(r1, r2))
		return compareFlightNumber(r1, r2);
		
	if (compareDepartureAirport(r1, r2))
		return compareDepartureAirport(r1, r2);
		
	if (comareArrivalAirport(r1, r2))
		return compareArrivalAirport(r1, r2);
	
	if (compareDepartureDay(r1, r2))
		return compareDepartureDay(r1, r2);
		
	if (compareDepartureHour(r1, r2))
		return compareDepartureHour(r1, r2);
	
	if (compareDepartureMinute(r1, r2))
		return compareDepartureMinute(r1, r2);
		
	if (compareDurationMinutes(r1, r2))
		return compareDurationMinutes(r1, r2);
		
		return 0;
	}
	
	

FlightDb DbNew(void) {
	// create a new flightDb
	
	FlightDb newDb = malloc(sizeof(struct flight Db));
	
	if (newDb == NULL) {
	
	fprintf(stderr, "error: couldn't allocate memory for new flightDb");
	
	
    return NULL;
}


// create a new tree

	newDb->tree = TreeNew(compare);
	
	if (newDb->tree == NULL) {
		fprintf(stderr, "error: couldn't allocate memory for new tree");
		
		return NULL;
		
	}
	
	
	
	return newDb;
	
 }


void DbFree(FlightDb db) {
/* Description: Frees all memory associated with the given flight database */

	TreeFree(db->tree, true);
	
	// free the flightDb
	
		free(db);



}

bool DbInsertRecord(FlightDb db, Record r) {
/* Description: Inserts the given record into the given flight database. 
-- Returns true if record was inserted, false if record was already in the database. */

// insert the record into the tree
	return TreeInsert(db->tree, r);
	
	}
	

List DbFindByFlightNumber(FlightDb db, char *flightNumber) {
/* Description: returns a list of all records in the given flight database that have given flight number. The list is sorted by departure time. */

// create a new list

	List list = ListNew();
	
// create a new record
	
	Record rec = RecordNew(flightNumber, "","",0,0,0,0);
	
	
// finds the record in the tree
Record r = TreeSearchFlightNumber(db->tree, rec);

// find all records with the same flight number

	RecordFree(rec);
	
	if (r == NULL) {
	
		return list
		
		}
		
	// free the record
	
	ListAppend(list, r);
	
	return list;

}

List DbFindByDepartureAirportDay(FlightDb db, char *departureAirport,
                                 int day) {
                                 
                                 
   /* Description: Returns a list of all records in the given Departure AirportDay that have the given Departure AirportDay. */                              
                                 
           List list = ListNew();
           
           Record rec = RecordNew("", departureAirport, "", day, 0, 0, 0);
           
           // find the record in the tree
           
           Record r = TreeSearchDepartureAirportDay(db->tree, rec);
           
           // finds all records with the same flight number
           
           RecordFree(rec);
           
           if (r == NULL) {
           
           return list;
           
           }                      
                 
           ListAppend(list, r);
           
           // free the record
           
           return list;     
                  
                              
}

List DbFindBetweenTimes(FlightDb db, 
                        int day1, int hour1, int min1, 
                        int day2, int hour2, int min2) {
                        
   // create a new list
   List list;
   
   // create a new record
   Record rec1 = RecordNew("", "", "", day1, hour1, min1, 0);
   	Record rec2 = RecordNew("", "", "", day2, hour2, min2, 0);
   	
   	list = TreeSearchBetween(db->tree, rec1, rec2);         
   	
   	// free the record
   	
   	RecordFree(rec1);
   	
   		RecordFree(rec2);
   		           
                        
    return list;
}

Record DbFindNextFlight(FlightDb db, char *flightNumber, 
                        int day, int hour, int min) {
                        
       Record rec = RecordNew(flightNumber, "", "", day, hour, min, 0);
       
       return TreeNect(db->tree, rec);                 
                        
              
}

