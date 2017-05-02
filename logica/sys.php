<?php
##########################################################################################
# 
# OBJETIVO:
# =========
#
# Iniciar socket.
#
# Parametros:
# ===========
#
#
# Desarrollo:
# 
# - Jose Andres Ceciliano Granados
#
#
#########################################################################################
if ($_POST['opt'] == 1){
	system('TTT\bin\Debug\TTT.exe');
	echo "start";
}else{
	$output = shell_exec('taskkill /F /IM "TTT.exe"');
	echo "down";
}
?>