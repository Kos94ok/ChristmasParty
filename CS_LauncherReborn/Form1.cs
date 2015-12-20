using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

namespace CS_LauncherReborn
{
    public partial class Form1 : Form
    {
        int gl_clientResolutionX, gl_clientResolutionY, gl_editorResolutionX, gl_editorResolutionY;
        bool gl_clientFullscreen, gl_clientBorderless, gl_editorFullscreen, gl_editorBorderless;

        public Form1()
        {
            InitializeComponent();
        }

        private void updateResolutionValues(ComboBox aspectRatio, ComboBox resolution, bool isEditor)
        {
            int i = 0, selectedIndex = 0;
            string buf;
            // Getting the screen size
            int screenX = Screen.PrimaryScreen.Bounds.Width;
            int screenY = Screen.PrimaryScreen.Bounds.Height;
            // Clearing old data
            resolution.Items.Clear();
            // Filling arrays
            int[,] dataArray = new int[64, 2];
            int index = aspectRatio.SelectedIndex;
            // 4:3 resolutions
            if (index == 0)
            {
                dataArray[i, 0] = 800; dataArray[i, 1] = 600; i += 1;
                dataArray[i, 0] = 1024; dataArray[i, 1] = 768; i += 1;
                dataArray[i, 0] = 1152; dataArray[i, 1] = 864; i += 1;
                dataArray[i, 0] = 1280; dataArray[i, 1] = 960; i += 1;
                dataArray[i, 0] = 1400; dataArray[i, 1] = 1050; i += 1;
                dataArray[i, 0] = 1600; dataArray[i, 1] = 1200; i += 1;
            }
            // 16:9 resolutions
            else if (index == 1)
            {
                dataArray[i, 0] = 1280; dataArray[i, 1] = 720; i += 1;
                dataArray[i, 0] = 1366; dataArray[i, 1] = 768; i += 1;
                dataArray[i, 0] = 1600; dataArray[i, 1] = 900; i += 1;
                dataArray[i, 0] = 1920; dataArray[i, 1] = 1080; i += 1;
                dataArray[i, 0] = 2560; dataArray[i, 1] = 1440; i += 1;
            }
            // 16:10 resolutions
            else
            {
                dataArray[i, 0] = 1280; dataArray[i, 1] = 800; i += 1;
                dataArray[i, 0] = 1440; dataArray[i, 1] = 900; i += 1;
                dataArray[i, 0] = 1680; dataArray[i, 1] = 1050; i += 1;
                dataArray[i, 0] = 1920; dataArray[i, 1] = 1200; i += 1;
                dataArray[i, 0] = 2560; dataArray[i, 1] = 1600; i += 1;
            }
            // Inserting the data
            for (int y = 0; y < i; y++)
            {
                if (screenX >= dataArray[y, 0] && screenY >= dataArray[y, 1])
                {
                    buf = dataArray[y, 0].ToString() + " x " + dataArray[y, 1].ToString();
                    resolution.Items.Add(buf);
                    if ((!isEditor && dataArray[y, 0] == gl_clientResolutionX && dataArray[y, 1] == gl_clientResolutionY)
                        || (isEditor && dataArray[y, 0] == gl_editorResolutionX && dataArray[y, 1] == gl_editorResolutionY))
                    {
                        selectedIndex = y;
                    }

                }
            }
            // Selecting something
            resolution.SelectedIndex = selectedIndex;
        }

