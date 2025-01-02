#! /bin/bash
sudo apt install tree
echo "Desktop & Disk E:"
diff <(tree -i --noreport ~/Desktop/hyz) <(tree -i --noreport /media/noi/54F212CCF212B1EA/hyz)
echo "Desktop & Cloud:"
diff <(tree -i --noreport ~/Desktop/hyz) <(tree -i --noreport /run/user/1000/gvfs/dav:host=10.66.5.73,port=1145,ssl=false,user=30,prefix=%2Fremote.php%2Fwebdav/hyz)
echo "Cloud & Disk E:"
diff <(tree -i --noreport /media/noi/54F212CCF212B1EA/hyz) <(tree -i --noreport /run/user/1000/gvfs/dav:host=10.66.5.73,port=1145,ssl=false,user=30,prefix=%2Fremote.php%2Fwebdav/hyz)
