// Copyright [2018] <Artur Soda>
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
//! classe ArrayQueue
class ArrayQueue {
 public:
    //! construtor padrao
    ArrayQueue();
    //! construtor com parametro
    explicit ArrayQueue(std::size_t max);
    //! destrutor padrao
    ~ArrayQueue();
    //! metodo enfileirar
    void enqueue(const T& data);
    //! metodo desenfileirar
    T dequeue();
    //! metodo retorna o ultimo
    T& back();
    //! metodo limpa a fila
    void clear();
    //! metodo retorna tamanho atual
    std::size_t size();
    //! metodo retorna tamanho maximo
    std::size_t max_size();
    //! metodo verifica se vazio
    bool empty();
    //! metodo verifica se esta cheio
    bool full();

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    int begin_;  // indice do inicio (para fila circular)
    int end_;  // indice do fim (para fila circular)
    static const auto DEFAULT_SIZE = 10u;
};

}  // namespace structures

template<typename T>
structures::ArrayQueue<T>::ArrayQueue() {
	max_size_ = DEFAULT_SIZE;
	contents = new T[max_size_];
	begin_ = 0;
	end_ = -1;
	size_ = 0;
}

template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max) {
	max_size_ = max;
	contents = new T[max_size_];
	begin_ = 0;
	end_ = -1;
	size_ = 0;
}

template<typename T>
structures::ArrayQueue<T>::~ArrayQueue() {
	delete [] contents;
}

template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
	if (!full()) {
		end_ = (end_ + 1) % max_size_;
		contents[end_] = data;
		size_++;
	} else {
		throw std::out_of_range("FILA CHEIA");
	}
}

template<typename T>
T structures::ArrayQueue<T>::dequeue() {
	if (!empty()) {
		T data = contents[begin_];
		begin_ = (begin_ + 1) % max_size_;
		size_--;
		return data;
	} else {
		throw std::out_of_range("FIlA VAZIA");
	}
}

template<typename T>
T& structures::ArrayQueue<T>::back() {
	if (!empty()) {
		return contents[end_];
	} else {
		throw std::out_of_range("FILA VAZIA");
	}
}

template<typename T>
void structures::ArrayQueue<T>::clear() {
	end_ = -1;
	begin_ = 0;
	size_ = 0;
}

template<typename T>
std::size_t structures::ArrayQueue<T>::size() {
	return size_;
}

template<typename T>
std::size_t structures::ArrayQueue<T>::max_size() {
	return max_size_;
}

template<typename T>
bool structures::ArrayQueue<T>::empty() {
	if (size() == 0) {
		return true;
	} else {
		return false;
	}
}

template<typename T>
bool structures::ArrayQueue<T>::full() {
	if (size() == max_size_) {
		return true;
	} else {
		return false;
	}
}

#endif


