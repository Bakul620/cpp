import random

def numberGussingGame():
    print("Welcome to Number Gussing Game!")
    a = random.randint(1,100)
    cnt = 0
    while True:
        print("Guss the Number(Between 1 and 100): ")
        num = int(input())
        cnt += 1
        if num == a:
            print("Congratulations! You Guss the number in "+ str(cnt)+" attempts.")
            break
        else :
            if num < a:
                print("Too low! Try again.")
            elif num > a:
                print("Too high! Try again.")

numberGussingGame()
