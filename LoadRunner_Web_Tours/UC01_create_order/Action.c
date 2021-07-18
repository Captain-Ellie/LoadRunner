Action()
{

	lr_start_transaction("UC01_TR04_Find_Flight");
	
	web_reg_find("Text=Payment Details", LAST);
	
	web_set_max_html_param_len("15000");
	
	web_submit_data("reservations.pl_2", 
		"Action=http://{hostPort}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/reservations.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=36", ENDITEM, 
		"Name=reserveFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR04_Find_Flight",LR_AUTO);

	lr_think_time(2);
	

	lr_start_transaction("UC01_TR05_Payment_Details");
	
	web_reg_find("Text=Thank you for booking through Web Tours.", LAST);
	
	web_submit_data("reservations.pl_3", 
		"Action=http://{hostPort}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{hostPort}/cgi-bin/reservations.pl", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value=Baker st.", ENDITEM, 
		"Name=address2", "Value=London", ENDITEM, 
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM, 
		"Name=creditCard", "Value={creditCard}", ENDITEM, 
		"Name=expDate", "Value=05\\06", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=37", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR05_Payment_Details",LR_AUTO);

	lr_think_time(2);
	
	return 0;
	
}