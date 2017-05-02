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
				<script>
		$.post('Logica/sys.php',{opt: 0},function(data1){
			console.log(data1);
		})
		</script>
    </head>
    <body style="background-color: black;overflow-x: hidden; overflow-y: hidden;" onload="" >
	<div id="particles-js" style="z-index:-2;"></div>
	<center>
	<h1 style="font-family: PIZARRA; color: white;">Fin del juego</h1>
	    <table style="font-family: PIZARRA; color: white; width: 100%;">
			<tr>
				<td class="hidden-xs">
				</td>
				<td>
					<?php if ($_GET['opt'] == "X"){?>
					<h1 class="puntos"><center>Felicidades <?php echo $_GET['nombre']; ?> Ganaste </h1><br>
					<?php } else if ($_GET['opt'] != "1") { ?>
					<h1 class="puntos"><center>Lo lamento Perdiste</h1><br>
					<?php }	if ($_GET['opt'] == "1"){?>
					<h1 class="puntos"><center>EMPATE <?php echo $_GET['nombre']; ?>, Intentaremos jugar mejor.  </h1><br>
					<?php } ?>
					<center>
						<a href="index.php" class="btn btn-success puntos"><h2>Nueva Partida</h2></a>
				</td>
				<td class="hidden-xs">
					<div class="dialogo">Gracias por jugar</div>
					<div class="newcharacter404">
						<div class="chair404"></div>
						<div class="leftshoe404"></div>
						<div class="rightshoe404"></div>
						<div class="legs404"></div>
						<div class="torso404">
						  <div class="body404"></div>
						  <div class="leftarm404"></div>
						  <div class="rightarm404"></div>
						  <div class="head404">
							<div class="eyes404"></div>
						  </div>
						</div>
						<div class="laptop404"></div>
					</div>	  
				</td>
			</tr>
		</table>
		<script src="js/vendor/jquery.ajaxchimp.min.js"></script>
		<script src="js/vendor/particles.min.js"></script>
		<script src="js/vendor/app.js"></script>		
    </body>
</html>