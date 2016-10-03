# Appodeal QT plugin

To add Appodeal plugin to your project you need to perform a few actions:
1) Download this project, unzip it and put Appodeal folder to your project root folder.
2) Open your .pro file and add the following line: `include(Appodeal/Appodeal.pri)`.
3) Copy TARGET value from the .pro file, then open YOUR_PROJECT_PATH/Appodeal/android/AndroidManifest.xml, find `android.app.lib_name` and replace the value with your TARGET value.

After that you can include Appodeal/appodeal.h to your source code and use appodeal's static functions to cache and show ads:
```
//You need to specify your own application key. It's important to use correct bundle id and application key pair.
Appodeal::Initialize("fee50c333ff3825fd6ad6d38cff78154de3025546d47a84f", Appodeal::BANNER | Appodeal::INTERSTITIAL); // initialize both of banner and interstitial 
Appodeal::Show(Appodeal::BANNER); //Appodeal uses autocache by default (you can disable it), so, you you don't have to worry about caching. 
```

A more complex example can be found in this demo project.

The plugin supports ant and gradle build systems.