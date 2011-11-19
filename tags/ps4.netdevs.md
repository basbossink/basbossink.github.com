---
layout: default
title: Posts tagged ps4.netdevs
keywords: [.NET,.NET development,C#,PowerShell,PowerShell advocacy,PowerShell syntax,development,ps4.netdevs]
---
<h2><a href="/2011-06-19/ps4.netdevs-0-what-and-why/">PS for .NET devs part 0: PowerShell what is it and why should I care?</a></h2>
{% assign my_date = ' Sun 19 Jun 2011' %}
Being a big [PowerShell][1] fan but not seeing many fellow developers around me use it, I
thought [PowerShell][1] could use some promotion among .NET
developers. This inspired me to start a series of blog
posts showing the great stuff [PowerShell][1] has to offer .NET
developers. The outline I have defined up to now looks like this:

1. Getting started with [PowerShell][1] 
1. [PowerShell][1]] as a better shell
1. The syntax of the [PowerShell][1] language
1. Listing the Targets in your MSBuild file
1. Getting an overview of your code-base
1. Shutting down the pesky virus scanner with WMI events
1. Looking into your MongoDB data with [PowerShell][1]
1. Freeing yourself from xml build languages with psake
1. Testing your .NET code using Pester
1. Automated UI testing with [PowerShell][1]
1. Writing a Visual Studio extension in 1 line of [PowerShell][1]
1. Using [PowerShell][1] to add Twitter and Jabber to VS
1. Using chewie and nuget to automate adding and updating libraries
1. Lightweight code generation with here string interpolation
1. Rapid UI prototyping with Show-UI
1. Automating debugging with WinDbg
1. Basic monitoring with [PowerShell][1]
1. Graphing monitoring data with [PowerShell][1] and gnuplot
1. Automating deployments
1. Automate smoke tests using [PowerShell][1] and VirtualBox
1. Using [PowerShell][1] to configure your application
1. Using [PowerShell][1] as an extensibillity point

This should give you a sense of the breadth and depth that is
available to you when you harness the power of [PowerShell][1].

## What is [PowerShell][1]? 
Citing [Wikipedia on Windows Powershell][2]:

>Windows PowerShell is Microsoft's task automation framework,
>consisting of a command-line shell and associated scripting language
>built on top of, and integrated with the .NET Framework. PowerShell
>provides full access to COM and WMI, enabling administrators to
>perform administrative tasks on both local and remote Windows systems.  

To expand on that a little [PowerShell][1] is built on .NET and uses
the .NET object model to give it it's competitive advantage.
Tasks ([Cmdlets][7] as they are officially called) can be composed
using the pipeline. Think of a UNIX shell but instead
of text flowing through the pipelines, .NET objects flow
through the pipelines. This relieves the user from "prayer based
parsing" with tools like e.g. `cut`, `sed`, `awk`. Combine this with the reflection
capabilities .NET has to offer, automatic (type) conversions, 
advanced parameter binding and you have a discoverable,
composition friendly working environment. Quoting [Jeffrey Snover][8],
(the architect behind the product now responsible for the entire
windows server platform): "It's like programming with hand grenades."
Watch [this][9] great [Going Deep][10] [episode][9] and see how
[Jeffrey][8] talks about this in detail with [Erik Meijer][11].

## Why should I care about PowerShell?
When I tried searching for the answer to this question I came up with
a list of blog-posts that were all oriented toward the IT-pro. For
reference I've included the links below in the [References section](#references). 
Apart from the hints given in the outline above on why you should
care. You may find yourself writing a [PowerShell module][5],
[Provider][6] or [Cmdlet][7] to help your users interact with the
application you are writing sooner than you think. When that's the
case it is crucial you have experience in [PowerShell][1], especially
since [PowerShell][1] requires you to abide to some specific naming
conventions. Furthermore [PowerShell][1] users expect certain
behaviors from the functionality you provide to be the same as they
are accustomed to from using other [Cmdlets][7] and [Providers][6].

The list of [PowerShell][1] features that are most useful for a .NET
developer as far as I can come up with from the top of my head:

