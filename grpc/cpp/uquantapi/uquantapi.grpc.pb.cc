// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: uquantapi.proto

#include "uquantapi.pb.h"
#include "uquantapi.grpc.pb.h"

#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace uquantapi {

static const char* Greeter_method_names[] = {
  "/uquantapi.Greeter/SayHello",
  "/uquantapi.Greeter/SayHelloAgain",
  "/uquantapi.Greeter/getFutureBars",
};

std::unique_ptr< Greeter::Stub> Greeter::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Greeter::Stub> stub(new Greeter::Stub(channel));
  return stub;
}

Greeter::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SayHello_(Greeter_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_SayHelloAgain_(Greeter_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_getFutureBars_(Greeter_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Greeter::Stub::SayHello(::grpc::ClientContext* context, const ::uquantapi::HelloRequest& request, ::uquantapi::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::HelloReply>* Greeter::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::uquantapi::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHello_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::HelloReply>* Greeter::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::uquantapi::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHello_, context, request, false);
}

::grpc::Status Greeter::Stub::SayHelloAgain(::grpc::ClientContext* context, const ::uquantapi::HelloRequest& request, ::uquantapi::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SayHelloAgain_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::HelloReply>* Greeter::Stub::AsyncSayHelloAgainRaw(::grpc::ClientContext* context, const ::uquantapi::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHelloAgain_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::HelloReply>* Greeter::Stub::PrepareAsyncSayHelloAgainRaw(::grpc::ClientContext* context, const ::uquantapi::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHelloAgain_, context, request, false);
}

::grpc::Status Greeter::Stub::getFutureBars(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::uquantapi::kBarReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getFutureBars_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::kBarReply>* Greeter::Stub::AsyncgetFutureBarsRaw(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::kBarReply>::Create(channel_.get(), cq, rpcmethod_getFutureBars_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::kBarReply>* Greeter::Stub::PrepareAsyncgetFutureBarsRaw(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::kBarReply>::Create(channel_.get(), cq, rpcmethod_getFutureBars_, context, request, false);
}

Greeter::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::uquantapi::HelloRequest, ::uquantapi::HelloReply>(
          std::mem_fn(&Greeter::Service::SayHello), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::uquantapi::HelloRequest, ::uquantapi::HelloReply>(
          std::mem_fn(&Greeter::Service::SayHelloAgain), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Greeter_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Greeter::Service, ::uquantapi::kBarRequest, ::uquantapi::kBarReply>(
          std::mem_fn(&Greeter::Service::getFutureBars), this)));
}

Greeter::Service::~Service() {
}

::grpc::Status Greeter::Service::SayHello(::grpc::ServerContext* context, const ::uquantapi::HelloRequest* request, ::uquantapi::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::SayHelloAgain(::grpc::ServerContext* context, const ::uquantapi::HelloRequest* request, ::uquantapi::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status Greeter::Service::getFutureBars(::grpc::ServerContext* context, const ::uquantapi::kBarRequest* request, ::uquantapi::kBarReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* FutureApi_method_names[] = {
  "/uquantapi.FutureApi/getFutureBars",
};

std::unique_ptr< FutureApi::Stub> FutureApi::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< FutureApi::Stub> stub(new FutureApi::Stub(channel));
  return stub;
}

FutureApi::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_getFutureBars_(FutureApi_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status FutureApi::Stub::getFutureBars(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::uquantapi::kBarReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getFutureBars_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::kBarReply>* FutureApi::Stub::AsyncgetFutureBarsRaw(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::kBarReply>::Create(channel_.get(), cq, rpcmethod_getFutureBars_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::kBarReply>* FutureApi::Stub::PrepareAsyncgetFutureBarsRaw(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::kBarReply>::Create(channel_.get(), cq, rpcmethod_getFutureBars_, context, request, false);
}

FutureApi::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FutureApi_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FutureApi::Service, ::uquantapi::kBarRequest, ::uquantapi::kBarReply>(
          std::mem_fn(&FutureApi::Service::getFutureBars), this)));
}

FutureApi::Service::~Service() {
}

::grpc::Status FutureApi::Service::getFutureBars(::grpc::ServerContext* context, const ::uquantapi::kBarRequest* request, ::uquantapi::kBarReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


static const char* StockApi_method_names[] = {
  "/uquantapi.StockApi/getFutureBars",
};

std::unique_ptr< StockApi::Stub> StockApi::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< StockApi::Stub> stub(new StockApi::Stub(channel));
  return stub;
}

StockApi::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_getFutureBars_(StockApi_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status StockApi::Stub::getFutureBars(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::uquantapi::kBarReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_getFutureBars_, context, request, response);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::kBarReply>* StockApi::Stub::AsyncgetFutureBarsRaw(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::kBarReply>::Create(channel_.get(), cq, rpcmethod_getFutureBars_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::uquantapi::kBarReply>* StockApi::Stub::PrepareAsyncgetFutureBarsRaw(::grpc::ClientContext* context, const ::uquantapi::kBarRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::uquantapi::kBarReply>::Create(channel_.get(), cq, rpcmethod_getFutureBars_, context, request, false);
}

StockApi::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      StockApi_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< StockApi::Service, ::uquantapi::kBarRequest, ::uquantapi::kBarReply>(
          std::mem_fn(&StockApi::Service::getFutureBars), this)));
}

StockApi::Service::~Service() {
}

::grpc::Status StockApi::Service::getFutureBars(::grpc::ServerContext* context, const ::uquantapi::kBarRequest* request, ::uquantapi::kBarReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace uquantapi

