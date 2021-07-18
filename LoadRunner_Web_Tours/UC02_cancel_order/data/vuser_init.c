/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 0
   ------------------------------------------------------------------------------- */

vuser_init()
{

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);

	lr_start_transaction("UC01_TR01_login");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=128572.831024706zzVDtztpQQfiDDDDDQziApHiQQHf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=34", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("SRCHUID=V=2&GUID=A4E765D003AD4E1CBF4E9A797DEEA438&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20200407; DOMAIN=iecvlist.microsoft.com");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR01_login",LR_AUTO);

	lr_think_time(43);

	lr_start_transaction("UC01_TR02_itinerary");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_itinerary",LR_AUTO);

	lr_think_time(75);

	lr_start_transaction("UC01_TR03_cancel_orders");

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=170413-7782-JB", ENDITEM, 
		"Name=flightID", "Value=229670-15469-JB", ENDITEM, 
		"Name=flightID", "Value=296351-23191-JB", ENDITEM, 
		"Name=flightID", "Value=11128-3113-JB", ENDITEM, 
		"Name=5", "Value=on", ENDITEM, 
		"Name=flightID", "Value=36630969-390-JB", ENDITEM, 
		"Name=flightID", "Value=3663059299-46238-JB", ENDITEM, 
		"Name=flightID", "Value=0-53-JB", ENDITEM, 
		"Name=flightID", "Value=0-61-JB", ENDITEM, 
		"Name=9", "Value=on", ENDITEM, 
		"Name=flightID", "Value=3300096337-69315-JB", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=66", ENDITEM, 
		"Name=removeFlights.y", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR03_cancel_orders",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("UC01_TR04_sign_off");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR04_sign_off",LR_AUTO);

	return 0;
}