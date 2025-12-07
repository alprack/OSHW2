# OSHW2
Anna Prack Assignment 2 for Operating Systems

Program Description:
This program demonstrates the Banker's Algorithm. This algorithm is used to determine if a computer has enough resources to allocate to a set of processes.

The program utilizes 2d vectors to make the necessary matrices. There is an "allocation" matrix, indicating how much of each type of resource each process has been given. The "max" matrix represents how much of each resource each process will need. The allocation matrix is subtracted from the max matrix to create the "need" matrix, representing how much *more* of each resource each process requires. Finally, there is an "available" vector to represent how many of each resource the computer has available. 

If a current processes' needed resources are more than the available resources, the process could fail to run, resulting in a deadlock.

After a process is finished, its' allocated resources can be added to the available resources. This means the order of processes can be reordered to avoid deadlock. This program determines if there is an order of processes to avoid deadlock (a "safe state"), and outputs the order of processes to safely run.

Is the provided system in a safe state?
Yes

What is the safe sequence?
P3, P4, P1, P2, P0

Usage Instructions:
(Note: I ran this on my windows machine using WSL and Unbuntu)

1) Download files from repository and navigate to directory in terminal

2) Compile program using:
	g++ bankers.cpp -o bankers

3) Run program using:
	./bankers input.txt

You can create your own input file. 
First provide the number of processes (ex: 5) and number of resource types (ex: 3)

From there, insert the entire allocation matrix
	0 1 0
	2 0 0
	3 0 2
	2 2 1
	0 0 2
Followed by the max matrix
	7 5 3
	3 3 2
	9 0 2
	2 2 2
	4 3 3
Finally, the available vector
	3 2 2

(Note: newlines are for readability)

Examples & Results:
See results.png
