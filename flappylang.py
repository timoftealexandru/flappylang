# Created by Mihai Sandor & Dobai David
from sys import *

tokens = []
num_stack = []
symbols = {}


def open_file(filename):
    data = open(filename, "r").read()
    data += "<EOF>"
    return data


def lex(file_contents):
    tok = ""
    state = 0
    is_expr = 0
    var_started = 0
    var = ""
    string = ""
    expr = ""
    file_contents = list(file_contents)
    for char in file_contents:
        tok += char
        if tok == " ":
            if state == 0:
                tok = ""
            else:
                tok = " "
        elif tok == "\n" or tok == "<EOF>":
            if expr != "" and is_expr == 1:
                tokens.append("EXPR:" + expr)
                expr = ""
            elif expr != "" and is_expr == 0:
                tokens.append("NUM:" + expr)
                expr = ""
            elif var != "":
                tokens.append("VAR:" + var)
                var = ""
                var_started = 0
            tok = ""
        elif tok == "=" and state == 0:
            if expr != "" and is_expr == 0:
                tokens.append("NUM:" + expr)
                expr = ""
            if var != "":
                tokens.append("VAR:" + var)
                var = ""
                var_started = 0
            if tokens[-1] == "EQUALS":
                tokens[-1] = "EQEQ"
            else:
                tokens.append("EQUALS")
            tok = ""
        elif tok == "$" and state == 0:
            var_started = 1
            var += tok
            tok = ""
        elif var_started == 1:
            if tok == "<" or tok == ">":
                if var != "":
                    tokens.append("VAR:" + var)
                    var = ""
                    var_started = 0
            var += tok
            tok = ""
        elif tok == "PRINT" or tok == "print":
            tokens.append("PRINT")
            tok = ""
        elif tok == "ENDIF" or tok == "endif":
            tokens.append("ENDIF")
            tok = ""
        elif tok == "IF" or tok == "if":
            tokens.append("IF")
            tok = ""
        elif tok == "THEN" or tok == "then":
            if expr != "" and is_expr == 0:
                tokens.append("NUM:" + expr)
                expr = ""
            tokens.append("THEN")
            tok = ""
        elif tok == "INPUT" or tok == "input":
            tokens.append("INPUT")
            tok = ""
        elif tok == "0" or tok == "1" or tok == "2" or tok == "3" or tok == "4" or tok == "5" or tok == "6" or \
                tok == "7" or tok == "8" or tok == "9":
            expr += tok
            tok = ""
        elif tok == "+" or tok == "-" or tok == "/" or tok == "*" or tok == "(" or tok == ")":
            is_expr = 1
            expr += tok
            tok = ""
        elif tok == "\t":
            tok = ""
        elif tok == "\"" or tok == " \"":
            if state == 0:
                state = 1
            elif state == 1:
                tokens.append("STRING:" + string + "\"")
                string = ""
                state = 0
                tok = ""
        elif state == 1:
            string += tok
            tok = ""
    # print(tokens)
    # return ''
    return tokens


def eval_expression(expr):
    return eval(expr)


def do_print(to_print):
    if to_print[0:6] == "STRING":
        to_print = to_print[8:]
        to_print = to_print[:-1]
    elif to_print[0:3] == "NUM":
        to_print = to_print[4:]
    elif to_print[0:4] == "EXPR":
        to_print = eval_expression(to_print[5:])
    print(to_print)


def do_assign(var_name, var_value):
    symbols[var_name[4:]] = var_value


def get_variable(var_name):
    var_name = var_name[4:]
    if var_name in symbols:
        return symbols[var_name]
    else:
        return "VARIABLE ERROR: Undefined Variable"
        exit()


def get_input(string, var_name):
    i = input(string[1:-1] + " ")
    symbols[var_name] = "STRING:\"" + i + "\""


def parse(toks):
    i = 0
    while i < len(toks):
        if toks[i] == "ENDIF":
            i += 1
        elif toks[i] + " " + toks[i + 1][0:6] == "PRINT STRING" or toks[i] + " " + toks[i + 1][0:3] == "PRINT NUM" or \
                        toks[i] + " " + toks[i + 1][0:4] == "PRINT EXPR" or \
                        toks[i] + " " + toks[i + 1][0:3] == "PRINT VAR":
            if toks[i + 1][0:6] == "STRING":
                do_print(toks[i + 1])
            elif toks[i + 1][0:3] == "NUM":
                do_print(toks[i + 1])
            elif toks[i + 1][0:4] == "EXPR":
                do_print(toks[i + 1])
            elif toks[i + 1][0:3] == "VAR":
                do_print(get_variable(toks[i + 1]))
            i += 2
        elif toks[i][0:3] + " " + toks[i + 1] + " " + toks[i + 2][0:6] == "VAR EQUALS STRING" or toks[i][0:3] + " " + \
            toks[i + 1] + " " + toks[i + 2][0:3] == "VAR EQUALS NUM" or toks[i][0:3] + " " + toks[i + 1] + \
            " " + toks[i + 2][0:4] == "VAR EQUALS EXPR" or \
                                toks[i][0:3] + " " + toks[i + 1] + " " + toks[i + 2][0:3] == "VAR EQUALS VAR":
            if toks[i + 2][0:6] == "STRING":
                do_assign(toks[i], toks[i + 2])
            elif toks[i + 2][0:3] == "NUM":
                do_assign(toks[i], toks[i + 2])
            elif toks[i + 2][0:4] == "EXPR":
                do_assign(toks[i], "NUM:" + str(eval_expression(toks[i + 2][5:])))
            elif toks[i + 2][0:3] == "VAR":
                do_assign(toks[i], get_variable(toks[i + 2]))
            i += 3
        elif toks[i] + " " + toks[i + 1][0:6] + " " + toks[i + 2][0:3] == "INPUT STRING VAR":
            get_input(toks[i + 1][7:], toks[i + 2][4:])
            i += 3
        elif toks[i] + " " + toks[i + 1][0:3] + " " + toks[i + 2] + " " + toks[i + 3][0:3] + " " + toks[
                i + 4] == "IF NUM EQEQ NUM THEN":
            if toks[i + 1][4:] == toks[i + 3][4:]:
                print("True")
            else:
                print("False")

            i += 5
            # print(symbols)


def run():
    data = open_file(argv[1])
    toks = lex(data)
    parse(toks)


run()
