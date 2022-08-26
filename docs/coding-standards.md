
---
title: Coding Standards
author: Lautaro Bachmann
---
\maketitle
\newpage
\tableofcontents
\newpage

# Source
Based on *Clean Code, by Robert C. Martin*

\newpage

# Comments


## Inappropriate Information

It is inappropriate for a comment to hold information better held in a different kind of system such as your source code control system, your issue tracking system, or any other record-keeping system.
meta-data
should not appear in comments.
Comments should be reserved for technical notes about the code and design.


## Obsolete Comment

Comments get old quickly. It is best not to write a comment that will become obsolete.
Obsolete comments tend to migrate away from the code they once described.


## Redundant Comment

A comment is redundant if it describes something that adequately describes itself.

Comments should say things that the code cannot say for itself.


## Poorly Written Comment

A comment worth writing is worth writing well. If you are going to write a comment, take the time to make sure it is the best comment you can write.


## Commented-Out Code

That code sits there and rots, getting less and less relevant with every passing day.
It pollutes the modules that contain it and distracts the people who try to read it. Commented-out code is an abomination.
**When you see commented-out code, delete it!**
the source code control system still remembers it. If anyone really needs it, he or she can go back and check out a previous version.


\newpage

# Functions


## Too Many Arguments

Functions should have a small number of arguments. 
More than three is very questionable and should be avoided with prejudice.


## Output Arguments

Output arguments are counterintuitive.

## Flag Arguments

Boolean arguments loudly declare that the function does more than one thing. They are confusing and should be eliminated.


## Dead Function

Methods that are never called should be discarded. Keeping dead code around is wasteful.


\newpage

# General


## Incorrect Behavior at the Boundaries

It seems obvious to say that code should behave correctly. The problem is that we seldom realize just how complicated correct behavior is.
Don’t rely on your intuition. Look for every boundary condition and write a test for it.


## Overridden Safeties

It is risky to override safeties.
Turning off certain compiler warnings
may help you get the build to succeed, but at the risk of endless debugging sessions.
Turning off failing tests and telling yourself you’ll get them to pass later is as bad as pretending your credit cards are free money.


## Duplication

**This is one of the most important rules in this book, and you should take it very seriously.**

Every time you see duplication in the code, it represents a missed opportunity for abstraction.
That duplication could probably become a subroutine or perhaps another class outright.

Coding becomes faster and less error prone because you have raised the abstraction level.

Still more subtle are the modules that have similar algorithms, but that don’t share similar lines of code. 

Find and eliminate duplication wherever you can.


## Code at Wrong Level of Abstraction

It is important to create abstractions that separate higher level general concepts from lower level detailed concepts.
We want all the lower level concepts to be in the derivatives and all the higher level concepts to be in the base class.
constants, variables, or utility functions that pertain only to the detailed implementation should not be present in the base class.
The base class should know nothing about them.
Good software design requires that we separate concepts at different levels and place them in different containers.

Isolating abstractions is one of the hardest things that software developers do, and there is no quick ﬁx when you get it wrong.


## Too Much Information

Well-deﬁned modules have very small interfaces that allow you to do a lot with a little. Poorly deﬁned modules have wide and deep interfaces that force you to use many different gestures to get simple things done.
A poorly deﬁned interface provides lots of functions that you must call, so coupling is high.

Good software developers learn to limit what they expose at the interfaces of their classes and modules.
**The fewer methods a class has, the better.**
The fewer variables a function knows about, the better. The fewer instance variables a class has, the better.
Hide your data. Hide your utility functions. Hide your constants and your temporaries. Don’t create classes with lots of methods or lots of instance variables. Don’t create lots of protected variables and functions for your subclasses. Concentrate on keeping interfaces very tight and very small. Help keep coupling low by limiting information.


## Dead Code

Dead code is code that isn’t executed. You ﬁnd it in the body of an if statement that checks for a condition that can’t happen. You ﬁnd it in the catch block of a try that never throws.
The problem with dead code is that after awhile it starts to smell.
dead code is not completely updated when designs change.
It was written at a time when the system was different.
**When you ﬁnd dead code, do the right thing. Give it a decent burial. Delete it from the system.**


## Vertical Separation

Variables and function should be deﬁned close to where they are used.
We don’t want local variables declared hundreds of lines distant from their usages.
Private functions should be deﬁned just below their ﬁrst usage.


