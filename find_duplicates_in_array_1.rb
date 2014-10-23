#!/usr/bin/ruby
#
# {1, 2, 3, 1, 3, 6, 6} -> {1, 3, 6}
#

arr = []
10.times { arr << rand(10) }
# arr = [ 1, 2, 3, 1, 3, 6, 6 ]

puts "arr: #{arr.inspect}"

i = 0
while i < arr.size
  # puts "arr[i]: #{arr[i]}; i: #{i}"
  # puts arr.inspect
  if arr[i] == i || arr[i] == arr[arr[i]]
    i += 1
  else
    temp = arr[i]
    arr[i] = arr[temp]
    arr[temp] = temp
  end
end

puts "arr: #{arr.inspect}"

duplicates = []
arr.each_with_index do |elem, i|
  duplicates << arr[i] if arr[i] != i
end

puts "duplicates: #{duplicates.compact}"
