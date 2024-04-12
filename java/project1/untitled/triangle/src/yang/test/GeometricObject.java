package yang.test;

public class GeometricObject {
    //date fields
    private String color = "White";
    private boolean filled;
    private java.util.Date dateCreated;

    //constructors
    public GeometricObject()
    {
        dateCreated = new java.util.Date();
    }
    public GeometricObject(String color, boolean filled)
    {
        dateCreated = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }

    //getter
    public String getColor()
    {
        return color;
    }
    public boolean isFilled()
    {
        return filled;
    }
    public java.util.Date getDateCreated()
    {
        return dateCreated;
    }
    //setter
    public void setColor(String color)
    {
        this.color = color;
    }
    public void setFilled(boolean filled)
    {
        this.filled = filled;
    }

    //override toString
    public String toString()
    {
        return "Created on " + dateCreated + "\ncolor: " + color +
                " and filled: " + filled;
    }
}
