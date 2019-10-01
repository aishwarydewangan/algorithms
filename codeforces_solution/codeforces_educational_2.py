

from collections import deque
stack_of_for = deque()
no_lines = int(raw_input())

loop_intensity = 1 
flag = 1
num = 0
while(no_lines):
  
    line = str(raw_input())
    line_split  = line.split()
    if(line_split[0] == "add"):
    
        num += loop_intensity*1
    
    if(line_split[0] == "for"):
    
        loop_intensity *= int(line_split[1])
        stack_of_for.append(int(line_split[1]))
    
    if(line_split[0] == "end"):
    
        loop_intensity /= stack_of_for[len(stack_of_for) - 1]
        stack_of_for.pop()

    if(num > 4294967295):
        flag = 0
        print("OVERFLOW!!!")
        break

    no_lines-=1

if flag:
    print(int(num))