import java.io.*;
import java.util.*;

class Evaluation
{
	String ratio;
	int nop;
	String type;
	int exptNo;

	String insertCount;
	String deleteCount;
	String totalNodes;

	String treapKeyComparisons;
	String bstKeyComparisons;
	String avltKeyComparisons;

	String treapRotations;
	String bstRotations;
	String avltRotations;

	String treapHeight;
	String bstHeight;
	String avltHeight;

	String treapAvgHeight;
	String bstAvgHeight;
	String avltAvgHeight;

	String treapAvgDepth;
	String bstAvgDepth;
	String avltAvgDepth;
	Evaluation(String ratio, int nop, String type, int exptNo)
	{
		this.ratio = ratio;
		this.nop = nop;
		this.type = type;
		this.exptNo = exptNo;
	}
}

class JavaToMatlab
{
	public static void main(String[] args)throws IOException
	{
		String fileName = "E:/IITG/Courses/1st sem/Data Structures Lab/C or CPP codes/3 Treaps/Experiments/";
		HashMap<String,Evaluation> map = new HashMap<String,Evaluation>();
		String[] ratios = {"6040", "6535", "7030", "7525", "8020"};
		int[] nops = {100, 1000, 10000, 100000, 1000000};
		String[] types = {"10", "2+5+3"};

		//store in hashmap
		for (int r = 0; r < 5; ++r) //for each ratio
		{
			for (int o = 0; o < 5; ++o) //for each nop
			{
				for (int t = 0; t < 2; ++t) //for each type
				{
					for (int e = 1; e <= 10; ++e) //for each experiment
					{
						Evaluation ev = new Evaluation(ratios[r],nops[o],types[t],e);
						String currFileName = fileName;
						String hashMapKey = "";
						hashMapKey += ratios[r];
						hashMapKey += "/";
						hashMapKey += nops[o];
						hashMapKey += "/";
						hashMapKey += types[t];
						hashMapKey += "/";
						hashMapKey += Integer.toString(e);
						hashMapKey += "/evaluation.txt";
						currFileName += hashMapKey;
						File file = new File(currFileName);
						BufferedReader br = new BufferedReader(new FileReader(file));
						String line = "";
						int indicator = -1;
						while ((line = br.readLine()) != null)
						{
							String[] tokens = line.split(" +");
							if (tokens[0].equals("Insertions:"))
								ev.insertCount = tokens[1];
							else if (tokens[0].equals("Deletions:"))
								ev.deleteCount = tokens[1];
							else if (tokens[0].equals("Treap"))
								indicator = 0;
							else if (tokens[0].equals("Binary"))
								indicator = 1;
							else if (tokens[0].equals("AVL"))
								indicator = 2;
							else if (tokens.length > 1 && tokens[1].equals("Key"))
							{
								if (indicator == 0)
									ev.treapKeyComparisons = tokens[3];
								else if (indicator == 1)
									ev.bstKeyComparisons = tokens[3];
								else if (indicator == 2)
									ev.avltKeyComparisons = tokens[3];
							}
							else if (tokens.length > 1 && tokens[1].equals("Rotations:"))
							{
								if (indicator == 0)
									ev.treapRotations = tokens[2];
								else if (indicator == 1)
									ev.bstRotations = tokens[2];
								else if (indicator == 2)
									ev.avltRotations = tokens[2];
							}
							else if (tokens[0].equals("Height"))
							{
								if (indicator == 0)
									ev.treapHeight = tokens[3];
								else if (indicator == 1)
									ev.bstHeight = tokens[3];
								else if (indicator == 2)
									ev.avltHeight = tokens[3];
							}
							else if (tokens.length > 5 && tokens[5].equals("root"))
							{
								if (indicator == 0)
									ev.treapAvgHeight = tokens[8];
								else if (indicator == 1)
									ev.bstAvgHeight = tokens[8];
								else if (indicator == 2)
									ev.avltAvgHeight = tokens[8];
							}
							else if (tokens.length > 5 && tokens[5].equals("bottom):"))
							{
								if (indicator == 0)
									ev.treapAvgDepth = tokens[6];
								else if (indicator == 1)
									ev.bstAvgDepth = tokens[6];
								else if (indicator == 2)
									ev.avltAvgDepth = tokens[6];
							}
							else if (tokens.length > 4 && tokens[3].equals("Nodes:"))
								ev.totalNodes = tokens[4];
						}
						map.put(hashMapKey,ev);
					}
				}
			}
		}

		//print
		String key = "/10000/2+5+3/";
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			for (int i = 1; i <= 10; ++i)
			{
				String currKey = "";
				currKey += ratios[r];
				currKey += key;
				currKey += Integer.toString(i);
				currKey += "/evaluation.txt";

				Evaluation ev = map.get(currKey);
				System.out.print(ev.insertCount+" ");
			}
			System.out.print(";");
		}
		System.out.println("]");
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			for (int i = 1; i <= 10; ++i)
			{
				String currKey = "";
				currKey += ratios[r];
				currKey += key;
				currKey += Integer.toString(i);
				currKey += "/evaluation.txt";

				Evaluation ev = map.get(currKey);
				System.out.print(ev.deleteCount+" ");
			}
			System.out.print(";");
		}
		System.out.println("]");
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			for (int i = 1; i <= 10; ++i)
			{
				String currKey = "";
				currKey += ratios[r];
				currKey += key;
				currKey += Integer.toString(i);
				currKey += "/evaluation.txt";

				Evaluation ev = map.get(currKey);
				System.out.print(ev.totalNodes+" ");
			}
			System.out.print(";");
		}
		System.out.println("]");


		/*String key = "/1000000/10/";
		System.out.println(key);
		System.out.println("Key comparisons");
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			String currKey = "";
			currKey += ratios[r];
			currKey += key;
			currKey += Integer.toString(7);
			currKey += "/evaluation.txt";

			Evaluation ev = map.get(currKey);
			System.out.print(ev.treapKeyComparisons+" "+ev.bstKeyComparisons+" "+ev.avltKeyComparisons+"; ");
		}
		System.out.println("]");

		System.out.println("Rotations");
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			String currKey = "";
			currKey += ratios[r];
			currKey += key;
			currKey += Integer.toString(7);
			currKey += "/evaluation.txt";

			Evaluation ev = map.get(currKey);
			System.out.print(ev.treapRotations+" "+ev.avltRotations+"; ");
		}
		System.out.println("]");

		System.out.println("Height");
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			String currKey = "";
			currKey += ratios[r];
			currKey += key;
			currKey += Integer.toString(7);
			currKey += "/evaluation.txt";

			Evaluation ev = map.get(currKey);
			System.out.print(ev.treapHeight+" "+ev.bstHeight+" "+ev.avltHeight+"; ");
		}
		System.out.println("]");

		System.out.println("Avg Height");
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			String currKey = "";
			currKey += ratios[r];
			currKey += key;
			currKey += Integer.toString(7);
			currKey += "/evaluation.txt";

			Evaluation ev = map.get(currKey);
			System.out.print(ev.treapAvgHeight+" "+ev.bstAvgHeight+" "+ev.avltAvgHeight+"; ");
		}
		System.out.println("]");

		System.out.println("Avg Depth");
		System.out.print("[");
		for (int r = 0; r < 5; ++r)
		{
			String currKey = "";
			currKey += ratios[r];
			currKey += key;
			currKey += Integer.toString(7);
			currKey += "/evaluation.txt";

			Evaluation ev = map.get(currKey);
			System.out.print(ev.treapAvgDepth+" "+ev.bstAvgDepth+" "+ev.avltAvgDepth+"; ");
		}
		System.out.println("]");*/
	}
}