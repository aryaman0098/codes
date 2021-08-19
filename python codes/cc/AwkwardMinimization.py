T = int(input())
for i in range (0,T):
    s = input()
    p, q = s.count("b"), s.count("g")
    d = 0
    c = q - p
    r = c // 2
    if len(s) == 0:
        print(d)
    else:
        if p == q:
            d = (q*(2*(q**2)+1))/3
        elif p>q:
            d = (q*(2*(q**2)+1))/3
            c = p - q
            r = c // 2
            d = d + (q*r*(2*q + r))
        elif q>p:
            d = (p*(2*(p**2)+1))/3
            d = d + (p*r*(2*p + r))
        if r == c / 2:
            print(int(d))
        else:
            if q<p:
                d = d + q*r + q**2
            else:
                d = d + p*r + p**2
            print(int(d))






    

        


    