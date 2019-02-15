import sys
import re

README="""FLags:
-h --help                 Displays a hint
-v --version              Displays version of the script
-i --set-indent           Sets the indentation of the table
-t --set-tabs-at-start  Sets the indentation at start"""
VERSION='1.0'

max_state = 0
indentetion = 1
start_indentation = 0

def handle_arguments():
    global indentetion
    global start_indentation
    args = sys.argv
    args.pop(0)
    size = len(args)
    i = 0
    while i < size:
        if args[i] == '-h' or args[i] == '--help':
            print (README)
            return False
        elif args[i] == '-v' or args[i] == '--version':
            print (VERSION)
            return False
        elif args[i] == '-i' or args[i] == '--set-indent':
            i += 1
            try:
                indentetion = int(args[i])
            except:
                print ('You must specify an indent', file=sys.stderr)
                return False
        elif args[i] == '-t' or args[i] == '--set-tabs-at-start':
            i += 1
            try:
                start_indentation = int(args[i])
            except:
                print ('You must specify an indent', file=sys.stderr)
                return False
        else:
            print ('Invalid argument')
            print (README)
            return False
        i += 1
    return True

def read_existing_output():
    file = open('lex.txt', 'r')
    arr = file.read().split('\n')
    file.close()
    return arr

def write_existing_output(arg):
    file = open('lex.txt', 'w')
    file.write(arg)

def indent_row(row):
    global max_state
    global indentetion
    states = row.split(',')
    max_len = len(str(max_state))
    new_row = ''
    for state in states:
        while len(state) < max_len + int(indentetion):
            state = ' ' + state
        new_row = new_row + state + ','
    new_row = new_row.lstrip()[:-1]
    return new_row

def refactoring_table():
    global start_indentation
    arr = read_existing_output()
    line = ''
    i = 0
    for item in arr:
        item = indent_row(item)
        if not item:
            break
        k = 0
        while k < start_indentation:
            line = line + '\t'
            k += 1
        if i >= 33 and i <= 126:
            line = line + '{' + item + '},' + ' /* ' + str(i) + '. ' + chr(i) + ' */\n'
        elif i >= 0 and i <= 9:
            line = line + '{' + item + '},' + ' /*  ' + str(i) + '.   */\n'
        elif i < 0 or i > 127:
            line = line + '{' + item + '},' + ' /* other */\n'
        else:
            line = line + '{' + item + '},' + ' /* ' + str(i) + '.   */\n'
        i += 1
    write_existing_output(line)

def init_table(cnt_states):
    file = open('lex.txt', 'w')
    i = 0
    while i < 129:
        k = cnt_states
        while k > 0:
            file.write('0,')
            k -= 1
        file.write('0\n')
        i += 1
    file.close()

def write_statement(state, pair, index):
    global max_state
    arr = read_existing_output()
    row = arr[index].split(',')
    row[state] = pair[1]
    if state > max_state:
        max_state = state
    line = ''
    for elem in row:
        line = line + str(elem) + ','
    arr[index] = line[:-1]
    line = ''
    for elem in arr:
        line = line + elem + '\n'
    write_existing_output(line)

def handling_pair(state, pair):
    if pair[0] == '\\n':
        pair[0] = '\n'
        write_statement(state, pair, ord('\n'))
    elif pair[0] == '\\t':
        pair[0] = '\t'
        write_statement(state, pair, ord('\t'))
    elif pair[0] == '\\-':
        pair[0] = '-'
        write_statement(state, pair, ord('-'))
    elif pair[0] == 'other':
        pair[0] = chr(128)
        write_statement(state, pair, 128)
    else:
        line = pair[0].strip('\\')
        if not line:
            write_statement(state, pair, ord('\\'))
        elif '-' in line:
            first = ord(line[0])
            last = ord(line[2])
            while first <= last:
                write_statement(state, pair, first)
                first += 1
        else:
            write_statement(state, pair, ord(line))

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

def read_statement(statement):
    if statement == '\n':
        return
    statements = re.split(r'(?<![\\]);', statement)
    arr = statements.pop(0).split(':')
    column = int(arr[0])
    default_state = int(arr[1])
    set_default(column, default_state)
    for item in statements:
        if not item or item == '\n':
            break
        pair = item.split(':')
        handling_pair(column, pair)

def read_input():
    input = open('lexgen.txt', 'r')
    init_table(int(input.readline()))
    for line in input:
        read_statement(line)
    refactoring_table()
    input.close()

if __name__ == '__main__':
    ret = True
    if len(sys.argv) > 1:
        ret = handle_arguments()
    if ret:
        read_input()

