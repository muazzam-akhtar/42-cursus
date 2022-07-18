To check for readline leaks and fd leaks with suppression file, we have vg.sup which can filter readline memory leaks but prints execve leaks to give you the general idea about the leaks. all you need is to get a copy of leak.sh and vg.sup and run them in docker. 

Good Luck :D
