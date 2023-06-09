package com.example.myinterpreter_gui_2.Model.Values;

import com.example.myinterpreter_gui_2.Model.Types.BoolType;
import com.example.myinterpreter_gui_2.Model.Types.Type;

public class BoolValue implements Value{

    boolean value;

    public BoolValue(boolean value) {
        this.value = value;
    }

    public Boolean getValue(){ return this.value; }

    @Override
    public Type getType() {
        return new BoolType();
    }

    @Override
    public String toString(){ return this.value ? "true" : "false"; }

    @Override
    public Value deepCopy() {
        return new BoolValue(value);
    }

    public boolean equals(Value anotherValue){
        if (!(anotherValue instanceof BoolValue))
            return false;
        return this.value == ((BoolValue) anotherValue).value;
    }
}
