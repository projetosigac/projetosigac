package com.sigac.firefighter;

import com.sigac.firefighter.model.ApiModelManager;

import java.util.List;


public class Util {

    public static void main(String[] args) {
        try {
            ApiModelManager modelManager = ApiModelManager.getInstance();
            modelManager.deleteVictim("0");
            modelManager.deleteVictim("1");

            modelManager.persistVictim(new Victim(0, Victim.State.BLACK, Victim.Sex.MALE, Victim.Age.YOUNG, "", 0));
            modelManager.persistVictim(new Victim(1, Victim.State.GREEN, Victim.Sex.MALE, Victim.Age.ADULT, "", 0));

            List<Victim> victims = modelManager.getVictims();
            System.out.println(victims.toString());
        }
        catch(Exception e) {
            System.out.println(e.toString());
        }
    }


}
