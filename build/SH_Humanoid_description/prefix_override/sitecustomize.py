import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/sejong/WS/SH_Humanoid/SH_ws/install/SH_Humanoid_description'
