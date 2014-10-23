def generate_sequences(a, b, k)
  if k == 0 || a > b
    return []
  end

  arr = []
  i = a
  while i <= b - k + 1
    sequences = generate_sequences(i + 1, b, k - 1)
    if sequences.empty?
      arr << "#{i}"
    else
      arr += sequences.map {|s| "#{i} #{s}"}
    end
    i = i + 1
  end
  arr
end

n = ARGV[0].to_i
k = ARGV[1].to_i

sequences = generate_sequences(1, n, k)
puts sequences.inspect
