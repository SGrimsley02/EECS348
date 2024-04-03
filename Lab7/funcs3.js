function validate(){
    var password1 = document.getElementById("password1").value;
    var password2 = document.getElementById("password2").value;
    if (password1.length > 8) {
        if (password1 == password2){
            alert("Everything is good!")
        } else {
            alert("Passwords do not match.")
        }
    } else {
        alert("Password is too short.")
    }
}