# Robot Development Platform Low Level Drivers

## Coding Conventions
(1) All comments that take up a single-line should use the // style of
    commenting. There should also be a space after the //:  
```
// This is a single-line comment.
```

(2) Standard multi-line comments should be of this form:  
```
/*
 * Notice that there are no words on the first line or last line of the
 * multi-line comment.
 * Also notice that there's (without the quotes) a "[space]*[space]" at the
 * start of each line between the first line and the last line.
 */
```

(3) Emphasised multi-line comments must have their second-line start
    (without the quotes) with: "[space]*[space]Note:[space]"
    They should be of this form:  
```
/***************************************************
 * Note: This is an emphasised multi-line comment. *
 ***************************************************/
```

(4) All lines should be 80 characters long or less.

(5) There should be no tab characters in any of the files.

(6) The standard indentation is 4 spaces.

(7) All blocks must use curly-braces, including blocks that have only 1 line in
    their body.
    There should be a space to the left of the opening-curly-brace.
    The opening-curly-brace should be on the same line as the head of the block.
    Example:  
```
if (x == 'a') {
    printf("x is the first letter of the alphabet.\n");
}
```

(8) For all blocks that contain at least 1 statement that isn't a null-statement,
    the closing-curly-brace should be the first non-white-space character of the
    line it appears on.
    Example:  
```
if (x == 'a') {
    printf("x is the first letter of the alphabet.\n");
}
```

(9) For all blocks that contain only one statement where that statement is a
    null-statement, the entire body of the block should be on the same line as
    the head of the block. The body should be (without the quotes) exactly
    this: "{ ; }".
    Example:  
```
while (get_bit(ADCSRA, ADSC)) { ; }
```

(10) This is an example of how an [if | else if | else] chain of blocks should be
    set-out:  
```
if (x == 'a') {
    printf("x is the first letter of the alphabet.\n");
} else if (x == 'b') {
    printf("x is the second letter of the alphabet.\n");
} else {
    printf("x is neither the first nor the second letter of the alphabet.\n");
}
```

(11) All library functions must be defined in header files. Header files are files
    that end (without the quotes) with ".h".

(12) All library functions should just be defined, never declared then defined:  
```
// Example of a function declaration:
uint16_t RDAddTwoNumbers(int x, int y); // DON'T DO THIS!

// Example of a function definition:
uint16_t RDAddTwoNumbers(int x, int y) {
    return (x + y);
}
```

(13) Every function should have a header comment of the same form as this header
     comment:  
```
/*
 * Reads an analog signal
 * 
 * @param unsigned char channel
 *     The pin that should be read
 *
 * @param unsigned char mode
 *     The mode can be MODE_8_BIT or MODE_10_BIT
 *     if mode == MODE_8_BIT, the resolution will be 256
 *     if mode == MODE_10_BIT, the resolution will be 1024
 * 
 * @return uint16_t
 *     Digital representation of analog signal
 */
uint16_t RDAnalogRead(unsigned char channel, unsigned char mode) {
    // Code of function body
    // ...
    // ...
    // ...
}
```

(14) All library function names should start (without the quotes) with "RD".
     The first letter of every word after RD in the function name should start
     with a capital-letter.
     Example:  
```
void RDPrintHello() {
    printf("Hello.\n");
}
```

(15) All macros, both object-like (macros that DO NOT have parameters) and
     function-like (macros that DO have parameters), must have identifiers that
     are all uppercase. If the identifier contains multiple words, they should
     be separated with underscores.
     Example:  
```
#define NUMBER_OF_SIDES_OF_SQUARE 4
```

(16) All definitions of function-like macros must have a set of round-brackets
     surrounding the replacement-list, as well as a set of round-brackets
     surrounding every individual reference, within the replacement-list, to a
     parameter of the macro. Also, there must be no white-space between the
     identifier of the macro and the first opening-round-bracket (otherwise the
     preprocessor will treat the macro as an object-like macro instead of as a
     function-like macro):
```
// Example of a function-like macro with all of the required round-brackets:
#define ADD_TWO_NUMBERS(x, y) ((x) + (y))
/*
 * In case you don't know what the term "replacement-list" means,
 * in the function-like macro immediately above this comment, the
 * replacement-list (without the quotes) is: "((x) + (y))".
 */
```

## Glossary
### Analog to Digial Converter
    * ADC.........Analog to Digital Converter
    * ADCH........ADC High byte
    * ADCSRA......ADC Control & Status Register A
    * ADCSRB......ADC Control & Status Register B
    * ADEN........ADC Enable
    * ADLAR.......ADC Left Adjust Result
    * ADMUX.......ADC Multiplexer Selection Register
    * ADSC........ADC Start Conversion

