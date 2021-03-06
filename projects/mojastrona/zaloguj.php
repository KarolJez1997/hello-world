<?php
session_start();

if(isset($_SESSION['logged_id']))
{
	header('Location: zapisz.php');
	exit();
}

?>
<!DOCTYPE html>
<html lang="pl">
<head>
	<meta charset="utf-8">
	<title>Wizytówka - Karol Jezierzański</title>
	<meta name="description" content="Programowanie - archiwum projektów">
	<meta name="keywords" content="php, html, CSS, SQL, C++, C#, Java">
	<meta http-equiv="X-Ua-Compatible" content="IE=edge">
	
	<link rel="stylesheet" href="main.css">
	<link href="https://fonts.googleapis.com/css?family=Alfa+Slab+One|Comfortaa:400,700&display=swap&subset=latin-ext" rel="stylesheet">
</head>
<body>
	<nav>
	    <h1 class="logo">Wizytówka - Karol Jezierzański</h1>
	 		<nav id="topnav">
			<ul class="menu">
				<li class="sub-menu-parent" tab-index="0"><a href="#">Projekty</a>
					<ul class="sub-menu">
						<li><a href="#">Projekt #1</a></li>
						<li><a href="#">Projekt #2</a></li>
						<li><a href="#">Projekt #3</a></li>
					</ul>
				</li>
				<li class="sub-menu-parent" tab-index="0"><a href="#">Kontakt</a>
					<ul class="sub-menu">
						<li><a href="rejestracja.php">Rejestracja</a></li>
						<li><a href="zaloguj.php">Logowanie</a></li>
						<li><a href="index.php">O mnie</a></li>	</ul>				
				</li>
				<li class="sub-menu-parent" tab-index="0"><a href="#">Zdjęcia</a></li>
			</ul>
		</nav>
		<div class="loguj">
			<form method="post" action="zapisz.php">
                    <label>Login <input type="email" name="email"></label><br><br>
                    <label>Hasło <input type="password" name="pass"></label><br><br>
                    <input type="submit" value="Zaloguj się!">
                    <button type="submit" formaction="index.php">Główna</button>
					
             	    <?php
					if(isset($_SESSION['bad_attempt']))
					{
						echo '<p>Niepoprawny email lub hasło!</p>';
						unset($_SESSION['bad_attempt']);
					}
					?>					
			</form>
		</div>
	</nav>
	
</body>
</html>