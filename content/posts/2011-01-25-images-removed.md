+++
date = "2011-01-25"
title = "Generated Stack Overflow flair in text"
+++

Those of you who've visited here before would have noticed the list of
badges in the right column. These were the standard badges you can
find all around the internet. Looking at the output of
[Pingdom][ping], [YSlow][yslow] and [WebSiteOptimization.com][wso] I
decided that removing a number of images from the site would improve
the load time. Furthermore [FriendFeed][ff] seemed to be having
performance problems of their own. Since I'm not a heavy
[FriendFeed][ff] user I decided to remove the badge entirely. 

## Stack Overflow API

One of the things [Stack Overflow][so] provides (besides being the most
awesome Q&A site on the web today) is [flair][flair], a badge you can put
on your web-page showing your [avatar][avat], reputation and badge
counts. I was aware of the fact that [Stack Overflow][so] also
provides an [API][api]. So I thought to myself let's
combine these two to provide a text-only badge. 

### The API

### Consuming [JSON][json] in [Ruby][ruby]

Searching for [JSON][json] and [Ruby][ruby] presents [this gem][jsonr]
as the first result. Looking through the documentation I decided to
give it a go. Since [Stack Overflow][so]'s [API][api] is a web-service
I looked up the documentation for [Ruby][ruby]'s http client. 


[jsonr]: http://flori.github.com/json/ "JSON implementation for Ruby"
[ruby]: http://www.ruby-lang.org/en/ "Ruby"
[json]: http://json.org/ "JSON" 
[so]: http://stackoverflow.com "Stack Overflow"
[avat]: http://en.wikipedia.org/wiki/Avatar_(computing) "Avatar"
[ff]: http://friendfeed.com/ "FriedFeed"
[api]: http://en.wikipedia.org/wiki/Application_programming_interface "Application programming interface"
[haml]: http://haml-lang.com/ "Haml"
[flair]: http://stackoverflow.com/users/flair "Stack Overflow flair"
[wso]: http://www.websiteoptimization.com/ "WebSiteOptimization.com"
[yslow]: http://developer.yahoo.com/yslow/ "YSlow"
[ping]: http://tools.pingdom.com "Pingdom"
