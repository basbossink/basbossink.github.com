+++
date = "2011-11-19"
title = "PS for .NET devs part 3: List Targets in your MSBuild file"
+++ 

The project I'm currently working on, started more than five years ago
and has quite a large [MSBuild][msb] file to perform all the build
automation for the project. A while back I found myself struggling to
remember the name of a specific build [`Target`][tar] that I don't use
very often. Since such a large XML file is not as readable as one
would hope I couldn't find what I was looking for fast enough. Since I
know [PowerShell][1] has good XML support I opened the
[PowerShell Integrated Scripting environment][ise] and experimented a
bit to see how hard it would be to list all the [`Target`][tar]s in
the [MSBuild][msb] file using [PowerShell][1]. 

To give you an idea what an [MSBuild][msb] file looks like here is a
little snippet from the [OpenWrap][ow] source: 

~~~ xml

<?xml version="1.0" encoding="utf-8" ?>
<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003" DefaultTargets="OpenWrap-Package" ToolsVersion="3.5">
  <PropertyGroup>
    <Root>$(MSBuildProjectDirectory)\..</Root>
    <Configuration Condition="'$(Configuration)' == ''">Debug</Configuration>
    <PackageName Condition="'$(PackageName)' == ''">OpenWrap</PackageName>
    <OpenWrap-DescriptorPath Condition="'$(OpenWrap-DescriptorPath)' == ''">$(Root)\$(PackageName).wrapdesc</OpenWrap-DescriptorPath>
    <OpenWrap-BuildTasksDirectory Condition="'$(OpenWrap-BuildTasksDirectory)' == ''">$(Root)\wraps\openwrap\build</OpenWrap-BuildTasksDirectory>
  </PropertyGroup>
  
  <ItemGroup> 
    <WrapBinary Include="$(Root)\src\**\*.csproj" />
  </ItemGroup>
  <Target Name="Clean">
    <Delete Files="$(Root)\scratch\build\**\*.*" ContinueOnError="true" />
    <Delete Files="$(Root)\scratch\package\**\*.*" ContinueOnError="true" />
    <RemoveDir Directories="$(Root)\scratch\build" ContinueOnError="true" />
    <RemoveDir Directories="$(Root)\scratch\package" ContinueOnError="true" />
  </Target>
  <!-- lots of lines deleted-->
</Project>

~~~


What's so great about [PowerShell][1]'s XML support? No fiddling
around with namespaces, the element tree can be walked using the `.`
(aka the property dereferencing operator). So to get all
[`Target`][tar] elements from the [MSBuild][msb] file you can use:

~~~ ps1
$build = [xml](Get-Content openwrap.proj)
$build.Project.Target
~~~


Using `Get-Member` you see that the `Target` objects have a `Name`
property.

![Viewing the Name property](ShowMSBuildTargetName.png)

One obvious thing to try would be

~~~ ps1
$build = [xml](Get-Content openwrap.proj)
$build.Project.Target.Name
~~~


But that gives no output, this is caused by the fact that `Name` is an
attribute. Using `Select-Object` however works perfectly.
The total script becomes:

~~~ ps1
$build = [xml](Get-Content openwrap.proj)
$build.Project.Target| Select-Object Name | Sort-Object Name
~~~


This could be put on 1 line to uphold the slogan,
["Automating the world one-liner at a time..."][pstb] but I find this
to be a little more readable.

This script took me 5 minutes to write and has already payed itself
back dozens of times when I need to find the name of the target that I
wish to run. That's all for now, next time will take a look at how you
can get an overview of your code-base using a few simple
[PowerShell][1] commands.

##### References

- [Scripting with Windows PowerShell](http://technet.microsoft.com/en-us/scriptcenter/dd742419)
- [MSBuild Overview](http://msdn.microsoft.com/en-us/library/ms171452(v=vs.90).aspx) 
- [PowerShell ISE](http://technet.microsoft.com/en-us/library/dd315244.aspx)
- [MSBuild Targets](http://msdn.microsoft.com/en-us/library/ms171462(v=VS.100).aspx)
- [OpenWrap](http://www.openwrap.org/)
- [Windows PowerShell Blog](http://blogs.msdn.com/b/powershell/)

[1]: http://technet.microsoft.com/en-us/scriptcenter/dd742419 "Scripting with Windows PowerShell"
[msb]: http://msdn.microsoft.com/en-us/library/ms171452(v=vs.90).aspx "MSBuild Overview"
[ise]: http://technet.microsoft.com/en-us/library/dd315244.aspx "PowerShell ISE"
[tar]: http://msdn.microsoft.com/en-us/library/ms171462(v=VS.100).aspx "MSBuild Targets"
[ow]: http://www.openwrap.org/ "OpenWrap" 
[pstb]: http://blogs.msdn.com/b/powershell/ "Windows PowerShell Blog"



