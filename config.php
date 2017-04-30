<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="viewport" content="width=device-width, initial-scale=1,maximum-scale=1.0">
        <title>GAT</title>
		<link rel="shortcut icon" type="image/x-icon" href="img/logo.png" />
        <link rel="stylesheet" href="css/bootstrap.min.css">
        <link rel="stylesheet" href="css/main.css">
		<link rel="stylesheet" href="css/human2.css">
		<script src="https://code.jquery.com/jquery-1.10.2.js"></script>
    </head>
    <body style="background-color: black;overflow-x: hidden; overflow-y: hidden;">
		<div id="particles-js" style="z-index:-2;"></div>
		<br><br>
		<center>
			<h1 style="font-family: PIZARRA; color: white;">Configuración</h1>
			<br><br>
			<?php if (!isset($_GET['nombre']) and !isset($_GET['ficha']) ) { ?> 	
				<h1 style="font-family: PIZARRA; color: white;">Digite su nombre</h1>
				<br><br><br><br>
				<form action="config.php" method="GET">
					<input type="text" name="nombre" autocomplete="off" autofocus class='input'>
				</form>
			<?php } if (isset($_GET['nombre'])and !isset($_GET['ficha']) ){ ?> 	
				<h1 style="font-family: PIZARRA; color: white;">Con que ficha desea jugar</h1>
				<br><br><br><br>
				<a href="config.php?nombre=<?php echo $_GET['nombre']; ?>&ficha=X" class="square c">X</a>	
				<a href="config.php?nombre=<?php echo $_GET['nombre']; ?>&ficha=O" class="square c" style="margin-left: 200px;">O</a>
			<?php } if(isset($_GET['ficha']) ) { ?>
				<h1 style="font-family: PIZARRA; color: white;">En que lugar desea realizar el juego</h1>
				<br><br><br><br>
				<a href="juego.php?nombre=<?php echo $_GET['nombre']; ?>&ficha=<?php echo $_GET['ficha']; ?>&pos=1" class="square c">Primero</a>
				<a href="juego.php?nombre=<?php echo $_GET['nombre']; ?>&ficha=<?php echo $_GET['ficha']; ?>&pos=2" class="square c" style="margin-left: 200px;">Segundo</a>
			<?php } ?>
		</center>
    </body>
	<script src="js/vendor/jquery.ajaxchimp.min.js"></script>
	<script src="js/vendor/particles.min.js"></script>
	<script src="js/vendor/app.js"></script>
</html>