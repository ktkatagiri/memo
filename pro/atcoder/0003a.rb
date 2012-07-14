N = STDIN.gets.chomp.to_i
@record = gets.split("")
@has = {
  'A' => 4,
  'B' => 3,
  'C' => 2,
  'D' => 1,
  'F' => 0
}

@sum = 0
N.times { |i|
  @sum += @has[@record[i]]
}

puts @sum.to_f / N.to_f
