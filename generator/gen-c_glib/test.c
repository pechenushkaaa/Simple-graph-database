/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include <string.h>
#include <thrift/c_glib/thrift.h>
#include <thrift/c_glib/thrift_application_exception.h>
#include "test.h"

gboolean
test_if_ping (TestIf *iface, Response ** _return, const Request * request, GError **error)
{
  return TEST_IF_GET_INTERFACE (iface)->ping (iface, _return, request, error);
}

GType
test_if_get_type (void)
{
  static GType type = 0;
  if (type == 0)
  {
    static const GTypeInfo type_info =
    {
      sizeof (TestIfInterface),
      NULL,  /* base_init */
      NULL,  /* base_finalize */
      NULL,  /* class_init */
      NULL,  /* class_finalize */
      NULL,  /* class_data */
      0,     /* instance_size */
      0,     /* n_preallocs */
      NULL,  /* instance_init */
      NULL   /* value_table */
    };
    type = g_type_register_static (G_TYPE_INTERFACE,
                                   "TestIf",
                                   &type_info, 0);
  }
  return type;
}

static void 
test_if_interface_init (TestIfInterface *iface);

G_DEFINE_TYPE_WITH_CODE (TestClient, test_client,
                         G_TYPE_OBJECT, 
                         G_IMPLEMENT_INTERFACE (TYPE_TEST_IF,
                                                test_if_interface_init))

enum _TestClientProperties
{
  PROP_0,
  PROP_TEST_CLIENT_INPUT_PROTOCOL,
  PROP_TEST_CLIENT_OUTPUT_PROTOCOL
};

void
test_client_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  TestClient *client = TEST_CLIENT (object);

  THRIFT_UNUSED_VAR (pspec);

  switch (property_id)
  {
    case PROP_TEST_CLIENT_INPUT_PROTOCOL:
      client->input_protocol = g_value_get_object (value);
      break;
    case PROP_TEST_CLIENT_OUTPUT_PROTOCOL:
      client->output_protocol = g_value_get_object (value);
      break;
  }
}

void
test_client_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  TestClient *client = TEST_CLIENT (object);

  THRIFT_UNUSED_VAR (pspec);

  switch (property_id)
  {
    case PROP_TEST_CLIENT_INPUT_PROTOCOL:
      g_value_set_object (value, client->input_protocol);
      break;
    case PROP_TEST_CLIENT_OUTPUT_PROTOCOL:
      g_value_set_object (value, client->output_protocol);
      break;
  }
}