        private int getSelectedResolution(int value, bool isEditor)
        {
            int index, selected, i = 0;
            int[,] dataArray = new int[64, 2];
            if (!isEditor) { index = drop_aspectRatio.SelectedIndex; selected = drop_resolution.SelectedIndex; }
            else { index = drop_aspectRatioEditor.SelectedIndex; selected = drop_resolutionEditor.SelectedIndex; }
            // 4:3 resolutions
            if (index == 0)
            {
                dataArray[i, 0] = 800; dataArray[i, 1] = 600; i += 1;
                dataArray[i, 0] = 1024; dataArray[i, 1] = 768; i += 1;
                dataArray[i, 0] = 1152; dataArray[i, 1] = 864; i += 1;
                dataArray[i, 0] = 1280; dataArray[i, 1] = 960; i += 1;
                dataArray[i, 0] = 1400; dataArray[i, 1] = 1050; i += 1;
                dataArray[i, 0] = 1600; dataArray[i, 1] = 1200; i += 1;
            }
            // 16:9 resolutions
            else if (index == 1)
            {
                dataArray[i, 0] = 1280; dataArray[i, 1] = 720; i += 1;
                dataArray[i, 0] = 1366; dataArray[i, 1] = 768; i += 1;
                dataArray[i, 0] = 1600; dataArray[i, 1] = 900; i += 1;
                dataArray[i, 0] = 1920; dataArray[i, 1] = 1080; i += 1;
                dataArray[i, 0] = 2560; dataArray[i, 1] = 1440; i += 1;
            }
            // 16:10 resolutions
            else
            {
                dataArray[i, 0] = 1280; dataArray[i, 1] = 800; i += 1;
                dataArray[i, 0] = 1440; dataArray[i, 1] = 900; i += 1;
                dataArray[i, 0] = 1680; dataArray[i, 1] = 1050; i += 1;
                dataArray[i, 0] = 1920; dataArray[i, 1] = 1200; i += 1;
                dataArray[i, 0] = 2560; dataArray[i, 1] = 1600; i += 1;
            }
            // Returning the requested data
            return dataArray[selected, value];
        }

        private void drop_aspectRatio_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateResolutionValues(drop_aspectRatio, drop_resolution, false);
        }

        private void drop_aspectRatioEditor_SelectedIndexChanged(object sender, EventArgs e)
        {
            updateResolutionValues(drop_aspectRatioEditor, drop_resolutionEditor, true);
        }

        private void updateClientSettings()
        {
            string buf;
            Ini myIni = new Ini("client.ini");
            // Fullscreen
            if (gl_clientFullscreen) { buf = " 1"; } else { buf = " 0"; }
            myIni.Write("Fullscreen", buf, "Display");
            // Borderless
            if (gl_clientBorderless) { buf = " 1"; } else { buf = " 0"; }
            myIni.Write("Borderless", buf, "Display");
            // ResolutionX
            buf = " " + getSelectedResolution(0, false).ToString();
            myIni.Write("ResolutionX", buf, "Display");
            // ResolutionY
            buf = " " + getSelectedResolution(1, false).ToString();
            myIni.Write("ResolutionY", buf, "Display");
            // Force Texture Preload
            if (check_texturePreload.Checked) { buf = " 1"; } else { buf = " 0"; }
            myIni.Write("ForceTexturePreload", buf, "Gameplay");
            // Force Texture Clear Up
            if (check_textureClearUp.Checked) { buf = " 1"; } else { buf = " 0"; }
            myIni.Write("ForceTextureClearUp", buf, "Gameplay");
        }

        private void updateEditorSettings()
        {
            string buf;
            Ini myIni = new Ini("editor.ini");
            // Fullscreen
            if (gl_editorFullscreen) { buf = " 1"; } else { buf = " 0"; }
            myIni.Write("Fullscreen", buf, "Display");
            // Borderless
            if (gl_editorBorderless) { buf = " 1"; } else { buf = " 0"; }
            myIni.Write("Borderless", buf, "Display");
            // ResolutionX
            buf = " " + getSelectedResolution(0, true).ToString();
            myIni.Write("ResolutionX", buf, "Display");
            // ResolutionY
            buf = " " + getSelectedResolution(1, true).ToString();
            myIni.Write("ResolutionY", buf, "Display");
            // Auto Create Directories
            if (check_foldersForModules.Checked) { buf = " 1"; } else { buf = " 0"; }
            myIni.Write("autoCreateDirectories", buf, "User Interface");
            // Max Undo Points
            buf = " " + edit_maxUndo.Text;
            myIni.Write("MaxUndoPoints", buf, "User Interface");
        }

        private void btn_launchClient_Click(object sender, EventArgs e)
        {
            updateClientSettings();
            updateEditorSettings();
            if (File.Exists("client.exe"))
            {
                var proc = new Process();
                proc.StartInfo.FileName = "client.exe";
                proc.Start();
                Application.Exit();
            }
        }