## Inconsistency

If you do something a certain way, do all similar things in the same way.
Be careful with the conventions you choose, and once chosen, be careful to continue to follow them.
Simple consistency like this, when reliably applied, can make code much easier to read and modify.


## Clutter

Variables that aren’t used, functions that are never called, comments that add no information, and so forth.
All these things are clutter and should be removed. Keep your source ﬁles clean, well organized, and free of clutter.


## Artiﬁcial Coupling

Things that don’t depend upon each other should not be artiﬁcially coupled.
In general an artiﬁcial coupling is a coupling between two modules that serves no direct purpose. It is a result of putting a variable, constant, or function in a temporarily convenient, though inappropriate, location. This is lazy and careless.


## Selector Arguments

Not only is the purpose of a selector argument difﬁcult to remember, each selector argument combines many functions into one.
Selector arguments are just a lazy way to avoid splitting a large function into several smaller functions.

It’s bad enough that you must remember what calculateWeeklyPay(false) means whenever you happen to stumble across it.


## Obscured Intent

We want code to be as expressive as possible.
Run-on expressions, Hungarian notation, and magic numbers all obscure the author’s intent.


## Misplaced Responsibility

One of the most important decisions a software developer can make is where to put code.
The principle of least surprise comes into play here. Code should be placed where a reader would naturally expect it to be.
Sometimes we get “clever” about where to put certain functionality. We’ll put it in a function that’s convenient for us, but not necessarily intuitive to the reader.

## Use Explanatory Variables

One of the more powerful ways to make a program readable is to break the calculations up into intermediate values that are held in variables with meaningful names.

It is hard to overdo this. More explanatory variables are generally better than fewer.


## Function Names Should Say What They Do

If the function adds ﬁve days to the date and changes the date, then it should be called addDaysTo or increaseByDays.
on the other hand, the function returns a new date that is ﬁve days later but does not change the date instance, it should be called daysLater or daysSince.
If you have to look at the implementation (or documentation) of the function to know what it does, then you should work to ﬁnd a better name or rearrange the functionality so that it can be placed in functions with better names.


## Understand the Algorithm

Lots of very funny code is written because people don’t take the time to understand the algorithm.

Before you consider yourself to be done with a function, make sure you understand how it works. It is not good enough that it passes all the tests. You must know that the solution is correct.
Often the best way to gain this knowledge and understanding is to refactor the function into something that is so clean and expressive that it is obvious how it works.

## Follow Standard Conventions

Every team should follow a coding standard based on common industry norms.
This coding standard should specify things like where to declare instance variables; how to name classes, methods, and variables; where to put braces; and so on.

Everyone on the team should follow these conventions.


## Replace Magic Numbers with Named Constants

This is probably one of the oldest rules in software development.
In general it is a bad idea to have raw numbers in your code. You should hide them behind well-named constants.

The term “Magic Number” does not apply only to numbers. It applies to any token that has a value that is not self-describing.


## Be Precise

Expecting the ﬁrst match to be the only match to a query is probably naive. Using ﬂoating point numbers to represent currency is almost criminal.
When you make a decision in your code, make sure you make it precisely.
Know why you have made it and how you will deal with any exceptions.
Ambiguities and imprecision in code are either a result of disagreements or laziness. In either case they should be eliminated.


## Encapsulate Conditionals

Extract functions that explain the intent of the conditional.


## Avoid Negative Conditionals

Negatives are just a bit harder to understand than positives. So, when possible, conditionals should be expressed as positives.


## Functions Should Do One Thing

It is often tempting to create functions that have multiple sections that perform a series of operations. Functions of this kind do more than one thing, and should be converted into many smaller functions, each of which does one thing.


## Hidden Temporal Couplings

Temporal couplings are often necessary, but you should not hide the coupling.
Structure the arguments of your functions such that the order in which they should be called is obvious.

Each function produces a result that the next function needs, so there is no reasonable way to call them out of order.
You might complain that this increases the complexity of the functions, and you’d be right. But that extra syntactic complexity exposes the true temporal complexity of the situation.


## Don’t Be Arbitrary

Have a reason for the way you structure your code, and make sure that reason is communicated by the structure of the code.
If a structure appears arbitrary, others will feel empowered to change it.


## Encapsulate Boundary Conditions

