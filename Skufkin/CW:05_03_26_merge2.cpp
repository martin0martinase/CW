#include <cstddef>

template <class T>
struct Bilist
{
    T val;
    Bilist<T> *next;
    Bilist<T> *prev;
};
template <class T>
Bilist<T> zero_node()
{
    Bilist<T> *head = new Bilist<T>{0, nullptr, nullptr}; // T();
    return head;
}
template <class T, class A>
Bilist<T> add(Bilist<T> *head, A &added)
{
    Bilist<T> *NewNode = new Bilist<T>{std::forward<A>(added), nullptr, head}; // T(); A(&&)
    head->next = NewNode;
    head = NewNode;
    return head;
}
template <class T>
void strong_clear(Bilist<T> *head)
{
    while (head->prev != nullptr)
    {
        head = head->prev;
        delete head->next;
    }
}
template <class T>
void omega_clear(Bilist<T> *head)
{
    while (head->prev != nullptr)
    {
        head = head->prev;
        delete head->val;
    }
}
