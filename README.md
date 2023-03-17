
|       |  Subarry   |       |
| :---: | :--------: | :---: |
|  Sum  | Prefix Sum |       |
|  Min  | Mono Stack |       |
|       |            |       |

## Mono Stack



## Prefix Sum


## Subarray Target Sum

See Problem 560, very useful.


# C++ Weapons



| Function                            | Method           |       |
| :---------------------------------- | :--------------- | :---: |
| Reverse a vector                    | std::reverse     |       |
| First element less than provided    | std::upper_bound |       |
| First element greater than provided | std::lower_bound |       |
| Find string/characterin string      | std::string.find |       |
|                                     |                  |       |

# Problem

## 370. Range Addition


### Intuition

- The value in the result only changes at range boundaries
- The left boundary will contribute +inc
- The right boundary will contribute -inc

### Approach

1. Scan the ranges and calculate the contribution
2. Scan the array and calculate the running sum

### Complexity

- Time complexity: $O(M+N)$
- Space complexity: $O(N)$


## 1310. XOR Queries of a Subarray

Simple prefix XOR;

## 1074. Number of Submatrices That Sum to Target

- 2D prefix sum & subarray sum to target problem
- Time complexity $O(M^2N)$

