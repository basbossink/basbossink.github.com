---
layout: default
title: Posts tagged ps4.netdevs
keywords: [.NET,.NET development,PowerShell,PowerShell advocacy,development,ps4.netdevs]
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
[12]: /tags/ps4.netdevs.html


