require "bundler/gem_tasks"
require "rspec/core/rake_task"

RSpec::Core::RakeTask.new(:spec)

task :default => :spec

require 'rake/extensiontask'
Rake::ExtensionTask.new('packn') do |t|
  t.name = 'packn'

  t.ext_dir = 'ext/packn'
  t.lib_dir = 'lib'
end
