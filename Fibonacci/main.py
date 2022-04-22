import math
import time

global time_start
global time_stop

def fib1(n):
    if n < 2:
        return n
    return fib1(n - 1) + fib1(n - 2)

def fib2(n):
    i = 1
    j = 0
    k = 1
    while (k <= n):
        j = i + j
        i = j - i
        k += 1
    return j;

def fib3(n):
    i = 1
    j = 0
    k = 0
    h = 1
    while (n > 0):
        if (n % 2) != 0:
            t = j * h
            j = i * h + j * k + t
            i = i * k + t
        t = h * h;
        h = 2 * k * h + t
        k = k * k + t
        n = n // 2
    return j

def fib(n):
    i = 1
    j = 0
    k = 0
    h = 1
    while (n > 0):
        if (n % 2) != 0:
            t = j * h
            j = i * h + j * k + t
            i = i * k + t
        t = h * h;
        h = 2 * k * h + t
        k = k * k + t
        n = n // 2;
    return j

def start():
    global time_start
    time_start = time.time() * 1000

def stop():
    global time_stop
    time_stop = (time.time() * 1000) - time_start
    return time_stop

# start()
# fib1(10)
# print("Timp de executie fib1 pentru n = 10 este de ", stop(), "milisecunde")

# start()
# fib1(40)
# print("Timp de executie fib1 pentru n = 40 este de ", stop(), "milisecunde")

# # start()
# # fib1(50)
# # print("Timp de executie fib1 pentru n = 50 este de ", stop(), "milisecunde")

# # start()
# # fib1(100)
# # print("Timp de executie fib1 pentru n = 100 este de ", stop(), "milisecunde")

# # start()
# # fib1(1000)
# # print("Timp de executie fib1 pentru n = 1000 este de ", stop(), "milisecunde")



# start()
# fib2(10)
# print("Timp de executie fib2 pentru n = 10 este de ", stop(), "milisecunde")

# start()
# fib2(40)
# print("Timp de executie fib2 pentru n = 40 este de ", stop(), "milisecunde")

# start()
# fib2(50)
# print("Timp de executie fib2 pentru n = 50 este de ", stop(), "milisecunde")

# start()
# fib2(100)
# print("Timp de executie fib2 pentru n = 100 este de ", stop(), "milisecunde")

# start()
# fib2(1000)
# print("Timp de executie fib2 pentru n = 1000 este de ", stop(), "milisecunde")



# start()
# fib3(10)
# print("Timp de executie fib3 pentru n = 10 este de ", stop(), "milisecunde")

# start()
# fib3(40)
# print("Timp de executie fib3 pentru n = 40 este de ", stop(), "milisecunde")

# start()
# fib3(50)
# print("Timp de executie fib3 pentru n = 50 este de ", stop(), "milisecunde")

# start()
# fib3(100)
# print("Timp de executie fib3 pentru n = 100 este de ", stop(), "milisecunde")

#start()
print(fib3(1000000000))
#print("Timp de executie fib3 pentru n = 1000 este de ", stop(), "milisecunde")

