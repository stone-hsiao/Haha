import random

def scores(n):
    return [random.randint(0,100) for i in range(n)]

n = int(input())
print(n)
print(*scores(n))   
