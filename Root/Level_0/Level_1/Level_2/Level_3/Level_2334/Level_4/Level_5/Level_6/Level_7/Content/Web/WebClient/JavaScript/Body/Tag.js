function Tag( tag, tagID )
{
  // Create a new tag element
  var m_tagElement = document.createElement( tag );

  // Check if the element was created successfully
  ErrorHandling.prototype.ValidObject( m_tagElement );

  // Set the tag ID
  m_tagElement.id = tagID;

  // This privileged method will be used to append the tag element to the required tag
  this.Append = function( tagID )
  {
    // Try to get a reference to the required tag element
    var tagElement = document.getElementById( tagID );

    // Check if the tag element exist
    ErrorHandling.prototype.ValidObject( tagElement );

    // Append the button elemnt to the tag element
    tagElement.appendChild( m_tagElement );
  }

  // This privileged method will be used to set on click event handler
  this.OnClick = function( onClickHandler )
  {
    // Set the onclick member of the button element
    m_tagElement.onclick = onClickHandler;
  }

  // This privileged method will be used to add text to the tag
  this.Text = function( text )
  {
    // Create a new text node and append it to the button element
    m_tagElement.appendChild( document.createTextNode( text ) );
  }



}
