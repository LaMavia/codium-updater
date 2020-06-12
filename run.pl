#!/usr/bin/perl
use warnings;
use strict;
my $err = system "sudo apt-get update";
die $! if $err;

my $url = `node src/main.bs.js`;
my $download_dir = "/tmp/codium-updater";
my $download_location = "$download_dir/rel.deb";
mkdir $download_dir;
$err = system "wget -O $download_location $url";
die $! if $err;

$err = system "sudo apt-get install $download_location";
die $! if $err;

rmdir $download_dir;