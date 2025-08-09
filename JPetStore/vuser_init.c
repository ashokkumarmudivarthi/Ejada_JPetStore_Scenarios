vuser_init()
{
	lr_start_transaction("TR1_JPetStore_Launch");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	
	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_header("sec-ch-ua", 
		"\"Not;A=Brand\";v=\"99\", \"Google Chrome\";v=\"139\", \"Chromium\";v=\"139\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	web_add_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_custom_request("{P_HostName}", 
		"URL=https://{P_HostName}/", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t25.inf", 
		"Mode=HTTP", 
		LAST);

	
	web_add_header("Origin", 
		"https://{P_HostName}");

	web_add_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_header("sec-ch-ua", 
		"\"Not;A=Brand\";v=\"99\", \"Google Chrome\";v=\"139\", \"Chromium\";v=\"139\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	web_custom_request("speculation", 
		"URL=https://{P_HostName}/cdn-cgi/speculation", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/speculationrules+json", 
		"Referer=https://{P_HostName}/", 
		"Snapshot=t27.inf", 
		LAST);

	
	web_add_header("Origin", 
		"https://{P_HostName}");

	web_add_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_header("sec-ch-ua", 
		"\"Not;A=Brand\";v=\"99\", \"Google Chrome\";v=\"139\", \"Chromium\";v=\"139\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	

	web_custom_request("jquery-3.7.1.min.js", 
		"URL=https://code.jquery.com/jquery-3.7.1.min.js", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://{P_HostName}/", 
		"Snapshot=t29.inf", 
		LAST);

	

	
	
	lr_end_transaction("TR1_JPetStore_Launch",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("TR2_JPetStore_ClickSignUp");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("sec-ch-ua", 
		"\"Not;A=Brand\";v=\"99\", \"Google Chrome\";v=\"139\", \"Chromium\";v=\"139\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_custom_request("newAccountForm", 
		"URL=https://{P_HostName}/account/newAccountForm", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{P_HostName}/", 
		"Snapshot=t33.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Origin", 
		"https://{P_HostName}");

	web_custom_request("speculation_2", 
		"URL=https://{P_HostName}/cdn-cgi/speculation", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/speculationrules+json", 
		"Referer=https://{P_HostName}/account/newAccountForm", 
		"Snapshot=t34.inf", 
		LAST);

	


	lr_end_transaction("TR2_JPetStore_ClickSignUp",LR_AUTO);
	
	lr_think_time(9);

	lr_start_transaction("TR3_JPetStore_SaveAccountInformation");


	web_add_auto_header("Origin", 
		"https://{P_HostName}");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("sec-ch-ua", 
		"\"Not;A=Brand\";v=\"99\", \"Google Chrome\";v=\"139\", \"Chromium\";v=\"139\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	web_add_header("Accept-Encoding", "gzip, deflate");
	
	//<a href="/account/signonForm">Sign In</a>

	
//	web_reg_save_param("C_redirectURL", "LB=<a href=\"", "RB=\">", "Search=Headers", LAST);
	
/*	// Capture redirect URL from Location header
web_reg_save_param("C_redirectURL",
    "LB=Location: ",
    "RB=\r\n",
    "Search=Headers",
    "NotFound=ERROR",
    LAST
);*/

	web_custom_request("newAccount", 
		"URL=https://{P_HostName}/account/newAccount", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{P_HostName}/account/newAccountForm", 
		"Snapshot=t44.inf", 
		"Mode=HTTP", 
		"Body=username={P_UsrName}&password={P_Password}&repeatedPassword={P_Password}&firstName={P_FirstName}&lastName={P_LastName}&email={P_Email}&phone={P_PhoneNumber}&address1={P_AddressLine1}&address2={P_AddressLine2}&city={P_City}&state={P_State}&zip={P_ZipCode}&country={P_Country}&languagePreference=english&favouriteCategoryId=DOGS&listOption=true&bannerOption=true", 
		LAST);
	
	web_add_header("Accept-Encoding", "gzip, deflate");
	//web_reg_find("Text=Your account has been created. Please try login.", LAST);
	
	web_reg_find("Text=Your account has been created. Please try login.", 
             "SaveCount=saveAccInfo_Count", 
             LAST);
	
	
	web_custom_request("FollowRedirect",
    "URL=https://{P_HostName}/account/signonForm?created=true",
    "Method=GET",
    "Resource=0",
    "RecContentType=text/html",
    LAST
);
	
if (atoi(lr_eval_string("{saveAccInfo_Count}")) > 0) {
    lr_output_message("Account creation confirmation found.");
} else {
    lr_error_message("ERROR: Account creation confirmation text NOT found.");
    lr_end_transaction("TR3_JPetStore_SaveAccountInformation", LR_FAIL);
    return 0; // Exit the action early if error
}

	
	web_custom_request("speculation_3", 
		"URL=https://{P_HostName}/cdn-cgi/speculation", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/speculationrules+json", 
		"Referer=https://{P_HostName}/account/signonForm?created=true", 
		"Snapshot=t45.inf", 
		LAST);


	lr_end_transaction("TR3_JPetStore_SaveAccountInformation",LR_PASS);
	
	lr_think_time(9);
	
	return 0;
}
