/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lib;

import java.util.Comparator;
import java.util.ArrayList;

/**
 *
 * @author victoriocarvalho
 */
@SuppressWarnings("rawtypes") // Anotação para suprimir avisos de compilação
public class BinaryTreeImpl<T> implements BinaryTree<T> {

    protected Node<T> root = null;
    protected Comparator<T> comparator;

    public BinaryTreeImpl(Comparator<T> comp) {
        comparator = comp;
    }

    @Override
    public void adicionar(T newValue) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public T pesquisar(T valor) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public T pesquisar(T valor, Comparator customComparator) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public T remover(T valor) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public int altura() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public String caminharEmNivel() {

        Node<T> currentNode = root;
        String buffer = "";

        if(currentNode != null){
            ArrayList<Node<T>> queue = new ArrayList<>();
            queue.add(currentNode);
            while(queue.size() > 0){
                currentNode = queue.get(0);
                buffer += currentNode.getValor().toString();
                if(currentNode.getFilhoEsquerda() != null){
                    queue.add(currentNode.getFilhoEsquerda());
                }
                if(currentNode.getFilhoDireita() != null){
                    queue.add(currentNode.getFilhoDireita());
                }
                queue.remove(0);
            }
        }

        return buffer;

    }

    @Override
    public String caminharEmOrdem() {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
