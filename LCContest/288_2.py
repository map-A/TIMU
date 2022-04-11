def minimizeResult(expression: str) -> str:

    a = expression.split('+')
    ret =999999999
    ans = ""
    for i in range(len(a[0])):
        add1 =(int)(a[0][i:])
        mut1 = 1
        flag1 = False
        if(i!=0):
            flag1 =True
            mut1=(int)(a[0][0:i])

        for j in range(len(a[1])):
            mut2 = 1
            flag2=False
            add2 = (int)(a[1][0:len(a[1])-j])

            if(j!=0):
                flag2 =True
                mut2 = (int)(a[1][-j:])


            if(ret>mut1*(add1+add2)*mut2):
                ret = mut1*(add1+add2)*mut2
                if(mut1!=1 or flag1==True):
                    ans = str(mut1)+'('+str(add1)+'+'+str(add2)+')'
                else:
                    ans = '('+str(add1)+'+'+str(add2)+')'
                if(mut2!=1 or flag2==True):
                    ans =ans+ str(mut2);

    return ans

expresion = "12+34"
ret = minimizeResult(expresion)
print(ret)