- [PowerShell][1] is a better shell
- [PowerShell][1] has very good support for working with xml
- [PowerShell][1] is easy to learn
- [Powershell][1] is an automation engine and a shell using a nice language
- [PowerShell][1] can be used to quickly lookup methods and/or experiment
with .NET types
- [PowerShell][1] easily talks to COM
- [PowerShell][1] can be used to query WMI, hookup to WMI events
- [PowerShell][1] has a built-in registry provider, which means
you can access the registry with the familiar `dir`, `copy` and `del`
commands
- for those doing web development, the IIS team provides a [PowerShell][1]
module that covers 99% of IIS's functionality
- SQL Server 2008 and up have a very comprehensive [PowerShell][1]
module that contains both a [Provider][6] and a set of [Cmdlets][7].

I hope all of the above gets you intrigued and/or inspired to look into
[PowerShell][1], or at least to check back here for part 1 of
[this series][12]. Until next time, wield your new found powers wisely.

{% include date.inc %}
 
<h5 id="references">References</h5>
<div class="references">
<ul>
<li><a href='http://www.computerperformance.co.uk/powershell/#Reasons_to_Learn_Monad_' title='Reasons to learn Monad'>Richard Siddaway&#8217;s Blog: Reaons to learn Monad</a></li>
<li><a href='http://www.techrepublic.com/blog/10things/10-reasons-why-you-should-learn-to-use-powershell/1073' title='10 reasons why you should learn to use PowerShell'>TechRepublic: 10 reasons why you should learn to use PowerShell</a></li>
<li><a href='http://technet.microsoft.com/en-us/scriptcenter/dd742419' title='Scripting with Windows PowerShell'>Technet: Scripting with Windows PowerShell</a></li>
<li><a href='http://en.wikipedia.org/wiki/Windows_PowerShell' title='Wikipedia entry for Windows PowerShell'>Wikipedia: Windows PowerShell</a></li>
<li><a href='http://msdn.microsoft.com/en-us/library/ms714395(v=VS.85).aspx' title='Cmdlet Overview'>Cmdlet Overview</a></li>
<li><a href='http://msdn.microsoft.com/en-us/library/ee126186(v=vs.85).aspx' title='Windows PowerShell Provider Overview'>Windows Powerhell Provider Overview</a></li>
<li><a href='http://go.microsoft.com/fwlink/?LinkId=144916'
title='Writing a Windows PowerShell Module'>Writing a Windows
PowerShell Module</a></li>
<li><a
href='http://www.microsoft.com/presspass/exec/de/snover/default.mspx'
title='Jeffrey Snover'>Jeffrey Snover</a></li>
<li><a
href='http://channel9.msdn.com/shows/Going+Deep/Expert-to-Expert-Erik-Meijer-and-Jeffrey-Snover-Inside-PowerShell/'
title='Expert to Expert: Erik Meijer and Jeffrey Snover - Inside PowerShell'>Expert to Expert: Erik Meijer and Jeffrey Snover - Inside PowerShell</a></li>
<li><a href='http://channel9.msdn.com/Shows/Going+Deep' title='Going Deep'>Going Deep</a></li>
<li><a href='http://research.microsoft.com/en-us/um/people/emeijer/'
title='Erik Meijer'>Erik Meijer</a></li>
<li><a href='/tags/ps4.netdevs.html' title='PS for .NET devs category'>PS for .NET devs category</a></li>
</ul>
</div>

