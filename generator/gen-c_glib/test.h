/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TEST_H
#define TEST_H

#include <thrift/c_glib/processor/thrift_dispatch_processor.h>

#include "generator_types.h"

/* Test service interface */
typedef struct _TestIf TestIf;  /* dummy object */

struct _TestIfInterface
{
  GTypeInterface parent;

  gboolean (*ping) (TestIf *iface, const Request * request, const Response * response, GError **error);
};
typedef struct _TestIfInterface TestIfInterface;

GType test_if_get_type (void);
#define TYPE_TEST_IF (test_if_get_type())
#define TEST_IF(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_IF, TestIf))
#define IS_TEST_IF(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_IF))
#define TEST_IF_GET_INTERFACE(inst) (G_TYPE_INSTANCE_GET_INTERFACE ((inst), TYPE_TEST_IF, TestIfInterface))

gboolean test_if_ping (TestIf *iface, const Request * request, const Response * response, GError **error);

/* Test service client */
struct _TestClient
{
  GObject parent;

  ThriftProtocol *input_protocol;
  ThriftProtocol *output_protocol;
};
typedef struct _TestClient TestClient;

struct _TestClientClass
{
  GObjectClass parent;
};
typedef struct _TestClientClass TestClientClass;

GType test_client_get_type (void);
#define TYPE_TEST_CLIENT (test_client_get_type())
#define TEST_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_CLIENT, TestClient))
#define TEST_CLIENT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), TYPE_TEST_CLIENT, TestClientClass))
#define TEST_IS_CLIENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_CLIENT))
#define TEST_IS_CLIENT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), TYPE_TEST_CLIENT))
#define TEST_CLIENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_CLIENT, TestClientClass))

gboolean test_client_ping (TestIf * iface, const Request * request, const Response * response, GError ** error);
gboolean test_client_send_ping (TestIf * iface, const Request * request, const Response * response, GError ** error);
gboolean test_client_recv_ping (TestIf * iface, GError ** error);
void test_client_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec);
void test_client_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec);

/* Test handler (abstract base class) */
struct _TestHandler
{
  GObject parent;
};
typedef struct _TestHandler TestHandler;

struct _TestHandlerClass
{
  GObjectClass parent;

  gboolean (*ping) (TestIf *iface, const Request * request, const Response * response, GError **error);
};
typedef struct _TestHandlerClass TestHandlerClass;

GType test_handler_get_type (void);
#define TYPE_TEST_HANDLER (test_handler_get_type())
#define TEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_HANDLER, TestHandler))
#define IS_TEST_HANDLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_HANDLER))
#define TEST_HANDLER_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), TYPE_TEST_HANDLER, TestHandlerClass))
#define IS_TEST_HANDLER_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), TYPE_TEST_HANDLER))
#define TEST_HANDLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_HANDLER, TestHandlerClass))

gboolean test_handler_ping (TestIf *iface, const Request * request, const Response * response, GError **error);

/* Test processor */
struct _TestProcessor
{
  ThriftDispatchProcessor parent;

  /* protected */
  TestHandler *handler;
  GHashTable *process_map;
};
typedef struct _TestProcessor TestProcessor;

struct _TestProcessorClass
{
  ThriftDispatchProcessorClass parent;

  /* protected */
  gboolean (*dispatch_call) (ThriftDispatchProcessor *processor,
                             ThriftProtocol *in,
                             ThriftProtocol *out,
                             gchar *fname,
                             gint32 seqid,
                             GError **error);
};
typedef struct _TestProcessorClass TestProcessorClass;

GType test_processor_get_type (void);
#define TYPE_TEST_PROCESSOR (test_processor_get_type())
#define TEST_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TEST_PROCESSOR, TestProcessor))
#define IS_TEST_PROCESSOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TEST_PROCESSOR))
#define TEST_PROCESSOR_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), TYPE_TEST_PROCESSOR, TestProcessorClass))
#define IS_TEST_PROCESSOR_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), TYPE_TEST_PROCESSOR))
#define TEST_PROCESSOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TEST_PROCESSOR, TestProcessorClass))

#endif /* TEST_H */
