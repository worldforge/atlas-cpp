#!/usr/bin/perl -w

@files = `find src -type f -name '*.cc'`;
foreach $cfile (@files) {
	chop($cfile);
	$newname = $cfile;
	$newname =~ s/\.cc$/\.cpp/;
	print("Renaming ",$cfile, " to ", $newname , "...\n");
	rename($cfile, $newname);
}
