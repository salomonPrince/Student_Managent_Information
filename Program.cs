//--------------------------------  	
// c# Class_work_3 (420-CT2-AS C2)
// © Salomon Bulambo
// ID : 2133726
// Date : 2023-01-17    
// Student_Management_Information
//----------------------------------  	

// Problem 1: Use Visual Studio editor to write an OOP console program in C# to manage complete student information.
// The program should be able to store the following information for each student: Accept (ask for) student’s name, age (as a sbyte),
// ID (as a uint), and college name, city, and address.

// Store all those values into the appropriate variable’s datatypes (use Convert class),
// and then, display all the student and college information on two lines by using the placeholders.

// Use a loop for having the valid age value entered between 21 to 85 years old.
// Use a loop do .. while and switch for having the options to enter a new student/ college information,
// display the information and the option to quit




using System;

namespace Student_Management_Information
{
    class Program
    {
        static void Main(string[] args)
        {
            // Variables
            string studentName="";
            sbyte studentAge=0;
            uint studentID=0;
            string collegeName = "";
            string collegeCity = "";
            string collegeAddress = "";
            char option;

            do
            {
                Console.WriteLine(" ------------------------------------------------------");
                Console.WriteLine("STUDENT MANAGEMENT INFORMATION");
                Console.WriteLine("1. Enter new Student (college information)");
                Console.WriteLine("2. Display information of the student");
                Console.WriteLine("3. Quit");

                Console.WriteLine(" -------------------------------------------------------------");

                // Loop for having the valid age value entered between 21 to 85 years old.


                // Loop do .. while and switch for having the options to enter a new student/ college  information,
                //do
                //{
                //Console.WriteLine(" Student Name: {0} \t Student Age: {1} \t Student ID: {2} \t College Name: {3} \t College City: {4}" +
                //                  " \t College Address: {5}", studentName, studentAge, studentID, collegeName, collegeCity, collegeAddress);

                //Console.WriteLine("Do you want to enter a new student/ college information? (Y/N) or (y/n) ");
                //  } while (Console.ReadLine() == "Y" || Console.ReadLine() == "y");  // option to quit the program if the user enter N or n
                //  or any other key except Y or y  
                option = Convert.ToChar(Console.ReadLine());
                switch (option)
                {

                    case '1': // option to enter a new student/ college information
                        Console.WriteLine(" Enter a new student/ college information");

                        Console.WriteLine("Enter your name: ");
                        studentName = Console.ReadLine();
                        do
                        {
                            Console.WriteLine("Enter your age: ");
                            
                            studentAge = Convert.ToSByte(Console.ReadLine());

                            if (studentAge >= 21 && studentAge <= 85) // Validation to check if the entered value is between 21 and 85
                            try 
                            {
                                Console.WriteLine("Your age is valid : " + studentAge);
                            }
                            catch (Exception ex1)
                                {
                                    Console.WriteLine("Error msg.\n" + ex1.Message);
                                }
                            else
                            {
                                Console.WriteLine("Your age is not valid");
                            }
                        } while (studentAge < 21 || studentAge > 85);

                    jump1: Console.WriteLine("Enter your ID: ");
                        studentID = Convert.ToUInt32(Console.ReadLine());
                        if (studentID < 1000000 || studentID > 9999999) // Validation to check if the entered value is between 1000000 and 9999999
                        {
                            Console.WriteLine("Your ID is not valid");
                            goto jump1;
                        }
                        else
                        {
                            Console.WriteLine("Your ID is valid : " + studentID);
                        }

                        Console.WriteLine("Enter your college name: ");
                        collegeName = Console.ReadLine();

                        Console.WriteLine("Enter your college city: ");
                        collegeCity = Console.ReadLine();

                        Console.WriteLine("Enter your college address: ");
                        collegeAddress = Console.ReadLine();

                        break;
                    case '2': // option to display the information
                        Console.WriteLine(" Student Name: {0} \t Student Age: {1} \t Student ID: {2} \t College Name: {3} \t College City: {4}" +
                                          " \t College Address: {5}", studentName, studentAge, studentID, collegeName, collegeCity, collegeAddress);
                        break;
                    case '3': // option to quit the program if the user enter N or n or any other key except Y or y
                        Console.WriteLine(" Quit the program");
                        break;

                    default:
                        Console.WriteLine(" Invalid option");
                        break;

                }
            } while (option != 3);
        }
    }
} 



