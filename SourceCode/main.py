import os
import tkinter as tk
from tkinter import filedialog as fd
import vlc
import time
import config
import time_format


def open_folder():
    dir_path = fd.askdirectory()
    print(dir_path)
    if dir_path:
        music_list.delete(0, tk.END)
        for f in os.listdir(dir_path):
            if f.endswith(".mp3"):
                music_list.insert(tk.END, str(f.replace(".mp3","")))
                musics.append(f"{dir_path}/{f}")


def open_file():
    global is_playing

     
    file_path = fd.askopenfile(filetypes=[
                                            ("MP3 Files", "*.mp3"),
                                            ("WAV Files", "*.wav"),
                                            ("All Files", "*.*")
                                        ])
    if file_path:
        music_name_label.config(text=str(os.path.basename(file_path.name).replace(".mp3","")))

        media = instance.media_new(file_path.name)
        player.set_media(media)
        player.play()
        time.sleep(0.5)
        is_playing = True


        total_ms = player.get_length()
        total_sec = total_ms // 1000
        music_pos.config(to=total_sec)

        icon = tk.PhotoImage(file="SourceCode/resources/pause-solid.png")    
        pause_button.config(image=icon)
        pause_button.image = icon

        
        min = time_format.sec_to_min(total_sec)
        min_str = ""
        sec_str = ""
        if min[0] < 10:
            min_str = f"0{min[0]}"
        else:
            min_str = f"{min[0]}"
        if min[1] < 10:
            sec_str = f"0{min[1]}"
        else:
            sec_str = f"{min[1]}"
        size_label.config(text=f"{min_str} : {sec_str}")


        update_pos()


def new_file():    
    file_path = fd.askopenfile(filetypes=[
                                            ("MP3 Files", "*.mp3"),
                                            ("WAV Files", "*.wav"),
                                            ("All Files", "*.*")
                                        ])
    print(file_path)
    if file_path:
        music_list.insert(tk.END, str(os.path.basename(file_path.name).replace(".mp3","")))
        musics.append(f"{file_path.name}")


def new_folder():    
    dir_path = fd.askdirectory()
    print(dir_path)
    if dir_path:
        for f in os.listdir(dir_path):
            if f.endswith(".mp3"):
                music_list.insert(tk.END, str(f.replace(".mp3","")))
                musics.append(f"{dir_path}/{f}")


def select_music(event):
    global is_playing
    index = music_list.curselection()
    if index:
        file = music_list.get(index)
        music_name_label.config(text=file)

        media = instance.media_new(musics[index[0]])
        player.set_media(media)
        player.play()
        time.sleep(0.5)
        is_playing = True


        total_ms = player.get_length()
        total_sec = total_ms // 1000
        music_pos.config(to=total_sec)

        icon = tk.PhotoImage(file="SourceCode/resources/pause-solid.png")    
        pause_button.config(image=icon)
        pause_button.image = icon

        
        min = time_format.sec_to_min(total_sec)
        min_str = ""
        sec_str = ""
        if min[0] < 10:
            min_str = f"0{min[0]}"
        else:
            min_str = f"{min[0]}"
        if min[1] < 10:
            sec_str = f"0{min[1]}"
        else:
            sec_str = f"{min[1]}"
        size_label.config(text=f"{min_str} : {sec_str}")


        update_pos()


def play_pause_music():
    global is_playing
    if is_playing is True:
        player.pause()
        is_playing = False
        icon = tk.PhotoImage(file="SourceCode/resources/play-solid.png")
    else:
        player.play()
        is_playing = True
        icon = tk.PhotoImage(file="SourceCode/resources/pause-solid.png")
    pause_button.config(image=icon)
    pause_button.image = icon


def next_music():
    index = music_list.curselection()
    music_list.selection_clear(0, tk.END)

    if index:
        current = index[0]
        new_index = (current + 1) % music_list.size()
    else:
        new_index = 0

    music_list.selection_set(new_index)
    music_list.activate(new_index)
    music_list.see(new_index)
    music_list.event_generate("<<ListboxSelect>>")


