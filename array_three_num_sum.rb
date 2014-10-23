#!/usr/bin/ruby
#

def check(arr, num)
  i = 0
  while i < arr.length
    if arr[i] >= num
      i = i + 1
      next
    end

    j = i + 1
    while j < arr.length
      if arr[j] >= num
        j = j + 1
        next
      end

      if arr[i] + arr[j] == num
        return true
      end
      j = j + 1
    end
    i = i + 1
  end
  return false
end

def check2(arr, num)
  i = 0
  while i < arr.length
    if arr[i] >= num
      i = i + 1
      next
    end

    if check(arr - Array(arr[i]), num - arr[i])
      return true
    end
    i = i + 1
  end
  return false
end

arr = [3, 1, 5, 4, 2]
num = ARGV[0].to_i

puts check2(arr, num)
