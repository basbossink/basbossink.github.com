---
layout: default
title: Posts tagged Jekyll
keywords: [Disqus,Haml,Jekyll,categories,comments,git,rake,ruby]
---
<h2><a href="/2011-01-16/blog-setup/">Combining Jekyll, Haml and Sass with GitHub Pages</a></h2>
{% assign my_date = ' Sun 16 Jan 2011' %}
Using [Git][git] introduced me to the wonderful services of
[GitHub][gith]. One of the many great features of [GitHub][gith] is
something known as [GitHub Pages][githp]. To quote the
[GitHub Pages][githp] intro:
> The GitHub Pages feature allows you to publish content to the web by
> simply pushing content to one of your GitHub hosted repositories. 
You can use [GitHub Pages][githp] for the website of your project or
as a 'User Page'. [GitHub][gith] uses [Git][git]'s
[post-commit hooks][poch], to invoke [Jekyll][jek] a [Ruby][ruby]
based static site generator.

## Enter Haml

Writing HTML by hand is somewhat tiresome, [Jekyll][jek] relieves this
burden for the most part by providing rendering of [Markdown][md] or
[Textilize][text] if that's what you prefer. The layout pages still require you to
write HTML though. [Haml][haml] is a [Rails][rails] view engine that has
a really nice syntax and has the ability to execute [Ruby][ruby] code.
After converting my [default layout][dlay] from HTML to [Haml][haml],
I was really happy with the result. The structure was much more clear
and no more of those missing end tags. [Haml][haml] is not
integrated into the stock [Jekyll][jek] version, [here][hamlp] is a
[Jekyll plugin][jekp], that does the trick. This plugin works great
for the content and stylesheets but does not work for the `_layout`
content. Therefor I decided to call [Rake][rake] to the rescue and use
the following rule to generate the HTML for the `_layout` directory

{% highlight ruby linenos %}

