# 📘 C++ Data Structures & Algorithms Overview

This document provides concise explanations and usage examples of fundamental C++ data structures and algorithms. Use it as a quick reference or study guide.

---

## 🚀 Algorithms in C++

C++ supports various algorithmic paradigms, often through the STL and custom implementations:

- **Sorting**: `std::sort(vec.begin(), vec.end());`
- **Searching**: `std::binary_search(vec.begin(), vec.end(), target);`
- **Recursion**: Common in divide-and-conquer approaches like merge sort
- **Dynamic Programming**: Often implemented with memoization via arrays or `std::unordered_map`
- **Greedy Algorithms**: Used in optimization problems like activity selection

---

## 🧰 Core Data Structures

### Stack
- **Concept**: Last In First Out (LIFO)
- **Example**: `std::stack<int> st;`
- **Use Cases**: Function call stack, undo operations

### Queue
- **Concept**: First In First Out (FIFO)
- **Example**: `std::queue<int> q;`
- **Use Cases**: BFS, scheduling

### Priority Queue
- **Concept**: Elements sorted by priority
- **Example**: `std::priority_queue<int> pq;`
- **Use Cases**: Dijkstra's algorithm, task managers

### Deque
- **Concept**: Double-ended queue
- **Example**: `std::deque<int> dq;`
- **Use Cases**: Sliding window, palindrome checking

### List
- **Concept**: Doubly linked list
- **Example**: `std::list<int> lst;`
- **Use Cases**: Frequent insertions/removals

### Vector
- **Concept**: Dynamic array
- **Example**: `std::vector<int> nums;`
- **Use Cases**: Fast access and iteration

### Map
- **Concept**: Key-value pair, ordered
- **Example**: `std::map<string, int> scoreMap;`
- **Use Cases**: Dictionaries, frequency counters

### Unordered Map
- **Concept**: Hash-based key-value store
- **Example**: `std::unordered_map<string, int> hashMap;`
- **Use Cases**: Faster lookups (non-ordered)

### Set
- **Concept**: Unique, ordered elements
- **Example**: `std::set<int> s;`
- **Use Cases**: Sorting + uniqueness

### Unordered Set
- **Concept**: Unique, hash-based
- **Example**: `std::unordered_set<int> us;`
- **Use Cases**: Fast membership testing

### Smart Pointers
- **Concept**: Automatic memory management
- **Examples**:
  - `std::unique_ptr<int> p = std::make_unique<int>(10);`
  - `std::shared_ptr<int> sp = std::make_shared<int>(20);`
- **Use Cases**: Avoid manual `new` and `delete`

---

## 📊 Comparison Table

| Structure          | Time Complexity (Avg)               | Best Use Case                                |
|--------------------|-------------------------------------|----------------------------------------------|
| Stack              | Push/Pop: O(1), Access: O(n)        | Undo features, recursion                     |
| Queue              | Enqueue/Dequeue: O(1), Access: O(n) | Task scheduling                              |
| Priority Queue     | Insert/Delete: O(log n)             | Pathfinding, priorities                      |
| Deque              | Insert/Delete both ends: O(1)       | Sliding window problems                      |
| List               | Insert/Delete: O(1), Search: O(n)   | Frequent modifications                      |
| Vector             | Access: O(1), Insert End: O(1), Insert Middle: O(n) | Most general-purpose array replacement |
| Map                | Access/Insert: O(log n)             | Sorted key-value storage                     |
| Unordered Map      | Acce2ss/Insert: O(1)                 | Faster lookups with hash-based keys          |
| Set                | Insert/Search: O(log n)             | Keep unique items in sorted order            |
| Unordered Set      | Insert/Search: O(1)                 | Fast uniqueness checking                     |
| Smart Pointers     | N/A                                 | Safe and automatic memory management         |

---

## ✅ When to Use What?

- Choose **`std::vector`** for fast and flexible arrays.
- Use **`std::list`** when you need quick insertions/removals.
- Pick **`std::map`** or **`std::unordered_map`** for key-value associations.
- Apply **`std::stack`**, **`std::queue`**, or **`std::priority_queue`** for specialized access patterns.
- Try **`std::set`** or **`std::unordered_set`** to manage unique elements.
- Use **smart pointers** to handle dynamic memory without manual cleanup.

---
