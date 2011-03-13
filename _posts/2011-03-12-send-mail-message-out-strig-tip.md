---
title: Quick Powershell tip concerning Out-String and Send-MailMessage
layout: post
published: true
categories: 
- PowerShell
keywords:
- Send-MailMessage
- ConvertTo-Html
- Out-String
--- 
Recently I wrote a script at work to generate a report about the load
on a set of servers. The gathered statistics were mailed around
everything nice and dandy. But after a few weeks something strange
happened the body of the mail message containing a nice table got
turned into gibberish.

## Cause 
I really didn't understand want went wrong all of a sudden, so
I started to inspect the output of the script. And low and behold the
trouble was caused by the fact that [Out-String][os] by default puts
only 80 characters in a line. Quoting the documentation: 

> -Width &lt;int&gt;
> Specifies the number of characters in each line of output. Any
> additional characters are truncated, not wrapped. If you omit this
> parameter, the width is determined by the characteristics of the host.
> The default for the PowerShell.exe host is 80 (characters).

If you're lucky the line breaks end up outside of your tags which was
the case for me the first couple of times the script ran. But if
[Out-String][os] happens to break the line inside an HTML tag, your
output gets garbled.

## Solution
I thought this would be easy to fix just specify `[int]::MaxValue` for
the `-Width` parameter to <code>Out&#8209;String</code>. Trying that in a
[PowerShell][ps] console gave:
![Out-String with unsatisfactory result][wr]
Hum, seems like the `[int]::MaxValue` doesn't get evaluated before it
is interpreted by <code>Out&#8209;String</code> so some extra parenthesis should do the
trick. 

## End result
The paragraph of code that I use to send around an HTML table
containing the load statistics hence becomes something like this:
<div class="highlight">
<code>
<span style='color:#FF4500'>$messageParameters</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>=</span><span style='color:#000000'>&nbsp;</span><span style='color:#000000'>@{</span><br />
<span style='color:#000000'>&nbsp;&nbsp;&nbsp;&nbsp;</span><span style='color:#000000'>Subject</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>=</span><span style='color:#000000'>&nbsp;</span><span style='color:#8B0000'>&quot;Weekly load report&quot;</span><br />
<span style='color:#000000'>&nbsp;&nbsp;&nbsp;&nbsp;</span><span style='color:#000000'>Body</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>=</span><span style='color:#000000'>&nbsp;</span><span style='color:#000000'>(</span><span style='color:#0000FF'>Get-LoadStatistics</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>|</span><span style='color:#000000'>&nbsp;</span><span style='color:#0000FF'>ConvertTo-Html</span><span style='color:#000000'>&nbsp;</span><span style='color:#000080'>-Head</span><span style='color:#000000'>&nbsp;</span><span style='color:#FF4500'>$head</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>|</span><span style='color:#000000'>&nbsp;</span><br />
<span style='color:#000000'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span><span style='color:#0000FF'>Out-String</span><span style='color:#000000'>&nbsp;</span><span style='color:#000080'>-Width</span><span style='color:#000000'>&nbsp;</span><span style='color:#000000'>(</span><span style='color:#008080'>[int]</span><span style='color:#A9A9A9'>::</span><span style='color:#000000'>MaxValue</span><span style='color:#000000'>)</span><span style='color:#000000'>)</span><br />
<span style='color:#000000'>&nbsp;&nbsp;&nbsp;&nbsp;</span><span style='color:#000000'>From</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>=</span><span style='color:#000000'>&nbsp;</span><span style='color:#8B0000'>&quot;donotreply@devnull.org&quot;</span><br />
<span style='color:#000000'>&nbsp;&nbsp;&nbsp;&nbsp;</span><span style='color:#000000'>To</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>=</span><span style='color:#000000'>&nbsp;</span><span style='color:#8B0000'>&quot;fred.flinstone@bedrock.com&quot;</span><br />
<span style='color:#000000'>&nbsp;&nbsp;&nbsp;&nbsp;</span><span style='color:#000000'>SmtpServer</span><span style='color:#000000'>&nbsp;</span><span style='color:#A9A9A9'>=</span><span style='color:#000000'>&nbsp;</span><span style='color:#8B0000'>&quot;my.smtpserver&quot;</span><br />
<span style='color:#000000'>}</span><br />
<span style='color:#0000FF'>Send-MailMessage</span><span style='color:#000000'>&nbsp;</span><span style='color:#FF4500'>@messageParameters</span><span style='color:#000000'>&nbsp;</span><span style='color:#000080'>-BodyAsHtml</span>
</code> 
</div>

I hope this helps anybody using the Power to send nice reports.

{% include date.inc %}

[os]: http://technet.microsoft.com/en-us/library/dd315365.aspx "Out-String" 
[ps]: http://technet.microsoft.com/en-us/scriptcenter/dd742419 "PowerShell"
[wr]: /images/wrong-width.png "Wrong syntax for the width parameter"
























