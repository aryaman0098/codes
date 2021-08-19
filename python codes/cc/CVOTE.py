N, M = map(int,input().split())
chef = {}
country = {}
for i in range (0, N):
    a, b = input().split()
    chef[a] = 0
    country[a] = b
votes = []
for i in range (0, M):
    v = input()
    votes.append(v)
for i in votes:
    chef[i] = chef[i] + 1
M = max(chef.values())
winner = []
for i in chef.keys() :
    if chef[i] == M:
        winner.append(i)
winnerChef = min(winner)
c = country.values()
Winner = {}
for i in c:
    Winner[i] = 0
for i in votes:
    Winner[country[i]] = Winner[country[i]] + 1
M = max(Winner.values())
winnerCountry = []
for i in Winner.keys():
    if Winner[i] == M:
        winnerCountry.append(i)
winnercountry = min(winnerCountry)
print(winnercountry)
print(winnerChef)

    