Logic Languages

- Specify what needs to be done or what constraints need to be satisfied, what needs to be true in the end.

Layout engine use this.  "this should be above that" and to the left of this thing".

Logic programming is also a part of more languages, because it does not micromanage the problem.  

In SQL SELECT COUNT(*) FROM USERS WHERE (LastLogin > 365)  just specifies the question (constraint), but not how to coompute that.

Functional.

Output = SomeFunctionOf(Input)

RecommendedSeatAssignements = SeatSelector(Passenger,Airplane,Flight)

Functional Anti-Pattern:

Global bool passengerIsFirstClass = true/false;

RecommendedSeatAssignements = SeatSelector(Passenger,Airplane,Flight)
   if (firstclass) ...
   else ...

List ans = []
for (;;) {

    // make a new list with one more
    // element (this is functional)
    ans = append(ans,nextSeat);

    // modify the list (not functional)
    ans.append(nextSeat);
} 

What is a regular expression?

RE describe sets of strings.

Ex: C id:   [A-Za-z_][A-Za-z0-9_]*

-?(0|([1-9][0-9]*))

(if|else|while|do|const)

Reg libraries, can convert RE's into
matchers, that can identify weather something is in the set or not.

   plain letter x - {"x"}

   abc - {string s | s can be split into (maybe empty)  x + y + z so that x in a, y in b, z in c}

   a|b|c - { s in a or s in b or s in c}

   a{n,m} a repeated n to m times
   a{3,5}=(aaa|aaaa|aaaaa)

   a*=a{0,infinity}
   a+=a{1,infinity}
   a?=a{0,1}

   [A-C1-3]=(A|B|C|1|2|3)

What is a context-free grammar?

   Used to define valid sentences in a language.

   Like RE, they define a set of strings.   But they are more general.

   <e> <<e>> <<<e>>>

   <e>|<<e>>|<<<e>>>

   EXP := 'e' | '<' EXP '>'


   Non-Terminals (EXP) and temainals 'e' and '<' and '>' above.  Often terminals are described with regular expressions (literals "cat" 37), but
   these are combined into semantic components using the grammar.

   <statement> := <if-statement> | <while-statement>

   <if-statement> := if '(' <expression> ')' <statement> <optional-else-statement>

   <optional-else-statement> := | else <statement>

Object vs. Immutable Object

objects have state/properties + methods.  Immutable object cannot change state or properties after construction.

c++ strings are mutable ( += works , you can append to a string).

javascript, python, java, strings are immutable, there is no way to change a string.   

   c++ string s = "hello"; s += " world"; // ok
        s = "hello"; s = s + " world";

    const string GREEN = "green";

    const GREEN = "green";


    // GREEN.clear(); GREEN.append("blue");

    
