<?php

$filename = "Data.txt";
$message = "";

if (empty($_POST["message"]))
    $message = "";
else
    $message = input($_POST["message"]);

function input($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}

echo("
<!DOCTYPE html>
<html>
<form method='post' action=");
echo htmlspecialchars($_SERVER["PHP_SELF"]);
echo(">
    <textarea name='message' rows='20' cols='120'>");

echo $message;
echo("</textarea>");
echo("<a href='./Board_main.php'>back</a><br>");
echo("<input type='submit' name='submin' value='Submit'>");
echo("</form></body></html>");

$fp = fopen( $filename, "w" ) or die("file open error");
fwrite( $fp, $message );

fclose($fp);

?>
