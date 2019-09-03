<?php
session_start();

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
	<header>
		<h1 class="logo">Rejestracja</h1>
		<p><a href="wyl.php">Wyloguj się!</a></p>
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
	</header>
	<article>
		<div class="loguj">
			<form method="post" action="insert.php">
                    <label>E-mail <input type="email" name="email"></label><br>
             	    <?php
					if(isset($_SESSION['e_email']))
					{
						echo '<p>Taki e-mail juz istnieje!</p>';
					}
					?>						
					<br>
                    <label>Hasło <input type="password" name="pass"></label><br>
					
					<br>
                    <label>Login <input type="text" name="login"></label><br>
             	    <?php
					if(isset($_SESSION['e_login']))
					{
						echo '<p>Taki login juz istnieje!</p>';
					}
					?>						
					<br>
                    <input type="submit" value="Zarejestruj się!">
                    <button type="submit" formaction="index.php">Główna</button>
					
				
			</form>		    
		</div>
	</article>

</body>
</html>