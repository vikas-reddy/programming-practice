# Mobile Numeric Keypad
#
# 1 2 3
# 4 5 6
# 7 8 9
#   0
#

class Keypad
  attr_reader :arr, :rows, :cols, :mr, :mc
  def initialize
    @arr = [
      [1,   2, 3],
      [4,   5, 6],
      [7,   8, 9],
      [nil, 0, nil]
    ]
    @rows = 4
    @cols = 3
    @mr = [0, 0, -1, 0, 1]
    @mc = [0, -1, 0, 1, 0]
  end

  def traverse(row, col, n)
    return 0 if n <= 0
    return 1 if n == 1

    count = 0
    (0..4).each do |i|
      x = row + mr[i]
      y = col + mc[i]
      if x >= 0 && y >= 0 && x < rows && y < cols && arr[x][y] != nil
        count += traverse(row + mr[i], col + mc[i], n - 1)
        printf arr[x][y].to_s
      end
    end
    return count

    printf arr[row][col].to_s

    traverse(row, col, n - 1) +
    traverse(row, col - 1, n - 1) +
    traverse(row - 1, col, n - 1) +
    traverse(row, col + 1, n - 1) +
    traverse(row + 1, col, n - 1)
  end

  def num_paths(n)
    return nil unless n > 0

    count = 0

    (0...rows).each do |row|
      (0...cols).each do |col|
        unless arr[row][col].nil?
          count += traverse(row, col, n)
          printf "\n"
        end
      end
    end
    count
  end
end

N = ARGV[0].to_i
keypad = Keypad.new
puts keypad.num_paths(N)
