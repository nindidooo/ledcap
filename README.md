# ledcap
firmware for attiny85 to flash rear tail lights of cap

## Step 1: Download Arduino packages
 - In Arduino go 'Preferences'->'Additional Boards Manager URLs' and add `https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json`.
- Navigate the menu Tools -> Board -> Boards Manger and type “attiny” into the top search board; there will click on the “Install” button on the attiny board package.
- Click “OK” to save and restart the Arduino IDE. 

## Step 2: Setup Arduion
You should now see an entry for ATtiny in the Tools > Board menu. Select “ATtiny25/45/85”.
 - Go 'Tools'->'Boards' and choose 'ATtiny 25/45/85'
 - Go 'Tools'->'Programmer' choose 'USBtinyISP'
 - Go 'Sketch'->'Export compiled binary'


## Step 3: Upload


Finally we upload to device:
On Mac: you will have a default pre-compiled version ready to use for t85. If you need to rebuild, look below in FAQ

```
cd
git clone https://github.com/micronucleus/micronucleus
cd ~/micronucleus/commandline/builds/x86_64-apple-darwin/
./micronucleus --run ~/Documents/Arduino/sketch_sep22a/sketch_sep22a.ino.tiny8.hex
```

You should then see something like...
```
> Starting to upload ...
writing: 83% complete
> Starting the user app ...
running: 100% complete
>> Micronucleus done. Thank you!
```

If this doesn't appear, repeat the `./micronucleus --run ~/Documents/Arduino/sketch_sep22a/sketch_sep22a.ino.tiny8.hex` command

## FAQ
Content was from here:
https://www.jasonacox.com/wordpress/archives/518
https://gist.github.com/gurre/20441945fdcbb0c2f2c346d9f894a361

Rebuilding micronucleus:
using `make CONFIG=t85_default`.
