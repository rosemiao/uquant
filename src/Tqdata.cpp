#include <uWS/uWS.h>
#include <uBEE.h>
//#include <unistd.h>
#include <iostream>

#pragma comment(lib, "uWS.lib")

int main()
{
  uWS::Hub h;

  // --------------------------------------------------------------------------------------------
  // 服务端接收到包后原封不动返回
  h.onConnection([](uWS::WebSocket<uWS::SERVER> *ws, uWS::HttpRequest req) {
    //ws->send("--server--");
    std::cout <<"Server onConnection send: --server--" << std::endl;
  });

  h.onMessage([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length, uWS::OpCode opCode) {
    if(length>0) {
      message[length] = 0;
      uBEE::SaveBin("../tick/tick.json",(const char*)message,length);
      uBEE::Tqjson(message);
      //uBEE::ErrLog(1000,"json error!",1,0,0);
      //uBEE::ErrLog(1000,"kkkk",1,(const char*)message,length);
      //printf("Server onMessage receive: %s\n", message);
    }
    //ws->send(message, length, opCode);
    //std::printf("Server onMessage send: %s\n", tmp);
  });

  bool k = h.listen(3000) ;
  if(!k) {
    std::cout << " listen error !!" << std::endl;
  }
  // --------------------------------------------------------------------------------------------

  // 客户端连上后发送hello
  h.onConnection([](uWS::WebSocket<uWS::CLIENT> *ws, uWS::HttpRequest req) {
    ws->send("--client0000--");
    std::cout <<"Client onConnection send: --client00--" << std::endl;
  });

  // 客户端打印接收到的消息
  h.onMessage([](uWS::WebSocket<uWS::CLIENT> *ws, char *message, size_t length, uWS::OpCode opCode) {
    char tmp[256];
    memcpy(tmp, message, length);
    tmp[length] = 0;
    printf("Client onMessage receive: %s\n", tmp);
    message[0] = '0';
    ws->send(message, length, opCode);
    printf("Client onMessage send: %s\n", tmp);
    //usleep(1000);

    //ws->close();
  });
  h.onPong([](uWS::WebSocket<uWS::SERVER> *ws, char *message, size_t length) {

    std::cout<< "ok ping\n";

  });
  h.getDefaultGroup<uWS::SERVER>().startAutoPing(2000);

  //h.connect("ws://localhost:3000");
  // --------------------------------------------------------------------------------------------

  h.run();
}