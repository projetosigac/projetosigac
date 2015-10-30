package com.sigac.firefighter.model;

import com.sigac.firefighter.Victim;

import java.util.List;

public interface ModelManager {

    public void deleteVictim(String id);

    public List<Victim> getVictims() throws Exception;

    public void persistVictim(Victim victim);

}
