# @Author: Joey Teng
# @Email:  joey.teng.dev@gmail.com
# @Filename: cryptopangrams.py
# @Last modified by:   Joey Teng
# @Last modified time: 06-Apr-2019


def gcd(a, b):
    if (a % b == 0):
        return b
    return gcd(b, a % b)


def main():
    T = int(input())
    for t in range(1, T + 1):
        n, l = [int(i) for i in input().split(' ')]
        digits = [int(i) for i in input().split(' ')]
        primes = set()
        letter = []

        first = digits[0] // gcd(digits[0], digits[1])
        letter.append(first)
        primes.add(first)
        for i in digits:
            letter.append(i // letter[-1])
            if (letter[-1] == 0):
                print("ERROR")
                return
            primes.add(letter[-1])

        print(sorted(primes))
        mapping = {}
        for index, i in enumerate(sorted(list(primes))):
            mapping[i] = chr(ord('A') + index)
        ans = ''.join([mapping[i] for i in letter])

        print("Case #{0}: {1}".format(t, ans))


if __name__ == '__main__':
    main()
