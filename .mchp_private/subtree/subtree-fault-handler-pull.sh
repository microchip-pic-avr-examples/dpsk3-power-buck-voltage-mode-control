#!/bin/sh
echo $SSH_AUTH_SOCK
cd ../../
echo Pulling changes from subtree 'subrepo-fault' branch 'main' into recently checked out working branch...
git subtree pull --prefix="dpsk_buck_vmc.X/sources/fault_handler/drivers" subrepo-fault main --squash
echo Pull complete
echo
echo Press Enter to exit
read
