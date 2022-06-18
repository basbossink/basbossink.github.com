+++
date = "2011-11-14"
title = "PS for .NET devs part 2: Comparing the PowerShell language to C#"
+++

In my previous posts in this series I discussed
[why you should care about PowerShell][0] and I pointed to some
resources to help you [get started with PowerShell][2]. This post will
describe the syntax of the [PowerShell][1] language by comparing it
with the syntax of C#. [Recently][3] the
[PowerShell language specification][4] was released under the
community promise, so if you want to learn everything there is to know
about the [PowerShell][1] language look [it][4] up.

To summarize this post: When translating a piece of C# code to
[PowerShell][1] take what you would normally write in C#, remove all
the explicit typing and add a few `$`'s here and there. The comparison
is mostly presented in a tabular form showing the C# syntax in the
first column and the equivalent [PowerShell][1] syntax in the second,
followed with a description of the particular language construct in
the last column. Enjoy.

### Comments

| C#           | PowerShell  | Description                       |
| ------------|-------------|----------------------------------- |
| `//`        | `#`         | single line                        |
| `/* ... */` | `<# ... #>` | multi line                         |
| `///`       |             | single line documentation comments |

#### Comment documentation keywords

[PowerShell][1] is also blessed with comment-based help but
because it does not have any formating keywords and does not focus on
types, a lot of the corresponding keywords have no equivalent in the
[PowerShell][1] column. [PowerShell][1] supports more keywords than
the ones listed below for the entire story please use
[PowerShell][1]'s built in help: `help about_Comment_Based_Help` or the [online documentation][help]:

| C#              | PowerShell      | Description                                            |
| ----------------|-----------------|------------------------------------------------------- |
|  `<c>`          |                 | Set text in a code-like font                           |
|  `<code>`       |                 | Set one or more lines of source code or program output |
|  `<example>`    | `.EXAMPLE`      | Indicate an example                                    |
|  `<exception>`  |                 | Identify the exceptions a method can throw             |
|  `<include>`    | `.EXTERNALHELP` | Includes XML from an external file                     |
|  `<list>`       |                 | Create a list or table                                 |
|  `<para>`       |                 | Permit structure to be added to text                   |
|  `<param>`      | `.PARAMETER`    | Describe a parameter for a method or constructor       |
|  `<paramref>`   |                 | Identify that a word is a parameter name               |
|  `<permission>` |                 | Document the security accessibility of a member        |
|  `<remarks>`    |                 | Describe a type                                        |
|  `<returns>`    | `.OUTPUTS`      | Describe the return value of a method                  |
|  `<see>`        | `.LINK`         | Specify a link                                         |
|  `<seealso>`    | `.LINK`         | Generate a See Also entry                              |
|  `<summary>`    | `.SYNOPSIS`     | Describe a member of a type                            |
|  `<value>`      |                 | Describe a property                                    |
|                 | `.NOTES`        | Additional information about the function or script    |
|                 | `.DESCRIPTION`  | A detailed description of the function or script       |
|                 | `.INPUTS`       | The inputs that can be piped to the function or script |

### Literals

Literals are the same as in C# with a few minor differences:

