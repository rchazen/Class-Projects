FREEGLUTAPP
-----------

This is a demo project to start implementing OpenGL applications
using freeglut. 

Linux Systems:
 - Type make to compile the application
 - The makefile will compile all .cpp files in the folder
 - Edit the makefile to change the name of the executable

Windows with Linux Shells:
 - Visual Studio Code and Linux shell is required 
 - Make sure the Linux shell terminal is open
 - Type make to compile the application
 - The makefile will compile all .cpp files in the folder
 - To generate the OpenGL window download the Windows X Server: https://sourceforge.net/projects/vcxsrv/
 - Run the application
 - Type echo "export DISPLAY=127.0.0.1:0.0" >> ~/.bashrc in the Linux terminal
 - Type source ~/.bashrc in the Linux Terminal
 - Run the executable file (./glutapp)
 
macOS:
 - Visual Studio Code and Linux shell is required
 - Ensure that the paths in the header files are appropriate
 - Type make to compile the application
 - Run the executable file (./glutapp)

Notes:
 - The provided freeglut library is only used in Windows; 
   in Linux and OS X the compiler will seek for the header
   files and libraries in the default development folders.

 - If glut is not recognized, make sure freeglut is installed 
   via the sudo apt-get install freeglut3-dev command.
   
 - On macOS, you can compile in the command line, so you don't
   have to use XCode. Simply follow the Linux instructions. 
   XCode should still be installed so that you have the OpenGL
   and GLUT libraries. To get started with XCode, download it
   from the App Store. Open it and let it set itself up. Then
   in the terminal type: xcode-select -install
   This will install the command line compiler tools on your Mac
