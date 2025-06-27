from math import floor
import os
import wave
import uuid
import sys

include_completely_hidden_takes = True
render_waves = False
no_reaper = False
skip_wav_conversion = False

for arg in sys.argv:
    if arg == "-hide":
        include_completely_hidden_takes = False
    if arg == "-render":
        render_waves = True
    if arg == "-no-reaper":
        no_reaper = True
    if arg == "-skip-conversion":
        skip_wav_conversion = True

f = open('EVENTLST.BR2', 'rb')

class Track:
    def __init__(self, name):
        self.name = name
        self.files = []
        self.startEnd = []

class FileStartEnd:
    def __init__(self, start, end):
        self.start = start
        self.end = end

class File:
    def __init__(self, start, end, duration, offset, name, track, virtual_track, order):
        self.start = start
        self.end = end
        self.duration = duration
        self.offset = offset
        self.name = name
        self.track = track
        self.virtual_track = virtual_track
        self.order = order

tracks = [Track("Track1_V0"), Track("Track2_V0"), Track("Track3_V0"), Track("Track4_V0"), Track("Track5_V0"), Track("Track6_V0"), Track("Track7_V0"), Track("Track8_V0"), Track("Track9a_V0"), Track("Track9b_V0"), Track("Track10a_V0"), Track("Track10b_V0"), Track("Track11a_V0"), Track("Track11b_V0"), Track("Track12a_V0"), Track("Track12b_V0"),
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
          Track("Track1_V15"),Track("Track2_V15"),Track("Track3_V15"),Track("Track4_V15"),Track("Track5_V15"),Track("Track6_V15"),Track("Track7_V15"),Track("Track8_V15"),Track("Track9a_V15"),Track("Track9b_V15"),Track("Track10a_V15"),Track("Track10b_V15"),Track("Track11a_V15"),Track("Track11b_V15"),Track("Track12a_V15"),Track("Track12b_V15"),]

extra_tracks = []

bin = f.read()

all_files = []

for i in range(0, len(bin), 64):
    # Read 64 bytes at a time

    while bin[i + 61] != 32:
        i += 32
        if i > len(bin) - 64:
            break

    if i > len(bin):
        break

    chunk = bin[i:i+64]
    if len(chunk) < 64:
        break  # Avoid processing incomplete chunks

    value_start = chunk[2] * 16777216 + chunk[3] * 65536 + chunk[4] * 256 + chunk[5]
    value_start = value_start * 16 / 44100 # Convert to seconds

    value_end = chunk[6] * 16777216 + chunk[7] * 65536 + chunk[8] * 256 + chunk[9]
    value_end = value_end * 16 / 44100 # Convert to seconds
    value_duration = value_end - value_start

    value_name = f"{chunk[24]:02X}{chunk[25]:02X}"

    value_order = chunk[58] * 256 + chunk[59]

    value_track = floor(chunk[44] / 16)

    value_virtual_track = chunk[44] % 16

    all_files.append(File(value_start, value_end, value_end - value_start, 0, value_name, value_track, value_virtual_track, value_order))

all_files.sort(key=lambda file: file.order)
all_files.reverse()

