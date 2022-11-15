#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

struct List {
    string value;
    List *next;
};

// Prints the list to cout
void print(List *l) {
    while (l != NULL) {
        // As long as l is not null....
        cout << l->value;  // Print out it's value
        l = l->next;       // Move on to the next value
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

// Add an item to the list
void insertAt(List *&list, int pos, string value) {
    if (list == NULL || pos == 0) {
        list = new List{value, list};
    } else {
        List *l = list;
        while (l->next != NULL && pos > 1) {
            pos--;
            l = l->next;
        }
        l->next = new List{value, l->next};
    }
}

int main() {
    List *theList = NULL;

    // Each insertAt 0 is like prepend
    insertAt(theList, 0, "D");
    insertAt(theList, 0, "C");
    insertAt(theList, 0, "A");  // List has ACD

    //insertAt 1 will put B after A
    insertAt(theList, 1, "B");  // Now list has ABCD

    //If the position is bigger than the list it should just be at the end
    insertAt(theList, 100, "E");  // Now list has ABCDE

    //Expected Output:
    //  ABCDE
    //  The list is 5 long.
    print(theList);
    cout << endl << "The list is " << length(theList) << " long." << endl;


}