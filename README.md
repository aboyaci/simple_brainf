# Simple Brainf Interpreter

A simple brainf interpreter which can handle nested loops.

## About brainf

Brainf is a imperative, tape-based, one-dimensional turing complete programming language designed by Urban Müller in 1993. It has 8 commands and 

More: https://esolangs.org/wiki/Brainfuck

## Commands

	> increment the data pointer
	< decrement the data pointer
	+ increment the data at the data pointer
	- decrement the data at the data pointer
	. output the data at the data pointer
	, read input, storing the data at the data pointer
	[ if the data at the pointer is zero, instead of moving the instruction pointer forward one, jump it forward to the command after the matching ] command
	] if the data at the pointer is nonzero, instead of moving the instruction pointer forward, jump it back to the command after the matching ] command
	
## How to Build

	make

## How to run

	./bf hello.b
	
## Hello world!

	++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.