gboolean test_client_send_ping (TestIf * iface, const Request * request, GError ** error)
{
  gint32 cseqid = 0;
  ThriftProtocol * protocol = TEST_CLIENT (iface)->output_protocol;

  if (thrift_protocol_write_message_begin (protocol, "ping", T_CALL, cseqid, error) < 0)
    return FALSE;

  {
    gint32 ret;
    gint32 xfer = 0;

    
    if ((ret = thrift_protocol_write_struct_begin (protocol, "ping_args", error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_protocol_write_field_begin (protocol, "request", T_STRUCT, 1, error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_struct_write (THRIFT_STRUCT (request), protocol, error)) < 0)
      return 0;
    xfer += ret;

    if ((ret = thrift_protocol_write_field_end (protocol, error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_protocol_write_field_stop (protocol, error)) < 0)
      return 0;
    xfer += ret;
    if ((ret = thrift_protocol_write_struct_end (protocol, error)) < 0)
      return 0;
    xfer += ret;

  }

  if (thrift_protocol_write_message_end (protocol, error) < 0)
    return FALSE;
  if (!thrift_transport_flush (protocol->transport, error))
    return FALSE;
  if (!thrift_transport_write_end (protocol->transport, error))
    return FALSE;

  return TRUE;
}

gboolean test_client_recv_ping (TestIf * iface, Response ** _return, GError ** error)
{
  gint32 rseqid;
  gchar * fname = NULL;
  ThriftMessageType mtype;
  ThriftProtocol * protocol = TEST_CLIENT (iface)->input_protocol;
  ThriftApplicationException *xception;

  if (thrift_protocol_read_message_begin (protocol, &fname, &mtype, &rseqid, error) < 0) {
    if (fname) g_free (fname);
    return FALSE;
  }

  if (mtype == T_EXCEPTION) {
    if (fname) g_free (fname);
    xception = g_object_new (THRIFT_TYPE_APPLICATION_EXCEPTION, NULL);
    thrift_struct_read (THRIFT_STRUCT (xception), protocol, NULL);
    thrift_protocol_read_message_end (protocol, NULL);
    thrift_transport_read_end (protocol->transport, NULL);
    g_set_error (error, THRIFT_APPLICATION_EXCEPTION_ERROR,xception->type, "application error: %s", xception->message);
    g_object_unref (xception);
    return FALSE;
  } else if (mtype != T_REPLY) {
    if (fname) g_free (fname);
    thrift_protocol_skip (protocol, T_STRUCT, NULL);
    thrift_protocol_read_message_end (protocol, NULL);
    thrift_transport_read_end (protocol->transport, NULL);
    g_set_error (error, THRIFT_APPLICATION_EXCEPTION_ERROR, THRIFT_APPLICATION_EXCEPTION_ERROR_INVALID_MESSAGE_TYPE, "invalid message type %d, expected T_REPLY", mtype);
    return FALSE;
  } else if (strncmp (fname, "ping", 4) != 0) {
    thrift_protocol_skip (protocol, T_STRUCT, NULL);
    thrift_protocol_read_message_end (protocol,error);
    thrift_transport_read_end (protocol->transport, error);
    g_set_error (error, THRIFT_APPLICATION_EXCEPTION_ERROR, THRIFT_APPLICATION_EXCEPTION_ERROR_WRONG_METHOD_NAME, "wrong method name %s, expected ping", fname);
    if (fname) g_free (fname);
    return FALSE;
  }
  if (fname) g_free (fname);

  {
    gint32 ret;
    gint32 xfer = 0;
    gchar *name = NULL;
    ThriftType ftype;
    gint16 fid;
    guint32 len = 0;
    gpointer data = NULL;
    

    /* satisfy -Wall in case these aren't used */
    THRIFT_UNUSED_VAR (len);
    THRIFT_UNUSED_VAR (data);

    /* read the struct begin marker */
    if ((ret = thrift_protocol_read_struct_begin (protocol, &name, error)) < 0)
    {
      if (name) g_free (name);
      return 0;
    }
    xfer += ret;
    if (name) g_free (name);
    name = NULL;

    /* read the struct fields */
    while (1)
    {
      /* read the beginning of a field */
      if ((ret = thrift_protocol_read_field_begin (protocol, &name, &ftype, &fid, error)) < 0)
      {
        if (name) g_free (name);
        return 0;
      }
      xfer += ret;
      if (name) g_free (name);
      name = NULL;

      /* break if we get a STOP field */
      if (ftype == T_STOP)
      {
        break;
      }

      switch (fid)
      {
        case 0:
          if (ftype == T_STRUCT)
          {
            if ((ret = thrift_struct_read (THRIFT_STRUCT (*_return), protocol, error)) < 0)
            {
              return 0;
            }
            xfer += ret;
          } else {
            if ((ret = thrift_protocol_skip (protocol, ftype, error)) < 0)
              return 0;
            xfer += ret;
          }
          break;
        default:
          if ((ret = thrift_protocol_skip (protocol, ftype, error)) < 0)
            return 0;
          xfer += ret;
          break;
      }
      if ((ret = thrift_protocol_read_field_end (protocol, error)) < 0)
        return 0;
      xfer += ret;
    }

    if ((ret = thrift_protocol_read_struct_end (protocol, error)) < 0)
      return 0;
    xfer += ret;

  }

  if (thrift_protocol_read_message_end (protocol, error) < 0)
    return FALSE;

  if (!thrift_transport_read_end (protocol->transport, error))
    return FALSE;

  return TRUE;
}

gboolean test_client_ping (TestIf * iface, Response ** _return, const Request * request, GError ** error)
{
  if (!test_client_send_ping (iface, request, error))
    return FALSE;
  if (!test_client_recv_ping (iface, _return, error))
    return FALSE;
  return TRUE;
}

static void
test_if_interface_init (TestIfInterface *iface)
{
  iface->ping = test_client_ping;
}

static void
test_client_init (TestClient *client)
{
  client->input_protocol = NULL;
  client->output_protocol = NULL;
}

static void
test_client_class_init (TestClientClass *cls)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (cls);
  GParamSpec *param_spec;

  gobject_class->set_property = test_client_set_property;
  gobject_class->get_property = test_client_get_property;

  param_spec = g_param_spec_object ("input_protocol",
                                    "input protocol (construct)",
                                    "Set the client input protocol",
                                    THRIFT_TYPE_PROTOCOL,
                                    G_PARAM_READWRITE);
  g_object_class_install_property (gobject_class,
                                   PROP_TEST_CLIENT_INPUT_PROTOCOL, param_spec);

  param_spec = g_param_spec_object ("output_protocol",
                                    "output protocol (construct)",
                                    "Set the client output protocol",
                                    THRIFT_TYPE_PROTOCOL,
                                    G_PARAM_READWRITE);
  g_object_class_install_property (gobject_class,
                                   PROP_TEST_CLIENT_OUTPUT_PROTOCOL, param_spec);
}

static void
test_handler_test_if_interface_init (TestIfInterface *iface);

G_DEFINE_TYPE_WITH_CODE (TestHandler, 
                         test_handler,
                         G_TYPE_OBJECT,
                         G_IMPLEMENT_INTERFACE (TYPE_TEST_IF,
                                                test_handler_test_if_interface_init))

gboolean test_handler_ping (TestIf * iface, Response ** _return, const Request * request, GError ** error)
{
  g_return_val_if_fail (IS_TEST_HANDLER (iface), FALSE);

  return TEST_HANDLER_GET_CLASS (iface)->ping (iface, _return, request, error);
}

static void
test_handler_test_if_interface_init (TestIfInterface *iface)
{
  iface->ping = test_handler_ping;
}

static void
test_handler_init (TestHandler *self)
{
  THRIFT_UNUSED_VAR (self);
}

static void
test_handler_class_init (TestHandlerClass *cls)
{
  cls->ping = NULL;
}

enum _TestProcessorProperties
{
  PROP_TEST_PROCESSOR_0,
  PROP_TEST_PROCESSOR_HANDLER
};

G_DEFINE_TYPE (TestProcessor,
               test_processor,
               THRIFT_TYPE_DISPATCH_PROCESSOR)

typedef gboolean (* TestProcessorProcessFunction) (TestProcessor *, 
                                                   gint32,
                                                   ThriftProtocol *,
                                                   ThriftProtocol *,
                                                   GError **);

typedef struct
{
  gchar *name;
  TestProcessorProcessFunction function;
} test_processor_process_function_def;

static gboolean
test_processor_process_ping (TestProcessor *,
                             gint32,
                             ThriftProtocol *,
                             ThriftProtocol *,
                             GError **);

static test_processor_process_function_def
test_processor_process_function_defs[1] = {
  {
    "ping",
    test_processor_process_ping
  }
};

static gboolean
test_processor_process_ping (TestProcessor *self,
                             gint32 sequence_id,
                             ThriftProtocol *input_protocol,
                             ThriftProtocol *output_protocol,
                             GError **error)
{
  gboolean result = TRUE;
  ThriftTransport * transport;
  ThriftApplicationException *xception;
  TestPingArgs * args =
    g_object_new (TYPE_TEST_PING_ARGS, NULL);

  g_object_get (input_protocol, "transport", &transport, NULL);

  if ((thrift_struct_read (THRIFT_STRUCT (args), input_protocol, error) != -1) &&
      (thrift_protocol_read_message_end (input_protocol, error) != -1) &&
      (thrift_transport_read_end (transport, error) != FALSE))
  {
    Request * request;
    Response * return_value;
    TestPingResult * result_struct;

    g_object_get (args,
                  "request", &request,
                  NULL);

    g_object_unref (transport);
    g_object_get (output_protocol, "transport", &transport, NULL);

    result_struct = g_object_new (TYPE_TEST_PING_RESULT, NULL);
    g_object_get (result_struct, "success", &return_value, NULL);

    if (test_handler_ping (TEST_IF (self->handler),
                           &return_value,
                           request,
                           error) == TRUE)
    {
      g_object_set (result_struct, "success", return_value, NULL);
      if (return_value != NULL)
        g_object_unref (return_value);

      result =
        ((thrift_protocol_write_message_begin (output_protocol,
                                               "ping",
                                               T_REPLY,
                                               sequence_id,
                                               error) != -1) &&
         (thrift_struct_write (THRIFT_STRUCT (result_struct),
                               output_protocol,
                               error) != -1));
    }
    else
    {
      if (*error == NULL)
        g_warning ("Test.ping implementation returned FALSE "
                   "but did not set an error");

      xception =
        g_object_new (THRIFT_TYPE_APPLICATION_EXCEPTION,
                      "type",    *error != NULL ? (*error)->code :
                                 THRIFT_APPLICATION_EXCEPTION_ERROR_UNKNOWN,
                      "message", *error != NULL ? (*error)->message : NULL,
                      NULL);
      g_clear_error (error);

      result =
        ((thrift_protocol_write_message_begin (output_protocol,
                                               "ping",
                                               T_EXCEPTION,
                                               sequence_id,
                                               error) != -1) &&
         (thrift_struct_write (THRIFT_STRUCT (xception),
                               output_protocol,
                               error) != -1));

      g_object_unref (xception);
    }

    if (request != NULL)
      g_object_unref (request);
    g_object_unref (result_struct);

    if (result == TRUE)
      result =
        ((thrift_protocol_write_message_end (output_protocol, error) != -1) &&
         (thrift_transport_write_end (transport, error) != FALSE) &&
         (thrift_transport_flush (transport, error) != FALSE));
  }
  else
    result = FALSE;

  g_object_unref (transport);
  g_object_unref (args);

  return result;
}

static gboolean
test_processor_dispatch_call (ThriftDispatchProcessor *dispatch_processor,
                              ThriftProtocol *input_protocol,
                              ThriftProtocol *output_protocol,
                              gchar *method_name,
                              gint32 sequence_id,
                              GError **error)
{
  test_processor_process_function_def *process_function_def;
  gboolean dispatch_result = FALSE;

  TestProcessor *self = TEST_PROCESSOR (dispatch_processor);
  ThriftDispatchProcessorClass *parent_class =
    g_type_class_peek_parent (TEST_PROCESSOR_GET_CLASS (self));

  process_function_def = g_hash_table_lookup (self->process_map, method_name);
  if (process_function_def != NULL)
  {
    g_free (method_name);
    dispatch_result = (*process_function_def->function) (self,
                                                         sequence_id,
                                                         input_protocol,
                                                         output_protocol,
                                                         error);
  }
  else
  {
    dispatch_result = parent_class->dispatch_call (dispatch_processor,
                                                   input_protocol,
                                                   output_protocol,
                                                   method_name,
                                                   sequence_id,
                                                   error);
  }

  return dispatch_result;
}

static void
test_processor_set_property (GObject *object,
                             guint property_id,
                             const GValue *value,
                             GParamSpec *pspec)
{
  TestProcessor *self = TEST_PROCESSOR (object);

  switch (property_id)
  {
    case PROP_TEST_PROCESSOR_HANDLER:
      if (self->handler != NULL)
        g_object_unref (self->handler);
      self->handler = g_value_get_object (value);
      g_object_ref (self->handler);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
  }
}

static void
test_processor_get_property (GObject *object,
                             guint property_id,
                             GValue *value,
                             GParamSpec *pspec)
{
  TestProcessor *self = TEST_PROCESSOR (object);

  switch (property_id)
  {
    case PROP_TEST_PROCESSOR_HANDLER:
      g_value_set_object (value, self->handler);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
      break;
  }
}

static void
test_processor_dispose (GObject *gobject)
{
  TestProcessor *self = TEST_PROCESSOR (gobject);

  if (self->handler != NULL)
  {
    g_object_unref (self->handler);
    self->handler = NULL;
  }

  G_OBJECT_CLASS (test_processor_parent_class)->dispose (gobject);
}

static void
test_processor_finalize (GObject *gobject)
{
  TestProcessor *self = TEST_PROCESSOR (gobject);

  thrift_safe_hash_table_destroy (self->process_map);

  G_OBJECT_CLASS (test_processor_parent_class)->finalize (gobject);
}

static void
test_processor_init (TestProcessor *self)
{
  guint index;

  self->handler = NULL;
  self->process_map = g_hash_table_new (g_str_hash, g_str_equal);

  for (index = 0; index < 1; index += 1)
    g_hash_table_insert (self->process_map,
                         test_processor_process_function_defs[index].name,
                         &test_processor_process_function_defs[index]);
}

static void
test_processor_class_init (TestProcessorClass *cls)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (cls);
  ThriftDispatchProcessorClass *dispatch_processor_class =
    THRIFT_DISPATCH_PROCESSOR_CLASS (cls);
  GParamSpec *param_spec;

  gobject_class->dispose = test_processor_dispose;
  gobject_class->finalize = test_processor_finalize;
  gobject_class->set_property = test_processor_set_property;
  gobject_class->get_property = test_processor_get_property;

  dispatch_processor_class->dispatch_call = test_processor_dispatch_call;
  cls->dispatch_call = test_processor_dispatch_call;

  param_spec = g_param_spec_object ("handler",
                                    "Service handler implementation",
                                    "The service handler implementation "
                                    "to which method calls are dispatched.",
                                    TYPE_TEST_HANDLER,
                                    G_PARAM_READWRITE);
  g_object_class_install_property (gobject_class,
                                   PROP_TEST_PROCESSOR_HANDLER,
                                   param_spec);
}
