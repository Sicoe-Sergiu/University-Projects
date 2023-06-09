package com.example.myinterpreter_gui_2.View;

import com.example.myinterpreter_gui_2.Controller.Controller;
import com.example.myinterpreter_gui_2.Exceptions.ADTException;
import com.example.myinterpreter_gui_2.Exceptions.ExpressionEvaluationException;
import com.example.myinterpreter_gui_2.Exceptions.StatementExecutionException;
import com.example.myinterpreter_gui_2.Model.ADTs.MyDictionary;
import com.example.myinterpreter_gui_2.Model.ADTs.MyHeap;
import com.example.myinterpreter_gui_2.Model.ADTs.MyList;
import com.example.myinterpreter_gui_2.Model.ADTs.MyStack;
import com.example.myinterpreter_gui_2.Model.Expressions.*;
import com.example.myinterpreter_gui_2.Model.ProgramState.ProgramState;
import com.example.myinterpreter_gui_2.Model.Statements.*;
import com.example.myinterpreter_gui_2.Model.Statements.FileOperations.CloseReadFile;
import com.example.myinterpreter_gui_2.Model.Statements.FileOperations.OpenReadFile;
import com.example.myinterpreter_gui_2.Model.Statements.FileOperations.ReadFile;
import com.example.myinterpreter_gui_2.Model.Types.BoolType;
import com.example.myinterpreter_gui_2.Model.Types.IntType;
import com.example.myinterpreter_gui_2.Model.Types.RefType;
import com.example.myinterpreter_gui_2.Model.Types.StringType;
import com.example.myinterpreter_gui_2.Model.Values.BoolValue;
import com.example.myinterpreter_gui_2.Model.Values.IntValue;
import com.example.myinterpreter_gui_2.Model.Values.StringValue;
import com.example.myinterpreter_gui_2.Repository.IRepository;
import com.example.myinterpreter_gui_2.Repository.Repository;

