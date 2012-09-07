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

# Assume 75% penetration
penetrationLimit = round(0.25 * len(shoe))

# Player's money and bets
playerInitialMoney = 4227
playerMoney = playerInitialMoney


# Modify the count based on the card seen
def changeCount(card):
    global count
    if card[1] >= 2 and card[1] <= 6:
        count += 1
    elif card[1] == 1 or (card[1] >= 10 and card[1] <= 13):
        count -= 1


# Count the totals of the player's cards. Returns an array, first is soft (ace = 11), second is hard (ace = 1)
def countTotals(playerCards):
    totals = [0,0]
    for card in playerCards:
        if card[1] == 1:
            totals[0] += 11
            totals[1] += 1
        elif card[1] <= 10:
            totals[0] += card[1]
            totals[1] += card[1]
        else:
            totals[0] += 10
            totals[1] += 10
    return totals


# Return the player move according to basic strategy (http://en.m.wikipedia.org/wiki/Blackjack#section_4)
def playerMovePair(playerCard, dealerCard):
	if playerCard == 1:
	   return "split"
	elif playerCard == 2 or playerCard == 3:
		if dealercard >=2 and dealercard <=7:
			return "split"
		else:
			return "hit"
	elif playerCard == 4:
		if dealercard >=5 and dealercard <=6:
			return "split"
		else:
			return "hit"
	elif playerCard == 5:
		if dealercard >=2 and dealercard <=9:
			return "double-hit"
		else:
			return "hit"
	elif playerCard == 6:
		if dealercard >=2 and dealercard <=6:
			return "split"
		else:
			return "hit"
	elif playerCard == 7:
		if dealercard >=2 and dealercard <=7:
			return "split"
		else:
			return "hit"
	elif playerCard == 8:
		return "split"
	elif playerCard == 9:
		if (dealercard >=2 and dealercard <=6) or (dealercard >=8 and dealercard <=9):
			return "split"
		else:
			return "stand"
	elif playerMovePair == 10 or playerMovePair == 11 or playerMovePair == 12 or playerMovePair == 13:
		return "stand"


# Return the player move according to basic strategy (http://en.m.wikipedia.org/wiki/Blackjack#section_4)
def playerMoveHard(playerTotal, dealerCard):
	return "?" # todo


# Return the player move according to basic strategy (http://en.m.wikipedia.org/wiki/Blackjack#section_4)
def playerMoveSoft(playerTotalWithoutAce, dealerCard):
	if playerTotalWithoutAce >= 8:
		return "stand"
	elif playerTotalWithoutAce == 7:
		if dealerCard == 2:
			return "stand"
		elif dealerCard >= 3 and dealerCard <= 6:
			return "double-stand"
		elif dealerCard == 7 or dealerCard == 8:
			return "stand"
		else:
			return "hit"
	elif playerTotalWithoutAce == 6:
		if dealerCard == 2 or dealerCard >= 7:
			return "hit"
		else:
			return "double-hit"
	elif playerTotalWithoutAce == 4 or playerTotalWithoutAce == 5:
		if dealerCard == 2 or dealerCard == 3 or dealerCard >= 7:
			return "hit"
		else:
			return "double-hit"
	elif playerTotalWithoutAce == 2 or playerTotalWithoutAce == 3:
		if dealerCard == 5 or dealerCard == 6:
			return "double-hit"
		else:
			return "hit"


# Return the player move according to basic strategy (http://en.m.wikipedia.org/wiki/Blackjack#section_4)
def playerMove(playerCards, dealerCard):
    if len(playerCards) == 2 and playerCards[0][0] == playerCards[0][1]:
    	return playerMovePair(playerCards[0][1], dealerCard[1])
    else:
        totals = countTotals(playerCards)
        if totals[1] > 21:
        	return "bust"
        elif totals[0] != totals[1]:
        	if totals[0] > 21:
        		return playerMoveHard(totals[1], dealerCard[1])
        	else:
        		return playerMoveSoft(totals[0] - 11, dealerCard[1])
        else:
        	return playerMoveHard(totals[1], dealerCard[1])


# Play one game of Blackjack
def playGame(bet):
    global shoe
    global playerMoney

    playerCards = [shoe.pop(), shoe.pop()]
    # dealer's first card is visible to the player
    dealerCards = [shoe.pop(), shoe.pop()]

    changeCount(playerCards[0])
    changeCount(playerCards[1])
    changeCount(dealerCards[0])

    move = playerMove(playerCards, dealerCards[0])
    while move != "bust" and move != "stand" and move != "surrender":
    	if move == "hit":
    		playerCards.append(shoe.pop())
    		changeCount(playerCards[-1])
    	elif move == "double-hit" or move == "double-stand":
    		pass # todo
    	elif move == "split":
    		pass # todo
    	move = playerMove(playerCards, dealerCards[0])

	# player now saw the dealer's second card
	changeCount(dealerCards[1])

    if move == "bust":
    	playerMoney -= bet
    elif move == "surrender":
    	playerMoney -= bet / 2
    elif move == "stand":
    	pass # todo


# returns the player's bet, based on the current card count
def playerBetBasedOnCount():
	global count
	return 27 # todo


####


# Run simulation
while len(shoe) > penetrationLimit:
    playGame(playerBetBasedOnCount())

# Print out results
gainOrLoss = "-"
if playerMoney - playerInitialMoney > 0:
    gainOrLoss = "+"

print "Player's money = $" + repr(playerMoney) + " (" + gainOrLoss + "$" + repr(abs(playerInitialMoney - playerMoney)) + ")"
