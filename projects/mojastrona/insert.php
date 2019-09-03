	<?php
	session_start();
			require_once 'baza.php';

		$email= filter_input(INPUT_POST, 'email', FILTER_VALIDATE_EMAIL);
		$password = filter_input(INPUT_POST, 'pass');
		$login = filter_input(INPUT_POST, 'login');
		
		//echo $login." ".$password;
		
		
		$userQuery1 = $db->prepare('SELECT  email FROM users WHERE email = :email');
		$userQuery1->bindValue(':email', $email, PDO::PARAM_STR);
		$userQuery1->execute();
		
		$mail = $userQuery1->rowCount();
		
		//echo $userQuery->rowCount();
		
		//echo $user['id']." ".$user['password'];
	    $userQuery2 = $db->prepare('SELECT  login FROM users WHERE login = :login');
		$userQuery2->bindValue(':login', $login, PDO::PARAM_STR);
		$userQuery2->execute();
		
		$loginik = $userQuery2->rowCount();
		
		
		//echo $userQuery->rowCount();
		
		
		if($mail>0)
		{
		   $_SESSION['e_email'] = true;	
		   header('Location: rejestracja.php');
		   exit();
		}
		else
		{
		   if(isset($_SESSION['e_email']))
			unset($_SESSION['e_email']);
		}
		if($loginik>0)
		{
		   $_SESSION['e_login'] = true;	
		   header('Location: rejestracja.php');
		   exit();
		}
		else
		{
		   if(isset($_SESSION['e_rejestracja']))
			unset($_SESSION['e_rejestracja']);
		}
		if(!(isset($_SESSION['e_rejestracja'])&&($_SESSION['e_rejestracja'])))
		{
	    $userQuery3 = $db->prepare('INSERT INTO users (email, haslo, login, AccDate) VALUES (:email, :haslo, :login, NOW())');
		$hash = password_hash($password, PASSWORD_DEFAULT);
		$userQuery3->bindValue(':email', $email, PDO::PARAM_STR);
		$userQuery3->bindValue(':haslo', $hash, PDO::PARAM_STR);
		$userQuery3->bindValue(':login', $login, PDO::PARAM_STR);
		$userQuery3->execute();
				   header('Location: zaloguj.php');
		}





?>