import random
def dice_rolling_game():
    count = 0
    while True:
        print("Roll the dice :(y/n) ? ")
        st = input()
        count += 1
        if(st == 'n'):
            print("You rolled " + str(count) + " times." )
            break
        a=random.randint(1,6)
        b=random.randint(1,6)
        print(a,b)
dice_rolling_game()