[1]: http://technet.microsoft.com/en-us/scriptcenter/dd742419 "Scripting with Windows PowerShell"
[2]: http://en.wikipedia.org/wiki/Windows_PowerShell "Wikipedia entry for Windows PowerShell"
[3]: http://www.computerperformance.co.uk/powershell/#Reasons_to_Learn_Monad_ "Reasons to learn Monad"
[4]: http://www.techrepublic.com/blog/10things/10-reasons-why-you-should-learn-to-use-powershell/1073 "10 reasons why you should learn to use PowerShell"
[5]: http://go.microsoft.com/fwlink/?LinkId=144916  "Writing a Windows PowerShell Module"
[6]: http://msdn.microsoft.com/en-us/library/ee126186(v=vs.85).aspx "Windows PowerShell Provider Overview"
[7]: http://msdn.microsoft.com/en-us/library/ms714395(v=VS.85).aspx "Cmdlet Overview"
[8]: http://www.microsoft.com/presspass/exec/de/snover/default.mspx "Jeffrey Snover"
[9]: http://channel9.msdn.com/shows/Going+Deep/Expert-to-Expert-Erik-Meijer-and-Jeffrey-Snover-Inside-PowerShell/ "Expert to Expert: Erik Meijer and Jeffrey Snover - Inside PowerShell"
[10]: http://channel9.msdn.com/Shows/Going+Deep "Going Deep" 
[11]: http://research.microsoft.com/en-us/um/people/emeijer/ "Erik Meijer"
[12]: /tags/ps4.netdevs.html "PS for .NET devs category"

<hr/>
<h2><a href="/2011-06-22/ps4.netdev-1-getting-started-with-powershell/">PS for .NET devs part 1: Getting started with PowerShell</a></h2>
{% assign my_date = ' Wed 22 Jun 2011' %}
After getting everybody warmed to the idea of learning [PowerShell][1]
in [part 0][0] of this [series][12]. Let's dig into a couple of ways
to get started with [PowerShell][1].

## The resource list
By now [PowerShell][1] has gained so much traction at this moment that
I could probably fill several dozen pages with links, pointers to the
excellent resources available on-line or in print. However I will
refrain myself to a couple starting points.

### On-line resources
- [PowerShell Community Toolbar][2]
  This is a browser plug-in that aggregates a big set of resources,
  from download links to the various [PowerShell][1] releases to a
  huge list of blogs filled with [PowerShell][1] content, to the
  localized [PowerShell][1] on-line help. Even if you are not very
  fond of browser toolbars I suggest you install it, take some time to
  follow the various links save them and uninstall the toolbar.
- [ScriptCenter PowerShell homepage][1] this contains loads of
  resources to get you started and should be considered the canonical
  starting point for finding [PowerShell][1] related resources. 
- [Windows PowerShell Survival guide][5]
  A large list of resources to get you started, compiled by the community.
- [PowerScripting podcast][4]
  If you have some time during you commute or any other activity that
  allows you to listen to some audio I highly recommend this show. The
  show notes are of a great quality, and contain lots of links to
  learning resources. The first shows take you step
  by step through the process of learning [PowerShell][1]. 

### (e-)Books

- [Effective Windows PowerShell][7]
  A great set of tips, explanations to be as the title suggests
  effective with [PowerShell][1].
- [Master-PowerShell][6]
  A very comprehensive free e-book starting with the basics and ending
  with a guide to remoting.   
- [Windows PowerShell in Action, Second Edition][3]
  This is in my opinion the [PowerShell][1] book available today that
  is the best suited for developers. It goes into all the details of
  the language and is very well written. Be sure to get the (recently)
  released second edition, since it is filled with loads of extra
  content covering the [PowerShell][1] version 2 features.


## Just use PowerShell instead of cmd
When learning something new it is always nice to be able to start with
something familiar. The beauty of [PowerShell][1] is that all your
previous knowledge about your favorite command-line tools are not
lost. [PowerShell][1] is a shell which means you can use it to start
any of tool you used to start in cmd. Moreover the [PowerShell][1]
team has incorporated a large number of [aliases][8] that should be
familiar to you whether you are coming from a linux or cmd background
the commands you know like `dir`, `ls`, `cd`, `del`, `rm` all work as you
would expect. These aliases are also very handy for those who don't
like to type long commands at the prompt. To get an idea of what
aliases are available try the following:

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS> dir alias: | Out-Host -Paging
]]>
</script>

Using [PowerShell][1] as your preferred shell gives you the
opportunity to gradually learn [PowerShell][1] and just
lookup/research stuff as you use it in your day to day work.

## The 3 amigo's of discovery 
When learning [PowerShell][1] I've found that the most helpful and
best [Cmdlets][9] are the following three.

