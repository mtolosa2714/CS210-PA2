# Developer Log (DEVLOG.md)

Minimum **6 entries** required.

### Entry 1
**Date:** 2026-04-20
**What I worked on:** I worked on implementing the functions of push, pop, top, size, and empty.
**Bugs or issues I encountered:**  I did not encounter any bugs or issues.
**How I tested the code:**  I created a temporary code in main.cpp that created a basic stack and checked if the functions gave the correct value when ran. 
**What I fixed or improved:** I did not have to fix or improve anything at this point
**Commit(s):** 1 and 2

---

### Entry 2
**Date:** 2026-04-21  
**What I worked on:** I made the tokenizer function that breaks the string into tokens
**Bugs or issues I encountered:**  I had problems with numbers that were more than single digits.
**How I tested the code:**  I tested using basic inputs like 3 + 4 * 2
**What I fixed or improved:** I made sure the tokenizer uses full numbers and separates the operators and parentheses
**Commit(s):**  3

---

### Entry 3
**Date:** 2026-04-26  
**What I worked on:** I made the precedence, postfix validation and evaluation functions
**Bugs or issues I encountered:**   I had to make sure the lefts and rights were working properly, specifically for the subtraction and division.
**How I tested the code:**  I used test inputs to make sure the validation and evalution functions returned the right thing.
**What I fixed or improved:** I did not have to fix or improve thi section of the code
**Commit(s):** 4, 5, and 6

---

### Entry 4
**Date:** 2026-04-27
**What I worked on:** I made the infix validation function
**Bugs or issues I encountered:**  I figured out how to track if the program was going to get a number, parenthesis, or operator
**How I tested the code:**  I used test inputs again, first valid ones and then invalid ones
**What I fixed or improved:** I added more logic to check the order and made sure the parentheses are balanced
**Commit(s):** 7

---

### Entry 5
**Date:** 2026-04-29
**What I worked on:** I worked on converting infix expressions into postfix format
**Bugs or issues I encountered:**  I had trouble making sure the operators were coming out in the right order based on precedence
**How I tested the code:**  I tested with inputs to make sure the postfix output matched what it should be
**What I fixed or improved:** I adjusted how operators were popped from the stack so higher or equal precedence ones came out first
**Commit(s):** 8

---

### Entry 6
**Date:** 2026-05-01
**What I worked on:** I connected everything together in main and fixed the tokenizer and infix conversion so the program works 
**Bugs or issues I encountered:** I had an issue where the last number in the input was not being added to the tokens and also accidentally put "(" into the output instead of the stack in infixToPostfix
**How I tested the code:**  I tested different inputs like postfix expressions, infix expressions, and invalid ones to make sure it printed the correct format and result
**What I fixed or improved:** I fixed the tokenizer to always include the last number and corrected how parentheses are handled so the postfix output is correct
**Commit(s):** 9
