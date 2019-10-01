#include "Tape.h"

template <typename bn>
tape<bn>::tape()
{
    curr, tip, tail  = new cell<bn> = NULL;
    cnt = 0;
    itrt = false;
}

template <typename bn>
void tape<bn>::resetP()
{
    curr = tip;
}

template <typename bn>
void tape<bn>::itR()
{
    if (curr->next == NULL)
        curr = tip;
    else
        curr = curr->next;
}

template <typename bn>
void tape<bn>::itL()
{
    if (curr->prev == NULL)
        curr = tail;
    else
        curr = curr->prev;
}

template <typename bn>
bool tape<bn>:: isPset()
{
    if (curr == NULL)
    {
        cout << "isPset()" << endl;
        return false;
    }
    else
        return true;
}

template <typename bn>
int tape<bn>::getP()
{
    cell<bn>* nw = tip;

    int pos = 0;

    while (nw != curr)
    {
        pos++;
        nw = nw->next;
    } 

    delete nw;
    return pos;
}

template <typename bn>
void tape<bn>::setP(bn inD)
{
    isEmpty();

    while (curr->next != NULL && curr->dta != inD)
    {
        curr = curr->next;
    }

    isPset();
}

template <typename bn>
bn tape<bn>::read()
{
    isPset();

    return curr->dta;
}

template <typename bn>
void tape<bn>::write(bn inD)
{
    curr->dta = inD;
}

template <typename bn>
int tape<bn>::length()
{
    resetP();

    cnt = 1;

    while (curr->next != NULL)
    {
        curr = curr->next;
        cnt++;
    }

    return cnt;
}

template <typename bn>
bool tape<bn>::isEmpty()
{
    if (tip->next == NULL)
        return true;
}

template <typename bn>
bool tape<bn>::isFull()
{
    try {cell<bn>* tst = new cell<bn>;}

    catch (bad_alloc)
    {
        cout << "List is full" << endl;
        return true;
    }
    
    return false;
}


    //insert


template <typename bn>
void tape<bn>::iHead(bn inD)
{
    isFull();

    cell<bn>* nw = new cell<bn>;

    nw->dta = inD;
    nw->next = tip;
    nw->prev = NULL;

    tip->prev = nw;
    tip = nw;

    curr = tip;

    cnt++;

    delete nw;
}

template <typename bn>
void tape<bn>::iTail(bn inD)
{
    isFull();
    isEmpty();
    isPset();

    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    tail = curr;

    cell<bn>* nw = new cell<bn>;

    nw->dta = inD;
    nw->next = NULL;
    nw->prev = tail;

    tail->next = nw;
    tail = nw;

    curr = tail;

    cnt++;

    delete nw;
}
/*
template <typename bn>
void tape<bn>::iSorted(bn inD)
{
    isFull();
    isEmpty();
    isPset();

    if (inD < curr->dta)
        iSortedL(inD);
    else if (inD >= curr->dta)
        iSortedR(inD);

    
    while (curr->next != NULL && curr->dta < inD)
        {
            curr = curr->next;
        }
    
    cell<bn>* nw = new cell<bn>;

    nw->dta = inD;
    nw->next = curr->next;
    nw->prev = curr;
    
    curr->next->perv = nw;
    curr->next = nw;

    delete nw;
    
}

template <typename bn>
void tape<bn>::iSortedR(bn inD)
{
    while (curr->next != NULL && curr->dta < inD)
        {
            curr = curr->next;
        }
    
    cell<bn>* nw = new cell<bn>;

    nw->dta = inD;
    nw->next = curr->next;
    nw->prev = curr;
    
    curr->next->perv = nw;
    curr->next = nw;

    delete nw;
}

template <typename bn>
void tape<bn>::iSortedL(bn inD)
{
    while (curr->prev != NULL && curr->dta < inD)
        {
            curr = curr->prev;
        }
    
    cell<bn>* nw = new cell<bn>;

    nw->dta = inD;
    nw->next = curr;
    nw->prev = curr->prev;
    
    curr->prev->next = nw;
    curr->prev = nw;

    delete nw;
}

*/
    //find


template <typename bn>
bool tape<bn>::find(bn inD)
{
    isEmpty();
    resetP();

    while (curr->next != NULL && curr->dta != inD)
    {
        curr = curr->next;
    }

    if (curr->dta == inD)
        return true;
    else
        return false;
}
/*
template <typename bn>
bool tape<bn>::findSorted(bn inD)
{
    isPset();

    if (inD < curr->dta)
        findSortedL(inD);
    else if (inD > curr->dta)
        findSortedR(inD);
    else
        return true;
}

template <typename bn>
bool tape<bn>::findSortedR(bn inD)
{
    while (curr->next != NULL && curr->dta != inD)
    {
        curr = curr->next;
    }

    if (curr->dta == inD)
        return true;
    else
        return false;
}

template <typename bn>
bool tape<bn>::findSortedL(bn inD)
{
    while (curr->prev != NULL && curr->dta != inD)
    {
        curr = curr->prev;
    }

    if (curr->dta == inD)
        return true;
    else
        return false;
}
*/

    //delete


template <typename bn>
void tape<bn>::del()
{
    isPset();

    if (curr->prev == NULL)
        delH();
    else if(curr->next == tail)
        delT();
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    delete curr;
    cnt--;

    resetP();
}

template <typename bn>
void tape<bn>::delH()
{
    tip = curr->next;
    tip->prev = NULL;
}

template <typename bn>
void tape<bn>::delT()
{
    tail = curr->prev;
    tail->next = NULL;
}

template <typename bn>
void tape<bn>::clear()
{
    while (tip->next != NULL)
    {
        curr = tip;
        tip = tip->next;
        delete curr;
    }
    curr = NULL;
    cnt = 0;
}

template class tape <char>;