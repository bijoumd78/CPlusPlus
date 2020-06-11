#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-bind"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

/**
 * The following example shows several STL non-mutating algorithms that
 * check for the max and min elements in an iterator range:
 *
 * •	max: returns larger of two items, possible using a binary predicate.
 * •	max_element: finds largest item in a range, may use a binary_predicate. 
 * •	min: returns larger of two items, possible using a binary_predicate. 
 * •	min_element: finds largest item in a range, may use a binary_predicate.
 * 
 * Like find() and find_if(), they return an iterator pointing to the
 * element found. If none is found, the iterator will point to the end
 * of the range.
 * 
 * ForwardIterator
 * max_element(ForwardIterator first,
 *             ForwardIterator last)
 *  
 * ForwardIterator
 *  min_element(ForwardIterator first,
 *              ForwardIterator last)
 * 
 * Notice that max_element() and min_element() require ForwardIterators,
 * not just InputIterators because they have to save the iterator of
 * the largest or smallest element found, and InputIterators don't
 * support saving.
 *
 * The max_element() and min_element() methods above use operator< to
 * identify the biggest and smallest items.  You can also pass a
 * predicate functor to max_element() and min_element(). This
 * predicate functor takes two arguments, the current max/min and an
 * element, and return true only when the element should replace the
 * current max/min, as shown below:
 * 
 * ForwardIterator
 * max_element(ForwardIterator first,
 *             ForwardIterator last,
 *             Compare pred)
 *  
 * ForwardIterator
 * min_element(ForwardIterator first,
 *             ForwardIterator last,
 *             Compare pred)
 */

/**
 * A functor used in the example below.
 */
class max_odd {
public:
  bool operator() (int current_max, int x) {
    return (x % 2) == 1 && x > current_max;
  }
};

/**
 * Demonstrates the use of STL algorithms that check for max and min
 * elements in an iterator range.
 */
int main() {
  vector<int> stats {10, 25, 9, -30, 41, 11, -40, 67, -10};

  cout << "Looking for max number" << endl;

  // Find the max element in the range.
  auto result = max_element(stats.begin(), stats.end());
 
  if (result != stats.end())
    cout << "Max found = " <<  *result << endl;

  // Find the min element in the range.
  result = min_element(stats.begin(), stats.end());
 
  if (result != stats.end())
    cout << "Min found = " <<  *result << endl;

  // Here's how to find the largest odd number in a collection.
  result = max_element(stats.begin(), stats.end(), max_odd());
  cout << "Max odd = " << *result << endl;

  // Here's how to find the smallest odd number in a collection
  // via a C++ generic lambda function.
  result = min_element(stats.begin(), stats.end(),
                       [](int x, int current_min) {
                         return (x % 2) == 1 && x < current_min;
                       });
  cout << "Min odd = " << *result << endl;

  return 0;
}

#pragma clang diagnostic pop
