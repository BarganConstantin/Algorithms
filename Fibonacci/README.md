## Recursive implementation

```
function fib(n)
    if n < 2 then return n
    else return fib1(n-1) + fib1(n-2)
```

&nbsp;&nbsp;&nbsp;&nbsp;We notice that in this example an algorithm was chosen to achieve the condition recursively, if we work with small data this method will give us an answer correctly and of course in a relatively short time, even if they are done calculations several times, but the situation changes with the introduction of data.

&nbsp;&nbsp;&nbsp;&nbsp;In order to understand this we will represent the recursive calculation process of Fibonacci number 5 through a tree:

<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164970200-7e2c3923-48c4-4b81-8f77-2b0ba18ddcda.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>
<br/>

&nbsp;&nbsp;&nbsp;&nbsp;We can observe, that to calculate (fib 5), we calculate (fib 4) and (fib 3). To calculate (fib 4), we calculate (fib 3) and (fiber 2), and if we continue like this we get a tree, whose branches are divided in two at each level, except for the extremities.

&nbsp;&nbsp;&nbsp;&nbsp;So we understand that such an approach is not exactly correct, because to calculate (fiber 5), we calculated twice (fib 3), three times (fib 2), five times fiber (1), and once with increasing the value of n, the number of repetitions will be increasing, because from what we see the number of steps increases exponentially, ie O (2n). On the other hand, the excessive use of recursion can lead to overloading the stack by exceeding its limits, and when the program tries to use more space than is available in the stack, the phenomenon of overflow also occurs, which leads to the fall. program without achieving an adequate result.
    
&nbsp;&nbsp;&nbsp;&nbsp;To visualize the behavior of the algorithm, at a large number of data, we will represent its complexity through a graph, which shows us the dependence between the data volume and the execution time:

<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164975722-817b9128-2e50-421c-afb7-72a722d9d6a1.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>
<br/>

&nbsp;&nbsp;&nbsp;&nbsp;So, we can say that using that algorithm, as the input data increases, the execution time will suddenly increase, which means that this method is very inefficient.
