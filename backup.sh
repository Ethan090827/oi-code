#! /bin/bash
cp -u -v -r ~/Desktop/hyz /media/noi/54F212CCF212B1EA
cp -u -v -r ~/Desktop/hyz /run/user/1000/gvfs/dav:host=10.66.5.73,port=1145,ssl=false,user=30,prefix=%2Fremote.php%2Fwebdav
cp -u -v ~/.config/Code/User/settings.json /run/user/1000/gvfs/dav:host=10.66.5.73,port=1145,ssl=false,user=30,prefix=%2Fremote.php%2Fwebdav/VSCode_Settings
cp -u -v -r ~/.config/Code/User/snippets /run/user/1000/gvfs/dav:host=10.66.5.73,port=1145,ssl=false,user=30,prefix=%2Fremote.php%2Fwebdav/VSCode_Settings
./start.sh