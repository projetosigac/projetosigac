package com.sigac.firefighter;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import com.sigac.firefighter.model.ObservableModelManager;

public class VictimFragment extends Fragment {

    private EditText vVictimName;
    private Spinner vVictimSex;
    private EditText vVictimIdQuery;
    private Spinner vVictimPriority;
    private EditText vVictimComment;

    private ArrayAdapter<CharSequence> mVictimPriorityAdapter;
    private ArrayAdapter<CharSequence> mVictimSexAdapter;
    private ObservableModelManager mModelManager;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        mModelManager = ObservableModelManager.Factory.get();
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        ViewGroup view = (ViewGroup) inflater.inflate(R.layout.victim_fragment, container, false);
        vVictimName = (EditText) view.findViewById(R.id.victim_name);
        vVictimIdQuery = (EditText) view.findViewById(R.id.victim_id_query);
        vVictimComment = (EditText) view.findViewById(R.id.victim_comment);

        vVictimSex = (Spinner) view.findViewById(R.id.victim_sex);
        mVictimSexAdapter = ArrayAdapter.createFromResource(
                getActivity(),
                R.array.victim_sex,
                android.R.layout.simple_spinner_item);
        vVictimSex.setAdapter(mVictimSexAdapter);

        vVictimPriority = (Spinner) view.findViewById(R.id.victim_priority);
        mVictimPriorityAdapter = ArrayAdapter.createFromResource(
                getActivity(),
                R.array.victim_priorities,
                android.R.layout.simple_spinner_item);
        vVictimPriority.setAdapter(mVictimPriorityAdapter);

        return view;
    }

    public void selectVictim(Victim victim) {
        /* TODO: Name? */
        vVictimName.setText(victim.getName());
        vVictimIdQuery.setText(Integer.toString(victim.getId(), 16));

        /* TODO: LOL! It's 7 am! */
        for (int i = 0; i < mVictimSexAdapter.getCount(); i++) {
            String sex = (String) mVictimSexAdapter.getItem(i);
            if (victim.getSex().toString().toLowerCase().equals(sex.toLowerCase())) {
                vVictimSex.setSelection(i);
                break;
            }
        }

        /* TODO: Plz */
        for (int i = 0; i < mVictimPriorityAdapter.getCount(); i++) {
            String priority = (String) mVictimPriorityAdapter.getItem(i);
            if (victim.getState().toString().toLowerCase().equals(priority.toLowerCase())) {
                vVictimPriority.setSelection(i);
                break;
            }
        }

        vVictimComment.setText("Age: " + victim.getAge().toString());
    }
}
