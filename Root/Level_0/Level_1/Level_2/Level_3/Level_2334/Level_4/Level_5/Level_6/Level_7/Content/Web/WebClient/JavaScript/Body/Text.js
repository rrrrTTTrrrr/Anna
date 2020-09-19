function Text( text, textID )
{
  // Create a new div element to contain the text
  var m_divElement = document.createElement( 'div' );

  // Check if the element was created successfully
  ErrorHandling.prototype.ValidObject( m_divElement );

  // Set the tag ID
  m_divElement.id = tagID;

  // This privileged method will be used to append the image element to the required tag
  this.Append = function( tagID )
  {
    // Try to get a reference to the required tag element
    var tagElement = document.getElementById( tagID );

    // Check if the tag element exist
    ErrorHandling.prototype.ValidObject( tagElement );

    // Append the div elemnt to the tag element
    tagElement.appendChild( m_divElement );
  }

  // This privileged method will be used to set on click event handler
  this.OnClick = function( onClickHandler )
  {
    // Set the onclick member of the div element
    m_divElement.onclick = onClickHandler;
  }

  // This privileged method will be used to add text
  this.SetText = function( text )
  {
    // Set the inner HTML member of the div element to the requied text
    m_divElement.innerHTML = text;
  }

}
