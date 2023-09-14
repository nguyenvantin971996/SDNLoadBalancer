import iperf3
import time
while True:
    client = iperf3.Client()
    client.duration = 2 # Measurement time [sec]
    client.bind_address = '10.0.0.1'
    client.server_hostname = '10.0.0.2' # Server's IP address
    print('Connecting to {0}:{1}'.format(client.server_hostname, client.port))
    result = client.run()
    if result.error:
        print(result.error)
    else:
        print('')
        print('Test completed:')
        # print('  started at         {0}'.format(result.time))
        # print('  bytes transmitted  {0}'.format(result.sent_bytes))
        # print('  retransmits        {0}'.format(result.retransmits))
        # print('  avg cpu load       {0}%\n'.format(result.local_cpu_total))

        # print('Average transmitted data in all sorts of networky formats:')
        # print('  bits per second      (bps)   {0}'.format(result.sent_bps))
        # print('  Kilobits per second  (kbps)  {0}'.format(result.sent_kbps))
        print('  Megabits per second  (Mbps)  {0}'.format(result.sent_Mbps))
        # print('  KiloBytes per second (kB/s)  {0}'.format(result.sent_kB_s))
        # print('  MegaBytes per second (MB/s)  {0}'.format(result.sent_MB_s))
    time.sleep(10)