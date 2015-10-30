package com.sigac.firefighter.model;

import android.util.Log;
import com.google.common.base.Throwables;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import com.sigac.firefighter.Victim;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Type;
import java.net.URL;
import java.net.URLConnection;
import java.util.List;

public class ApiModelManager extends BaseModelManager {

    private static class InstanceHolder {
        private static final ApiModelManager INSTANCE = new ApiModelManager();
    }

    public static ApiModelManager getInstance() {
        return InstanceHolder.INSTANCE;
    }

    private ApiModelManager() {
       /* Prevents outside instantiation */
    }

    public void deleteVictim(String id) {
        httpQuery("delete%20from%20victims%20where%20id=" + id);
        notifyObservers();
    }

    public List<Victim> getVictims() throws Exception  {
        String lookupQuery = "select%20*%20from%20victims";
        String ret;

        ret = httpQuery(lookupQuery);

        Gson gson = new Gson();
        Type listType = new TypeToken<List<Victim>>(){}.getType();
        List<Victim> victims = gson.fromJson(ret, listType);

        return victims;
    }

    public void persistVictim(Victim victim) {
        //insert into victims values(id, state, sex, age, name, occurrence_id);
        String insertQuery = String.format("insert into victims (id, state, sex, age, name, occurrence_id) " +
                        "values (%d, %d, %d, %d, \'%s\', %d);",
                victim.getId(), victim.getState().ordinal(), victim.getSex().ordinal(),
                victim.getAge().ordinal(), victim.getName(), victim.getOccurrence_id());

        insertQuery = insertQuery.replaceAll("'", "%27");
        insertQuery = insertQuery.replaceAll(" ", "%20");

        String ret = httpQuery(insertQuery);

        notifyObservers();
    }

    public String httpQuery(String query) {
        try {
            URL yahoo = new URL("http://powerful-forest-9086.herokuapp.com/?q=" + query);
            URLConnection yc = yahoo.openConnection();
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(
                            yc.getInputStream()));
            String inputLine;
            inputLine = in.readLine();
            in.close();

            return inputLine;
        } catch (IOException e) {
            Throwables.propagate(e);
        }

        return null;
    }
}
