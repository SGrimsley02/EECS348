function changeColors(){
    var border_r = document.getElementById("border_R").value;
    var border_g = document.getElementById("border_G").value;
    var border_b = document.getElementById("border_B").value;
    var border_w = document.getElementById("border_W").value;
    var back_r = document.getElementById("back_R").value;
    var back_g = document.getElementById("back_G").value;
    var back_b = document.getElementById("back_B").value;

    document.body.style.borderColor = "rgb(${border_r}, ${border_g}, ${border_b})";
    document.body.style.backgroundColor = "rgb(${back_r}, ${back_g}, ${back_b})";
    document.body.style.borderWidth = border_w + 'px';
}