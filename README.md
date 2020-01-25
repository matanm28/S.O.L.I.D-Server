
# S.O.L.I.D Server

"S.O.L.I.D Server"- Second Mile-Stone main achievements:

    1) Writing a server class based on OOP SOLID principales.
    2) Writing and implementing an ClientHandler class to
	  "translate" a given problem to query our server can solve.
    3) Implementing a genral graph solvers using known algorithms.

## Extra Details

This **Server** gets an input of some problem and uses a given **ClientHandler** implemention to solve it. Our server design uses _dependicy injection_ to bridge the server's "lack of knowladge" about the given problem.
The **ClientHandler** interface is a _cached based_ problem solver. upon recieveing a problem the **Handler** first checks it's cache for past solutions if no prrior solution is present it then uses a **Solver** class to make one, the new solution is then inserted to the cache's memory and returned to the client via the server's functionlty.
The **Handler** itself is also unaware to the problem it solves, we use a pre given _object adapter_ that takes a certain problem and "translates" it to a graph problem which our Solver knows how to deal with, we do that using a _State design pattern_.

## More on Algorithms
The Solver can be injected with a certain graph algorithm which solves a given problem based on a given _initial & goal state_ and a _cost function_ of the graph.
We implemented the following algorithms:
1. Best First Search - in our main program we use this search.
2. A-Star.
3. Depth First Search.
4. Breath First Search.

To see which algorithm is best for our uses, we experimentally tested several graphs with different characteristics (size, amount of tracks, amount of arcs, etc.) and examined the number of vertices we evaluated in each algorithm. A PDF file with the full conclusions of our experiment can be found in this repository.
![](flight-gear%20menu.png)

The best algorithm for our use came out to be BestFS.

## More on Servers implemetions
We created to types of server's:  
1. Serial Server - can listen to multiple clients but only deals with a single query at a time.
2. Parllel Server - can listen to multiple clients and deals with multiple querys at a time.  


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
The interpreter receives a single argument which is the path of a text file containing the code you'll want to run.
Notice that if the text file resides in the same folder as _a.out_ you only need to add its name.

After compiling you can run the interpreter with our provided _makefile_ using the following commands:
1. To run the provided _fly.txt_ file use:
>make run
2. To run the provided _fly_with_func.txt_ file use: 
>make runFunc

3. To run with your own writen code use:
> ./a.out _your_code_file_name.txt_

## Python Script
