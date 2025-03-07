#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include "stack.h"
#include "heap.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}



void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------



class Compare {
public:
    bool operator()(int val) {
        return val < 10;
    }
};


Node* makeList(std::vector<int> list, int index=0) {
    if (index < list.size()) {
        return new Node(list[index], makeList(list, index + 1));
    }
    return nullptr;
}



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    Node* list = makeList({2,4});
    Node* small = (Node*) &list; // set to a non-null address
    Node* large = (Node*) &list; // set to a non-null address
    llpivot(list, small, large, 3);
    print(small);
    print(large);
    print(list);
    std::cout << "___" << std::endl;

////    // part 1
//    Node* smaller = nullptr;
//    Node* larger = nullptr;
//    llpivot(head, smaller, larger, 1);
//    std::cout << "smaller" << std::endl;
//    print(smaller);
//    std::cout << "larger" << std::endl;
//    print(larger);

    Compare comp;
    Node* res = llfilter(head, comp);

//    print(res);


    // test stack
//    Stack<int> stack;
//    stack.push(3);
//    stack.push(5);
//    stack.pop();
//    int top = stack.top();
//    std::cout << top << std::endl;;


    // test heap
//    Heap<int> h(3);
//    h.push(5);
//    h.push(3);
//    h.push(2);
//    h.push(12);
//    h.push(22);
//    h.push(33);
//    h.push(5);
//    h.pop();
//    h.push(2);
//    h.push(1);
//    h.push(40);
//    h.pop();
//    h.pop();
//    std::cout << h << std::endl;

    
    return 0;

}
