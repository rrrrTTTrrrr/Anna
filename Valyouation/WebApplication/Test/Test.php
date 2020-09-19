
<?php

	echo $_POST['input'];
	echo "<br>";
	echo "<br>";

	echo "<br>";
	echo "<br>";

	echo $_COOKIE[ 'PHPSESSID' ];

	if ( session_status() == PHP_SESSION_ACTIVE )
	{
		echo "before PHP_SESSION_ACTIVE";
	}

	echo "<br>";
	echo "<br>";

	session_start( [ '$_COOKIE[ 'PHPSESSID' ]' ] );

	if ( session_status() == PHP_SESSION_ACTIVE )
	{
		echo "after PHP_SESSION_ACTIVE";
	}

	if (empty($_SESSION['count'])) {
	   $_SESSION['count'] = 1;
	} else {
	   $_SESSION['count']++;
	}

	setcookie( "Lord", "16", time() + 200 );

	echo "<br>";
	echo "<br>";

	echo $_COOKIE[ "Lord" ];

	echo "<br>";
	echo "<br>";

	echo session_id();

	?>



	<p>
	Hello visitor, you have seen this page <?php echo $_SESSION['count']; ?> times.
	</p>

	<p>
	To continue, <a href="nextpage.php?<?php echo htmlspecialchars(SID); ?>">click
	here</a>.
	</p>


