#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 63 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 06/19/19
# Time: 22:07:46
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ \t\n]+

    2  "//".*

    3  [0-9]+

    4  false|true

    5  "if"

    6  "else"

    7  "while"

    8  [a-zA-Z_]([a-zA-Z_]|[0-9])*

    9  "+"

   10  "-"

   11  "*"

   12  "=="

   13  "<"

   14  ">"

   15  "<="

   16  ">="

   17  "<>"

   18  "="

   19  "!"

   20  "&"

   21  "||"

   22  ";"

   23  "("

   24  ")"

   25  "{"

   26  "}"


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x26               goto 5
	0x28               goto 6
	0x29               goto 7
	0x2a               goto 8
	0x2b               goto 9
	0x2d               goto 10
	0x2f               goto 11
	0x30 - 0x39 (10)   goto 12
	0x3b               goto 13
	0x3c               goto 14
	0x3d               goto 15
	0x3e               goto 16
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x64 (4)    goto 17
	0x65               goto 18
	0x66               goto 19
	0x67 - 0x68 (2)    goto 17
	0x69               goto 20
	0x6a - 0x73 (10)   goto 17
	0x74               goto 21
	0x75 - 0x76 (2)    goto 17
	0x77               goto 22
	0x78 - 0x7a (3)    goto 17
	0x7b               goto 23
	0x7c               goto 24
	0x7d               goto 25


state 2
	^INITIAL

	0x09 - 0x0a (2)    goto 3
	0x20               goto 3
	0x21               goto 4
	0x26               goto 5
	0x28               goto 6
	0x29               goto 7
	0x2a               goto 8
	0x2b               goto 9
	0x2d               goto 10
	0x2f               goto 11
	0x30 - 0x39 (10)   goto 12
	0x3b               goto 13
	0x3c               goto 14
	0x3d               goto 15
	0x3e               goto 16
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x64 (4)    goto 17
	0x65               goto 18
	0x66               goto 19
	0x67 - 0x68 (2)    goto 17
	0x69               goto 20
	0x6a - 0x73 (10)   goto 17
	0x74               goto 21
	0x75 - 0x76 (2)    goto 17
	0x77               goto 22
	0x78 - 0x7a (3)    goto 17
	0x7b               goto 23
	0x7c               goto 24
	0x7d               goto 25


state 3
	0x09 - 0x0a (2)    goto 3
	0x20               goto 3

	match 1


state 4
	match 19


state 5
	match 20


state 6
	match 23


state 7
	match 24


state 8
	match 11


state 9
	match 9


state 10
	match 10


state 11
	0x2f               goto 26


state 12
	0x30 - 0x39 (10)   goto 12

	match 3


state 13
	match 22


state 14
	0x3d               goto 27
	0x3e               goto 28

	match 13


state 15
	0x3d               goto 29

	match 18


state 16
	0x3d               goto 30

	match 14


state 17
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 8


state 18
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x6b (11)   goto 17
	0x6c               goto 31
	0x6d - 0x7a (14)   goto 17

	match 8


state 19
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61               goto 32
	0x62 - 0x7a (25)   goto 17

	match 8


state 20
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x65 (5)    goto 17
	0x66               goto 33
	0x67 - 0x7a (20)   goto 17

	match 8


state 21
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x71 (17)   goto 17
	0x72               goto 34
	0x73 - 0x7a (8)    goto 17

	match 8


state 22
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x67 (7)    goto 17
	0x68               goto 35
	0x69 - 0x7a (18)   goto 17

	match 8


state 23
	match 25


state 24
	0x7c               goto 36


state 25
	match 26


state 26
	0x00 - 0x09 (10)   goto 26
	0x0b - 0xff (245)  goto 26

	match 2


state 27
	match 15


state 28
	match 17


state 29
	match 12


state 30
	match 16


state 31
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x72 (18)   goto 17
	0x73               goto 37
	0x74 - 0x7a (7)    goto 17

	match 8


state 32
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x6b (11)   goto 17
	0x6c               goto 38
	0x6d - 0x7a (14)   goto 17

	match 8


state 33
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 5


state 34
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x74 (20)   goto 17
	0x75               goto 39
	0x76 - 0x7a (5)    goto 17

	match 8


state 35
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x68 (8)    goto 17
	0x69               goto 40
	0x6a - 0x7a (17)   goto 17

	match 8


state 36
	match 21


state 37
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x64 (4)    goto 17
	0x65               goto 41
	0x66 - 0x7a (21)   goto 17

	match 8


state 38
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x72 (18)   goto 17
	0x73               goto 39
	0x74 - 0x7a (7)    goto 17

	match 8


state 39
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x64 (4)    goto 17
	0x65               goto 42
	0x66 - 0x7a (21)   goto 17

	match 8


state 40
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x6b (11)   goto 17
	0x6c               goto 43
	0x6d - 0x7a (14)   goto 17

	match 8


state 41
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 6


state 42
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 4


state 43
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x64 (4)    goto 17
	0x65               goto 44
	0x66 - 0x7a (21)   goto 17

	match 8


state 44
	0x30 - 0x39 (10)   goto 17
	0x41 - 0x5a (26)   goto 17
	0x5f               goto 17
	0x61 - 0x7a (26)   goto 17

	match 7


#############################################################################
# Summary
#############################################################################

1 start state(s)
26 expression(s), 44 state(s)


#############################################################################
# End of File
#############################################################################
