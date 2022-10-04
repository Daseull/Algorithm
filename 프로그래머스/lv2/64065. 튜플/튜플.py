import re

def solution(s):
    answer = []
    
    strs = s.split('},{')
    lists = []
    for str in strs:
        number = re.findall(r'\d+', str)
        lists.append(set(number))
    lists.append(set())
    lists.sort(key = lambda x : len(x))
    for i in range(len(lists) - 1):
        answer.append(int(list(lists[i+1] - lists[i])[0]))
        
    
    return answer