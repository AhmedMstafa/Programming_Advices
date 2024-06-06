using System;
using System.Linq;

namespace Main3
{
    internal class Program
    {

        enum enWeekDays
        {
            Monday,     // 0
            Tuesday,    // 1
            Wednesday,  // 2
            Thursday,   // 3
            Friday,     // 4
            Saturday,   // 5
            Sunday      // 6
        }

        //if you set a value , it will auto number everything after it.
        enum enCategories
        {
            Electronics,    // 0
            Food,           // 1
            Automotive = 6, // 6
            Arts,           // 7
            BeautyCare,     // 8
            Fashion         // 9
        }


        //Enum can have any numarical data type byte, sbyte, short, ushort, int, uint, long, or ulong
        //but not string

        enum enCategories2 : byte
        {
            Electronics = 1,
            Food = 5,
            Automotive = 6,
            Arts = 10,
            BeautyCare = 11,
            Fashion = 15
        }

        struct stStudent
        {
            public string FirstName;
            public string LastName;
        }

        enum WeekDays
        {
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday,
            Sunday
        }

        static void Main(string[] args)
        {
            /*
            
            Syntax

            Console.WriteLine("Hello World.");

            Console.ReadKey();

             */

            /*
             WriteLine

            Console.WriteLine("Hello World!");
            Console.WriteLine("My Name is Mohammed Abu-Hadhoud");
            Console.WriteLine("I am Learning C#");
            Console.WriteLine("It is an easy language to learn :-)");
            Console.WriteLine("The sum of 10 + 20 is " + (10 + 20));
            Console.ReadKey();
             */

            /*
             Write

            Console.WriteLine("Hello World!");
            Console.WriteLine("My Name is Mohammed Abu-Hadhoud");
            Console.Write("I am Learning C#");
            Console.Write("It is an easy language to learn :-)");
            Console.Write("The sum of 10 + 20 is " + (10 + 20));
            Console.ReadKey();
             */

            /*
             Formatted String

              Console.WriteLine("{0} {1}", "Welcome to", "ProgrammingAvices");
              Console.WriteLine("Hi MyName is: {0} I live in {1}", "Mohammed", "Jordan");

                Console.ReadKey();
             */

            /*
             Escape Characters

            Console.WriteLine("Useful Escape Characters:\n");

            //Newline
            Console.WriteLine("Newline:");
            Console.WriteLine( "Welcome to \n ProgrammingAvices\n");

            //Tab
            Console.WriteLine("Tab:");
            Console.WriteLine("Welcome to\tProgrammingAvices\n");

            //Backspace
            Console.WriteLine("Backspace:");
            Console.WriteLine("Welcome to \bProgrammingAvices\n");

            //Single quote
            Console.WriteLine("Single Quote:");
            Console.WriteLine("Welcome to \' ProgrammingAvices\n");

            //Double quote
            Console.WriteLine("Double Quote:");
            Console.WriteLine("Welcome to \" ProgrammingAvices\n");

            //Backslash
            Console.WriteLine("Backslash:");
            Console.WriteLine("Welcome to \\ ProgrammingAvices\n");

            //Alert
            Console.WriteLine("Alert:");
            Console.WriteLine("\a");


            Console.ReadKey();

             */

            /*
             Single Line/Multiple Lines Comments

                      //this is a single line comment 
            Console.Write("My Name is Mohammed Abu-Hadhoud ");

            This is 
            a multiple line
            comment.

            Console.ReadKey();

            */

            /*
             Vairables

            string MyName = "Mohammed Abu-Hadhoud";
            Console.WriteLine(MyName);

            int x=10; int y=20;

            Console.WriteLine("x=" + x);
            Console.WriteLine("y=" + y);
            //this line will give wrong answer :-)
            Console.WriteLine("x+y=" + x + y);

            //this line will give right answer :-)
            Console.WriteLine("x+y=" + (x + y));

            //other common data types
            double MyDouble = 25.89D;
            char MyLetter = 'M';
            bool MyBool = true;

            Console.ReadKey();

             */

            /* Implicitly typed variables
             Alternatively in C#, we can declare a variable without knowing 
             its type using var keyword. 
             Such variables are called implicitly typed local variables.

             Variables declared using var keyword must be initialized at the time of declaration.

            var x = 10;
            var y = 10.5;
            var z = "Mohammed";

            Console.WriteLine("x={0}, y={1}, z={2}", x, y, z);

            Console.ReadKey();
            */

            /*  Numbers Datatypes
                //Byte

            byte b1 = 255;
            //  byte b2 = -128;// compile-time error: Constant value '-128' cannot be converted to a 'byte'
            sbyte sb1 = -128;
            sbyte sb2 = 127;
            Console.WriteLine("\nByte:");
            Console.WriteLine("Min={0} , Max={1}", Byte.MinValue, Byte.MaxValue);


            Console.WriteLine("\nSByte:");
            Console.WriteLine("Min={0} , Max={1}", SByte.MinValue, SByte.MaxValue);

            //Short
            short s1 = -32768;
            short s2 = 32767;
            // short s3 = 35000;//Compile-time error: Constant value '35000' cannot be converted to a 'short'

            ushort us1 = 65535;
            //  ushort us2 = -32000; //Compile-time error: Constant value '-32000' cannot be converted to a 'ushort'

            Console.WriteLine("\nShort:");
            Console.WriteLine("Min={0} , Max={1}", Int16.MinValue, Int16.MaxValue);

            Console.WriteLine("\nUShort:");
            Console.WriteLine("Min={0} , Max={1}", UInt16.MinValue, UInt16.MaxValue);

            //int
            int i = -2147483648;
            int j = 2147483647;
            //  int k = 4294967295; //Compile-time error: Cannot implicitly convert type 'uint' to 'int'.

            uint ui1 = 4294967295;
            // uint ui2 = -1; //Compile-time error: Constant value '-1' cannot be converted to a 'uint'

            Console.WriteLine("\nInt:");
            Console.WriteLine("Min={0} , Max={1}", Int32.MinValue, Int32.MaxValue);

            Console.WriteLine("\nUInt:");
            Console.WriteLine("Min={0} , Max={1}", UInt32.MinValue, UInt32.MaxValue);

            //Long
            long l1 = -9223372036854775808;
            long l2 = 9223372036854775807;

            ulong ul1 = 18223372036854775808ul;
            ulong ul2 = 18223372036854775808UL;

            Console.WriteLine("\nLong:");
            Console.WriteLine("Min={0} , Max={1}", Int64.MinValue, Int64.MaxValue);

            Console.WriteLine("\nULong:");
            Console.WriteLine("Min={0} , Max={1}", UInt64.MinValue, UInt64.MaxValue);


            //Float
            float f1 = 123456.5F;
            float f2 = 1.123456f;

            Console.WriteLine("\nFloat:");
            Console.WriteLine("Min={0} , Max={1}", float.MinValue, float.MaxValue);


            //double
            double d1 = 12345678912345.5d;
            double d2 = 1.123456789123456d;

            Console.WriteLine("\nDouble:");
            Console.WriteLine("Min={0} , Max={1}", double.MinValue, double.MaxValue);



            //Decimal
            //The decimal type has more precision and a smaller range
            //than both float and double,
            //and so it is appropriate for financial and monetary calculations.
            decimal d3 = 123456789123456789123456789.5m;
            decimal d4 = 1.1234567891345679123456789123m;

            Console.WriteLine("\nDecimal:");
            Console.WriteLine("Min={0} , Max={1}", decimal.MinValue, decimal.MaxValue);


            //Scientific Notation
            //Use e or E to indicate the power of 10 
            //as exponent part of scientific notation with float, double or decimal.

            double d = 0.12e2;
            Console.WriteLine(d);  // 12;

            float f = 123.45e-2f;
            Console.WriteLine(f);  // 1.2345

            decimal m = 1.2e6m;
            Console.WriteLine(m);// 1200000



            //hex & Binary
            int hex = 0x2F;
            int binary = 0b_0010_1111;

            Console.WriteLine(hex);
            Console.WriteLine(binary);

            Console.ReadKey();
             */

            /*
             //get default value using default(type)
            int i = default(int); // 0
            float f = default(float);// 0
            decimal d = default(decimal);// 0
            bool b = default(bool);// false
            char c = default(char);// '\0'

            // C# 7.1 onwards
            //get default value using default
            int i2 = default; // 0
            float f2 = default;// 0
            decimal d2 = default;// 0
            bool b2 = default;// false
            char c2 = default;// '\0'

           

            Console.ReadKey();
             */

            /*
             Enums

            enWeekDays WeekDays;

            WeekDays = enWeekDays.Friday;

            Console.Write((byte)enWeekDay.Friday)

             Console.WriteLine(WeekDays.GetHashCode());

            Console.ReadKey();
             */

            /*
             NULLable
            //  Nullable<int> can be assigned any value
            //  from -2147483648 to 2147483647, or a null value.

            Nullable<int> i = null;

        

            Console.ReadKey();
             */

            /*
                         
            //you dont specify any type here , automatically will be specified
            var student = new { Id = 20, FirstName = "Mohammed", LastName = "Abu-Hadhoud" };

            Console.WriteLine("\nExample1:\n");
            Console.WriteLine(student.Id); //output: 20
            Console.WriteLine(student.FirstName); //output: Mohammed
            Console.WriteLine(student.LastName); //output: Abu-Hadhoud
           
            //You can print like this:
            Console.WriteLine(student);

           
            //anonymous types are read-only
            //you cannot change the values of properties as they are read-only.

           // student.Id = 2;//Error: cannot chage value
           // student.FirstName = "Ali";//Error: cannot chage value


           //An anonymous type's property can include another anonymous type.
           var student2 = new
            {
                Id = 20,
                FirstName = "Mohammed",
                LastName = "Abu-Hadhoud",
                Address = new { Id = 1, City = "Amman", Country = "Jordan" }
            };

            Console.WriteLine("\nExample2:\n");
            Console.WriteLine(student2.Id);
            Console.WriteLine(student2.FirstName);
            Console.WriteLine(student2.LastName);

            Console.WriteLine(student2.Address.Id);
            Console.WriteLine(student2.Address.City);
            Console.WriteLine(student2.Address.Country);
            Console.WriteLine(student2.Address);



            Console.ReadKey();
             */

            /*
                         
            //A struct object can be created with or without the new operator,
            //same as primitive type variables.

            stStudent Student ;
            stStudent Student2 = new stStudent();


            Student.FirstName = "Mohammed";
            Student.LastName = "Abu-Hadhoud";

   
            Console.WriteLine(Student.FirstName);   
            Console.WriteLine(Student.LastName);

            
            Student2.FirstName = "Ali";
            Student2.LastName = "Ahmed";


            Console.WriteLine(Student2.FirstName);
            Console.WriteLine(Student2.LastName);

            Console.ReadKey();

            }
             */

            /* Dynamic
             * 
            dynamic MyDynamicVar = 100;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = "Hello World!!";
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = true;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = DateTime.Now;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            Console.ReadKey();
             */

            /*
            //assigns default value 01/01/0001 00:00:00

            DateTime dt1 = new DateTime();

            //assigns year, month, day
            DateTime dt2 = new DateTime(2023, 12, 31);

            //assigns year, month, day, hour, min, seconds
            DateTime dt3 = new DateTime(2023, 12, 31, 5, 10, 20);

            //assigns year, month, day, hour, min, seconds, UTC timezone
            DateTime dt4 = new DateTime(2023, 12, 31, 5, 10, 20, DateTimeKind.Utc);

            Console.WriteLine(dt1);
            Console.WriteLine(dt2);
            Console.WriteLine(dt3);
            Console.WriteLine(dt4);

            Console.ReadKey();
             */

            /* String
            string S1 = "Mohammed Abu-Hadhoud";

            Console.WriteLine(S1.Length);

            //this will take 5 characters staring position 2
            Console.WriteLine(S1.Substring(2, 5));
            Console.WriteLine(S1.ToLower());
            Console.WriteLine(S1.ToUpper());
            Console.WriteLine(S1[2]);
            Console.WriteLine(S1.Insert(3,"KKKK"));
            Console.WriteLine(S1.Replace("m","*"));
            Console.WriteLine(S1.IndexOf("m"));
            Console.WriteLine(S1.Contains("m"));
            Console.WriteLine(S1.Contains("x"));
            Console.WriteLine(S1.LastIndexOf ("m"));
           
            string S2 = "Ali,Ahmed,Khalid";

            string[] NamesList = S2.Split(',');

            Console.WriteLine(NamesList[0]);
            Console.WriteLine(NamesList[1]);
            Console.WriteLine(NamesList[2]);

            string S3 = "  Abu-Hadhoud  ";
            Console.WriteLine(S3.Trim());
            Console.WriteLine(S3.TrimStart());
            Console.WriteLine(S3.TrimEnd());

            Console.ReadKey();
             */

            /*
            //  String Interpolation

            string firstName = "Mohammed";
            string lastName = "Abu-Hadhoud";
            string code = "107";

            //You shold use $ to $ to identify an interpolated string 
            string fullName = $"Mr. {firstName} {lastName}, Code: {code}";

            Console.WriteLine(fullName);

            Console.ReadKey();
             */

            /* Casting
           int myInt = 17;
            double myDouble = myInt;       // Automatic casting: int to double

            Console.WriteLine(myInt);      // Outputs 17
            Console.WriteLine(myDouble);   // Outputs 17


            Console.ReadKey();

                   double myDouble = 17.58;
            int myInt = (int) myDouble;    // Manual casting: double to int

            Console.WriteLine(myDouble);   // Outputs 17.58
            Console.WriteLine(myInt);      // Outputs 17


            Console.ReadKey();
             */

            /* Convert
      
            int myInt = 20;
            double myDouble = 7.25;
            bool myBool = true;

            Console.WriteLine(Convert.ToString(myInt));    // convert int to string
            Console.WriteLine(Convert.ToDouble(myInt));    // convert int to double
            Console.WriteLine(Convert.ToInt32(myDouble));  // convert double to int
            Console.WriteLine(Convert.ToString(myBool));   // convert bool to string


            Console.ReadKey();
             */

            /* Casting Enums
            Console.WriteLine(WeekDays.Friday); //output: Friday 
            int day = (int)WeekDays.Friday; // enum to int conversion
            Console.WriteLine(day); //output: 4 

            var wd = (WeekDays)5; // int to enum conversion
            Console.WriteLine(wd);//output: Saturday 

            Console.ReadKey();
             */

            /* Read Line
             
            // Type your username and press enter
            Console.WriteLine("Enter username?");

            string userName = Console.ReadLine();
            Console.WriteLine("Username is: " + userName);

            Console.ReadKey();

            Console.WriteLine("Enter your age?");
            //if you dont convert you will get error, and if you enter string you will get error
            int age = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Your age is: " + age);


            Console.ReadKey();
             */

            /*
            // create an array
            int[] numbers = { 1, 2, 3 };

            //access first element
            Console.WriteLine("Element in first index : " + numbers[0]);

            //access second element
            Console.WriteLine("Element in second index : " + numbers[1]);

            //access third element
            Console.WriteLine("Element in third index : " + numbers[2]);


            //through loop
            Console.WriteLine("\nAccess array using loop:\n");
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.WriteLine("Element in index {0} : {1} ", i, numbers[0]);
            }


                        //initializing 2D array
            int[,] numbers = { { 12, 13 }, { 55, 77 } };

            // access first element from the first row
            Console.WriteLine("Element at index [0, 0] : " + numbers[0, 0]);

            // access first element from second row
            Console.WriteLine("Element at index [1, 0] : " + numbers[1, 0]);


            Console.ReadKey();

             */
            /*
            // Note that we used System.Linq above.

            int[] numbers = { 51, -1, 2, 14, 18, 40, 178 };

            // get the minimum element
            Console.WriteLine("Smallest  Element: " + numbers.Min());

            // Max() returns the largest number in array
            Console.WriteLine("Largest Element: " + numbers.Max());

            // Note that we used System.Linq above.

            int[] numbers = { 20, 22, 19, 18, 1 };

           

            // compute Count
            Console.WriteLine("Count : " + numbers.Count());
           
            // compute Sum
            Console.WriteLine("Sum : " + numbers.Sum());

            // compute the average
            Console.WriteLine("Average: " + numbers.Average());

            Console.ReadKey();
             */

            /* Math
             
            Console.WriteLine("Max of 5, 10 is: {0}",Math.Max(5, 10));
            Console.WriteLine("Min of 5, 10 is: {0}",Math.Min(5, 10));
            Console.WriteLine("Squir Root of 64 is: {0}",Math.Sqrt(64));
            Console.WriteLine("Absolute (positive) value of  -4.7 is: {0}", Math.Abs(-4.7));
            Console.WriteLine("Round of 9.99 is: {0}",Math.Round(9.99));

            Console.ReadKey();
             */

            /* Method
              static void PrintMyName()
        {
            Console.WriteLine("Mohammed Abu-Hadhoud");
        }
        static void Main(string[] args)
            {


            PrintMyName();

            Console.ReadKey();

             */
        }
    }
}
