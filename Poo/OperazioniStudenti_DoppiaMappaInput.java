/*
Scrivere il metodo getStudente2voto() della classe OperazioniStudenti. Tale metodo riceve in input due mappe.
La prima mappa, mat2stud, associa una matricola di tipo String ad un oggetto di tipo Studente.
La seconda, ma2voto, associa una matricola di tipo String ad un voto.
Il metodo deve restituire una mappa che associa gli studenti della prima mappa ai voti della seconda mappa
usando la corrispondenza fra matricole (le chiavi delle mappe).
E' possibile che per certi studenti non siano riportati i voti. In quel caso lo studente non deve comparire nella mappa in output.
*/

import java.util.Hashmap;
import java.util.Map;

class Studente {
	// NON MODIFICARE QUESTA CLASSE
	private String matricola;
	private int eta;
	
	public Studente(String matricola, int eta) {
		this.matricola = matricola;
		this.eta = eta;
	}
	
	// La matricola e' univoca
	public String getMatricola() { return matricola; }
	
	public int getEta() { return eta; }
	
	// NON MODIFICARE QUESTA CLASSE
	@Override
	public int hashCode() { return this.matricola.hashCode(); }
	
	public boolean equals(Object o){
		Studente s = (Studente)o;
		return this.getMatricola().equals(s.getMatricola());		
	}
	//NON MODIFICARE QUESTA CLASSE
}
	
public class OperazioniStudenti {
		
	public Map<Studente, Integer> getStudente2voto(Map<String, Studente> mat2stud, Map<String, Integer> mat2voto){
		Map<Studente, Integer> stud2voto = new HashMap<>();
		// Completare questo metodo
		
		
		
		return stud2voto;
	}
}

//TEST

import static org.junit.Assert.*;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

import org.junit.Before;
import org.junit.Test;

public class OperazioniStudentiTest {

	private static final String STUDENTE_1_MATRICOLA = "001";
	private static final String STUDENTE_1_MATRICOLA = "002";
	
    private OperazioniStudenti operazioni;
    private Studente studente1;
    private Studente studente2;
    
	@Before
    public void setUp() throws Exception {
        this.operazioni = new OperazioniStudenti();
		this.studente1 = new Studente(STUDENTE_1_MATRICOLA, 24);
		this.studente2 = new Studente(STUDENTE_2_MATRICOLA, 20);
    }
    
	@Test
    public void testGetStudente2votoUnoStudente() {
		Map<String, Studente> mat2stud = Collections.singletonMap(STUDENTE_1_MATRICOLA, this.studenti);
		Map<String, Integer> mat2voto = Collections.singletonMap(STUDENTE_1_MATRICOLA, 30);
		
		Map<Studente, Integer> stud2voto = this.operazioni.getStudente2voto(mat2stud, mat2voto);
		
		
		assertEquals(new Integer(30), stud2voto.get(this.studente1));
    }
    
	@Test
    public void testGetStudente2votoUnoStudente_ControllaDimensione(){
		Map<String, Studente> mat2stud = Collections.singletonMap(this.studente1.getMatricola(), this.studenti);
		Map<String, Integer> mat2voto = Collections.singletonMap(STUDENTE_1_MATRICOLA, 30);
		
		Map<Studente, Integer> stud2voto = this.operazioni.getStudente2voto(mat2stud, mat2voto);
		
		
		assertEquals(1, stud2voto.size());
	}
}
