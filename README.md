# br1600conv
Project file convertor for BR-1600CD
V0.2

Tool for converting raw project files from Boss BR-1600CD to wav-files and Reaper project.
VR8 files are raw audio data that can be easily converted to 16-bit 44.1 kHz mono wav-files. If you have just long takes that use multiple tracks and don't have any overdubs or partial takes, that conversion is enough. If you have takes that don't begin exactly where other takes begin or you can't immediately tell which take goes where, you have a problem. This tool tries to parse project files and recreate what BR-1600CD plays and renders when it is set to export data via USB.
Why do this if that machine has USB-connection? Well, the connection seems to be unstable, probably due age of the machine and how USB-connections have evolved. Modern computers seem more often than not to timeout when establishing connection. This itself would not be a huge, just somewhat irritating, problem, but BR-1600CD needs to render its tracks into coherent wav-files (remember, the tracks inside the machine are comprised of separate takes and not just long file) and it takes long time and if the USB-connection fails (or when it's ended deliberately), the machine removes the rendered files.
So, you can just use USB-backup option, get raw files from song-folder and run this tool in that folder.

Currently it converts the VR8-files to wav and parses EVENTLST.BR2 enough to know where to places the files. Now it creates a project file for Reaper ( https://www.reaper.fm ), future development will allow it to render each track into long wav-file so you can use any other DAW.

Currently done in Python and C++ to have just executable file.

What is parsed from EVENTLST.BR2:

All data in big-endian

Data for each take is a 64 byte chunk with:
- Bytes 2-5: 32 bit unsigned interger indicating start of wav file in samples from beginning of song divided by 16
- Bytes 6-9: 32 bit unsigned interger indicating end of wav file in samples from beginning of song divided by 16
- Bytes 24-25: name of the wav-file in hexadecimal, with prefix of TK00.
- Byte 44: track of the take. Upper 4 bytes indicate number of the physical track. [Lower are which virtual track is used? Need more research]
- Bytes 58-59: running number of take, bigger number is newer. [Not sure if this really uses both bytes, I haven't yet had over 255 takes in one song]
- Byte 61: always has value 20h

What to research:
- Bytes 46-57: name of the take?
- SONGPRM.BR2 seems to contain names of tracks and settings volume, panning, eq and other effects. It could be fun to read them and recreate whole mix with Reapers default effects, but that is probably just waste of time. Names of the tracks should be read from here though.
- EVENTLST.BR2 has randomly 32 byte long empty rows those are skipped over, by reading byte 61 and checking if it is something else than 20h. Need to test if there are edge cases where real rows are skipped
- After last real take information there is basically random data, hack for those empty lines skips those in my files always, but there is probably chance for that byte 61 to be 20h randomly

BR-1600CD seems to save even takes that are completely written over. Using argument "-hide" they aren't added to project. If there are takes that partly overlap each other, the newest take is shown completely and oldest have clips of them playing when there isn't newer take.
