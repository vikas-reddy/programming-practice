
class Dialpad
  attr_reader :arr
  def initialize
    @arr = [
      [],
      [],
      ['a', 'b', 'c'],
      ['d', 'e', 'f'],
      ['g', 'h', 'i'],
      ['j', 'k', 'l'],
      ['m', 'n', 'o'],
      ['p', 'q', 'r', 's'],
      ['t', 'u', 'v'],
      ['w', 'x', 'y', 'z']
    ]
  end

  def words(n)
    return [] if n % 10 == 0

    digit = n % 10
    res = []

    if n/10 == 0
      res = arr[digit].dup
    else

      prefixes = words(n/10)

      prefixes.each do |prefix|
        (0...(arr[digit].length)).each do |i|
          res << "#{prefix}#{arr[digit][i]}"
        end
      end
    end
    res
  end
end

num = ARGV[0].to_i
d = Dialpad.new
puts d.words(num).inspect
