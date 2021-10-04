package org.una;

import org.una.facade.Facade;


//el cliente interactúa directamente con la Fachada y no con los subsistemas, de esta manera
//se da una utilización sencilla y fácil de usar


public class App {
    public static void main(String[] args) {
        Facade cliente1 = new Facade();
        cliente1.buscar("02/07/2018", "08/07/2018", "San José", "Cartago");

        Facade cliente2 = new Facade();
        cliente2.buscar("02/07/2018", "08/07/2018", "Heredia", "Guanacaste");
    }
}