rule '.html' => ['.haml'] do |t|
    sh %{ haml -E utf-8 #{t.source} #{t.name.sub(/_haml\./,'.')} }
end

{% endhighlight %}

Note the non-standard output filename on line 2, this is needed because
[Jekyll][jek] does not use extensions when referring to layouts and it
chooses any file in the `_layout` directory with the correct base
name. With this rule in place I can generate my layout using
[Haml][haml]. Since I was rendering the layout HTML locally I decided
to skip the plugin altogether and generate the CSS with [Sass][sass]
locallly as well. Since this also gives me more control and I can be
sure that the page rendered locally will look exactly the same once
everything is committed. For generating the CSS I use the following rule:

{% highlight ruby linenos %}

rule '.css' => ['.scss'] do |t|
    sh %{ sass -t compressed #{t.source} #{t.name} }
end

{% endhighlight %}

## Generating a tag cloud

Using [Haml][haml] in the layout page opens some interesting
possibilities since we can embed [Ruby][ruby] code inside the
template. I found some [Rake][rake] [snippets][raketag] to generate
tag lists using [Jekyll][jek]'s api. Adapt that code a bit and [Haml][haml]
can generate the tag cloud using [Jekyll][jek]. This in turn gets used as part
of the layout for each post. Isn't that a wonderful self referential
system. Here's the [Haml][haml] code to produce the tag list you see
in the right column.

{% highlight haml linenos %}

%h3 Categories
  %ul
  :ruby
  require 'rubygems'
  require 'jekyll'
  puts "<!--"
  options = Jekyll.configuration({})
  site = Jekyll::Site.new(options)
  site.read_posts('')
  puts "-->"
  site.categories.sort.each do |category, posts|
      print "<li>"
      print "<a href=\"/tags/#{category.gsub(/\s+/,'-')}.html\">"
      print "#{category} (#{posts.length})</a>"
      print "</li>"
  end
{% endhighlight %}

Apparently `site.read_posts` outputs to stdout to avoid it from
clogging up the page it's output gets rendered as an HTML comment
(line 6 and 10).

### Generating pages for posts per tag

Also inspired by [this gist][raketag] I added a [Rake][rake] task to
generate a page for each used tag in the site containing all posts
that refer to the tag. Here's the code:

{% highlight ruby linenos %}

namespace :tags do
  task :clean do 
    rm_rf "tags"
    mkdir "tags"
  end

  task :generate do
    puts 'Generating tags...'
    require 'rubygems'
    require 'jekyll'
    include Jekyll::Filters

    options = Jekyll.configuration({})
    site = Jekyll::Site.new(options)
    site.read_posts('')
    site.categories.sort.each do |category, posts|
      keywords = aggregate_keywords(category, posts)
      html= <<-HTML
---
layout: default
title: Posts tagged #{category}
keywords: [#{keywords}]
---
HTML
      posts.each do |post|
        post_data = post.to_liquid
        html << <<-HTML
<h2><a href="#{post_data['url']}">#{post_data['title']}></a></h2>
#{post_data['content']}
HTML
      end
      File.open("tags/#{category.gsub(/\s+/,'-')}.md", 'w+') do |file|
        file.puts html
      end
    end
  end
end

{% endhighlight %}
To be able to fill the `<meta keywords...` each post puts keywords
appropriate for the post in the [Yaml Front Matter][yfm].
The function `aggregate_keywords` just puts the category at hand
and all the keywords from all posts in one set and returns them as a comma
separated list, like so:

{% highlight ruby linenos %}

def aggregate_keywords(category,posts)
  keywords = SortedSet.new()
  keywords << category
  posts.each do |post|
    post_data = post.to_liquid
    if post_data.has_key? 'keywords' 
      post_data['keywords'].each do |word|
        keywords << word
      end
    end
  end
  return keywords.to_a.join(',')
end

{% endhighlight %}

Next up from my blog setup backlog is a comments facility.
If you'd like to use any of the code quoted above
[fork me on GitHub][me].

{% include date.inc %}

[me]: https://github.com/basbossink/basbossink.github.com "Github Pages repository"
[md]: http://daringfireball.net/projects/markdown/ "Markdown"
[text]: http://www.textism.com/tools/textile/ "Textile"
[yfm]: https://github.com/mojombo/jekyll/wiki/YAML-Front-Matter "YAML front matter"
[sass]: http://sass-lang.com/ "Sass"
[raketag]: https://gist.github.com/143571 "Gist to generate tag cloud using Rake"
[rake]: http://rake.rubyforge.org/ "Rake"
[dlay]: https://github.com/basbossink/basbossink.github.com/blob/master/_layouts/default_haml.haml "Default layout"
[rails]:http://rubyonrails.org/ "Ruby on Rails" 
[haml]: http://haml-lang.com/ "Haml"
[jekp]: https://github.com/mojombo/jekyll/wiki/Plugins "Jekyll Plugins"
[hamlp]: http://blog.martiandesigns.com/2010/07/19/haml-sass-converters-for-jekyll.html "Haml and SASS converters for Jekyll" 
[ruby]: http://www.ruby-lang.org/en/ "Ruby"
[jek]: http://jekyllrb.com/ "Jekyll"
[poch]: http://www.kernel.org/pub/software/scm/git/docs/githooks.html "githooks"
[git]: http://git-scm.com/ "Git"
[gith]: http://github.com/ "GitHub"
[githp]: http://pages.github.com/ "GitHub Pages"


<hr/>
<h2><a href="/2011-01-19/adding-comments/">Adding Comments</a></h2>
{% assign my_date = ' Wed 19 Jan 2011' %}
In [my last post][prev] I hinted that the next feature to be
implemented was a comments facility. Searching through the web I
found two options [Disqus][disq] and [IntenseDebate][inde]. Browsing
through their respective sites, I liked [Disqus][disq] better.
Judging by a few comparisons I found [here][comp1] and [here][comp2],
and the fact that [gitready][gitr] uses [Disqus][disq].
[Disqus][disq] scored best in my comparison. Their registration
process also was a lot less labor intensive. Adding the code to the
site was also trivial. Being a bit overly purist I decided to
translate the code snippet provided by [Disqus][disq] to
[Haml][haml]. Which results in the following:

{% highlight haml linenos %}
{% assign post_id = '{{ post.id }}' %}
{% assign post_url = '{{ post.url}}' %}
%div#disqus_thread
:javascript
  /* * * CONFIGURATION VARIABLES: EDIT BEFORE PASTING INTO YOUR WEBPAGE * * */
  var disqus_shortname = 'basbossink'; // required: replace example with your forum shortname

  // The following are highly recommended additional parameters. Remove the slashes in front to use.
  var disqus_identifier = '{{ post_id }}';
  var disqus_url = 'http://basbossink.github.com{{ post_url }}';

  /* * * DON'T EDIT BELOW THIS LINE * * */
  (function() {
    var dsq = document.createElement('script'); dsq.type = 'text/javascript'; dsq.async = true;
    dsq.src = 'http://' + disqus_shortname + '.disqus.com/embed.js';
    (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(dsq);
  })();
%noscript 
  Please enable JavaScript to view the 
  %a{ :href => "http://disqus.com/?ref_noscript" } 
    comments powered by Disqus.
%a.dsq-brlink{ :href => "http://disqus.com" } 
  blog comments powered by
  %span.logo-disqus 
    Disqus
{% endhighlight %}

This snippet can also be found in the [Git][git] [repository][repo] from which
this blog is generated, [here][dh] to be exact. Now that the basic
infrastructure is in place. It is probably time for some real content.
Until next time.

{% include date.inc %}

[comp1]: http://geeklad.com/disqus-vs-intense-debate "Disqus vs. Intensdebate"
[comp2]: http://spicycauldron.com/2009/07/06/disqus-vs-intensedebate/ "Disqus vs. Intensdebate"
[gitr]: http://gitready.com/ "gitready"
[repo]: https://github.com/basbossink/basbossink.github.com "personal pages"
[dh]: https://github.com/basbossink/basbossink.github.com/raw/master/_includes/disqus.haml "Disqus code in haml syntax"
[git]: http://git-scm.com/ "git"
[haml]: http://haml-lang.com/ "Haml"
[disq]: http://disqus.com/ "Disqus"
[inde]: http://intensedebate.com/ "IntenseDebate"
[prev]: http://basbossink.github.com/2011-01-16/blog-setup/ "Blog setup"

<hr/>
