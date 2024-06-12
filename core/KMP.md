## KMP algorithm

### Preprocessing the Pattern
The algorithm preprocesses the pattern to create the LPS(longest prefix suffix) array. 
The LPS array stores the length of the longest proper prefix of the pattern that is also a suffix. This helps in
determining the number of characters to be skipped in case of a mismatch

### Pattern Matching
The algorithm uses the LPS array to avoid re-examining characters that have already been matched.
When a mismatch occurs, the algorithm uses the LPS array to determine the next positions to match,
thus optimizing the search process.
