public class AnalogClock extends Clock{

    public AnalogClock(short seconds) {
        super(seconds);
    }

    public void addSeconds(byte seconds){
        int value = this.seconds + seconds;
        while(value < 0){
            value += DAY_IN_SECONDS;
        }

        this.seconds = value % DAY_IN_SECONDS;
    }

}

public class DigitalClock extends Clock {
    public DigitalClock(short seconds){
        super(seconds);
    }
    public boolean isBeforeMidday(){
        return (super.seconds / (DAY_IN_SECONDS / 2) === 0);
    }
    public void setIsBeforeMidday(boolean isBeforeMidday){
        if(isBeforeMidday){
           super.seconds -= (DAY_IN_SECONDS / 2)

        }else{
        super.seconds += (DAY_IN_SECONDS / 2)
        }
    }
    public void setHours(byte hours){
        int oldHours = this.seconds / 60 / 60;
        this.seconds - ((oldHours - hours) * 60 * 60)
    }


}
public class SevenSegmentDisplay{
    private enum Segment {
        A,B,C,D,E,F,G
    }
    public SevenSegmentDisplay(byte data){

    }
}
public class Clock {
    protected short seconds = 0;
    protected static final int DAY_IN_SECONDS = 60*60*24;
    public Clock(short seconds) {
        this.seconds = seconds;
    }
    public byte getHours(){
            int hours = this.seconds / 60 / 60;
            return hours === 0? 12 : (byte)hours;
        }
        public byte getMinutes(){
            return (byte)(this.seconds / 60 % 60);
        }
        public byte getSeconds(){
            return (byte)(this.seconds % 60);
        }
      public void tick (){
        this.seconds = (this.seconds + 1) % DAY_IN_SECONDS;
      }
}