#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <ostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
private:
    /// Add whatever helper functions and data members you need below
    int m_;
    PComparator c_;
    std::vector<T> arr;

    // helper functions to balance heap
    void trickle_up(int index);
    void trickle_down(int index);


public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;


  // other helper functions

  // get arr
  const std::vector<T>& get_arr() const {
      return arr;
  }

  // override to print
  friend std::ostream& operator<<(std::ostream& os, const Heap<T, PComparator>& heap) {
      for (auto& item : heap.get_arr()) {
          os << item << " ";
      }
      return os;
  }


};

// Add implementation of member functions here

// constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) :
    m_(m),
    c_(c)
{

}

// destructor
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

    return arr[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
      throw std::underflow_error("Heap is empty");

  }

  // move last item to first item
  std::swap(arr[arr.size() - 1], arr[0]);

  // remove last elem
  arr.pop_back();

  // use trickle down to re-heapify
    trickle_down(0);

}

// push item into list
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item) {
    arr.push_back(item);
    trickle_up(arr.size() - 1);
}

// get size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return arr.size();
}

// see if empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return arr.empty();
}


// trickle up
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickle_up(int index) {
    if (index == 0) return;

    // get parent index
    int parent_index = (index - 1) / 2;

    // swap parent if not "better"
    if (!c_(arr[parent_index], arr[index])) {
        std::swap(arr[parent_index], arr[index]);
        trickle_up(parent_index);
    }


}


// trickle up
template <typename T, typename PComparator>
void Heap<T, PComparator>::trickle_down(int index) {
    int right = (index + 1) * 2;
    int left = right - 1;
    int best = index;

    // check if right is better
    if (right < arr.size() && c_(arr[right], arr[best])) {
        best = right;
    }

    // check if left is better
    if (left < arr.size() && c_(arr[left], arr[best])) {
        best = left;
    }

    // swap if there was a change
    if (best != index) {
        std::swap(arr[best], arr[index]);
        trickle_down(best);
    }

}

#endif

