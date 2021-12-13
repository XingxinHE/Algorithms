class StaticArray:
        def __init__(self, n):
                self.data = [None] * n             # (0)Init
                                                   
                                                   # (1)get func
        def get_at(self, i):
                if not (0 <= i < len(self.data)):      # check if the index i is valid
                        raise IndexError
                return self.data[i]                    # get the data at index i

                                                   # (2)set func
        def set_at(self, i, x):
                if not (0 <= i < len(self.data)):      # check if the index is valid
                        raise IndexError
                self.data[i] = x                       # set the data at index i

def birthday_match(students):
        """
        Find a pair of students with the same birthday
        Input: tuple of student (name, bday) tuples
        Output: tuple of student names or None
        """
        n = len(students)                                        # O(1)
        record = StaticArray(n)                                  # O(n)
        for i in range(n):                                       # n
                (name_que, bday_que) = students[i]               # O(1)
                for j in range(i):                               # k   check if it is in record
                        (name_rec, bday_rec) = record[j]         # O(1)
                        if bday_rec == bday_que:                 # O(1)
                                return (name_que, name_rec)      # O(1)
                record.set_at(i, (name_que, bday_que))           # O(1)
        return None                                              # O(1)
