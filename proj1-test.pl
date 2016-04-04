#!/usr/bin/perl -w

# Perl script for testing CSCE 531 proj1 submissions (declarations)

# Usage (can be run in any working directory):
# $ proj1-test.pl --self-test

# Writes to file "comments.txt" in your project directory
# ($project_directory, defined below)

# This script must be run under the bash shell!

# edit as needed

# This project directory (below) should be the common parent of two
# subdirectories:
#     proj1 -- contains the source files of your submission
#     proj1test -- contains the test files T1L*.c
# The script will run "make" in the proj1 subdirectory, then run the resulting
# executable on files in the proj1test subdirectory, putting the output files
# in the proj1 (source) directory, which it then compares with the same output
# files in the proj1test subdirectory. Comments are placed in the project
# directory in the file "comments.txt".
#
# The project directory should be an ABSOLUTE path name
# ($ENV{HOME} expands to your home directory). It is currently set
# to the place where I keep the test files in my own account.
$project_directory = "$ENV{HOME}/public_html/csce531/handouts";
$semester = 'sp16';

# This default bison message varies by system or configuration
# On CSE Linux systems in the labs
# $bison_parse_error_msg = "syntax error";
# On my Mac
# $bison_parse_error_msg = "parse error";

############ You should not have to edit below this line ##############

$project_installment = 1;
$hw_dir = "proj$project_installment";
$test_suite_dir = "$project_directory/${hw_dir}test";
$submission_root = "$ENV{HOME}/courses/csce531/$semester/proj1/submissions";
$test_file_prefix = "T${project_installment}L";
$timeout = 11;			# seconds
$prog_name = 'pcc3';

# Hash to hold the test results
%error_counts = ();
%strip_error_counts = ();

# Check existence of project directory
die "No project directory $project_directory\n"
    unless -d $project_directory;

# Check existence of source code directory
die "No executable directory $project_directory/$hw_dir\n"
    unless -d "$project_directory/$hw_dir";

# Check existence of test suite directory
die "No test suite directory $test_suite_dir\n"
    unless -d $test_suite_dir;

#sub main
{
    $project_directory =~ /^\//
	or die "Project dir pathname $project_directory is not absolute\n";

    # Get C source test files
    opendir DIR, $test_suite_dir;
    my @filenames = readdir DIR;
    my @testfilenames = ();
    while (@filenames) {
        $name = shift @filenames;
	next if $name !~ /^($test_file_prefix.*)\.c$/;
	push @testfilenames, ($1);
    }

    # Typical element is $test_file_hash{$level}->{$ok_or_err} = $base
    %test_file_hash = ();

    foreach $base (@testfilenames) {
	$base =~ /^$test_file_prefix(\d+[^_]*)_(err|ok)$/;
	$test_file_hash{$1}{$2} = $&;
    }

    if (@ARGV && $ARGV[0] eq '--self-test') {
	$uname = 'self-test';
	process_user();
    }
    elsif (@ARGV) {
	while (@ARGV) {
	    $uname = shift @ARGV;
	    process_user();
	}
    }
    else {
	opendir DIR, $submission_root
	    or die "Cannot open submission directory $submission_root ($!)\n";
	@usernames = readdir DIR;
	closedir DIR;

	while (@usernames) {
	    $uname = shift @usernames;
	    next if $uname =~ /^\./;
	    next unless -d "$submission_root/$uname";
	    process_user();
	}
    }
}


