# DSA-Unit-4-TREE
# Voter ID Management System Using Binary Search Tree (BST)

## 1. Project Overview

The Voter ID Management System is a menu-driven C++ application that uses a Binary Search Tree (BST) to store and manage voter IDs.

The project compares two BSTs constructed using different insertion orders:
- Sorted Voter IDs
- Shuffled Voter IDs

It calculates the height of both trees, displays voter IDs using inorder traversal, and searches for a specific voter ID while counting the number of comparisons required.

## 2. Problem Statement

To design and implement a Voter ID Management System using a Binary Search Tree in C++. The system stores unique voter IDs and compares the performance of BSTs constructed using sorted and shuffled insertion orders. It supports displaying voter IDs, calculating tree heights, and searching for voter IDs.

## 3. Objectives

- To understand the concept of a Binary Search Tree.
- To insert voter IDs into a BST.
- To prevent duplicate voter IDs.
- To construct BSTs using sorted and shuffled insertion orders.
- To calculate and compare the heights of two BSTs.
- To display voter IDs using inorder traversal.
- To search for a voter ID and count the comparisons.
- To understand the effect of insertion order on BST performance.


## 4. Features

1. **Enter Voter IDs:** Accepts voter IDs from the user.
2. **Duplicate Handling:** Ignores duplicate voter IDs.
3. **Build BSTs:** Creates two BSTs using sorted and shuffled voter IDs.
4. **Display Heights:** Displays the height of both BSTs.
5. **Display Voter IDs:** Prints voter IDs using inorder traversal.
6. **Search Voter ID:** Searches for an ID in both trees.
7. **Comparison Counting:** Displays the number of comparisons made during each search.
8. **Exit:** Terminates the program.

## 5. How It Works

### Step 1: Enter Voter IDs
The user enters the number of voter IDs and their values. Duplicate IDs are ignored.

### Step 2: Build BSTs
The program sorts the IDs and creates the first BST using sorted insertion order. It shuffles the original IDs and creates the second BST using shuffled insertion order.

### Step 3: Calculate Tree Heights
The program calculates and displays the heights of both BSTs.

### Step 4: Display Voter IDs
Inorder traversal displays the voter IDs in ascending order.

### Step 5: Search Voter ID
The user enters an ID to search. The program reports whether the ID exists and displays the number of comparisons made in each BST.

## 6. Sample Input

```text
Enter your choice: 1
How many voter IDs? 5
Enter ID 1: 40
Enter ID 2: 20
Enter ID 3: 60
Enter ID 4: 10
Enter ID 5: 30
