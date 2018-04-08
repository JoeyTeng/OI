# a = list(map(int, input().split(' ')))
for n in range(10):
    a = list(range(n, 0, -1))
    change = True
    while change:
        change = False
        for i in range(len(a) - 2):
            if (a[i] > a[i + 2]):
                a[i], a[i + 2] = a[i + 2], a[i]
                change = True
    print(a)
