#!/usr/bin/perl -w

@files = `find src -type f -name '*.cpp'`;
foreach $cfile (@files) {
	chop($cfile);
	$newname = $cfile;
	$newname =~ s/\.cpp$/\.cc/;
	print("Renaming ",$cfile, " to ", $newname , "...\n");
	rename($cfile, $newname);
}
