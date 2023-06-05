t = int(input())  # number of test cases

for _ in range(t):
    k = int(input())  # k-th element to find

    # Start with 1 and keep incrementing the number until the k-th element is found
    num = 1
    while k > 0:
        if num % 3 != 0 and num % 10 != 3:
            k -= 1
        num += 1

    # Print the k-th element
    print(num - 1)
