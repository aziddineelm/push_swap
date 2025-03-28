# Push_swap  

**Push_swap** is a project from the 42/1337 curriculum that challenges students to sort a stack of integers using only two stacks (`a` and `b`) and a limited set of operations, aiming for the least number of moves.  

---

## 📋 **Project Description**  
The goal of this project is to develop a program that:  
- Sorts a stack of integers efficiently.  
- Uses a predefined set of operations.  
- Minimizes the number of moves.  
- Handles edge cases like duplicate numbers and already sorted stacks.  

This project is a great way to deepen your understanding of algorithms, stack manipulation, and optimization techniques.  

---

## 🛠️ **How It Works**  
The program implements a sorting algorithm using two stacks and a set of operations to rearrange elements optimally. It continuously moves elements between stacks `a` and `b` until the original stack is sorted.  

---

## 🚀 **Features**  
- It implements an efficient sorting algorithm.  
- Uses only the allowed operations.  
- Optimized to minimize the number of moves.  
- It handles various input cases, including edge cases.  

---

## 📂 **Repository Structure**  
```
.
├── push_swap.c        
├── sorting.c          
├── larg_sort.c        
├── operations_a.c     
├── operations_b.c     
├── stack_utils.c      
├── array_utils.c      
├── list_utils.c       
├── string_utils.c     
├── ft_split.c         
├── memory.c           
├── validation.c       
├── push_swap.h        
├── Makefile           
└── bonus/   
```

## 📜 **Allowed Operations**  
- `sa`: Swap the first two elements of stack `a`.  
- `sb`: Swap the first two elements of stack `b`.  
- `ss`: Perform `sa` and `sb` simultaneously.  
- `pa`: Push the top element from stack `b` to stack `a`.  
- `pb`: Push the top element from stack `a` to stack `b`.  
- `ra`: Rotate stack `a` (shift all elements up, first element becomes last).  
- `rb`: Rotate stack `b` (shift all elements up, first element becomes last).  
- `rr`: Perform `ra` and `rb` simultaneously.  
- `rra`: Reverse rotate stack `a` (shift all elements down, last element becomes first).  
- `rrb`: Reverse rotate stack `b` (shift all elements down, last element becomes first).  
- `rrr`: Perform `rra` and `rrb` simultaneously.  

---

## 🏆 **Evaluation Criteria**  
- The program must not use standard sorting functions.  
- It must handle edge cases efficiently (duplicates, already sorted inputs, etc.).  
- The number of operations should be minimized.  
