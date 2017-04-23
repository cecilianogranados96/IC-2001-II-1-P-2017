<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="viewport" content="width=device-width, initial-scale=1,maximum-scale=1.0">
        <title>GAT - El juego mas complejo que has jugado.</title>
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
			<?php if (!isset($_GET['ficha'])) { ?> 	
				<h1 style="font-family: PIZARRA; color: white;">Con que ficha desea jugar</h1>
				<br><br><br><br>
				<a href="config.php?ficha=X" class="square c">X</a>	
				<a href="config.php?ficha=O" class="square c" style="margin-left: 200px;">O</a>
			<?php }else{ ?>
				<h1 style="font-family: PIZARRA; color: white;">En que lugar desea realizar el juego</h1>
				<br><br><br><br>
				<a href="juego.php?ficha=<?php echo $_GET['ficha']; ?>&pos=1" class="square c">Primero</a>
				<a href="juego.php?ficha=<?php echo $_GET['ficha']; ?>&pos=2" class="square c" style="margin-left: 200px;">Segundo</a>
			<?php } ?>
		</center>
    </body>
	<script src="js/vendor/jquery.ajaxchimp.min.js"></script>
	<script src="js/vendor/particles.min.js"></script>
	<script src="js/vendor/app.js"></script>
</html>