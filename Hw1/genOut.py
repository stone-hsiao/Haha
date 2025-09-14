import os

c = [e for e in os.listdir() if e.endswith('.c')][0]
os.system('gcc '+c+' -o '+c.replace('.c','.exe'))

exe = [e for e in os.listdir() if e.endswith('.exe')][0]

ins = [e for e in os.listdir() if e.endswith('.in')]

for ine in ins:
    os.system(exe+' < '+ine+' > '+ine.replace('.in','.out'))

for i,ine in enumerate(ins):
    print('----------------------------')
    print('# '+str(i+1))
    print('----------------------------')
    with open(ine,encoding='utf-8') as f:
        print(f.read())
    print('----------------------------')
    with open(ine.replace('.in','.out'),encoding='utf-8') as f:
        print(f.read())
#input('press enter to continue')
