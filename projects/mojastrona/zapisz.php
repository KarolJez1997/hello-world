<?php
session_start();

		require_once 'baza.php';

if(!isset($_SESSION['logged_id']))
{
	if(isset($_POST['email']))
	{
		$email= filter_input(INPUT_POST, 'email', FILTER_VALIDATE_EMAIL);
		$password = filter_input(INPUT_POST, 'pass');
		
				if($password=='BARDZOTAJNEHASLO')
		{
		   $_SESSION['Admin']=true;
		   unset($_SESSION['bad_attempt']);
		   header('Location: admin.php');
		   exit();			
		}
		
		//echo $login." ".$password;
		
		
		$userQuery = $db->prepare('SELECT id, haslo, email FROM users WHERE email = :email');
		$userQuery->bindValue(':email', $email, PDO::PARAM_STR);
		$userQuery->execute();
		
		//echo $userQuery->rowCount();
		
		$user = $userQuery->fetch();
		//echo $user['id']." ".$user['password'];

		
		if($user && password_verify($password, $user['haslo']))
		{
			$_SESSION['logged_id'] = $user['id'];
			$_SESSION['logged_email'] = $user['email'];
			unset($_SESSION['bad_attempt']);
		}
		else
		{
		   $_SESSION['bad_attempt'] = true;	
		   header('Location: zaloguj.php');
		   exit();
		}
	}
	else
	{
		header('Location: zaloguj.php');
		exit();
	}
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
	<header>
		<h1 class="logo">Witaj <?= $_SESSION['logged_email'] ?>!</h1>
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
</body>
</html>