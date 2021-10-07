import java.io.*;
import java.util.Arrays;

class SortKeys
{
	public static void main(String[] args)throws IOException
	{
		File file = new File("keys10K80.txt");
		BufferedReader br = new BufferedReader(new FileReader(file));
		String line = "";
		int[] arr = new int[5803];
		int i = 0;
		while ((line = br.readLine()) != null)
		{
			arr[i++] = Integer.parseInt(line);
		}
		br.close();
		Arrays.sort(arr);
		file = new File("keys10K80Sorted.txt");
		BufferedWriter bw = new BufferedWriter(new FileWriter(file));
		for (i = 0; i < 5803; ++i)
		{
			bw.write("insert "+Integer.toString(arr[i]));
			bw.write("\n");
		}
		bw.write("quit");
		bw.close();
	}
}