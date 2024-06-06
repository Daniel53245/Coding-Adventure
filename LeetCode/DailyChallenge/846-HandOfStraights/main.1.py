#thank to lord I do not have to keep buildi wheels 
class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        """
        :type hand: List[int]
        :type groupSize: int
        :rtype: bool
        """
        if(len(hand)%groupSize) != 0:
                return False
        
        # sort the hand
        hand.sort()
        # create a dictionary to store the count of each card
        occurence = {}
        for card in hand:
                if card in occurence:
                        occurence[card] += 1
                else:
                        occurence[card] = 1
        #count the number of rise in hand count
        
        countRaise = 0
        countReduce = 0
        sortedKeys = sorted(occurence.keys())
        
        # check sortedKey are consisi of consecutive groups of groupSize
        accum = 1
        for i in range(len(sortedKeys)):
                if sortedKeys[i] + 1 in sortedKeys:
                        accum += 1
                        print("next key found for" , sortedKeys[i], "with accum", accum)
                # the next key is not there
                elif(accum < groupSize):
                        accum = 1
                        print("The keys are not consecutive enough@ ", sortedKeys[i],"with accum", accum)
                        return False
        
        
        # check raise and downs
        currentCount = occurence[sortedKeys[0]]
        for number in sortedKeys[1:]:
                if occurence[number] < currentCount:
                        countReduce += 1
                if occurence[number] > currentCount:
                        countRaise += 1
                currentCount = occurence[number]
        if countRaise != countReduce:
                print("The count of keys are not right ")
                return False
        return True
                        