### Get-Help
[`Get-Help`][10] does exactly what you would expect especially when you know
it's aliases: `man`, `help`. You can get the help on help by typing `help`
at the prompt. This shows you how you can use [`Get-Help`][10]. Note
that [PowerShell][1] also comes with topical help pages that start
with `about_` to get an overview of the available topics type: 

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS> help about_*
]]>
</script>
 at the [PowerShell][1] prompt.

### Get-Command
[`Get-Command`][11] provides a way to search for a Cmdlet you would
like to use. Looking at the output of `help Get-Command` or shorter
`Get-Command -?` you will see that one of the parameter sets contain
the `-Noun` and `-Verb` parameters. The naming convention used for
Cmdlets is `<Verb>-<Noun>` this makes remembering and searching the
Cmdlets a lot easier. Say for instance I would like to know all
Cmdlets that remove stuff then 

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS> Get-Command -Verb remove
]]>
</script>
will list them nicely. If I would like to know what Cmdlets are available for
working with computer objects, I would type: 
<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS> Get-Command -Noun Computer
]]>
</script> 

### Get-Member
[`Get-Member`][13] list all member that is public methods and properties
of the object passed to it. This ideal for finding what information
can be extracted from an object, what you can do with a specific
object respectively. To for instance lookup what properties you could
use on a file to sort in a directory listing you could type 

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS> dir | Get-Member
]]>
</script>
Or if you don't want to wait on a slowly loading MSDN page to lookup
what methods are available to you on a [`TimeSpan`][14] object you
could use something like:

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS> New-Object TimeSpan | Get-Member 
]]>
</script>

Or if you can't remember the way `SubString` works type:

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS> ""| gm
]]>
</script>
where `gm` is the (shorter) alias for [`Get-Member`][13].

I hope this provides enough pointers to guide you through your first
steps to [PowerShell][1] mastery. Check back soon for part 2 of
[this series][12] when we dive in to the [PowerShell][1] language as
viewed through the eyes of a C# developer.

{% include date.inc %}

<h5 id="references">References</h5>
<div class="references">
<ul>
<li><a href='/2011-06-19/ps4.netdevs-0-what-and-why/' title='PS for .NET devs part 0: PowerShell what is it and why should I care?'>PS for .NET devs part 0: PowerShell what is it and why should I care?</a></li>
<li><a href='http://technet.microsoft.com/en-us/scriptcenter/dd742419' title='Scripting with Windows PowerShell'>Technet: Scripting with Windows PowerShell</a></li>
<li><a href='http://powershell.ourtoolbar.com/' title='PowerShell Community Toolbar'>PowerShell Community Toolbar</a></li>
<li><a href='http://www.manning.com/payette2/' title='Windows PowerShell in Action'>Windows PowerShell in Action</a></li>
<li><a href='http://powerscripting.net/' title='PowerScripting Podcast'>PowerScripting Podcast</a></li>
<li><a href='http://social.technet.microsoft.com/wiki/contents/articles/windows-powershell-survival-guide.aspx#Learning_Resources' title='Windows PowerShell Survival Guide'>Windows PowerShell Survival Guide</a></li>
<li><a href='http://powershell.com/cs/blogs/ebook/' title='Master-PowerShell'>Master-PowerShell</a></li>
<li><a href='http://rkeithhill.wordpress.com/2009/03/08/effective-windows-powershell-the-free-ebook/' title='Effective Windows PowerShell'>Effective Windows PowerShell</a></li>
<li><a href='http://technet.microsoft.com/library/dd347645(en-us).aspx' title='About Aliases'>About Aliases</a></li>
<li><a href='http://msdn.microsoft.com/en-us/library/ms714395(v=VS.85).aspx' title='Cmdlet Overview'>Cmdlet Overview</a></li>
<li><a href='http://go.microsoft.com/fwlink/?LinkID=113316' title='Get-Help online help'>Get-Help online help</a></li>
<li><a href='http://go.microsoft.com/fwlink/?LinkID=113309' title='Get-Command online help'>Get-Command online help</a></li>
<li><a href='/tags/ps4.netdevs.html' title='PS for .NET devs category'>PS for .NET devs category</a></li>
<li><a href='http://go.microsoft.com/fwlink/?LinkID=113322' title='Get-Member online help'>Get-Member online help</a></li>
<li><a href='http://msdn.microsoft.com/en-us/library/system.timespan.aspx' title='msdn: TimeSpan'>msdn: TimeSpan</a></li>
</ul>
</div>
[0]: /2011-06-19/ps4.netdevs-0-what-and-why/ "PS for .NET devs part 0: PowerShell what is it and why should I care?"
[1]: http://technet.microsoft.com/en-us/scriptcenter/dd742419 "Scripting with Windows PowerShell"
[2]: http://powershell.ourtoolbar.com/ "PowerShell Community Toolbar"
[3]: http://www.manning.com/payette2/ "Windows PowerShell in Action"
[4]: http://powerscripting.net/ "PowerScripting Podcast"
[5]: http://social.technet.microsoft.com/wiki/contents/articles/windows-powershell-survival-guide.aspx#Learning_Resources "Windows PowerShell Survival Guide"
[6]: http://powershell.com/cs/blogs/ebook/ "Master-PowerShell"
[7]: http://rkeithhill.wordpress.com/2009/03/08/effective-windows-powershell-the-free-ebook/ "Effective Windows PowerShell"
[8]: http://technet.microsoft.com/library/dd347645(en-us).aspx "About Aliases"
[9]: http://msdn.microsoft.com/en-us/library/ms714395(v=VS.85).aspx "Cmdlet Overview"
[10]: http://go.microsoft.com/fwlink/?LinkID=113316 "Get-Help online help"
[11]: http://go.microsoft.com/fwlink/?LinkID=113309 "Get-Command online help"
[12]: /tags/ps4.netdevs.html
[13]: http://go.microsoft.com/fwlink/?LinkID=113322 "Get-Member online help"
[14]: http://msdn.microsoft.com/en-us/library/system.timespan.aspx "msdn: TimeSpan"

