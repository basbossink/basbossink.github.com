require 'rake/clean'

CLEAN.include('_layouts/*.html')
CLEAN.include('css/*.css')
CLEAN.include('tags/*.*')
CLOBBER.include('_site')

LAYOUT_SRC = FileList['**/*.haml']
LAYOUT_HTML = LAYOUT_SRC.ext('html')
CSS_SRC = FileList['css/*.scss']
CSS = CSS_SRC.ext('css')
LAYOUT = LAYOUT_HTML + CSS

rule '.html' => ['.haml'] do |t|
    sh %{ haml -E utf-8 #{t.source} #{t.name} }
end

rule '.css' => ['.scss'] do |t|
    sh %{ sass -t compressed #{t.source} #{t.name} }
end


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
      html= <<-HTML
---
layout: default
title: Posts tagged #{category}
---
HTML
      posts.each do |post|
        post_data = post.to_liquid
        html << <<-HTML
<h2><a href="#{post_data['url']}">#{post_data['title']}</a></h2>
{% assign my_date = ' #{post_data['date'].strftime("%a %d %b %Y")}' %}
#{post_data['content']}
HTML
      end
      File.open("tags/#{category.gsub(/\s+/,'-')}.md", 'w+') do |file|
        file.puts html
      end
    end
  end
end

desc 'Generate html and css from sources'
task :build => LAYOUT do
end

desc 'commpress html'
task :shrink => :build do
  FileList['_layouts/default.html'].each do |file|
    sh %{ java -jar c:/Users/bas/programs/htmlcompressor/htmlcompressor-0.9.8.jar --remove-intertag-spaces --remove-quotes #{file} -o #{file}}
  end
end

desc 'Build and start server'
task :server => :build do
  sh %{ jekyll --server }
end

desc "Create per tag pages and rest"
task :default => [:build, "tags:generate"]











