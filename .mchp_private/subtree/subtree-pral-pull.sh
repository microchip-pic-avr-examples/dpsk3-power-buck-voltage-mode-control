#!/bin/sh
echo $SSH_AUTH_SOCK
cd ../../
git subtree pull --prefix="dpsk_vmc.X/sources/common/p33c_pral" subrepo-pral main --squash 
echo Press Enter to exit
read
