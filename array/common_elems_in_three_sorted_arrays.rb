#!/usr/bin/ruby
#

def generate_array
  arr = []
  5.times { arr << rand(5) }
  arr.uniq.sort
end
a = generate_array
b = generate_array
c = generate_array

# All pointers start at 0
pa = pb = pc = 0

puts "a: #{a.inspect}"
puts "b: #{b.inspect}"
puts "c: #{c.inspect}"
while pa < a.size && pb < b.size && pc < c.size
  if a[pa] == b[pb]
    if a[pa] == c[pc]
      puts a[pa]
      pa += 1
      pb += 1
      pc += 1
    else
      if a[pa] > c[pc]
        pc += 1
      else
        pa += 1
        pb += 1
      end
    end
  else
    if a[pa] == c[pc]
      if b[pb] < a[pa]
        pb += 1
      else
        pa += 1
        pc += 1
      end
    else
      min = [a[pa], b[pb], c[pc]].min
      case min
      when a[pa] then pa += 1
      when b[pb] then pb += 1
      when c[pc] then pc += 1
      end
    end
  end
  # puts "pa: #{pa.inspect}, pb: #{pb.inspect}, pc: #{pc.inspect}"
end
