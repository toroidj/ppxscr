#!*script

$arg = $PPx->{Arguments};
if ( !$arg->Count ){
	$PPx->Echo("No parameter");
}else{
	for ( $i = 0 ; $i < $arg->Count ; $i++ ){
		$PPx->Echo($arg->Item($i));
	}
}
