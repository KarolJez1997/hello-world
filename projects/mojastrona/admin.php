<?php
session_start();

require_once 'baza.php';

if(!isset($_SESSION['Admin']))
{
	header('Location: index.php');
	exit();
}

 $usersQuery = $db->prepare('SELECT * FROM users');
 $usersQuery->execute();
 
 $users = $usersQuery->fetchAll();

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
	    <h1 class="logo">ADMIN ROOM</h1>
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
	</nav>
	             <div class="loguj2">
	 		        <table>
				   <thead>
						<tr><th colspan="5">Łącznie rekordów: <?= $usersQuery->rowCount() ?></th></tr>
						<tr><th>ID</th><th>E-mail</th><th>login</th><th>Data założenia</th></tr>
				   </thead>
				   <tbody>
				      <?php
					   echo'<form method="post" action="zmiany.php">';
					    foreach($users as $user) {
							echo "<tr><td>{$user['id']}</td><td>{$user['email']}</td><td>{$user['login']}</td><td>{$user['AccDate']}</td><td>";
							echo '<input type="checkbox" name="checkbox[]" value="'.$user['id'].'" /></td></tr>';
							
						}
						echo'<tr><td><input type="checkbox" name="USUNTO"/>USUŃ TO</td><td><input type="checkbox" name="EDYTUJ"/>USUŃ TO</td></tr>';
					   echo '<input type="submit" value="Dokonaj zmian"/>';
						echo'</form>';
					  ?>
					  
				   </tbody>
                </table>
				</div>
                     <p><a href="wyl.php">Wyloguj się!</a></p>

	
</body>
</html>

