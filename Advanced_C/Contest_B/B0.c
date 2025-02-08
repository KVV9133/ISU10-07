
uint64_t findMaxBlock(list *head)
{
	if (!head) 
	{
        return 0;
      }
	uint64_t max_address = 0;
	size_t max_size = 0;
	while (head) 
    {
		if (head->size > max_size) 
		{
            	max_size = head->size;
            	max_address = head->address;
           }
        	head = head->next;
    }
    return max_address;
}

