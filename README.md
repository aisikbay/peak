# Peak (Divide & Conquer)
Problem: Consider an array of n values that has this property: The values in the array increase up to some index p, 0≤p<n-1, and then decrease for all indices beyond p through n-1. 
Problem: Find the value p at which the peak occurs. Read input values from a 'peak.txt' file as integers, one per line.<br>

## Example
>Input: list={-1, 1, 2, 4, 3, 0}
>Output: Peak of 4 found at index 3
<p>
<img src="https://github.com/aisikbay/peak/assets/94331548/88831c01-9a45-42b0-a0f1-924594fb43d8"></img><br>
In the example above, the peak of 4 occurs at index 3.
</p>

## Approach
This is a recursive binary search approach, where at every iteration the number of potential answers is halved. 
* _Time Complexity_: _O($log{_2}{N}$)
* _Space Complexity_: _O($log{_2}{N}$)

