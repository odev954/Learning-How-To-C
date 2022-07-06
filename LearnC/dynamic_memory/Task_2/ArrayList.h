#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define CAPACITY_MIN_SIZE 10

typedef struct ArrayList
{
	int* list;
	int length;
	int capacity;
} ArrayList;

ArrayList create(int capacity)
{
	ArrayList self = { 0, 0, capacity };
	
	self.list = (int*)malloc(sizeof(int) * self.capacity);

	return self;
}

void addElement(ArrayList* self, int element)
{
	if (self->length == self->capacity)
	{
		ArrayList newSelf = create(self->capacity + CAPACITY_MIN_SIZE);

		for (int i = 0; i < self->length; i++)
		{
			newSelf.list[i] = self->list[i];
		}
		newSelf.length = self->length;

		free(self->list);

		*self = newSelf;
	}
	self->list[self->length] = element;
	self->length += 1;
}

void deleteElement(ArrayList* self, int index)
{
	ArrayList newSelf = create(self->capacity);

	for (int i = 0, j = 0; i < self->length; i++)
	{
		if (i != index)
		{
			newSelf.list[j] = self->list[i];
			j++;
		}
	}
	newSelf.length = self->length - 1;

	free(self->list);

	*self = newSelf;
}

#endif
