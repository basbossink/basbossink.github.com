---
published: true
layout: post
title: "Running with the devil"
categories:
 - learning
keywords:
- learning
- exercism.io
- Haskell
--- 
This blog has been dormant for quite some time. But I would like to take this 
oppertunity to promote a special site that has stolen my heart over the last 
couple of weeks. It is a tool for learning that [runs with the devil][devil]. 
The site I'm talking about is [exercism.io][ex], to quote their byline: 

> Crowd-sourced code reviews on daily practice problems.

The site is currently in public beta, but I have not seen any problems with it 
yet. The idea is that you solve small programming problems in a language of 
your choice, who get reviewed by your peers. This process can help you 
reach a solution to the problem that is idiomatic for the language you're 
using. This really magnifies your learning of a language. Mainly because you 
can be enlightened about the blind spots that you have when you're trying to 
learn a new language and start with the mindset of the language(s) that 
you already know. The list of languages that you can use is quite extensive:

- Clojure
- Coffeescript
- Elixir
- Go
- Haskell
- Javascript
- Objective C
- Ocaml
- Perl5
- Python
- Ruby
- Scala

Support for Java, Rust, Erlang, PHP and Common Lisp is comming soon.
The exercises come with a Readme that describes the behavior you need to 
implement and a set of unit tests you can use to check your solution. 
Retrieving the exercises and submitting your solutions is handled by a
[small command-line utility][cli] named [`exercism`][cli]. The exercises I've 
worked on upto now are what I would call bite-sized. A first iteration of an 
exercise can be produced in 5-15 minutes. So the barrier to entry is really 
low. This is great for people who want to improve their skills but also want 
to maintain a work-life balance. The fact that other people take the time to 
review your work also really motivated me to improve my solutions to the 
exercises. To put it in other words, having people help you, really makes 
learning easier and more fun.

A good example of how your code gets refined when following up on other 
peoples advice is the 9 iterations it took me before I was happy with my 
[solution to the wordcount exercise in Haskell][wc]. One of my reviewers was 
kind enough to point me to a library function that greatly simplified my 
solution. Furthermore being reminded that Haskell is a lazy language was also 
great for me because those are the practical details that you hardly ever see 
in language tutorials. 

Another great aspect of [exercism][ex] is that you can learn to recieve and 
give feedback, which I think is a critical skill to practice if you want to 
succeed as a professional software developer. Discussing code in 
this kind of detail really enforces my view that readibillity of code is more 
important than terseness, especially when it comes to a language like Haskell. 
I hope I've inspired you to try out [exercism][ex] and hope your code will 
soon be [running with the devil][devil]. 

{% include date.inc %}

[devil]: http://www.youtube.com/watch?v=fcvtnEvclGs
[ex]: http://exercism.io/
[wc]: http://exercism.io/submissions/5e93f797c6d41bf77afee973
[cli]: http://cli.exercism.io/
