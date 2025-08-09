Login()
{
	
	lr_rendezvous("Login_Rendezvous");

	lr_start_transaction("TR4_JPetStore_Login");



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
web_reg_find("Text=Welcome", LAST);

	web_custom_request("signon", 
		"URL=https://{P_HostName}/account/signon", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{P_HostName}/account/signonForm?created=true", 
		"Snapshot=t54.inf", 
		"Mode=HTTP", 
		"Body=referer=&username={P_UsrName}&password={P_Password}", 
		LAST);

	web_concurrent_start(NULL);

	web_custom_request("speculation_4", 
		"URL=https://{P_HostName}/cdn-cgi/speculation", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/speculationrules+json", 
		"Referer=https://{P_HostName}/", 
		"Snapshot=t55.inf", 
		LAST);

	web_custom_request("banner_dogs.gif", 
		"URL=https://{P_HostName}/images/banner_dogs.gif", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=https://{P_HostName}/", 
		"Snapshot=t56.inf", 
		LAST);

	web_concurrent_end(NULL);


	lr_end_transaction("TR4_JPetStore_Login",LR_AUTO);

	lr_think_time(39);

	lr_start_transaction("TR5_JPetStore_Logout");


	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("sec-ch-ua", 
		"\"Not;A=Brand\";v=\"99\", \"Google Chrome\";v=\"139\", \"Chromium\";v=\"139\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_custom_request("signoff", 
		"URL=https://{P_HostName}/account/signoff", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{P_HostName}/", 
		"Snapshot=t60.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Origin", 
		"https://{P_HostName}");

	web_concurrent_start(NULL);

	web_custom_request("speculation_5", 
		"URL=https://{P_HostName}/cdn-cgi/speculation", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=application/speculationrules+json", 
		"Referer=https://{P_HostName}/", 
		"Snapshot=t61.inf", 
		LAST);


	web_concurrent_end(NULL);

	lr_end_transaction("TR5_JPetStore_Logout",LR_AUTO);

	return 0;
}