// This object will be used to bring images from the server
function Image( imageURI, imageID )
{

  // Start with fetching the image from the server and add it to the image element when the image was downloaded
  fetch( imageURI ).then( function( response )
  {
    // Take the image part from the HTTP response and use it to create a new URL object
    var imageObjectURL = URL.createObjectURL( response.blob() );

    // Add the URL object containing the image to the image element
    m_imageElement.src = imageObjectURL;
  });

  // Create a new image element
  var m_imageElement = document.createElement( 'img' );

  // Check if the element was created successfully
  ErrorHandling.prototype.ValidObject( m_imageElement );

  // Set the tag ID
  m_imageElement.id = tagID;

  // This privileged method will be used to append the image element to the required tag
  this.Append = function( tagID )
  {
    // Try to get a reference to the required tag element
    var tagElement = document.getElementById( tagID );

    // Check if the tag element exist
    ErrorHandling.prototype.ValidObject( tagElement );

    // Append the image elemnt to the tag element
    tagElement.appendChild( m_imageElement );
  }

  // This privileged method will be used to set on click event handler
  this.OnClick = function( onClickHandler )
  {
    // Set the onclick member of the button element
    m_imageElement.onclick = onClickHandler;
  }

  // This privileged method will be used to add text to the image
  this.Text = function( text )
  {
    // Create a new text node and append it to the image element
    m_imageElement.appendChild( document.createTextNode( text ) );
  }

}
