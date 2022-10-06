#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>> class Heap {
  public:
    /**
     * @brief Construct a new Heap object
     *
     * @param m ary-ness of heap tree (default to 2)
     * @param c binary predicate function/functor that takes two items
     *          as an argument and returns a bool if the first argument has
     *          priority over the second.
     */
    Heap(int m = 2, PComparator c = PComparator());

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
    T const& top() const;

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

  private:
    int m;
    PComparator c;
    std::vector<T> items;
    void trickle_up(int i);
    void trickle_down(int i);
    /// Add whatever helper functions and data members you need below
};

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m{m}, c{c} {}

template <typename T, typename PComparator> Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
    items.push_back(item);
    trickle_up(size() - 1);
}

// We will start top() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator>
T const& Heap<T, PComparator>::top() const {
    // Here we use exceptions to handle the case of trying
    // to access the top element of an empty heap
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("");
    }
    // If we get here we know the heap has at least 1 item
    // Add code to return the top element
    return items[0];
}

// We will start pop() for you to handle the case of
// calling top on an empty heap
template <typename T, typename PComparator> void Heap<T, PComparator>::pop() {
    if (empty()) {
        // ================================
        // throw the appropriate exception
        // ================================
        throw std::underflow_error("");
    }
    items.front() = items.back();
    items.pop_back();
    trickle_down(0);
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    return items.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return items.size();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickle_up(int i) {
    if (i == 0) {
        // Base case: at the root node
        return;
    }
    int p = (i - 1) / m;
    if (c(items[i], items[p])) {
        std::swap(items[i], items[p]);
        trickle_up(p);
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickle_down(int i) {
    int min_child = m * i + 1;
    if ((unsigned)min_child >= size()) {
        // There are no children
        return;
    }
    for (int child = m * i + 2; child <= m * i + m; child++) {
        if ((unsigned)child >= size()) {
            break;
        }
        if (c(items[child], items[min_child])) {
            min_child = child;
        }
    }
    if (c(items[min_child], items[i])) {
        std::swap(items[min_child], items[i]);
        trickle_down(min_child);
    }
}

#endif
