using System;
using System.Collections.Generic;
using System.Diagnostics;
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

namespace GameLauncher
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        bool isRunning = false;

        public MainWindow()
        {
            InitializeComponent();
        }

        /** 
         * Launcht the game
         */
        private void btnStartGame_Click(object sender, RoutedEventArgs e)
        {
            string exePath = "E:\\RandomProjects\\Engine\\src\\bin\\x64\\Debug\\GameEngine.exe";

            Process.Start(exePath);
            System.Windows.Application.Current.Shutdown();

        }

        private void btnUpdate_Click(object sender, RoutedEventArgs e)
        {
            MessageBoxResult result = MessageBox.Show(
                "Failed to update the game. Try again?",
                "ERROR!",
                MessageBoxButton.YesNo,
                MessageBoxImage.Error
            );
        }
    }
}
