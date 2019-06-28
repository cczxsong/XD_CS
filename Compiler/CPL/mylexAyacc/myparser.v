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
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 06/19/19
# Time: 22:20:03
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : P $end

    1  P : _ID _EVAL E
    2    | P _SEM P
    3    | _WHILE B _LC P _RC
    4    | _IF B _LC P _RC _ELSE _LC P _RC

    5  B : _BOOL
    6    | E _EQ E
    7    | E _LT E
    8    | E _GT E
    9    | E _ELT E
   10    | E _EGT E
   11    | E _NEQ E
   12    | _NOT B
   13    | B _AND B
   14    | B _OR B

   15  E : E _MINUS E
   16    | _MINUS E
   17    | E _PLUS E
   18    | E _TIMES E
   19    | _LP E _RP
   20    | _ID
   21    | _NUM


##############################################################################
# States
##############################################################################

state 0
	$accept : . P $end

	_WHILE  shift 1
	_ID  shift 2
	_IF  shift 3

	P  goto 4


state 1
	P : _WHILE . B _LC P _RC

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_BOOL  shift 8
	_MINUS  shift 9
	_NOT  shift 10

	E  goto 11
	B  goto 12


state 2
	P : _ID . _EVAL E

	_EVAL  shift 13


state 3
	P : _IF . B _LC P _RC _ELSE _LC P _RC

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_BOOL  shift 8
	_MINUS  shift 9
	_NOT  shift 10

	E  goto 11
	B  goto 14


state 4
	$accept : P . $end  (0)
	P : P . _SEM P

	$end  accept
	_SEM  shift 15


state 5
	E : _LP . E _RP

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 16


state 6
	E : _ID .  (20)

	.  reduce 20


state 7
	E : _NUM .  (21)

	.  reduce 21


state 8
	B : _BOOL .  (5)

	.  reduce 5


state 9
	E : _MINUS . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 17


state 10
	B : _NOT . B

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_BOOL  shift 8
	_MINUS  shift 9
	_NOT  shift 10

	E  goto 11
	B  goto 18


state 11
	B : E . _EQ E
	B : E . _LT E
	B : E . _GT E
	B : E . _ELT E
	B : E . _NEQ E
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E
	B : E . _EGT E

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	_LT  shift 22
	_EQ  shift 23
	_GT  shift 24
	_ELT  shift 25
	_EGT  shift 26
	_NEQ  shift 27


state 12
	P : _WHILE B . _LC P _RC
	B : B . _OR B
	B : B . _AND B

	_LC  shift 28
	_AND  shift 29
	_OR  shift 30


state 13
	P : _ID _EVAL . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 31


state 14
	P : _IF B . _LC P _RC _ELSE _LC P _RC
	B : B . _OR B
	B : B . _AND B

	_LC  shift 32
	_AND  shift 29
	_OR  shift 30


state 15
	P : P _SEM . P

	_WHILE  shift 1
	_ID  shift 2
	_IF  shift 3

	P  goto 33


state 16
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E
	E : _LP E . _RP

	_RP  shift 34
	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21


state 17
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E
	E : _MINUS E .  (16)

	.  reduce 16


state 18
	B : B . _OR B
	B : B . _AND B
	B : _NOT B .  (12)

	.  reduce 12


state 19
	E : E _TIMES . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 35


state 20
	E : E _MINUS . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 36


state 21
	E : E _PLUS . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 37


state 22
	B : E _LT . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 38


state 23
	B : E _EQ . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 39


state 24
	B : E _GT . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 40


state 25
	B : E _ELT . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 41


state 26
	B : E _EGT . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 42


state 27
	B : E _NEQ . E

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_MINUS  shift 9

	E  goto 43


state 28
	P : _WHILE B _LC . P _RC

	_WHILE  shift 1
	_ID  shift 2
	_IF  shift 3

	P  goto 44


state 29
	B : B _AND . B

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_BOOL  shift 8
	_MINUS  shift 9
	_NOT  shift 10

	E  goto 11
	B  goto 45


state 30
	B : B _OR . B

	_LP  shift 5
	_ID  shift 6
	_NUM  shift 7
	_BOOL  shift 8
	_MINUS  shift 9
	_NOT  shift 10

	E  goto 11
	B  goto 46


state 31
	P : _ID _EVAL E .  (1)
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	.  reduce 1


state 32
	P : _IF B _LC . P _RC _ELSE _LC P _RC

	_WHILE  shift 1
	_ID  shift 2
	_IF  shift 3

	P  goto 47


state 33
	P : P _SEM P .  (2)
	P : P . _SEM P

	.  reduce 2


state 34
	E : _LP E _RP .  (19)

	.  reduce 19


state 35
	E : E . _PLUS E
	E : E _TIMES E .  (18)
	E : E . _TIMES E
	E : E . _MINUS E

	.  reduce 18


state 36
	E : E . _PLUS E
	E : E . _TIMES E
	E : E _MINUS E .  (15)
	E : E . _MINUS E

	.  reduce 15


state 37
	E : E _PLUS E .  (17)
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E

	.  reduce 17


state 38
	B : E _LT E .  (7)
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	.  reduce 7


state 39
	B : E _EQ E .  (6)
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	.  reduce 6


state 40
	B : E _GT E .  (8)
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	.  reduce 8


state 41
	B : E _ELT E .  (9)
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	.  reduce 9


state 42
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E
	B : E _EGT E .  (10)

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	.  reduce 10


state 43
	B : E _NEQ E .  (11)
	E : E . _PLUS E
	E : E . _TIMES E
	E : E . _MINUS E

	_TIMES  shift 19
	_MINUS  shift 20
	_PLUS  shift 21
	.  reduce 11


state 44
	P : P . _SEM P
	P : _WHILE B _LC P . _RC

	_RC  shift 48
	_SEM  shift 15


state 45
	B : B . _OR B
	B : B _AND B .  (13)
	B : B . _AND B

	.  reduce 13


state 46
	B : B _OR B .  (14)
	B : B . _OR B
	B : B . _AND B

	.  reduce 14


state 47
	P : P . _SEM P
	P : _IF B _LC P . _RC _ELSE _LC P _RC

	_RC  shift 49
	_SEM  shift 15


state 48
	P : _WHILE B _LC P _RC .  (3)

	.  reduce 3


state 49
	P : _IF B _LC P _RC . _ELSE _LC P _RC

	_ELSE  shift 50


state 50
	P : _IF B _LC P _RC _ELSE . _LC P _RC

	_LC  shift 51


state 51
	P : _IF B _LC P _RC _ELSE _LC . P _RC

	_WHILE  shift 1
	_ID  shift 2
	_IF  shift 3

	P  goto 52


state 52
	P : P . _SEM P
	P : _IF B _LC P _RC _ELSE _LC P . _RC

	_RC  shift 53
	_SEM  shift 15


state 53
	P : _IF B _LC P _RC _ELSE _LC P _RC .  (4)

	.  reduce 4


##############################################################################
# Summary
##############################################################################

26 token(s), 4 nonterminal(s)
22 grammar rule(s), 54 state(s)


##############################################################################
# End of File
##############################################################################
