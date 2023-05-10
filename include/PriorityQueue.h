#pragma once

#include <iostream>
#include <list>
#include <exception>

/**
 * @brief The MyComparator struct
 * @details This struct is used to compare two objects of the same type.
 * The operator() is used to compare two objects of the same type.
 */
template <class T>
struct MyComparator {
    T operator()(T a, T b) const {
        return a - b;
    }
};

/**
 * @brief The PriorityQueue class
 * @details This class is a priority queue. It is a list of objects of the same type.
 * The objects are sorted by the MyComparator struct.
 */
template <class T>
class PriorityQueue {

public:
    void push(const T& t);
    T poll();

private:
    std::list<T> m_pq;
};

/**
 * @brief push
 * @details This method is used to insert an object in the priority queue.
 * @param t The object to insert.
 */
template<class T>
inline void PriorityQueue<T>::push(const T& t)
{
    auto it = m_pq.begin();
    while (it != m_pq.end() && MyComparator<T>()(*it, t) < 0 )
        advance(it, 1);
    m_pq.insert(it, t);
}

/**
 * @brief poll
 * @details This method is used to remove the first object of the priority queue.
 * @return The first object of the priority queue.
 */
template<class T>
inline T PriorityQueue<T>::poll()
{
    if (m_pq.empty())
        throw std::runtime_error("PriorityQueue empty !");
    auto last = m_pq.front();
    m_pq.pop_front();
    return last;
}
