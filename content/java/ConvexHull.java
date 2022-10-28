//make sure to make new file!
import java.io.*;
import java.util.*;
//standard convex hull
public class ConvexHull{
	
	public static void main(String[] args)throws IOException{
		BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		
		while(true){
			int n = Integer.parseInt(f.readLine());
			
			if(n==0) break;
			
			ArrayList<Point> points = new ArrayList<Point>();
			HashSet<Point> seen = new HashSet<Point>();
			for(int k = 0; k < n; k++){
				StringTokenizer st = new StringTokenizer(f.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
			
				Point p = new Point(a,b);
				if(!seen.contains(p)){
					points.add(p);
					seen.add(p);
				}
			}
		
			Collections.sort(points);
		
			ArrayList<Point> answer = convexhull(points);
		
			out.println(answer.size());
			for(Point p : answer){
				out.println(p);
			}
		}
		
		
		out.close();
	}
	
	//takes in array of points sorted by x coordinate from left to right
	//outputs convex hull in counterclockwise order, starting from leftmost point.
	public static ArrayList<Point> convexhull(ArrayList<Point> points){
		
		ArrayList<Point> hull = new ArrayList<Point>();
		
		//lower
		Stack<Point> lower = new Stack<Point>();
		lower.add(points.get(0));
		
		for(int k = 1; k < points.size(); k++){
			//while the are at least 2 elements currently in stack and the the last two points + this point make a right turn (or collinear), pop
			while(lower.size() >= 2){
				Point last = lower.pop();
				Point last2 = lower.pop();
				
				if(crossproduct(last2,last,points.get(k)) <= 0){
					lower.push(last2);
				} else {
					lower.push(last2);
					lower.push(last);
					break;
				}
			}
			lower.push(points.get(k));
		}
		
		//upper hull
		Stack<Point> upper = new Stack<Point>();
		upper.add(points.get(points.size()-1));
		
		for(int k = points.size()-2; k >= 0; k--){
			//while the are at least 2 elements currently in stack and the the last two points + this point make a right turn (or collinear), pop
			while(upper.size() >= 2){
				Point last = upper.pop();
				Point last2 = upper.pop();
				
				if(crossproduct(last2,last,points.get(k)) <= 0){
					upper.push(last2);
				} else {
					upper.push(last2);
					upper.push(last);
					break;
				}
			}
			upper.add(points.get(k));
		}
		
		//add upper then lower then reverse
		ArrayList<Point> hullupper = new ArrayList<Point>();
		while(!upper.isEmpty()){
			hullupper.add(upper.pop());
		}
		
		ArrayList<Point> hulllower = new ArrayList<Point>();
		while(!lower.isEmpty()){
			hulllower.add(lower.pop());
		}
		
		Collections.reverse(hullupper);
		Collections.reverse(hulllower);
		
		for(Point p : hulllower) hull.add(p);
		for(int k = 1; k < hullupper.size()-1; k++) hull.add(hullupper.get(k));          //don't add first and last points
		
		return hull;
					
		
	}
	
	//positive if a->b->c is left turn (counter-clockwise)
	//negative if right turn (clockwise)
	//0 is a,b,c are collinear
	public static int crossproduct(Point a, Point b, Point c){
		return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
	}
	
	public static class Point implements Comparable<Point>{
		int x;
		int y;
		public Point(int a, int b){
			x = a;
			y = b;
		}
		//sort by x coordinate from left to right
		//if same x coordinate, sort by y coordinate from down to up
		public int compareTo(Point p){
			if(x != p.x) 
				return x-p.x;
			return y-p.y;
		}
		
		public int hashCode(){
			return toString().hashCode();
		}
		
		public boolean equals(Object o){
			Point p = (Point)o;
			return x==p.x && y==p.y;
		}
		
		public String toString(){
			return "" + x + " " + y;
		}
	}
	
	
	
		
}