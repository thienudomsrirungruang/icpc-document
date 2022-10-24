
// add if needed
DecimalFormat f = new DecimalFormat("##.00");

import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;

public class Template {
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(in.readLine());
		StringBuilder sb = new StringBuilder();
		int cases = Integer.parseInt(st.nextToken());
		for(int i = 0; i < cases; i++)
		{
			solve(in, st, sb);
		}
		System.out.println(sb);
	}

	public static void solve(BufferedReader in, StringTokenizer st, StringBuilder sb) throws Exception
	{
		
	}

	public static int[] readArr(int N, BufferedReader in, StringTokenizer st) throws Exception
	{
		int[] arr = new int[N];
		st = new StringTokenizer(in.readLine());
		for(int i=0; i < N; i++)
		arr[i] = Integer.parseInt(st.nextToken());
		return arr;
	}
}
