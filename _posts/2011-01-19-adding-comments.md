---
layout: post
published: true
categories: 
- Jekyll
keywords:
- Disqus
- comments
- Haml 
--- 
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

{% assign post_id = '{{ post.id }}' %}
{% assign post_url = '{{ post.url}}' %}

<script type="syntaxhighlighter" class="brush: plain">
<![CDATA[

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
]]>
</script>
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
