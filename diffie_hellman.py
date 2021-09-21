

N = 23
     
  
G = 9
     
      
print('The Value of N is :%d'%(N))
print('The Value of G is :%d'%(G))
     
    # Alice will choose the private key a
x = 4
print('The Private Key a for Alice is :%d'%(x))
     
    # gets the generated key
A = int(pow(G,x,N)) 
     
    # Bob will choose the private key b
y = 3
print('The Private Key b for Bob is :%d'%(y))
    
    # gets the generated key
B = int(pow(G,y,N)) 
     
     
    # Secret key for Alice
ka = int(pow(B,x,N))
     
    # Secret key for Bob
kb = int(pow(A,y,N))
     
print('Secret key for the Alice is : %d'%(ka))
print('Secret Key for the Bob is : %d'%(kb))