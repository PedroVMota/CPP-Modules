#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <utility>


#ifndef COLORS_H
#define COLORS_H

#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */

#endif

class PmergeMe
{
private:
    //arr in a deque
    std::deque<double> m_container;
    //arr in a map
    std::map<double, double> m_map;
    //arr in a queue
    std::queue<double> m_queue;
    //arr in a set
    std::set<double> m_set;
    size_t m_size;
    std::string m_str;

public:
    PmergeMe(std::string str) : m_container(), m_str(str)
    {
        std::istringstream iss(str);
        std::string selector;
        while (std::getline(iss, selector, ' '))
            m_container.push_back(std::stod(selector));
        m_size = m_container.size();
        for (size_t i = 0; i < m_container.size(); ++i)
            m_map.insert(std::pair<double, double>(m_container[i], m_container[i]));
        for (size_t i = 0; i < m_container.size(); ++i)
            m_queue.push(m_container[i]);
        std::cout << "Before: ";
        for(std::deque<double>::iterator it = m_container.begin(); it != m_container.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    };

    void fordJohnsonSortDeque();
    void fordJohnsonSortMap();
    void fordJohnsonSortQueue();
    void fordJohnsonSortSet();
    ~PmergeMe(){};
};

void PmergeMe::fordJohnsonSortDeque()
{
    clock_t start = clock();
    for (size_t i = 0; i < m_container.size(); ++i)
        for (size_t j = i + 1; j < m_container.size(); ++j)
            if (m_container[j] < m_container[i])
                std::swap(m_container[i], m_container[j]);
    clock_t end = clock();
    std::cout << "After: ";
    for(std::deque<double>::const_iterator it = m_container.begin(); it != m_container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    long long us = (end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << m_size << " elements with std::deque: " << us << "us" << std::endl;
}

void PmergeMe::fordJohnsonSortMap()
{
    clock_t start = clock();
    std::multimap<double, double> sortedMap;

    for (std::map<double, double>::iterator it = m_map.begin(); it != m_map.end(); ++it)
        sortedMap.insert(std::make_pair(it->second, it->first));
    m_map.clear();
    for (std::multimap<double, double>::iterator it = sortedMap.begin(); it != sortedMap.end(); ++it)
        m_map.insert(std::make_pair(it->second, it->first));
    clock_t end = clock();
    long long us = (end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << m_size << " elements with std::map: " << us << "us" << std::endl;
}

void PmergeMe::fordJohnsonSortQueue()
{
    clock_t start = clock();
    std::vector<double> sortedQueue;
    while (!m_queue.empty())
    {
        sortedQueue.push_back(m_queue.front());
        m_queue.pop();
    }
    std::sort(sortedQueue.begin(), sortedQueue.end());
    for (size_t i = 0; i < sortedQueue.size(); ++i)
        m_queue.push(sortedQueue[i]);
    clock_t end = clock();
    long long us = (end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << m_size << " elements with std::queue: " << us << "us" << std::endl;
}


void PmergeMe::fordJohnsonSortSet()
{
    clock_t start = clock();
    std::vector<double> sortedSet;
    for (std::set<double>::iterator it = m_set.begin(); it != m_set.end(); ++it)
        sortedSet.push_back(*it);
    std::sort(sortedSet.begin(), sortedSet.end());
    m_set.clear();
    for (size_t i = 0; i < sortedSet.size(); ++i)
        m_set.insert(sortedSet[i]);
    clock_t end = clock();
    long long us = (end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << m_size << " elements with std::set: " << us << "us" << std::endl;
}

