#include "prio_q.h"

struct prio_q * prio_q_create()
{
	// TODO

	struct prio_q* q = (struct prio_q*) malloc(sizeof(struct prio_q));
    q->size = 0; // queue is empty
	q->front = NULL;
    return q;
}

void prio_q_enqueue(struct prio_q *q, void *data, int prio)
{
	// TODO
    struct prio_q_elem* new_node = (struct prio_q_elem*) malloc(sizeof(struct prio_q_elem));
    new_node->data = data;
    new_node->priority = prio;
    new_node->next = NULL;

    struct prio_q_elem* node_ref = (q->front);
    struct prio_q_elem* node_prev = (q->front);

    while(node_ref->next != NULL && node_ref->priority >= prio){
        node_prev = node_ref->next;
        node_ref = node_ref->next;
    }

    new_node->next = node_ref;
    node_prev->next = new_node;
    q->size++;
}

void * prio_q_dequeue(struct prio_q *q)
{
	// TODO
	if (q->front == NULL)
        return NULL;
	void *data = q->front->data;
	struct prio_q_elem* old_first = q->front;
	q->front = q->front->next;
	free(old_first); // free the old queue node
	q->size--; // decrement the queue size.
    return data;
}

void * prio_q_front(struct prio_q *q)
{
	// TODO
    return q->front->data;
}

int prio_q_destroy(struct prio_q *q, void ** data)
{
	// TODO
	int counter = 0;
    struct prio_q_elem* temp;
    while(q->front != NULL){
        temp = q->front;
        data[counter++] = temp->data;
        q->front = temp->next;
        free(temp);
    }
    free(q);
    return counter;
}

void prio_q_print(struct prio_q * q, void (*print_data)(void*))
{
	// Implementierung dieser Funktion ist OPTIONAL und wird daher NICHT BEWERTET!
	struct prio_q_elem* temp = q->front;
    while(temp != NULL){
        print_data(temp->data);
        temp = temp->next;
    }
}
