package com.sigac.firefighter;

import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.*;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import com.sigac.firefighter.model.ObservableModelManager;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

// TODO: Save buttons state when pressed, there is no way to tell the gender of the current victim being created!
public class ScreeningFragment extends Fragment {

    private TextView mIdTextView;

    private Button mMaleButton;
    private Button mFemaleButton;

    private Button mChildButton;
    private Button mYoungButton;
    private Button mAdultButton;
    private Button mOldButton;

    private Button mSafeButton;
    private Button mInjuredbutton;
    private Button mSevereButton;
    private Button mDeadButton;

    private Button mSubmitButton;

    private Victim mVictim;

    private ObservableModelManager mModelManager;
    private EditText mVictimName;
    private TextView mIdField;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mModelManager = ObservableModelManager.Factory.get();
        mVictim = new Victim();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.screening_fragment, container, false);

        mIdField = (TextView) view.findViewById(R.id.id_field);
        mIdField.setText(Integer.toString(randomId(), 16));

        mVictimName = (EditText) view.findViewById(R.id.victim_name);

        mMaleButton = (Button) view.findViewById(R.id.button_male);
        mMaleButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setSex(Victim.Sex.MALE);
            }
        });

        mFemaleButton = (Button) view.findViewById(R.id.button_female);
        mFemaleButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setSex(Victim.Sex.FEMALE);
            }
        });

        mChildButton = (Button) view.findViewById(R.id.button_child);
        mChildButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setAge(Victim.Age.CHILD);
            }
        });

        mYoungButton = (Button) view.findViewById(R.id.button_young);
        mYoungButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setAge(Victim.Age.YOUNG);
            }
        });

        mAdultButton = (Button) view.findViewById(R.id.button_adult);
        mAdultButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setAge(Victim.Age.ADULT);
            }
        });

        mOldButton = (Button) view.findViewById(R.id.button_old);
        mOldButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setAge(Victim.Age.OLD);
            }
        });

        mSafeButton = (Button) view.findViewById(R.id.button_safe);
        mSafeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setState(Victim.State.GREEN);
            }
        });

        mInjuredbutton = (Button) view.findViewById(R.id.button_injured);
        mInjuredbutton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setState(Victim.State.YELLOW);
            }
        });

        mSevereButton = (Button) view.findViewById(R.id.button_severe);
        mSevereButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setState(Victim.State.RED);
            }
        });

        mDeadButton = (Button) view.findViewById(R.id.button_dead);
        mDeadButton .setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setState(Victim.State.BLACK);
            }
        });

        mSubmitButton = (Button) view.findViewById(R.id.submit_button);
        mSubmitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mVictim.setId(Integer.parseInt(mIdField.getText().toString(), 16));
                mVictim.setName(mVictimName.getText().toString());
                new PersistVictimsTask().execute();
                mIdField.setText(Integer.toString(randomId(), 16));
                mVictim = new Victim();
            }
        });

        return view;
    }

    private class PersistVictimsTask extends AsyncTask<Void, Void, Void> {
        @Override
        protected Void doInBackground(Void... params) {
            mModelManager.persistVictim(mVictim);
            return null;
        }
    }

    // TODO: REMOVE THIS!!!
    // TODO: REMOVE THIS!!!
    // TODO: REMOVE THIS!!!
    private static Random RANDOM = new Random();

    private static int randomId() {
        return RANDOM.nextInt();
    }
}