sub process_user {
    print(STDERR "Processing $uname/$hw_dir\n\n");
    if ($uname eq 'self-test') {
	$udir = "$project_directory";
    }
    else {
	$udir = "$submission_root/$uname";
    }
    die "No subdirectory corresponding to $uname ($!)\n"
	unless -d $udir;

    open(COMMENTS, "> $udir/comments.txt");

    cmt("Comments for $uname -------- " . now() . "\n");

    chdir $udir;

    if (!(-d $hw_dir)) {
	cmt("  No $hw_dir subdirectory found\n");
	close COMMENTS;
	return;
    }

    chdir $hw_dir
	or die "Cannot change to $udir/$hw_dir directory ($!)\n";

    # try make clean, regardless of what happens
    system("make", "clean");

    opendir DIR, "$udir/$hw_dir"
	or die "Cannot open $udir/$hw_dir directory ($!)\n";
    @filenames = readdir DIR;
    closedir DIR;
    $count = 0;
    while (@filenames) {
	$filename = shift @filenames;
	chomp $filename;
	next if $filename =~ /^\./;
	if ($filename =~ /^lex\.yy|^y\.tab|\.o$|^parse\.c$|^scan\.c$|^ppc3$/) {
	    cmt("Removing illegal file: $filename\n");
	    unlink $filename;
	    $count++;
	}
    }
    cmt("No illegal files found\n")
	if $count == 0;

    test_prog($prog_name);

    report_summary();

    close COMMENTS;

    # try cleaning -- don't care what happens
    system("make", "clean");

    if ($uname eq 'self-test') {
	print(STDERR "\nDone.\nComments are in comments.txt\n");
    }
    else {
	print(STDERR "\nDone.\nComments are in $uname/comments.txt\n");
    }
}


sub test_prog {
    my ($prog) = @_;

    print(STDERR "Errors msgs for $uname/$prog:\n");
    print(STDOUT "System msgs for $uname/$prog:\n");

    cmt("Testing $prog:\n");

    $error_counts{$prog} = 0;
    $strip_error_counts{$prog} = 0;

    $rc = test_make($prog);

    if (!$rc) { # if couldn't make original prog
	cmt("$prog FAILED TO BUILD\n");
	$error_counts{$prog}++;
	return;
    }

    foreach $level (sort by_extracted_number (keys(%test_file_hash))) {

	cmt("\n\nLEVEL $level:\n\n");

	foreach $key (sort { $b cmp $a; } (keys(%{$test_file_hash{$level}}))) {

	    $base = $test_file_hash{$level}{$key};

	    -e "$test_suite_dir/$base.c" || die "$base.c does not exist ($!)\n";
	    cmt("Running $prog with input $base.c ...");
	    print(STDERR "----$base.c:\n");
	    $testFile = "$test_suite_dir/$base.c";
	    unlink "$base.s"
		if -e "$base.s";
	    unlink "$base.err"
		if -e "$base.err";
	    $error_counts{$base} = 0;
	    eval {
		local $SIG{ALRM} = sub { die "TIMED OUT\n" };
		alarm $timeout;
		$rc = system("./$prog < $testFile > $base.s 2> $base.err");
		alarm 0;
	    };
	    if ($@ && $@ eq "TIMED OUT\n") {
		cmt(" $@");		# program timed out before finishing
		$error_counts{$base}++;
		next;
	    }
	    elsif ($rc >> 8) {
		cmt(" nonzero termination status\n");
	    }
	    else {
		cmt(" zero termination status\n");
	    }

	    # Test error file in any case; contains the symbol table dump
	    if (!(-e "$base.err")) {
		cmt("  ERROR MESSAGE FILE $base.err DOES NOT EXIST\n");
		$error_counts{$base}++;
	    }
	    else {
		cmt("  $base.err exists\n  Comparing with solution file ...");
		if ($base =~ /_ok$/) {
		    $report = `diff $base.err $test_suite_dir/$base.err`;
		    chomp $report;
		    if ($report eq '') {
			cmt(" files match\n");
		    }
		    else {
			cmt(" FILES DIFFER:\nvvvvv\n$report\n^^^^^\n");
			$error_counts{$base}++;
		    }
		}
		else {
		    # Test source file has errors. Compare error messages
		    # only, ignoring the symbol table dump
		    $user_src = `cat $base.err`;
		    if ($user_src =~ /\n\n        Dump: Id  = /s) {
			$user_src = $`;
		    }
		    else {
			cmt(" NO SYMBOL TABLE DUMP\n");
			$error_counts{$base}++;
			next;
		    }
		    $test_src = `cat $test_suite_dir/$base.err`;
		    if ($test_src =~ /\n\n        Dump: Id  = /s) {
			$test_src = $`;
		    }
		    else {
			cmt(" NO SYMBOL TABLE DUMP???\n");
			next;
		    }
		    cmt(" Comparing error messages:\n");
		    cmt("-----Yours:-----\n$user_src");
		    cmt("-----Mine:------\n$test_src");
		    cmt("================\n");
		}
	    }

	    # Ignore assembly output if test file has errors
	    next if ($base =~ /_err$/);

	    if (!(-e "$base.s")) {
		cmt("  OUTPUT FILE $base.s DOES NOT EXIST\n");
		$error_counts{$base}++;
		next;
	    }

	    cmt("  $base.s exists\n  Comparing with solution file ...");
	    $report = `diff $base.s $test_suite_dir/$base.s`;
	    chomp $report;
	    if ($report eq '') {
		cmt(" files match\n");
		next;
	    }
	    cmt(" FILES DIFFER:\nvvvvv\n$report\n^^^^^\n");
	    $error_counts{$base}++;
	}
    }
}


