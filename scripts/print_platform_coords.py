from numpy import cos, sin, pi, zeros

rad = 4.5

r0 = 0.0 * rad
r1 = 0.5 * rad
r2 = 1.0 * rad

arc0 = 2.0 * pi / 1.0
arc1 = 2.0 * pi / 8.0
arc2 = 2.0 * pi / 16.0

pcart = zeros([25, 2])
ppolar = zeros([25, 2])

for i in range(25):

    if i == 0:
        theta = (i - 0) * arc0 - pi / 2.0
        pcart[i][0] = r0 * cos(theta)
        pcart[i][1] = r0 * sin(theta)
        ppolar[i][0] = r0
        ppolar[i][1] = theta

    elif i > 0 and i < 9:
        theta = (i - 1) * arc1 - pi / 2.0
        pcart[i][0] = r1 * cos(theta)
        pcart[i][1] = r1 * sin(theta)
        ppolar[i][0] = r1
        ppolar[i][1] = theta

    elif i > 9 and i < 25:
        theta = (i - 9) * arc2 - pi / 2.0
        pcart[i][0] = r2 * cos(theta)
        pcart[i][1] = r2 * sin(theta)
        ppolar[i][0] = r2
        ppolar[i][1] = theta


print "First the platform coordinates in cartesian.\n\n"

for i, p in enumerate(pcart):

    if i == 24:
        print "{% 2.10f,% 2.10f}" % (p[0], p[1])

    else:
        print "{% 2.10f,% 2.10f}," % (p[0], p[1])


print "\n\nAnd in polar.\n\n"
for i, p in enumerate(ppolar):
    if i == 24:
        print "{% 2.10f,% 2.10f}" % (p[0], p[1])

    else:
        print "{% 2.10f,% 2.10f}," % (p[0], p[1])
