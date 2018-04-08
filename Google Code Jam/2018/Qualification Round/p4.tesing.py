import numpy

a, b, c = tuple(numpy.array(list(map(
    float, input('z y x\n').strip().rstrip().split(' ')))) / 180 * numpy.pi)

Rz = numpy.matrix([[numpy.cos(a), -numpy.sin(a), 0],
                   [numpy.sin(a), numpy.cos(a), 0],
                   [0, 0, 1]])
Ry = numpy.matrix([[numpy.cos(b), 0, numpy.sin(b)],
                   [0, 1, 0],
                   [-numpy.sin(b), 0, numpy.cos(b)]])
Rx = numpy.matrix([[1, 0, 0],
                   [0, numpy.cos(c), -numpy.sin(c)],
                   [0, numpy.sin(c), numpy.cos(c)]])

xz = numpy.matrix([[1, 0, 0],
                   [0, 0, 0],
                   [0, 0, 1]])

A = numpy.matrix(numpy.identity(3) * 0.5) * 2

A2 = Rz * Ry * Rx * A
print(A2)
print(numpy.linalg.det(A2))

A3 = xz * A2
print(A3)

A4 = numpy.matrix([[A3[0, 0], A3[0, 2]],
                   [A3[2, 0], A3[2, 2]]])
print(A4)
print(numpy.linalg.det(A4))
