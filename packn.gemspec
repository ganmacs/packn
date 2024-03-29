
lib = File.expand_path("../lib", __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require "packn/version"

Gem::Specification.new do |spec|
  spec.name          = "packn"
  spec.version       = Packn::VERSION
  spec.authors       = ["Yuta Iwama"]
  spec.email         = ["ganmacs@gmail.com"]

  spec.summary       = "pack/unapcker"
  spec.description   = "unpacker/pack"
  spec.homepage      = "https://github.com/ganmacs/packn"

  # Specify which files should be added to the gem when it is released.
  # The `git ls-files -z` loads the files in the RubyGem that have been added into git.
  spec.files         = Dir.chdir(File.expand_path('..', __FILE__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]

  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "bundler"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rspec"
  spec.add_development_dependency "benchmark-ips"
end
