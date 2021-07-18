vuser_end()
{
	
	lr_start_transaction("UC01_TR04_sign_off");
	
	web_url("SignOff Button", 
		"URL=http://{hostPort}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR04_sign_off",LR_AUTO);

	return 0;
}
