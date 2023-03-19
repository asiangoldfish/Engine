using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Runtime.CompilerServices;

namespace GameLauncher.View.UserControls
{
    /// <summary>
    /// Interaction logic for InputField.xaml
    /// </summary>
    public partial class InputField : UserControl, INotifyPropertyChanged
    {
        // Member variables
        private string placeholder;         // Active placeholder string
        private string defaultPlaceholder;  // Default placeholder string

        // Events
        public event PropertyChangedEventHandler? PropertyChanged;

        // Contructor
        public InputField()
        {
            placeholder = string.Empty;
            defaultPlaceholder = string.Empty;

            DataContext = this;
            InitializeComponent();
        }

        // Properties
        public string Placeholder
        { 
            get { return placeholder; }
            set 
            {  
                placeholder = value;
                defaultPlaceholder = placeholder;
                OnPropertyChanged();
            } 
        }

        private void tbInput_GotFocus(object sender, RoutedEventArgs e)
        {
            tbPlaceholder.Text = "";
        }

        private void tbInput_LostFocus(object sender, RoutedEventArgs e)
        {
            if (tbInput.Text == "")
            {
                tbPlaceholder.Text = defaultPlaceholder;
            }
        }

        private void tbInput_TextChanged(object sender, TextChangedEventArgs e)
        {
            /*
             * We want to prevent any whitespaces from being input. To do this,
             * we delete the last character and assume that's the whitespace.
             * When this happens, the text cursor is moved back to the start.
             * We fix this by saving the old position, removing the whitespace
             * and then restore the position.
             */
            int oldIndex = tbInput.CaretIndex;

            if (tbInput.Text.EndsWith(' '))
            {
                tbInput.Text = tbInput.Text.Remove(tbInput.Text.Length-1);
                tbInput.CaretIndex = oldIndex - 1;
            }
        }

        private void OnPropertyChanged( [CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
