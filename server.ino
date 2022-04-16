// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "<<YOUR WIFI SSID>>";
const char* password = "<<YOUR WIFI PASSWORD>>";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output15State = "off";
String output4State = "off";

// Assign output variables to GPIO pins
const int output15 = 15;
const int output4 = 4;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

// Define Authentication
const char* base64Encoding = "TWlzaE1hc2hMYWJzOm1pc2htYXNo";  // base64encoding user:pass - "dXNlcjpwYXNz", MishMashLabs:mishmash - "TWlzaE1hc2hMYWJzOm1pc2htYXNo"


void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(output15, OUTPUT);
  pinMode(output4, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output15, LOW);
  digitalWrite(output4, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // check base64 encode for authentication
            // Finding the right credentials
            if (header.indexOf(base64Encoding)>=0)
            {
            
              // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
              // and a content-type so the client knows what's coming, then a blank line:
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println("Connection: close");
              client.println();
              
              // Display the HTML web page
              client.println("<!DOCTYPE html><html>");
              client.println("<head>");
              client.println("<meta charset='UTF-8'>");
              client.println("<link rel='icon' type='image/x-icon' href='https://cdn.dribbble.com/users/1573719/screenshots/15675086/media/460a3198328726158e47eb208f46822e.png?compress=1&resize=1200x900&vertical=top'>");
              client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
              client.println("<meta http-equiv='X-UA-Compatible' content='ie=edge'><title>Morpheuslord Web page</title>");
              client.println("<link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/animate.css/3.7.0/animate.min.css'><link href='https://fonts.googleapis.com/css?family=Comfortaa:700' rel='stylesheet'>");
              client.println("<script src='https://code.jquery.com/jquery-3.3.1.min.js' integrity='sha256-FgpCb/KJQlLNfOu91ta32o/NMZxltwRo8QtmkMRdAu8=' crossorigin='anonymous'>");
              client.println("</script><link rel='stylesheet' href='https://use.fontawesome.com/releases/v5.7.1/css/all.css' integrity='sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr' crossorigin='anonymous'>");
              // Feel free to change the background-color and font-size attributes to fit your preferences
              client.println("<style>@import 'https://fonts.googleapis.com/css2?family=Goldman&display=swap';@import 'https://fonts.googleapis.com/css?family=Open+Sans:300,400,700';");
              client.println("body,html {padding:0px; margin:0px;font-family: 'Comfortaa', cursive;font-weight:bold;color:#fff;background:rgb(0, 0, 0);scroll-behavior: smooth;}");
              client.println("#header {width:80%;padding:4% 10%;text-align:center;position:absolute;transition:0.6s ease-in-out;}");
              
              
              //stylesheet
              client.println("#header div {display:block;}");
              client.println(".text-change-container {height: 20%;width: 100%;justify-content: center;align-items: center;display: flex;}");
              client.println(".text-change {font-family: 'Goldman', monospace;font-weight: normal;font-size: larger;color: #c8c8c8;filter: drop-shadow(0 0 0.3em rgba(200,200,200,0.3));}");
              client.println(".dud {color: rgba(200,30,30,0.8);filter: drop-shadow(0 0 0.5em #f00);}");
              client.println("#middle {width:100%;height:80vh;background:linear-gradient(0deg,rgba(0,0,0,1),rgba(0,0,0,0)),url('https://cdn.dribbble.com/users/1573719/screenshots/15675086/media/460a3198328726158e47eb208f46822e.png?compress=1&resize=1200x900&vertical=top') center center fixed;background-size:100% auto;background-repeat:no-repeat;color:white;display:flex;justify-content:center;flex-direction:column;transition:1s ease-in-out;padding-top:20vh;}");
              client.println(".btn_one {color:white;padding:10px 40px;border-radius:50px;border:2px solid #fff;font-size:18px;font-family: 'Comfortaa', cursive;font-weight:bold;background:transparent;transition:0.4s ease-in-out;margin:30px 10px;}");
              client.println("#tagline {font-size:50px;width:60%;}");
              client.println("#portfolio {width:80%;padding:2% 10%;}");
              client.println("#portfolio div h1 {font-size:40px;background-image: linear-gradient(to left, #FF416C 0%, #FF4B2B 100%);-webkit-background-clip:text;background-clip:text;-webkit-text-fill-color: transparent;background-size:500% 500% !important;-webkit-animation: Gradient 20s ease infinite;-moz-animation: Gradient 20s ease infinite;-o-animation: Gradient 20s ease infinite;animation: Gradient 20s ease infinite;font-family: 'Comfortaa', cursive;}");
              client.println("#title {font-size:40px;background-image: linear-gradient(to left, #FF416C 0%, #FF4B2B 100%);-webkit-background-clip:text;background-clip:text;-webkit-text-fill-color: transparent;background-size:500% 500% !important;-webkit-animation: Gradient 20s ease infinite;-moz-animation: Gradient 20s ease infinite;-o-animation: Gradient 20s ease infinite;animation: Gradient 20s ease infinite;font-family: 'Comfortaa', cursive;}");
              client.println("#links {margin:40px 0px;transition:0.6s ease-in-out;color:#FF4B2B;}");
              client.println("#links a {margin:0px 30px;color:inherit;text-decoration:none;transition:0.4s ease-in-out;padding:5px 8px;border-bottom:2px solid transparent;}");
              client.println("#links a:hover {border-bottom:2px solid #fff;}");
              client.println("#middle {width:100%;height:80vh;background:linear-gradient(0deg,rgba(0,0,0,1),rgba(0,0,0,0)),url('https://cdn.dribbble.com/users/1573719/screenshots/15675086/media/460a3198328726158e47eb208f46822e.png?compress=1&resize=1200x900&vertical=top') center center fixed;background-size:100% auto;background-repeat:no-repeat;color:white;display:flex;justify-content:center;flex-direction:column;transition:1s ease-in-out;padding-top:20vh;}");
              client.println(".btn_one {color:white;padding:10px 40px;border-radius:50px;border:2px solid #fff;font-size:18px;font-family: 'Comfortaa', cursive;font-weight:bold;background:transparent;transition:0.4s ease-in-out;margin:30px 10px;}");
              client.println(".btn_one:hover {background:white;cursor:pointer;color:#000;}");
              client.println("#tagline {font-size:50px;width:60%;}#portfolio {width:80%;padding:2% 10%;}#portfolio div h1 {font-size:40px;background-image: linear-gradient(to left, #FF416C 0%, #FF4B2B 100%);-webkit-background-clip:text;background-clip:text;-webkit-text-fill-color: transparent;background-size:500% 500% !important;-webkit-animation: Gradient 20s ease infinite;-moz-animation: Gradient 20s ease infinite;-o-animation: Gradient 20s ease infinite;animation: Gradient 20s ease infinite;font-family: 'Comfortaa', cursive;}");
              client.println("#portfolio {width:80%;padding:2% 10%;}");
              client.println("#portfolio div h1 {font-size:40px;background-image: linear-gradient(to left, #FF416C 0%, #FF4B2B 100%);-webkit-background-clip:text;background-clip:text;-webkit-text-fill-color: transparent;background-size:500% 500% !important;-webkit-animation: Gradient 20s ease infinite;-moz-animation: Gradient 20s ease infinite;-o-animation: Gradient 20s ease infinite;animation: Gradient 20s ease infinite;font-family: 'Comfortaa', cursive;}");
              client.println("@media (max-width: 800px) {.container td:nth-child(4),.container th:nth-child(4) { display: none; }}");
              client.println("#skills {margin:4vh 0px !important;padding:2vh 0px !important;}");\
              client.println("#work {margin:4vh 0px !important;padding:2vh 0px !important;} #contact {margin:4vh 0px !important;padding:2vh 0px !important;}");
              client.println("#contact form {width:100%;}#contact form input {width:46%;margin:20px 1%;background:transparent;border:0px;border-bottom:2px solid rgba(255,255,255,0.5);padding:8px 10px;font-family: 'Comfortaa', cursive;font-size:18px;transition:0.4s ease-in-out;color:#fff;}#contact form textarea {width:96%;margin:20px 1%;padding:8px 10px;border:0px;border-bottom:2px solid rgba(255,255,255,0.5);padding:8px 10px;font-family: 'Comfortaa', cursive;font-size:18px;background:transparent;resize:none;transition:0.4s ease-in-out;color:#fff;}#contact form input:focus {outline:none;border-bottom:2px solid rgba(255,255,255,1);}#contact form textarea:focus {outline:none;border-bottom:2px solid rgba(255,255,255,1);}::placeholder {color:#fff;}");
              client.println("@media (max-width: 900px){#header {width:94%;padding:15% 3%;}");
              client.println("#title {font-size:30px;}#links {margin:30px 0px;}#links a {margin:0px;}#middle {width:100%;border-radius:0px;height:80vh;background-size:cover;}#tagline {width:90%;font-size:30px;}.btn_one {font-size:14px;padding:8px 20px;}.btn_two {font-size:14px;padding:8px 20px;}#contact form input {width:92%;}#contact form textarea {width:92%;}.btn_social {font-size:14px;margin:10px;padding:10px 11px;}");
              client.println("#footer {width:100%;padding:10vh 0px;text-align:center;font-weight:bold;}#footer a {font-size:18px;background-image: linear-gradient(to left, #FF416C 0%, #FF4B2B 100%);-webkit-background-clip:text;background-clip:text;-webkit-text-fill-color: transparent;background-size:500% 500% !important;-webkit-animation: Gradient 20s ease infinite;-moz-animation: Gradient 20s ease infinite;-o-animation: Gradient 20s ease infinite;animation: Gradient 20s ease infinite;font-family: 'Comfortaa', cursive;text-decoration:none;}");
              client.println("button:focus {outline:none;}");
              client.println("::-webkit-scrollbar {width:5px;height:5px;}::-webkit-scrollbar-track {background: #f1f1f1; }::-webkit-scrollbar-thumb {background: #000; }::-webkit-scrollbar-thumb:hover {background: #555; }");
              client.println("@-webkit-keyframes Gradient {0% {background-position: 0% 50%}50% {background-position: 100% 50%}100% {background-position: 0% 50%}}@-moz-keyframes Gradient {0% {background-position: 0% 50%}50% {background-position: 100% 50%}100% {background-position: 0% 50%}}@keyframes Gradient {0% {background-position: 0% 50%}50% {background-position: 100% 50%}100% {background-position: 0% 50%}");
              client.println("#customers th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #746AB0;color: white;}");
              client.println(".project div {font-weight:normal;}.btn_two {color:#000;padding:10px 40px;border-radius:50px;border:2px solid #fff;font-size:18px;font-family: 'Comfortaa', cursive;font-weight:bold;background:#fff;transition:0.4s ease-in-out;margin:30px 10px;}.btn_two:hover {background:transparent;cursor:pointer;color:#fff;}#details { margin:6vh 0px;}.btn_social {font-size:18px;color:#fff;margin:40px 20px;padding:15px 18px;border-radius:50%;background:#000;transition:0.4s ease-in-out;}.btn_social:hover {color:#000;background:#fff;cursor:pointer;}");
              client.println("table{width:100%;table-layout: fixed;}.tbl-header{background-color: rgba(255,255,255,0.3);}.tbl-content{height:300px;overflow-x:auto;margin-top: 0px;border: 1px solid rgba(255,255,255,0.3);}th{padding: 20px 15px;text-align: left;font-weight: 500;font-size: 12px;color: #fff;text-transform: uppercase;}td{padding: 15px;text-align: left;vertical-align:middle;font-weight: 300;font-size: 12px;color: #fff;border-bottom: solid 1px rgba(255,255,255,0.1);}");
              client.println("#tagline {font-size:50px;width:60%;}");
              client.println(".container th h1 {font-weight: bold;font-size: 1em;text-align: left;color: #185875;}.container td {font-weight: normal;font-size: 1em;-webkit-box-shadow: 0 2px 2px -2px #0E1119;-moz-box-shadow: 0 2px 2px -2px #0E1119;box-shadow: 0 2px 2px -2px #0E1119;}.container {text-align: left;overflow: hidden;width: 80%;margin: 0 auto;display: table;padding: 0 0 8em 0;}.container td, .container th {padding-bottom: 2%;padding-top: 2%;padding-left:2%;  }.container tr:nth-child(odd) {background-color: #323C50;}.container tr:nth-child(even) {background-color: #2C3446;}.container th {background-color: #1F2739;}.container td:first-child { color: #FB667A; }.container tr:hover {background-color: #464A52;-webkit-box-shadow: 0 6px 6px -6px #1c243a;-moz-box-shadow: 0 6px 6px -6px #1c243a;box-shadow: 0 6px 6px -6px #1c243a;}.container td:hover {background-color: #FFF842;color: #403E10;font-weight: bold;box-shadow: #7F7C21 -1px 1px, #7F7C21 -2px 2px, #7F7C21 -3px 3px, #7F7C21 -4px 4px, #7F7C21 -5px 5px, #7F7C21 -6px 6px;transform: translate3d(6px, -6px, 0);transition-delay: 0s;transition-duration: 0.4s;transition-property: all;transition-timing-function: line;}");
              client.println("#customers {font-family: Arial, Helvetica, sans-serif;border-collapse: collapse;width: 100%;}#customers td, #customers th {border: 1px solid #FF4B2B;padding: 8px;}#customers tr {background-color: #ffa739;}#customers th {padding-top: 12px;padding-bottom: 12px;text-align: left;background-color: #746AB0;color: white;}");
              
              
              client.println(".btn_one:hover {background:white;cursor:pointer;color:#000;}</style></head>");
              
              // Web Page Heading

              client.println("<div id='loading'><div id='spinner'></div></div><div id='header' class='animated slideInDown' style='animation-delay:1s;'><div id='title'></div><br><div id='links'><a href='#about'>about </a><a href='#skills'>skills</a><a href='#work' style='margin:0px 60px;'>works</a><a href='#contact'>contact</a></div></div>");
              client.println("<body><center><div id='middle'><div class='text-change-container'><div class='text-change'></div></div><div class='text-change-container'><div class='text-change'></div></div><div id='tagline' class='animated zoomIn' style='animation-delay:1s;'>Welcome to my Website.<br><button class='btn_one'>Nothing Risky over here.</button></div> </div></center>");
              client.println("<div id='portfolio'><div id='about'><h1>About.</h1><div>");
              client.println("<p>");
              client.println("I am a intermediate level hacker, programmer and a blogger I really enjoy hacking and learning the complicated things involved in it I am a white hat hacker not intrested in doing black hat stuff and intrested in growing my knowledge in all possible ways. I learnt all my hacking and my basic skills from online resources mainly youtube and to gain a more indepth understanding on what happens in a industry or what does a Black hat hacker does to gain unauthorized access to your machine I need to learn more and gain more knowledge thats why I left my initial plans in commerce and persuied my dreames on being a hacker i joined Jain Demeed to be university in BCA and I am  currently studying to increase my knowledge.");
              client.println("</p>");
              client.println(" <div id='skills'><h1>skills.</h1><div><p>I dont have much to talk about these are my skills I have gained in my journey so far:<br><ul style='list-style-type:square'><li>Writing articles.</li><li>Hacking networks.</li><li>Various ways to compromise a website</li><li>Information Gathering skills.</li><li>Pentest machines to a certain level.</li><li>I have considerable knowledge in networking and system hardwares.</li><li>Python.</li><li>C language.</li><li>Basic Web-dev.</li></ul><br>These are some of the skills i have gained till now but i am working towards certifications such as CEH, OSCP, Ejpt ,etc.</p></div> </div>");
              client.println("<div id='work'><h1>works.</h1><div class='project'><h2>Blogs</h2><div>");
              client.println("<table id='container'><tr><th>Sl.no</th><th>Name</th><th>discription</th><th>link</th></tr><tr><tr>");
              client.println("<td>1</td><td>Top Resources to Learn Ethical Hacking</td><td>In this article of mine I have discussed the best resourses online from where I learned hacking in the first place and I felt many others who want to learn hacking will be usefull. </td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/top-resources-to-learn-ethical-hacking' target='_blank'>view blog</a></button></td></tr><tr>");
              client.println("<td>2</td><td>How to Protect Hackers From Your Privacy</td><td>Security is important! For the average human, your daily internet habits might not matter. But for hackers, well,  your data is money. Data big or small is valuable. In this blog, Im going to discuss how we can secure our web accounts, web servers, mobiles, Windows systems & Linux systems.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/how-to-protect-hackers-from-your-privacy' target='_blank'>view blog</a></button></td></tr>");
              client.println("<td>3</td><td>Os prefered by hackers</td><td>These are operating systems with the best kernel installed in it and with the solid configs are considered best o/s for a hacker. This is the basic requirement. There is a wide range for selection. We will be discussing five operating systems, there benefits and drawbacks .</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/the-five-linux-operating-systems-hackers-prefer-izf231bw' target='_blank'>view blog</a></button></td></tr><tr><td>4</td><td>Password file to prevent bruteforce attack</td><td>Brute-forcing a really important method that a hacker or a pentester must be aware of and he will use in various places.Password files are the files which contains various passwords and random symbol combination that can be potential password to an account or an server admin login. who knows? the main problem faced by any hacker is how to make this password file more efficient and more productive and he will be having the question that is the password i am searching for is in this file and is he using a weak password</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/great-methods-to-create-a-password-file-to-prevent-brute-force-attacks-vft34sr' target='_blank'>view blog</a></button></td></tr><tr><td>5</td><td>Brute-hacking-framework</td><td>hacking framework complete source+-code for web, wifi, url, sql-injection and doing a complete web scan for starters</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/a-closer-look-at-brute-hacking-framework-with-a-source-code-example-ho3033ql' target='_blank'>view blog</a></button></td></tr><tr><td>6</td><td>intro to metasploit</td><td>The Metasploit Project is a computer security project written in ruby that provides information about security vulnerabilities and aids in penetration testing and IDS signature development. It is owned by Boston, Massachusetts-based security company Rapid7.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/introducing-metasploit-jf1q3474' target='_blank'>view blog</a></button></td></tr><tr>");
              client.println("<td>7</td><td>Installing portable Vbox</td><td>A portable Virtualbox is the portable version of Oracle Virtualbox software. It works similar to VM-ware, but it is completely free. You can install this portable version on your Pendrive preferred space. You can run virtually any OS on this Pendrive without using additional software installation or booting from the Pendrive.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/how-to-set-up-portable-virtualbox-with-kali-linux-pb1535iq'target='_blank'>view blog</a></button></td></tr><tr><td>8</td><td>How to hack into android</td><td>In this article, we will explore how hackers hack into the phones of victims and steal their data for malicious purposes.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/hacking-android-phones-bdk32ze'target='_blank'>view blog</a></button></td></tr><tr><td>9</td><td>More info on DDoS attacks</td><td>DDoS attack or Distributed Denial of Service attack is an attack aiming to destroy the service of a website by crashing its server by sending a lot of packets and requests to the server. The hackers usually use tools like the low orbit ion cannon, ping of death, SYN flood, HTTP flood & more.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/launching-ddos-attacks-using-various-programs-and-methods-6n2a367b'target='_blank'>view blog</a></button></td></tr><tr><td>10</td><td>Dark web</td><td>Dark web is a completely isolated part in the internet and this was first introduced to carryout military operations during the world-war now it is famous for illegal trade and transactions of stolen info of various people's social media acc and bank information's and transactions are mainly carried out via bitcoins or any other crypto currency.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/facts-you-probably-didnt-know-about-the-dark-web-w2j37k4'target='_blank'>view blog</a></button></td></tr><tr><td>11</td><td>Reverse Shell</td><td>reverse shell is a hacking vulnerability in which the hacker executes .php codes or an executable file in which he gets access to the shell of the target system and by which he can install rats or steal any info regarding the his banks or the info regarding the users of the websites and its services ..</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/how-to-run-reverse-shell-for-hacking-in-linux-of5i37ob'target='_blank'>view blog</a></button></td></tr><tr>");
              client.println("<td>12</td><td>Hack wifi like a pro</td><td>Unlike most radio jammers, deauthentication acts in a unique way. The IEEE 802.11 (Wi-Fi) protocol contains the provision for a deauthentication frame. Sending the frame from the access point to a station is called a 'sanctioned technique to inform a rogue station that they have been disconnected from the network'</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/how-to-hack-wifi-like-a-pro-hacker'target='_blank'>view blog</a></button></td></tr><tr><td>13</td><td>Common hacking methods to hack websites</td><td>Hacking is a skill set people even go to any extent to hack a person. Usually if the person has to be hacked there some loopholes in is digital life which are used to control your whole life.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/all-the-methods-you-can-use-to-hack-into-a-website-hs1v3g4t'target='_blank'>view blog</a></button></td></tr><tr><td>14</td><td>Make a Affordable Hackers Pc</td><td>In this article, I am discussing how you can set up a complete hacking lab for the most affordable price possible.For hacking, you need not have a really powerful computer you can start hacking using a really week pc also but in the long run, you should have a really powerful pc to handle the workload such as password cracking, sending & receiving a huge amount of TCP or any protocol packets, etc.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/how-to-customize-your-hacking-set-up-for-the-most-affordable-price-bq5n37es'target='_blank'>view blog</a></button></td></tr><tr><td>15</td><td>Convert android into a hacking server</td><td>For hacking, you need a device with a Linux system - it can be any device that has the potential to run tools according to your requirements. For example, android phones are completely capable of being used as hacking machines as they use Linux.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/hacking-android-phones-bdk32ze'target='_blank'>view blog</a></button></td></tr><tr><td>16</td><td>Crack passwords using hashcat</td><td>Discuss all the various ways you can crack passwords using hascat utility.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/how-to-crack-a-password-using-hashcat'target='_blank'>view blog</a></button></td></tr><tr><td>17</td><td>Hack windows machines like a pro</td><td>Discuss all the various ways you can hack a windows machine.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/how-to-hack-a-windows-machine-like-a-pro-hacker-3e1v37rz'target='_blank'>view blog</a></button></td></tr></tr><tr>");
              client.println("<td>18</td><td>View all my Articles</td><td>List all the article i have written.</td><td><button type='button' class='btn_one'><a href='https://hackernoon.com/u/morpheuslord'target='_blank'>view page</a></button></td></tr></table></div>");
              client.println("<div class='project'><h2>Brute framework</h2><div>This was an inspired tool from Pentestbox tool using this tool you can do a pentest to a certain level and also succeed in it butthis is not ment for complete pentest but a project i did for fun.</div><button class='btn_one'><a href='https://github.com/morpheuslord/'target='_blank'>visit Github</button><button class='btn_one'><a href='https://github.com/morpheuslord/Brute-Hacking-Framework-SourceCode'target='_blank'>View Code</a></button><h2>Youtube</h2><div>This is my youtube channel with all my youtube tutorials in it presently its not much but i will work towards improving it.</div><button class='btn_one'><a href='https://www.youtube.com/channel/UCerUR7wpbXyFmTCMGciOV_w'target='_blank'>View channel</a></button></div>");      
              client.println("</div><div id='contact'><h1>contact.</h1> <div id='title'>MORPHEUSLORD@PROTONMAIL.COM</div><br><div id='details'><a class='btn_social' href='https://hackernoon.com/u/morpheuslord'><i class='fas fa-rss-square'></i></a><a class='btn_social' href='https://www.linkedin.com/in/chiranjeevi-g-33787521a'><i class='fas fa-at'></i></a><a class='btn_social' href='https://twitter.com//morpheuslord2'><i class='fab fa-twitter'></i></a><a class='btn_social' href='https://instagram.com/morpheuslord_9034'><i class='fas fa-hashtag'></i></a><a class='btn_social' href='https://github.com/morpheuslord/'><i class='fab fa-github'></i></a>    </div> </div></div>");
              
              client.println("<script src='index.js' type='text/javascript'></script><script async src='https://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js?client=ca-pub-6909321993621088'crossorigin='anonymous'></script><ins class='adsbygoogle'style='display:block'data-ad-client='ca-pub-6909321993621088'data-ad-slot='6857132369'data-ad-format='auto'data-full-width-responsive='true'></ins><script>(adsbygoogle = window.adsbygoogle || []).push({});</script>");
              client.println("</body></html>");
              
              // The HTTP response ends with another blank line
              client.println();
              // Break out of the while loop
              break;
            }
            else{
              client.println("HTTP/1.1 401 Unauthorized");
              client.println("WWW-Authenticate: Basic realm=\"Secure\"");
              client.println("Content-Type: text/html");
              client.println();
              client.println("<html>Authentication failed</html>");
            }
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
