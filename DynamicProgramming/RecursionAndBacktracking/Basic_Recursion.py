import numpy as np
import math

# Linear Recursion 
def Fibonacci(n):
    if n <= 1:
        return (n,0)
    else:
        (a,b) = Fibonacci(n-1)
        return (a+b, a)

def LinearSum(Array, n):
    if n == 0:
        return 0
    else:
        return LinearSum(Array, n-1) + Array[n-1]

def ReverseSequence(Array, start, stop):
    if start < stop -1:
        Array[start], Array[stop-1] = Array[stop-1], Array[start]
        ReverseSequence(Array, start + 1, stop -1)

def FindPower(Number, exponent):
    if exponent == 0:
        return 1
    else:
        partial = FindPower(Number, exponent//2)
        result = partial*partial
        if exponent%2 == 1:
            result *= Number
        return result


        # Binary recursion 
        
def binarySum(array, start, stop):
    if start >= stop:
        return 0
    elif start == stop-1:
        return array[start]
    else:
        mid = (start + stop) // 2
        return binarySum(array, start, mid)+binarySum(array, mid, stop)

def main():

    fib = Fibonacci(10)
    print(fib)

    S = list(np.random.randint(10, 100, size=20))
    print(S, "-->",LinearSum(S,len(S)))

    ReverseSequence(S, 2, 5)
    print(S)

    print(FindPower(2,5))


if __name__ == "__main__":
    main()