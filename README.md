# mruby-pivot_root   [![Build Status](https://travis-ci.org/udzura/mruby-pivot_root.svg?branch=master)](https://travis-ci.org/udzura/mruby-pivot_root)
PivotRoot class
## install by mrbgems
- add conf.gem line to `build_config.rb`

```ruby
MRuby::Build.new do |conf|

    # ... (snip) ...

    conf.gem :github => 'udzura/mruby-pivot_root'
end
```
## example
```ruby
p PivotRoot.hi
#=> "hi!!"
t = PivotRoot.new "hello"
p t.hello
#=> "hello"
p t.bye
#=> "hello bye"
```

## License
under the MIT License:
- see LICENSE file