for file in all_files:
    value_start = file.start
    value_end = file.end
    value_duration = value_end - value_start

    value_name = file.name
    value_track = file.track

    value_virtual_track = file.virtual_track

    add_to_extra_track = False

    segments_to_hide = []

    tracks[value_track + value_virtual_track].startEnd.sort(key=lambda st: st.start)

    for startEnd in tracks[value_track + value_virtual_track].startEnd:
        if value_start >= startEnd.start and value_start < startEnd.end and value_end > startEnd.end:   # file starts during newer file and ends after it
            segments_to_hide.append([value_start, startEnd.end])
        if value_start < startEnd.start and value_end > startEnd.start and value_end < startEnd.end:    # file starts before newer file and ends before it
            segments_to_hide.append([startEnd.start, value_end])
        if value_start < startEnd.start and value_end > startEnd.end:                                   # file starts before newer file and ends after it
            segments_to_hide.append([startEnd.start, startEnd.end])
        if value_start >= startEnd.start and value_end < startEnd.end:                                  # file is completely hidden by newer file
            add_to_extra_track = True
        
    if add_to_extra_track:
        extra_track_name = "Extra" + tracks[value_track + value_virtual_track].name
        index_of_extra_track_to_add = -1
        for i, existing_extra_track in enumerate(extra_tracks):
            if existing_extra_track.name == extra_track_name:
                add_to_new_extra_track = False
                for startEndExtra in existing_extra_track.startEnd:
                    if value_start >= startEndExtra.start and value_start < startEndExtra.end:
                        add_to_new_extra_track = True
                    if value_end > startEndExtra.start and value_end < startEndExtra.end:
                        add_to_new_extra_track = True
                    if startEndExtra.start >= value_start and startEndExtra.end < value_end:
                        add_to_new_extra_track = True
                if not add_to_new_extra_track:
                    index_of_extra_track_to_add = i
        if index_of_extra_track_to_add != -1:
            extra_tracks[index_of_extra_track_to_add].files.append((value_start, value_end, value_duration, 0, value_name))
            extra_tracks[index_of_extra_track_to_add].startEnd.append(FileStartEnd(value_start, value_end))
        else:
            extra_track = Track(extra_track_name)
            extra_track.files.append((value_start, value_end, value_duration, 0, value_name))
            extra_track.startEnd.append(FileStartEnd(value_start, value_end))
            extra_tracks.append(extra_track)
    else:
        if segments_to_hide:
            segments_to_hide.sort(key=lambda seg: seg[0])
            segments_to_show = []
            for i in range(0, len(segments_to_hide) - 1):
                segments_to_show.append([segments_to_hide[i][1], segments_to_hide[i+1][0]])
            if segments_to_hide[0][0] > value_start:
                segments_to_show.append([value_start, segments_to_hide[0][0]])
            if segments_to_hide[-1][1] < value_end:
                segments_to_show.append([segments_to_hide[-1][1], value_end])
            for i, show in enumerate(segments_to_show):
                tracks[value_track + value_virtual_track].files.append((show[0], show[1], show[1] - show[0], show[0] - value_start, value_name))
        else:
            tracks[value_track + value_virtual_track].files.append((value_start, value_end, value_duration, 0, value_name))
            tracks[value_track + value_virtual_track].startEnd.append(FileStartEnd(value_start, value_end))

f.close()

if include_completely_hidden_takes:
    extra_tracks.sort(key=lambda track: track.name)
    for extra_track in extra_tracks:
        tracks.append(extra_track)

if not skip_wav_conversion:
    for file in os.listdir():
        if file.endswith(".VR8"):
            print("Converting " + file)
            with open(file, "rb") as raw_file:
                data = raw_file.read()
                new_filename = file.replace(".VR8", "") + ".wav"
                wav_file = wave.open(new_filename, "wb")
                wav_file.setnchannels(1)
                wav_file.setsampwidth(2)
                wav_file.setframerate(44100)
                wav_file.writeframesraw(data)
                wav_file.close()

