public class Graphic {
    protected String label;
    public Graphic(String label){
        this.label = label;
    }
    public String getLabel(){
        return this.label;
    }
    public void setLabel(String label){
        this.label = label;
    }

}

public class Point extends Graphic {
    private int x;
    private int y;
    public Point(String label, int x, int y){
        super(label);
        this.x = x;
        this.y = y;
    }
    public int getX(){
            return this.x;
        }
    public void setX(){
        this.x = x;
    }


}

public class Line extends Graphic {
    private Point p1;
    private Point p2;
    public Line(String label, Point p1, Point p2){
        super(label);
        this.p1 = p1;
        this.p2 = p2;
    }
    public int getX(){
            return this.x;
        }
    public void setX(){
        this.x = x;
    }


}