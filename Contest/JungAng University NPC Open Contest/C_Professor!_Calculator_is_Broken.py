from decimal import *

n = int(input())
for _ in range(n):
    a, b = list(map(Decimal, input().split()))
    print(f"{a * b:.18f}")