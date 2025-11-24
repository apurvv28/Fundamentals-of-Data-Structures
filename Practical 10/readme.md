# Infix to Prefix and Postfix Converter

## Overview
A C++ program that converts infix expressions to both prefix and postfix notation using stack operations, and also evaluates the resulting postfix expressions. This implementation demonstrates fundamental concepts in compiler design and expression parsing.

## Features

### 1. Expression Conversion
- **Infix to Postfix**: Converts standard infix notation to postfix (Reverse Polish Notation)
- **Infix to Prefix**: Converts infix notation to prefix (Polish Notation)

### 2. Expression Evaluation
- **Postfix Evaluator**: Computes the numerical value of postfix expressions
- **Supports**: Basic arithmetic operations (+, -, *, /, ^)

## Algorithm Details

### Infix to Postfix Conversion
1. **Parenthesis Handling**: Adds surrounding parentheses to ensure proper operator precedence
2. **Operand Detection**: Identifies alphabetic characters and digits as operands
3. **Stack Management**: Uses stack to handle operator precedence and parentheses
4. **Operator Precedence**: Implements priority-based operator placement

### Infix to Prefix Conversion
1. **String Reversal**: Reverses the infix expression
2. **Parenthesis Swapping**: Converts '(' to ')' and vice versa
3. **Postfix Conversion**: Uses the infix-to-postfix algorithm on reversed expression
4. **Final Reversal**: Reverses the result to get prefix notation

### Postfix Evaluation
1. **Operand Stack**: Uses stack to store numerical values
2. **Operator Processing**: Pops operands and applies operators
3. **Result Calculation**: Returns the final computed value

## Operator Precedence

| Operator | Precedence Level |
|----------|------------------|
| `^`      | 3 (Highest)      |
| `*`, `/` | 2                |
| `+`, `-` | 1                |
| `(`, `)` | 0                |

## Code Structure

### Key Functions

1. **`isOperator(char c)`**
   - Checks if a character is an operator
   - Returns boolean value

2. **`getPriority(char C)`**
   - Returns precedence level of operators
   - Higher number indicates higher precedence

3. **`infixToPostfix(string infix)`**
   - Main conversion algorithm
   - Returns postfix string

4. **`infixToPrefix(string infix)`**
   - Uses reversal and postfix conversion
   - Returns prefix string

5. **`evaluatePostfix(string postfix)`**
   - Computes numerical result
   - Returns integer value

## Usage Examples

### Input:
```
Enter Infix Expression: a+b*c
```

### Output:
```
Postfix Expression: abc*+
Prefix Expression: +a*bc
Postfix Evaluation: [numerical result if digits used]
```

### Supported Operations:
- **Addition**: `a + b`
- **Subtraction**: `a - b`
- **Multiplication**: `a * b`
- **Division**: `a / b`
- **Exponentiation**: `a ^ b`

## Compilation and Execution

### Requirements:
- C++ compiler with STL support
- `<bits/stdc++.h>` header (GCC compiler)

### Compilation Command:
```bash
g++ -o expression_converter program.cpp
./expression_converter
```

## Input Guidelines

1. **Use single-character variables** or digits for evaluation
2. **Supported operators**: +, -, *, /, ^
3. **Parentheses** are supported for grouping
4. **Spaces** are allowed but not required

## Example with Evaluation

### Input:
```
Enter Infix Expression: 2+3*4
```

### Output:
```
Postfix Expression: 234*+
Prefix Expression: +2*34
Postfix Evaluation: 14
```

## Technical Details

### Time Complexity
- **Conversion**: O(n) where n is expression length
- **Evaluation**: O(n) for postfix evaluation

### Space Complexity
- O(n) for stack operations

### Data Structures Used
- **Stack**: For operator management and expression evaluation
- **String**: For expression manipulation and storage

## Error Handling
- The program assumes valid infix expressions
- No explicit error checking for malformed expressions
- Division by zero may cause runtime errors during evaluation

## Applications

1. **Compiler Design**: Expression parsing in programming languages
2. **Calculator Development**: Scientific calculator implementations
3. **Expression Evaluation**: Mathematical computation systems
4. **Educational Tool**: Learning stack operations and expression parsing

## Learning Outcomes

This implementation demonstrates:
- Stack data structure applications
- Operator precedence handling
- Expression parsing algorithms
- Postfix notation advantages for evaluation
- String manipulation techniques
- Algorithm design for expression conversion
