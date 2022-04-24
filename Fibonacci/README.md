## Second implementation (recursive)

```
function fib2(n)
     i = 1; j = 0
     for k = 1 to n do  j = i + j
                        i = j - i
     return j

```

&nbsp;&nbsp;&nbsp;&nbsp;The second algorithm already involves an iterative process, which is a faster approach to solving our problem. At the same time, we will use much less memory from the stack (compared to the previous model) which allows us to exclude the phenomenon of overflow, even if the input data will be very large.

&nbsp;&nbsp;&nbsp;&nbsp;Next we will determine the execution time of the algorithm, to later determine its complexity:

```
function fib2(n)
 1:    i = 1; j = 0
 2:   for k = 1 to n do  
 3:               j = i + j
 4:               i = j - i
     return j

T(n) = c1*2 + c2 * (1 + n + 1 + 2n) + c3 * 2 * n + c4 * 2 * n=
= 2 + 2 + 3n + 4n + 2 + 2 = 4 + 7n
```

&nbsp;&nbsp;&nbsp;&nbsp;Because T (n) = 8 + n => the complexity of the algorithm is O (n), let us analyze the graph of the dependence between the data volume and the execution time for the complexity O (n):

<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164976252-b9088e27-4c50-4092-99a0-996227454288.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>
<br/>

&nbsp;&nbsp;&nbsp;&nbsp;We can see that the graph of dependence of data volume and execution time is a straight line, which means that we are dealing with a linear complexity, so the execution time of that algorithm increases in direct proportion to the size of the input data, which is a result. better compared to the recursive algorithm.

&nbsp;&nbsp;&nbsp;&nbsp;So we understand that such an approach is not exactly correct, because to calculate (fiber 5), we calculated twice (fib 3), three times (fib 2), five times fiber (1), and once with increasing the value of n, the number of repetitions will be increasing, because from what we see the number of steps increases exponentially, ie O (2n). On the other hand, the excessive use of recursion can lead to overloading the stack by exceeding its limits, and when the program tries to use more space than is available in the stack, the phenomenon of overflow also occurs, which leads to the fall. program without achieving an adequate result.
    
&nbsp;&nbsp;&nbsp;&nbsp;To visualize the behavior of the algorithm, at a large number of data, we will represent its complexity through a graph, which shows us the dependence between the data volume and the execution time:

<div align="center">
  <kbd>
    <img src="https://user-images.githubusercontent.com/60443226/164975722-817b9128-2e50-421c-afb7-72a722d9d6a1.png" alt="MarineGEO circle logo"/>
  </kbd>
</div>
<br/>

&nbsp;&nbsp;&nbsp;&nbsp;So, we can say that using that algorithm, as the input data increases, the execution time will suddenly increase, which means that this method is very inefficient.
