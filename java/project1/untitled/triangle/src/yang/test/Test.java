package yang.test;

public class Test {
    public static void main(String[] args) {
        try {
            Triangle tri=new Triangle("yellow",true,1,1.5,1);
            System.out.println(tri.toString());
            System.out.println(tri.getArea());
            System.out.println(tri.getPerimeter());
            System.out.println(tri.getColor());
            System.out.println(tri.isFilled());
        } catch (IllegalSideException e) {
            String message = new RuntimeException(e).getMessage();
            System.out.println(message);
        }
        try {
            Triangle tri=new Triangle(-1,0,1);
            System.out.println(tri.toString());
            System.out.println(tri.getArea());
            System.out.println(tri.getPerimeter());
        } catch (IllegalSideException e) {
            String message = new RuntimeException(e).getMessage();
            System.err.println(message);
        }
    }
}
