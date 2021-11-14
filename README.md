# The Algorithms
 This is the repo I learned MIT 6.006 Introduction to Algorithms.

# 1.Introduction

:dart: The goal is to **solve** computation problems, and to **communicate** that your solutions are **correct** and **efficient**.

This lecture covers following topics:

- algorithm - to know what it is first
- correctness - then to define what is correct
- efficiency - evaluate the efficiency
- model of computation - how to compute and integrate algorithm in computation
- data structure - how data structure can help



## 1.1. Algorithm

:pushpin:**What is a algorithm?**

It has following properties:

- Procedure mapping each input to a **single** output (deterministic)

- Algorithm **solves** a problem if it returns a correct output for every problem input



:pushpin:**Example of an algorithm**

An algorithm to see whether there are students with same birthday in a same classroom.

A. Maintain a record of names and birthdays(initially empty)

B. Interview each student(loop)

​	B.1. *if* birthday exists in record, return found(**true**)

​	B.2. *else* add name and birthday to record(**false**)

C. Return **None** if last interviewed student without success



## 1.2. Correctness

:thinking: **How** to **prove** the **correctness** of an algorithm?

- For **small** inputs, can use case analysis
- :star:For arbitrarily **large** inputs, algorithm must be **recursive** or **loop**
  - Normally use **induction** to prove the correctness



:pushpin:**Example of Proof**

Following are the steps of proof on the last birthday matching problem.

1. Induct on $k$: the number of students in the classroom
2. **Hypothesis**: if first $k$ contains match, returns match(TRUE) before asking $k+1$ student
3. **Base case**: $k=0$, first $k$ does not contain match
4. Assume for induction hypothesis holds for $k = k'$, and consider $k = k' +1$ (saying in coding context, if not found, continue...)
5. If first $k'$ contains a match, already returned a match by induction
6. Else first $k'$ do not have match, so if first $k' +1$ has match, match contains $k' +1$
7. Then algorithm checks directly whether birthday of student $k' +1$ exists in first $k'$



:page_with_curl:Side Notes:

$k'$​ is nothing else but an arbitrary number



## 1.3. Efficiency

Once the algorithm is proved correct, it has to be measured in efficiency. 



:pushpin:**What is the rule to measure efficiency?**

- **machine independent** -> meaning we don't evaluate with machines because a same algorithm may have different performance on different computer!
- **Quantify OPS** -> meaning counting number of fixed-time operations algorithm takes to return
- **inputs:arrow_up_small:time:arrow_up_small:** -> meaning the size of input directly affect the time of computation
- **$n$** -> usually the amount of input is denoted as $n$
- **polynomial $n^c$​** -> meaning the algorithm is efficient enough if it returns in polynomial computation time with respect to amount of input
- **None** -> meaning sometimes an efficient algorithm does not exist.



:pushpin: **Asymptotic Notation**

$\Omicron$ - Upper bounds

$\Omega$ - Lower bounds

$\Theta$ - tight bounds

$\in$ - is

$=$ - order



:pushpin:**Example of Asymptotic Notation**

The following equations

1. *T*(*n*) = $\Omicron(n^{100})$
2. *T*(*n*) = $\Omega(n^3)$
3. *T*(*n*) = $\Theta(n^3)$

in English

1. *T*(*n*) grows asymptotically **no faster** than $n^{100}$
2. *T*(*n*) grows asymptotically **no slower** than $n^3$
3. *T*(*n*) grows asymptotically **as fast as** $n^3$



:pushpin:**Efficiency Table**

| input | constant    | logarithmic      | linear      | log-linear        | quadratic      | polynomial    | exponential                 |
| ----- | ----------- | ---------------- | ----------- | ----------------- | -------------- | ------------- | --------------------------- |
| $n$   | $\Theta(1)$ | $\Theta(\log n)$ | $\Theta(n)$ | $\Theta(n\log n)$ | $\Theta (n^2)$ | $\Theta(n^c)$ | $2^{\Theta(n^c)}$           |
| 1000  | 1           | $\approx$10      | 1000        | $\approx$10,000   | 1,000,000      | 1000$^c$      | 2$^{1000}\approx$10$^{301}$ |
| Time  | 1 $ns$      | 10 $ns$          | 1 $\mu s$   | 10$\mu s$         | 1$ms$          | 10$^{3c-9}$s  | 10$^{281}$ millenia         |



:pushpin:**Efficiency Chart**

<img src="https://upload.wikimedia.org/wikipedia/commons/7/7e/Comparison_computational_complexity.svg" alt="efficiency_chart" 	title="efficiency_chart" width="400" height="400" />



## 1.4. Model of Computation

:pushpin:**Why?**

To **precisely calculate** the resources used by an algorithm, we need to model how long a computer takes to perform basic operations.

:pushpin:**What is RAM?**

RAM is Random Access Memory. It is an internal memory that **exchanges data directly with the CPU**.

:pushpin:**What is Word-RAM**?

In reality, the interaction between CPU and RAM can be very **complicated**. Therefore in this class, the lecturers coined Word-RAM:laughing:. A Word-RAM processor can perform basic binary operations on two machine words in constant time. 

:pushpin:**Example of Word-RAM**

$w$-bits Word-RAM allows you to read and write from at most $2^w$ addresses in memory.

$4$-bits Word-RAM allows you to read and write from at most $16$ addresses in memory. Like:

| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   | 12   | 13   | 14   | 15   | 16   |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| V    | J    | O    | T    | R    | B    | L    | R    | E    | S    | V    | Z    | P    | O    | M    | B    |

:pushpin:**Requirement of $w$**

Suppose we need to read $n$ words, what is the **minimum** bits of this Word-RAM?
$$
\begin{align}
2^w &> n\\w&>\log_2(n)
\end{align}
$$
:pushpin:**Basic Operation on processor**

Normally, we suppose the processor supports many **constant time operations** on a $\Omicron(1)$ number of words (integers):

- **integer arithmetic**: $(+, -, *, /, \%)$
- **logical operators**: $(\&\&, ||, !, ==, <, >, <=, =>)$
- **bitwise arithmetic**: $(\&, |, <<, >>, ...)$
- **read & write**: Given word $a$, can read word at address $a$, write word to address $a$



## 1.5. Data Structures

:pushpin:**What is data structure?**

A **data structure** is **a way to store a non-constant amount of data**, supporting a set of operations to interact with that data.

:pushpin:**What is interface?**

The set of operations supported by a data structure is called an **interface**. (:warning: The interface here is not the one in C# e.g. `IEnumerable`)

Example:

- `List<T>` has the interface of `Add()`

- `Dictionary<TKey, TValue>` has the interface of `Add()`

- :warning: They are with same operation but their logic behind are highly different.



:pushpin:**Why data structures are important?**

The data structures determine **how to store data highly affect the runtime** of such a algorithm.

- Many data structures might support the same interface, but could provide different performance for each operation. 

- Many problems can be solved trivially by storing data in an appropriate choice of data structure.





# 2.Data Structures







# 3.Sorting
