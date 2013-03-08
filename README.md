pbfi
====

## What?

Preetam's BrainFuck Interpreter.

## Why?

Good question.

## How?

Write some [brainfuck](http://en.wikipedia.org/wiki/Brainfuck) and put it in a file. Here's the mandatory "Hello World!":

```brainfuck
    +++++ +++++
    [
        > +++++ ++
        > +++++ +++++
        > +++
        > +
        <<<< -
    ]
    > ++ .
    > + .
    +++++ ++ .
    .
    +++ .
    > ++ .
    << +++++ +++++ +++++ .
    > .
    +++ .
    ----- - .
    ----- --- .
    > + .
    > .
```

Then pass it to pbfi:

```
    $ ./pbfi bf/hello.bf
    Hello World!
```

## TODO

1. Error handling: weird shit can happen with unbalanced brackets, illegal data ptr increments and decrements

2. REPL-style so you can somewhat know what is going on
