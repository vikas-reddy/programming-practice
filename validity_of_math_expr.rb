#!/usr/bin/ruby
#

str = "(a+b)(a*b)"

unary_operands = %w(+ -)
binary_operands = %w(+ - * / %)

stack = []

(0...str.length).each do |i|
  char = str[i]

  case char
  when unary_operands.include?(char) || binary_operands.include?(char)
  when '('
    stack.push(char)
  when ')'
    if stack.any? && stack.last == '('
      stack.pop
    else
      stack.push(char)
    end
  when ' '
    // d o nothing
  when /[a-zA-z]/
    stack.push(char)
  end
end

puts stack.inspect
