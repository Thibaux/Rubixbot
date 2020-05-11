using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToKociemba
{
    class Program
    {
        static void Main(string[] args)
        {
            // ToKociemba WWWWWGGGGGYRRRWBBOOOGYRRWBOOGGYRRRWBBOOOBBBYYYYY => F            

            string input = null;
            if (Console.IsInputRedirected)
            {
                Console.SetIn(new StreamReader(Console.OpenStandardInput(8192))); // This will allow input >256 chars
                while (Console.In.Peek() != -1)
                {
                    input = Console.In.ReadLine();
                }
            }
            else
            {
                //Console.WriteLine(args[0]);
                //Console.WriteLine(args[0].Length);
                input = args[0].ToString();
            }

            // U => UP ; L => LEFT ; F => FRONT ; R => RIGHT ; B => BACK ; D => DOWN	
            input = input.Replace('W', 'U');
            input = input.Replace('G', 'L');
            input = input.Replace('R', 'F');
            input = input.Replace('B', 'R');
            input = input.Replace('O', 'B');
            input = input.Replace('Y', 'D');
                        
            string Notation_ULFRBD;

            //Désignation des 12 arêtes
            Notation_ULFRBD = input[6].ToString() + input[12].ToString() + " ";   // à la place de UF ...
            Notation_ULFRBD += input[4].ToString() + input[15].ToString() + " ";    // à la place de UR ...
            Notation_ULFRBD += input[1].ToString() + input[18].ToString() + " ";    // à la place de UB ...
            Notation_ULFRBD += input[3].ToString() + input[9].ToString() + " ";    // à la place de UL ...
            Notation_ULFRBD += input[41].ToString() + input[32].ToString() + " ";    // à la place de DF ...
            Notation_ULFRBD += input[44].ToString() + input[35].ToString() + " ";    // à la place de DR ...
            Notation_ULFRBD += input[46].ToString() + input[38].ToString() + " ";    // à la place de DB ...
            Notation_ULFRBD += input[43].ToString() + input[29].ToString() + " ";    // à la place de DL ...
            Notation_ULFRBD += input[23].ToString() + input[24].ToString() + " ";    // à la place de FR ...
            Notation_ULFRBD += input[22].ToString() + input[21].ToString() + " ";    // à la place de FL ...
            Notation_ULFRBD += input[26].ToString() + input[25].ToString() + " ";    // à la place de BR ...
            Notation_ULFRBD += input[27].ToString() + input[20].ToString() + " ";    // à la place de BL ...

            //Désignation des 8 coins
            Notation_ULFRBD += input[7].ToString() + input[13].ToString() + input[14].ToString() + " ";   // à la place de UFR
            Notation_ULFRBD += input[2].ToString() + input[16].ToString() + input[17].ToString() + " ";   // à la place de URB
            Notation_ULFRBD += input[0].ToString() + input[19].ToString() + input[8].ToString() + " ";   // à la place de UBL
            Notation_ULFRBD += input[5].ToString() + input[10].ToString() + input[11].ToString() + " ";   // à la place de ULF
            Notation_ULFRBD += input[42].ToString() + input[34].ToString() + input[33].ToString() + " ";   // à la place de DRF
            Notation_ULFRBD += input[40].ToString() + input[31].ToString() + input[30].ToString() + " ";   // à la place de DFL
            Notation_ULFRBD += input[45].ToString() + input[28].ToString() + input[39].ToString() + " ";   // à la place de DLB
            Notation_ULFRBD += input[47].ToString() + input[37].ToString() + input[36].ToString();   // à la place de DBR
            
            Console.WriteLine(Notation_ULFRBD); 
        }
    }
}
