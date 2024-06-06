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
        # build group form lowest elemetn and deduct the count of each card
        sortedKeys = sorted(occurence.keys())
        for card in sortedKeys:
                while occurence[card] > 0:
                        for i in range(groupSize):
                                if card + i not in occurence:
                                        return False
                                occurence[card + i] -= 1
                                if occurence[card + i] < 0:
                                        return False
        
        return True
                        