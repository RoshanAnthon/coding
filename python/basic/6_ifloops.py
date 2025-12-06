a = 5
b = 10

if a>b:
    print(f"{a} is greater")
else:
    print(f"{b} is greateer")


num = int(input("enter the number whose factorial you want: "))
fact = 1

for i in range(1,num+1):
    fact = fact * i

print(f"factorial of {num} is {fact} \n")

num2 = int(input("enter a number to check if its prime: "))
non_prime = False

for i in range(2,num2):
    if num2%i == 0:
        print(f"{num2} is not prime")
        non_prime = True

if non_prime == False:
   print(f"{num2} is prime")