if not no_reaper:
    if os.path.exists("song.rpp"):
        os.remove("song.rpp")

    f = open("song.rpp", "x")
    f.write("<REAPER_PROJECT 0.1 \"7.40/win64\" 1750634845\n")
    f.write("  <NOTES 0 2\n")
    f.write("  >\n")
    f.write("  RIPPLE 0 0\n")
    f.write("  GROUPOVERRIDE 0 0 0\n")
    f.write("  AUTOXFADE 129\n")
    f.write("  ENVATTACH 2\n")
    f.write("  POOLEDENVATTACH 0\n")
    f.write("  MIXERUIFLAGS 11 48\n")
    f.write("  ENVFADESZ10 40\n")
    f.write("  PEAKGAIN 1\n")
    f.write("  FEEDBACK 0\n")
    f.write("  PANLAW 1\n")
    f.write("  PROJOFFS 0 0 0\n")
    f.write("  MAXPROJLEN 0 0\n")
    f.write("  GRID 3455 8 1 8 1 0 0 0\n")
    f.write("  TIMEMODE 1 5 -1 30 0 0 -1\n")
    f.write("  VIDEO_CONFIG 0 0 65792\n")
    f.write("  PANMODE 3\n")
    f.write("  PANLAWFLAGS 3\n")
    f.write("  CURSOR 0\n")
    f.write("  ZOOM 2.32748451506296 0 0\n")
    f.write("  VZOOMEX 6 0\n")
    f.write("  USE_REC_CFG 0\n")
    f.write("  RECMODE 1\n")
    f.write("  SMPTESYNC 0 30 100 40 1000 300 0 0 1 0 0\n")
    f.write("  LOOP 0\n")
    f.write("  LOOPGRAN 0 4\n")
    f.write("  RECORD_PATH \"Media\" ""\n")
    f.write("  <RECORD_CFG\n")
    f.write("    ZXZhdxgAAQ==\n")
    f.write("  >\n")
    f.write("  <APPLYFX_CFG\n")
    f.write("  >\n")
    f.write("  RENDER_FILE ""\n")
    f.write("  RENDER_PATTERN ""\n")
    f.write("  RENDER_FMT 0 2 0\n")
    f.write("  RENDER_1X 0\n")
    f.write("  RENDER_RANGE 1 0 0 0 1000\n")
    f.write("  RENDER_RESAMPLE 3 0 1\n")
    f.write("  RENDER_ADDTOPROJ 0\n")
    f.write("  RENDER_STEMS 0\n")
    f.write("  RENDER_DITHER 0\n")
    f.write("  RENDER_TRIM 0 0 0 0\n")
    f.write("  TIMELOCKMODE 0\n")
    f.write("  TEMPOENVLOCKMODE 1\n")
    f.write("  ITEMMIX 1\n")
    f.write("  DEFPITCHMODE 589824 0\n")
    f.write("  TAKELANE 1\n")
    f.write("  SAMPLERATE 44100 0 0\n")
    f.write("  <RENDER_CFG\n")
    f.write("    ZXZhdxgAAQ==\n")
    f.write("  >\n")
    f.write("  LOCK 1\n")
    f.write("  <METRONOME 6 2\n")
    f.write("    VOL 0.25 0.125\n")
    f.write("    BEATLEN 4\n")
    f.write("    FREQ 1760 880 1\n")
    f.write("    SAMPLES "" "" "" ""\n")
    f.write("    SPLIGNORE 0 0\n")
    f.write("    SPLDEF 2 660 "" 0 ""\n")
    f.write("    SPLDEF 3 440 "" 0 ""\n")
    f.write("    PATTERN 0 169\n")
    f.write("    PATTERNSTR ABBB\n")
    f.write("    MULT 1\n")
    f.write("  >\n")
    f.write("  GLOBAL_AUTO -1\n")
    f.write("  TEMPO 120 4 4 0\n")
    f.write("  PLAYRATE 1 0 0.25 4\n")
    f.write("  SELECTION 0 0\n")
    f.write("  SELECTION2 0 0\n")
    f.write("  MASTERAUTOMODE 0\n")
    f.write("  MASTERTRACKHEIGHT 0 0\n")
    f.write("  MASTERPEAKCOL 16576\n")
    f.write("  MASTERMUTESOLO 0\n")
    f.write("  MASTERTRACKVIEW 0 0.6667 0.5 0.5 0 0 0 0 0 0 0 0 0 0\n")
    f.write("  MASTERHWOUT 0 0 1 0 0 0 0 -1\n")
    f.write("  MASTER_NCH 2 2\n")
    f.write("  MASTER_VOLUME 1 0 -1 -1 1\n")
    f.write("  MASTER_PANMODE 3\n")
    f.write("  MASTER_PANLAWFLAGS 3\n")
    f.write("  MASTER_FX 1\n")
    f.write("  MASTER_SEL 0\n")
    f.write("  <MASTERPLAYSPEEDENV\n")
    f.write("    EGUID {A91547DB-BB6A-430A-89AE-24BA6298F8A2}\n")
    f.write("    ACT 0 -1\n")
    f.write("    VIS 0 1 1\n")
    f.write("    LANEHEIGHT 0 0\n")
    f.write("    ARM 0\n")
    f.write("    DEFSHAPE 0 -1 -1\n")
    f.write("  >\n")
    f.write("  <TEMPOENVEX\n")
    f.write("    EGUID {EEF37424-61FB-452B-89FE-A73CFF41619F}\n")
    f.write("    ACT 1 -1\n")
    f.write("    VIS 1 0 1\n")
    f.write("    LANEHEIGHT 0 0\n")
    f.write("    ARM 0\n")
    f.write("    DEFSHAPE 1 -1 -1\n")
    f.write("  >\n")
    f.write("  <PROJBAY\n")
    f.write("  >\n")

    for i, track in enumerate(tracks):
        if track.files:
            print("Writing track " + track.name + " with " + str(len(track.files)) + " audio clips")
            track_name = track.name
            uuid_track = str(uuid.uuid4()).upper()
            f.write("  <TRACK {")
            f.write(f"{uuid_track}")
            f.write("}\n")
            f.write(f"    NAME {track_name}\n")
            f.write("    PEAKCOL 16576\n")
            f.write("    BEAT -1\n")
            f.write("    AUTOMODE 0\n")
            f.write("    PANLAWFLAGS 3\n")
            f.write("    VOLPAN 1 0 -1 -1 1\n")
            f.write("    MUTESOLO 0 0 0\n")
            f.write("    IPHASE 0\n")
            f.write("    PLAYOFFS 0 1\n")
            f.write("    ISBUS 0 0\n")
            f.write("    BUSCOMP 0 0 0 0 0\n")
            f.write("    SHOWINMIX 1 0.6667 0.5 1 0.5 0 0 0\n")
            f.write("    FIXEDLANES 9 0 0 0 0\n")
            f.write("    SEL 0\n")
            f.write("    REC 0 0 1 0 0 0 0 0\n")
            f.write("    VU 64\n")
            f.write("    TRACKHEIGHT 68 0 0 0 0 0 0\n")
            f.write("    INQ 0 0 0 0.5 100 0 0 100\n")
            f.write("    NCHAN 2\n")
            f.write("    FX 1\n")
            f.write("    TRACKID {" f"{uuid_track}" "}\n")
            f.write("    PERF 0\n")
            f.write("    MIDIOUT -1\n")
            f.write("    MAINSEND 1 0\n")
            for start, end, duration, offset, name in track.files:
                uuid_IGUID = str(uuid.uuid4()).upper()
                uuid_GUID = str(uuid.uuid4()).upper()
                f.write("    <ITEM\n")
                f.write(f"      POSITION {start}\n")
                f.write("      SNAPOFFS 0\n")
                f.write(f"      LENGTH {duration}\n")
                f.write("      LOOP 1\n")
                f.write("      ALLTAKES 0\n")
                f.write("      FADEIN 1 0 0 1 0 0 0\n")
                f.write("      FADEOUT 1 0 0 1 0 0 0\n")
                f.write("      MUTE 0 0\n")
                f.write("      SEL 0\n")
                f.write("      IGUID {" f"{uuid_IGUID}" "}\n")
                f.write("      IID 1\n")
                f.write(f"      NAME {name}\n")
                f.write("      VOLPAN 1 0 1 -1\n")
                f.write(f"      SOFFS {offset}\n")
                f.write("      PLAYRATE 1 1 0 -1 0 0.0025\n")
                f.write("      CHANMODE 0\n")
                f.write("      GUID {" f"{uuid_GUID}" "}\n")
                f.write("      <SOURCE WAVE\n")
                f.write(f"        FILE \"TK00{name}.wav\"\n")
                f.write("      >\n")
                f.write("    >\n")
            f.write("  >\n")

    f.write("  <EXTENSIONS\n")
    f.write("  >\n")
    f.write(">\n")
    f.close()

if render_waves:
    print("Rendering wav-files of tracks not implemented yet")