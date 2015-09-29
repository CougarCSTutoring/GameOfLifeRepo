from math import sqrt


def is_prime(x, primes):
    root_x = sqrt(x)
    for prime in primes:
        if prime > root_x:
            break
        if x % prime == 0:
            return False
    return True


def n_primes(n):
    primes = []
    x = 2
    while len(primes) < n:
        if is_prime(x, primes):
            primes.append(x)
        x += 1
    return primes

print(n_primes(10000))