using System;
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
    /// Interaction logic for Login.xaml
    /// </summary>
    public partial class Login : UserControl
    {
        public Login()
        {
            InitializeComponent();
        }

        private void btnLogin_Click(object sender, RoutedEventArgs e)
        {
            // If the password input field is not empty, then we clear it and
            // re-focus it
            if (Password.Placeholder != "")
            {
                //tbPassword.Focus();
                //tbPassword.Text = "";
                Password.Placeholder = "Test";
            }
        }

        /*
        private void tbPassword_LostFocus(object sender, RoutedEventArgs e)
        {
            if (tbPassword.Text == "")
            {
                tbPasswordPlaceholder.Text = "Password";
            }
        }
        */
    }
}
