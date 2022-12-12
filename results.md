# Written Report
## The output and correctness of each algorithm
### BFS Algorithm

### Dijkstra’s Algorithm

### PageRank Algorithm
The PageRank funtion takes in one parameter which is the iteration number that the user likes to set to. The larger iteration number produces smaller error. Then the function calculates the importance rank for each airport and outputs a map to store all the rank. There is helper writeToFile function for the PageRank to write the map into a txt file. The running time is $O(N^2)$, where the N is the total number of airports.    

Here is a sample PageRank visualization:    

``airport: 3380``   
``rank: 32.039``   
``airport: 7895``   
``rank: 1.80368``   
``airport: 2808``   
``rank: 5.82483``   
``airport: 3787``   
``rank: 0.0104119``   
``airport: 12037``   
``rank: 0.0104119``

The full visualization output is in ./Output/PageRank_output.txt.    

There are two test cases for PageRank Algorithm:    
* "test_matrix_multiply_small"     
Ensure the helper funtion matrix_multiply can multiply the adjcent matrix with a vector correctly.

* "test_PageRank"     
Ensure the PageRank Algorithm can produce the desirable results for a smaller data set.

## Leading Question Answer
By utilizing OpenFlights datasets, we successfully contruct a program to give the shortest path between two aiports. In our initial leading question, we said to visulize the shorteset path but end up with just the shortest path due to time shortage. Besides, our program allows to produce the importance rank of all airporst and a full world airports traversal.
