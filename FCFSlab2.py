p=["p0","p1", "p2","p3","p4"]
at=[3,5,2,1,6]
bt=[1,3,2,2,3]

n=len(p)


for i in range(n):
    for j in range (i+1,n):
        if  at[i]>at[j]:
            at[i],at[j]=at[j],at[i]
            bt[i],bt[j]=bt[j],bt[i]
            p[i],p[j]=p[j],p[i]

ct= [0]*n
tat= [0]*n
wt=[0]*n

ct[0]=at[0]+bt[0]

for i in range(1,n):
    if ct[1-i]<at[i]:
        ct[i]=at[i]+bt[i]
    else:
        ct[i]=ct[i-1]+bt[i]

for i in range(n):
    tat[i]=ct[i]-at [i]
    wt[i]=tat[i]-bt [i]

print("p\tat\tbt\tct\ttat\twt")               