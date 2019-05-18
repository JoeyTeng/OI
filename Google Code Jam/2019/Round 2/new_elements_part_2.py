# @Author: Joey Teng
# @Email:  joey.teng.dev@gmail.com
# @Filename: new_elements_part_2.py
# @Last modified by:   Joey Teng
# @Last modified time: 19-May-2019
import fractions

T = int(input())
for t in range(1, T + 1):
    impossible = 0
    N = int(input())
    molecule = []
    for i in range(N):
        molecule.append(tuple(map(int, str(input()).split(' '))))
    fraction = []
    for i in range(1, N):
        x = molecule[i - 1][0] - molecule[i][0]
        y = molecule[i][1] - molecule[i - 1][1]
        if x == 0 and y < 0 or y == 0 and x > 0:
            print("Case #{}: IMPOSSIBLE".format(t))
            impossible = 1
            break
        if x == 0 or y == 0:
            continue

        _fraction = fractions.Fraction(x, y)
        if x < 0 and _fraction < 0:
            continue

        if x < 0:
            fraction.append((0, fractions.Fraction(x, y)))
        else:
            fraction.append((1, fractions.Fraction(x, y)))

    if impossible:
        continue

    if len(fraction) == 0:
        x = 1
        y = 1
        print("Case #{0}: {1} {2}".format(t, x, y))
        continue

    fraction.sort()
    if fraction[0][0] == 0:
        checking = fraction[0][1]
        for sign, frac in fraction:
            if sign == 1:
                if frac <= checking:
                    print("Case #{}: IMPOSSIBLE".format(t))
                    impossible = 1
                break

    if impossible:
        continue

    x = 0
    y = 0

    print("Case #{0}: {1} {2}".format(t, x, y))
