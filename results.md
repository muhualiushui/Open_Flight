# Written Report
## The output and correctness of each algorithm
### BFS Algorithm
BFS is used to traverse all the airports that have a route. That is, whenever you enter the ID of an airport, BFS takes that point as the starting point and outputs a vector with all the points. So, as long as the input ID is valid (with a route). Then, the final output will be the same length in the end (3199).
Here are two examples:

``1.`` 3830<br>
``2.`` 49<br>
``3.`` 73<br>
.<br>
.<br>
.<br>
``3197.`` 7157<br>
``3198.`` 7241<br>
``3199.`` 1032<br>

``1.`` 6740<br>
``2.`` 2750<br>
``3.`` 7356<br>
.<br>
.<br>
.<br>
``3197.`` 1032<br>
``3198.`` 7157<br>
``3199.`` 7241<br>

Obviously, the two examples have different inputs (3830 & 6740). But they both traverse the entire graph to find the right nodes (airports).


### Dijkstra’s Algorithm
Dijkstra’s Algorithm is used to solve the shortest path issue we face in Open Flight. It takes two input elements which are starting airport and end airports. To make sure the correctness, Dijkstra’s algorithm is test by 6 different cases in which 3 of them are invalid input and should return nothing and others are valid input should return a list of airports’ names.

### PageRank Algorithm
The PageRank funtion takes in one parameter which is the iteration number that the user likes to set to. The larger iteration number produces smaller error. Then the function calculates the importance rank for each airport and outputs a map to store all the rank. There is helper writeToFile function for the PageRank to write the map into a txt file. The running time is $O(N^2)$, where the N is the total number of airports.    

Here is a sample of PageRank visualization:    

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

The larger rank number means that the airport is more important.

The full visualization output is in ./Output/PageRank_output.txt.    

There are two test cases for PageRank Algorithm:    
* "test_matrix_multiply_small"     
Ensure the helper funtion matrix_multiply can multiply the adjcent matrix with a vector correctly.

* "test_PageRank"     
Ensure the PageRank Algorithm can produce the desirable results for a smaller data set.

## Leading Question Answer
By utilizing OpenFlights datasets, we successfully contruct a program to give the shortest path between two aiports. In our initial leading question, we said to visulize the shorteset path but end up with just the shortest path due to time shortage. Besides, our program allows to produce the importance rank of all airporst and a full world airports traversal.
