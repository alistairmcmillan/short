#!/usr/bin/env python
# Simple Black Jack Card Counting Monte Carlo experiment
# No warranty whatsoever, use at your own risk.
# (c) Jan Dlabal, 2012.
# http://houbysoft.com/

from random import shuffle

# Each card is represented by a tuple of the form (x,y)
# where x = color (1-4)
# and y = card (1-13), 1 = Ace, 2-10 = numbers, 11 = J, 12 = Q, 13 = K
singleDeck = sum(map(lambda color : zip([color] * 13, range(1,14)), range(1,5)), [])

# Assume a 6-deck shoe
shoe = singleDeck * 6
shuffle(shoe)

# Card counter's count
count = 0

# Modify the count based on the card seen
def changeCount(card):
    global count
    if card[1] >= 2 and card[1] <= 6:
        count += 1
    elif card[1] == 1 or (card[1] >= 10 and card[1] <= 13):
        count -= 1

