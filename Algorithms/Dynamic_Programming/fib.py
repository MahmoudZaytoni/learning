def fib(n, mem):
    if (n <= 1):
        return 1
    if not n in mem:
        mem[n] = fib(n-1, mem) + fib(n-2, mem)
    return mem[n]


mem = {}
n = int(input())
fibon = fib(n, mem)
print(fibon)
    