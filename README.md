# FlappyLang-Python Interpreter

#####FlappyLang is open source minimal programming language with *basic* syntax. 

## STRUCTURE FLAPPY-LANG

#PRINT: 
	* NUMBERS          							[X]
	* STRING           							[X]
	* EXPRESSIONS      							[X]
	* VARIABLES        							[X]

#VARIABLES:
	* ASSIGNING VARIABLES    					[X]
	* ASSIGNING VARIABLES TO OTHER VARIABELS    [X]

#PRINT IN SH:										   	
    * INPUT                                     [X]

#STATEMENTS:
	* IF STATEMENTS							    [X]
	* PARSING CONDITIONS						[X]


##DOCUMENTATION

###PRINT:

```flappy
print "Hello World" => LowerCase
PRINT "HELLO WORLD" => UpperCase
```

###NUMBER:

```flappy
10 + 2 => Addition
10 - 2 => Decrase
10 / 2 => Division
10 * 2 => Multiplication
print 10
```
##### You have possibility to *print* number.

###STRING:

```flappy
print "STRING"
```

###EXPRESSIONS:
```flappy
10 * (2+4) => Expression
```

###VARIABLES:

```flappy
$var nameLang = "Flappy"
print $var
```

###ASSIGNING VARIABLES TO OTHER VARIABLES

```flappy
$var1 = 10 => Initializing variables
$var2 = $var1 => Assigning variables to other variables
print $var2 => 10 => Output variables after assigning
```
###INPUT

```flappy
input "Enter your name: " $name
input => function
"Enter your name " => String
$name => variables
```


###STATEMENTS AND PARSING CONDITIONS(IF, THEN)

```flappy
if 1 == 1 then => 1 == 1 (eval True)
    print "Hello World" => print STRING
endif => Close IF
```

###EXTENSION
```flappy
.fa //This is extension file for FlappyLang
```

###COMMENTS
```flappy
//This is comment in (FlappyLang)
```
