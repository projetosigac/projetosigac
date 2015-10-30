package com.sigac.firefighter;

/*
create table victims(id int not null, state int not null, sex int, age int, name varchar(30), occurrence_id int );
insert into victims values(id, state, sex, age, name, occurrence_id);

 VICTIM
    id int
    sex int   { MALE, FEMALE }
    age int   { CHILD, YOUNG, ADULT, OLD }
    state int { GREEN, YELLOW, RED, BLACK }

    name string
    occurrence_id
*/

import com.google.gson.annotations.SerializedName;

// TODO: Implement parcelable
public class Victim {

    public enum Sex {
        @SerializedName("0")
        MALE (0),

        @SerializedName("1")
        FEMALE(1);

        private final int value;

        Sex (int value) {
            this.value = value;
        }
    }

    public enum Age {
        @SerializedName("0")
        CHILD(0),

        @SerializedName("1")
        YOUNG(1),

        @SerializedName("2")
        ADULT(2),

        @SerializedName("3")
        OLD(3);

        private final int value;

        Age (int value) {
            this.value = value;
        }
    }

    public enum State {
        @SerializedName("0")
        GREEN(0),

        @SerializedName("1")
        YELLOW(1),

        @SerializedName("2")
        RED(2),

        @SerializedName("3")
        BLACK(3);

        private final int value;

        State (int value) {
            this.value = value;
        }
    }

    private int id;
    private Sex sex;
    private Age age;
    private State state;

    private String name;
    private int occurrence_id;

    public Victim() {
        age = Age.CHILD;
        occurrence_id = 0;
        name = "";
        state = State.GREEN;
        sex = Sex.MALE;
        id = 0;
    }

    public Victim(int id, State state, Sex sex, Age age, String name, int occurrence_id) {
        this.age = age;
        this.occurrence_id = occurrence_id;
        this.name = name;
        this.state = state;
        this.sex = sex;
        this.id = id;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("ID: " + id + "\n");
        sb.append("State:" + state + "\n");
        sb.append("Sex:" + sex + "\n");
        sb.append("Name:" + name + "\n");
        sb.append("OccurrenceId:" + occurrence_id + "\n");

        return sb.toString();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Sex getSex() {
        return sex;
    }

    public void setSex(Sex sex) {
        this.sex = sex;
    }

    public Age getAge() {
        return age;
    }

    public void setAge(Age age) {
        this.age = age;
    }

    public State getState() {
        return state;
    }

    public void setState(State state) {
        this.state = state;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getOccurrence_id() {
        return occurrence_id;
    }

    public void setOccurrence_id(int occurrence_id) {
        this.occurrence_id = occurrence_id;
    }
}
