require 'rake/clean'

task :default => :build

CLEAN.include('_layouts/*.html')
CLEAN.include('css/*.css')
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
