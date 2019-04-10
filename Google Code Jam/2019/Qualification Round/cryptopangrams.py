# @Author: Joey Teng
# @Email:  joey.teng.dev@gmail.com
# @Filename: cryptopangrams.py
# @Last modified by:   Joey Teng
# @Last modified time: 10-Apr-2019


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
        letter = [0 for i in digits]

        start_index = -1
        for index, i in enumerate(digits[:-1]):
            key = gcd(i, digits[index + 1])
            # print("gcd({}, {}) = {}".format(i, digits[index + 1], key))
            if (key != i and key != digits[index + 1]):
                # Prevent ABA-like patters.
                # This would resulted in two same consecutive ciphertexts
                start_index = index
                letter[index] = digits[index] // key
                letter[index + 1] = key
                primes.add(letter[index])
                primes.add(letter[index + 1])
                # print("Key: {}".format(key))
                break

        # print("Start index: {}".format(start_index))
        # print("letter: {}".format(letter))

        for index in range(start_index - 1, -1, -1):
            letter[index] = digits[index + 1] // letter[index + 1]
            # print("letter[{}] = {}".format(index, letter[index]))
            primes.add(digits[index] // letter[index + 1])

        for index in range(start_index + 1, len(digits)):
            letter[index] = digits[index - 1] // letter[index - 1]
            # print("letter[{}] = {}".format(index, letter[index]))
            primes.add(digits[index - 1] // letter[index - 1])

        # print(sorted(primes))
        mapping = {}
        for index, i in enumerate(sorted(list(primes))):
            mapping[i] = chr(ord('A') + index)
        ans = ''.join([mapping[i] for i in letter])

        print("Case #{0}: {1}".format(t, ans))


if __name__ == '__main__':
    main()
