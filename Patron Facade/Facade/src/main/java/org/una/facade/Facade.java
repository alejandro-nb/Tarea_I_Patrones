package org.una.facade;

import org.una.api.AvionAPI;
import org.una.api.HotelAPI;


//la Fachada implementa los métodos necesarios de los subsistemas, actúa como intermediario

public class Facade {

    private AvionAPI avionAPI;
    private HotelAPI hotelAPI;

    public Facade() {
        avionAPI = new AvionAPI();
        hotelAPI = new HotelAPI();
    }

    public void buscar(String fechaIda, String fechaVuelta, String origen, String destino) {
        avionAPI.buscarVuelos(fechaIda, fechaVuelta, origen, destino);
        hotelAPI.buscarHoteles(fechaIda, fechaVuelta, origen, destino);
    }
}
