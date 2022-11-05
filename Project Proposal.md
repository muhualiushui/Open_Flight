## Leading Question 
We chose OpenFlights as our datasets.   
We will learn that by using various graph algorithms, we can visualize the dataset which is hard to read and imagine by human minds. 
Since the problem that we want to solve is to visualize all shortest routes from different airports on the world map, we choose to use BFS, Dijkstra’s Algorithm, PageRank as our graph algorithms.
After finishing OpenFlights, our graph should be allowed to search things like a specific airline route, an airport, and so forth.

## Dataset Acquisition
#### Data Format

Considering we are preparing to do the open flights as our final project. Our data set will come from the internet totally. The data set will use routes data mainly, from 2014 across all the countries, which will be our edges of nodes. The Frequency of the single Flight will be the weight that will be used to construct our graph. On the other words, we will count the number of routes on some edge and use (1/number of routes). This would give a measure of throughput on the route.

#### Data Correction

Considering data may contain invalid information in row dimension and colum dimension. We will specifically treat both situations. ALL data will be stored in a vector as an initial database. The following discussion for avoiding error will be based on vectors. When we are dealing with data, we would put all of the data into a vector at first, a line of string will be our base unit. If there is a entry contain invalid value like “#$@” we would leave it to deal with it in the future. If we discover the entire entry is missing, we will skip it. After we complete the first step, we need to make the string into several words corresponding to the column catalog. Since All of the data are split by “ , ”, we will use it as an identifier to separate the string. One situation may happen in this process: If the separated strings are out of bound, we will throw out the entire string because it is impossible for us to know which column contains a mistake. 

Now, we have our database in vector with row and column, we can deal with invalid input such “#$@”. Since we don’t need all of the columns or catalog, if the invalid data is discovered in such a catalog, it would not affect our function. If it is discovered in our column that we will use it as input in a new function, we would throw entire rows of the data since we can not repair it.

#### Data Storage:

We will construct our graph by vector and map. As We mentioned before, our initial database will be stored into the vector and the cost would be $O(n)$ since the catalog is a constant we can treat as 1.  Then we will process our initial data by map, each airport will be a single vertex which classified data of corresponding rows in our initial database. And we will store it in a Map which will cost $O(V^2)$, since it will store every airport (#V) and all of the reachable airports(#V reachable airports for each airport) it would be. 

## Algorithm 
#### Function Inputs

The expected inputs is all the data of airport, airlines, and routes. We may need to use getLine and store them in our variable. We may use some algorithms, thoses include BFS, Dijkstra’s Algorithm, and PageRank. BFS is used for traversal the graph. Dijkstra’s Algorithm is the way that we find the shortest path. PageRank can be used to find the airports we want.

#### Function Outputs
	
The expected output will be presented as a photo which contains all of the edges (routes) and Node(airpods) based on the real world map. To archives this goal, we would use graph visualization libraries like matPLot e.g. All input data used for visualization will be stored in a Map which was mentioned in Data Storage before. Extra help classes like image construct class will be used for helping. 

#### Function Efficiency 

The time complexity of BFS is $O(V + E)$.

The time complexity of Dijkstra’s Algorithm is $O(V^2)$, but we can adjust the algorithm to reduce $O((V+E)LogV)$.

The time complexity of PageRank is $O(V+E)$.

V: Number of vertices
	
E: Number of edges on each vertex

## Timeline
#### Nov 11, 2022 

Data acquisition and Data processing

#### Nov 18, 2022 

Complete BFS Algorithm and all general class structure

#### Nov 25, 2022 

Complete Dijkstra’s Algorithm and some basic test cases

#### Dec 2, 2022	

Complete PageRank Algorithm and visualize the graph

#### Dec 8, 2022 

Complete written report, README and record presentation video
