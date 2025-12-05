class Task_one {
	public static void main(String[] args) {
		System.out.println("Hello user!");	
	}
}
class Task_one_two{
	public static void main(String[] args) {
		if(args.length > 0) {
			System.out.println("You entered: " + args[0]);
		} else {
			System.out.println("No input was provided");
		}
	}
}
class Task_one_three {
	public static void main(String[] args) {
		if(args.length > 1) {
			int n =0;
			try {
				 n = Integer.parseInt(args[0]);	
			} catch(NumberFormatException e) {
				System.out.println("the argument is not an intger!");
			}

			for(int i=0;i<n;i++) {
				System.out.println(args[1]);
			}
		} else {
			System.out.println("No input was provided");
		}
	}
}