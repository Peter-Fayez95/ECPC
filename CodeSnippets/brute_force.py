from random import randint

def brute_force_check(n, lst):
    """
    compute the solution, brute force
    """
    for i in range(n-1):
        if lst[i]>lst[i+1]:
            return "NO"
    return "YES"

with open("input.txt", 'r') as f1, open("output.txt", 'r') as f2:
    #tc = 1
    tc = int(f1.readline().strip('\n'))

    for i in range(1, tc+1):
        n = int(f1.readline().strip())
        lst = list(map(int, f1.readline().split()))
        
        # c++ solution
        ans1 = f2.readline().strip()

        # brute force solution
        ans2 = brute_force_check(n, lst)

        if ans1 != ans2:
            print(f"Wrong answer on test {i}: Expected ({ans2}), Found({ans1})\n")
