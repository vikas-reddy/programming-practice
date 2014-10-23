#!/usr/bin/ruby
#

n = ARGV[0].to_i

a = Math.sqrt(n).floor

if a == Math.sqrt(n)
  puts n
else
  if (n - a**2) < ((a+1)**2 - n)
    puts a**2
  else
    puts (a+1)**2
  end
end
