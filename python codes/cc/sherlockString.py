import math
import os
import random
import re
import sys

# Complete the isValid function below.
def isValid(s):
    f = []
    for i in range (0,257):
        f.append(0)

    for i in range (0,len(s)):
        f[ord(s[i])] = f[ord(s[i])] + 1

    for i in range (0, 257):
        if f[i] != 0:
            c = f[i]    
            break

    for i in range (0, 257):
        if f[i] != 0:
            if c == f[i]:
                flag = True
            else:
                flag = False
                break
    
    counter = 0            
    if flag == True :
        return "YES"
    else : 
        for i in range (0,257):
            if f[i] != 0:
                if c != f[i]:
                    a = f[i] - c
                    counter = counter + 1
    
        if counter == 1 :
            if (a == 1 or a == -1):
                return "YES"
        else:
                return "NO"


print(isValid("ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd"))