# Problem: https://open.kattis.com/problems/4thought

s=[]
o=['+','-','*','//']
for i in range(64):
	s.append(eval("4"+o[i//16]+"4"+o[i%16//4]+"4"+o[i%4]+"4"))
for t in range(int(input())):
	n=int(input())
	try:
		i=s.index(n)
		print(("4 "+o[i//16]+" 4 "+o[i%16//4]+" 4 "+o[i%4]+" 4 = "+str(n)).replace("//","/"))
	except:
		print("no solution")