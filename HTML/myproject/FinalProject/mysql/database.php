<?php

//phpinfo();
class SQL
{
    private PDO $db;
    public array $head = [], $arr = []; //表头及表内容

    public function __construct()
    {
        $host = "localhost";
        $user = "root";
        $pw = "0990lk"; //只需要修改为自己的密码即可
        $dbname = "homework";

        try {
            $dns = "mysql:host=$host;dbname=$dbname";
            $this->db = new PDO($dns, $user, $pw);
        } catch (PDOException $err) {
            die('链接失败! ' . $err->getMessage());
        }
    }

    public function Run($str): void
    {
        try {
            $this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $run = $this->db->query($str);

            $this->arr = $run->fetchAll(PDO::FETCH_ASSOC);
            if (!empty($this->arr))
                $this->head = array_keys($this->arr[0]);
        } catch (PDOException $e) {
            echo $str, "   ", $e->getMessage(), '<br>';
        }
    }
}

//function printTable($arr, $head): void
//{
//    foreach ($arr as $row) {
//        echo '<tr>';
//        foreach ($head as $col) {
//            echo '<td>', $row[$col], '</td>';
//        }
//        echo '</tr>';
//    }
//    echo '</tbody></table>';
//}
