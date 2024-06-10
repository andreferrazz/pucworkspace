import java.util.Scanner;

void main(String... args) {
	try (var scanner = new Scanner(System.in)) {
		int d = scanner.nextInt();
		int res = (d % 8) == 0 ? 3 : (d % 8) - 5;
		System.out.print(res);
	}
}