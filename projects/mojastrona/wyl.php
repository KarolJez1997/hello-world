<?php
session_start();
unset($_SESSION['logged_id']);
unset($_SESSION['logged_email']);
unset($_SESSION['Admin']);

header('Location: zaloguj.php');
?>