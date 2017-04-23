<?php
##########################################################################################
# 
# OBJETIVO:
# =========
#
# Interactual directamente con la consola.
#
# Parametros:
# ===========
# -mensaje
#
# Desarrollo:
# 
# - Jose Andres Ceciliano Granados
#
#
#########################################################################################
	$host    = "localhost";
	$port    = 1500;
	if (isset($_POST['mensaje'])){		
		$message = $_POST['mensaje'];
	}else{
		$message = $_GET['mensaje'];
	}
	$socket = socket_create(AF_INET, SOCK_STREAM, 0) or die("Could not create socket\n");
	$result = socket_connect($socket, $host, $port) or die("Could not connect to server\n");  
	if($result) { 
		socket_write($socket, $message, strlen($message)) or die("Could not send data to server\n");
		$result = socket_read ($socket, 2048) or die("Could not read server response\n");
	}
	echo $result;
	//socket_close($socket);
?>