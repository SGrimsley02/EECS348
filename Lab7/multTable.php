<?php
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['number'])) {
    $number = $_POST['number'];
    echo "<h2>Multiplication Table</h2>";
    echo "<table border='1'>";
    echo "<tr><th>&times;</th>";
    for ($i = 1; $i <= $number; $i++) {
        echo "<th>$i</th>";
    }
    echo "</tr>";
    for ($i = 1; $i <= $number; $i++) {
        echo "<tr><th>$i</th>";
        for ($j = 1; $j <= $number; $j++) {
            echo "<td>" . ($i * $j) . "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
}
?>
