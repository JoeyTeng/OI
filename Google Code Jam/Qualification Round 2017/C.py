import math
from sys import argv

c = 0
for line in open(argv[1], 'r'):
    if c == 0:
        continue

    print line
    c += 1
    n, k = map(int, line.split())
    print (n, k)
    floor = int(math.log(k) / math.log(2)) + 1

    f_sum = n - (2 ** floor - 1)
    f_min = int(f_sum // 2 ** floor)
    f_max = f_min + 1
    f_num = int(2 ** floor)

    n_max = int(f_sum - f_num * f_min)
    n_min = int(f_num - n_max)
    f_k = k - (2 ** (floor - 1) - 1)

    max_min = min(n_max, n_min)
    if n_max > n_min:
        two_max = (n_max - n_min) // 2
        two_min = 0
    else:
        two_min = (n_min - n_max) // 2
        two_max = 0

    if f_k <= two_max:
        print("Case #%d: %d %d" %(c, f_max, f_max))
    elif f_k > two_max and f_k - two_max <= max_min:
        print("Case #%d: %d %d" %(c, f_max, f_min))
    else:
        print("Case #%d: %d %d" %(c, f_min, f_min))

print ("END")
