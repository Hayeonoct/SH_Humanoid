import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/sejong/Desktop/SH_ws/install/SH_Humanoid_description'
