#!/usr/bin/ruby
#

def first_max(arr, a)
  len = arr.length

  return arr if a >= len

  last = arr[len - 1]
  i = len - 2
  while i >= a
    arr[i+1] = arr[i]
    i -= 1
  end
  arr[a] = last;

  first_max(arr, a+2)
end

arr = []
9.times { arr << rand(100) }
arr.sort!

puts arr.inspect
puts first_max(arr, 0).inspect