# Tries to make the given executable program.  Returns true iff success
sub test_make {
    my ($prog) = @_;
    my $execFile = "$prog";

    cmt("  Attempting to build $prog ...");
    $rc = system("make", "-B", $prog);
    if ($rc >> 8) {
	cmt(" make -B $prog FAILED\n");
	return 0;
    }

    if (!(-e $execFile)) {
	cmt(" $prog EXECUTABLE DOES NOT EXIST\n");
	return 0;
    }

    cmt(" ok\n");
    return 1;
}


sub report_summary {
    cmt("######################################################\n");
    cmt("Summary for $uname:\n");

    foreach $base (sort by_second_extracted_number (keys %error_counts)) {
	cmt("  $base: ");
	$cnt = $error_counts{$base};
	if ($cnt > 0) {
	    cmt(" $cnt PROBLEM(S) FOUND");
	}
	elsif ($base !~ /_err$/) {
	    cmt(" ok");
	}
	else {
	    cmt(" error message(s) (will check appropriateness by hand)");
	}
	cmt("\n");
    }
    cmt("######################################################\n");
    cmt(" 80% level: (supplied by hand)\n");
    cmt(" 90% level: (supplied by hand)\n");
    cmt("100% level: (supplied by hand)\n");
}


sub cmt {
    my ($str) = @_;
#  print $str;
    print(COMMENTS $str);
}


sub now {
    my $ret;

    my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime;
    $ret = ('Sun','Mon','Tue','Wed','Thu','Fri','Sat')[$wday];
    $ret .= " ";
    $ret .= ('Jan','Feb','Mar','Apr','May','Jun','Jul',
	     'Aug','Sep','Oct','Nov','Dec')[$mon];
    $ret .= " $mday, ";
    $ret .= $year + 1900;
    $ret .= " at ${hour}:${min}:${sec} ";
    if ( $isdst ) {
	$ret .= "EDT";
    } else {
	$ret .= "EST";
    }
    return $ret;    
}


sub by_extracted_number
{
    my ($n1,$n2);
    $a =~ /^\d+/;
    $n1 = $&;
    $b =~ /^\d+/;
    $n2 = $&;
    $n1 <=> $n2;
}



sub by_second_extracted_number
{
    my ($n1,$n2);
    if ($a =~ /^[^0-9]+\d+[^0-9]+(\d+)/) {
	$n1 = $1;
    }
    else {
	$n1 = 1000000;
    }
    if ($b =~ /^[^0-9]+\d+[^0-9]+(\d+)/) {
	$n2 = $1;
    }
    else {
	$n2 = 1000000;
    }
    $n1 <=> $n2;
}
