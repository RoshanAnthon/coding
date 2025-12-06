
factf = 1
#this num=1 is python feature, if you dont pass a number and just call the function this 1 is considered as default
def factorial_rec(num=1):
    if num==1 or num==0:
        return 1
    return num * factorial_rec(num-1)

num = int(input("enter the number whose factorial you want"))
fact = factorial_rec(num)

print(f"factorial of {num} is {fact}")

