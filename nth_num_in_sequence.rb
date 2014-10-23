#!/usr/bin/ruby
#
# nth number in sequence
# 3, 4, 33, 34, 43, 44, 333, 334, 343, 344, 433, 434, etc.,

def binary(a, b)
  if a == 0
    str = "0"
  else
    str = ""
    n = a
    while n > 0
      str.insert(0, (n%2).to_s)
      n = n/2
    end
  end
  if str.length < b
    str.insert(0, "#{'0' * (b - str.length)}")
  end
  str.gsub!('0', '3')
  str.gsub('1', '4')
end

# input
n = ARGV[0].to_i

unless n > 0
  puts "Invalid input"
  exit 0
end

(1..100).each do |n|
  # b-digit number
  b = Math.log(n + 1, 2).floor
  l = 2 * ( 2**(b-1) - 1 )

  a = n - l - 1

  # b bit binary representation of a
  puts binary(a, b)
end
