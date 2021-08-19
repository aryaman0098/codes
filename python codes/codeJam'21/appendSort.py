T = int(input())
t = 1

while(t <= T):

    count = 0;

    N = int(input())
    L = input().split()

    for i in range (len(L) - 1):
        
        if int(L[i]) < int(L[i + 1]):
            
            continue     
        
        else :

            x = len(L[i]) - len(L[i + 1])

            if x == 0:
                
                L[i + 1] = L[i + 1] + "0"
                count += 1 
            
            else:
                
                flag = 0
                
                for j in range (len(L[i + 1])):

                    if int(L[i + 1][j]) > int(L[i][j]):

                        flag = 1
                        break 

                    elif int(L[i + 1][j]) < int(L[i][j]):

                        flag = -1
                        break
                    
                    elif int(L[i + 1][j]) == int(L[i][j]):

                        continue

                if flag == 1:

                    L[i + 1] = L[i + 1] + x * "0"

                    count += x

                elif flag == -1:
                    
                    L[i + 1] = L[i + 1] + (x + 1) * "0"

                    count += x + 1

                elif flag == 0:
                    
                    if L[i][-1:] == "9":
                        count += len(L[i]) - len(L[i + 1]) + 1
                    else:
                        count += len(L[i]) - len(L[i + 1])

                    L[i + 1] = L[i + 1] + L[i][len(L[i + 1]) : len(L[i]) - 1]
                    L[i + 1] = L[i + 1] + str(int(L[i][-1:]) + 1)
                
    print(f"Case #{t}: {count}")
                    
    t += 1

