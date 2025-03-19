def isPalindromic(num):
    s = str(num)
    for i in range(len(s)):
            if not(s[i] == s[len(s)-1-i]):
                    return False
    return True
lst = []
for a in range(900,1000):
    for b in range(900,1000):
        if isPalindromic(a*b):
            lst.append(a*b)
            # print(str(a)+" * "+str(b)+ " = "+ str(a*b))
print(max(lst))


