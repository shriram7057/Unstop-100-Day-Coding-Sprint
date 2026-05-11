def find_crash_time(M1, M2):
    time = 0
    allocation = 1
    
    while True:
        time += 1
        if M1 >= M2:
            if M1 >= allocation:
                M1 -= allocation
            else:
                break
        else:
            if M2 >= allocation:
                M2 -= allocation
            else:
                break
        
        allocation += 1
    
    print(time, M1, M2)
    print(time, time + M1, time + M1 + M2)

# Read input
M1, M2 = map(int, input().split())
find_crash_time(M1, M2)