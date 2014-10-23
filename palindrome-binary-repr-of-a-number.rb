#!/usr/bin/ruby
#
# Is the binary representation of the number a palindrome?

def palindrome?(str)
  i = 0
  while i < str.length/2
    if str[i] != str[str.length - i - 1]
      return false
    end
    i = i + 1
  end
  return true
end

num = ARGV[0].to_i
bin = ""
lsd_found = false

k = num
while k > 0
  if !lsd_found
    lsd_found = (k % 2 == 1)
    next if lsd_found
  else
    bin.insert(0, (k % 2).to_s)
  end
  k = k/2
end

puts palindrome?(bin).inspect
