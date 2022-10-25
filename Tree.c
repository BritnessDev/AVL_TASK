// Implementation of the Tree ADT

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "Record.h"
#include "Tree.h"
#include "FlightDb.h"

typedef struct node *Node;
struct node {
    Record rec;
    Node   left;
    Node   right;

    // IMPORTANT: Do not modify the fields above
    // You may add additional fields below if necessary

} node;

struct tree {
    Node root;
    int (*compare)(Record, Record);

    // IMPORTANT: Do not modify the fields above
    // You may add additional fields below if necessary
    
    int size;

};

static void doTreeFree(Node n, bool freeRecords);

////////////////////////////////////////////////////////////////////////
// Provided functions
// !!! DO NOT MODIFY THESE FUNCTIONS !!!

Tree TreeNew(int (*compare)(Record, Record)) {
    Tree t = malloc(sizeof(*t));
    if (t == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    t->root = NULL;
    t->compare = compare;
    return t;
}

void TreeFree(Tree t, bool freeRecords) {
    doTreeFree(t->root, freeRecords);
    free(t);
}

static void doTreeFree(Node n, bool freeRecords) {
    if (n != NULL) {
        doTreeFree(n->left, freeRecords);
        doTreeFree(n->right, freeRecords);
        if (freeRecords) {
            RecordFree(n->rec);
        }
        free(n);
    }
}

////////////////////////////////////////////////////////////////////////
// Functions you need to implement

bool TreeInsert(Tree t, Record rec) {
	// insert into tree t the record rec
    // Return true if the record was inserted, false if it was already present in the tree
    
    // check if the tree is empty
    if (t->root == NULL) {
    	Node new = (Node)malloc(sizeof(node));
    	if(new == NULL) {
    	fprintf(stderr, "error: out of memory\n");
    	
    	exit(EXIT_FAILURE);
    	
    	}
    	
    	new->rec = rec;
    	new->left = NULL;
    	new->right = NULL;
    	t->root = new;
    	t->size = 1;


    return true;
}

//  if the tree is not empty, insert into the tree to create a BALANCED tree

// return true if inserted, false if already present

Node curr = t->root;
while (curr!= NULL) {

	// if the record is already present, return false
	if (t->compare(rec, curr->rec) == 0) {
	
	return false;
	
  }
  
  // if the record is less than the current node, go left
  
  if (t->compare(rec, curr->rec) < 0 {
  	// if the left node is empty, insert the record
  	
  	if (curr->left == NULL) {
  	Node new = malloc(sizeof(node));
  	if(new == NULL) {
  		fprintf(stderr, "error: out of memory\n");
  		
  		exit(EXIT_FAILURE);
  		
  		}
  		
  		new->rec = rec;
  		new->left = NULL;
  		new->right = NULL;
  		curr->left = new;
  		t->size++;
  		return true;
  		
  	}
  	
  	// if the node is not empty, go left
  	
  	curr = curr->left;
  	
  	}
  	
  	// if the record is greater than the current node, go right
  	
  	if (t->compare(rec, curr->rec) > 0 {
  	
  	// if the right node is empty, insert the record
  	if (curr->right == NULL) {
  		Node new = malloc(sizeof(node)); // create a new node
  		if (new == NULL) {
  		fprintf(stderr, "error: out of memory\n");
  		
  		exit(EXIT_FAILURE);
  		
  		}
  		
  		new->rec = rec;
  		new->left = NULL;
  		new->right = NULL;
  		curr->right = new;
  		t->size++; // increment size of tree
  		return true;
  		
  	}
  	
  	// if the right node is not empty, go right
  	
  	curr = curr->right;
  	
      }

   }

	return false;
	
}	

static Record doTreeSearch(Tree t, Record rec) {

// prevent memory leaks

	if (curr == NULL) {
	
    return NULL;
}


// if the current node is equal to the given record, return the record
if (t->compare(curr->rec, rec) == 0) {
	return curr->rec;
	
	}
	
	// if the current node is less than the given record, go right
	if (t->compare(curr->rec, rec) < 0 {
		return doTreeSearch(curr->right, rec, t);
		
	}
	
	// if the current node is greater than the given record, go left
	if (t->compare(curr->rec, rec) > 0 {
		return doTreeSearch(curr->left, rec, t);
		
	}
	
	return NULL;
	
}

static Record doTreeSearchFlightNumber(Node curr, Record rec, tree) {

 // prevent memory leaks
 if (curr == NULL) {
 	return NULL;
 	
 	}
 	
 	// if the current node is equal to the given record,    	return the record
 	
 	if (compareFlightNumber(curr->rec, rec) == 0 {
 	
 	return curr->rec;
 	
 	}
 	
 	// if the current node is less than the given record, go right
 	
 	if (compareFlightNumber(curr->rec, rec) < 0) {
 		return doTreeSearchFlightNumber(curr->right, rec, t);
 		
 		}
 		
 	// if the current node is greater than the given record, go left
 	if (compareFlightNumber(curr->rec, rec) {
 		return doTreeSearchFlightNumber(curr->left, rec, t);
 		
 		}
 		
 		return NULL;
 		
 	}
 	
static Record doTreeSearchDepartureAirportDay(Node curr, Record rec, Tree t) {

// prevent memory leaks
if (curr == NULL) {
	return NULL;
	
	}
	
// if the current node is equal to the given record, return the record

if (compareDepartureAirport(curr->rec, rec) == 0) {
	if (compareDepartureDay(curr->rec, rec) == 0) {
	
		return curr->rec;
		
		}
		
	if(compareDepartureDay(curr->rec, rec) > 0)
	
	{
	
		return doTreeSearchDepartureAirportDay(curr->left, rec, t);
		
		}
		
		if (compareDepartureDay(curr->rec, rec) < 0)
		
	{
	
		return doTreeSearchDepartureAirportDay(curr->right, rec, t);
		
		}
		
 }
 
 // if the current node is less than the given record, go right
 
 if (compareDepartureAirport(curr->rec, rec) < 0) {
 	return doTreeSearchDepartureAirportDay(curr->left, rec, t);
 	
 	}
 	
 	// if the current node is greater than the given record, go left
 	
 	if (compareDepartureAirport(curr->rec, rec) > 0) {
 	
 		return doTreeSearchDepartureAirportDay(curr->right, rec, t);
 		
 		}
 		
 		return NULL;
 		
 	}
 	
 Record TreeSearch(Tree t, Record rec) {
 	// prevent memory leaks
 	
 	return doTreeSearch(t->root, rec, t);
 	
 	}
 	
 Record TreeSearchFlightNumber(Tree t, Record rec) {
 	return doTreeSearchFlightNumber(t->root, rec, t);
 	
 	}
 	
 Record TreeSearchDepartureAirportDay(Tree t, Record rec) {
 	return doTreeSearchDepartureAirportDay(t->root, rec, t);
 	
 	}
 

List TreeSearchBetween(Tree t, Record lower, Record upper) {
	/* Searches the tree for all records greater than lower (inclusive) and smaller than upper (inclusive) and returns the records in a list in ascending order. Returns an empty list if there are no such records. */
	
	// The list must be freed by the caller.
	
	// if the tree is empty, return an empty list
	
	if (t->root == NULL) {

    return ListNew();
}

// if the tree is not empty, search for records

	List list = ListNew();
	Node curr = t->root;
	while (curr != NULL) {
	
// if the current node is greater than the lower bound and less than the upper bound, add it to the list

	if (compareFullDay(curr->rec, lower) >= 0) {
	
	// insert the record into the list, use ListAppend
	
	if(compareFullDay(curr->rec, upper) <= 0) {
	
		ListAppend(list, curr->rec);
		
		curr = curr->left;
		
			}
			
			else
			
				curr = curr->right;
				
		}
		
		else {
		
			curr = curr->left;
			
	      }
		
	}
	
	return list;
	
  }


Record TreeNext(Tree t, Record rec) {
	Record result;
	
	int min = 7 * 1440;
	
	Node curr = t->root;
	
		if (curr == NULL) {
	

    	return NULL;
	}


	while (curr!= NULL) {
	
	if (compareNextFullDay(curr->rec, rec) < min) {
	
		min = compareNextFullDay(curr->rec, rec);
		
		result = curr->rec;
		
		curr= curr->left;
		
		}
		
		else
		
			curr = curr->right;
			
	}
	
	RecordFree(rec);
	
	return result;
	
}



////////////////////////////////////////////////////////////////////////
