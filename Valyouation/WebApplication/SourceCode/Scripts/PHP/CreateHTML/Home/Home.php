<?php
  
    // Include the template engine for HTML functionality
    require_once 'SourceCode/Scripts/PHP/CreateHTML/Objects/HTMLtemplateEngine/HTMLtemplateEngine.php';

    // Include the head object that creates the head part of the HTML
    require_once 'SourceCode/Scripts/PHP/CreateHTML/Objects/Head/Head.php';

    // Include the body object that creates the body part of the HTML
    require_once 'SourceCode/Scripts/PHP/CreateHTML/Objects/Body/Body.php';

    // Create a new head object that will create the head part of the HTML
    $HTMLhead = new Head();

    // Add the required tags to the head part of the HTML file

    // Add a title to the home page
    $HTMLhead->AddTitleTag( $global_webApplicationName );

    // Add a meta tag with the attributes http-equiv and content to state that the file is html and the charset is UTF-8
    $HTMLhead->AddMetaFileTypeTag( 'Content-Type', 'text/html; charset=utf-8' );

    // Add links to all of the CSS style sheets required

    // One for the layout of the elements 
    $HTMLhead->AddLinkForCSSstyleSheetTag( 'http://localhost/SourceCode/CSS/Layout.css' );

    // And another for the style of the elements
    $HTMLhead->AddLinkForCSSstyleSheetTag( 'http://localhost/SourceCode/CSS/Style.css' );

    // And another for the style of the elements
    $HTMLhead->AddLinkForCSSstyleSheetTag( 'https://fonts.googleapis.com/css?family=Roboto:100' );

    // Create a new body object that will create the body part of the HTML
    $HTMLbody = new Body();

    // Create an instance of the template engine for HTML object, and provide the HTML template file 
    $HTMLtemplateEngine = new HTMLtemplateEngine( '<body><div class="Grid"><div id="Header" name="Header" class="HeaderLayout HeaderStyle">{{{HeaderHTMLfile}}}</div><div id="Body" name="Body" class="BodyLayout BodyStyle">{{{BodyHTMLfile}}}</div><div id="Footer" name="Footer" class="FooterLayout FooterStyle">{{{FooterHTMLfile}}}</div></div></body>' );

    // Check if a new season was created
    if ( $NewSession === 1 )
    {
        // A new session was created

            // Set a new cookie for the State session variable
        $newCookie = new PHPcookie( 'State', 'FirstEntrance', 3600 );

        // Store the content of the HTML files that needs to be inserted into the final index HTML file
        $HeaderFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Header/Header.inc' );
        $BodyFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Body/Body.inc' );
        $FooterFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Footer/Footer.inc' );

        // Set all the tags and the content to replace them in the template engine for HTML instance
        $HTMLtemplateEngine->Set( "HeaderHTMLfile", $HeaderFileContent );
        $HTMLtemplateEngine->Set( "BodyHTMLfile", $BodyFileContent );
        $HTMLtemplateEngine->Set( "FooterHTMLfile", $FooterFileContent );
    }
    else if ( $IsUserLoggedIn !== 1 )
    {
        // Store the content of the HTML files that needs to be inserted into the final index HTML file
        $HeaderFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Header/Header.inc' );
        $BodyFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Body/Body.inc' );
        $FooterFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Footer/Footer.inc' );

        // Set all the tags and the content to replace them in the template engine for HTML instance
        $HTMLtemplateEngine->Set( "HeaderHTMLfile", $HeaderFileContent );
        $HTMLtemplateEngine->Set( "BodyHTMLfile", $BodyFileContent );
        $HTMLtemplateEngine->Set( "FooterHTMLfile", $FooterFileContent );
    }
    // Check if the user is logged in
    else
    {
        // A session was resumed and the user is logged in

            // Store the content of the HTML files that needs to be inserted into the final index HTML file
        $HeaderFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Header/HeaderLoggedUser.inc' );
        $BodyFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Body/Body.inc' );
        $FooterFileContent = file_get_contents( 'SourceCode/HTML/HTMLbody/Footer/Footer.inc' );

        // Set all the tags and the content to replace them in the template engine for HTML instance
        $HTMLtemplateEngine->Set( "HeaderHTMLfile", $HeaderFileContent );
        $HTMLtemplateEngine->Set( "BodyHTMLfile", $BodyFileContent );
        $HTMLtemplateEngine->Set( "FooterHTMLfile", $FooterFileContent );
    }

    // Replace all the tags in the body part of the HTML file with the required content
    $HTMLtemplateEngine->Replace();

    // Create an instance of the template engine for HTML object, and provide the HTML template file 
    $HTMLtemplateEngine = new HTMLtemplateEngine( $global_HTMLbasicFormat );

    // Set all the tags and the content to replace them in the template engine for HTML instance
    $HTMLtemplateEngine->Set( "HeadHTML", $HTMLhead->GetHTML() );
    $HTMLtemplateEngine->Set( "BodyHTML", $HTMLbody->GetHTML() );

    // Insert the head and body parts of the HTML instead of the tags in the template 
    $HTMLtemplateEngine->Replace();

    // Send to the client the result HTML
    echo $HTMLtemplateEngine->GetHTML();

?>