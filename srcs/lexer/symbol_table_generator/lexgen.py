import re

def read_existing_output():
    file = open('lex.cc', 'r')
    arr = file.read().split('\n')
    file.close()
    return arr

def write_existing_output(arg):
    file = open('lex.cc', 'w')
    file.write(arg)

def refactoring_table():
    arr = read_existing_output()
    line = ''
    i = 0
    for item in arr:
        if not item:
            break
        if i >= 33 and i <= 126:
            line = line + '{' + item + '},' + ' /* ' + str(i) + '. ' + chr(i) + ' */\n'
        elif i >= 0 and i <= 9:
            line = line + '{' + item + '},' + ' /*  ' + str(i) + '.   */\n'
        else:
            line = line + '{' + item + '},' + ' /* ' + str(i) + '.   */\n'
        i += 1
    write_existing_output(line)

def init_table(cnt_states):
    file = open('lex.cc', 'w')
    i = 0
    while i < 128:
        k = int(cnt_states)
        while k > 0:
            file.write('0,')
            k -= 1
        file.write('0\n')
        i += 1
    file.close()

def write_state(state, pair, index):
    arr = read_existing_output()
    new_arr = arr[index].split(',')
    new_arr[state] = pair[1]
    line = ''
    for elem in new_arr:
        line = line + str(elem) + ','
    arr[index] = line[:-1]
    line = ''
    for elem in arr:
        line = line + elem + '\n'
    write_existing_output(line)

def handling_pair(state, pair):
    if pair[0] == '\\n':
        pair[0] = '\n'
        write_state(state, pair, ord('\n'))
    else:
        line = pair[0].strip('\\')
        if not line:
            write_state(state, pair, ord('\\'))
        elif '-' in line:
            first = ord(line[0])
            last = ord(line[2])
            while first <= last:
                write_state(state, pair, first)
                first += 1
        else:
            write_state(state, pair, ord(line))

def set_default(state, default):
    arr = read_existing_output()
    line = ''
    for item in arr:
        if not item:
            break
        new_arr = item.split(',')
        new_arr[state] = default
        new_line = ''
        for elem in new_arr:
            new_line = new_line + str(elem) + ','
        line = line + new_line[:-1] + '\n'
    write_existing_output(line)

def write_states(line):
    input = re.split(r'(?<![\\]);', line)
    arr = input.pop(0).split(':')
    state = int(arr[0])
    default = int(arr[1])
    set_default(state, default)
    for item in input:
        if not item or item == '\n':
            break
        pair = item.split(':')
        handling_pair(state, pair)

def read_input():
    input = open('lex.pp', 'r')
    flag = True
    for line in input:
        if flag:
            init_table(int(line))
            flag = False
        else:
            write_states(line)
    input.close()
    refactoring_table()

if __name__ == '__main__':
    read_input()