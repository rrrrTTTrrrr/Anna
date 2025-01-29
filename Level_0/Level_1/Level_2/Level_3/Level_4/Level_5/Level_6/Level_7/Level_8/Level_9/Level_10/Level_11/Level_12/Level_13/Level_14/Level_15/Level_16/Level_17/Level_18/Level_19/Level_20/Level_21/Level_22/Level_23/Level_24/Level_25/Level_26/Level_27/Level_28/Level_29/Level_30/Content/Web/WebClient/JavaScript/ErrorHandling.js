function ErrorHandling()
{}

// Public methods :

// This public method will be used to check if the given object is not null or undefined
ErrorHandling.prototype.ValidObject( object )
{

  // Check if the object is null or undefined
  if ( ( object === null ) || ( object === undefined ) )
  {
    // The object is not valid
    // Just die
    Die();
  }

}
