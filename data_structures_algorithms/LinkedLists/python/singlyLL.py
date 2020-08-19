class Node:

	def __init__(self, data):

		self.data = data
		self.next = None

class LinkedList:

	def __init__(self):

		self.head = None

	def push(self, data):

		tmp = Node(data)
		tmp.next = self.head
		self.head = tmp;

	def insert_after(self, prev_node, data):

		if prev_node is None:
			return -1

		tmp = Node(data)
		tmp.next = prev_node.next
		prev_node.next = tmp;

	def append(self, data):

		tmp = Node(data)

		if self.head is None:
			self.head = tmp
			return 0

		last = self.head
		while (last.next):
			last = last.next

		last.next = tmp

	def print_list(self):

		tmp = self.head

		while(tmp):
			print(tmp.data)
			tmp = tmp.next


