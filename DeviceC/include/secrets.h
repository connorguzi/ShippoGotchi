#include <pgmspace.h>


// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAKoHorp2dosnsJNGOwSEkhLdAr0BMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDA1MDEwMDQ2
MzlaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQC2UZKhgWob6E8rEIOe
boKui15n7xz27l+DtCxtMltCR0hJMBp/EkiY8hBdoksAHvtLvjWt8DiT8eaMQ9FW
TlGNEW8O8u+4s9jS1POXazfBeJadQmo9y2KtUWFfVwG7tYvrNLH4nCwGr9EVB6Do
0YYLK9In7K8Bd5gFZvhjErLaS99hcf0B6pWaxtLrdWL5BsiOZ7aYbJmVOcex6Pxw
8mPqt5nUSFN3UjmzgyHji5v9Fp/0pgDykvNUE0ImuIYdSkXNU4GZZ7qwjvcLoRxJ
nPIj0pZCTbTeEwcZwkc2VJDpRmTD4lxLVxhwpOLUSh62Sl5OaYfUb81kvIsAeh34
fQgFAgMBAAGjYDBeMB8GA1UdIwQYMBaAFOOpYhZ7FAun9ekmfz2++CxhXpcRMB0G
A1UdDgQWBBSk8IBqpxe/gjAeU0yPUZM7AcPPzzAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAjTjFIaMHncRsJI8oDY1Tcr3r
4L5GHQl4Hda+R7F1G1pHZb72QoBxtNV5FAqv5Z1iqweXjhbXlyHnA2OGDCF190OM
yKhdc+CAqGGGh5/ZPXMq/MB/S2vWYxZ+M1klGTSdwHyZ2dUx3CqNfOh8V8xJkCLr
t4t1xflTDtx0VmEB9tSQAHxPqNX+rQvPIqsD21ocoKNLtt1xLAfRfTtNpTQNMZiw
NH3epJkzo4AASBjYzSvFjyKDnQGrxgC/w+4nx6DAOhztnAfWC7AKYYe5I8U7rrJi
JFxptUfFLS530gDTakonHifjiVW7CsJ+M+Jms+FaVwwXnA7AOK/61rb7pQDl9w==
-----END CERTIFICATE-----

)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAtlGSoYFqG+hPKxCDnm6CroteZ+8c9u5fg7QsbTJbQkdISTAa
fxJImPIQXaJLAB77S741rfA4k/HmjEPRVk5RjRFvDvLvuLPY0tTzl2s3wXiWnUJq
PctirVFhX1cBu7WL6zSx+JwsBq/RFQeg6NGGCyvSJ+yvAXeYBWb4YxKy2kvfYXH9
AeqVmsbS63Vi+QbIjme2mGyZlTnHsej8cPJj6reZ1EhTd1I5s4Mh44ub/Raf9KYA
8pLzVBNCJriGHUpFzVOBmWe6sI73C6EcSZzyI9KWQk203hMHGcJHNlSQ6UZkw+Jc
S1cYcKTi1EoetkpeTmmH1G/NZLyLAHod+H0IBQIDAQABAoIBAC2tJCJITPAu9F6i
pYb0wtK94eoCEuyebdmOMy8sVYa2WxrS7WB2kS+YPZdnyIiAOo8QWVx5eYM/MHZl
qzWHK5E/E+bX4E0S6bhwV5LQ7sgO0RUXBYzzvoYThGShZLLFWgeUTR4u6izGsYgm
QB70FzQHR4BvIK0qbDC2SnZvwdVEjqLCjUAIsbpDC+DKNM+Zu1SDIIPIPHI6LODZ
ogklohSR5S/jDjyRfZ8te9GkoGVrJNPBEXkSbQzatTT+j9jKCJyMUuYkps+e8Ami
2aCq6njUOS6h2TIRq1ECE/3gmHWQeR40580oAZotiUNflyB9gBC4h4iFuohTkSYA
Wis67AECgYEA35RqluC6VasleHaEVB5/qHV2L6N0ox8dtyLXGsYubokBRmW8xqUz
Ju4FVV9VMS/N6EFR7tydq7uGxAWFB0jCWzoGIOyzybYn9qjo8TIc0JkWtqVEBgJW
B7/ksvI0so5IsPatQU/TlK1l/NyRfYaxN26xB6ClF4fJXCaZ2IJVWwUCgYEA0MF8
9cxG6H+fgud6FYOodiTpJ22TAMKfvCEj9D19C0DwWKyMq7a7JKkI8HAPp9e42WVP
J918kR830DGDf7akvTXIx2aoC6q3la7HBenC+G48rSE5RYWsmsYoxyR600RqUawn
Fp2nnPy26pGRFNAK5nISFjGO4lxlFqjVFuVKiQECgYBIxVLoJt8fUSRSEClEA+VD
HHBKUyZ8jX0rhYCD62tjeN5cXnLSKST8D87Wmb/t0YRwiwoy98WuBsx3cuB4nXr9
HGawQrrF9a8OPq4LC2eLkbht3F7Goe4EebXjdKgoUd1hE/kSX/wa0VF3uwbz12pJ
A5NFS0lQ3lZw0vOSH+HOTQKBgHxaxpWlmpflbqAMRC2MwE2gr0NNgsRxK7ZmB4T3
HAYYKRSptSKVN+Yey7RvDORvHS5jq0OULSBF+HmNBUiPBJOx9mjSPki06afA9c4P
8pULFhoMMJG5j5ijcqcuk/xGRQ9h/eb7A14BLPWOwV4kkFm2mg+edf9iCtX0vPtm
m4ABAoGAb4+0W1Cajl+LCA12Q+HOHfEJgBkYAXI4Y5XeZS9C9yaavou8e7VsmjA2
8ZAzn+HMaqfMiqkVcWx7pl8lvqMlYlx+9dcMD4ETgP15MggW9i6/2bQtHOq1ngmk
NEHDLNCQgjHvu6xzQsoQldbhS006lCmLif7ozsnr8eeb2f4Qjwc=
-----END RSA PRIVATE KEY-----

)KEY";