- In [PowerShell][1] the backtick (`` ` ``) is the escape character:
  ``PS>"Quotes need to be escaped `""``
- [PowerShell][1] does not have `char` literals to create one you have
  to use a cast: `[char]"a"`.
- [PowerShell][1] multi-line strings also begin with the `@"` it
  however has to be followed by a new line, furthermore the end mark
  is a `"@` which has to be put at the beginning of the line.
- Array literals are created using the array operator `,`. So
  `"Fred","Barney"` creates on array containing 2 strings.
- [PowerShell][1] distinguishes single quoted `''` and double quoted
  `""` string literals the former causes the string to be interpreted
  verbatim while the later is subject to string interpolation. Here's
  an example:

~~~ ps1
PS>"my $PSCulture is dutch"
My nl-NL is dutch.
PS>'my $PSCulture is dutch'
My $PSCulture is dutch.
~~~

- [PowerShell][1] supports `HashTable` literals of the form: `@{
  <name> = <value>; [<name> = <value> ] ... }`. Below you can see that
  `HashTable` literals can be split across multiple lines in which
  case the semicolons (`;`) after the name-value pair can be omitted
  leaving a nice and readable `HashTable` behind.

~~~ ps1
PS>$table = @{ a=37; b=42;}
PS>$ttable = @{
>>a=37
>>b=43
>>}
>>
PS>
~~~


### Variables
In [PowerShell][1] variable declarations don't require explicit
typing, they do however have to be prefixed with a `$`.

~~~ ps1
PS>$now = [DateTime]::UtcNow
PS>$message = 'hello'
~~~


Being a .NET developer you're probably wondering how you can create
objects in [PowerShell][1]. There is no `new` keyword but there is a
[`New-Object`][new] [Cmdlet][cmdl]. It can for example be used like
this:

~~~ ps1
PS>$dateofbirth = New-Object DateTime -ArgumentList 1972,7,12
PS>$feeds = new-object -Com Microsoft.FeedsManager
PS>$feeds.IsSubscribed("http://basbossink.github.com/atom.xml")
True
~~~


To have a little bit more brevity in the shell you don't have to
specify the entire full name of the type. [PowerShell][1] has some
built-in type accelerators so for instance in the case of
`System.DateTime` you can leave of the `System` namespace part. See
[this][tag] [StackOverflow][so] [question][tag] for some extra
references about the subject. As you can see the [`New-Object`][new]
[Cmdlet][cmdl] can also be used to create COM objects see `help
New-Object` for more details or look at the
[online documentation][new].

### Operators

The arithmetic and assignment operators are the same for C# and
[PowerShell][1] the differences start with the comparison operators
the familiar `>` and friends are replaced with a `-` followed by an
abbreviation for the comparison. This was done to keep the meaning
of `>` for redirection as all system administrators now it from dos and
POSIX shells.

<div class="code">
<table>
<thead>
<tr><th>C#</th><th>PowerShell</th><th>Description</th></tr>
</thead>
<tbody>
<tr><td>==</td><td>-eq</td><td></td></tr>
<tr><td>!=</td><td>-ne</td><td></td></tr>
<tr><td>&gt;</td><td>-gt</td><td></td></tr>
<tr><td>&lt;</td><td>-lt</td><td></td></tr>
<tr><td>&lt;=</td><td>-le</td><td></td></tr>
<tr><td>&gt;=</td><td>-ge</td><td></td></tr>
<tr><td></td><td>-match</td><td>regular expression matching</td></tr>
<tr><td></td><td>-notmatch</td><td></td></tr>
<tr><td></td><td>-like</td><td>wildcard pattern matching</td></tr>
<tr><td></td><td>-notlike</td><td></td></tr>
<tr><td></td><td>-replace</td><td>replace regular expressions</td></tr>
<tr><td>|</td><td>-bOR</td><td></td></tr>
<tr><td>&amp;</td><td>-bAND</td><td></td></tr>
<tr><td>^</td><td>-bXOR</td><td></td></tr>
<tr><td>~</td><td>-bNOT</td><td></td></tr>
<tr><td>&amp;&amp;</td><td>-and</td><td></td></tr>
<tr><td>||</td><td>-or</td><td></td></tr>
<tr><td></td><td>-xor</td><td></td></tr>
<tr><td>!</td><td>!,-not</td><td></td></tr>
<tr><td>++</td><td>++</td><td></td></tr>
<tr><td>--</td><td>--</td><td></td></tr>
<tr><td>is</td><td>-is</td><td></td></tr>
<tr><td></td><td>-isnot</td><td></td></tr>
<tr><td>as</td><td>-as</td><td></td></tr>
</tbody>
</table>
</div>

Apart from this table above there are a couple of extra operators that
have no C# equivalent:

- Redirection operators:
  `>, >>, 2>, 2>&1`
- Comma operator: `,`
  Creates an array.
- Split and Join operators: `-split,-join`
  To divide and combine substrings
    ~~~ ps1
    PS>1,2,3 -join '*'
    1*2*3
    PS>$env:PATH -split ';'
    %SystemRoot%\system32\WindowsPowerShell\v1.0\
    ⋮ 
    ~~~
- Call operator: `&`
  Run a command, script, or script block.
    ~~~ ps1
    PS>& 'C:\Program Files (x86)\GNU\GnuPG\sha256sum.exe' test.iso
    ~~~
- Dot sourcing operator: `.`
  Runs a script so that the variables, functions defined in the script
  are part of the calling scope.
- Static member operator: `::`
  Used to call static method or retrieve
  static properties of a .NET Framework class.
    ~~~ ps1
    [Math]::Sin(([Math]::PI)/2)
    ~~~
- Range operator: `..`
  Represents the sequential integers within the given
  upper and lower boundary.
    ~~~ ps1
    PS>1..10 -join ','
    1,2,3,4,5,6,7,8,9,10
    ~~~
- Format operator: `-f`
  The following two pieces of code are equivalent (starting with C#):
    ~~~ cs
    Math.PI.ToString("{0:0.00}")
    ~~~
    ****
    ~~~ ps1
    "{0:0.00}" -f [Math]::PI
    ~~~
- Subexpression operator: `$()`
  Returns the result of one or more statements.
  Very handy in string interpolation like
    ~~~ ps1

    PS>"This machine has $([Environment]::ProcessorCount) cpu's"
    This machine has 2 cpu's
    ~~~
- Array subexpression operator `@()`
  Returns the result of one or more statements as an array.

### Selection Statements

[PowerShell][1] supports the `if-else` and `switch` statements.
The `if-else` differs only in the fact that [PowerShell][1] has a
`elseif` keyword where C# uses `else if`.

In [PowerShell][1] the `switch` statement has more functionality
compared to C# since it supports switching on regular expressions and
wildcards when the values supplied let themselves be converted to
strings. Again use `help about_Switch` (or look [here][switch]).

### Iteration Statements

<div class="code">
<table>
<thead>
<tr><th>C#</th><th>PowerShell</th></tr>
</thead>
<tbody>
<tr>
<td>do {...} while (x &lt; 5 )</td>
<td>do {...} while ($x -lt 5 )</td>
</tr>
<tr>
<td>for(int i=0; i &lt; 37; i++) {...}</td>
<td>for($i=0; i -lt 37; i++) {...}</td>
</tr>
<tr>
<td>foreach(var i in Collection) {...}</td>
<td>foreach($i in $collection) {...}</td>
</tr>
<tr>
<td></td>
<td>&lt;command&gt; | foreach {...}</td>
</tr>
<tr>
<td></td>
<td>&lt;command&gt; | ForEach-Object {...}</td>
</tr>
<tr>
<td>while(x &lt; 5) {...}</td>
<td>while($x -lt 5) {...}</td>
</tr>
</tbody>
</table>
</div>

Even though it's not explicitly mentioned in the table above
[PowerShell][1] also supports the familiar `break` and `continue` keywords. See `help
about_break` (or [here][break]) and `help about_continue` (or
[here][continue]) for details. When using [`ForEach-Object`][feo] the
[Automatic Variable][av] `$_` represents the current item, see [`help
about_Foreach`][fe] for details.

### Exception Handling

Since version 2 [PowerShell][1] supports the C#
[`try-catch-finally`][tryc] syntax besides the earlier introduced
[`trap`][trap] keyword, which can be viewed as a `catch` block with an
implicit `try` for the surrounding scope. [PowerShell][1] also
supports [`throw`][throw], the difference being that any expression
can be [`throw`][throw]n. The expression in the [`throw`][throw]
syntax is optional, this reminds me a bit of the [Perl][perl]
[`die`][die] function.

### Functions

Functions in [PowerShell][1] are quite a different beast when compared
to C#. At first glance there are many similarities, both languages
support positional parameters, keyword parameters and optional
parameters. The extra benefit in the case of [PowerShell][1] in my
opinion is, the ability to use pipeline parameters. Lets look at an
example:

~~~ ps1

function Get-SumOfSquares {
    begin { $result = 0 }
    process { $result += $_ * $_ }
    end { $result }
}
1..25 |
ForEach-Object { Get-Random -Maximum 100 } |
Get-SumOfSquares

~~~

Here you can see the filtering of the pipeline input in a way that
reminds me of [Awk][awk], the [`begin` and `end` syntax][awkbeg]
specifically. The `begin` and `end` blocks mean exactly what you think
they mean. The `process` block gets called by [PowerShell][1] for each
value received from the pipeline. Where `$_` has the value of the
[`Current`][cur] value as in the value of the [`Current`][cur]
property when using the [`IEnumerator`][ienum] interface. Since
version 2 a lot of functionality was added to provide extra
functionality to functions, the so called [Advanced Functions][af] see
`help about_Functions_Advanced` for details this includes stuff like
declarative parameter validation, specifying parameter sets, aliases
and a brief help message for parameters. Elaborating on the earlier
`Get-SumOfSquares` example a full blown implementation could look
something like this:

~~~ ps1

function Get-SumOfSquares {
    Param(
        [Parameter(Mandatory=$true,
                   ValueFromPipeline=$true,
                   HelpMessage="An array of integers." )]
        [Alias("IN")]
        [int[]]
        $InputObject
    )
    $result = 0
    $InputObject | ForEach-Object {
        $result += $_ * $_
    }
    $result
}

~~~

After pasting this in the [PowerShell][1] console an example usage
might look like the screenshot below.

![Get-SumOfSquares example interaction][sumpic]

### Epilogue

This is my brief summary of the syntactic differences between C# and
[PowerShell][1]. I hope this can help you with coming to grips with
[PowerShell][1]. Next time we'll look at how easy it is to work with
XML in [PowerShell][1] and munge a large [MSBuild][msb] file with a
small script.



##### References

- [PS for .NET devs part 0: PowerShell what is it and why should I care?](/2011-06-19/ps4.netdevs-0-what-and-why/)
- [Scripting with Windows PowerShell](http://technet.microsoft.com/en-us/scriptcenter/dd742419)
- [PS for .NET devs part 1: Getting started with PowerShell](/2011-06-22-ps4.netdev-1-getting-started-with-powershell/)
- [Powershell Language specification announcement](http://blogs.msdn.com/b/powershell/archive/2011/04/16/powershell-language-now-licensed-under-the-community-promise.aspx)
- [About Break](http://technet.microsoft.com/en-us/library/dd315285.aspx)
- [About Comment Based Help](http://technet.microsoft.com/en-us/library/dd819489.aspx)
- [About Continue](http://technet.microsoft.com/en-us/library/dd347559.aspx)
- [About Switch](http://technet.microsoft.com/en-us/library/dd347715.aspx)
- [About Throw](http://technet.microsoft.com/en-us/library/dd819510.aspx)
- [About Trap](http://technet.microsoft.com/en-us/library/dd347548.aspx)
- [About Try, Catch, Finally](http://technet.microsoft.com/en-us/library/dd315350.aspx)
- [The Perl Programming Language](http://www.perl.org)
- [The Perl die Function](http://perldoc.perl.org/functions/die.html)
- [MSBuild](http://msdn.microsoft.com/en-us/library/wea2sca5.aspx)
- [New-Object](http://technet.microsoft.com/en-us/library/dd315334.aspx)
- [Cmdlet overview](http://msdn.microsoft.com/en-EN/library/ms714395(v=VS.85).aspx)
- [StackOverflow question about type accelerators](http://stackoverflow.com/questions/1145312/)
- [StackOverflow](http://stackoverflow.com)
- [Current property](http://msdn.microsoft.com/en-us/library/system.collections.ienumerator.current.aspx)
- [IEnumerator interface](http://msdn.microsoft.com/en-us/library/system.collections.ienumerator.aspx)
- [About Functions Advanced](http://technet.microsoft.com/en-us/library/dd315326.aspx)
- [The Awk programming language](http://en.wikipedia.org/wiki/AWK)
- [GNU Awk Begin End syntax](http://www.gnu.org/s/gawk/manual/gawk.html#BEGIN_002fEND)
- [About Foreach](http://technet.microsoft.com/en-us/library/dd347733.aspx)
- [ForEach-Object](http://technet.microsoft.com/en-us/library/dd347608.aspx)
- [About Automatic Variables](http://technet.microsoft.com/en-us/library/dd347675.aspx)

[0]: /2011-06-19/ps4.netdevs-0-what-and-why/ "PS for .NET devs part 0: PowerShell what is it and why should I care?"
[1]: http://technet.microsoft.com/en-us/scriptcenter/dd742419 "Scripting with Windows PowerShell"
[2]: /2011-06-22-ps4.netdev-1-getting-started-with-powershell/ "PS for .NET devs part 1: Getting started with PowerShell"
[3]: http://blogs.msdn.com/b/powershell/archive/2011/04/16/powershell-language-now-licensed-under-the-community-promise.aspx "Powershell Language specification announcement"
[4]: http://www.microsoft.com/download/en/details.aspx?id=9706 "Windows PowerShell Language Specification Version 2.0"
[12]: /tags/ps4.netdevs.html
[trap]: http://technet.microsoft.com/en-us/library/dd347548.aspx "About Trap"
[tryc]: http://technet.microsoft.com/en-us/library/dd315350.aspx "About Try, Catch, Finally"
[help]: http://technet.microsoft.com/en-us/library/dd819489.aspx "About Comment Based Help"
[switch]: http://technet.microsoft.com/en-us/library/dd347715.aspx "About Switch"
[throw]: http://technet.microsoft.com/en-us/library/dd819510.aspx "About Throw"
[perl]: http://www.perl.org "The Perl Programming Language"
[die]: http://perldoc.perl.org/functions/die.html "The Perl die Function"
[break]: http://technet.microsoft.com/en-us/library/dd315285.aspx "About Break"
[continue]: http://technet.microsoft.com/en-us/library/dd347559.aspx "About Continue"
[msb]: http://msdn.microsoft.com/en-us/library/wea2sca5.aspx "MSBuild"
[new]: http://technet.microsoft.com/en-us/library/dd315334.aspx "New-Object"
[cmdl]: http://msdn.microsoft.com/en-EN/library/ms714395(v=VS.85).aspx "Cmdlet overview"
[so]: http://stackoverflow.com "StackOverflow"
[tag]: http://stackoverflow.com/questions/1145312/ "StackOverflow question about type accelerators"
[ienum]: http://msdn.microsoft.com/en-us/library/system.collections.ienumerator.aspx "IEnumerator interface"
[cur]: http://msdn.microsoft.com/en-us/library/system.collections.ienumerator.current.aspx "Current property"
[sumpic]: GetSumOfSquaresSample.png "Get-SumOfSquares example interaction"
[af]: http://technet.microsoft.com/en-us/library/dd315326.aspx "About Functions Advanced"
[awk]: http://en.wikipedia.org/wiki/AWK "The Awk programming language"
[awkbeg]: http://www.gnu.org/s/gawk/manual/gawk.html#BEGIN_002fEND "GNU Awk Begin End syntax"
[fe]: http://technet.microsoft.com/en-us/library/dd347733.aspx "About Foreach"
[feo]: http://technet.microsoft.com/en-us/library/dd347608.aspx "ForEach-Object"
[av]: http://technet.microsoft.com/en-us/library/dd347675.aspx "About Automatic Variables"
