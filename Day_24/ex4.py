def spaceship_fleets(k, pos, speed):

    ships = list(zip(pos, speed))

    ships.sort(reverse=True)

    fleets = 0
    max_time = 0

    for position, spd in ships:

        time = (k - position) / spd

        if time > max_time:
            fleets += 1
            max_time = time

    return fleets
def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    n = int(data[0])  # First input is the integer 'n'
    k = int(data[1])  # Second input is the integer 'k'
    pos = list(map(int, data[2:n+2]))  # Third input is the array of current distances
    speed = list(map(int, data[n+2:2*n+2]))  # Fourth input is the array of speeds
    
    # Call user logic function and print the output
    result = spaceship_fleets(k, pos, speed)
    print(result)

if __name__ == "__main__":
    main()