package com.sigac.firefighter.model;

public interface ObservableModelManager extends ModelManager {

    public void addObserver(Observer observer);

    public static interface Observer {
        public void onChange(ModelManager m);
    }

    public static class Factory {
        public static ObservableModelManager get() {
            return ApiModelManager.getInstance();
        }
    }
}
