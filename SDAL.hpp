#include <ostream>
#include <cstddef>

namespace cop3530 {
    template <typename T>
    class SDAL {
    private:
        int maxSize;
        int currentSize;
        T* list;
        void resizeList();
    
    public:
        
        // Non const iterator.
        class SDAL_Iter //: public std::iterator<std::forward_iterator_tag, T>
        {
        public:
            // inheriting from std::iterator<std::forward_iterator_tag, T>
            // automagically sets up these typedefs...
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::forward_iterator_tag iterator_category;
      
            // but not these typedefs...
            typedef SDAL_Iter self_type;
            typedef SDAL_Iter& self_reference;
      
        private:
            T* position;
      
        public:
            explicit SDAL_Iter( pointer pos = nullptr ) : position( pos ) {}
            SDAL_Iter( const SDAL_Iter& src ) : position( src.position ) {}
       
            reference operator*() const {
                return *position;
            }
            pointer operator->() const {
                return position;
            }
      
            self_reference operator=( const SDAL_Iter& src ) {
                position = src.position;
            }

            self_reference operator++() {
                ++position;
                return *this;
            } // preincrement
            
            self_type operator++(int) {
                self_type result( *this );
                ++position;
                return result;
            } // postincrement

            bool operator==(const SDAL_Iter& rhs) const {
                return position == rhs.position;
            }
            bool operator!=(const SDAL_Iter& rhs) const {
                return position != rhs.position;
            }
        }; // end SDAL_Iter 

        class SDAL_Const_Iter //: public std::iterator<std::forward_iterator_tag, T>
        {
        public:
            // inheriting from std::iterator<std::forward_iterator_tag, T>
            // automagically sets up these typedefs...
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef const T& reference;
            typedef const T* pointer; 
            typedef std::forward_iterator_tag iterator_category;
      
            // but not these typedefs...
            typedef SDAL_Const_Iter self_type;
            typedef SDAL_Const_Iter& self_reference;
      
        private:
            const T* position;
      
        public:
            explicit SDAL_Const_Iter( pointer pos = nullptr ) : position( pos ) {}
            SDAL_Const_Iter( const SDAL_Iter& src ) : position( src.position ) {}
       
            reference operator*() const {
                return *position;
            }
            pointer operator->() const {
                return position;
            }
      
            self_reference operator=( const SDAL_Iter& src ) {
                position = src.position;
            }

            self_reference operator++() {
                ++position;
                return *this;
            } // preincrement
            
            self_type operator++(int) {
                self_type result( *this );
                ++position;
                return result;
            } // postincrement

            bool operator==(const SDAL_Const_Iter& rhs) const {
                return position == rhs.position;
            }
            bool operator!=(const SDAL_Const_Iter& rhs) const {
                return position != rhs.position;
            }
        }; // end SDAL_Iter 

        typedef std::size_t size_t;
        typedef T value_type;
        typedef SDAL_Iter iterator;
        typedef SDAL_Const_Iter const_iterator; 
        iterator begin() { return SDAL_Iter( list ); }
        iterator end() { return SDAL_Iter( list + currentSize ); }
        const_iterator begin() const { return SDAL_Const_Iter( list ); }
        const_iterator end() const { return SDAL_Const_Iter( list + currentSize ); } 

        SDAL();
        SDAL( int maxSize );
        SDAL( const SDAL& src );
        ~SDAL();
        SDAL& operator=( const SDAL& src ) {
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
        size_t size() const;
        void clear();
        bool contains( const T& element, 
                       bool equals( const T& a, const T& b  ) ) const;
        std::ostream& print( std::ostream& out ) const;
        T& operator[](int i);
        T const& operator[](int i) const;
    };
}
