+++
date = "2021-11-21"
title = "Rising sun"
+++ 
Recently my interest in the [Go][go] programming language changed from dormant back to active. Being a [.NET][net] developer by day and frankly getting new feature fatigue. I was drawn to a simpler world. I studied Go in the past using e.g. [exercism][exc] and watching every [Rob Pike youtube video][rpyt] I could find. I brushed up on what I learned before and found that with the introduction of Go [modules][mod], life improved quite a bit. I was lucky to find the fantastic [Just for func youtube channel][jff], that really helped me to learn more about the practicalities of writing Go code. 

## The likes

I started by writing a really small stub implementation of a [SOAP][soap] service at work. This was really easy given the excellent support for HTTP in the [net/http][nethttp] package and [Fiddler][fiddler]. My routine was,
- detect what calls to the service were being made, 
- grab the response body using Fiddler, 
- reformat it, 
- paste it into the Go code, 
- check if some part of the response needed to be parameterized, 
- if so add some `%s` directives and use `fmt.Fprintf` instead of `fmt.Printf` to write to the response. 

I especially appreciated that the standard library fills the HTTP `Content-Type` header correctly based on the content written to the writer. 

## Inception

With this positive experience behind me, I was trying to find a next project to work on. Recently I was experimenting with moving my work tracking/todo list management setup from [Emacs Org-Mode][org] to [Taskwarrior][tw]. What I was missing was the ability to make brief notes about activities that were not planned or part of my todo list but that I do anyway. Think of things like helping a coworker with some problem they are having, or e.g. responding to an email from a customer. I'm aware of the [`log`][log] command of taskwarrior but I felt these smallish items should not pollute my task list. I tried [taskbook][tb] to fill in this gap but wasn't happy with it. So what else to do but to write something really simple myself. This marked the birth of [sun][sun].

## Design

One key feature I wanted to implement was that notes would only be shown of the recent past. Next to that sun should be fast and perform in constant time. Another restriction I put on myself was to only use the Go standard library. Once I looked at the different options in the [encoding][enc] package. I decided to use [encoding/gob][gob] and [encoding/binary][encbin] in conjunction to be able to read the data file starting at the end. The file layout is explained in the picture below, courtesy of the excellent [svgbob][svgbob] application.

![sun file layout](https://stand-up-notes.org/diag-d5114b597967979fdc5fe4880f64ae82.svg) 

This layout has two main advantages it is simple to write when appending a new entry to the file and it can be read in reverse from the end of the file in a straightforward manner.

## Implementation

The implementation of the reading and writing of the data was done quickly. The rest of the application was a lot of getting used to how error handling is done in Go. Having played with languages such as [Rust][rust], the Go usage of errors is still something I struggle with. Being a fan of small functions I found it hard to choose the correct function size in Go without *duplicating* the error handling on multiple levels.  

## Following through

My GitHub account currently counts a large number of dreams/ideas and someday maybes. What made this project different was that I wanted the functionality for my daily work and it was small and simple enough that I could implement it in a limited amount of time. I was also very pleased to have found [Asciidoctor][ad] which allowed me to have a `README` file that is presented on GitHub nicely, which can be transformed into a simple website easily. Asciidoctor also supports [conditionals][cond], which makes it possible to include parts of the document only when processed by GitHub for instance. A few clicks on [Netlify][netlify] and a deployment one-liner and Bob's your uncle. The fact that Go makes cross-compilation so easy and some [shell scripting][rel] made it easy to publish a release to GitHub semi-automatically. Since I don't expect to add any features to sun trying to fully automate the release process seems overkill.

## In conclusion

I had some real fun implementing sun and learning a lot about Go in the process. Have a look at the code on [GitHub][src] if your interested. If you have any suggestions about possible improvements for the code please let me know, I'm eager to learn. I hope this very small utility provides some value to others, 🙏.


[go]: https://golang.org/
[net]: https://dotnet.microsoft.com/
[exc]: https://exercism.org/
[rpyt]: https://www.youtube.com/results?search_query=rob+pike+golang
[mod]: https://golang.org/doc/#developing-modules 
[jff]: https://www.youtube.com/c/JustForFunc
[soap]: https://en.wikipedia.org/wiki/SOAP
[nethttp]: https://pkg.go.dev/net/http
[fiddler]: https://www.telerik.com/fiddler
[org]: https://orgmode.org/
[tw]: https://taskwarrior.org/
[sun]: https://stand-up-notes.org
[enc]: https://pkg.go.dev/encoding
[gob]: https://pkg.go.dev/encoding/gob
[encbin]: https://pkg.go.dev/encoding/binary
[svgbob]: https://github.com/ivanceras/svgbob 
[rust]: https://rust-lang.org/
[ad]: https://asciidoctor.org/
[netlify]: https://netlify.com/
[src]: https://github.com/basbossink/sun
[tb]: https://github.com/klaussinani/taskbook
[log]: https://taskwarrior.org/docs/commands/log.html
[cond]: https://docs.asciidoctor.org/asciidoc/latest/directives/conditionals/
[rel]: https://github.com/basbossink/sun/blob/main/release.sh
