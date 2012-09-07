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

shoe = []

decksInShoe = 6

# Card counter's count
count = 0

# Assume 75% penetration
penetrationLimit = round(0.25 * 6 * 52)

# Player's money and bets
playerInitialMoney = 10000
baseBet = 100
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
    countSoftAce = True
    for card in playerCards:
        if card[1] == 1:
            if countSoftAce:
                totals[0] += 11
                countSoftAce = False
            else:
                totals[0] += 1
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
        if dealerCard >=2 and dealerCard <=7:
            return "split"
        else:
            return "hit"
    elif playerCard == 4:
        if dealerCard >=5 and dealerCard <=6:
            return "split"
        else:
            return "hit"
    elif playerCard == 5:
        if dealerCard >=2 and dealerCard <=9:
            return "double-hit"
        else:
            return "hit"
    elif playerCard == 6:
        if dealerCard >=2 and dealerCard <=6:
            return "split"
        else:
            return "hit"
    elif playerCard == 7:
        if dealerCard >=2 and dealerCard <=7:
            return "split"
        else:
            return "hit"
    elif playerCard == 8:
        return "split"
    elif playerCard == 9:
        if (dealerCard >=2 and dealerCard <=6) or (dealerCard >=8 and dealerCard <=9):
            return "split"
        else:
            return "stand"
    elif playerCard == 10 or playerCard == 11 or playerCard == 12 or playerCard == 13:
        return "stand"


# Return the player move according to basic strategy (http://en.m.wikipedia.org/wiki/Blackjack#section_4)
def playerMoveHard(playerTotal, dealerCard):
    if playerTotal == 21:
        return "stand"
    elif playerTotal >= 17 and playerTotal <= 20:
        return "stand"
    elif playerTotal == 16:
        if dealerCard >= 2 and dealerCard <= 6:
            return "stand"
        elif dealerCard == 7 or dealerCard == 8:
            return "hit"
        else:
            return "surrender"
    elif playerTotal == 15:
        if dealerCard >= 2 and dealerCard <= 6:
            return "stand"
        elif (dealerCard >= 7 and dealerCard <= 9) or dealerCard == 1:
            return "hit"
        else:
            return "surrender"
    elif playerTotal == 14 or playerTotal == 13:
        if dealerCard >= 2 and dealerCard <= 6:
            return "stand"
        else:
            return "hit"
    elif playerTotal == 12:
        if dealerCard == 2 or dealerCard == 3:
            return "hit"
        elif dealerCard <= 6 and dealerCard >= 4:
            return "stand"
        else:
            return "hit"
    elif playerTotal == 11:
        if dealerCard == 1:
            return "hit"
        else:
            return "double-hit"
    elif playerTotal == 10:
        if dealerCard == 1 or dealerCard >= 10:
            return "hit"
        else:
            return "double-hit"
    elif playerTotal == 9:
        if dealerCard >= 3 and dealerCard <= 6:
            return "double-hit"
        else:
            return "hit"
    elif playerTotal >= 5 and playerTotal <= 8:
        return "hit"


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


# returns card value; for purposes of knowing whether the player is allowed to split
def cardValue(card):
	if card <= 10:
		return card
	else:
		# J,Q,K
		return 10


# Return the player move according to basic strategy (http://en.m.wikipedia.org/wiki/Blackjack#section_4)
def playerMove(playerCards, dealerCard):
    if len(playerCards) == 2 and cardValue(playerCards[0][1]) == cardValue(playerCards[1][1]):
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


# Return the dealer's move. Assuming stand on soft 17
def dealerMove(dealerCards):
    totals = countTotals(dealerCards)
    if totals[0] < 17:
        return "hit"
    elif totals[1] <= 21:
        return "stand"
    else:
        return "bust"


# Returns either "dealer" or "player"
def whoWins(playerCards, dealerCards):
    playerTotals = countTotals(playerCards)
    dealerTotals = countTotals(dealerCards)
    playerFinal = 0
    dealerFinal = 0
    if playerTotals[0] <= 21:
        playerFinal = playerTotals[0]
    else:
        playerFinal = playerTotals[1]
    if dealerTotals[0] <= 21:
        dealerFinal = dealerTotals[0]
    else:
        dealerFinal = dealerTotals[1]
    if playerFinal > 21:
        return "dealer"
    elif dealerFinal > 21:
        return "player"
    elif playerFinal < dealerFinal:
        return "dealer"
    else:
        return "player"


