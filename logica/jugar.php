<?php

	$host    = "localhost";
	$port 	 = 1500;

	$socket = socket_create(AF_INET, SOCK_STREAM, 0);
	$result = socket_connect($socket, $host, $port);  

	
	socket_write($socket, "AAAA", strlen("AAAA"));
	$result = socket_read ($socket, 2048);
?>
