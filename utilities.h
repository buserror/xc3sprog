#include <sys/time.h>
#include <memory>
#include "bitfile.h"

#include "devicedb.h"
#include "jtag.h"
#include "cabledb.h"

class DeviceDB;


void detect_chain(Jtag *jtag, DeviceDB *db);
int getIO(std::auto_ptr<IOBase> *io, struct cable_t*,  
          char const *dev, const char *serial, bool verbose, bool ftd2xx);
const char *getCableName(int type);
#define OSNAME_LEN	64
void get_os_name(char *buf, int buflen);


/* Utility class for measuring execution times. */
class Timer
{
 private:
  struct timeval m_tv;

 public:
  // Construct and start timer.
  Timer()
  {
    start();
  }

  // Restart timer from zero.
  void start()
  {
    gettimeofday(&m_tv, NULL);
  }

  // Return number of seconds elapsed since starting the timer.
  double elapsed() const
  {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + 1.0e-6 * t.tv_usec - m_tv.tv_sec - 1.0e-6 * m_tv.tv_usec;
  }
};

