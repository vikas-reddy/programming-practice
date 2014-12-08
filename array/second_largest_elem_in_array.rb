#!/usr/bin/ruby
#

arr = []
12.times { arr << rand(100) }

puts "#{arr.inspect}"

a = b = c = d = nil

arr.each do |elem|
  if a == nil || a < elem
    a, b, c, d = elem, a, b, c
  elsif b == nil || b < elem
    b, c, d = elem, b, c
  elsif c == nil || c < elem
    c, d = elem, c
  elsif d == nil || d < elem
    d = elem
  end
end

puts arr.sort.inspect
puts d
