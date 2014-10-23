#!/usr/bin/ruby
#

str = "(((ab)"
stack = []

(0...str.length).each do |i|
  char = str[i]
  if char == '('
    stack.push([char, i])
  elsif char == ')'
    if stack.empty?
      stack.push([char, i])
    else
      if stack.last.first == '('
        stack.pop
      end
    end
  end
end

puts stack.inspect

wrong_entries = stack.map {|elem| elem[1]}

(0...str.length).each do |i|
  unless wrong_entries.include?(i)
    printf "%c", str[i]
  end
end
printf "\n"
