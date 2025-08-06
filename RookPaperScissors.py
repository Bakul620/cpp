import random

def RockPaperScissors():
    print("Welcome to Rock Paper Scissors!")
    choice =random.choice(['r','p','s'])
    print("Rook, Paper, Scissors! (r/p/s) : ")
    st = input()
    print("You Chose : " + st)
    print("Computer Chose : " + choice)
    if st == choice:
        print("You Win!")
    else:
        print("You Lose!")

RockPaperScissors()
