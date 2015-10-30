package com.sigac.firefighter;

import android.content.Context;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;

public class MainFragmentPageAdapter extends FragmentPagerAdapter {

    /* TODO: So ugly, but at least we don't have magical numbers flying around */
    public static int VICTIM_TAB_INDEX = 2;

    /* TODO: Who needs types? :P */
    private static Object[][] TABS = {
            {"Screening", new ScreeningFragment()},
            {"Search", new SearchFragment()},
            {"Victim", new VictimFragment()}
    };

    private Context mContext;

    public MainFragmentPageAdapter(FragmentManager fm, Context context) {
        super(fm);
        mContext = context;
    }

    @Override
    public int getCount() {
        return TABS.length;
    }

    @Override
    public Fragment getItem(int position) {
        return (Fragment) TABS[position][1];
    }

    @Override
    public CharSequence getPageTitle(int position) {
        return (String) TABS[position][0];
    }

}
