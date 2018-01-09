#include "uBEE.h"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <algorithm>
#include <vector>

namespace uBEE
{

HubApi::HubApi()
{
}

void HubApi::Init()
{
  memset(URL,'\0',256);
  sprintf(URL,"3001");
  port = 3001;
}

void HubApi::S_onMessage()
{
  h.onMessage([this](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
    char tmp[256];
    memcpy(tmp, message, length);
    tmp[length] = 0;
    message[0] = '0';
    uBEE::ErrLog(1000,"kkkk",1,(const char*)message,length);
    message[length-1] = 0;
    printf("Server onMessage receive: %s\n", message);
    ws->send(message, length, opCode);
    std::printf("Server onMessage send: %s\n", tmp);
  });
}

void HubApi::S_onConnection()
{
  h.onConnection([this](uWS::WebSocket<uWS::SERVER> *ws, uWS::HttpRequest req) {
    //ws->send("--server--");
    std::cout <<"Server onConnection send: --server--" << std::endl;
  });
}

void HubApi::S_onDisconnection()
{
  h.onDisconnection([this](uWS::WebSocket<uWS::SERVER> *ws, int code, char *message, size_t length) {
    std::cout << "onDisconnection !!" << std::endl;
    std::cout << message << std::endl;
  });
}

void HubApi::S_onPong()
{
  h.onPong([this](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length) {
    std::cout<< "ok ping\n";
  });
  h.getDefaultGroup<uWS::SERVER>().startAutoPing(2000);
}

void HubApi::S_Listen()
{
  bool k = h.listen(port) ;
  if(!k) {
    std::cout << " listen error !!" << std::endl;
    exit(-1);
  }
}
void HubApi::Run()
{
  h.run();
}

void  HubApi::Start()
{
  HubApi::S_onDisconnection();
  HubApi::S_onConnection();
  HubApi::S_onMessage();
  HubApi::S_onPong();
  HubApi::S_Listen();
  HubApi::Run();
}

} // namespace
