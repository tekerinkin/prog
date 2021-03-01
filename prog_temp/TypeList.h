//
// Created by Дима Шестаков on 01.03.2021.
//

#ifndef C___TYPELIST_H
#define C___TYPELIST_H


#include<iostream>


namespace internal{
    struct Void{
    };
} //internal

template<typename ...Args>
struct TypeList{
    typedef internal::Void Head;
    typedef internal::Void Tail;
};

typedef TypeList<> EmptyTypeList;

template<typename H, typename ...T>
struct TypeList<H, T...>{
    typedef H Head;
    typedef TypeList<T...> Tail;
};


//IsEmpty

template<typename Tl>
struct IsEmpty : std::true_type
{};

template<>
struct IsEmpty<TypeList<internal::Void, internal::Void>> :
        std::true_type
{};

template<typename ...Args>
struct IsEmpty<TypeList<Args...>> :
        std::integral_constant<bool,
                IsEmpty<typename TypeList<Args...>::Tail>::value && std::is_same<typename TypeList<Args...>::Head, internal::Void>::value>
{};


//Contains
template<typename T, typename ...Tl>
struct Contains :
        std::false_type
{
};

template<typename ...Args>
struct Contains<internal::Void, Args...> :
        std::false_type
{};

template<typename T, typename ...Args>
struct Contains<T, TypeList<Args...>> :
        std::integral_constant<bool,
                std::is_same<typename TypeList<Args...>::Head, T>::value || Contains<T, typename TypeList<Args...>::Tail>::value>
{};


//Length

template<typename T>
struct Length :
        std::integral_constant<unsigned int, 0>
{};

template<typename ...Args>
struct Length<TypeList<Args...>> :
        std::integral_constant<unsigned int,
                IsEmpty<TypeList<Args...>>::value ? 0 :
                1 + Length<typename TypeList<Args...>::Tail>::value>
{};


//Type_at

template<unsigned int N, typename T>
struct Type_at{
    typedef internal::Void type;
};

template<typename ...Args>
struct Type_at<0, TypeList<Args...>>
{
    typedef typename TypeList<Args...>::Head type;
};

template<unsigned int N, typename ...Args>
struct Type_at<N, TypeList<Args...>>
{
    static_assert(N < Length<TypeList<Args...>>::value, "N is too big");
    typedef typename Type_at<N-1, typename TypeList<Args...>::Tail>::type type;
};



// output

std::ostream& operator<<(std::ostream& ostr, EmptyTypeList)
{
    ostr << "{}";
    return ostr;
}

template<typename Tl>
void PrintTypeListHelper(Tl, std::ostream& ostr)
{
}

template<typename T>
void PrintTypeListHead(T, std::ostream& ostr)
{
   ostr << typeid(T).name();
}

template<typename ...Args>
void PrintTypeListHead(TypeList<Args...> tl, std::ostream& ostr)
{
    ostr << tl;
}

template<typename H, typename ...Args>
void PrintTypeListHelper(TypeList<H, Args...>, std::ostream& ostr)
{
    PrintTypeListHead(H(), ostr);
    if(!IsEmpty<TypeList<Args...>>::value){
        ostr << ' ';
        PrintTypeListHelper<Args...>(TypeList<Args...>(), ostr);
    }
}

template<typename ...Args>
std::ostream& operator<<(std::ostream& ostr,TypeList<Args...> tl)
{
    ostr << '{';
    PrintTypeListHelper(tl, ostr);
    ostr << '}';
    return ostr;
}


//append

template<typename T2, typename ...Tl1>
struct Append{
};

template<typename T, typename ...Args>
struct Append<T, TypeList<Args...>>{
    typedef TypeList<Args...,T> type;
};

template<typename ...Tl1, typename ...Tl2>
struct Append<TypeList<Tl1...>, TypeList<Tl2...>>
{
    typedef TypeList<Tl1...,Tl2...> type;
};
#endif //C___TYPELIST_H