def prev_music():
    index = music_list.curselection()
    music_list.selection_clear(0, tk.END)

    if index:
        current = index[0]
        new_index = (current - 1) % music_list.size()
    else:
        new_index = music_list.size() - 1

    music_list.selection_set(new_index)
    music_list.activate(new_index)
    music_list.see(new_index)
    music_list.event_generate("<<ListboxSelect>>")


def update_pos():
    if player.is_playing():
        if is_user_set_pos == False:
            current_ms = player.get_time()
            current_sec = current_ms // 1000

            music_pos.set(current_sec)

            min = time_format.sec_to_min(current_sec)
            min_str = ""
            sec_str = ""
            if min[0] < 10:
                min_str = f"0{min[0]}"
            else:
                sec_str = f"{min[0]}"
            if min[1] < 10:
                sec_str = f"0{min[1]}"
            else:
                sec_str = f"{min[1]}"

            pos_label.config(text=f"{min_str} : {sec_str}")


            window.after(500, update_pos)
    else:
        next_music()


def user_start_set_pos(event):
    global is_user_set_pos
    is_user_set_pos = True


def user_finish_set_pos(event):
    global is_user_set_pos
    is_user_set_pos = False
    time_ = music_pos.get()
    print(time_)
    player.set_time(time_ * 1000)
    window.after(500, update_pos)


def update_sound(event):
    sound = music_sound.get()
    sound_label.config(text=str(sound))
    player.audio_set_volume(sound)
    mute_button.config(relief="raised")
    if sound < 50 and sound > 0:  
        icon = tk.PhotoImage(file="SourceCode/resources/volume-low-solid.png")
    elif sound >= 50:
        icon = tk.PhotoImage(file="SourceCode/resources/volume-high-solid.png")
    else:
        icon = tk.PhotoImage(file="SourceCode/resources/volume-off-solid.png")
    mute_button.config(image=icon)
    mute_button.image = icon


def mute_sound():
    sound = music_sound.get()
    if player.audio_get_volume() == 0:
        player.audio_set_volume(sound)
        mute_button.config(relief="raised")
        if sound < 50 and sound > 0:  
            icon = tk.PhotoImage(file="SourceCode/resources/volume-low-solid.png")
        elif sound >= 50:
            icon = tk.PhotoImage(file="SourceCode/resources/volume-high-solid.png")
        else:
            icon = tk.PhotoImage(file="SourceCode/resources/volume-off-solid.png")
        mute_button.config(image=icon)
        mute_button.image = icon
    else:
        player.audio_set_volume(0)
        mute_button.config(relief="sunken")
        icon = tk.PhotoImage(file="SourceCode/resources/volume-off-solid.png")
        mute_button.config(image=icon)
        mute_button.image = icon


instance = vlc.Instance("--no-xlib", "--intf", "dummy")
player = instance.media_player_new()



is_playing = False
is_user_set_pos = False
window = tk.Tk()
window.title("Music Player")

icon = tk.PhotoImage(file="SourceCode/resources/headphones-solid.png")
window.iconphoto(False, icon)




menubar = tk.Menu(window)
window.config(menu=menubar)


fileMenu = tk.Menu(menubar)


openMenu = tk.Menu(fileMenu)
openMenu.add_command(label="Open File", accelerator="Ctrl+Alt+O", command=open_file)
window.bind_all("<Control-Alt-o>", lambda event: open_file())
openMenu.add_command(label="Open Folder", accelerator="Ctrl+Shift+O", command=open_folder)
window.bind_all("<Control-Shift-O>", lambda event: open_folder())

fileMenu.add_cascade(label="Open", menu=openMenu)




newMenu = tk.Menu(fileMenu)
newMenu.add_command(label="New File", accelerator="Ctrl+Alt+N", command=new_file)
window.bind_all("<Control-Alt-n>", lambda event: new_file())
newMenu.add_command(label="New Folder", accelerator="Ctrl+Shift+N", command=new_folder)
window.bind_all("<Control-Shift-N>", lambda event: new_folder())



