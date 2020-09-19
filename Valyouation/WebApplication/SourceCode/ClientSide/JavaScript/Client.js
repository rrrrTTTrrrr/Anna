function Client()
{

  // This is the client side

  function RecordState()
  {
    // The first stage is to copy all the body part of the HTML
  }


  // Create a map to contain the JavaScript functionality for creating the view
  var m_viewToScript = new Map();

  // Create a new HTTPrequest object to connect with the server
  var queryServer = new HTTPrequest( 'POST', 'http://localhost/cgi-bin/index.exe' );

  function CreateView()
  {
      // The file containing the functionality to create the view is loaded

      // Store the file in this instance
      m_javaScriptContainer[ 'ACCESS' ] = queryServer.GetResponseText();

      // Create a new script element
      var scriptElement = document.createElement( 'script' );

      // Set the script type
      scriptElement.type = 'text/javascript';

      // Set the script ID
      scriptElement.id= 'ACCESS';

      // Set the script tag content with the functionality to create the view
      scriptElement.text = queryServer.GetResponseText();

      // Add the element to the DOM tree
      document.getElementById( 'Body' )[0].appendChild( scriptElement );

      // Create the view
      Access();
  }

  // Set the event handler of the time the file is loaded
  queryServer.DONEeventHandler( CreateView );

  // Query for the javascript functionality to constrcut the home page
  queryServer.Send( 'ACCESS' );


  xhr.open('GET', url, true);
  xhr.send('');


  // View object - will contain all the neccesary code to
  function View()
  {

    // Number of segments the body part needs to contain, for example header, sidebar, footer etc...
    var m_numberOfBodySegments;

    //
  }

}
