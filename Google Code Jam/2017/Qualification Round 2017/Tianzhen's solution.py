import math
#Modify
from sys import argv
f = open(argv[1])
#f = open("C-large.in")
#ModifyEnd
line = []
for l in f:
    line.append(l.strip())
c = 0
for l in line[1:]:
    c += 1
    temp = l.split()
    n = int(temp[0])
    k = int(temp[1])
    floor = int(math.log(k) / math.log(2)) + 1
##    print("floor: {}".format(floor))
    f_sum = n - (2 ** floor - 1)
##    print("f_sum: {}".format(f_sum))
    f_min = int(f_sum // 2 ** floor)
##    print("f_min: {}".format(f_min))
    f_max = f_min + 1
##    print("f_max: {}".format(f_max))
    f_num = int(2 ** floor)
##    print("f_num: {}".format(f_num))
    n_max = int(f_sum - f_num * f_min)
##    print("n_max: {}".format(n_max))
    n_min = int(f_num - n_max)
##    print("n_min: {}".format(n_min))
    f_k = k - (2 ** (floor - 1) - 1)
##    print("f_k: {}".format(f_k))
    max_min = min(n_max, n_min)
    if n_max > n_min:
        two_max = (n_max - n_min) // 2
        two_min = 0
    else:
        two_min = (n_min - n_max) // 2
        two_max = 0
    if f_k <= two_max:
        print("Case #{}: {} {}".format(c, f_max, f_max))
    elif f_k > two_max and f_k - two_max <= max_min:
        print("Case #{}: {} {}".format(c, f_max, f_min))
    else:
        print("Case #{}: {} {}".format(c, f_min, f_min))

  

