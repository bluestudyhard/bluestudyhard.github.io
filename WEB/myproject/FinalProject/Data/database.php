<?php
class SQL
{
    private PDO $db;
    public array $head = [], $arr = [];

    public function __construct() //构造函数
    {
        $host = 'localhost';
        $username = 'root';
        $password = '0990lk';
        $dbname = 'homework';

        try {
            $dsn = "mysql:host=$host; dbname=$dbname";
            $this->db = new PDO($dsn, $username, $password);
        } catch (PDOException $err) {

            die('link error' . $err->getMessage());
        }
    }

//Run内联函数放入sql语句
    public function Run($str): void
    {
        try {
            $this->arr = $this->db->query($str)->fetchAll(PDO::FETCH_ASSOC);
            if (!empty($this->arr)) {
                $this->head = array_keys($this->arr[0]);
            }
        } catch (PDOException $e) {
            echo $str, " ", $e->getMessage(), '<br>';
        }
    }
}
