package com.sigac.firefighter.model;

import com.sigac.firefighter.Victim;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MemoryMockModelManager extends BaseModelManager {

    private static class InstanceHolder {
        private static final MemoryMockModelManager INSTANCE = new MemoryMockModelManager();
    }

    public static MemoryMockModelManager getInstance() {
        return InstanceHolder.INSTANCE;
    }

    private Map<String, Victim> mDatabase = new HashMap<>();

    private MemoryMockModelManager() {
        /* Prevents outside instantiation */
    }

    @Override
    public void deleteVictim(String id) {
        mDatabase.remove(id);
        notifyObservers();
    }

    @Override
    public List<Victim> getVictims() throws Exception {
        return new ArrayList<>(mDatabase.values());
    }

    @Override
    public void persistVictim(Victim victim) {
        mDatabase.put(String.valueOf(victim.getId()), victim);
        notifyObservers();
    }
}
