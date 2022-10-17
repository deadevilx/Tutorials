# Tutorial_00 - Git for Windows and Visual Studio Setup

    Prerequisites:
        Download and install [Git for Windows](https://gitforwindows.org/)
        Download and install [Visual Studio Community Edition](https://developer.microsoft.com/)

## Setting up Git for Windows using SSH keys
    1. Generate SSH public/private keypair using ssh-keygen utility or use existing ones
    2. Copy your id_rsa.pub to GitHub (you must be GitHub account owner and logged-in)
    3. Copy your id_rsa to your C:\Users\<Username>\.ssh directory

    Now right click on any directory and choose Git GUI here. Then type GitHub repository URL and destination directory name
    e.g. git@github.com:deadevilx/Tutorials.git on the first field and Tutorials on the second

    Press Enter

    Response Yes to all GitForWindows client questions. All done.

## Setting up Visual Studio
    Find Tutorials\Tutorial_00\App.sln file and open it. Visual Studio runs and ready to use.
    Some additional settings may help you write programs.
    
    1. Select "Line Numbers" checkbox on Tools -> Options -> Text Editor -> All Languages menu

![Show Line Numbers](https://github.com/deadevilx/Tutorials/blob/master/images/tutorial_00_00.png)

    2. Select "Automatically close the console when debugging stops" checkbox on Tools -> Options -> Debugging -> General

![Automatically close the console window](https://github.com/deadevilx/Tutorials/blob/master/images/tutorial_00_01.png)

    3. Press F5 and wait until application start executing. That's all for now.