<hr/>
<h2><a href="/2011-11-14/ps4.netdevs-2-powershell-syntax/">PS for .NET devs part 2: Comparing the PowerShell language to C#</a></h2>
{% assign my_date = ' Mon 14 Nov 2011' %}
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
C#           | PowerShell  | Description                        
-------------|-------------|-----------------------------------
 `//`        | `#`         | single line                        
 `/* ... */` | `<# ... #>` | multi line                         
 `///`       |             | single line documentation comments 

#### Comment documentation keywords
[PowerShell][1] is also blessed with comment-based help but
because it does not have any formating keywords and does not focus on
types, a lot of the corresponding keywords have no equivalent in the
[PowerShell][1] column. [PowerShell][1] supports more keywords than
the ones listed below for the entire story please use
[PowerShell][1]'s built in help: `help about_Comment_Based_Help` or the [online documentation][help]:

C#              | PowerShell      | Description                                           
----------------|-----------------|-------------------------------------------------------
 `<c>`          |                 | Set text in a code-like font                          
 `<code>`       |                 | Set one or more lines of source code or program output
 `<example>`    | `.EXAMPLE`      | Indicate an example                                   
 `<exception>`  |                 | Identify the exceptions a method can throw          
 `<include>`    | `.EXTERNALHELP` | Includes XML from an external file                    
 `<list>`       |                 | Create a list or table                                
 `<para>`       |                 | Permit structure to be added to text                  
 `<param>`      | `.PARAMETER`    | Describe a parameter for a method or constructor      
 `<paramref>`   |                 | Identify that a word is a parameter name              
 `<permission>` |                 | Document the security accessibility of a member       
 `<remarks>`    |                 | Describe a type                                       
 `<returns>`    | `.OUTPUTS`      | Describe the return value of a method                 
 `<see>`        | `.LINK`         | Specify a link                                        
 `<seealso>`    | `.LINK`         | Generate a See Also entry                             
 `<summary>`    | `.SYNOPSIS`     | Describe a member of a type                           
 `<value>`      |                 | Describe a property                                   
                | `.NOTES`        | Additional information about the function or script   
                | `.DESCRIPTION`  | A detailed description of the function or script      
                | `.INPUTS`       | The inputs that can be piped to the function or script

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
<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS>"my $PSCulture is dutch"
My nl-NL is dutch.
PS>'my $PSCulture is dutch'
My $PSCulture is dutch.
]]>
</script>
- [PowerShell][1] supports `HashTable` literals of the form: `@{
  <name> = <value>; [<name> = <value> ] ... }`. Below you can see that
  `HashTable` literals can be split across multiple lines in which
  case the semicolons (`;`) after the name-value pair can be omitted
  leaving a nice and readable `HashTable` behind.
