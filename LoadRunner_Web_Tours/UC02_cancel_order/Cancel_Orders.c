Cancel_Orders()
{
		
	int x = 1;
	int y = rand()%3 + 1;

	lr_think_time(8);
	
	lr_start_transaction("UC01_TR03_cancel_orders");
	
	lr_param_sprintf("clipboard",
    "%s=on&",
    lr_eval_string("{flightID_count}")); 
	
    lr_save_string("", "clipboard");
    
    for (x=1; x<=3; x++) {
    	
    	lr_param_sprintf("clipboard", "%s%d=on&", lr_eval_string("{clipboard}"), x);
    		  
    }

    for (x=1;x<=atoi(lr_eval_string("{flightID_count}"));x++) {
    
        lr_param_sprintf("clipboard",
        "%sflightID=%s&",
        lr_eval_string("{clipboard}"),
        lr_paramarr_idx("flightID",x));
        

        lr_param_sprintf("clipboard",
        "%s.cgifields=%s&",
        lr_eval_string("{clipboard}"),
        lr_paramarr_idx("cgifield",x));
        
    }    
    
    
    if (atoi(lr_eval_string("{flightID_count}")) >= y) {
    	
    	lr_save_string(lr_eval_string("{clipboard}removeFlights.x=36&removeFlights.y=4"), "par");
    	lr_save_string(lr_eval_string(lr_eval_string("{flightID_{flightID_count}}")), "c_cancelflight");
       	
    }
    
     
    web_reg_find("Text=Itinerary", LAST);
    
     web_custom_request("itinerary.pl_2",
    "URL=http://{hostPort}/cgi-bin/itinerary.pl",
    "Method=POST",
    "Resource=0",
    "RecContentType=text/html",
    "Referer=http://{hostPort}/cgi-bin/itinerary.pl",
    "Snapshot=t23.inf",
    "Mode=HTTP",
    "Body={par}",
    LAST);
    
	/*web_submit_data("itinerary.pl", 
		"Action=http://{hostPort}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/itinerary.pl", 
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
		LAST);*/

	lr_end_transaction("UC01_TR03_cancel_orders",LR_AUTO);

	lr_think_time(8);
	
	return 0;
	
}
