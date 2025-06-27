#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <cmath>

class File {
    public:
        double start = 0;
        double end = 0;
        double duration = 0;
        double offset = 0;
        std::string name = "";
        int track = 0;
        int virtualTrack = 0;
        int order = 0;

        File(double start_, double end_, double duration_, double offset_, std::string name_, int track_, int virtualTrack_, int order_);
        File(double start_, double end_, double duration_, double offset_, std::string name_);
};

File::File(double start_, double end_, double duration_, double offset_, std::string name_, int track_, int virtualTrack_, int order_) :
    start(start_), end(end_), duration(duration_), offset(offset_), name(name_), track(track_), virtualTrack(virtualTrack_), order(order_) {}

File::File(double start_, double end_, double duration_, double offset_, std::string name_) :
    start(start_), end(end_), duration(duration_), offset(offset_), name(name_) {}

class FileStartEnd {
    public:
        double start;
        double end;
        FileStartEnd(double start_, double end_);
};

FileStartEnd::FileStartEnd(double start_, double end_) : start(start_), end(end_) {};

class Track {
    public:
        std::string name;
        std::vector<File> files;
        std::vector<FileStartEnd> startEnd;
        Track(std::string name_);
};

Track::Track(std::string name_) : name(name_) {

};

int main(int argc, char *argv[]){

    bool includeCompletelyHiddenTakes = true;
    bool renderWaves = false;
    bool noReaper = false;
    bool skipWavConversion = false;

    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-hide") {
            std::cout << "-hide" << "\n";
            includeCompletelyHiddenTakes = false;
        }
        if (std::string(argv[i]) == "-render") {
            std::cout << "-render" << "\n";
            renderWaves = true;
        }
        if (std::string(argv[i]) == "-no-reaper") {
            std::cout << "-no-reaper" << "\n";
            noReaper = true;
        }
        if (std::string(argv[i]) == "-skip-conversion") {
            std::cout << "-skip-conversion" << "\n";
            skipWavConversion = true;
        }
    }

    std::vector<Track> tracks = {
        Track("Track1_V0"), Track("Track2_V0"), Track("Track3_V0"), Track("Track4_V0"), Track("Track5_V0"), Track("Track6_V0"), Track("Track7_V0"), Track("Track8_V0"), Track("Track9a_V0"), Track("Track9b_V0"), Track("Track10a_V0"), Track("Track10b_V0"), Track("Track11a_V0"), Track("Track11b_V0"), Track("Track12a_V0"), Track("Track12b_V0"),
        Track("Track1_V1"), Track("Track2_V1"), Track("Track3_V1"), Track("Track4_V1"), Track("Track5_V1"), Track("Track6_V1"), Track("Track7_V1"), Track("Track8_V1"), Track("Track9a_V1"), Track("Track9b_V1"), Track("Track10a_V1"), Track("Track10b_V1"), Track("Track11a_V1"), Track("Track11b_V1"), Track("Track12a_V1"), Track("Track12b_V1"),
        Track("Track1_V2"), Track("Track2_V2"), Track("Track3_V2"), Track("Track4_V2"), Track("Track5_V2"), Track("Track6_V2"), Track("Track7_V2"), Track("Track8_V2"), Track("Track9a_V2"), Track("Track9b_V2"), Track("Track10a_V2"), Track("Track10b_V2"), Track("Track11a_V2"), Track("Track11b_V2"), Track("Track12a_V2"), Track("Track12b_V2"),
        Track("Track1_V3"), Track("Track2_V3"), Track("Track3_V3"), Track("Track4_V3"), Track("Track5_V3"), Track("Track6_V3"), Track("Track7_V3"), Track("Track8_V3"), Track("Track9a_V3"), Track("Track9b_V3"), Track("Track10a_V3"), Track("Track10b_V3"), Track("Track11a_V3"), Track("Track11b_V3"), Track("Track12a_V3"), Track("Track12b_V3"),
        Track("Track1_V4"), Track("Track2_V4"), Track("Track3_V4"), Track("Track4_V4"), Track("Track5_V4"), Track("Track6_V4"), Track("Track7_V4"), Track("Track8_V4"), Track("Track9a_V4"), Track("Track9b_V4"), Track("Track10a_V4"), Track("Track10b_V4"), Track("Track11a_V4"), Track("Track11b_V4"), Track("Track12a_V4"), Track("Track12b_V4"),
        Track("Track1_V5"), Track("Track2_V5"), Track("Track3_V5"), Track("Track4_V5"), Track("Track5_V5"), Track("Track6_V5"), Track("Track7_V5"), Track("Track8_V5"), Track("Track9a_V5"), Track("Track9b_V5"), Track("Track10a_V5"), Track("Track10b_V5"), Track("Track11a_V5"), Track("Track11b_V5"), Track("Track12a_V5"), Track("Track12b_V5"),
        Track("Track1_V6"), Track("Track2_V6"), Track("Track3_V6"), Track("Track4_V6"), Track("Track5_V6"), Track("Track6_V6"), Track("Track7_V6"), Track("Track8_V6"), Track("Track9a_V6"), Track("Track9b_V6"), Track("Track10a_V6"), Track("Track10b_V6"), Track("Track11a_V6"), Track("Track11b_V6"), Track("Track12a_V6"), Track("Track12b_V6"),
        Track("Track1_V7"), Track("Track2_V7"), Track("Track3_V7"), Track("Track4_V7"), Track("Track5_V7"), Track("Track6_V7"), Track("Track7_V7"), Track("Track8_V7"), Track("Track9a_V7"), Track("Track9b_V7"), Track("Track10a_V7"), Track("Track10b_V7"), Track("Track11a_V7"), Track("Track11b_V7"), Track("Track12a_V7"), Track("Track12b_V7"),
        Track("Track1_V8"), Track("Track2_V8"), Track("Track3_V8"), Track("Track4_V8"), Track("Track5_V8"), Track("Track6_V8"), Track("Track7_V8"), Track("Track8_V8"), Track("Track9a_V8"), Track("Track9b_V8"), Track("Track10a_V8"), Track("Track10b_V8"), Track("Track11a_V8"), Track("Track11b_V8"), Track("Track12a_V8"), Track("Track12b_V8"),
        Track("Track1_V9"), Track("Track2_V9"), Track("Track3_V9"), Track("Track4_V9"), Track("Track5_V9"), Track("Track6_V9"), Track("Track7_V9"), Track("Track8_V9"), Track("Track9a_V9"), Track("Track9b_V9"), Track("Track10a_V9"), Track("Track10b_V9"), Track("Track11a_V9"), Track("Track11b_V9"), Track("Track12a_V9"), Track("Track12b_V9"),
        Track("Track1_V10"),Track("Track2_V10"),Track("Track3_V10"),Track("Track4_V10"),Track("Track5_V10"),Track("Track6_V10"),Track("Track7_V10"),Track("Track8_V10"),Track("Track9a_V10"),Track("Track9b_V10"),Track("Track10a_V10"),Track("Track10b_V10"),Track("Track11a_V10"),Track("Track11b_V10"),Track("Track12a_V10"),Track("Track12b_V10"),
        Track("Track1_V11"),Track("Track2_V11"),Track("Track3_V11"),Track("Track4_V11"),Track("Track5_V11"),Track("Track6_V11"),Track("Track7_V11"),Track("Track8_V11"),Track("Track9a_V11"),Track("Track9b_V11"),Track("Track10a_V11"),Track("Track10b_V11"),Track("Track11a_V11"),Track("Track11b_V11"),Track("Track12a_V11"),Track("Track12b_V11"),
        Track("Track1_V12"),Track("Track2_V12"),Track("Track3_V12"),Track("Track4_V12"),Track("Track5_V12"),Track("Track6_V12"),Track("Track7_V12"),Track("Track8_V12"),Track("Track9a_V12"),Track("Track9b_V12"),Track("Track10a_V12"),Track("Track10b_V12"),Track("Track11a_V12"),Track("Track11b_V12"),Track("Track12a_V12"),Track("Track12b_V12"),
        Track("Track1_V13"),Track("Track2_V13"),Track("Track3_V13"),Track("Track4_V13"),Track("Track5_V13"),Track("Track6_V13"),Track("Track7_V13"),Track("Track8_V13"),Track("Track9a_V13"),Track("Track9b_V13"),Track("Track10a_V13"),Track("Track10b_V13"),Track("Track11a_V13"),Track("Track11b_V13"),Track("Track12a_V13"),Track("Track12b_V13"),
        Track("Track1_V14"),Track("Track2_V14"),Track("Track3_V14"),Track("Track4_V14"),Track("Track5_V14"),Track("Track6_V14"),Track("Track7_V14"),Track("Track8_V14"),Track("Track9a_V14"),Track("Track9b_V14"),Track("Track10a_V14"),Track("Track10b_V14"),Track("Track11a_V14"),Track("Track11b_V14"),Track("Track12a_V14"),Track("Track12b_V14"),
        Track("Track1_V15"),Track("Track2_V15"),Track("Track3_V15"),Track("Track4_V15"),Track("Track5_V15"),Track("Track6_V15"),Track("Track7_V15"),Track("Track8_V15"),Track("Track9a_V15"),Track("Track9b_V15"),Track("Track10a_V15"),Track("Track10b_V15"),Track("Track11a_V15"),Track("Track11b_V15"),Track("Track12a_V15"),Track("Track12b_V15")
    };

    std::vector<Track> extraTracks;
    std::vector<File> allFiles;

    uintmax_t fileSizeSystem = std::filesystem::file_size("EVENTLST.BR2");

    if (fileSizeSystem == 0) {
        std::cerr << "File is empty or does not exist." << "\n";
        return 1;
    }

    std::vector<uint8_t> bin(fileSizeSystem);

    std::ifstream file("EVENTLST.BR2", std::ios::binary);
    file.read(reinterpret_cast<char*>(bin.data()), fileSizeSystem);
    if(!file) {
        std::cerr << "Error reading file." << file.gcount() << " bytes read." << "\n";
    }
    file.close();

    std::cout << "EVENTLST.BR2 length: " << fileSizeSystem << "\n";

    for (int i = 0; i < fileSizeSystem; i += 64) {
        while (bin[i + 61] != 32) {
            i += 32;
            if (i > fileSizeSystem - 64) {
                break;
            }
        }

        if (i > fileSizeSystem - 64) {
            break;
        }

        uint8_t* chunk = &bin[i];

        double valueStart = chunk[2] * 16777216 + chunk[3] * 65536 + chunk[4] * 256 + chunk[5];
        valueStart = valueStart * 16 / 44100; // Convert to seconds

        double valueEnd = chunk[6] * 16777216 + chunk[7] * 65536 + chunk[8] * 256 + chunk[9];
        valueEnd = valueEnd * 16 / 44100; // Convert to seconds

        double valueDuration = valueEnd - valueStart;

        char buf[5];
        snprintf(buf, sizeof(buf), "%02X%02X", chunk[24], chunk[25]);
        std::string valueName = buf;

        int valueOrder = chunk[58] * 256 + chunk[59];

        int valueTrack = static_cast<int>(floor(chunk[44] / 16));

        int valueVirtualTrack = chunk[44] % 16;

        File file(valueStart, valueEnd, valueDuration, 0, valueName, valueTrack, valueVirtualTrack, valueOrder);

        allFiles.push_back(file);
    }

    std::sort(allFiles.begin(), allFiles.end(), [](const File& a, const File& b) {
        return a.order > b.order;
    });

    for (const auto& file : allFiles) {
        double valueStart = file.start;
        double valueEnd = file.end;
        double valueDuration = file.duration;
        std::string valueName = file.name;
        int valueTrack = file.track;
        int valueVirtualTrack = file.virtualTrack;

        bool addToExtraTrack = false;

        std::vector<std::vector<double>> segmentsToHide;

        std::sort(tracks[valueTrack + valueVirtualTrack].startEnd.begin(), tracks[valueTrack + valueVirtualTrack].startEnd.end(), [](const FileStartEnd& a, const FileStartEnd& b) {
            return a.start < b.start;
        });

        for (const auto& startEnd : tracks[valueTrack + valueVirtualTrack].startEnd) {
            if (valueStart >= startEnd.start && valueStart < startEnd.end && valueEnd > startEnd.end) {     // file starts during newer file and ends after it
                segmentsToHide.push_back(std::vector<double> {valueStart, startEnd.end});
            }
            if (valueStart < startEnd.start && valueEnd > startEnd.start && valueEnd < startEnd.end) {     // file starts before newer file and ends before it
                segmentsToHide.push_back(std::vector<double> {startEnd.start, valueEnd});
            }
            if (valueStart < startEnd.start && valueEnd > startEnd.end) {                                  // file starts before newer file and ends after it
                segmentsToHide.push_back(std::vector<double> {startEnd.start, startEnd.end});
            }
            if (valueStart >= startEnd.start && valueEnd < startEnd.end) {                                 // file is completely hidden by newer file
                addToExtraTrack = true;
            }
        }
            
        if (addToExtraTrack) {
            std::string extraTrackName = "Extra" + tracks[valueTrack + valueVirtualTrack].name;
            int indexOfExtraTrackToAdd = -1;
            for (int i = 0; i < extraTracks.size(); i++) {
                Track existingExtraTrack = extraTracks[i];

                if (existingExtraTrack.name == extraTrackName) {
                    bool addToNewExtraTrack = false;
                    for (const auto& startEndExtra : existingExtraTrack.startEnd) {
                        if (valueStart >= startEndExtra.start && valueStart < startEndExtra.end) {
                            addToNewExtraTrack = true;
                        }
                        if (valueEnd > startEndExtra.start && valueEnd < startEndExtra.end) {
                            addToNewExtraTrack = true;
                        }
                        if (startEndExtra.start >= valueStart && startEndExtra.end < valueEnd) {
                            addToNewExtraTrack = true;
                        }
                        if (!addToNewExtraTrack) {
                            indexOfExtraTrackToAdd = i;
                        }
                    }
                }
            }
            if (indexOfExtraTrackToAdd != -1) {
                extraTracks[indexOfExtraTrackToAdd].files.push_back(File(valueStart, valueEnd, valueDuration, 0, valueName));
                extraTracks[indexOfExtraTrackToAdd].startEnd.push_back(FileStartEnd(valueStart, valueEnd));
            }
            else {
                Track extraTrack = Track(extraTrackName);
                extraTrack.files.push_back(File(valueStart, valueEnd, valueDuration, 0, valueName));
                extraTrack.startEnd.push_back(FileStartEnd(valueStart, valueEnd));
                extraTracks.push_back(extraTrack);
            }
        } else {
            if (!segmentsToHide.empty()) {

                std::sort(segmentsToHide.begin(), segmentsToHide.end(), [](const std::vector<double>& a, const std::vector<double>& b) {
                    return a[0] < b[0];
                });

                std::vector<std::vector<double>> segmentsToShow;

                for (int i = 0; i < segmentsToHide.size() - 1; i++) {
                    segmentsToShow.push_back(std::vector<double> {segmentsToHide[i][1], segmentsToHide[i+1][0]});
                }

                if (segmentsToHide[0][0] > valueStart) {
                    segmentsToShow.push_back(std::vector<double> {valueStart, segmentsToHide[0][0]});
                }
                if (segmentsToHide[segmentsToHide.size() - 1][1] < valueEnd) {
                    segmentsToShow.push_back(std::vector<double> {segmentsToHide[segmentsToHide.size() - 1][1], valueEnd});
                }

                for (const auto& show : segmentsToShow) {
                    tracks[valueTrack + valueVirtualTrack].files.push_back(File{show[0], show[1], show[1] - show[0], show[0] - valueStart, valueName});
                }

            } else {
                tracks[valueTrack + valueVirtualTrack].files.push_back(File{valueStart, valueEnd, valueDuration, 0, valueName});
                tracks[valueTrack + valueVirtualTrack].startEnd.push_back(FileStartEnd{valueStart, valueEnd});
            }
        }
    }

    if (includeCompletelyHiddenTakes) {
        std::sort(extraTracks.begin(), extraTracks.end(), [](const Track& a, const Track& b) {
            return a.name < b.name;
        });
        for (const auto& extraTrack : extraTracks) {
            tracks.push_back(extraTrack);
        }
    }

    if (!skipWavConversion) {
        for (const auto& entry : std::filesystem::directory_iterator(".")) {
            if (entry.is_regular_file() && entry.path().extension() == ".VR8") {
                std::cout << "Found VR8 file: " << entry.path().filename() << "\n";
                std::ifstream vr8file(entry.path(), std::ios::binary);
                if (vr8file) {
                    std::vector<uint8_t> vr8data((std::istreambuf_iterator<char>(vr8file)), std::istreambuf_iterator<char>());
                    std::cout << "Read " << vr8data.size() << " bytes from " << entry.path().filename() << "\n";
                    // vr8data now contains the file contents as an array

                    uint32_t totalFileSize = 36 + 8 + vr8data.size(); // 36 bytes for the header + 'data' + data size + data

                    uint8_t sizeByte1 = static_cast<uint8_t>((totalFileSize) & 0xFF);
                    uint8_t sizeByte2 = static_cast<uint8_t>((totalFileSize >> 8) & 0xFF);
                    uint8_t sizeByte3 = static_cast<uint8_t>((totalFileSize >> 16) & 0xFF);
                    uint8_t sizeByte4 = static_cast<uint8_t>((totalFileSize >> 24) & 0xFF);
                    
                    std::string filename = entry.path().filename().string();
                    filename = filename.substr(0, filename.size() - 4) + ".wav";

                    std::ofstream newWavData(filename, std::ios::binary);

                    std::vector<uint8_t> outBuf;

                    // TO DO properly:
                    outBuf.insert(outBuf.end(), {0x52, 0x49, 0x46, 0x46}); // 'RIFF'
                    outBuf.insert(outBuf.end(), {sizeByte1, sizeByte2, sizeByte3, sizeByte4}); // File size
                    outBuf.insert(outBuf.end(), {0x57, 0x41, 0x56, 0x45}); // 'WAVE'
                    outBuf.insert(outBuf.end(), {0x66, 0x6D, 0x74, 0x20}); // 'fmt '
                    outBuf.insert(outBuf.end(), {0x10, 0x00, 0x00, 0x00}); // fmt chunk size (16 for PCM)
                    outBuf.insert(outBuf.end(), {0x01, 0x00}); // Audio format (1 for PCM)
                    outBuf.insert(outBuf.end(), {0x01, 0x00}); // Number of channels (1 for mono)
                    outBuf.insert(outBuf.end(), {0x44, 0xAC, 0x00, 0x00}); // Sample rate (48000)
                    outBuf.insert(outBuf.end(), {0x00, 0x00, 0x00, 0x00}); // Byte rate (placeholder)
                    outBuf.insert(outBuf.end(), {0x02, 0x00}); // Block align (2 bytes per sample)
                    outBuf.insert(outBuf.end(), {0x10, 0x00, }); // Bits per sample ( 16 bits)
                    outBuf.insert(outBuf.end(), {0x64, 0x61, 0x74, 0x61}); // 'data'

                    outBuf.insert(outBuf.end(), {static_cast<uint8_t>(vr8data.size() & 0xFF), 
                                                static_cast<uint8_t>((vr8data.size() >> 8) & 0xFF), 
                                                static_cast<uint8_t>((vr8data.size() >> 16) & 0xFF), 
                                                static_cast<uint8_t>((vr8data.size() >> 24) & 0xFF)}); // Data size

                    for (int i = 0; i < vr8data.size(); i++) {
                        outBuf.push_back(vr8data[i]);
                    }

                    newWavData.write(reinterpret_cast<const char*>(outBuf.data()), outBuf.size());
                    newWavData.flush();

                    newWavData.close();
                }
                // You can add your processing code here
            }
        }
    }

    std::ofstream rppFile("song2.rpp");
    if (!rppFile) {
        std::cerr << "Failed to open song.rpp for writing.\n";
    } else {
        rppFile << "<REAPER_PROJECT 0.1 \"7.40/win64\" 1750634845\n";
        rppFile << "  <NOTES 0 2\n";
        rppFile << "  >\n";
        rppFile << "  RIPPLE 0 0\n";
        rppFile << "  GROUPOVERRIDE 0 0 0\n";
        rppFile << "  AUTOXFADE 129\n";
        rppFile << "  ENVATTACH 2\n";
        rppFile << "  POOLEDENVATTACH 0\n";
        rppFile << "  MIXERUIFLAGS 11 48\n";
        rppFile << "  ENVFADESZ10 40\n";
        rppFile << "  PEAKGAIN 1\n";
        rppFile << "  FEEDBACK 0\n";
        rppFile << "  PANLAW 1\n";
        rppFile << "  PROJOFFS 0 0 0\n";
        rppFile << "  MAXPROJLEN 0 0\n";
        rppFile << "  GRID 3455 8 1 8 1 0 0 0\n";
        rppFile << "  TIMEMODE 1 5 -1 30 0 0 -1\n";
        rppFile << "  VIDEO_CONFIG 0 0 65792\n";
        rppFile << "  PANMODE 3\n";
        rppFile << "  PANLAWFLAGS 3\n";
        rppFile << "  CURSOR 0\n";
        rppFile << "  ZOOM 2.32748451506296 0 0\n";
        rppFile << "  VZOOMEX 6 0\n";
        rppFile << "  USE_REC_CFG 0\n";
        rppFile << "  RECMODE 1\n";
        rppFile << "  SMPTESYNC 0 30 100 40 1000 300 0 0 1 0 0\n";
        rppFile << "  LOOP 0\n";
        rppFile << "  LOOPGRAN 0 4\n";
        rppFile << "  RECORD_PATH \"Media\" ""\n";
        rppFile << "  <RECORD_CFG\n";
        rppFile << "    ZXZhdxgAAQ==\n";
        rppFile << "  >\n";
        rppFile << "  <APPLYFX_CFG\n";
        rppFile << "  >\n";
        rppFile << "  RENDER_FILE ""\n";
        rppFile << "  RENDER_PATTERN ""\n";
        rppFile << "  RENDER_FMT 0 2 0\n";
        rppFile << "  RENDER_1X 0\n";
        rppFile << "  RENDER_RANGE 1 0 0 0 1000\n";
        rppFile << "  RENDER_RESAMPLE 3 0 1\n";
        rppFile << "  RENDER_ADDTOPROJ 0\n";
        rppFile << "  RENDER_STEMS 0\n";
        rppFile << "  RENDER_DITHER 0\n";
        rppFile << "  RENDER_TRIM 0 0 0 0\n";
        rppFile << "  TIMELOCKMODE 0\n";
        rppFile << "  TEMPOENVLOCKMODE 1\n";
        rppFile << "  ITEMMIX 1\n";
        rppFile << "  DEFPITCHMODE 589824 0\n";
        rppFile << "  TAKELANE 1\n";
        rppFile << "  SAMPLERATE 44100 0 0\n";
        rppFile << "  <RENDER_CFG\n";
        rppFile << "    ZXZhdxgAAQ==\n";
        rppFile << "  >\n";
        rppFile << "  LOCK 1\n";
        rppFile << "  <METRONOME 6 2\n";
        rppFile << "    VOL 0.25 0.125\n";
        rppFile << "    BEATLEN 4\n";
        rppFile << "    FREQ 1760 880 1\n";
        rppFile << "    SAMPLES "" "" "" ""\n";
        rppFile << "    SPLIGNORE 0 0\n";
        rppFile << "    SPLDEF 2 660 "" 0 ""\n";
        rppFile << "    SPLDEF 3 440 "" 0 ""\n";
        rppFile << "    PATTERN 0 169\n";
        rppFile << "    PATTERNSTR ABBB\n";
        rppFile << "    MULT 1\n";
        rppFile << "  >\n";
        rppFile << "  GLOBAL_AUTO -1\n";
        rppFile << "  TEMPO 120 4 4 0\n";
        rppFile << "  PLAYRATE 1 0 0.25 4\n";
        rppFile << "  SELECTION 0 0\n";
        rppFile << "  SELECTION2 0 0\n";
        rppFile << "  MASTERAUTOMODE 0\n";
        rppFile << "  MASTERTRACKHEIGHT 0 0\n";
        rppFile << "  MASTERPEAKCOL 16576\n";
        rppFile << "  MASTERMUTESOLO 0\n";
        rppFile << "  MASTERTRACKVIEW 0 0.6667 0.5 0.5 0 0 0 0 0 0 0 0 0 0\n";
        rppFile << "  MASTERHWOUT 0 0 1 0 0 0 0 -1\n";
        rppFile << "  MASTER_NCH 2 2\n";
        rppFile << "  MASTER_VOLUME 1 0 -1 -1 1\n";
        rppFile << "  MASTER_PANMODE 3\n";
        rppFile << "  MASTER_PANLAWFLAGS 3\n";
        rppFile << "  MASTER_FX 1\n";
        rppFile << "  MASTER_SEL 0\n";
        rppFile << "  <MASTERPLAYSPEEDENV\n";
        rppFile << "    EGUID {A91547DB-BB6A-430A-89AE-24BA6298F8A2}\n";
        rppFile << "    ACT 0 -1\n";
        rppFile << "    VIS 0 1 1\n";
        rppFile << "    LANEHEIGHT 0 0\n";
        rppFile << "    ARM 0\n";
        rppFile << "    DEFSHAPE 0 -1 -1\n";
        rppFile << "  >\n";
        rppFile << "  <TEMPOENVEX\n";
        rppFile << "    EGUID {EEF37424-61FB-452B-89FE-A73CFF41619F}\n";
        rppFile << "    ACT 1 -1\n";
        rppFile << "    VIS 1 0 1\n";
        rppFile << "    LANEHEIGHT 0 0\n";
        rppFile << "    ARM 0\n";
        rppFile << "    DEFSHAPE 1 -1 -1\n";
        rppFile << "  >\n";
        rppFile << "  <PROJBAY\n";
        rppFile << "  >\n";

        for (const auto& track : tracks) {
            if (!track.files.empty()) {
                std::cout << "Writing track " << track.name << " with " << track.files.size() << " audio clips" << "\n";

                std::string hex[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

                std::string uuid_track = "";

                for (int i = 0; i < 32; i++) {
                    uuid_track.append(hex[static_cast<int>(std::rand() % 16)]);
                    if (i == 7 || i == 11 || i == 15 || i == 19) {
                        uuid_track.append("-");
                    }
                }
                
                rppFile << "  <TRACK {" << uuid_track << "}\n";
                rppFile << "    NAME " << track.name << "\n";
                rppFile << "    PEAKCOL 16576\n";
                rppFile << "    BEAT -1\n";
                rppFile << "    AUTOMODE 0\n";
                rppFile << "    PANLAWFLAGS 3\n";
                rppFile << "    VOLPAN 1 0 -1 -1 1\n";
                rppFile << "    MUTESOLO 0 0 0\n";
                rppFile << "    IPHASE 0\n";
                rppFile << "    PLAYOFFS 0 1\n";
                rppFile << "    ISBUS 0 0\n";
                rppFile << "    BUSCOMP 0 0 0 0 0\n";
                rppFile << "    SHOWINMIX 1 0.6667 0.5 1 0.5 0 0 0\n";
                rppFile << "    FIXEDLANES 9 0 0 0 0\n";
                rppFile << "    SEL 0\n";
                rppFile << "    REC 0 0 1 0 0 0 0 0\n";
                rppFile << "    VU 64\n";
                rppFile << "    TRACKHEIGHT 68 0 0 0 0 0 0\n";
                rppFile << "    INQ 0 0 0 0.5 100 0 0 100\n";
                rppFile << "    NCHAN 2\n";
                rppFile << "    FX 1\n";
                rppFile << "    TRACKID {" << uuid_track << "}\n";
                rppFile << "    PERF 0\n";
                rppFile << "    MIDIOUT -1\n";
                rppFile << "    MAINSEND 1 0\n";
                for (const auto& file : track.files) {

                    std::string uuid_IGUID = "";
                    std::string uuid_GUID = "";
                    
                    for (int i = 0; i < 32; i++) {
                        uuid_IGUID.append(hex[static_cast<int>(std::rand() % 16)]);
                        uuid_GUID.append(hex[static_cast<int>(std::rand() % 16)]);
                        if (i == 7 || i == 11 || i == 15 || i == 19) {
                            uuid_IGUID.append("-");
                            uuid_GUID.append("-");
                        }
                    }

                    rppFile << "    <ITEM\n";
                    if (std::fmod(file.start, 1) == 0) {
                        rppFile << "      POSITION " << std::fixed << std::setprecision(0) << file.start << "\n";
                    } else {
                        rppFile << "      POSITION " << std::fixed << std::setprecision(14) << file.start << "\n";
                    }
                    rppFile << "      SNAPOFFS 0\n";
                    if (std::fmod(file.duration, 1) == 0) {
                        rppFile << "      LENGTH " << std::fixed << std::setprecision(0) << file.duration << "\n";
                    } else {
                        rppFile << "      LENGTH " << std::fixed << std::setprecision(14) << file.duration << "\n";
                    }
                    rppFile << "      LOOP 1\n";
                    rppFile << "      ALLTAKES 0\n";
                    rppFile << "      FADEIN 1 0 0 1 0 0 0\n";
                    rppFile << "      FADEOUT 1 0 0 1 0 0 0\n";
                    rppFile << "      MUTE 0 0\n";
                    rppFile << "      SEL 0\n";
                    rppFile << "      IGUID {" << uuid_IGUID << "}\n";
                    rppFile << "      IID 1\n";
                    rppFile << "      NAME " << file.name << "\n";
                    rppFile << "      VOLPAN 1 0 1 -1\n";
                    if (std::fmod(file.offset, 1) == 0) {
                        rppFile << "      SOFFS " << std::fixed << std::setprecision(0) << file.offset << "\n";
                    } else {
                        rppFile << "      SOFFS " << std::fixed << std::setprecision(14) << file.offset << "\n";
                    }
                    rppFile << "      PLAYRATE 1 1 0 -1 0 0.0025\n";
                    rppFile << "      CHANMODE 0\n";
                    rppFile << "      GUID {" << uuid_GUID << "}\n";
                    rppFile << "      <SOURCE WAVE\n";
                    rppFile << "        FILE \"TK00" << file.name << ".wav\"\n";
                    rppFile << "      >\n";
                    rppFile << "    >\n";
                }
                rppFile << "  >\n";
            }
        }

        rppFile << "  <EXTENSIONS\n";
        rppFile << "  >\n";
        rppFile << ">\n";

        rppFile.close();
    }
}
