import itertools

T = int(input())
for t in range(T):
    tmp = input()
    raw = list(map(int, input().strip().split(' ')))
    a = []
    b = []
    for i, num in enumerate(raw):
        if (i % 2 == 1):
            b.append(num)
        else:
            a.append(num)
    a.sort()
    b.sort()
    c = list(itertools.chain.from_iterable(
        [[a[i], b[i]] for i in range(len(b))]))
    if len(a) > len(b):
        c.append(a[-1])

    for index, number in enumerate(c[:-1]):
        if number > c[index + 1]:
            print("Case #{}: {}".format(t + 1, index))
            exit()
            break

    print("Case #{}: OK".format(t + 1))
