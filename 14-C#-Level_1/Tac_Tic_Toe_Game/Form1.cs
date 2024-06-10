using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tac_Tic_Toe_Game.Properties;

namespace Tac_Tic_Toe_Game
{
    public partial class Tac_Tic_Toe_Game : Form
    {
        public Tac_Tic_Toe_Game()
        {
            InitializeComponent();
        }

        enum enPlayer
        {
            Player1,
            Player2
        }

        enum enWinner
        {
            Player1,
            Player2,
            Draw,
            GameInProgress
        }

        struct stGameStatus
        {
            public enWinner Winner;
            public bool GameOver;
            public short PlayCount;
        }

        enPlayer PlayerTurn = enPlayer.Player1;

        stGameStatus GameStatus;

        private void RestButton(Button b)
        {
            b.Tag = "?";
            b.Image = Resources.question_mark_96;
            b.BackColor = Color.Transparent;
        }
        private void RestartGame()
        {
            RestButton(btn1);
            RestButton(btn2);
            RestButton(btn3);
            RestButton(btn4);
            RestButton(btn5);
            RestButton(btn6);
            RestButton(btn7);
            RestButton(btn8);
            RestButton(btn9);

            PlayerTurn = enPlayer.Player1;
            lbWhoIsWinner.Text = "In Progress";
            lbPlayer.Text = "Player 1";
            GameStatus.GameOver = false;
            GameStatus.Winner = enWinner.GameInProgress;
            GameStatus.PlayCount = 0;
        }
        public void EndGame()
        {
            lbPlayer.Text = "Game Over";
            switch(GameStatus.Winner)
            {
                case enWinner.Player1:
                    lbWhoIsWinner.Text = "Player 1";
                    break;
                case enWinner.Player2:
                    lbWhoIsWinner.Text = "Player 2";
                    break;
                default:
                    lbWhoIsWinner.Text = "Draw";
                    break;
            }

            MessageBox.Show("GameOver", "GameOver", MessageBoxButtons.OK,MessageBoxIcon.Information);
        }
        public bool ChecValues(Button b1, Button b2, Button b3)
        {
            if (b1.Tag.ToString() != "?"
                && b1.Tag.ToString() == b2.Tag.ToString()
                && b1.Tag.ToString() == b3.Tag.ToString())
            {
                b1.BackColor = Color.Green;
                b2.BackColor = Color.Green;
                b3.BackColor = Color.Green;

                if (b1.Tag.ToString() == "X")
                {
                    GameStatus.Winner = enWinner.Player1;
                    GameStatus.GameOver = true;
                    EndGame();
                    return true;
                }
                else
                {
                    GameStatus.Winner = enWinner.Player2;
                    GameStatus.GameOver = true;
                    EndGame();
                    return true;
                }
            }

            GameStatus.GameOver = false;
            return false;
        }

        public void CheckWinner()
        {
            if (ChecValues(btn1, btn2, btn2))
                return;

            if (ChecValues(btn4, btn5, btn6))
                return;

            if (ChecValues(btn7, btn8, btn9))
                return;

            if (ChecValues(btn1, btn4, btn7))
                return;

            if (ChecValues(btn2, btn5, btn8))
                return;

            if (ChecValues(btn3, btn6, btn9))
                return;

            if (ChecValues(btn1, btn5, btn9))
                return;

            if (ChecValues(btn3, btn5, btn7))
                return;

        }
        public void ChangeImge(Button btn)
        {
            if(btn.Tag.ToString() == "?")
            {
                switch(PlayerTurn)
                {
                    case enPlayer.Player1:
                        btn.Image = Resources.X;
                        PlayerTurn = enPlayer.Player2;
                        lbPlayer.Text = "Player 2";
                        GameStatus.PlayCount++;
                        btn.Tag = "X";
                        CheckWinner();
                        break;
                    case enPlayer.Player2:
                        btn.Image = Resources.O;
                        PlayerTurn = enPlayer.Player1;
                        lbPlayer.Text = "Player 1";
                        GameStatus.PlayCount++;
                        btn.Tag = "O";
                        CheckWinner();
                        break;
                }
            }
            else
            {
                MessageBox.Show("Wrong Choice", "Wrong", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            if(GameStatus.PlayCount == 9)
            {
                GameStatus.GameOver = true;
                GameStatus.Winner = enWinner.Draw;
                EndGame();
            }
        }

        private void Tac_Tic_Toe_Game_Paint(object sender, PaintEventArgs e)
        {
            Color White = Color.FromArgb(255, 255, 255, 255);
            Pen WhitePen = new Pen(White,15);

            WhitePen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            WhitePen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(WhitePen, 340, 185, 720, 185);
            e.Graphics.DrawLine(WhitePen, 340, 315, 720, 315);

            e.Graphics.DrawLine(WhitePen, 465, 65, 465, 435);
            e.Graphics.DrawLine(WhitePen, 595, 65, 595, 435);

        }

        private void btn_Click(object sender, EventArgs e)
        {
            ChangeImge((Button)sender);
        }
        private void btnRestart_Click(object sender, EventArgs e)
        {
            RestartGame();
        }
    }
}
