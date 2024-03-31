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
        Node<T> newNode = new Node<>(newValue);
        if (root == null) {
            root = newNode;
        } else {
            Node<T> currentNode = root;
            Node<T> previousNode;
            while (true) {
                previousNode = currentNode;
                if (comparator.compare(newValue, currentNode.getValor()) < 0) {
                    currentNode = currentNode.getFilhoEsquerda();
                    if (currentNode == null) {
                        previousNode.setFilhoEsquerda(newNode);
                        return;
                    }
                } else {
                    currentNode = currentNode.getFilhoDireita();
                    if (currentNode == null) {
                        previousNode.setFilhoDireita(newNode);
                        return;
                    }
                }
            }
        }
    }

    @Override
    public T pesquisar(T valor) {
        Node<T> currentNode = root;
        while (currentNode != null) {
            if (this.comparator.compare(valor, currentNode.getValor()) == 0) {
                return currentNode.getValor();
            } else if (this.comparator.compare(valor, currentNode.getValor()) < 0) {
                currentNode = currentNode.getFilhoEsquerda();
            } else {
                currentNode = currentNode.getFilhoDireita();
            }
        }
        return null;
    }

    @SuppressWarnings("unchecked") // Anotação para suprimir avisos de compilação
    @Override
    public T pesquisar(T valor, Comparator customComparator) {
        Node<T> currentNode = root;
        while (currentNode != null) {
            if (customComparator.compare(valor, currentNode.getValor()) == 0) {
                return currentNode.getValor();
            } else if (customComparator.compare(valor, currentNode.getValor()) < 0) {
                currentNode = currentNode.getFilhoEsquerda();
            } else {
                currentNode = currentNode.getFilhoDireita();
            }
        }
        return null;
    }

    @Override
    public T remover(T valor) {
        Node<T> currentNode = root;
        while(currentNode != null){
            if(this.comparator.compare(valor, currentNode.getValor()) == 0){
                T removedValue = currentNode.getValor();
                if(currentNode.getFilhoDireita() == null && currentNode.getFilhoEsquerda() == null){
                    currentNode = null; // Nó não possui filhos
                }else if(currentNode.getFilhoDireita() == null){
                    currentNode = currentNode.getFilhoEsquerda(); // Nó possui apenas filho à esquerda
                }else if(currentNode.getFilhoEsquerda() == null){
                    currentNode = currentNode.getFilhoDireita(); // Nó possui apenas filho à direita
                }else{
                    Node<T> successor = currentNode.getFilhoDireita();
                    while(successor.getFilhoEsquerda() != null){
                        successor = successor.getFilhoEsquerda();
                    }
                    currentNode.setValor(successor.getValor());
                    successor = null;
                }
                return removedValue;
            }else if(this.comparator.compare(valor, currentNode.getValor()) < 0){
                currentNode = currentNode.getFilhoEsquerda();
            }else{
                currentNode = currentNode.getFilhoDireita();
            }
        }
        return null;
    }

    @Override
    public int altura() {
        
        Node<T> currentNode = root;
        int height = 0;

        while(currentNode != null){
            height++;
            if(currentNode.getFilhoDireita() != null){
                currentNode = currentNode.getFilhoDireita();
            }else if(currentNode.getFilhoEsquerda() != null){
                currentNode = currentNode.getFilhoEsquerda();
            }else{
                currentNode = null;
            }
        }
        return height;
    }

    @Override
    public int quantidadeNos() {
        int buffer = 0;
        Node<T> currentNode = root;
        while(currentNode != null){
            buffer++;
            if(currentNode.getFilhoDireita() != null){
                currentNode = currentNode.getFilhoDireita();
            }else if(currentNode.getFilhoEsquerda() != null){
                currentNode = currentNode.getFilhoEsquerda();
            }else{
                currentNode = null;
            }
        }
        return buffer;
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
