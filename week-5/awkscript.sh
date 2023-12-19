

awk 'BEGIN { characters=0; words=0; lines=0; }
     { 
       lines++;
       words += NF;
       characters += length($0);
     }
     END {
       print "Number of characters: " characters;
       print "Number of words: " words;
       print "Number of lines: " lines;
     }' anil

