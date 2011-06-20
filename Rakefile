require 'rake/clean'

LAYOUT_SRC = FileList.new('_includes/*.haml','_layouts/*.haml', 'index.haml')
LAYOUT_HTML = LAYOUT_SRC.ext('html')
SCSS = FileList.new('css/*.scss')
CSS = SCSS.ext('css')
LAYOUT = LAYOUT_HTML + CSS

CLOBBER.include('_site')
CLEAN.include('tags/*.*')
CLEAN.include(LAYOUT)
CLEAN.include('css/combined.css')

rule '.html' => ['.haml'] do |t|
    sh %{ haml -E utf-8 #{t.source} #{t.name.sub(/_haml\./,'.')} }
end

rule '.css' => ['.scss'] do |t|
    sh %{ sass -t compressed #{t.source} #{t.name} }
end

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

def concatenate_files(output_filename, input_files)
  File.open(output_filename, "a+") do |out|
    out.puts input_files.map{ |s| IO.read(s)}
  end
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
<h2><a href="#{post_data['url']}">#{post_data['title']}</a></h2>
{% assign my_date = ' #{post_data['date'].strftime("%a %d %b %Y")}' %}
#{post_data['content']}
#{'<hr/>' unless post == posts.last}
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
  sh %{ jekyll --no-server --no-auto --safe }
  FileList['_site/**/*.html'].each do |file|
    sh %{ java -jar c:/Users/bas/programs/htmlcompressor/htmlcompressor-0.9.8.jar --remove-intertag-spaces --remove-quotes #{file} -o #{file}}
  end
end

desc 'commpress html'
task :shrink => :build do
  FileList['_layouts/default.html'].each do |file|
    sh %{ java -jar c:/Users/bas/programs/htmlcompressor/htmlcompressor-0.9.8.jar --remove-intertag-spaces --remove-quotes #{file} -o #{file}}
  end
  rm_rf 'css/combined.css'
  concatenate_files("css/combined.css",FileList['css/*.css'])
  sh %{ java -jar C:/Users/bas/programs/yuicompressor-2.4.6/build/yuicompressor-2.4.6.jar css/combined.css -o _site/css/combined.css }
end

desc 'Build and start server'
task :server => :default do
  sh %{ jekyll --server --safe }
end

desc "Create per tag pages and rest"
task :default => [:shrink, "tags:generate"]











