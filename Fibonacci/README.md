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
