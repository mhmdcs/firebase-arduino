#ifndef FIREBASE_HTTP_CLIENT_H
#define FIREBASE_HTTP_CLIENT_H

#include <string>

#include "Arduino.h"
#include "Stream.h"

struct HttpStatus {
  static const int TEMPORARY_REDIRECT = 307;
};

class FirebaseHttpClient {
 public:
  static FirebaseHttpClient* create();

  virtual void setReuseConnection(bool reuse) = 0;
  virtual void begin(const std::string& url) = 0;
  virtual void begin(const std::string& host, const std::string& path) = 0;

  virtual void end() = 0;

  virtual void addHeader(const std::string& name, const std::string& value) = 0;
  virtual void collectHeaders(const char* header_keys[],
                              const int header_key_count) = 0;
  virtual std::string header(const std::string& name) = 0;

  virtual int sendRequest(const std::string& method, const std::string& data) = 0;

  virtual std::string getString() = 0;

  virtual Stream* getStreamPtr() = 0;

  virtual std::string errorToString(int error_code) = 0;

  virtual bool connected() = 0;

 protected:
  static const uint16_t kFirebasePort = 443;
};

static const char kFirebaseFingerprint[] =
      "6E:F3:55:47:6D:F1:0E:5B:2B:04:F2:F8:C0:8B:E8:05:65:0F:1A:C1"; // 2021-11 for https://miyahv3-default-rtdb.firebaseio.com/

#endif  // FIREBASE_HTTP_CLIENT_H
