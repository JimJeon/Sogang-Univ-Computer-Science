<?php

// To use Korean
echo("<meta charset='utf-8'>");

// Filename to write down visit count
$filename = "counter.txt";

$myCookie = $_COOKIE['IP'];

$fp = fopen( $filename, "r" );

if(!filesize( $filename ))
    $count = 0;
else
    $count = fread( $fp, filesize( $filename ));
fclose($fp);

if( !isset($myCookie) )
{
    setcookie( "IP",$_SERVER["REMOTE_ADDR"], time() + 60*60*8 );
    $count++;
}
echo ("방문자 수 = ");

$string = (string) $count;
for( $i = 0; $i < strlen( $string ); ++$i )
{
    $ch = substr( $string, $i, 1 );
    echo( "<img src='./res/".$ch.".JPG'>");
}

$fp = fopen( $filename, "w" ) or die("failed to open file");
fwrite( $fp, $count );
fclose($fp);

?>
