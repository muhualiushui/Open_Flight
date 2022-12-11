# Open_Flight
CS225 Final Project by Team BabyBus

## Github Organization
* ./Data Folder   
Include all the datasets that are using in this project

* ./Output Folder   
txt files, full output data of BFS and PageRank algorithm

* ./entry Folder    
Include main entry

* ./src Folder     
All of the source code.        
Flight_map.cpp : Our graph and main algorithm.     
Transform.cpp : Data Parsing.   

* ./tests    
Include all the tests for each algorithm

* ./results.md    
Written Report

* ./Final Presentation.md    
Include our presentation video link

## Running instructions    
* To first build and run executables   
``mkdir build``    
``cd build``    
``cmake ..``    
``make main``    
``./main``    

* To first build and run tests   
``mkdir build``    
``cd build``    
``cmake ..``    
``make test``    
``./test``    

Our function is called Open_Flight which could provide the shortest path for your flight (minimal distance will cost) and two more additional functions are output all airports and ranking airports by importance. This function has 4 different classes but only one class should be used which is Flight_map. You should input valid data into the function first. The input data is stored in the Data package. If you want to use your own data, please follow the correct format the same as the Data format shown in the Data package.    


After you prepare your data properly, you can begin to use our function. Only one step needed is to construct a Flight_map class with input from Data by following sequence: Airports, Routes, and Airline. Then you can call 3 different function:
1. BFS(int start): input:  source Airports ID    
it will return all possible airport the input airports could arrive base on the routes data    
The position of output is decided by you, get the result from the BFS which is stored in a vector and output in any place you want by the writeToFile function.    
	
2. Dijkstras(int start, int end): input:  source Airports ID and destination ID    
It will return the shortest path from source Airport to our designed destination Airport
output will shows on terminal.    

3. PageRank(int max_iter): input: iteration time base on your own Data as big as possible but the time will be longer    
It will return the importance for every airport    
The position of output is decided by you, get the result from the PageRank which is stored in a vector and output in any place you want by the writeToFile function.    
