#!/usr/bin/ruby
#
# in O(n)
# counting sort takes O(n+2)
#
arr = []
10.times { arr << rand(100) - 50 }

puts arr.inspect

i = 0
j = arr.size - 1
while i < arr.size && j >= 0 && i <= j
  while arr[i] < 0
    i = i + 1
  end
  while arr[j] >= 0
    j = j - 1
  end
  if i < j
    arr[i], arr[j] = arr[j], arr[i]
  end
end
puts arr.inspect
