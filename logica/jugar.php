<?php
	$host    = "localhost";
	$port    = 1500;
	if (isset($_POST['i'])){		
		$i = $_POST['i'];
		$j = $_POST['j'];
	}else{
		$i = $_GET['i'];
		$j = $_GET['j'];
	}
	
	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("<script>window.location='index.php'</script>");
	socket_write($socket, 3, strlen(3))or die("<script>window.location='index.php'</script>");
	$result = socket_read ($socket, 2048) or die("<script>window.location='index.php'</script>");

	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("ERROR");
	socket_write($socket, $i, strlen($i)) or die("ERROR");
	$result = socket_read ($socket, 2048) or die("ERROR");
	
	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("ERROR");
	$result = socket_connect($socket, $host, $port) or die("ERROR");
	socket_write($socket, $j, strlen($j)) or die("ERROR");	
	$result = socket_read ($socket, 2048) or die("ERROR");

	echo $result;
?>