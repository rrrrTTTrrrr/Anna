


var formjs = document.getElementById( 'form' );

// console.log( formjs );
console.log( formjs[0].value );

formjs.action = 'Test.php';
formjs.method = 'POST';

var submitb = document.getElementById( 'SubmitButton' );

submitb.onclick = function() { formjs.submit(); }







