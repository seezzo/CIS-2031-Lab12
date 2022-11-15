#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

struct List {
  string value;
  List *next;
};

// Prints the list to cout
void print(List *l) {
  while (l != NULL) {
    // As long as l is not null....
    cout << l->value << endl; // Print out it's value
    l = l->next;              // Move on to the next value
  }
}

// Returns the number of items in the list
int length(List *l) {
  int length = 0;
  while (l != NULL) {
    l = l->next;
    length++;
  }
  return length;
}

//Add an item to the list
void insertAt(List* &list, int pos, string value){
    if ( list == NULL || pos == 0 ){
        list = new List{value, list};
    } else {
        List* l = list;
        while( l->next != NULL && pos > 1 ){
            pos--;
            l = l->next;
        }
        l->next = new List{value, l->next};
    }
}

int main() {
  List *theList = NULL;
  insertAt(theList, 100, "A");
  insertAt(theList, 100, "B");
  insertAt(theList, 100, "C");
  insertAt(theList, 100, "D");
  print(theList);
  cout << "The list is " << length(theList) << " long." << endl;
}