<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS>$table = @{ a=37; b=42;}
PS>$ttable = @{
>>a=37
>>b=43
>>}
>>
PS>
]]>
</script>  

### Variables
In [PowerShell][1] variable declarations don't require explicit
typing, they do however have to be prefixed with a `$`.   

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS>$now = [DateTime]::UtcNow
PS>$message = 'hello'
]]>
</script>

Being a .NET developer you're probably wondering how you can create
objects in [PowerShell][1]. There is no `new` keyword but there is a
[`New-Object`][new] [Cmdlet][cmdl]. It can for example be used like
this:

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS>$dateofbirth = New-Object DateTime -ArgumentList 1972,7,12
PS>$feeds = new-object -Com Microsoft.FeedsManager
PS>$feeds.IsSubscribed("http://basbossink.github.com/atom.xml")
True
]]>
</script>

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
<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS>1,2,3 -join '*'
1*2*3
PS>$env:PATH -split ';'
%SystemRoot%\system32\WindowsPowerShell\v1.0\
&vellip; 
]]></script>

- Call operator: `&` 
  Run a command, script, or script block.

<script type="syntaxhighlighter" class="brush: ps"><![CDATA[
PS>& 'C:\Program Files (x86)\GNU\GnuPG\sha256sum.exe' test.iso
]]>
</script>

- Dot sourcing operator: `.`   
  Runs a script so that the variables, functions defined in the script
  are part of the calling scope.

- Static member operator: `::`   
  Used to call static method or retrieve
  static properties of a .NET Framework class.
<script type="syntaxhighlighter" class="brush: ps">
<![CDATA[[Math]::Sin(([Math]::PI)/2)]]></script>

- Range operator: `..`   
  Represents the sequential integers within the given 
  upper and lower boundary.
<script type="syntaxhighlighter" class="brush: ps">
<![CDATA[PS>1..10 -join ','
1,2,3,4,5,6,7,8,9,10]]></script>

