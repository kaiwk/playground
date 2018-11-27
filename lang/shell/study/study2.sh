#!/bin/bash

# make_page - A script to produce an HTML file

title="System infomation for $HOSTNAME"
right_now=$(date +"%x %r %Z")

cat <<- _EOF_
<html>
    <head>
    <title>
        $title
    </title>
    </head>
    <body>
        <h1>$title</h1>
        <p>Update on $right by $USER</p>
    </body>
</html>
_EOF_
