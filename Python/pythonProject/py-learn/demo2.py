x = []
y = []
x.append(int(input("请输入第一点的横坐标")))
y.append(int(input("请输入第一点的纵坐标")))
x.append(int(input("请输入第二点的横坐标")))
y.append(int(input("请输入第二点的纵坐标")))
x.append(int(input("请输入第三点的横坐标")))
y.append(int(input("请输入第三点的纵坐标")))

x1 = x[1] - x[0]
y1 = y[1] - y[0]
x2 = x[2] - x[0]
y2 = y[2] - y[0]
print(abs(x1*y2 - x2*y1) / 2)
