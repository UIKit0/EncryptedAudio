<?php

$toBeConverted=<<<EOF
00000000 00000000 00000000 00000000 00000000 00000000 00000000 e79a7b1e 
fa0fb2b7 f47b094b 87079baf 2f51bb0a 41764109 93dc2d64 b150c8c9 9f6b6c43 
1b37aea9 f302afd8 d84af325 1045c838 e365db2f 2bdd9ce8 b05c5c5c 50359571 
43acfa1b 2a65e5b2 39ae5dd8 61635cb4 39fe9343 2d3f8b54 0c27c7df f2e97728 
82943677 2c365561 4df97cad 2a5e21f6 d153b8d9 33648c2d 35de67c9 
EOF;


echo strtoupper(str_replace(PHP_EOL, '', str_replace(' ', '', $toBeConverted)));