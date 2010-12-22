---
published: true
title: PowerShell as a compositional computation engine
layout: post
categories: [PowerShell,extendibillity]
---


In this post I will be making the case for using [Windows PowerShell][ps] as a
general purpose computation engine with a [pipes and filters][pf] archictecture.
This might seem odd at first since [PowerShell][ps] is designed to be
a tool that helps system administrators automate tasks they encounter
in their day to day activities. In my opinion however [PowerShell][ps]
has a number of features and has an easy enough extensibillity story
that makes it a perfect candidate to use it to develop a domain
specific toolkit that can be used by end users.

## Extensibillity
[PowerShell][ps] provides a number of options for extinding it and/or
embedding it in your software.
### The Provider
The [Windows PowerShell Provider][pr] gives you as a developer the
oppertunity to surface your specific data as file system structure
that can be easily accessed through powershell. To give you a more
concrete idea 

[ps]: http://technet.microsoft.com/nl-nl/scriptcenter/dd742419.aspx "PowerShell"
[pf]: http://www.eaipatterns.com/PipesAndFilters.html "Pipes and Filters"
[pr]: http://msdn.microsoft.com/en-us/library/ee126186(v=VS.85).aspx "Windows PowerShell Provider"

