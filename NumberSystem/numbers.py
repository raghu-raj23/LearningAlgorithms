# Decimal to binary
# quotient = num/2 rem = num%2, reverse of rem

# Binary to Decimal
# binary * digit position with power of 2 


def bintodec(num:int):
    ans,x = 0,1
    while num>0:
        y = num%10
        ans += x * y
        x *= 2
        num //= 10
    return ans

def octtodec(num:int):
    ans,x = 0,1
    while num>0:
        y = num%10
        ans += x * y
        x *= 8
        num //= 10
    return ans

def hexatodec(num:str):
    ans,x = 0,1
    s = len(num)
    for i in range(s-1, -1):
        if ord(num[i]) >= ord('0') and ord(num[i]) <= ord('9'):
            ans += x *(ord(num[i])-ord("0"))
        elif ord(num[i]) >= ord('A') and ord(num[i]) <= ord('F'):
            ans+= x * (ord(num[i])-ord('A')+10)
        x *= 16
    return ans


def addBinary(num1:int, num2:int):
    ans, prevC = 0,0
    while num1>0 and num2>0:
        if num1%2==0 and num2%2==0:
            ans = ans*10 + prevC
            prevC = 0
        elif (num1%2==0 and num2%2==1) or (num1%2==1 and num2%2==0):
            if prevC == 1:
                ans = ans*10 + 0
                prevC = 0
            else:
                ans = ans*10 + prevC
        else:
            ans = ans*10 + prevC
            prevC = 1
        
        num1//= 10
        num2//= 10

        while num1>0:
            if prevC ==1:
                if num1%2==1:
                    ans = ans*10 + 0
                    prevC = 1
                else:
                    ans = ans*10 + 1
                    prevC =0
            else:
                ans = ans*10 + num1%2
            num1 //= 10
        while num2>0:
            if prevC ==1:
                if num2%2==1:
                    ans = ans*10 + 0
                    prevC = 1
                else:
                    ans = ans*10 + 1
                    prevC =0
            else:
                ans = ans*10 + num2%2
            num2 //= 10

        if prevC ==1:
            ans = ans*10 +1
        ans = str(ans)[::-1]
        return int(ans)


def main():
    n = 10101
    print(bintodec(n))
    print(hexatodec('1CF'))
    print(addBinary(10101,10101))

main()