
# S.O.L.I.D Server

"S.O.L.I.D Server"- Second Mile-Stone main achievements:

    1) Writing a server-class based on OOP SOLID principles.
    2) Writing and implementing a ClientHandler class to "translate" a given problem to a query our server can solve.
    3) Implementing general graph solvers using known algorithms.

## More on the implementation process

This **Server** gets an input of some problem and uses a given **ClientHandler** implementation to solve it. Our server design uses _dependicy injection_ to bridge the server's "lack of knowledge" about the given problem.
The **ClientHandler** interface is a _cached based_ problem solver. upon receiving a problem the **Handler** first checks it's a cache for past solutions if no prior solution is present it then uses a **Solver** class to make one, the new solution is then inserted to the cache's memory and returned to the client via the server's functionality.
The **Handler** itself is also unaware of the problem it solves, we use a pre-given _object adapter_ that takes a certain problem and "translates" it to a graph problem which our Solver knows how to deal with, we do that using a _State design pattern_.

## More on Algorithms
The Solver can be injected with a certain graph algorithm that solves a given problem based on a given _initial & goal state_ and a _cost function_ of the graph.
We implemented the following algorithms:
1. Best First Search - in our main program we use this search.
2. A-Star.
3. Depth First Search.
4. Breadth-First Search.

To see which algorithm is best for our needs, we experimentally tested several graphs with different characteristics (size, amount of paths, amount of edges, etc.) and examined the number of vertices we evaluated in each algorithm. A PDF file with the full conclusions of our experiment can be found in this repository.
![](External%20Files/AlgorithmsTest.JPG)

The best algorithm for our use came out to be BestFS.

## More on Servers implementations
our server uses a TCP/IP architecture, we created two types of servers:  
1. Serial Server - can listen to multiple clients but only deals with a single query at a time.
2. Parallel Server - can listen to multiple clients and deals with multiple queries at a time.  


## Compiling
We provide a _makefile_ to compile this project, you should use it!
To properly use this _makefile_ you should download the repository content without changing any files location.

In case you had to change the folder's path, make sure the _makefile_ resides in the outer folder alongside _main.cpp_.
Compile this program with the following command:
> make all

Alternatively (if you didn't change folders and files location), you can download source.txt from this repository and use the following command:
> make compile

notice that source.txt should reside in the same folder as the _makefile_

## Running
Our main receives a single argument which is the port number for the server to listen to.
After compiling you can run the interpreter with our provided _makefile_ using the following commands:
1. To run the provided with the default port number use:
>make run
2. To run with a port number of your choice use: 
> ./a.out _your_port_number_

## Problems input
currently, our server is given a matrix of positive numbers that represent a maze, an initial position (start point inside the maze) and a goal position (endpoint inside the maze). Those positions are described using two integers which point to their location in the matrix. The numbers in each cell in the matrix represent the cost of a step through a certain cell. To mark a cell as blocked use "-1" as it's value. 
In our implementation of the maze, one can only travel up, down, left, right.
Every matrix file should have the word "end" in it to mark the end of input.
Here is an example for a valid matrix text file:
> 14,10,16,4,17,2,11,15,5,-1

> 1,10,6,10,2,7,4,15,1,2

> 2,13,3,8,15,20,11,17,12,19

> 5,7,14,6,18,13,20,2,8,5

> 4,15,-1,20,15,7,11,12,19,2

> 4,4,18,14,16,1,-1,1,18,15

> 10,5,1,10,17,19,18,0,15,9

> 15,10,20,15,0,2,20,3,0,13

> 13,2,19,2,-1,8,-1,7,19,15

> -1,12,5,1,5,9,18,11,-1,5

> 0,0

> 9,9

> end

## Python Script
We provide a python script called_parallel_tester_ for you to easily send problems to our server. this script resides in a folder called Python Scripts inside of this repository and can be given up to 10 matrixes to send to the server.
This script works with a default port number 5600 so you should run the main program with the same port number.
Inside of the Python Script folder, you'll also find pre-built matrixes you can use or alter.
