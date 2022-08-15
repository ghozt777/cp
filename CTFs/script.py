from sys import * 

def __main__():
	f=open('./out.txt')
	ip=f.readlines()

	arr:List=[]

	for i in range(0,len(ip)):
		line:string=ip[i]
		sanitzed_string:string=""
		for j in range(0,len(line)):
			if line[j] == '\n' or line[j] == ' ':
				break
			sanitzed_string+=line[j]
		arr.append(sanitzed_string)

	res:string=""

	for i in range(0,len(arr)):
		res+=chr(int(arr[i]))

	print(res)



__main__()