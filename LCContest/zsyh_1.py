



def deleteText(article: str, index: int) -> str:
    a = article.split(" ")
    start = 0
    for i in range(len(a)):
        if(start<=index<start+len(a[i])):
            a.pop(i)
            break
        elif index== start+len(a[i]):
            break
        else:
            start+=len(a[i])+1
    ret = ""
    for i in range(len(a)-1):
        ret+=a[i]
        ret+=" "
    if(len(a)>0):
        ret+=a[len(a)-1]
    return ret