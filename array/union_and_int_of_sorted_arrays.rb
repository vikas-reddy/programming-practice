
# They're sets. So, don't worry about duplicates
def next_of(arr, i)
  j = i
  while arr[i] == arr[j] && j < arr.size
    j = j + 1
  end
  j
end

a1 = []; 2.times { a1 << rand(10) }; a1.sort!
a2 = []; 10.times { a2 << rand(10) }; a2.sort!

puts a1.inspect
puts a2.inspect

a3 = [] # union
a4 = [] # intersection

i = 0
j = 0
while i < a1.size && j < a2.size
  if a1[i] == a2[j]
    a3 << a1[i]
    a4 << a1[i]
    i = next_of(a1, i)
    j = next_of(a2, j)
  elsif a1[i] < a2[j]
    a3 << a1[i]
    i = next_of(a1, i)
  else
    a3 << a2[j]
    j = next_of(a2, j)
  end
end

if i < a1.size
  while i < a1.size
    a3 << a1[i]
    i = next_of(a1, i)
  end
else
  while j < a2.size
    a3 << a2[j]
    j = next_of(a2, j)
  end
end

puts a3.inspect
puts a4.inspect