# Play one game of Blackjack
def playGame(bet):
    print "-----------------------"
    global shoe
    global playerMoney

    # player's hands
    playerHands = [[shoe.pop(), shoe.pop()]]
    playerHandsStatus = ["new"]
    # dealer's first card is visible to the player
    dealerCards = [shoe.pop(), shoe.pop()]

    print "player dealt",
    print playerHands
    print "dealer dealt",
    print dealerCards

    changeCount(playerHands[0][0])
    changeCount(playerHands[0][1])
    changeCount(dealerCards[0])

    while "open" in playerHandsStatus or "new" in playerHandsStatus:
        for i in range(0,len(playerHands)):
            playerCards = playerHands[i]
            move = playerMove(playerCards, dealerCards[0])

            while (playerHandsStatus[i] != "closed" and move != "bust" and move != "stand" and move != "surrender") and not (playerHandsStatus[i] == "open" and move == "double-stand"):
            	print "player "+move
                if move == "hit" or (playerHandsStatus[i]!="new" and move == "double-hit"):
                    playerCards.append(shoe.pop())
                    changeCount(playerCards[-1])
                elif playerHandsStatus[i] == "new" and (move == "double-hit" or move == "double-stand"):
                    bet *= 2
                    playerCards.append(shoe.pop())
                    changeCount(playerCards[-1])
                    playerHandsStatus[i] = "closed"
                    print "player now has",
                    print playerHands
                    break
                elif move == "split":
                    card1 = shoe.pop()
                    card2 = shoe.pop()
                    changeCount(card1)
                    changeCount(card2)
                    playerHands.append([playerCards[1], card1])
                    playerHandsStatus.append("open")
                    playerCards.remove(playerCards[1])
                    playerCards.append(card2)
                print "player now has",
                print playerHands
                playerHandsStatus[i] = "open"
                move = playerMove(playerCards, dealerCards[0])
            
            if playerHandsStatus[i] != "closed" and playerHandsStatus[i] != "stand":
                if move == "bust":
                    print "player bust! (",
                    print playerCards,
                    print ")"
                    playerHandsStatus[i] = "closed"
                    playerMoney -= bet
                elif move == "surrender":
                    print "player surrender! (",
                    print playerCards,
                    print ")"
                    playerHandsStatus[i] = "closed"
                    playerMoney -= bet / 2
                elif move == "stand" or move == "double-stand":
                	playerHandsStatus[i] = "stand"

    # player now saw the dealer's second card
    changeCount(dealerCards[1])

    dmove = dealerMove(dealerCards)
    while dmove != "bust" and dmove != "stand":
        # dmove == "hit"
        dealerCards.append(shoe.pop())
        changeCount(dealerCards[-1])
        dmove = dealerMove(dealerCards)

	print "dealer "+dmove+" (",
	print dealerCards,
	print ")"

    for i in range(0,len(playerHands)):
        if playerHandsStatus[i] == "stand":
            if dmove == "bust":
                # player wins
                print "player wins! (",
                print playerHands[i],
                print ")"
                playerMoney += bet
            else:
                if whoWins(playerHands[i], dealerCards) == "player":
                    print "player wins! (",
    	            print playerHands[i],
                    print ")"
                    playerMoney += bet
                else:
                    print "player loses! (",
    	            print playerHands[i],
                    print ")"
                    playerMoney -= bet


# returns the player's bet, based on the current card count
def playerBetBasedOnCount():
    global count
    global shoe
    global baseBet
    decksInShoe = round(float(len(shoe)) / float(52))
    if decksInShoe == 0:
        print shoe
        print len(shoe)
        exit()
    trueCount = round(float(count) / float(decksInShoe));
    if trueCount > 0:
        return baseBet * trueCount
    else:
        return baseBet


# run through one shoe
def playShoe():
    global singleDeck
    global shoe
    global count
    global decksInShoe
    count = 0
    shoe = singleDeck * decksInShoe
    shuffle(shoe)
    while len(shoe) > penetrationLimit:
        playGame(playerBetBasedOnCount())


####


# Play 100 shoes.
x = 0
while x < 1000:
    playShoe()
    x += 1

# Print out results
gainOrLoss = "-"
if playerMoney - playerInitialMoney > 0:
    gainOrLoss = "+"

print "Player's money = $" + repr(playerMoney) + " (" + gainOrLoss + "$" + repr(abs(playerInitialMoney - playerMoney)) + ")"
