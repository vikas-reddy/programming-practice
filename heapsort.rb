#!/bin/ruby
#
class Heap
  attr_reader :array

  def initialize(array)
    @array = array
    @heap_size = @array.length
  end

  def sort!
    build_heap
    # and then sort it
    (@array.length - 1).downto(1) do |i|
      @array[i], @array[0] = @array[0], @array[i]
      @heap_size -= 1
      heapfiy(0)
    end
  end

  # Builds a heap in-place
  def build_heap
    (@heap_size/2 - 1).downto(0) do |i|
      heapfiy(i)
      i -= 1
    end
  end

  # Heapifies the subtree rooted at i
  def heapfiy(i)
    l, r = lchild(i), rchild(i)

    if l < @heap_size && @array[i] < @array[l]
      largest = l
    else
      largest = i
    end

    if r < @heap_size && @array[largest] < @array[r]
      largest = r
    end

    unless largest == i
      @array[i], @array[largest] = @array[largest], @array[i]
      heapfiy(largest)
    end
  end

  private
  def parent(i); i/2 ;    end
  def rchild(i); 2*i + 2; end
  def lchild(i); 2*i + 1; end
end

# main()

# Verification
# 1000.times do
#   array = 50.times.map { rand(10000) }
#   heap = Heap.new(array)
#   heap.sort!
#   puts heap.array unless heap.array == array.sort
# end
# exit

array = 20.times.map { rand(1000) }
puts "Input: #{array.inspect}"

heap = Heap.new(array)
heap.sort!

puts "Output: #{heap.array.inspect}"
puts "Ruby's: #{array.sort.inspect}"
