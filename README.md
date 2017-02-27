# FlappyLang-Python Interpreter(Core)

##### FlappyLang is open source minimal programming language with *basic* syntax. 

## STRUCTURE FLAPPY-LANG

# PRINT

- [x] NUMBERS
- [x] STRING
- [x] EXPRESSIONS
- [x] VARIABLES

# VARIABLES

- [x] ASSIGNING VARIABLES
- [x] ASSIGNING VARIABLES TO OTHER VARIABLES

# PRINT IN SH

- [x] INPUT

# STATEMENTS

- [x] IF STATEMENTS
- [X] PARSING CONDITIONS

## DOCUMENTATION

### PRINT:

```flappy
print "Hello World" => LowerCase
PRINT "HELLO WORLD" => UpperCase
```

### NUMBER:

```flappy
10 + 2 => Addition
10 - 2 => Decrase
10 / 2 => Division
10 * 2 => Multiplication
print 10
```

##### You have possibility to *print* number.

### STRING:

```flappy
print "STRING"
```

### EXPRESSIONS:

```flappy
10 * (2+4) => Expression
```

### VARIABLES:

```flappy
$var nameLang = "Flappy"
print $var
```

### ASSIGNING VARIABLES TO OTHER VARIABLES

```flappy
$var1 = 10 => Initializing variables
$var2 = $var1 => Assigning variables to other variables
print $var2 => 10 => Output variables after assigning
```

### INPUT

```flappy
input "Enter your name: " $name
input => function
"Enter your name " => String
$name => variables
```

### STATEMENTS AND PARSING CONDITIONS(IF, THEN)

```flappy
if 1 == 1 then => 1 == 1 (eval True)
    print "Hello World" => print STRING
endif => Close IF
```

### EXTENSION

```flappy
.fa //This is extension file for FlappyLang
```

### COMMENTS

```flappy
//This is comment in (FlappyLang)
```

#### Coming soon add docs for imperative language.

#### TODO: Copy the following files in these folders and modify import routes:

##### In core(directory):

* flappy_ast.py
* flappy_combinators.py
* euqality.py
* flappy_parser.py

##### In lexer(directory):

* flappy_lexer.py
* flappy_lexer_divider.py
* lexer.py

##### In test(directory):

* test.py
* test_combinators.py
* test_eval.py
* test_flappy_parser.py
* test_lexer.py

