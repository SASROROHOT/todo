var index=0;
function render(){
    while(localStorage.getItem(index) !== null){
        document.getElementById('risposte').innerHTML += localStorage.getItem(index);
        index++;
    }
}
render();
var testo;
document.getElementById('btn1').addEventListener('click', function(){
    event.preventDefault();
    if(document.getElementById('ins').value === '') return;
    testo=document.getElementById('ins').value;
    
    document.getElementById('risposte').innerHTML += '<div class="ss"> <input type="checkbox" class="mybox"><p class="boh">'+ testo +'</p> </div>';
    localStorage.setItem(index++ , '<div class="ss"> <input type="checkbox"><p class="boh">'+ testo +'</p> </div>');
    document.getElementById('ins').value='';
    
})

document.getElementById('clear').addEventListener('click', function(){
    localStorage.clear();
    document.querySelectorAll('#risposte .ss').forEach(element => {
        element.remove();
    });
   // window.location.reload();
})
