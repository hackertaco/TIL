어떤 것이 best organization? 
- access pattern에 따라 다르다. 
- cost estimation 해야한다.

## Cost model for Analysis
- B: # blocks
- R: # records per block
- D: Average time to read/write disk block

## Heap files vs Sorted files

- B: # blocks -> 5
- R: # records per block -> 2
- D: Average time to read/write disk block -> 2ms

라고 가정했을 때, 
1. Scan all records
   - Heap: B*D
   - Sorted: B*D
2. Equality Search
   - Heap의 경우, 
     - Probability that key is on page i is 1/B
     - #of pages touched if key on page i is i
     - so pages touched on average is B/2
   - Sorted의 경우,
     - worst case: log2B
     - Average case: log2B
   - Heap: 0.5B*D
   - Sorted: log2B*D
3. Range Search
   - Heap의 경우, 얼마나 많은 레코드가 있는지 알 수가 없다. 그래서 전부 다 돌아봐야한다.
   - Heap: B*D
   - Sorted: (log2B+pages)*D
4. Insert
   - Heap: Stick at the end of file
   - Sorted: Find location for record: log2BD
   - Heap: 2D (Read + write)
   - Sorted: (log2B+B)*D (일단 읽고, 다른 파일들도 옮겨주어야하기 때문) 
5. Delete
    - Heap: 일단 전체 케이스 읽는 데 B/2, Delete 하는데 1, so (B/2 + 1) * D
    - Sorted: 전체 케이스 읽는 데 log2B, 하나 삭제하면 옮겨주어야하므로 (log2B+B)*D

인덱스 이용해 좀 더 개선이 가능