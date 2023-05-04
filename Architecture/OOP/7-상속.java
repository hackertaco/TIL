import java.time.OffsetDateTime;
import java.util.UUID;

public class BaseEntity {
    private UUID id;
    private OffsetDateTime createdDateTime;
    private OffsetDateTime modifiedDateTime;

    public BaseEntity(UUID id, OffsetDateTime createdDateTime, OffsetDateTime modifiedDateTime){
        this.id = id;
        this.createdDateTime = createdDateTime;
        this.modifiedDateTime = modifiedDateTime;
    }

    public UUID getID(){
        return this.id;
    }
    public OffsetDateTime getCreatedDateTime(){
        return this.createdDateTime;
    }
    public OffsetDateTime getModifiedDateTime(){
            return this.modifiedDateTime;
        }

    public void setModifiedDateTime(OffsetDateTime modifiedDateTime){
        this.modifiedDateTime = modifiedDateTime;
    }
}


// course.java
import java.time.OffsetDateTime;
import java.time.ZoneOffset;
import java.util.ArrayList;
import java.util.UUID;

public class Course extends BaseEntity {
    private String courseCode;
    private String title;
    private ArrayList<CourseTerm> courseTerms;

    public Course(UUID id, OffsetDateTime createdDateTime, OffsetDateTime modifiedDateTime, String courseCode, String title){
        super(id, createdDateTime, modifiedDateTime);
        this.courseCode = courseCode;
        this.title = title;
        this.courseTerms = new ArrayList<>();
    }

    public String getTitle(){
        return this.title;
    }

    public void setTite(String title){
        this.title = title;
    }

    public ArrayList<CourseTerm> getCourseTerms(){
        return this.courseTerms;
    }

    public void setCourseTerms(ArrayList<CourseTerm> courseTerms){
        this.courseTerms = courseTerms;
    }
    // helper methods
    public void addCourseTerm(int term){
        CourseTerm courseTerm = new CourseTerm(UUID.randomUUID(), OffsetDateTime.now(ZoneOffset.UTC), OffsetDateTime.now(ZoneOffset.UTC), this, term);
        this.courseTerms.add(courseTerm);
    }
}

// CourseTerm.java

import java.time.OffsetDateTime;
import java.util.ArrayList;
import java.util.UUID;

public class CourseTerm extends BaseEntity {
    private int term;
    private Course course;
    private ArrayList<Student> students;

    public CourseTerm(UUID id, OffsetDateTime offsetDateTime, OffsetDateTime modifiedDateTime, Course course, int term)
    {
        super(id, offsetDateTime, modifiedDateTime);

        this.course = course;
        this.term = term;
        this.students = new ArrayList<>();
    }

    public ArrayList<Student> getStudents(){
        return this.students;
    }
    // helper methods

    public void addStudent(Student student){
        this.students.add(student);
    }

    public int getStudentsCounts(){
        return this.students.size();
    }
}

// Student.java
import java.time.OffsetDateTime;
import java.util.UUID;

public class Student extends BaseEntity {
    private String name;
    private String email;
    private String nickname;

    public Student (UUID id, OffsetDateTime offsetDateTime, OffsetDateTime modifiedDateTime, String name, ...){
        super(id, offsetDateTime, modifiedDateTime);
    }
}

// Program.java
import java.time.OffsetDateTime;
import java.time.ZoneOffset;
import java.util.UUID;

public class Program {
    public static void main(String[] args){
        UUID id = UUID.randomUUID();
        OffsetDateTime now = OffsetDateTime.now(ZoneOffset.UTC);
        BaseEntity student1 = new Student(id, now, now, "K", "P", "KtotheP");// 이 경우, student 형을 받을 때 캐스팅 필요
        Student student2 = new Student(id, now, now, "t", "a", "dd");
    }
}

