# Gherkin-Cpp

*PLEASE NOTE - THIS IS A WORK IN PROGRESS*

This project is to create a parser for the Gherkin language used in Behavioural Driven Development (Given-When-Then).

This is designed as a library that other software can use to parse Gherkin text files into an Abstract Syntax Tree (AST).

A simple example of the Gherkin Language:

```
Feature: A really useful thing

    As a user
    I want to a thing that does something useful
    So that I can be impressed by its usefulness

Scenario: Usefulness is apparent

    Given that I have a useful thing
    When I apply it to a task
    Then it does something useful
```

## See Also

* [Pepper](https://github.com/dmeehan1968/Pepper) - A BDD Library for C++.  Uses Gherkin-Cpp for parsing of .feature files.

