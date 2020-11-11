import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;
import java.util.Scanner;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.File;

public class main {

    public static void main(String args[])
    {


        // Table which maps a given string instruction to a arraylist of strings i.e., function/Opcode and format

        HashMap<String,ArrayList<String> >table = new HashMap<>();

        ArrayList<String> v = new ArrayList<>();
        v.add("100000");
        v.add("R");
        table.put("add", v);

        ArrayList<String> v1 = new ArrayList<>();
        v1.add("100001");
        v1.add("R");
        table.put("addu",v1);

        ArrayList<String> v2 = new ArrayList<>();
        v2.add("100010");
        v2.add("R");
        table.put("sub", v2);

        ArrayList<String> v3 = new ArrayList<>();
        v3.add("100011");
        v3.add("R");
        table.put("subu",v3);

        ArrayList<String> v4 = new ArrayList<>();
        v4.add("100100");
        v4.add("R");
        table.put("and", v4);

        ArrayList<String> v5 = new ArrayList<>();
        v5.add("100101");
        v5.add("R");
        table.put("or",v5);

        ArrayList<String> v6 = new ArrayList<>();
        v6.add("100111");
        v6.add("R");
        table.put("nor", v6);

        ArrayList<String> v7 = new ArrayList<>();
        v7.add("101010");
        v7.add("R");
        table.put("slt",v7);

        ArrayList<String> v8 = new ArrayList<>();
        v8.add("101011");
        v8.add("R");
        table.put("sltu", v8);

        ArrayList<String> v9 = new ArrayList<>();
        v9.add("000000");
        v9.add("R");
        table.put("sll",v9);

        ArrayList<String> v10 = new ArrayList<>();
        v10.add("000010");
        v10.add("R");
        table.put("srl", v10);

        ArrayList<String> v11 = new ArrayList<>();
        v11.add("001000");
        v11.add("R");
        table.put("jr",v11);

        ArrayList<String> v12 = new ArrayList<>();
        v12.add("000100");
        v12.add("I");
        table.put("beq", v12);

        ArrayList<String> v13 = new ArrayList<>();
        v13.add("000101");
        v13.add("I");
        table.put("bne",v13);

        ArrayList<String> v14 = new ArrayList<>();
        v14.add("001000");
        v14.add("I");
        table.put("addi", v14);

        ArrayList<String> v15 = new ArrayList<>();
        v15.add("001001");
        v15.add("I");
        table.put("addiu",v15);

        ArrayList<String> v16 = new ArrayList<>();
        v16.add("001100");
        v16.add("I");
        table.put("andi", v16);

        ArrayList<String> v17 = new ArrayList<>();
        v17.add("001101");
        v17.add("I");
        table.put("ori",v17);

        ArrayList<String> v18 = new ArrayList<>();
        v18.add("001010");
        v18.add("I");
        table.put("slti", v18);

        ArrayList<String> v19 = new ArrayList<>();
        v19.add("001011");
        v19.add("I");
        table.put("sltiu",v19);

        ArrayList<String> v20 = new ArrayList<>();
        v20.add("001111");
        v20.add("I");
        table.put("lui", v20);

        ArrayList<String> v21 = new ArrayList<>();
        v21.add("100011");
        v21.add("I");
        table.put("lw",v21);

        ArrayList<String> v22 = new ArrayList<>();
        v22.add("101011");
        v22.add("I");
        table.put("sw",v22);

        ArrayList<String> v23 = new ArrayList<>();
        v23.add("011010");
        v23.add("R");
        table.put("div",v23);

        ArrayList<String> v24 = new ArrayList<>();
        v24.add("011011");
        v24.add("R");
        table.put("divu", v24);

        ArrayList<String> v25 = new ArrayList<>();
        v25.add("011000");
        v25.add("R");
        table.put("mult",v25);

        ArrayList<String> v26 = new ArrayList<>();
        v26.add("011000");
        v26.add("R");
        table.put("multu", v26);

        ArrayList<String> v27 = new ArrayList<>();
        v27.add("000100");
        v27.add("R");
        table.put("sllv",v27);

        ArrayList<String> v28 = new ArrayList<>();
        v28.add("000011");
        v28.add("R");
        table.put("sra", v28);

        ArrayList<String> v29 = new ArrayList<>();
        v29.add("000111");
        v29.add("R");
        table.put("srav",v29);

        ArrayList<String> v30 = new ArrayList<>();
        v30.add("000110");
        v30.add("R");
        table.put("srlv", v30);

        ArrayList<String> v31 = new ArrayList<>();
        v31.add("100110");
        v31.add("R");
        table.put("xor",v31);

        ArrayList<String> v32 = new ArrayList<>();
        v32.add("001110");
        v32.add("I");
        table.put("xori", v32);

        ArrayList<String> v33 = new ArrayList<>();
        v33.add("010000");
        v33.add("R");
        table.put("mfhi",v33);

        ArrayList<String> v34 = new ArrayList<>();
        v34.add("010010");
        v34.add("R");
        table.put("mflo",v34);

        ArrayList<String> v35 = new ArrayList<>();
        v35.add("000010");
        v35.add("J");
        table.put("j",v35);

        ArrayList<String> v36 = new ArrayList<>();
        v36.add("000011");
        v36.add("J");
        table.put("jal", v36);

        ArrayList<String> v37 = new ArrayList<>();
        v37.add("001000");
        v37.add("J");
        table.put("jr",v37);

        ArrayList<String> v38 = new ArrayList<>();
        v38.add("001001");
        v38.add("J");
        table.put("jalr",v38);

        HashMap<String, String> registers  = new HashMap<>();

        registers.put("$at", "00001");
        registers.put("$zero", "00000");
        registers.put("$v0", "00010");
        registers.put("$v1", "00011");
        registers.put("$a0", "00100");
        registers.put("$a1", "00101");
        registers.put("$a2", "00110");
        registers.put("$a3", "00111");
        registers.put("$t0", "01000");
        registers.put("$t1", "01001");
        registers.put("$t2", "01010");
        registers.put("$t3", "01011");
        registers.put("$t4", "01100");
        registers.put("$t5", "01101");
        registers.put("$t6", "01110");
        registers.put("$t7", "01111");
        registers.put("$s0", "10000");
        registers.put("$s1", "10001");
        registers.put("$s2", "10010");
        registers.put("$s3", "10011");
        registers.put("$s4", "10100");
        registers.put("$s5", "10101");
        registers.put("$s6", "10110");
        registers.put("$s7", "10111");
        registers.put("$t8", "11000");
        registers.put("$t9", "11001");
        registers.put("$k0", "11010");
        registers.put("$k1", "11011");
        registers.put("$gp", "11100");
        registers.put("$sp", "11101");
        registers.put("$fp", "11110");
        registers.put("$ra", "11111");

        registers.put("while", "01011010101100100000111100");
        registers.put("exit",  "1010101010101010");
        registers.put("yes", "1011011011011011");
        registers.put("sub",   "11001100110110111000001100");
        registers.put("loop","0101010111011000");
        registers.put("not", "0000000011111111");
        registers.put("findFactorial", "00001111000011110000111100");
        registers.put("done", "0000000011110000");

        HashMap<Integer, String> imm  = new HashMap<>();

        imm.put(-1, "1111111111111111");
        imm.put(-2, "1111111111111110");
        imm.put(-3, "1111111111111101");
        imm.put(-4, "1111111111111100");
        imm.put(-8, "1111111111111000");
        imm.put(-12, "1111111111110100");
        imm.put(16, "1111111111110000");
        imm.put(-20, "1111111111101100");



        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the file name: ");
        String fname = sc.nextLine();

        // input file name will of prog*.asm

        // output file name will be of bin2prog*.txt


        String delims = "[ \t ,]+";

        fname = "sample_data/" + fname;

        try {
            List<String> allLines = Files.readAllLines(Paths.get(fname));


            // for output file name
            String outFileName =  "bin2" + fname.substring(0,5) + ".txt";

            FileWriter fw = new FileWriter(outFileName);

            for (String line : allLines) {

                line = line.trim();
                if(! line.isEmpty()) {

                    if(line.indexOf(":") != -1) // if the line has a label which ends with :
                    {
                        // the line has a label;
                        line = line.trim();

                        System.out.println("This is a label : " + line  + "   of length   " +  line.length() );

                                continue;

                    }
                  else if( (line.indexOf(":") == -1) && (line.indexOf(".") == -1)  && (line.indexOf("#") == -1)  ) {
                       String[] tokens = line.split(delims);

                        for(String s : tokens)
                        {
                            System.out.print(s + "  ");
                        }


                       if(table.containsKey(tokens[0] ) )
                       {

                           String opcode;
                           String rs;
                           String rt;
                           String rd;
                           String funct;
                           String immidiate = "";
                           String shamt;
                           String offset;
                           int t;

                           // It contains the entries of a key which is tokens[0] and its values
                           ArrayList<String> temp = table.get(tokens[0]);

                           if(tokens.length == 4)
                           {


                               if(temp.get(1) == "R")
                               {
                                   opcode = "000000";
                                   rd = registers.get(tokens[1]);
                                   rs = registers.get(tokens[2]);

                                   funct = temp.get(0);

                                   if(tokens[0].equals("sll") || tokens[0].equals("srl") )
                                   {
                                       rt = "00000";
                                       shamt = decitoBin(tokens[3],  5);
                                   }
                                   else
                                   {
                                       rt = registers.get(tokens[3]);
                                       shamt = "00000";
                                   }

                                   System.out.println("\n" + opcode + " " + rs + " " + rt +" " + rd +" " + shamt + " " + funct);

                                    fw.write(opcode  + rs + rt + rd  + shamt + funct);
                                    fw.write("(" + bintoHexa(opcode+rs+rt+rd+shamt+funct) +", " + tokens[0] +" "+ tokens[1] + ", " + tokens[2] + ", " + tokens[3] + ")"  + "\n" );

                                   continue;
                               }
                               else if(temp.get(1) == "I")
                               {
                                   opcode = temp.get(0);
                                   rs = registers.get(tokens[1]);
                                   rt = registers.get(tokens[2]);

                                   if(tokens[0].equals("bne") || tokens[0].equals("beq") )
                                   {
                                       // immidiate = "0000000000000000";
                                       immidiate = registers.get(tokens[3]);
                                   }
                                   else
                                   {
                                       t = Integer.parseInt(tokens[3]);

                                       if(t < 0)
                                       {
                                           immidiate = imm.get(t);
                                       }
                                       else
                                       {
                                           immidiate = Integer.toBinaryString(t);

                                           if(immidiate.length() < 16)
                                           {
                                               String t1 = "";
                                               int diff = 16 - immidiate.length();
                                               while(diff-- > 0)
                                               {
                                                   t1 = t1 + "0";
                                               }

                                               immidiate =  t1 + immidiate;
                                           }
                                       }


                                   }

                                   System.out.println();
                                   System.out.println(opcode+ " " + rs + " "+ rt + " "+ immidiate );
                                   fw.write(opcode + rs + rt + immidiate  );
                                   fw.write("(" + bintoHexa(opcode+rs+rt+immidiate) +", " + tokens[0] +" "+ tokens[1] + ", " + tokens[2] + ", " + tokens[3] + ")"  + "\n" );
                                   continue;
                               }

                           }else if(tokens.length == 3)
                           {

                               if(temp.get(1) == "R")
                               {
                                   opcode = "000000";
                                   if(tokens[0].equals("div"))
                                   {
                                       rd = "00000";
                                   }
                                   else
                                   {
                                       rd = "00000";
                                   }

                                   rs = registers.get(tokens[1]);
                                   rt = registers.get(tokens[2]);
                                   funct = temp.get(0);
                                   shamt = "00000";

                                   System.out.println();
                                   System.out.println(opcode + " " + rs + " " + rt +" " + rd +" " + shamt + " " + funct);
                                    fw.write(opcode  + rs  + rt  + rd  + shamt + funct );
                                   fw.write("(" + bintoHexa(opcode+rs+rt+rd+shamt+funct) + ", " + tokens[0] +" "+ tokens[1] + ", " + tokens[2]  + ")"  + "\n" );
                                   continue;
                               }
                               else if(temp.get(1) == "I")
                               {

                                   opcode = temp.get(0);
                                   rt = registers.get(tokens[1]);
                                   rs = registers.get(tokens[2]);

                                   if(tokens[0].equals("sw") || tokens[0].equals("sh") || tokens[0].equals("sb") || tokens[0].equals("lw") || tokens[0].equals("lui"))
                                   {

                                       if(tokens[2].endsWith(")") )
                                       {
                                           int i = 0;
                                           while (tokens[2].charAt(i) != '(')
                                           {
                                               i++;
                                           }

                                           immidiate = tokens[2].substring(0,i);
                                           rs = tokens[2].substring(i+1, tokens[2].length() - 1);

                                           rs = registers.get(rs);

                                           int val = Integer.parseInt(immidiate);
                                           immidiate = String.format("%16s", Integer.toBinaryString(val)).replace(' ', '0');
                                       }

                                       System.out.println();
                                       System.out.println(opcode + " " + rs + " " + rt+ " "  + immidiate);
                                       String ans = opcode + rs + rt + immidiate;
                                       int b = Integer.parseUnsignedInt(ans,2);
                                       fw.write(opcode + rs + rt + immidiate );
                                       fw.write("(" + Integer.toHexString(b) + ", " + tokens[0] +" "+ tokens[1] + ", " + tokens[2]  + ")"  + "\n" );
                                       continue;
                                   }

                                   rt = registers.get(tokens[2]);

                                   if(tokens[0].equals("bne") || tokens[0].equals("beq") )
                                   {
                                       immidiate = "0000000000000000";
                                   }
                                   else
                                   {
                                       t = Integer.parseInt(tokens[3]);
                                       immidiate = Integer.toBinaryString(t);

                                       if(immidiate.length() < 16)
                                       {
                                           String t1 = "0";
                                           int diff = 16 - immidiate.length();
                                           while(diff-- >= 0)
                                           {
                                               t1 = t1 + "0";
                                           }

                                           immidiate = t1 + immidiate;
                                       }

                                   }

                                   System.out.println();
                                   System.out.println(opcode+ " " + rs + " "+ rt + " "+ immidiate );
                                   fw.write(opcode+ rs +  rt + immidiate );
                                   fw.write("(" + bintoHexa(opcode+rs+rt+immidiate) +", "  + tokens[0] +" "+ tokens[1] + ", " + tokens[2] + ")"  + "\n" );

                                   continue;

                               }

                           }else if (tokens.length == 2)
                           {
                               if(tokens[0].equals("jr"))
                               {
                                   opcode = "000000";
                                   funct = temp.get(0);
                                   shamt = "00000";
                                   rt = registers.get(tokens[1]);
                                   rd = "00000";
                                   rs = "00000";

                                   System.out.println();
                                   System.out.println(opcode + " " + rs + " " + rt + " " + rd + " " + shamt + " " + funct);
                                   fw.write(opcode + rs + rt + rd +  shamt +  funct );
                                   fw.write("(" + bintoHexa(opcode+rs+rt+rd+shamt+funct) +", " + tokens[0] +" "+ tokens[1] + ")"  + "\n" );
                                   continue;
                               }
                               else if(tokens[0].equals("j") || tokens[0].equals("jal") )
                               {
                                   String address;
                                   opcode = temp.get(0);
                                   address = registers.get(tokens[1]);

                                   System.out.println(opcode + " " + address);
                                   fw.write(opcode + address);
                                   fw.write("(" + bintoHexa(opcode+address) +", " + tokens[0] +" "+ tokens[1] + ")"  + "\n" );
                                   continue;
                               }
                               else if(tokens[0].equals("mfhi") || tokens[0].equals("mflo") )
                               {
                                   funct = temp.get(0);
                                   rs = "00000";
                                   rt = "00000";
                                   rd = registers.get(tokens[1]);
                                   opcode = "000000";
                                   shamt = "00000";

                                   System.out.println();
                                   System.out.println(opcode + " " + rs + " " + rt + " " + rd + " " + shamt + " " + funct);
                                   fw.write(opcode + rs +  rt + rd +  shamt +  funct );
                                   fw.write("(" + bintoHexa(opcode+rs+rt+rd+shamt+funct) +", " + tokens[0] +" "+ tokens[1] + ")"  + "\n" );
                                   continue;

                               }

                           }
                       }
                       else
                       {
                           System.out.println("not key of this " + tokens[0]);
                       }

                       System.out.print("----------");



                   }
                }


            }

            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }


        System.out.println();



    }

    public static String bintoHexa(String bin)
    {
            int dec = Integer.valueOf(bin,2);

            return Integer.toHexString(dec);

    }
    public static String decitoHexa(String dec)
    {
        int i = Integer.parseInt(dec);

        String hexa = Integer.toHexString(i);

        return hexa;
    }

    public static String BinaryToDecimal(String bin)
    {
        int decimal = Integer.parseInt(bin, 2);
        String s = String.valueOf(decimal);

        return s;
    }

    public static String decitoBin(String dec, int val)
    {
        int t; // integer of string representaion

        t = Integer.parseInt(dec);
        dec = Integer.toBinaryString(t);
        String t1 = "";
        if(dec.length() < val)
        {

            int diff = val - dec.length();
            while(diff >= 0)
            {
                t1 = t1 + "0";
                diff--;
            }

        }

        return t1+dec;
    }


}

