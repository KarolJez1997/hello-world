 <?php
 session_start();

require_once 'baza.php';

if(!isset($_SESSION['Admin']))
{
	header('Location: index.php');
	exit();
}

foreach($_POST['checkbox'] as $checkbox) 
{
	$id=$checkbox;
	if(isset($_POST['checkbox']))
	{
		 
		if(isset($_POST['USUNTO']))
		{	
	      $Query = $db->prepare('DELETE FROM users WHERE id = :id');
		  $Query->bindValue(':id', $id, PDO::PARAM_STR);
		  $Query->execute();
		}
	}
}
	header('Location: admin.php');
	exit();	
 ?>
 
