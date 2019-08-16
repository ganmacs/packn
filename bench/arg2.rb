require 'benchmark/ips'
require 'packn'

Benchmark.ips do |x|
  x.report('String#pack') do
    [1, 2].pack('NN')
  end

  x.report('BigEndian4.pack2') do
    Packn::BigEndian4.pack2(1, 2)
  end
end
