# Greedy Algorithms – Practical 2

This repository contains C++ implementations of two classic greedy algorithm problems:

1. **Coin Change Problem (Minimizing number of coins)**
2. **Activity Selection Problem (Maximizing non-overlapping activities)**

---

## 1. Coin Change Problem (Greedy Approach)

### Problem Statement
Given a set of coin denominations and an amount, find the minimum number of coins required to make the amount using the greedy approach.

---

### Algorithm Logic
1. Sort the coin denominations in descending order.  
2. Start with the largest coin and use as many as possible without exceeding the amount.  
3. Subtract the value of chosen coins from the amount.  
4. Repeat until the amount becomes `0`.

---

### Pseudocode

function coinChange(coins[], amount):
    sort coins in descending order
    count = 0
    for coin in coins:
        if amount >= coin:
            count += amount / coin
            amount = amount % coin
    return count

### Time and Space Complexity
> Sorting: O(n log n) (where n = number of coin denominations)
> Iteration: O(n)

# Overall:
> Worst Case = O(n log n)
> Best Case = Ω(n) (if already sorted and divisible early)
> Average Case = Θ(n log n)

## Space Complexity: O(1) (constant extra space, ignoring input array)

---

## 2. Activity Selection Problem (Greedy Approach)
### Problem Statement
Given n activities with start and finish times, select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

### Algorithm Logic
1. Sort all activities by their finishing times.
2. Select the first activity (earliest finishing).
3. For every next activity, check if its start time is greater than or equal to the finish time of the last selected activity.
4. If yes, select it.
5. Continue until all activities are checked.

### Pseudocode

function activitySelection(activities[]):
    sort activities by finish time
    selected = [first activity]
    lastFinish = finish time of first activity
    for i = 1 to n-1:
        if activities[i].start >= lastFinish:
            add activities[i] to selected
            lastFinish = activities[i].finish
    return selected


### Time and Space Complexity
> Sorting: O(n log n)
> Selection Loop: O(n)

## Overall:
> Worst Case = O(n log n)
> Best Case = Ω(n) (if already sorted)
> Average Case = Θ(n log n)

# Space Complexity: O(n) (to store selected activities)

### Outputs
1. Coin Change
> Enter number of coin denominations: 4
> Enter coin denominations: 1 2 5 10
> Enter amount to make change: 27
> Minimum number of coins required to make change for 27 is: 5

2. Activity Selection
> Enter number of activities: 6
> Enter start and finish times of activities:
1 3
2 5
4 6
6 7
5 9
8 10

> Maximum number of non-conflicting activities: 4
> Selected activities are:
> Activity 1 (1, 3)
> Activity 3 (4, 6)
> Activity 4 (6, 7)
> Activity 6 (8, 10)