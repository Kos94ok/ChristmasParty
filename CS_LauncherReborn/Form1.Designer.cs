namespace CS_LauncherReborn
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_launchClient = new System.Windows.Forms.Button();
            this.btn_launchEditor = new System.Windows.Forms.Button();
            this.drop_screenMode = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.drop_videoMode = new System.Windows.Forms.ComboBox();
            this.drop_aspectRatio = new System.Windows.Forms.ComboBox();
            this.drop_resolution = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.check_textureClearUp = new System.Windows.Forms.CheckBox();
            this.check_texturePreload = new System.Windows.Forms.CheckBox();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label6 = new System.Windows.Forms.Label();
            this.edit_maxUndo = new System.Windows.Forms.TextBox();
            this.check_foldersForModules = new System.Windows.Forms.CheckBox();
            this.label3 = new System.Windows.Forms.Label();
            this.drop_videoModeEditor = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.drop_aspectRatioEditor = new System.Windows.Forms.ComboBox();
            this.label5 = new System.Windows.Forms.Label();
            this.drop_resolutionEditor = new System.Windows.Forms.ComboBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // btn_launchClient
            // 
            this.btn_launchClient.Location = new System.Drawing.Point(12, 379);
            this.btn_launchClient.Name = "btn_launchClient";
            this.btn_launchClient.Size = new System.Drawing.Size(102, 23);
            this.btn_launchClient.TabIndex = 0;
            this.btn_launchClient.Text = "Launch Client";
            this.btn_launchClient.UseVisualStyleBackColor = true;
            this.btn_launchClient.Click += new System.EventHandler(this.btn_launchClient_Click);
            // 
            // btn_launchEditor
            // 
            this.btn_launchEditor.Location = new System.Drawing.Point(196, 379);
            this.btn_launchEditor.Name = "btn_launchEditor";
            this.btn_launchEditor.Size = new System.Drawing.Size(102, 23);
            this.btn_launchEditor.TabIndex = 1;
            this.btn_launchEditor.Text = "Launch Editor";
            this.btn_launchEditor.UseVisualStyleBackColor = true;
            this.btn_launchEditor.Click += new System.EventHandler(this.btn_launchEditor_Click);
            // 
            // drop_screenMode
            // 
            this.drop_screenMode.AutoSize = true;
            this.drop_screenMode.Location = new System.Drawing.Point(6, 9);
            this.drop_screenMode.Name = "drop_screenMode";
            this.drop_screenMode.Size = new System.Drawing.Size(74, 13);
            this.drop_screenMode.TabIndex = 3;
            this.drop_screenMode.Text = "Screen Mode:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 36);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(71, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Aspect Ratio:";
            // 
            // drop_videoMode
            // 
            this.drop_videoMode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.drop_videoMode.FormattingEnabled = true;
            this.drop_videoMode.Items.AddRange(new object[] {
            "Fullscreen",
            "Window",
            "Borderless"});
            this.drop_videoMode.Location = new System.Drawing.Point(135, 6);
            this.drop_videoMode.Name = "drop_videoMode";
            this.drop_videoMode.Size = new System.Drawing.Size(121, 21);
            this.drop_videoMode.TabIndex = 5;
            this.drop_videoMode.SelectedIndexChanged += new System.EventHandler(this.drop_videoMode_SelectedIndexChanged);
            // 
            // drop_aspectRatio
            // 
            this.drop_aspectRatio.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.drop_aspectRatio.FormattingEnabled = true;
            this.drop_aspectRatio.Items.AddRange(new object[] {
            "4:3",
            "16:9",
            "16:10"});
            this.drop_aspectRatio.Location = new System.Drawing.Point(135, 33);
            this.drop_aspectRatio.Name = "drop_aspectRatio";
            this.drop_aspectRatio.Size = new System.Drawing.Size(121, 21);
            this.drop_aspectRatio.TabIndex = 6;
            this.drop_aspectRatio.SelectedIndexChanged += new System.EventHandler(this.drop_aspectRatio_SelectedIndexChanged);
            // 
            // drop_resolution
            // 
            this.drop_resolution.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.drop_resolution.FormattingEnabled = true;
            this.drop_resolution.Location = new System.Drawing.Point(135, 60);
            this.drop_resolution.Name = "drop_resolution";
            this.drop_resolution.Size = new System.Drawing.Size(121, 21);
            this.drop_resolution.TabIndex = 7;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(6, 63);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(60, 13);
            this.label2.TabIndex = 8;
            this.label2.Text = "Resolution:";
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(12, 118);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(286, 255);
            this.tabControl1.TabIndex = 9;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.check_textureClearUp);
            this.tabPage1.Controls.Add(this.check_texturePreload);
            this.tabPage1.Controls.Add(this.drop_screenMode);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.drop_resolution);
            this.tabPage1.Controls.Add(this.drop_videoMode);
            this.tabPage1.Controls.Add(this.drop_aspectRatio);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(278, 229);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Client";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // check_textureClearUp
            // 
            this.check_textureClearUp.AutoSize = true;
            this.check_textureClearUp.Location = new System.Drawing.Point(9, 121);
            this.check_textureClearUp.Name = "check_textureClearUp";
            this.check_textureClearUp.Size = new System.Drawing.Size(136, 17);
            this.check_textureClearUp.TabIndex = 10;
            this.check_textureClearUp.Text = "Force Texture Clear Up";
            this.check_textureClearUp.UseVisualStyleBackColor = true;
            // 
            // check_texturePreload
            // 
            this.check_texturePreload.AutoSize = true;
            this.check_texturePreload.Location = new System.Drawing.Point(9, 98);
            this.check_texturePreload.Name = "check_texturePreload";
            this.check_texturePreload.Size = new System.Drawing.Size(131, 17);
            this.check_texturePreload.TabIndex = 9;
            this.check_texturePreload.Text = "Force Texture Preload";
            this.check_texturePreload.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.label6);
            this.tabPage2.Controls.Add(this.edit_maxUndo);
            this.tabPage2.Controls.Add(this.check_foldersForModules);
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.drop_videoModeEditor);
            this.tabPage2.Controls.Add(this.label4);
            this.tabPage2.Controls.Add(this.drop_aspectRatioEditor);
            this.tabPage2.Controls.Add(this.label5);
            this.tabPage2.Controls.Add(this.drop_resolutionEditor);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(278, 229);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Editor";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 124);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(91, 13);
            this.label6.TabIndex = 18;
            this.label6.Text = "Max Undo Points:";
            // 
            // edit_maxUndo
            // 
            this.edit_maxUndo.Location = new System.Drawing.Point(135, 121);
            this.edit_maxUndo.Name = "edit_maxUndo";
            this.edit_maxUndo.Size = new System.Drawing.Size(121, 20);
            this.edit_maxUndo.TabIndex = 17;
            // 
            // check_foldersForModules
            // 
            this.check_foldersForModules.AutoSize = true;
            this.check_foldersForModules.Location = new System.Drawing.Point(9, 98);
            this.check_foldersForModules.Name = "check_foldersForModules";
            this.check_foldersForModules.Size = new System.Drawing.Size(155, 17);
            this.check_foldersForModules.TabIndex = 16;
            this.check_foldersForModules.Text = "Create Folders For Modules";
            this.check_foldersForModules.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(6, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(74, 13);
            this.label3.TabIndex = 10;
            this.label3.Text = "Screen Mode:";
            // 
            // drop_videoModeEditor
            // 
            this.drop_videoModeEditor.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.drop_videoModeEditor.FormattingEnabled = true;
            this.drop_videoModeEditor.Items.AddRange(new object[] {
            "Fullscreen",
            "Window",
            "Borderless"});
            this.drop_videoModeEditor.Location = new System.Drawing.Point(135, 6);
            this.drop_videoModeEditor.Name = "drop_videoModeEditor";
            this.drop_videoModeEditor.Size = new System.Drawing.Size(121, 21);
            this.drop_videoModeEditor.TabIndex = 12;
            this.drop_videoModeEditor.SelectedIndexChanged += new System.EventHandler(this.drop_videoModeEditor_SelectedIndexChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 63);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 15;
            this.label4.Text = "Resolution:";
            // 
            // drop_aspectRatioEditor
            // 
            this.drop_aspectRatioEditor.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.drop_aspectRatioEditor.FormattingEnabled = true;
            this.drop_aspectRatioEditor.Items.AddRange(new object[] {
            "4:3",
            "16:9",
            "16:10"});
            this.drop_aspectRatioEditor.Location = new System.Drawing.Point(135, 33);
            this.drop_aspectRatioEditor.Name = "drop_aspectRatioEditor";
            this.drop_aspectRatioEditor.Size = new System.Drawing.Size(121, 21);
            this.drop_aspectRatioEditor.TabIndex = 13;
            this.drop_aspectRatioEditor.SelectedIndexChanged += new System.EventHandler(this.drop_aspectRatioEditor_SelectedIndexChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 36);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(71, 13);
            this.label5.TabIndex = 11;
            this.label5.Text = "Aspect Ratio:";
            // 
            // drop_resolutionEditor
            // 
            this.drop_resolutionEditor.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.drop_resolutionEditor.FormattingEnabled = true;
            this.drop_resolutionEditor.Location = new System.Drawing.Point(135, 60);
            this.drop_resolutionEditor.Name = "drop_resolutionEditor";
            this.drop_resolutionEditor.Size = new System.Drawing.Size(121, 21);
            this.drop_resolutionEditor.TabIndex = 14;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(13, 13);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(285, 99);
            this.pictureBox1.TabIndex = 10;
            this.pictureBox1.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(310, 414);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.btn_launchEditor);
            this.Controls.Add(this.btn_launchClient);
            this.Name = "Form1";
            this.Text = "Simple Link Launcher";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btn_launchClient;
        private System.Windows.Forms.Button btn_launchEditor;
        private System.Windows.Forms.Label drop_screenMode;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox drop_videoMode;
        private System.Windows.Forms.ComboBox drop_aspectRatio;
        private System.Windows.Forms.ComboBox drop_resolution;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox drop_videoModeEditor;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ComboBox drop_aspectRatioEditor;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox drop_resolutionEditor;
        private System.Windows.Forms.CheckBox check_textureClearUp;
        private System.Windows.Forms.CheckBox check_texturePreload;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox edit_maxUndo;
        private System.Windows.Forms.CheckBox check_foldersForModules;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

