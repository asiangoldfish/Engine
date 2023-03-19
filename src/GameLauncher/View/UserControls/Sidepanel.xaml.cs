﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace GameLauncher.View.UserControls
{
    /// <summary>
    /// Interaction logic for Sidepanel.xaml
    /// </summary>
    public partial class Sidepanel : UserControl
    {
        public Sidepanel()
        {
            InitializeComponent();
        }

        private void btnSettings_Click(object sender, RoutedEventArgs e)
        {
            //MessageBox.Show("Failed to update the game. Try again?", "ERROR!", MessageBoxButton.YesNo, MessageBoxImage.Error);

            MessageBoxResult result = MessageBox.Show(
                "Failed to update the game. Try again?", 
                "ERROR!",
                MessageBoxButton.YesNo, 
                MessageBoxImage.Error
                );

        }

        private void btnQuit_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Application.Current.Shutdown();
        }
    }
}
