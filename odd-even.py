# Jeremy

numbers = [5, 1, 4, 8, 12, 7, 4, 9, 11, 14, 32, 2, 7, 12]

listEven = []
listOdd  = []

for i in numbers:
	if i % 2 == 0:
		listEven.append(i)
	else:
		listOdd.append(i)

print("Even " + str(listEven))
print("Odd  " + str(listOdd))

