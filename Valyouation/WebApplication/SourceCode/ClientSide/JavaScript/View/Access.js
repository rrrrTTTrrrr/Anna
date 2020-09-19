// This object will be used to create the acess view of the web application
function Acess()
{

  // This method will be used to create the navigation bar of the view
  function NavigationBar()
  {
    // Logo :

    // Create an image element to contain the logo
    var logo = new Image( 'http://localhost/Images/Logo.jpeg', 'Logo' );

    // Motivation :

    // Create a text element to contain the connection to the motivation view
    var motivation = new Text( 'Motivation', 'Motivation' );

    // Check that the text element was created successfully
    ErrorHandling.prototype.ValidObject( motivation );

    // How it works :

    // Create a text element to contain the connection to the how it works view
    var howItWorks = new Text( 'How it works', 'HowItWorks' );

    // Check that the text element was created successfully
    ErrorHandling.prototype.ValidObject( howItWorks );

    // Join :

    // Create a text element to contain the connection to the join view
    var join = new Text( 'Join', 'Join' );

    // Check that the text element was created successfully
    ErrorHandling.prototype.ValidObject( join );

    // Log in :

    // Create a text element to contain the connection to the log in view
    var login = new Text( 'Login', 'Login' );

    // Check that the text element was created successfully
    ErrorHandling.prototype.ValidObject( login );
  }
  
}