fileMenu.add_cascade(label="New", menu=newMenu)



fileMenu.add_separator()
fileMenu.add_command(label="Exit", accelerator="Ctrl+Q", command=quit)
window.bind_all("<Control-q>", lambda event: quit())






menubar.add_cascade(label="File", menu=fileMenu)


musics = []
music_list = tk.Listbox(window)
music_list.bind("<<ListboxSelect>>", select_music)


music_name_label = tk.Label(window, text="there is no music")


controls_frame = tk.Frame(window)

controls_frame.columnconfigure(0, weight=1)
controls_frame.columnconfigure(1, weight=4)
controls_frame.columnconfigure(2, weight=1)


pos_frame = tk.Frame(controls_frame)

pos_label =  tk.Label(pos_frame, text="00:00")
music_pos = tk.Scale(pos_frame, from_=0, to=100, orient=tk.HORIZONTAL, showvalue=False)
size_label =  tk.Label(pos_frame, text="00:00")

music_pos.bind("<Button-1>", user_start_set_pos)
music_pos.bind("<ButtonRelease-1>", user_finish_set_pos)




buttons_frame = tk.Frame(controls_frame)

buttons_frame.columnconfigure(0, weight=1)
buttons_frame.columnconfigure(1, weight=1)
buttons_frame.columnconfigure(2, weight=1)


previous_icon = tk.PhotoImage(file="SourceCode/resources/backward-solid.png")
pause_icon = tk.PhotoImage(file="SourceCode/resources/play-solid.png")
next_icon = tk.PhotoImage(file="SourceCode/resources/forward-solid.png")

previous_button = tk.Button(buttons_frame, text="prev", image=previous_icon, command=prev_music)
pause_button = tk.Button(buttons_frame, text="pause", image=pause_icon, command=play_pause_music)
next_button = tk.Button(buttons_frame, text="next", image=next_icon, command=next_music)



sound_frame = tk.Frame(controls_frame)
sound_frame.columnconfigure(0, weight=1)
sound_frame.columnconfigure(1, weight=4)
sound_frame.columnconfigure(2, weight=1)

mute_button = tk.Button(sound_frame, command=mute_sound)
music_sound = tk.Scale(sound_frame, from_=0, to=100, orient=tk.HORIZONTAL, showvalue=False, command=update_sound)
music_sound.set(50)
sound_label = tk.Label(sound_frame, text="50")


mute_button.columnconfigure(0, weight=1)
music_sound.columnconfigure(1, weight=4)
sound_label.columnconfigure(2, weight=1)

mute_button.grid(row=0, column=0, sticky="w")
music_sound.grid(row=0, column=1, sticky="ew")
sound_label.grid(row=0, column=2, sticky="e")


previous_button.columnconfigure(0, weight=1)
pause_button.columnconfigure(1, weight=1)
next_button.columnconfigure(2, weight=1)


previous_button.grid(row=0, column=0)
pause_button.grid(row=0, column=1)
next_button.grid(row=0, column=2)


pos_label.columnconfigure(0, weight=1)
music_pos.columnconfigure(1, weight=4)
size_label.columnconfigure(2, weight=1)


pos_label.grid(row=0, column=0, sticky="w")
music_pos.grid(row=0, column=1, sticky="ew")
size_label.grid(row=0, column=2, sticky="e")




buttons_frame.columnconfigure(0, weight=1)
pos_frame.columnconfigure(1, weight=4)
sound_frame.columnconfigure(2, weight=1)



buttons_frame.grid(row=0, column=0, sticky="w")
pos_frame.grid(row=0, column=1, sticky="ew")
sound_frame.grid(row=0, column=2, sticky="e")


music_list.pack(expand=True, fill="both")
music_name_label.pack(fill="x")
controls_frame.pack(fill="x")


window.mainloop()