public class Interpreter {
    public static void main(String[] args){

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));

        // EX_1 #######################################################################################################
        IStatement ex1 = new CompoundStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(new AssignmentStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));

        try{
            ex1.typeCheck(new MyDictionary<>());
            ProgramState prg1 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex1);
            IRepository repo1 = new Repository(prg1, "log1.txt");
            Controller ctrl1 = new Controller(repo1);
            menu.addCommand(new RunExampleCommand("1", ex1.toString(), ctrl1));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_2 #######################################################################################################
        IStatement ex2 = new CompoundStatement(new VariableDeclarationStatement("a",new IntType()),
                new CompoundStatement(new VariableDeclarationStatement("b",new IntType()),
                        new CompoundStatement(new AssignmentStatement("a", new ArithmeticExpression('+',new ValueExpression(new IntValue(2)),new
                                ArithmeticExpression('*',new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompoundStatement(new AssignmentStatement("b",new ArithmeticExpression('+',new VariableExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VariableExpression("b"))))));
        try {
            ex2.typeCheck(new MyDictionary<>());
            ProgramState prg2 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex2);
            IRepository repo2 = new Repository(prg2, "log2.txt");
            Controller ctrl2 = new Controller(repo2);
            menu.addCommand(new RunExampleCommand("2", ex2.toString(), ctrl2));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_3 #######################################################################################################
        IStatement ex3 = new CompoundStatement(new VariableDeclarationStatement("a", new BoolType()),
                new CompoundStatement(new VariableDeclarationStatement("v", new IntType()),
                        new CompoundStatement(new AssignmentStatement("a", new ValueExpression(new BoolValue(true))),
                                new CompoundStatement(new IfStatement(new VariableExpression("a"),
                                        new AssignmentStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssignmentStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));
        try {
            ex3.typeCheck(new MyDictionary<>());
            ProgramState prg3 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex3);
            IRepository repo3 = new Repository(prg3, "log3.txt");
            Controller ctrl3 = new Controller(repo3);
            menu.addCommand(new RunExampleCommand("3", ex3.toString(), ctrl3));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_4 #######################################################################################################
        IStatement ex4 = new CompoundStatement(new VariableDeclarationStatement("varf", new StringType()),
                new CompoundStatement(new AssignmentStatement("varf", new ValueExpression(new StringValue("test.in"))),
                        new CompoundStatement(new OpenReadFile(new VariableExpression("varf")),
                                new CompoundStatement(new VariableDeclarationStatement("varc", new IntType()),
                                        new CompoundStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                new CompoundStatement(new PrintStatement(new VariableExpression("varc")),
                                                        new CompoundStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                                new CompoundStatement(new PrintStatement(new VariableExpression("varc")),
                                                                        new CloseReadFile(new VariableExpression("varf"))))))))));
        try {
            ex4.typeCheck(new MyDictionary<>());
            ProgramState prg4 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex4);
            IRepository repo4 = new Repository(prg4, "log4.txt");
            Controller ctrl4 = new Controller(repo4);
            menu.addCommand(new RunExampleCommand("4", ex4.toString(), ctrl4));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_5 #######################################################################################################
        IStatement ex5 = new CompoundStatement(new VariableDeclarationStatement("a", new IntType()),
                new CompoundStatement(new VariableDeclarationStatement("b", new IntType()),
                        new CompoundStatement(new AssignmentStatement("a", new ValueExpression(new IntValue(5))),
                                new CompoundStatement(new AssignmentStatement("b", new ValueExpression(new IntValue(7))),
                                        new IfStatement(new RelationalExpression(">", new VariableExpression("a"),
                                                new VariableExpression("b")),new PrintStatement(new VariableExpression("a")),
                                                new PrintStatement(new VariableExpression("b")))))));
        try {
            ex5.typeCheck(new MyDictionary<>());
            ProgramState prg5 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex5);
            IRepository repo5 = new Repository(prg5, "log5.txt");
            Controller ctrl5 = new Controller(repo5);
            menu.addCommand(new RunExampleCommand("5", ex5.toString(), ctrl5));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_6 #######################################################################################################
        IStatement ex6 = new CompoundStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(new AssignmentStatement("v", new ValueExpression(new IntValue(4))),
                        new CompoundStatement(new WhileStatement(new RelationalExpression(">", new VariableExpression("v"), new ValueExpression(new IntValue(0))),
                                new CompoundStatement(new PrintStatement(new VariableExpression("v")), new AssignmentStatement("v",new ArithmeticExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VariableExpression("v")))));
        try {
            ex6.typeCheck(new MyDictionary<>());
            ProgramState prg6 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex6);
            IRepository repo6 = new Repository(prg6, "log6.txt");
            Controller ctrl6 = new Controller(repo6);
            menu.addCommand(new RunExampleCommand("6", ex6.toString(), ctrl6));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_7 #######################################################################################################
        IStatement ex7 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompoundStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompoundStatement(new HeapAllocationStatement("a", new VariableExpression("v")),
                                        new CompoundStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new VariableExpression("a")))))));
        try {
            ex7.typeCheck(new MyDictionary<>());
            ProgramState prg7 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex7);
            IRepository repo7 = new Repository(prg7, "log7.txt");
            Controller ctrl7 = new Controller(repo7);
            menu.addCommand(new RunExampleCommand("7", ex7.toString(), ctrl7));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_8 #######################################################################################################
        IStatement ex8 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompoundStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompoundStatement(new HeapAllocationStatement("a", new VariableExpression("v")),
                                        new CompoundStatement(new PrintStatement(new HeapReadingExpression(new VariableExpression("v"))),
                                                new PrintStatement(new ArithmeticExpression('+',new HeapReadingExpression(new HeapReadingExpression(new VariableExpression("a"))), new ValueExpression(new IntValue(5)))))))));
        try {
            ex8.typeCheck(new MyDictionary<>());
            ProgramState prg8 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex8);
            IRepository repo8 = new Repository(prg8, "log8.txt");
            Controller ctrl8 = new Controller(repo8);
            menu.addCommand(new RunExampleCommand("8", ex8.toString(), ctrl8));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_9 #######################################################################################################
        IStatement ex9 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompoundStatement( new PrintStatement(new HeapReadingExpression(new VariableExpression("v"))),
                                new CompoundStatement(new HeapWritingStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithmeticExpression('+', new HeapReadingExpression(new VariableExpression("v")), new ValueExpression(new IntValue(5))))))));
        try {
            ex9.typeCheck(new MyDictionary<>());
            ProgramState prg9 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex9);
            IRepository repo9 = new Repository(prg9, "log9.txt");
            Controller ctrl9 = new Controller(repo9);
            menu.addCommand(new RunExampleCommand("9", ex9.toString(), ctrl9));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        // EX_10 #######################################################################################################
        IStatement ex10 = new CompoundStatement(new VariableDeclarationStatement("v", new RefType(new IntType())),
                new CompoundStatement(new HeapAllocationStatement("v", new ValueExpression(new IntValue(20))),
                        new CompoundStatement(new VariableDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompoundStatement(new HeapAllocationStatement("a", new VariableExpression("v")),
                                        new CompoundStatement(new HeapAllocationStatement("v", new ValueExpression(new IntValue(30))),
                                                new PrintStatement(new HeapReadingExpression(new HeapReadingExpression(new VariableExpression("a")))))))));
        try {
            ex10.typeCheck(new MyDictionary<>());
            ProgramState prg10 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex10);
            IRepository repo10 = new Repository(prg10, "log10.txt");
            Controller ctrl10 = new Controller(repo10);
            menu.addCommand(new RunExampleCommand("10", ex10.toString(), ctrl10));

        }catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }

        IStatement ex11 = new CompoundStatement(new VariableDeclarationStatement("v", new IntType()),
                new CompoundStatement(new VariableDeclarationStatement("a", new RefType(new IntType())),
                        new CompoundStatement(new AssignmentStatement("v", new ValueExpression(new IntValue(10))),
                                new CompoundStatement(new HeapAllocationStatement("a", new ValueExpression(new IntValue(22))),
                                        new CompoundStatement(new ForkStatement(new CompoundStatement(new HeapWritingStatement("a", new ValueExpression(new IntValue(30))),
                                                new CompoundStatement(new AssignmentStatement("v", new ValueExpression(new IntValue(32))),
                                                        new CompoundStatement(new PrintStatement(new VariableExpression("v")),
                                                                new PrintStatement(new HeapReadingExpression(new VariableExpression("a"))))))),
                                                new CompoundStatement(new PrintStatement(new VariableExpression("v")),
                                                        new PrintStatement(new HeapReadingExpression(new VariableExpression("a")))))))));
        try {
            ex11.typeCheck(new MyDictionary<>());
            ProgramState prg11 = new ProgramState(new MyStack<>(), new MyDictionary<>(), new MyList<>(), new MyDictionary<>(), new MyHeap(), ex11);
            IRepository repo11 = new Repository(prg11, "log11.txt");
            Controller ctrl11 = new Controller(repo11);
            menu.addCommand(new RunExampleCommand("11", ex11.toString(), ctrl11));
        } catch (ExpressionEvaluationException | ADTException | StatementExecutionException e) {
            System.out.println(e.getMessage());
        }
        menu.show();
    }
}
