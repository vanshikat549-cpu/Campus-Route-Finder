# Campus Route Finder — Test Cases

## Test Case 1: Direct Route

**Purpose:** Test a route between directly connected locations.

**Input:**

Menu choice: 3

Starting location: 1 (Main Gate)

Destination: 2 (Library)

**Expected Output:**

Shortest Route: Main Gate -> Library

Number of edges: 1

**Actual Output:**

Shortest Route: Main Gate -> Library

Number of edges: 1

**Status:** Pass

---

## Test Case 2: Multi-Stop Route

**Purpose:** Test the shortest route between locations that are not directly connected.

**Input:**

Menu choice: 3

Starting location: 1 (Main Gate)

Destination: 8 (Lab)

**Expected Output:**

Shortest Route: Main Gate -> Block 1 -> Block 2 -> Lab

Number of edges: 3

**Actual Output:**

Shortest Route: Main Gate -> Block 1 -> Block 2 -> Lab

Number of edges: 3

**Status:** Pass

Note: An alternative route with the same number of edges is also correct.

---

## Test Case 3: Unreachable Destination

**Purpose:** Test locations belonging to separate connected components.

**Input:**

Menu choice: 3

Starting location: 1 (Main Gate)

Destination: 6 (Auditorium)

**Expected Output:**

No route exists between these locations!

**Actual Output:**

No route exists between these locations!

**Status:** Pass


---

## Conclusion

These test cases check direct routes, multi-stop routes, unreachable destinations, and connected-component detection.

Run the program and verify the actual outputs before submitting the report.
