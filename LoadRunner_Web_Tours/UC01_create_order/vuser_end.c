vuser_end()
{
	
	lr_start_transaction("UC01_TR6_Invoice");

	web_submit_data("reservations.pl_4", 
		"Action=http://{hostPort}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/reservations.pl", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=Book Another.x", "Value=39", ENDITEM, 
		"Name=Book Another.y", "Value=10", ENDITEM, 
		LAST);

	web_custom_request("FormDateUpdate.class_2", 
		"URL=http://{hostPort}/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"TargetFrame=", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t19.inf", 
		LAST);

	lr_end_transaction("UC01_TR6_Invoice",LR_AUTO);
	
	return 0;
}
