Itinerary()
{
	lr_think_time(8); 
		
	lr_start_transaction("UC01_TR02_itinerary");

	
	web_reg_save_param("flightID",
    "lb=<input type=\"hidden\" name=\"flightID\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);

    web_reg_save_param("cgifield",
    "lb=<input type=\"hidden\" name=\".cgifields\" value=\"",
    "rb=\"  />",
    "ord=all",
    LAST);
	
	
	web_url("welcome.pl",
		"URL=http://{hostPort}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_itinerary",LR_AUTO);

	lr_think_time(8); 
	
	return 0;
	
}
