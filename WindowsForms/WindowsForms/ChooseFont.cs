﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Text;

namespace WindowsForms
{
	public partial class ChooseFont : Form
	{
		public Font Font { get; set; }
		public string Filename { get; set; }
		public ChooseFont()
		{
			InitializeComponent();
			comboBoxChooseFont.Items.AddRange(GetFontListFromCurrentDirectoryByExtension("*.ttf"));
			comboBoxChooseFont.Items.AddRange(GetFontListFromCurrentDirectoryByExtension("*.otf"));
			comboBoxChooseFont.SelectedIndex = 0;   //Если из списка ничего не выбрано, то 'SelectedIndex = -1';
													//comboBoxChooseFont.SelectedItem = comboBoxChooseFont.Items[0];
		}
		public ChooseFont(MainForm parent, string font_name, int font_size) : this()
		{
			nudFontSize.Value = font_size;
			//comboBoxChooseFont.SelectedText = font_name;
			int index = comboBoxChooseFont.FindStringExact(font_name);
			comboBoxChooseFont.SelectedIndex = index;
			Font = lblExample.Font;
			Filename = font_name;
		}
		string[] GetFontListFromCurrentDirectoryByExtension(string extension)
		{
			Console.WriteLine(Application.ExecutablePath);
			string execution_path = Path.GetDirectoryName(Application.ExecutablePath);
			Console.WriteLine(execution_path);
			Directory.SetCurrentDirectory($"{execution_path}\\..\\..\\Fonts");
			Console.WriteLine(Directory.GetCurrentDirectory());
			string[] fonts = Directory.GetFiles(Directory.GetCurrentDirectory(), extension);
			for (int i = 0; i < fonts.Length; i++)
			{
				fonts[i] = fonts[i].Split('\\').Last();
			}
			return fonts;
		}
		void SetFont(string filename, float size = 32)
		{
			PrivateFontCollection pfc = new PrivateFontCollection();
			pfc.AddFontFile(filename);
			lblExample.Font = new Font(pfc.Families[0], size);
		}

		private void comboBoxChooseFont_SelectedIndexChanged(object sender, EventArgs e)
		{
			if ((sender as ComboBox).SelectedItem != null)
				SetFont((sender as ComboBox).SelectedItem.ToString());
		}

		private void btnOK_Click(object sender, EventArgs e)
		{
			Font = lblExample.Font;
			Filename = comboBoxChooseFont.SelectedItem.ToString();
		}

		private void nudFontSize_ValueChanged(object sender, EventArgs e)
		{
			//lblExample.Font.Size = (float)(sender as NumericUpDown).Value;
			SetFont(comboBoxChooseFont.SelectedItem.ToString(), (float)nudFontSize.Value);
		}
	}
}
