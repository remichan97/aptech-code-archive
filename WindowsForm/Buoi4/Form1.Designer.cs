
namespace Buoi4
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnTinhNghiem = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.txtHeSo1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txtHeSo2 = new System.Windows.Forms.TextBox();
            this.txtHeSo3 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtNghiem1 = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtNghiem2 = new System.Windows.Forms.TextBox();
            this.txtNghiemKep = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.btnReset = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnTinhNghiem
            // 
            this.btnTinhNghiem.Location = new System.Drawing.Point(473, 104);
            this.btnTinhNghiem.Name = "btnTinhNghiem";
            this.btnTinhNghiem.Size = new System.Drawing.Size(75, 23);
            this.btnTinhNghiem.TabIndex = 0;
            this.btnTinhNghiem.Text = "Tính nghiệm";
            this.btnTinhNghiem.UseVisualStyleBackColor = true;
            this.btnTinhNghiem.Click += new System.EventHandler(this.btnTinhNghiem_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(44, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Hệ số a";
            // 
            // txtHeSo1
            // 
            this.txtHeSo1.Location = new System.Drawing.Point(71, 10);
            this.txtHeSo1.Name = "txtHeSo1";
            this.txtHeSo1.Size = new System.Drawing.Size(113, 20);
            this.txtHeSo1.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(192, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Hệ số b";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(372, 13);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(45, 13);
            this.label3.TabIndex = 4;
            this.label3.Text = "Hệ số C";
            // 
            // txtHeSo2
            // 
            this.txtHeSo2.Location = new System.Drawing.Point(242, 10);
            this.txtHeSo2.Name = "txtHeSo2";
            this.txtHeSo2.Size = new System.Drawing.Size(113, 20);
            this.txtHeSo2.TabIndex = 5;
            // 
            // txtHeSo3
            // 
            this.txtHeSo3.Location = new System.Drawing.Point(435, 10);
            this.txtHeSo3.Name = "txtHeSo3";
            this.txtHeSo3.Size = new System.Drawing.Size(113, 20);
            this.txtHeSo3.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(52, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Nghiệm 1";
            // 
            // txtNghiem1
            // 
            this.txtNghiem1.Location = new System.Drawing.Point(71, 61);
            this.txtNghiem1.Name = "txtNghiem1";
            this.txtNghiem1.ReadOnly = true;
            this.txtNghiem1.Size = new System.Drawing.Size(106, 20);
            this.txtNghiem1.TabIndex = 8;
            this.txtNghiem1.TabStop = false;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(184, 64);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(52, 13);
            this.label5.TabIndex = 9;
            this.label5.Text = "Nghiệm 2";
            // 
            // txtNghiem2
            // 
            this.txtNghiem2.Location = new System.Drawing.Point(242, 61);
            this.txtNghiem2.Name = "txtNghiem2";
            this.txtNghiem2.ReadOnly = true;
            this.txtNghiem2.Size = new System.Drawing.Size(113, 20);
            this.txtNghiem2.TabIndex = 10;
            this.txtNghiem2.TabStop = false;
            // 
            // txtNghiemKep
            // 
            this.txtNghiemKep.Location = new System.Drawing.Point(435, 61);
            this.txtNghiemKep.Name = "txtNghiemKep";
            this.txtNghiemKep.ReadOnly = true;
            this.txtNghiemKep.Size = new System.Drawing.Size(113, 20);
            this.txtNghiemKep.TabIndex = 11;
            this.txtNghiemKep.TabStop = false;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(363, 64);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(64, 13);
            this.label6.TabIndex = 12;
            this.label6.Text = "Nghiệm kép";
            // 
            // btnReset
            // 
            this.btnReset.Location = new System.Drawing.Point(366, 103);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(75, 23);
            this.btnReset.TabIndex = 13;
            this.btnReset.Text = "Nhập lại";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(560, 148);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.txtNghiemKep);
            this.Controls.Add(this.txtNghiem2);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.txtNghiem1);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtHeSo3);
            this.Controls.Add(this.txtHeSo2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtHeSo1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.btnTinhNghiem);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Giải phương trình bậc 2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnTinhNghiem;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtHeSo1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtHeSo2;
        private System.Windows.Forms.TextBox txtHeSo3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtNghiem1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtNghiem2;
        private System.Windows.Forms.TextBox txtNghiemKep;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button btnReset;
    }
}

