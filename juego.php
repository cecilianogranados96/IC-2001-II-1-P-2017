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
		<script>
		var mensajes = ["Buena jugadada","No eres tan bueno","Eso no me gusto","Debes mejorar","Tienes cerebro","Me gusta","No eres tan bueno","Eso me gusta","Es un reto","Me estas retando","Yo lo hago mejor","Continua","Veremos como acaba esto"];
		function jugar(x,y){
			valor = $("#"+x+y).text();
			if (valor == ""){
				$(".dialogo").text(mensajes[Math.floor(Math.random()*(mensajes.length-0))]+"...");
				correr();
				$.post('Logica/s.php',{x: 0,y: 0},function( data ) {
					parar();
				})
			}else{
				$(".dialogo").text("Movimiento Incorrecto :/");
			}
		}
		function correr(){
			$(".torso404").css("animation","sway 20s ease infinite");
			$(".head404").css("animation","headTilt 20s ease infinite");
			$(".eyes404").css("animation","blink404 10s steps(1) infinite, pan 10s ease-in-out infinite");
			$(".leftarm404").css("animation","typeLeft 0.4s linear infinite");
			$(".rightarm404").css("animation","typeLeft 0.4s linear infinite");
			$(".laptop404").css("animation","tapWobble 0.4s linear infinite");
		}
		function parar(){
			$(".dialogo").text("Esperando...");
			$(".torso404").css("animation","sway 20s ease ");
			$(".head404").css("animation","headTilt 20s ease ");
			$(".eyes404").css("animation","blink404 10s steps(1) , pan 10s ease-in-out ");
			$(".leftarm404").css("animation","typeLeft 0.4s linear ");
			$(".rightarm404").css("animation","typeLeft 0.4s linear ");
			$(".laptop404").css("animation","tapWobble 0.4s linear ");
		}
		</script>
    </head>
    <body style="background-color: black;overflow-x: hidden; overflow-y: hidden;">
	<div id="particles-js" style="z-index:-2;"></div>
	<center>
	<h1 style="font-family: PIZARRA; color: white;">Tablero de juego</h1>
	    <table style="font-family: PIZARRA; color: white; width: 100%;">
			<tr>
				<td class="hidden-xs">
					<br>
					<h1 class="puntos"><center>RONDA</h1><br>
					<h1 class="puntos"><center>0</h1>
					<br>
					<center>
						<a href="index.php" class="btn btn-danger puntos"><h2>Terminar</h2></a>
					<br>
				</td>
				<td>
					<center>
					<table>
					  <tr id="row1">
						<td class="square" onclick="jugar('1','1');" id="11">X</td>
						<td class="square v" onclick="jugar('1','2');" id="12"></td>
						<td class="square" onclick="jugar('1','3');" id="13">X</td>
					  </tr>
					  <tr id="row2">
						<td class="square h" onclick="jugar('2',1');" id="21"></td>
						<td class="square v h" onclick="jugar('2','2');" id="22"></td>
						<td class="square h" onclick="jugar('2','3');" id="23">X</td>
					  </tr>
					  <tr id="row3">
						<td class="square" onclick="jugar('3','1');" id="31">O</td>
						<td class="square v" onclick="jugar('3','2');" id="32">X</td>
						<td class="square" onclick="jugar(3'','3');" id="33"></td>
					  </tr>
					</table>
				</td>
				<td class="hidden-xs">
					<div class="dialogo">Esperando...</div>
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