Boundary conditions are hard to keep track of. Put the processing for them in one place. Don’t let them leak all over the code.

For example, `level+1`. This is a boundary condition that should be encapsulated within a variable named something like `nextLevel`.


## Functions Should Descend Only One Level of Abstraction

The statements within a function should all be written at the same level of abstraction, which should be one level below the operation described by the name of the function.

Separating levels of abstraction is one of the most important functions of refactoring, and it’s one of the hardest to do well.

when you break a function along lines of abstraction, you often uncover new lines of abstraction that were obscured by the previous structure.


## Keep Conﬁgurable Data at High Levels

If you have a constant such as a default or conﬁguration value that is known and expected at a high level of abstraction, do not bury it in a low-level function.


## Avoid Transitive Navigation

In general we don’t want a single module to know much about its collaborators. More speciﬁcally, if A collaborates with B, and B collaborates with C, we don’t want modules that use A to know about C.

it comes down to making sure that modules know only about their immediate collaborators and do not know the navigation map of the whole system.
If many modules used some form of the statement a.getB().getC(), then it would be difﬁcult to change the design and architecture to interpose a Q between B and C.

This is how architectures become rigid. Too many modules know too much about the architecture.


\newpage

# Names


## Choose Descriptive Names

Don’t be too quick to choose a name. Make sure the name is descriptive. Remember that meanings tend to drift as software evolves, so frequently reevaluate the appropriateness of the names you choose.

The power of carefully chosen names is that they overload the structure of the code with description.


## Choose Names at the Appropriate Level of Abstraction

Don’t pick names that communicate implementation;
choose names the reﬂect the level of abstraction of the class or function you are working in.


## Use Standard Nomenclature Where Possible

Names are easier to understand if they are based on existing convention or usage. For example, if you are using the DECORATOR pattern, you should use the word Decorator in the names of the decorating classes.

the more you can use names that are overloaded with special meanings that are relevant to your project, the easier it will be for readers to know what your code is talking about.


## Unambiguous Names

Choose names that make the workings of a function or variable unambiguous.

it’s explanatory value outweighs the length.


## Use Long Names for Long Scopes

The length of a name should be related to the length of the scope.
You can use very short variable names for tiny scopes, but for big scopes you should use longer names.

variables and functions with short names lose their meaning over long distances. So the longer the scope of the name, the longer and more precise the name should be.


## Avoid Encodings

Names should not be encoded with type or scope information.
Also project and/or subsystem encodings such as

vis_ (for visual imaging system) are distracting and redundant.
Keep your names free of Hungarian pollution.


## Names Should Describe Side-Effects

Names should describe everything that a function, variable, or class is or does.
Don’t hide side effects with a name. Don’t use a simple verb to describe a function that does more than just that simple action.


\newpage

# Tests

## Insufﬁcient Tests

How many tests should be in a test suite?
A test suite should test everything that could possibly break.
The tests are insufﬁcient so long as there are conditions that have not been explored by the tests or calculations that have not been validated.


## Use a Coverage Tool!

Coverage tools reports gaps in your testing strategy. They make it easy to ﬁnd modules, classes, and functions that are insufﬁciently tested.


## Don’t Skip Trivial Tests

They are easy to write and their documentary value is higher than the cost to produce them.


## An Ignored Test Is a Question about an Ambiguity

Sometimes we are uncertain about a behavioral detail because the requirements are unclear. We can express our question about the requirements as a test that is commented out


## Test Boundary Conditions

Take special care to test boundary conditions. We often get the middle of an algorithm right but misjudge the boundaries.


## Exhaustively Test Near Bugs

Bugs tend to congregate. When you ﬁnd a bug in a function, it is wise to do an exhaustive test of that function. You’ll probably ﬁnd that the bug was not alone.


## Patterns of Failure Are Revealing

Sometimes you can diagnose a problem by ﬁnding patterns in the way the test cases fail.
This is another argument for making the test cases as complete as possible. Complete test cases, ordered in a reasonable way, expose patterns.


## Test Coverage Patterns Can Be Revealing

Looking at the code that is or is not executed by the passing tests gives clues to why the failing tests fail.


## Tests Should Be Fast

A slow test is a test that won’t get run. When things get tight, it’s the slow tests that will be dropped from the suite.
**So do what you must to keep your tests fast.**
