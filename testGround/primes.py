tope = 100
primes = []
i = 2
while(i<=tope):
    done = False
    for j in primes:
        if i%j == 0:
            done = True
            break
    if done==False:
        primes.append(i)
    i = i + 1
    pass

print primes
