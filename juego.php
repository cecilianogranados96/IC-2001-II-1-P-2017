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
		
		$.post('Logica/config.php',{opt: <?php echo $_GET['pos']; ?>},function(data) {
			dibujar();
		})
		
		
		var mensajes = ["Buena jugadada","No eres tan bueno","Eso no me gusto","Debes mejorar","Tienes cerebro","Me gusta","No eres tan bueno","Eso me gusta","Es un reto","Me estas retando","Yo lo hago mejor","Continua","Veremos como acaba esto"];
		function jugar(x,y){
			valor = $("#"+x+y).text();
			if (valor == ""){
				$(".dialogo").text(mensajes[Math.floor(Math.random()*(mensajes.length-0))]+"...");
				correr();
				$.post('Logica/jugar.php',{i: x,j: y},function(data) {
					$.post('Logica/ver_tablero.php',{opt: 0},function(data1){
							var data = data1;
							console.log(data);
							var pos = data.split("~");
							for(x=0;x<9;x++){
								var div = pos[x].split("-");
								if (div[1] == "*"){
									val = "";					
								}else{
									val = div[1];
								}
								$(div[0]).html(val);
							}
							
							//verificación de ganador
							
							verificar();
							/*
							$.post('Logica/verificar.php',{opt: 0},function(data1) {
								if (data1 == "Win"){
									window.location.href = 'gano.php?opt=win&nombre=<?php echo $_GET['nombre']; ?>&pos=<?php echo $_GET['pos']; ?>';
								}else if (data1 == "Loose"){
									window.location.href = 'gano.php?opt=loose&nombre=<?php echo $_GET['nombre']; ?>&pos=<?php echo $_GET['pos']; ?>';
								}
							})
							*/
						})
			
			
					parar();
				})
			}else{
				$(".dialogo").text("Movimiento Incorrecto :/");
			}
		}
		
		function dibujar(){
			$.post('Logica/ver_tablero.php',{opt: 0},function(data1){
				var data = data1;
				console.log(data);
				var pos = data.split("~");
				for(x=0;x<9;x++){
					var div = pos[x].split("-");
					if (div[1] == "*"){
						val = "";					
					}else{
						val = div[1];
					}
					$(div[0]).html(val);
				}
			})
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
			$(".dialogo").text("Espero tu movimiento...");
			$(".torso404").css("animation","sway 20s ease ");
			$(".head404").css("animation","headTilt 20s ease ");
			$(".eyes404").css("animation","blink404 10s steps(1) , pan 10s ease-in-out ");
			$(".leftarm404").css("animation","typeLeft 0.4s linear ");
			$(".rightarm404").css("animation","typeLeft 0.4s linear ");
			$(".laptop404").css("animation","tapWobble 0.4s linear ");
		}
		setTimeout(function(){
		  $(".dialogo").text("Espero tu movimiento...");
		  correr();
		  parar();
		}, 3000);
		
		
		
		function verificar(){
			var url_win_X = "gano.php?opt=X&nombre=<?php echo $_GET['nombre']; ?>&pos=<?php echo $_GET['pos']; ?>";
			var url_win_O = "gano.php?opt=O&nombre=<?php echo $_GET['nombre']; ?>&pos=<?php echo $_GET['pos']; ?>";
			var url_win_EN = "gano.php?opt=1&nombre=<?php echo $_GET['nombre']; ?>&pos=<?php echo $_GET['pos']; ?>";
			
			//Fila
			if ($("#00").text() == "X" &&  $("#01").text() == "X" && $("#02").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#00").text() == "O" &&  $("#01").text() == "O" && $("#02").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}
			
			if ($("#10").text() == "X" &&  $("#11").text() == "X" && $("#12").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#10").text() == "O" &&  $("#11").text() == "O" && $("#12").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}
			
			if ($("#20").text() == "X" &&  $("#21").text() == "X" && $("#22").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#20").text() == "O" &&  $("#21").text() == "O" && $("#22").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}
			//Columnas
			if ($("#00").text() == "X" &&  $("#10").text() == "X" && $("#20").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#00").text() == "O" &&  $("#10").text() == "O" && $("#20").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}
		
			if ($("#01").text() == "X" &&  $("#11").text() == "X" && $("#21").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#01").text() == "O" &&  $("#11").text() == "O" && $("#21").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}
			
			if ($("#02").text() == "X" &&  $("#12").text() == "X" && $("#22").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#02").text() == "O" &&  $("#12").text() == "O" && $("#22").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}
			//Diagonales
			if ($("#00").text() == "X" &&  $("#11").text() == "X" && $("#22").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#00").text() == "O" &&  $("#11").text() == "O" && $("#22").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}

			if ($("#02").text() == "X" &&  $("#11").text() == "X" && $("#20").text() == "X"){
				console.log("X gana");
				window.location.href = url_win_X;
			}else if($("#02").text() == "O" &&  $("#11").text() == "O" && $("#20").text() == "O"){
				console.log("O gana");
				window.location.href = url_win_O;
			}
			
			//VERIFICAR EMPATE	
			if (
				$("#00").text() != "" && 
				$("#01").text() != "" && 
				$("#02").text() != "" && 
				$("#10").text() != "" && 
				$("#11").text() != "" && 
				$("#12").text() != "" && 
				$("#20").text() != "" && 
				$("#21").text() != "" && 
				$("#22").text() != ""){
				console.log("X gana");
				window.location.href = url_win_EN;
			}
		}

		</script>
    </head>
    <body style="background-color: black;overflow-x: hidden; overflow-y: hidden;" onload="" >
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
					<table class="tablero">
					  <tr id="row1">
						<td class="square" onclick="jugar('0','0');" id="00">*</td>
						<td class="square v" onclick="jugar('0','1');" id="01">*</td>
						<td class="square" onclick="jugar('0','2');" id="02">*</td>
					  </tr>
					  <tr id="row2">
						<td class="square h" onclick="jugar('1','0');" id="10">*</td>
						<td class="square v h" onclick="jugar('1','1');" id="11">*</td>
						<td class="square h" onclick="jugar('1','2');" id="12">*</td>
					  </tr>
					  <tr id="row3">
						<td class="square" onclick="jugar('2','0');" id="20">*</td>
						<td class="square v" onclick="jugar('2','1');" id="21">*</td>
						<td class="square" onclick="jugar('2','2');" id="22">*</td>
					  </tr>
					</table>
				</td>
				<td class="hidden-xs">
					<div class="dialogo">Hola mi nombre es Dan...</div>
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