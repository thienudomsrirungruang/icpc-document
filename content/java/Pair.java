static class Pair implements Comparable<Pair> {
	int a;
	int b;
	Pair(int a, int b) {
		this.a = a;
		this.b = b;
	}
	@Override
	public int compareTo(Pair other) {
		if (a != other.a) {
			return other.a-a;
		} else {
			return other.b-b;
		}
	}
}
