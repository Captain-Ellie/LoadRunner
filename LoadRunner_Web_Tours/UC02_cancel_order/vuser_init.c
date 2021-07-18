vuser_init()
{

	web_reg_save_param("userSession",
	                   "LB=\"userSession\" value=\"",
	                   "RB=\"/>",
	                   LAST);

	
	
	web_url("WebTours", 
		"URL=http://{hostPort}/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	
	lr_start_transaction("UC01_TR01_login");
	  
	
	web_submit_data("login.pl",
		"Action=http://{hostPort}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={userName}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=34", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR01_login",LR_AUTO);

	
    return 0;
	

	
}