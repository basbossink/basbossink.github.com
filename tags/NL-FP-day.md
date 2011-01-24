---
layout: default
title: Posts tagged NL-FP day
keywords: [Clean,Haskell,NL-FP day]
---
<h2><a href="/2011-01-09/NLFP-day/">NL FP day 2011</a></h2>
{% assign my_date = ' Sun 09 Jan 2011' %}
Last Friday I attended the [Nederlandse Functioneel Programmeren dag][nlfp]. 
The program showed a wide variety of short (20 min.) talks. This
appeared to be a nice low barrier of entry opportunity to see what's
currently hot in the field of [functional programming][fp].
With the added benefit of being able to talk to people who get to use
languages like [Haskell][has], [F#][fs] on a daily bases instead of in
their spare time &#9786;.

### The talks

#### [Creating a Dataflow Processor in C&#955;aSH][dfp]

Anja Niedermeier presented a talk about designing a dataflow processor
using [C&#955;aSH][cash] a functional hardware description language that
borrows both its syntax and semantics from [Haskell][has]. The
interesting part for me was to see a parallel to a question that was
recently posed at my current project to create some means to let users
create their own image processing pipeline from a given set of basic
operations.

#### [Unifying Merging and Permuting Parsers][mpp]

Doaitse Swierstra gave a talk about combining [parsers][par] for
[permutations][perm] with [parsers][par] for merged structures. An
example of a [parser][par] for a permuted structure would be a
[parser][par] for HTML elements, since attributes can occur in any
order. An example of a [parser][par] for a merged structure would be
[The Utrecht Attribute Grammar System][uuagc], which needs to parse
different types of text in a file. Another example of this would be a
[template language][templ] like [Liquid][liq]. I found it a bit to
abstract to really grasp it.
 
#### [Functional Modeling of Musical Harmony][mus]

Jos&eacute; Pedro Magalh&atilde;es presented the way in which he and
his fellow researchers used [Haskell][has]
[Generalized Algebraic Data types][gadt] to model chord sequences. The
practical application of this work could for instance be recognising
music based on the found chord sequences. This talk was very
interesting to me since it combined the field of music with
programming [Haskell][has].  

#### [The Expression Problem in Clojure][cexp] 

Sander van den Berg presented a way to solve a reformulation of the
[Expression Problem][exp]. The expression problem was coined by
[Philip Wadler][wad] as 'a salient indicator of its (red: programming
language) capacity for expression' [\[1\]][expr]. This was the only talk
that featured a [dynamically typed language][dyn], [Clojure][cloj] in
this case. The language features demonstrated were [protocols][prot]
and [data types][dat]. Before the lunch break Sander also demo-ed a
[Clojure][cloj] program that was coded on stage at a Java conference,
that tried to 'find' a best estimate to the famous [Mona Lisa][mona]
by drawing only polygons. The program also tried to demonstrate
[Lisp's][lisp] [homoiconicity][hom], this is the property that code
can manipulate code because the syntax of the language can be
represented as a data structure in a primitive type of the language.
[Lisp][lisp] is not the only language that is considered to be
[homoiconic][hom] other noteworthy examples are [XSLT][xslt],
[Postscript][post] and [R][r].

#### [Renjin: Towards a more pure, scalable R][renjin]

Alexander Bertram gave an interesting talk about his efforts to write
a Java-based [R][r] interpreter and compiler. [R][r] is language with
a large history, created and maintained mostly by statisticians and
data-analysts. This accounts for the large number of language
features, some of which make computer scientists curl their toes.
[R][r] is a functional language in which even if and break are
functions, that can even be redefined, aaah. Running R in the 'cloud'
is the ultimate goal, to provide a solution for data-mining very large
datasets.

#### [jQuery Programming with Haskell][jqhas]

After lunch Jurri&euml;n Stutterheim presented the way one can
currently use the [Utrecht Haskell Compiler][uhc] to compile [Haskell][has]
code to JavaScript and how one can use the popular [jQuery][jq]
library from within [Haskell][has]. The demo was cool, there were
still some hurdles to overcome however. The use of optional parameters
is one of them. I couldn't help but wonder why some many people fight
JavaScript. In my opinion we should just take it's good parts and use
it's dynamic nature to our benefit and fight the error proneness of the
dynamism with a sufficient set of unit tests, and right-sizing of
view code using presentation patterns like [Model View ViewModel][mvvm].

#### [From Clean to JavaScript via Sapl][clja]

Jan Martin Jansen presented efforts to build a [Clean][clean] to
JavaScript compiler. This talk discussed in technical detail how some
JavaScript constructs could be translated to Sapl (an intermediate
language used by the [Clean][clean] compiler).

#### [Exchanging sources between Clean and Haskell - A Double-Edged Front End for the Clean compiler][hascl]
     
Peter Achten presented work to combine the forces of [Clean][clean]
and [Haskell][has] by providing two new dialects of both
[Clean][clean] and [Haskell][has] that can be used with the
[Clean][clean] compiler. It was interesting to learn something about
the similarities and differences between [Clean][clean] and
[Haskell][has]. One of the differences between [Clean][clean] and [Haskell][has]
is the fact the [Haskell][has] uses [Monads][mon] to separate
[pure][pure] code from [side effecting code][side] while
[Clean][clean] uses a concept called [uniqueness types][uniq].

#### [Mixed-signal modelling][mixm]

Kenneth Rovers presented his work on using [Haskell][has] to create simulations
of mixed-signals encountered for instance in a
[phased array][paa]. The solution to the problem was very
elegant, instead of trying to simulate a continuous signal with a set
of values over a time-series, describe the simulation with functions
that depend on the parameter time. The different components of the
system can be composed using function composition. 

#### [From Trees to Graphs and Back Again][ftgba]

Next up Stefan Holdermans talked about making sharing explicit in
[trees][tree] which results in [graphs][graph]. Then he went on to
explain how through the use of polynomial types[^1] and various
[cata-][cata] and [anamorphisms][anam] one can impress your audience.
Needless to say this talk was a bit to abstract for me even though
I've had my share of [Category theory][categ] while I was studying for
my masters degree in mathematics. I could not see how this work would
make me happy as a programmer trying to work with [graphs][graph].

[^1]: Of which I could not find a decent link describing them. 

#### [Evolving the layout of serialized data][eser]

Alexey Rodriguez was the last presenter of the day. The title of the
talk intrigued me, especially since I've recently given up on
serialization. In my opinion the time saved by not having to write a
parser and generator for your data format is spent (and then some)
solving the up-, and downgrade problems when using some form of
serialization. Alexey described a framework in [OCaml][ocaml] used at
[his company][vefa] to solve the aforementioned problem.

#### Aftermath

The drinks and dinner afterwords were interesting and well deserved I
would say. Having the opportunity to learn a little bit more about
[Clean][clean] and chat about using [FsCheck][fsc] to test a large
[C#][csharp] code-base. After a good meal I went home tired, inspired
and functionally rewired.

{% include date.inc %}

[csharp]: http://en.wikipedia.org/wiki/C_Sharp_(programming_language) "C#"
[fsc]: http://fscheck.codeplex.com/ "FsCheck"
[ocaml]: http://en.wikipedia.org/wiki/Ocaml "OCaml" 
[vefa]: http://www.vectorfabrics.com/ "VectorFabrics"
[eser]: http://caes.ewi.utwente.nl/External/NLFP/#evolvingthelayoutofserializeddata "Evolving the layout of serialized data"
[anam]: http://en.wikipedia.org/wiki/Anamorphism "Anamorphism"
[categ]: http://en.wikipedia.org/wiki/Category_theory "Category theory"
[cata]: http://en.wikipedia.org/wiki/Catamorphism "Catamorphism"
[graph]: http://en.wikipedia.org/wiki/Graph_(mathematics) "Graph"
[tree]: http://en.wikipedia.org/wiki/Tree_(data_structure) "Tree data structure"
[ftgba]:http://caes.ewi.utwente.nl/External/NLFP/#fromtreestographsandbackagain "From Trees to Graphs and Back Again"
[templ]: http://en.wikipedia.org/wiki/Template_engine_(web) "Template engine"
[liq]: http://www.liquidmarkup.org/ "Liquid"
[uuagc]: http://www.cs.uu.nl/wiki/bin/view/HUT/AttributeGrammarSystem "Utrecht University Attribute Grammar Compiler"
[mpp]: http://caes.ewi.utwente.nl/External/NLFP/#unifyingmergingandpermutingparsers "Unifing Merging and Permutating Parsers"
[par]: http://en.wikipedia.org/wiki/Parser "Parser"
[perm]: http://en.wikipedia.org/wiki/Permutation "Permutation"
[post]: http://en.wikipedia.org/wiki/PostScript_programming_language "PostScript"
[xslt]: http://en.wikipedia.org/wiki/XSLT "XSLT"
[hom]: http://en.wikipedia.org/wiki/Homoiconicity "Homoiconicity"
[mona]: http://en.wikipedia.org/wiki/Mona_Lisa "Mona Lisa"
[lisp]: http://en.wikipedia.org/wiki/Lisp_(programming_language) "Lisp" 
[paa]: http://en.wikipedia.org/wiki/Phased_array "Phased array"
[mixm]: http://caes.ewi.utwente.nl/External/NLFP/#mixedsignalmodelling "Mixed-signal modelling"
[pure]: http://en.wikipedia.org/wiki/Pure_function "Pure function"
[side]: http://en.wikipedia.org/wiki/Side_effect_(computer_science) "Side effects"
[uniq]: http://en.wikipedia.org/wiki/Uniqueness_type "Uniqueness type"
[mon]: http://www.haskell.org/haskellwiki/Monad "Monad"
[hascl]:http://caes.ewi.utwente.nl/External/NLFP/#cleanhaskell "Clean Haskell"
[expr]: http://www.daimi.au.dk/~madst/tool/papers/expression.txt "Expression problem paper"
[clja]: http://caes.ewi.utwente.nl/External/NLFP/#fromcleantojavascriptviasapl "From Clean to JavaScript via Sapl"
[jqhas]: http://caes.ewi.utwente.nl/External/NLFP/#jqueryprogrammingwithhaskell "jQuery Programming with Haskell"
[clean]: http://wiki.clean.cs.ru.nl/Clean "Clean"
[mvvm]: http://en.wikipedia.org/wiki/MVVM "Model View ViewModel"
[jq]: http://jquery.com/ "jQuery"
[uhc]: http://www.cs.uu.nl/wiki/UHC "Utrecht Haskell Compiler"
[r]: http://www.r-project.org/ "The R Project for Statistical Computing"
[renjin]: http://caes.ewi.utwente.nl/External/NLFP/#renjintowardsamorepurescalabler "Renjin: Towards a more pure, scalable R"
[dat]: http://clojure.org/datatypes "Clojure datatypes"
[prot]: http://clojure.org/Protocols "Clojure protocols"
[wad]: http://homepages.inf.ed.ac.uk/wadler/ "Phillip Wadler"
[cloj]: http://clojure.org/ "Clojure"
[dyn]: http://en.wikipedia.org/wiki/Type_system#Dynamic_typing "Dynamic Typing"
[cexp]: http://caes.ewi.utwente.nl/External/NLFP/#theexpressionprobleminclojure "The Expression Problem in Clojure"
[exp]: http://en.wikipedia.org/wiki/Expression_Problem "Expression Problem"
[nlfp]: http://caes.ewi.utwente.nl/External/NLFP/ "NL-FP Dag 2011"
[fp]: http://en.wikipedia.org/wiki/Functional_programming "Functional Programming"
[has]: http://www.haskell.org/haskellwiki/Haskell "Haskell"
[fs]: http://msdn.microsoft.com/fsharp/ "F#"
[dfp]: http://caes.ewi.utwente.nl/External/NLFP/#creatingadataflowprocessorinclash "Data Flow Processor"
[cash]: http://clash.ewi.utwente.nl/ClaSH/Index.html "C&#955;aSH" 
[mus]: http://caes.ewi.utwente.nl/External/NLFP/#functionalmodelingofmusicalharmony "Functional Modeling of Musical Harmony"
[gadt]: http://www.haskell.org/haskellwiki/GADT "Generalised algebraic datatype"


<hr/>
