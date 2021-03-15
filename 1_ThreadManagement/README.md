# Thread Management Guide

<img src="images/1.png" width=500 height=300>

## Process

<img src="images/2.png" width=500 height=300>

### Context 

<img src="images/3.png" width=500 height=200>

Processor running multiple processes in a round robin manner by doing context switching

<img src="images/4.png" width=500 height=200>

### Thread

A process contains atleast 1 thread called main thread, which is the entry point for the program.

<img src="images/5.png" width=500 height=200>

Analogy

A Ship with a Captain and his crew. Crew reports to the captain.

<img src="images/6.png" width=500 height=200>

Memory

Threads of a process share the memory, whereas different processes run on seperate memory spaces.

<img src="images/7.png" width=500 height=200>

### Parallel processing

Modern computers have multiple processors (cores). With multiple cores, processes can run in parallel without context switching. 

<img src="images/8.png" width=500 height=250>

Example:  Building a House. 

The planning and laying foundation should happen sequentially. Whereas, the tasks such as plumming , drilling, carpenting, gardening, etc can be done parallelly. 

Similarly, process/task can be run parallely.
There can be different levels of parallelism:

<img src="images/9.png" width=500 height=250>

1. Task level paralellism : Where each task is doing different operation on different/same data.

2. Data level paralellism: Where each task is performing same operation on different data.

## Difference between Parallelism and Concurrency 


<img src="images/10.png" width=500 height=250>

Parallelism and Concurrency are often used interchangeably, there is a slight difference to it.

In the above image: 
Processes running on a single processor by performing context switching, gives us the notion/illusion of parallesim though it is using the processor at different time interval, this is concurrency. 

On the other hand, when each of the processes can run on different cores/processors at the same time, this is true parallelism.

## Lambda Functions

Different syntaxes of lambda function

<img src="images/11.png" width=500 height=200>


## Joinability of threads

<img src="images/12a.png" width=500 height=150>
<img src="images/12b.png" width=500 height=200>

Properly constructed threads are joinable. The word "Properly constructed" means a callable function must be passed as an argument to the thread class constructor. Ex: `std::thread thread_1(func_1)`. 

On the otherhand the default constructed thread is non joinable. Ex: `std::thread thread_2`. `thread_2` is not joinable.

<img src="images/13.png" width=500 height=100>

## Join and detach functions

### Join

<img src="images/14.png" width=500 height=200>

If thread 2 is launched from thread 1, thread 1 is blocked until the thread 2 is finished executing. 

<img src="images/15.png" width=500 height=200>


### Detach 

<img src="images/16.png" width=500 height=200>

In this case, thread 1 is not blocked when thread 2 is launched from thread 1.

<img src="images/17.png" width=500 height=200>

## Better Join Mechanism

<img src="images/18.png" width=500 height=200>