- Format operator: `-f`   
  The following two pieces of code are equivalent (starting with C#):
<script type="syntaxhighlighter" class="brush: csharp">
<![CDATA[Math.PI.ToString("{0:0.00}")]]></script>
<script type="syntaxhighlighter" class="brush: ps">
<![CDATA["{0:0.00}" -f [Math]::PI]]></script>

- Subexpression operator: `$()`  
  Returns the result of one or more statements.
  Very handy in string interpolation like  
<script type="syntaxhighlighter" class="brush: ps">
<![CDATA[
PS>"This machine has $([Environment]::ProcessorCount) cpu's"
This machine has 2 cpu's
]]></script>

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

<script type="syntaxhighlighter" class="brush: ps">
<![CDATA[
function Get-SumOfSquares { 
    begin { $result = 0 }
    process { $result += $_ * $_ }
    end { $result }
}
1..25 | 
ForEach-Object { Get-Random -Maximum 100 } | 
Get-SumOfSquares
]]></script>

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

<script type="syntaxhighlighter" class="brush: ps">
<![CDATA[
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
]]></script>
After pasting this in the [PowerShell][1] console an example usage
might look like the screenshot below.
![Get-SumOfSquares example interaction][sumpic] 

### Epilogue
This is my brief summary of the syntactic differences between C# and
[PowerShell][1]. I hope this can help you with coming to grips with
[PowerShell][1]. Next time we'll look at how easy it is to work with
XML in [PowerShell][1] and munge a large [MSBuild][msb] file with a
small script. 

{% include date.inc %}

##### References
<div class="references">
<ul>
<li><a href='/2011-06-19/ps4.netdevs-0-what-and-why/' title='PS for .NET devs part 0: PowerShell what is it and why should I care?'>PS for .NET devs part 0: PowerShell what is it and why should I care?</a></li>
<li><a href='http://technet.microsoft.com/en-us/scriptcenter/dd742419' title='Scripting with Windows PowerShell'>Technet: Scripting with Windows PowerShell</a></li>
<li><a href='/tags/ps4.netdevs.html' title='PS for .NET devs category'>PS for .NET devs category</a></li>
<li><a
href='/2011-06-22-ps4.netdev-1-getting-started-with-powershell/' title='PS for .NET devs part 1: Getting started with PowerShell'>
PS for .NET devs part 1: Getting started with PowerShell</a></li>
<li><a href='http://blogs.msdn.com/b/powershell/archive/2011/04/16/powershell-language-now-licensed-under-the-community-promise.aspx' title='Powershell Language specification announcement'>Powershell Language specification announcement</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd315285.aspx'
title='About Break'>About Break</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd819489.aspx'
title='About Comment Based Help'>About Comment Based Help</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd347559.aspx'
title='About Continue'>About Continue</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd347715.aspx'
title='About Switch'>About Switch</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd819510.aspx'
title='About Throw'>About Throw</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd347548.aspx'
title='About Trap'>About Trap</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd315350.aspx'
title='About Try, Catch, Finally'>About Try, Catch, Finally</a></li>
<li><a href='http://www.perl.org'
title='The Perl Programming Language'>The Perl Programming Language</a></li>
<li><a href='http://perldoc.perl.org/functions/die.html'
title='The Perl die Function'>The Perl die Function</a></li>
<li><a href='http://msdn.microsoft.com/en-us/library/wea2sca5.aspx'
title='MSBuild'>MSBuild</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd315334.aspx'
title='New-Object'>New-Object</a></li>
<li><a href='http://msdn.microsoft.com/en-EN/library/ms714395(v=VS.85).aspx'
title='Cmdlet overview'>Cmdlet overview</a></li>
<li><a href='http://stackoverflow.com/questions/1145312/'
title='StackOverflow question about type accelerators'>StackOverflow question about type accelerators</a></li>
<li><a href='http://stackoverflow.com'
title='StackOverflow'>StackOverflow</a></li>
<li><a href='http://msdn.microsoft.com/en-us/library/system.collections.ienumerator.current.aspx'
title='Current property'>Current property</a></li>
<li><a href='http://msdn.microsoft.com/en-us/library/system.collections.ienumerator.aspx'
title='IEnumerator interface'>IEnumerator interface</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd315326.aspx'
title='About Functions Advanced'>About Functions Advanced</a></li>
<li><a href='http://en.wikipedia.org/wiki/AWK'
title='The Awk programming language'>The Awk programming language</a></li>
<li><a href='http://www.gnu.org/s/gawk/manual/gawk.html#BEGIN_002fEND'
title='GNU Awk Begin End syntax'>GNU Awk Begin End syntax</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd347733.aspx'
title='About Foreach'>About Foreach</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd347608.aspx'
title='ForEach-Object'>ForEach-Object</a></li>
<li><a href='http://technet.microsoft.com/en-us/library/dd347675.aspx'
title='About Automatic Variables'>About Automatic Variables</a></li>
</ul>
</div>
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
[sumpic]: /images/GetSumOfSquaresSample.png "Get-SumOfSquares example interaction"
[af]: http://technet.microsoft.com/en-us/library/dd315326.aspx "About Functions Advanced"
[awk]: http://en.wikipedia.org/wiki/AWK "The Awk programming language"
[awkbeg]: http://www.gnu.org/s/gawk/manual/gawk.html#BEGIN_002fEND "GNU Awk Begin End syntax"
[fe]: http://technet.microsoft.com/en-us/library/dd347733.aspx "About Foreach"
[feo]: http://technet.microsoft.com/en-us/library/dd347608.aspx "ForEach-Object"
[av]: http://technet.microsoft.com/en-us/library/dd347675.aspx "About Automatic Variables"


