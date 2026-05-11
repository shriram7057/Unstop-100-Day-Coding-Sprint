# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input().strip())
s = input().strip()

vowels = set("aeiou")
result = []
i = 0

while i < n:
    if s[i] in vowels:
        j = i
        
        # Find length of consecutive vowels
        while j < n and s[j] in vowels:
            j += 1
        
        vowel_seq = s[i:j]
        result.append(vowel_seq)
        
        # Add '$' only if exactly 2 consecutive vowels
        if len(vowel_seq) == 2:
            result.append('$')
        
        i = j
    else:
        result.append(s[i])
        i += 1

print("".join(result))