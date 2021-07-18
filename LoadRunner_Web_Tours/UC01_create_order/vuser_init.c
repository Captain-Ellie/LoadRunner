vuser_init()
{	
	   
	web_reg_save_param("userSession",
	                   "LB=\"userSession\" value=\"",
	                   "RB=\"/>",
	                   LAST);
	
	
	web_reg_find("Text=Welcome to the Web Tours site.", LAST);
	
	web_url("WebTours", 
		"URL=http://{hostPort}/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	
	lr_start_transaction("UC01_TR01_Login");
	
	web_reg_find("Text=Web Tours reservation pages.", LAST); 
    
	web_submit_data("login.pl", 
		"Action=http://{hostPort}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession}", ENDITEM, 
		"Name=username", "Value={userName}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=58", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);
	
	
	
	return 0;
}
