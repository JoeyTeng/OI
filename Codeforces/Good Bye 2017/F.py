n = int(raw_input())
point = []
for i in range(n):
    point.append((lambda x: (int(x[0]), x[1]))(raw_input().split(' ')))
point.sort(key=lambda x: x[0])

edge = []
for i, x in enumerate(point):
    for j, y in enumerate(point):
        edge.append((i, j, abs(y[0] - x[0])))
