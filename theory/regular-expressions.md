# Regular Expressions

Notation for describing a set of strings.

- What is an email?
- What is phone #?
- What is a number?
- What is an id?

Usually infinite sets of strings.  Notation that is built from parts.

## Empty RE
the empty regular expression
mathes the empty string

## Letter RE
some "normal" letter x

x as a re (regular expression) matches exactly the string "x"

## r1 followed by r2: r1 r2 matches any string s that could be broken into two (posibly empty) parts s1 s2, where s1 matches r1 and s2 matches r2.

## r1 or r2: r1 | r2
 matches any string s that matches r1, or matches r2 (or both).

Ex
  r() - {""}

  r(a) - {"a"}

  r(b) - {"b"}

  r(ab) 
  - {s=s1+s2|s1 in r(a) and s2 in r(b)}
  - {s=s1+s2|s1 = "a", s2 = "b"}
  - {"ab"}

  r(a|b) 
  - {s|s in r(a) or s in r(b)}
  - {s| s = "a" or s = "b"}
  - {"a","b"}

  r(cat|dog)
  - {s|s in r(cat) or s in r(dog)}
  - {"cat","dog"}

  r((cat|dog)(|s))
  - {s|s=s1+s2 where s1 in r(cat|dog) and s2 in r(|s) }
  - {s|s=s1+s2 where (s1 = "cat" or s1 = "dog") and s2 in {"","s"} }
  - {"cat","cats","dog","dogs"}

  r(|s)
  - {S|S in r() or S in r(s)}
  - {"","s"}

  r(cat)
  - {s|s=s1+s2+s3|s1 = "c" and s2 = "a" and s3 = "t"} = {"cat"}

  r(R*)
  - r(|R|RR|RRR|RRRR|...) 0 or more R's.

  r(R{a,b})
  - r(RRR (a copies)|...| RRRR(b copies))

r((0|1|2|3|4|5|6|7|8|9)
  (0|1|2|3|4|5|6|7|8|9)*)
  - {"0","1",..."9","00","01",..,"09"}
  - "00000000"

Digit = (0|..|9)
PositiveDigit=(1|..|9)
Decimal = r(0|(PositiveDigit|Digit*))
  = {"0","1","324908574239805732457890",
      but not "003323"}

Letter=(A|..|Z|a|..|z)
Separator=(-|_|+)
User = (Letter|(Letter|Digit|Separator)*)
Domain = (((Letter|Digit)(Letter|Digit)*(|.))){1,}(.edu|.com|.org))

EMail = User@Domain

___----___--dsfsdf09877890

[-A-Za-z0-9._]=(-|A|..|Z|a|..|z|0|..|9|.|_)

:digit:
:letter:
* - 0 or more
+ - 1 or more
{n,m} - from n to m copies
{n,} n or more

()
\(\)
|
\|

Assignment: write RE for C identifier, and a double literal.  x, _x, MyBananas, 

-1.233
1.33
0.233
0.333e-34

Use the C++ regex library for a matcher and tests.

