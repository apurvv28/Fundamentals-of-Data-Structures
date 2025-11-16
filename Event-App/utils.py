from models import LinkedList, Stack, Queue

class EventManager:
    def __init__(self):
        self.events_list = LinkedList()
        self.undo_stack = Stack()
        self.waiting_list_queue = Queue()
    
    def add_event(self, event):
        self.events_list.append(event)
        self.undo_stack.push(('add_event', event))
    
    def undo_last_action(self):
        if not self.undo_stack.is_empty():
            action, data = self.undo_stack.pop()
            # Implement undo logic based on action type
            return True
        return False
    
    def add_to_waiting_list(self, participant):
        self.waiting_list_queue.enqueue(participant)
    
    def process_waiting_list(self, event_id):
        # Process waiting list when spots become available
        pass

class Analytics:
    @staticmethod
    def get_event_stats(events):
        total_events = len(events)
        total_participants = sum(len(event.get('registered_participants', [])) for event in events)
        total_checked_in = sum(len(event.get('checked_in_participants', [])) for event in events)
        
        return {
            'total_events': total_events,
            'total_participants': total_participants,
            'total_checked_in': total_checked_in,
            'attendance_rate': (total_checked_in / total_participants * 100) if total_participants > 0 else 0
        }