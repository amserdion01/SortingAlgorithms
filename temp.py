import random
for x in range(1000000):
    n = random.randint(-100000,100000)
    with open("neg2.txt","a") as f:
        print(n,file=f)
