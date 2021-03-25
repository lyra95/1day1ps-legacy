import os
from operator import itemgetter
def readLog(path):
    f = open(path,'r')
    args = f.read().split('\n')
    f.close()
    args[0] = args[0][5:]
    args[1] = args[1][11:]
    args[2] = args[2][8:]
    args[3] = args[3][4:]
    return args

def writeTo(args):
    name,diff,timelog,url = args[0],args[1],args[2],args[3]
    f = open("list.txt",'a')
    f.write(';'+name+','+diff+','+timelog+','+url)
    f.close()
    print("logged successfully in list.txt")

# run only for once to initializing list.txt
def orderByDate_list_txt():
    f = open("list.txt",'r')
    content = f.read().split(';')
    listOfSolved = [args.split(',') for args in content]
    f.close()
    listOfSolved.sort(key=lambda args:args[2])
    
    f = open("list.txt",'w')
    f.close()
    for args in listOfSolved:
        writeTo(args)


# run only for once to lookup all log.txt files in dir .
def lookupDir():
    for dirname, dirnames, filenames in os.walk('.'):
        for filename in filenames:
            if filename=='log.txt':
                path = os.path.join(dirname, filename)
                writeTo(readLog(path))


def createDir(path):
    try:
        if not os.path.exists(path):
            os.makedirs(path)
    except OSError:
        print ('Error: Creating directory. ' + path)

def createLog(path,args):
    name = args[0]
    diff = args[1]
    timelog = args[2]
    url = args[3]

    f = open(path,'x')
    f.write("name:"+name+'\n')
    f.write("difficulty:"+diff+'\n')
    f.write("timelog:"+timelog+'\n')
    f.write("url:"+url)
    f.close()

def createCpp(path):
    f = open(path,'x')
    f.close()

###################################################################3
def listOfAction():
    print("\nsystem: choose action.\n")
    print("0. exit\n")
    print("1. create directory and setup\n")
    print("2. list solved problems(by date)\n")
    print("3. list solved problems(by name)\n")
    print("4. list solved problems(by difficulty)\n")
    print("5. serch by name\n")

# 1.
def creator():
    f = open("timelog.txt",'r')
    latest = f.readline()
    f.close()

    name = input("system: type name\nuser:")
    diff = input("system: type difficulty\nuser:")
    timelog = input("system: type timelog(latest: "+latest +")\nuser:")
    url = input("system: type url\nuser:")

    args = [name,diff,timelog,url]
    createDir(timelog)
    createLog(timelog+"/log.txt",args)
    createCpp(timelog+"/mySol.cpp")

    print("successfully created dir: "+timelog)

    f = open("timelog.txt",'w')
    f.write(timelog)
    f.close()
    print("logged successfully in timelog.txt")

    writeTo(args)

# 2,3,4
def listSolvedProblems(order):
    f = open("list.txt",'r')
    content = f.read().split(';')
    listOfSolved = [args.split(',') for args in content]
    f.close()

    if order == "name":
        listOfSolved.sort(key=itemgetter(0,2))
    if order == "diff":
        listOfSolved.sort(key=itemgetter(1,0))

    for i in range(len(listOfSolved)):
        num,name,diff,date,url = fill(str(i),5), fill(listOfSolved[i][0],30), fill(listOfSolved[i][1],10), fill(listOfSolved[i][2],15), listOfSolved[i][3]+'\n'
        print(num+diff+date+name+url)

    if(input("press any key to go back to menu\nuser:")):
        return

def fill(s,size):
    while size-len(s) > 0:
        s += " "
    return s

while(True):
    listOfAction()
    x = input("\nuser:")
    if(x=='1'):
        try:
            creator()
        except:
            print("failed creating directory")
    elif(x=='2'):
        listSolvedProblems("date")
    elif(x=='3'):
        listSolvedProblems("name")
    elif(x=='4'):
        listSolvedProblems("diff")
    else:
        break