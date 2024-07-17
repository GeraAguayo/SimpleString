#include <cstdio>
#include <stdexcept>
#include <cstring>


struct SimpleString{
	//Constructor definition
	SimpleString()
	: max_size{0}, buffer{nullptr}, length{0} {}

	//Constructor implementation
    SimpleString (size_t max_size) 
    : max_size {max_size},
    length{} {
        if (max_size == 0){
            throw std::runtime_error{"Invalid size to create string"};
        }
        buffer = new char[max_size];
        buffer[0] = 0;  
    }

	//Copy constructor  
	SimpleString(const SimpleString& original)
	: max_size{original.max_size}, length{original.length}, buffer{new char [original.max_size]} {
		std::strncpy(this->buffer, original.buffer, this->max_size);
	}

    //Copy assignment operator
    SimpleString& operator=(const SimpleString& other){

        if (this == &other){
            printf("They are the same string.\n");
            return *this;   
        }
        else{
            char* new_buffer = new char[other.max_size];
            delete[] buffer;
            buffer = new_buffer;
            length = other.length;
            max_size = other.max_size;
            std::strncpy(buffer, other.buffer, max_size);
            return *this;

        }
        

    }

    //Move operator
    SimpleString moveTo(SimpleString& destiny){
        if(this == &destiny){
            printf("Move operation canceled, origin and destiny are the same.\n");
            return *this;
        }
        else{
            destiny.max_size = max_size;
            destiny.length = length;
            std::strncpy(destiny.buffer, buffer, destiny.max_size);
            delete[] buffer;
            length = 0;
            max_size = 0;
            buffer = nullptr;
            return destiny;
        }
    }

    ~SimpleString() {
        delete[] buffer;
    }

    void print() const{
        printf("\nString: %s",buffer);
		printf("Address: %p\n", buffer);
    }
    
    bool add_line(const char* input_char){
        const auto input_len = strlen(input_char);
        //If the sum of the current len, the input len and 2 more(for null and breakline) it's greater than the max_size allowed
        if (input_len + this->length + 2 > this->max_size) return false;
        //Else
        std::strncpy(this->buffer + this->length, input_char, this->max_size - this->length);
        this->length += input_len;
        this->buffer[this->length++] = '\n';
        this->buffer[this->length] = 0;

        return true;
    }

    private:
        size_t max_size;
        char* buffer;
        size_t length;


};
