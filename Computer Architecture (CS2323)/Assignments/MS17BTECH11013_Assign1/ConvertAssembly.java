import javax.print.DocFlavor;
import java.nio.file.Files;
import java.util.Scanner;
import java.util.List;
import java.nio.file.Paths;
import java.io.*;
import java.awt.*;
import java.util.*;
import java.util.List;
import java.util.Scanner;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.File;

public class main {

    public static void main(String[] args)
    {

        // ++++++++++++++++++++++++++++ FunCode Table only for R formats +++++++++++++++++++++++++++++++++++
        // add, addu, sub, subu, and, or, nor, slt, sltu, sll, srl, jr
        HashMap<String, ArrayList<String>> FunctTable = new HashMap<>();

        ArrayList<String> v = new ArrayList<>();
        v.add("add");
        v.add("R");
        FunctTable.put("100000", v);

        ArrayList<String> v1 = new ArrayList<>();
        v1.add("addu");
        v1.add("R");
        FunctTable.put("100001",v1);

        ArrayList<String> v2 = new ArrayList<>();
        v2.add("sub");
        v2.add("R");
        FunctTable.put("100010", v2);

        ArrayList<String> v3 = new ArrayList<>();
        v3.add("subu");
        v3.add("R");
        FunctTable.put("100011",v3);

        ArrayList<String> v4 = new ArrayList<>();
        v4.add("and");
        v4.add("R");
        FunctTable.put("100100", v4);

        ArrayList<String> v5 = new ArrayList<>();
        v5.add("or");
        v5.add("R");
        FunctTable.put("100101",v5);

        ArrayList<String> v6 = new ArrayList<>();
        v6.add("nor");
        v6.add("R");
        FunctTable.put("100111", v6);

        ArrayList<String> v7 = new ArrayList<>();
        v7.add("slt");
        v7.add("R");
        FunctTable.put("101010",v7);

        ArrayList<String> v8 = new ArrayList<>();
        v8.add("jr");
        v8.add("R");
        FunctTable.put("001000", v8);

        ArrayList<String> v9 = new ArrayList<>();
        v9.add("sll");
        v9.add("R");
        FunctTable.put("000000",v9);

        ArrayList<String> v10 = new ArrayList<>();
        v10.add("srlv");
        v10.add("R");
        FunctTable.put("000110", v10);

        ArrayList<String> v11 = new ArrayList<>();
        v11.add("srlv");
        v11.add("R");
        FunctTable.put("101010",v11);

        ArrayList<String> v12 = new ArrayList<>();
        v12.add("div");
        v12.add("R");
        FunctTable.put("011010", v12);

        ArrayList<String> v13 = new ArrayList<>();
        v13.add("divu");
        v13.add("R");
        FunctTable.put("011011",v13);

        ArrayList<String> v14 = new ArrayList<>();
        v14.add("mult");
        v14.add("R");
        FunctTable.put("011000", v14);

        ArrayList<String> v15 = new ArrayList<>();
        v15.add("multu");
        v15.add("R");
        FunctTable.put("011001",v15);

        ArrayList<String> v16 = new ArrayList<>();
        v16.add("mfhi");
        v16.add("R");
        FunctTable.put("010000", v16);

        ArrayList<String> v17 = new ArrayList<>();
        v17.add("mflo");
        v17.add("R");
        FunctTable.put("010010",v17);

        ArrayList<String> v18 = new ArrayList<>();
        v18.add("mtlo");
        v18.add("R");
        FunctTable.put("010011", v18);

        ArrayList<String> v19 = new ArrayList<>();
        v19.add("xor");
        v19.add("R");
        FunctTable.put("100110",v19);

        HashMap<String, ArrayList<String>> OPCodeTable  = new HashMap<>();


        // ++++++++++++++++++++++++++++  OPcode Table only for I or J formats +++++++++++++++++++++++++++++
        // beq, bne, addi, addiu, andi, ori, slti, sltiu, lui, lw, sw
        // j, jal


        ArrayList<String> v20 = new ArrayList<>();
        v20.add("lui");
        v20.add("I");
        OPCodeTable.put("001111", v20);

        ArrayList<String> v21 = new ArrayList<>();
        v21.add("lw");
        v21.add("I");
        OPCodeTable.put("100011",v21);

        ArrayList<String> v22 = new ArrayList<>();
        v22.add("sw");
        v22.add("I");
        OPCodeTable.put("101101",v22);

        ArrayList<String> v23 = new ArrayList<>();
        v23.add("beq");
        v23.add("I");
        OPCodeTable.put("000100",v23);

        ArrayList<String> v24 = new ArrayList<>();
        v24.add("bne");
        v24.add("I");
        OPCodeTable.put("000101", v24);

        ArrayList<String> v25 = new ArrayList<>();
        v25.add("addi");
        v25.add("I");
        OPCodeTable.put("001000",v25);

        ArrayList<String> v26 = new ArrayList<>();
        v26.add("addiu");
        v26.add("I");
        OPCodeTable.put("001001", v26);

        ArrayList<String> v27 = new ArrayList<>();
        v27.add("ori");
        v27.add("I");
        OPCodeTable.put("001101",v27);

        ArrayList<String> v28 = new ArrayList<>();
        v28.add("sltiu");
        v28.add("I");
        OPCodeTable.put("001011", v28);

        ArrayList<String> v29 = new ArrayList<>();
        v29.add("slti");
        v29.add("I");
        OPCodeTable.put("001010",v29);

        ArrayList<String> v30 = new ArrayList<>();
        v30.add("andi");
        v30.add("I");
        OPCodeTable.put("001100", v30);

        ArrayList<String> v32 = new ArrayList<>();
        v32.add("xori");
        v32.add("I");
        OPCodeTable.put("001110", v32);

        ArrayList<String> v35 = new ArrayList<>();
        v35.add("j");
        v35.add("J");
        OPCodeTable.put("000010",v35);

        ArrayList<String> v36 = new ArrayList<>();
        v36.add("jal");
        v36.add("J");
        OPCodeTable.put("000011", v36);


        HashMap<String, String> InvRegister = new HashMap<>();

        InvRegister.put("00001", "$at");
        InvRegister.put("00000", "$zero");
        InvRegister.put("00010", "$v0");
        InvRegister.put("00011", "$V1");
        InvRegister.put("00100", "$a0" );
        InvRegister.put("00101", "$a1");
        InvRegister.put("00110", "$a2");
        InvRegister.put("00111", "$a3");
        InvRegister.put("01000", "$t0");
        InvRegister.put("01001", "$t1");
        InvRegister.put("01010","$t2");
        InvRegister.put("01011", "$t3");
        InvRegister.put("01100", "$t4");
        InvRegister.put("01101", "$t5");
        InvRegister.put("01110", "$t6");
        InvRegister.put("01111", "$t7");
        InvRegister.put("10000", "$s0");
        InvRegister.put("10001", "$s1");
        InvRegister.put("10010", "$s2");
        InvRegister.put("10011", "$s3");
        InvRegister.put("10100", "$S4");
        InvRegister.put("10101", "$s5");
        InvRegister.put("10110", "$s6");
        InvRegister.put("10111", "$s7");
        InvRegister.put("11000", "$t8");
        InvRegister.put("11001", "$t9");
        InvRegister.put("11010", "$k0");
        InvRegister.put("11011", "$k1");
        InvRegister.put("11100", "$gp");
        InvRegister.put("11101", "$sp");
        InvRegister.put("11110", "$fp");
        InvRegister.put("11111", "$ra");

        InvRegister.put("01011010101100100000111100", "while");
        InvRegister.put("1010101010101010", "exit");
        InvRegister.put("1011011011011011", "yes");
        InvRegister.put("11001100110110111000001100", "sub");
        InvRegister.put("0101010111011000", "loop");
        InvRegister.put("0000000011111111", "not");
        InvRegister.put("00001111000011110000111100", "findFactorial");
        InvRegister.put("0000000011110000", "done");



        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the file name: " );
        String fname = sc.nextLine();

        //  String fname = "prog4bin.txt";
        // Input will be like prog*bin.txt

        fname = "sample_data/" + fname;



        String outFileName = fname.substring(0,9)  + ".asm";

        try {
            List<String> allLines = Files.readAllLines(Paths.get(fname));

            FileWriter fw = new FileWriter(outFileName);

            for(String line : allLines)
            {
                String opcode;
                line = line.substring(0,32);  // only extract the first 32 bits

                System.out.println(line);

                String arg1;    // labels e.g add, addi, addu
                String arg2;    // labels for destination register/ address / immediate
                String arg3;    // labels
                String arg4;

                    opcode = line.substring(0,6);

                    String Rop = "000000";

                    if(opcode.compareTo(Rop) == 0)
                    {

                        // R type format which has opcode "000000"

                        ArrayList<String> entries = FunctTable.get(line.substring(26,32));    // If it is a R format then we should go according to the function value which is a string between 26 to 31
                        arg1 = entries.get(0); // string representation of function e.q add, sub

                        if(entries.get(0).equals("mult") || entries.get(0).equals("div") || entries.get(0).equals("multu") || entries.get(0).equals("divu") )
                        {
                            arg2 = InvRegister.get(line.substring(6,11));
                            arg3 = InvRegister.get(line.substring(11,16));
                            System.out.println(arg1 + " " +  arg2 + " " + arg3 );
                            fw.write(arg1 + " " +  arg2 + " " + arg3 + "\n" );

                            continue;    // Indicates this line is done parsing now for another line
                        }
                        else if(entries.get(1).equals("sll") || entries.get(1).equals("srl") )
                        {
                            String shamt = line.substring(21,26);
                            int sha = Integer.parseInt(shamt,2);
                            arg4 = Integer.toString(sha);

                            arg3 = InvRegister.get(line.substring(11,16));
                            arg2 = InvRegister.get(line.substring(16,21));

                            System.out.println(arg1 + " " + arg2 + ", " + arg3 + ", " + arg4);
                            fw.write(arg1 + " " +  arg2 + " " + arg3+ ", " + arg4 + "\n" );
                            continue;

                        } else if( entries.get(1).equals("jr") )
                        {
                            // here arg2 will be source register which we have assigned random address
                            arg2 = InvRegister.get(line.substring(6,11) );

                            System.out.println(arg1 + " " + arg2);
                            fw.write(arg1 + " " +  arg2 + "\n");
                            continue;

                        }else if(entries.get(1).equals("mfhi") || entries.get(1).equals("mflo") )
                        {
                            // here arg2 will have only destination register so we need to exxtract destination register from line and get the register from table
                            arg2 = InvRegister.get(line.substring(16,21));

                            System.out.println(arg1 + " " + arg2);
                            fw.write(arg1 + " " + arg2 + "\n");
                            continue;
                        }

                        arg2 = InvRegister.get(line.substring(11,16));    // get the destination register
                        arg3 = InvRegister.get(line.substring(6,11));     // get the rs register
                        arg4 = InvRegister.get(line.substring(11,16));    // get the rt register

                        System.out.println(arg1+ " " + arg2  + ", " + arg3 + ", " + arg4);
                        fw.write(arg1+ " " + arg2  + ", " + arg3 + ", " + arg4 + "\n");

                        // End of all types for R formats
                    }
                    else {


                        ArrayList<String> entries = OPCodeTable.get(opcode);
                        arg1 = entries.get(0);     // String representation of function e.g addi


                        if(entries.get(1).equals("I"))
                        {

                            if(arg1.equals("bne") || arg1.equals("beq") )
                            {
                                arg2 = InvRegister.get(line.substring(6,11));    // get the rs register value
                                arg3 = InvRegister.get(line.substring(11,16));   // get the rt register
                                arg4 = InvRegister.get(line.substring(16,32) );  // get the 16 bit immidiate value

                                System.out.println(arg1 + " " + arg2 + ", " + arg3 + ", " + arg4);
                                fw.write(arg1 + " " + arg2 + ", " + arg3 + ", " + arg4 + "\n");
                                continue;
                            }
                            else if(arg1.equals("lw") || arg1.equals("sw") || arg1.equals("lui") || arg1.equals("sb") || arg1.equals("sh") )
                            {
                                arg2 = InvRegister.get(line.substring(11,16) ); // get the first register rt which is from 11 to 15
                                arg3 = InvRegister.get(line.substring(6,11)); // get the rs register which is from 6 to 10
                                String off = line.substring(16, 32);

                                // convert that offset to integer
                                int i = Integer.parseInt(off,2);

                                arg3 = i + "(" + arg3 + ")";

                                System.out.println(arg1 + " " + arg2 + " " + arg3);
                                fw.write(arg1 + " " + arg2 + ", " + arg3 + "\n");
                                continue;
                            }


                            arg2 = InvRegister.get(line.substring(11,16) );  // get the register value rt which is from 11 to 15
                            arg3 = InvRegister.get(line.substring(6,11));  // get the register value rs which is from 6 to 10

                            if(InvRegister.containsKey(line.substring(16,32)))
                            {
                                arg4 = InvRegister.get(line.substring(16,32));
                            }
                            else
                            {
                                String mystr = line.substring(16,32);
                                int myint = Integer.parseInt(mystr,2);
                                arg4 = Integer.toString(myint);
                            }
                            System.out.println(arg1 + " " + arg2 + ", " + arg3 + ", " + arg4);
                            fw.write(arg1 + " " + arg2 + ", " + arg3 + ", " + arg4 + "\n");



                        } else if (entries.get(1).equals("J"))
                        {
                            // J formats includes j and jal with 26 bit address value


                            arg2 = InvRegister.get(line.substring(6,32)); // get the address value which is from 6 to 31

                            System.out.println(arg1 +" " + arg2);
                            fw.write(arg1 + " " + arg2 + "\n");
                            continue;

                        }


                    }



            }


                fw.close();
            }
            catch (IOException e) {
            e.printStackTrace();
        }
    }



}


