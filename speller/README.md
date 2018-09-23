# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

Yi ge jia de cir

## According to its main page, what does `getrusage` do?

calculates the time needed for the program to complete the task

## Per that same main page, how many members are in a variable of type `struct rusage`?

2 members (before and after)

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

it is more efficient cause using the value would lead to copying them while calculating

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

the speller program iterates over each symbol of a specific text until it is indicated that a \n is identified or other special character (indicating the end of a word), then
checks if this word is in our dictionary, then repeats the process again until we have checked every single word in the text

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc allows us to be more flexible in our implementation. we get to identify more characters that indicate the end of a word

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

simple to make sure the content of the dictionary will not be altered
