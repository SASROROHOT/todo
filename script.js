var index=0;
function render(){
    while(localStorage.getItem(index) !== null){
        document.getElementById('risposte').innerHTML += '<div class="ss"> <input type="checkbox" class="mybox" onclick="cex('+index+')" '+ localStorage.getItem('n'+index)+'><p class="boh">'+ localStorage.getItem(index) +'</p> </div>';
        index++;
    }
}

render();
var testo;
var help;
document.getElementById('btn1').addEventListener('click', function(){
    event.preventDefault();
    if(document.getElementById('ins').value === '') return;
    testo=document.getElementById('ins').value;
    help='';
    document.getElementById('risposte').innerHTML += '<div class="ss"> <input type="checkbox" class="mybox" onclick="cex('+index+')"'+ help +'><p class="boh">'+ testo +'</p> </div>';
    localStorage.setItem(index , testo);
    localStorage.setItem('n'+index, help);
    index++;
    document.getElementById('ins').value='';
    
})

document.getElementById('clear').addEventListener('click', function(){
    localStorage.clear();
    document.querySelectorAll('#risposte .ss').forEach(element => {
        element.remove();
    });
   // window.location.reload();
})

function cex(e){
    let stato = localStorage.getItem('n'+e);

    if(stato === " checked"){
        localStorage.setItem('n'+e, "");
    } else {
        localStorage.setItem('n'+e, " checked");
    }

    window.location.reload();
}
