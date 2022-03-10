# Midterm Exam Notes

## Core Intro Concepts

Types of programming languages

- functional
- logic (consstraint)
- procedural
- object oriented

Scope of programming languages

- Turing Complete (can compute any traditional thing (python with infinite memory, using only a finite amount at any given time).
- Limited in scope.

Computational Model

- VonNeumann Architecture
  - [stack top going down]
  - [ lots of air ]
  - [ heap going up with holes in free list ]
  - [ global variables ]
  - [ constants (literals)]
  - [ text / code ]

  - CPU model is processor, executing code from the text, and creating stack frames as it calls functions/methods/procedures and remove them on return.   (Threaded has lots of CPU's and 1 stack per CPU).

- Neural Network (graph directed down)
-    i.......i.......i  [input layer]
-     \ ... /        |
-        n           n
-        \...........|
-              o        [output layer]
- Rule: each edge has a weight
- The current nodes in a layer have values.
-   value(n) = sigmoid(sum over all predicessors (weight * p))
- Machine Learning is all about designing and training these kinnds of graphs (optimizing the graph structure, and the weights.
- Non traditional model, but the graphs are big.
- So traditional programming langueas are used to describe the graph, and the data sets to optimize. (python)



- Quantum Computer

- fixed known inputs, define a probabilty distribution of all inputs.
- QC determines the pd of the output.

- There are classical sims for this and languages for this as well.

Example: solve something simple in a functional or procedural style.   Ex: factorial.

rec/func: 
 int fact(int n) {
     return n > 1 ? fact(n-1) * n : 1;
 }

 iter:
 int fact(int n) {
   int ans = 1;
   for (int i=2; i<=n; ++i) {
       ans = ans * i;
   }
   return ans;
 }

 Promise this question: why do immutable objects and functional programming style go well together?

 Promise: what is an object?

 Objects tie state with methods that they are modified by or interact with.  They are usually nouns in the description of a problem space: Car, NetworkID, Socket.  Making them are instances  (Car fiat), instances have public and private parts  (fiat.drive() vs. fiat.m_timingPhaseAngle).  This simplifies using them correctly.

 Immutable objects cannot be modifed. python numbers are immutable objects.   3 += 1 would be really complex to follow.

 With immutable objects you can't do this:

double readMileage(Car &car) {
   car.start();
   double ans = car.odometer();
   car.stop();
   return ans;
}

if this code exited early (car.odometer() failed by throwing bad_odometer exception) you would end up with a running car.

double readaMileage(const Car &car) {
    ++carsISawToday;
   Car started(car.createStartedCar());
   return started.odimeter();
}

Some languages are purists.  Why?

Regular Expressions

EBNF/BNF

Describe this set of strings: 
```
  <start> ::= <<start>> a | b
```
Top Down vs Bottom up

Ambiguity
Parse Tree

Exam 17 of March!



