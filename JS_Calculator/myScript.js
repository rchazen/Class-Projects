var num;
var operator;
var input_1 = 0;
var input_operator;
var input_2 = 0;
var bool = 0;
var dot_count = 0;
var operator_count = 0;
var new_click = null;

function numClicked(num){
    if(new_click == true){
        document.getElementById("display").value = " ";
    }
    if(num != "."){
    document.getElementById("display").value += num;
    } else if(num == "." && dot_count == 0){
        document.getElementById("display").value += num;
        dot_count++;
    } else{

    }

}

function equalClicked(){
    if(bool == 0){
        input_2 =  document.getElementById("display").value
        bool = 1;
    }
    let x = input_1 +input_operator+ input_2
    let y = eval(x)
    document.getElementById("display").value = y
    input_1 = y
    operator_count = 0;
    
}
function clearClicked(){
    document.getElementById("display").value = " ";
    bool = 0;
    dot_count = 0;
    input_1 = 0;
    input_2 = 0
    operator_count = 0;
    input_operator = " ";
    new_click = false;
}
function operatorClicked(operator){
    bool = 0;
    dot_count = 0;
    if(operator_count == 0){
        input_1 = document.getElementById("display").value;
        document.getElementById("display").value = " ";
        operator_count++;
    } else {
        input_2 = document.getElementById("display").value;
        let x = input_1 +input_operator+ input_2;
        let y = eval(x);
        document.getElementById("display").value = y;
        input_1 = y
        new_click = true;

    }
    
    input_operator = operator;
    


   
    




}