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
			<?php if (!isset($_GET['nombre']) and !isset($_GET['ficha']) ) { 				
				session_start();
				if(isset($_SESSION["nombre"])){
					$nombre = $_SESSION["nombre"];
				}else{
					$nombre = "";
				}
				

				?> 	
				<h1 style="font-family: PIZARRA; color: white;">Digite su nombre</h1>
				<br><br><br><br>
				<form action="config.php" method="GET">
					<input type="text"  value="<?php echo $nombre; ?>" name="nombre" autocomplete="off" autofocus class='input'>
				</form>
			<?php } if(isset($_GET['nombre']) ) { 
				session_start();
				$_SESSION["nombre"] = $_GET['nombre'];
			?>
				<h1 style="font-family: PIZARRA; color: white;">En que lugar desea realizar el juego</h1>
				<br><br><br><br>
				<a href="config.php?nombre=<?php echo $_GET['nombre']; ?>&pos=1" class="square c">Primero</a>
				<a href="config.php?nombre=<?php echo $_GET['nombre']; ?>&pos=0" class="square c" style="margin-left: 200px;">Segundo</a>
			<?php if(isset($_GET['pos'])){ ?>
			<script>
			/*$.post('Logica/config.php',{opt: <?php echo $_GET['pos']; ?>},function( data ) {
					console.log(data); */
					window.location.href = 'juego.php?nombre=<?php echo $_GET['nombre']; ?>&pos=<?php echo $_GET['pos']; ?>';
			//})
			</script>
			<?php	
			}
} ?>
		</center>
    </body>
	<script src="js/vendor/jquery.ajaxchimp.min.js"></script>
	<script src="js/vendor/particles.min.js"></script>
	<script src="js/vendor/app.js"></script>
</html>