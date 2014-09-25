#include <ostream>

template <typename T>
class SSLL {
private:
    struct Node {
        T value;
        Node* next;
        
        // Node with no arguments!
        Node() {
            this->value = NULL;
            this->value = NULL;
        }
        
        // For creating nodes with values.
        Node( T value ) {
            this->value = value;
            this->next = NULL;
        }
    };
    Node* head; 
    Node* tail;
    // Traversing the list every time is lame.
    int listSize;
    
public:
    SSLL();
    SSLL( const SSLL& src );
    ~SSLL();
    SSLL& operator=( const SSLL& src ) {
        if ( &src == this )
            return *this;
    }
    T replace( const T& element, int position );
    void insert( const T& element, int position );
    void push_front( const T& element );
    void push_back( const T& element );
    T pop_front();
    T pop_back();
    T remove( int position );
    T item_at( int position ) const;
    bool is_empty() const;
    int size() const;
    void clear();
    bool contains( const T& element, 
                   bool equals( const T& a, const T& b  ) ) const;
    std::ostream& print( std::ostream& out ) const;
};
