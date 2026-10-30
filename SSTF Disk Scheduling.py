reqseq=[3,60,10,25,30,4]
head=41

total=0
sequence=[head]

while reqseq:
    closest=min(reqseq,key=lambda x:abs(x-head))
    total+=abs(closest-head)
    head=closest
    
    sequence.append(closest)
    reqseq.remove(closest)
    
    
   
print(total)
print(sequence)