        private void btn_launchEditor_Click(object sender, EventArgs e)
        {
            updateClientSettings();
            updateEditorSettings();
            if (File.Exists("editor.exe"))
            {
                var proc = new Process();
                proc.StartInfo.FileName = "editor.exe";
                proc.Start();
                Application.Exit();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Reading client.ini
            string buf;
            Ini myIni = new Ini("client.ini");
            buf = myIni.Read("Fullscreen", "Display");  if (buf == "1") { gl_clientFullscreen = true; } else { gl_clientFullscreen = false; }
            buf = myIni.Read("Borderless", "Display");  if (buf == "1") { gl_clientBorderless = true; } else { gl_clientBorderless = false; }
            buf = myIni.Read("ResolutionX", "Display"); gl_clientResolutionX = Int32.Parse(buf);
            buf = myIni.Read("ResolutionY", "Display"); gl_clientResolutionY = Int32.Parse(buf);
            buf = myIni.Read("ForceTexturePreload", "Gameplay");
            if (buf == "1") { check_texturePreload.Checked = true; } else { check_texturePreload.Checked = false; }
            buf = myIni.Read("ForceTextureClearUp", "Gameplay");
            if (buf == "1") { check_textureClearUp.Checked = true; } else { check_textureClearUp.Checked = false; }
            
            // Reading editor.ini
            myIni = new Ini("editor.ini");
            buf = myIni.Read("Fullscreen", "Display"); if (buf == "1") { gl_editorFullscreen = true; } else { gl_editorFullscreen = false; }
            buf = myIni.Read("Borderless", "Display"); if (buf == "1") { gl_editorBorderless = true; } else { gl_editorBorderless = false; }
            buf = myIni.Read("ResolutionX", "Display"); gl_editorResolutionX = Int32.Parse(buf);
            buf = myIni.Read("ResolutionY", "Display"); gl_editorResolutionY = Int32.Parse(buf);
            buf = myIni.Read("autoCreateDirectories", "User Interface");
            if (buf == "1") { check_foldersForModules.Checked = true; } else { check_foldersForModules.Checked = false; }
            buf = myIni.Read("maxUndoPoints", "User Interface"); edit_maxUndo.Text = buf;

            // Setting the default video mode
            if (gl_clientBorderless) { drop_videoMode.SelectedIndex = 2; }
            else if (gl_clientFullscreen) { drop_videoMode.SelectedIndex = 0; }
            else { drop_videoMode.SelectedIndex = 1; }
            if (gl_editorBorderless) { drop_videoModeEditor.SelectedIndex = 2; }
            else if (gl_editorFullscreen) { drop_videoModeEditor.SelectedIndex = 0; }
            else { drop_videoModeEditor.SelectedIndex = 1; }

            // Setting the default aspect ratio
            float aspect = (float)gl_clientResolutionX / gl_clientResolutionY;
            if (System.Math.Abs(aspect - 1.78) < 0.01) { drop_aspectRatio.SelectedIndex = 1; }
            else if (System.Math.Abs(aspect - 1.6) < 0.01) { drop_aspectRatio.SelectedIndex = 2; }
            else { drop_aspectRatio.SelectedIndex = 0; }
            aspect = (float)gl_editorResolutionX / gl_editorResolutionY;
            if (System.Math.Abs(aspect - 1.78) < 0.01) { drop_aspectRatioEditor.SelectedIndex = 1; }
            else if (System.Math.Abs(aspect - 1.6) < 0.01) { drop_aspectRatioEditor.SelectedIndex = 2; }
            else { drop_aspectRatioEditor.SelectedIndex = 0; }
        }

        private void drop_videoMode_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (drop_videoMode.SelectedIndex == 0) { gl_clientBorderless = false; gl_clientFullscreen = true; }
            else if (drop_videoMode.SelectedIndex == 1) { gl_clientBorderless = false; gl_clientFullscreen = false; }
            else { gl_clientBorderless = true; gl_clientFullscreen = false; }
        }

        private void drop_videoModeEditor_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (drop_videoModeEditor.SelectedIndex == 0) { gl_editorBorderless = false; gl_editorFullscreen = true; }
            else if (drop_videoModeEditor.SelectedIndex == 1) { gl_editorBorderless = false; gl_editorFullscreen = false; }
            else { gl_editorBorderless = true; gl_editorFullscreen = false; }
        }
    }
}
