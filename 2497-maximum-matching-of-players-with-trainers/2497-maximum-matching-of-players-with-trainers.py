class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players = sorted(players)
        trainers = sorted(trainers)

        n = len(players)
        m = len(trainers)

        i = 0;j=0
        cnt = 0
        while i<n and j<m:
            if players[i] <= trainers[j]:
                cnt += 1
                i = i+1
                j= j+1
            else:
                j = j+1
        
        return cnt



        