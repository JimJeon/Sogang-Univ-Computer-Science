<?php

$filename = "Data.txt";

echo("
<!DOCTYPE html>
<html>
<body>
<textarea name='message' rows=20 cols=120 readonly>");

$fp = fopen($filename, "r") or die("file open error");
$message = fread($fp, filesize($filename));
fclose($fp);

echo $message;
echo("</textarea>");
echo("<a href='./Board_main.php'>back</a>");
echo("</body></html>");

?>
