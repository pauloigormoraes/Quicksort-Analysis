<?php

/*********************************
*****Autor: Paulo Igor Moraes*****
*****Egenharia da Computação******
****Ambiente: Ubuntu 16.04 LTS****
*********** PHP 7.0.4 ************
**** Ordenação por QuickSort *****
*********************************/

function rangeR() {
  for($r = 0; $r < 6; $r++) {
  $arr[] = rand(5, 10);
  }
  //quicksort($arr, 1, 6);
}

echo "QuickSort - Ordenacao\n";

$arr = [5, 3, 7, 9, 6];

function quicksort ($arr, $start, $final) {
  $pivo = 0;
  if ($final > $start) {
  $pivo = partion ($arr, $start, $final);
  quicksort($arr, $start, $pivo-1);
  quicksort($arr, $pivo+1, $final);
  }
  else {
  echo "Erro de execução, verifica seu pivo!\n";
  }
  echo '$pivo';
}

function partion($arr, $start, $final) {
  $left = $start;
  $right = $final;
  $pivo = $arr["$start"];
  $dr = 0;
  while ($left < $right) {
    if ($arr["$left"] <= $pivo) $left++;
    else ($arr["$right"] > $pivo) {$right--};
     if ($left < $right) {
      $dr = $arr["$left"];
      $arr["$left"] = $arr["$right"];
      $arr["$right"] = $dr;
     }
  }
  $arr["$start"] = $arr["$right"];
  $arr["$right"] = $pivo;
  return $arr["$right"];
}

quicksort($arr, 0, 4);

?>
