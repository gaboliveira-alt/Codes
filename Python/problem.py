while True:
    n = int(input())
    if n == 0:
        break
    
    while n > 0:
        n -= 1
        line = input().strip()
        print(line)
        