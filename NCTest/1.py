


def solve(str1,str2):
    kv = {};
    for i in str1:
        times = str2.count(i)
        kv[i] = times
    ret = ""
    for i in str1:
        if i in kv:
            ret+=str(i)+":"+str(kv[i])+','
            kv.pop(i)
    return ret[0:-1]
ret = solve("123abcabc","342adbceacb12")
print(ret)


