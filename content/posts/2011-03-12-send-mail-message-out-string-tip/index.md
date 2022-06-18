+++
date = "2022-06-18"
title = "Quick Powershell tip concerning Out-String and Send-MailMessage"
+++ 
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

~~~ ps1
$messageParameters = @{
    Subject = "Weekly load report"
    Body = (Get-LoadStatistics | ConvertTo-Html -Head $head | 
        Out-String -Width ([int]::MaxValue))
    From = "donotreply@devnull.org"
    To = "fred.flinstone@bedrock.com"
    SmtpServer = "my.smtpserver"
}
Send-MailMessage @messageParameters -BodyAsHtml
~~~


I hope this helps anybody using the Power to send nice reports.



[os]: http://technet.microsoft.com/en-us/library/dd315365.aspx "Out-String" 
[ps]: http://technet.microsoft.com/en-us/scriptcenter/dd742419 "PowerShell"
[wr]: wrong-width.png "Wrong syntax for the width parameter"
























