#!/usr/bin/ruby
#
# Insertion sort in Ruby

def sort(array)
  len = array.length

  (0..(len - 2)).each do |pos|
    # array[0..pos] is always sorted
    # Find the min element in the subarray array[pos+1..len-1]
    # Swap the min element found with array[pos+1]
    # Insert array[pos+1] in the array[0..pos] properly so as to make this subarray sorted

    min_idx = pos
    ((pos + 1)..(len - 1)).each do |i|
      if array[min_idx] > array[i]
        min_idx = i
      end
    end

    array[min_idx], array[pos+1] = array[pos+1], array[min_idx]

    elem = array[pos + 1]
    i = pos
    while i >= 0 && array[i] > array[pos + 1]
      array[i+1] = array[i]
      i = i - 1
    end
    array[i+1] = elem
  end

  array
end

input = []
10.times { input << rand(100) }
puts "input: #{input.inspect}"
output = sort(input)
puts "output    : #{output.inspect}"
puts "input.sort: #{input.sort.inspect}"
