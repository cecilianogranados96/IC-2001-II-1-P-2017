<?php
##########################################################################################
# 
# OBJETIVO:
# =========
#
# Cerrar el juego colocado para cliente.
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
$output = shell_exec('taskkill /F /IM "Veneno.exe"');
echo "TERMINADO";
?>
